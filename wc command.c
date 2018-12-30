//write a c program to implement wc command using system calls.
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<error.h>
#define BUFF 1024

int main(int argc, char *argv[]){
    int fd1,fd2,nread;
    char *buf[1024];
    fd2=open(argv[2],O_RDONLY);
    if(fd2==-1){
       perror(argv[2]);
       return; 
    }
  
  fd1=open(argv[1],O_WRONLY);
  if(fd1==-1){
  	  perror(argv[1]);
  	  return;
  }
  
  while((nread=read(fd2,buf,BUFF))>0)
      write(fd1,buf,nread);
   
   close(fd2);
   close(fd1);
}

