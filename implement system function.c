#include<unistd.h>
#include<stdio.h>
#include<math.h>

void main(){
   char command[80]; 
   //int pid = fork(void);

   while(1){
      printf("%%");
      fgets(command,80,stdin);
      system(command);
   }
}
