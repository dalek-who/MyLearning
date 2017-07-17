#include "ramdisk.h"
#include "util.h"

#include "files.h"

process ramdisk_find(const char *filename)
{
  int i;
  for(i=0; i<get_num_files(); ++i)
  {
    File *file = get_nth_file(i);
    if( same_string( file->filename, filename ) )
      return file->process;
  }
  return 0;
}
