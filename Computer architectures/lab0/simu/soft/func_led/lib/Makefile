.SUFFIXES: .o64 .elf64 .bin64

objs= memset.o memcpy.o printf.o udelay.o now.o putchar.o puts.o printhex.o  printbase.o memcmp.o strcat.o strchr.o strcmp.o strtok.o strspn.o strcspn.o getchar.o testchar.o vsprintf.o atob.o sprintf.o strtoupp.o toupper.o str_fmt.o strcpy.o strlen.o strichr.o strlen.o  strncmp.o strncpy.o newprintf.o cache.o cmdline.o irq.o malloc.o guess.o strtoul.o

objs64=$(objs:.o=.o64)

$(TOPDIR)/libtinyc.a: $(objs)
	$(CROSS_COMPILE)$(AR) -cr  $@ $?

$(TOPDIR)/libtinyc64.a: $(objs64)
	$(CROSS_COMPILE)$(AR) -cr  $@ $?

clean:
	rm -f *.o *.a *.s *.o64 *.bin64 *.elf64


-include $(TOPDIR)/rules.make
