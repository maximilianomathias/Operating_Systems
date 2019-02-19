#include <stdio.h>              /* Cabecera llamada al sistema printf  */
#include <unistd.h>             /* Cabecera llamada al sistema gtcwd  */
#include <sys/types.h>          /* Cabeceras llamadas al sistema opendir, readdir y closedir  */
#include <dirent.h>
#include <string.h>
#include <limits.h>


int main(int argc, char *argv[])
{
  DIR *dir;
  struct dirent *d;
  int fileDesc;
  char buf[PATH_MAX];


  if(getcwd(buf, sizeof(buf))!=NULL)
  {
    printf("Dentro de my ls\n");
    printf("Current working directory: %s\n", buf);
    if((dir = opendir(buf))!=NULL)
    {
      printf("Se ha podido abrir el directorio\n");
      while((d = readdir(dir))!=NULL)
        printf("%s\n", d->d_name);
    }
  }


}
