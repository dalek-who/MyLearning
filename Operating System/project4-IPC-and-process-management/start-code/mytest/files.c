#include "files.h"
#include "processes.h"

/* This file represents a table
 * mapping file names to entry
 * points.  It is analogous to
 * tasks.c in the previous project.
 */

static File files[] =
  {
    	{.filename = "init", .process = &init},
	{.filename = "shutdown", .process = &shutdown_process},
	{.filename = "rewatch", .process = &theplay },
    	{.filename = "SunQuan", .process = &SunQuan },
    	{.filename = "LiuBei", .process = &LiuBei },
	{.filename = "CaoCao", .process = &CaoCao },
  };

#define NUM_FILES     ( sizeof(files) / sizeof(File) )

int get_num_files()
{
  return NUM_FILES;
}

File *get_nth_file(int n)
{
  return &files[n];
}



