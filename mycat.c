#include <stdio.h>              /* Cabecera llamada al sistema printf  */
#include <sys/types.h>          /* Cabeceras llamada al sistema open  */
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>             /* Cabecera llamadas al sistema read, write y close  */

// define the buffer size
#define N 1024

int main(int argc, char *argv[])
{
  int fileDesc,n;
  char buf[N];



  printf("HOLA MY CAT\n" );
  // chek if argument number is correct
  if(argc < 2){
    printf("No arguments has been passed\n");
    return -1;
  }

  if ((fileDesc=open(argv[1],O_RDONLY,0666))<0) {
    perror("Error opening file");
    return -1;
  }else{
    while ((n=read(fileDesc,buf,N))>0)
      printf("%s \n",buf);
      write(STDOUT_FILENO, buf, n);
  }

  printf("Argument number: %d\n",argc );
  for(int i = 0; i< argc; i++)
    printf("Argument: %s\n",argv[i]);
  /*

  if ((fileName=open("file_read.txt",O_CREAT|O_RDWR,0666))<0) {
    perror("Error opening file");
    exit(1);
  }

  while ((n=read(fd,buf,N))>0)
    printf("Read from file character %c \n",buf[0]);

  if (n<0) {
    perror("Read error occured:");
    return -1;
  }
  else
  */
    close(fileDesc);


  return 0;
}
