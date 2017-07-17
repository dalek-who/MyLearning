#ifndef RAMDISK_H
#define RAMDISK_H

/* ramdisk provides a fake filesystem.
 * It is read-only, and its contents
 * are assembled at compile time.
 */

typedef void (*process)(void);

typedef struct
{
  const char *  filename;
  process       process;
} File;

process ramdisk_find(const char* filename);


#endif

