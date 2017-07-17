#include <assert.h>
#include <elf.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Elf32_Phdr * read_exec_file(FILE **execfile, char *filename, Elf32_Ehdr **ehdr)
{
	*execfile = fopen(filename, "rb");
	if(*execfile == NULL)
	{
		printf("open fail\n");
		exit(1);
	}	
	Elf32_Phdr *fp;
	int i = 1;
	fp = (Elf32_Phdr *)malloc(sizeof(Elf32_Phdr));
	*ehdr = (Elf32_Ehdr *)malloc(sizeof(Elf32_Ehdr));
	fread(*ehdr, i * sizeof(Elf32_Ehdr), 1, *execfile);
	fseek(*execfile, i * (*ehdr)->e_phoff, 0);
	fread(fp, sizeof(Elf32_Phdr), 1, *execfile);
	return fp;
}

void write_bootblock(FILE **image_file, FILE *boot_file, Elf32_Ehdr *boot_header,Elf32_Phdr *boot_phdr)
{
	int i = 1;
	void *buffer = calloc(512, sizeof(i));
	fseek(boot_file, i * (boot_phdr->p_offset), 0);
	fread(buffer, boot_phdr->p_filesz, 1, boot_file);
	rewind(*image_file);
	fwrite(buffer, 512, 1, *image_file);
	fseek(*image_file, 510L, 0);
	fputc(0x55, *image_file);
	fputc(0xaa, *image_file);
	free(buffer);
	return;
}

void write_kernel(FILE **image_file, FILE *kernel_file, Elf32_Ehdr *kernel_ehdr, Elf32_Phdr *kernel_phdr)
{
	int i = 1;
	void *buffer = calloc(kernel_phdr->p_filesz, sizeof(i));
	fseek(kernel_file, kernel_phdr->p_offset, 0);
	fread(buffer, kernel_phdr->p_filesz, 1, kernel_file);
	fseek(*image_file, 512L, 0);
	fwrite(buffer, kernel_phdr->p_filesz, 1, *image_file);
	free(buffer);
	return;
}

int count_kernel_sectors(Elf32_Ehdr *kernel_header, Elf32_Phdr *kernel_phdr)
{
	int i;
	i = kernel_header->e_phnum * kernel_phdr->p_filesz;
	if(i % 512 == 0)
		return i >> 9;
	else return (i >> 9) + 1;
}

void record_kernel_sectors(FILE **image_file, Elf32_Ehdr *kernel_ehdr, Elf32_Phdr *kernel_phdr, int num_sec)
{
	int i;
	i = kernel_ehdr->e_phnum * kernel_phdr->p_filesz;
	if(i % 512 == 0)
		num_sec= i >> 9;
	else num_sec = (i >> 9) + 1;
	fseek(*image_file, 2L, 0);
	fputc(num_sec>>0, *image_file);
	fputc(num_sec>>8, *image_file);
	fputc(num_sec>>16, *image_file);
	fputc(num_sec>>24, *image_file);
	return;
}

void extended_opt(Elf32_Phdr *boot_phdr, int k_phnum, Elf32_Phdr *kernel_phdr, int num_sec)
{	
	printf("Number of disk sectors:%d\n", 1 + num_sec);
	printf("bootblock image info\n");
	printf("\tsectors:  1\n");
	printf("\toffset of segment in the file: 0x%X\n", boot_phdr->p_offset);
	printf("\tthe image\'s vatural address of segment in memory: 0x%X\n", boot_phdr->p_vaddr);
	printf("\tthe file image size of segment:  0x%X\n", boot_phdr->p_filesz); 
	printf("\tthe memory image size of segment:  0x%X\n", boot_phdr->p_memsz);
	printf("\tthe size of write to the OS image:  0x%X\n", boot_phdr->p_filesz);
	printf("kernel image info\n");
	printf("\tsectors:  %d\n", num_sec);
	printf("\toffset of segment in the file: 0x%X\n", kernel_phdr->p_offset);
	printf("\tthe image\'s vatural address of segment in memory: 0x%X\n", kernel_phdr->p_vaddr);
	printf("\tthe file image size of segment:  0x%X\n", kernel_phdr->p_filesz); 
	printf("\tthe memory image size of segment:  0x%X\n", kernel_phdr->p_memsz);
	printf("\tthe size of write to the OS image:  0x%X\n", kernel_phdr->p_filesz);
	return;
}


int main(int argc, char *argv[])
{
	FILE **image_file, *boot_file, *kernel_file;
	Elf32_Ehdr *boot_ehdr, *kernel_ehdr;
	Elf32_Phdr *boot_phdr, *kernel_phdr;
	int num_sec = 0;
	image_file = malloc(sizeof(FILE *));
	if(argc != 4 && argv[1]!="--extended")
		return 1;
	boot_phdr = read_exec_file(&boot_file, argv[2], &boot_ehdr);
	kernel_phdr = read_exec_file(&kernel_file, argv[3], &kernel_ehdr);
	*image_file = fopen("image", "wb");
	write_bootblock(image_file, boot_file, boot_ehdr, boot_phdr);
	write_kernel(image_file, kernel_file, kernel_ehdr, kernel_phdr);
	num_sec = count_kernel_sectors(kernel_ehdr, kernel_phdr);
	record_kernel_sectors(image_file, kernel_ehdr, kernel_phdr, num_sec);
	extended_opt(boot_phdr, kernel_ehdr->e_phnum, kernel_phdr, num_sec);
	fclose(*image_file);
	fclose(boot_file);
	fclose(kernel_file);
	free(image_file);
	return 0;
}

