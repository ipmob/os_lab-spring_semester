//write a c program to implement stack with push and pop operations.
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top=-1;
int a[10];
int value;

int push(int data){
   if(top==MAX-1){
     printf("full");
     return 0;
   }
  else{
    a[++top]=data;
  }
}//end of push

int pop(){
  if(top==-1){
     printf("empty");
     return 0;
  }
  else 
    return a[top--];
}//end of pop

int display(){
   int i;
   if(top==-1){
     printf("Empty");
     return 0;
   }
   printf("Stack is :");
   printf(" \n");
   for(i=top;i>=0;i--){
     printf("  %d\n",a[i]);
  }
}//end of display

int main(){
  int choice;
  printf("1.push\n2.pop\n3.display\n4.exit");
  while(1){
     printf("\nEnter your choice :"); 
     scanf("%d",&choice);
     switch(choice){
        case 1:
              printf("\nEnter the data :");
              scanf("%d",&value);
              push(value);
              break;
        case 2:
              printf("Popped iem is %d:", pop());
              break;
        case 3:
              display();
              break;
        case 4:
               exit(1);
               break;
        default:
              printf("Wrong choice");
              break;
     }//end of switch
  }//end of while
}//end of main


