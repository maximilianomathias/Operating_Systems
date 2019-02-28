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

  // chek if argument number is correct. if not, we end porcess by returning -1.
  if(argc < 2){
    printf("No file path nor file name has been passed\n");
    return -1;
  }
  /* FLAG: O_RDONLY sisnce we're only gonna open the file to read it.
    If we get a -1 as a file descriptor, we return a -1 to end the process and errno is set apropietly.
  */
  if ((fileDesc=open(argv[1],O_RDONLY, 0666))<0) {
    perror("Error opening file");
    return -1;
  }
  else{
    while ((n=read(fileDesc,buf,N))>0){
      write(STDOUT_FILENO, buf, n);
      // if the numebr of bytes written is less than 0, an error is returned.
      if (n<0){
        perror("Read error occured:");
        return -1;
      }
    }
  }
  close(fileDesc);
  return 0;
}
