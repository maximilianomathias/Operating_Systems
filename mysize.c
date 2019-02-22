#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
  DIR *dir;             //
  struct dirent *d;     // structure type to retain info about directories
  char buf[PATH_MAX];   // buffer for directory path
  int fd;               // filedescriptor
// Controls if the argumets passed are greater that 1
  if(argc > 1){
    printf("NUmber or arguments esceeded");
    return -1;
  }

  if(getcwd(buf, sizeof(buf))!=NULL){
    printf("Current working directory: %s\n", buf);
// loads the directory to the DIR pointer
    if((dir = opendir(buf))!=NULL)
    {
      printf("despues de opendir\n");
// goes through the list of files until there is none
      while((d = readdir(dir))!=NULL){
        printf("Dentro del bucle while\n");

        if(d->d_type == DT_REG){
          printf("Es un archivo regular");
          //fd = open(dir, O_RDONLY);
        }
      }
      closedir(dir);
    }else
      return -1;
  }else
    return -1;

}
