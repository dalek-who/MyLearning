#!/usr/bin/python

import os, sys, subprocess
fs_size_bytes = 1048576

def spawn_lnxsh():
    global p
    p = subprocess.Popen('./lnxsh', shell=True, stdin=subprocess.PIPE)

def issue(command):
    p.stdin.write(command + '\n')

def check_fs_size():
    fs_size = os.path.getsize('disk')
    if fs_size > fs_size_bytes:
        print "** File System is bigger than it should be (%s) **" %(pretty_size(fs_size))

def do_exit():
    issue('exit')
    return p.communicate()[0]
#create a file that is larger than 8 blocks so that the file system is forced to use
#indirect block pointers
def test_large_file():
    issue('mkfs')
    # create a file large enough to use all the blocks in the system
    issue('create large_file 10000000')
    issue('stat large_file') # blocks: 1914, size: 975872
    issue('create f 100') #should fail
    #check_fs_size();
    do_exit();

# create a directory with enough files that the directory needs to be resized into
# an inode with indirect pointers
def test_large_dir():
    issue('mkfs')
    issue('mkdir dir')
    issue('cd dir')
    for x in range(0, 640):
        issue('create f%d 1' %x)

    issue('ls')
    # test catting files before and after the boundary between blocks 8 and 9
    issue('cat f510') #A
    issue('cat f511') #A
    issue('cat f512') #A
    issue('cd ..')
    issue('stat dir')
    do_exit()

def test_dir_frag():
    issue('mkfs')
    issue('mkdir dir')
    issue('cd dir')
    for x in range(1, 639):
        issue('create f%d 1' %x)
    issue('stat .') # should take up 10 blocks
    for x in range(1, 129):
        issue('unlink f%d' %x)
    issue('stat .') # should take up 8 blocks, removes indirect block
    for x in range(1, 129):
        issue('create f%d 1' %x)
    issue('ls') #all files from f1 to f638 should be present
    do_exit()

# test that interleaved reads and writes on same file but different
# descriptors work
def test_multi_open():
    issue('mkfs')
    issue('open f 2')
    issue('open f 1')
    issue('open f 3')
    issue('write 0 hello')
    issue('read 1 5') # hello
    issue('write 2 thereworld')
    issue('read 1 5') # world
    issue('lseek 1 0')
    issue('read 1 5') # there
    do_exit()

# make sure we fail when there are no file handles left
def test_get_all_handles():
    issue('mkfs')
    for x in range(0,520):
        issue('open f%d 3' %x) #should fail after file handle 512
    do_exit()

# make sure we fail when all inodes are used
def test_get_all_inodes():
    issue('mkfs')
    for x in range(0,1026):
        issue('open f%d 3' %x) #should fail after 1024, 3 times
        issue('close 0')
    do_exit()

def test_rmdir():
    issue('mkfs')
    issue('stat .')
    for x in range(0, 256):
        issue('mkdir f%d' %x)
        #issue('stat f%d' %x)
    issue('stat .')
    for x in range(0, 256):
        issue('rmdir f%d' %x)
    issue('stat .')
    issue('ls')
    do_exit()

print "......Starting my tests\n\n"
sys.stdout.flush()

# spawn_lnxsh()
# test_rmdir()

# spawn_lnxsh()
# test_large_file()

spawn_lnxsh()
#dir tests need to implement shell_ls
test_large_dir()

# spawn_lnxsh()
# test_dir_frag()

# spawn_lnxsh()

# test_multi_open()

# spawn_lnxsh()
# test_get_all_handles()

# spawn_lnxsh()
# test_get_all_inodes()