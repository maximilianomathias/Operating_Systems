#include <stdio.h>              /* Cabecera llamada al sistema printf  */
#include <unistd.h>             /* Cabecera llamada al sistema gtcwd  */
#include <sys/types.h>          /* Cabeceras llamadas al sistema opendir, readdir y closedir  */
#include <dirent.h>
#include <string.h>
#include <limits.h>
#include <string.h>


int main(int argc, char *argv[])
{
  DIR *dir;
  struct dirent *d;
  int fileDesc;
  char buf[PATH_MAX];
  int i = 0;
  char *changeDir;

  // control
  printf("tamaño de path max: %d\n", PATH_MAX);
  printf("Numero de argumntos: %d\n", argc);

  if(argc == 1){ // control number of arguments
    if(getcwd(buf, sizeof(buf))!=NULL)
    {
      printf("Current working directory: %s\n", buf);

      if((dir = opendir(buf))!=NULL)
      {
        while((d = readdir(dir))!=NULL)
          printf("%s\n", d->d_name);
      }else
        return -1;
    }
    close(dir);

  }
  if(argc == 2){
    printf("Dentro de los dos argumentos\n");
    if(getcwd(buf, sizeof(buf))!=NULL)
      printf("OLD working directory: %s\n", buf);
    while(argv[i]!=NULL){
      printf("Argumentos: %s\n", argv[i]);
      i++;
    }
    int a = chdir(argv[1]);
    if(getcwd(buf, sizeof(buf))!=NULL)
      printf("NEW working directory: %s\n", buf);

      if((dir = opendir(buf))!=NULL)
      {
        while((d = readdir(dir))!=NULL)
          printf("%s\n", d->d_name);
      }else
        return -1;
  }

  return 0;
}
