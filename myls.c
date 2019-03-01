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
  {
    printf("Too many arguments\n");
    return -1;//---------- ASK PROFESSOR how many arguments can be provided
  }

// Gets the current working durectory into the buffer (buf)
  if(getcwd(buf, sizeof(buf))==NULL)
  {
    perror("Error getting the current working directory");
    return -1;
  }
  // if the number of arguments passed is equal to 1, we use the current working directory.
  if(argc == 1)
  {
    if((dir = opendir(buf))==NULL)
    {
      perror("Error opening the directory");
      return -1;
    }
  }
  else // we change the current working directory according to the name/path specified in the second argument
  {
    if((dir = opendir(argv[1]))==NULL)
    {
      perror("Error opening the directory");
      return -1;
    }
  }
  // if everything went fine, we read every list of entries in that direcotry.
  while((d = readdir(dir))!=NULL)
    printf("%s\n", d->d_name);
// finally we close the directory.
  closedir(dir);

  return 0;
}
