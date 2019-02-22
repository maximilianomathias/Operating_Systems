#include <stdio.h>              /* header library for printf  */
#include <unistd.h>             /* header library for the system calls gtcwd  */
#include <sys/types.h>          /* header library for the system calls opendir, readdir y closedir  */
#include <dirent.h>             /* header library to operate with directories */

int main(int argc, char *argv[])
{
  DIR *dir;
  struct dirent *d;
  char buf[PATH_MAX];

// Controls if the argumets passed are greater that 2
  if(argc > 2)
    return -1;

// Changes the current directory if number of argumentes is = 2
  if(argc == 2){
    if((chdir(argv[1])!=0)){
      perror("");
      return -1;
    }
  }

// load the path into the buffer
  if(getcwd(buf, sizeof(buf))!=NULL){
// loads the directory to the DIR pointer
    if((dir = opendir(buf))!=NULL)
    {
// goes through the list of files until there is none
      while((d = readdir(dir))!=NULL)
        printf("%s\n", d->d_name);
      closedir(dir);
    }else
      return -1;
  }else
    return -1;

  return 0;
}
