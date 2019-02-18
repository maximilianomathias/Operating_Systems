## Operating_Systems
Programs made in C in order to communicate with the kernel from the user. 

This lab allows the student to familiarize with Operating System calls (especially related to the file system management) 
following the POSIX standard. Unix allows you to make calls directly to the Operating System from a program implemented in 
a high-level language, in particular, C language.
Most of input/output (I/O) operations in Unix can be done using uniquely five calls: open, read, write, lseek and close.
For the Operating System kernel, all files opened are identified using file descriptors. A file descriptor is a non negative 
integer. When we open a file that already exists, the kernel returns a file descriptor to the process. When we want to read 
or write from/to a file, we identify the file with the file descriptor that was returned by the open call.
Each open file has a current read/write position ("current file offset"). It is represented by a non-negative integer that 
measures the number of bytes from the beginning of the file. The read and write operations normally start at the current 
position and create an increment in that position equal to the number of bytes read or written. By default, this position is 
initialized to 0 when a file is opened, unless the option O_APPEND is specified. The current position (current_offset) of an 
open file can be changed explicitly using the system call lseek.
To manipulate directories, you can use the system calls opendir, readdir and closedir. An open directory is identified with a 
directory descriptor, which is a pointer of type DIR (DIR*). When we open a directory with opendir, the kernel returns a 
directory descriptor from which the different entries to that directory can be read using the calls to the function readdir. 
The call readdir returns a directory entry in a pointer to a structure of type dirent (struct dirent*). Such structure will 
contain the fields corresponding to that entry such as the name of the entry, or the type (if it is a normal file, another 
directory, symbolic links, etc.). Repeated calls to the function readdir will be returning the next entries in an open 
directory.
