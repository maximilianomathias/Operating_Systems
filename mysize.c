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
  int fileSize;

// Controls if the argumets passed are greater that 1
  if(argc > 1){
    printf("Number or arguments exceeded");
    return -1;
  }

  if(getcwd(buf, sizeof(buf))!=NULL){
// loads the directory to the DIR pointer
    if((dir = opendir(buf))!=NULL){
// goes through the list of files until there is none
      while((d = readdir(dir))!=NULL){
        if(d->d_type == DT_REG){
          if((fd = open(d->d_name, O_RDONLY, 0666))<0){ // 0444?
            perror("Error opening the file");
            return -1;
          }else{
            fileSize = lseek(fd, 0, SEEK_END);
            printf("%s\t%d\n", d->d_name, fileSize);
            close(fd);
          }
        }
      }
      closedir(dir);
    }else
      return -1;
  }else
    return -1;

    return 0;
}
