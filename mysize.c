#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
  DIR *dir;
  struct dirent *d;
  char buf[PATH_MAX];
  int fd;
  int fileSize;

// Controls if the argumets passed are greater that 1
  if(argc > 1)
  {
    printf("Number or arguments exceeded");
    return -1;
  }
  // Gets the current working durectory into the buffer (buf)
  if(getcwd(buf, sizeof(buf))!=NULL)
  {
    // loads the directory to the DIR pointer
    if((dir = opendir(buf))!=NULL)
    {
      // goes through the list of files until there is none
      while((d = readdir(dir))!=NULL)
      {
        // we compare if the file allocated corresponds witha regular type file.
        if(d->d_type == DT_REG)
        {
          // if so, we open this file
          if((fd = open(d->d_name, O_RDONLY, 0666))<0)
          {
            perror("Error opening the file");
            return -1;
          }
          else
          {
            // we start from the first character and seek for the end of the file.
            fileSize = lseek(fd, 0, SEEK_END);
            printf("%s\t%d\n", d->d_name, fileSize);
            close(fd);
          }
        }
      }
      closedir(dir);
    }
    else
    {
      perror("Error opening the directory:");
      return -1;
    }

  }
  else
  {
    perror("Error getting the current working directory:");
    return -1;
  }
    return 0;
}
