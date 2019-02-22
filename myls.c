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
  if(argc > 2){
    printf("Number of arguments exceded\n");
    return -1;
  }
  // Changes the current directory if number of argumentes is = 2
  if(argc == 2){ // control number of arguments
    printf("Inside the two-argument scope\n");
    if((chdir(argv[1])!=0)){
      perror("");
      return -1;
    }
  }

  if(getcwd(buf, sizeof(buf))!=NULL){
    printf("Current working directory: %s\n", buf);

    if((dir = opendir(buf))!=NULL)
    {
      while((d = readdir(dir))!=NULL)
        printf("%s\n", d->d_name);
    }else
      return -1;
  }else
    return -1;

  return 0;
}

// notes

/*
int i = 0;
while(argv[i]!=NULL){
printf("Argumentos: %s\n", argv[i]);
i++;
}*/
