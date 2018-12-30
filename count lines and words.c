//write a c program to count number of words and lines in a file using system calls.
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#define BUFF_SIZE 1024
int main(int argc,char *argv[]){
     int src,dest,nr,nw,c=0,i,c1=0;
     char *buff;
     buff=(char*)malloc(1024*sizeof(char));
	
     src=open(argv[1],O_RDONLY);
     if(src==-1)
	printf("error in opening of file");
  
     while((nr=read(src,buff,BUFF_SIZE))>0){
	for(i=0;buff[i]!='\0';i++){
	    printf("%c",buff[i]);
	    if(buff[i]==' '||buff[i]=='\n')
		   c++;
		   if(buff[i]=='\n')
		      c1++;	
      }
		
		
}
	printf("no. of words=%d\n",c);
	printf("no. of lines=%d\n",c1); 
	close(src);
}


