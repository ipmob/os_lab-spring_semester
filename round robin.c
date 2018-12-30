//write a program to implement round robin cpu scheduling algorithm.

#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
 
int main() 
{ 
 
  int count,j,n,time,remain,flag=0,time_quantum,waiting=0,turnaround=0,arrival[10],burst[10],rt[10];

  printf("Enter total number of Processes: "); 
  scanf("%d",&n); 
  remain=n; 

  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time for Process %d :",count+1); 
    scanf("%d",&arrival[count]); 
    printf("Enter Burst Time for Process Number %d :",count+1); 
    scanf("%d",&burst[count]); 
    rt[count]=burst[count]; 
  } 

  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t Turnaround Time\tWaiting Time\n"); 

  for(time=0,count=0;remain!=0;) 
  { 

    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 

    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t\t%d\t\t%d\n",count+1,time-arrival[count],time-arrival[count]-burst[count]); 
      waiting+= time-arrival[count]-burst[count]; 
      turnaround+= time-arrival[count]; 
      flag=0; 
    } 
  
  if(count==n-1) 
      count=0; 
    else if(arrival[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
 
  printf("\nAverage Waiting Time= %f\n",waiting*1.0/n); 
  printf("Average Turnaround Time = %f\n",turnaround*1.0/n); 
  
  return 0; 

}//end of main

