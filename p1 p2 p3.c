/*Write a collection of programs p1, p2, p3 such that they execute sequentially with the 
sameprocess-id, and each program should also print its PID(Process id). The user should
 be able toinvoke any combination of these programs, to achieve the required functionality. 
 For exampleconsider three programs twice, half, square which accept only one integer as 
 argument and Doessome specific operation*/



Square.c

#include <stdio.h>
#include<string.h>
#define BUFSIZE 128

int parse_output(char *fname) {
    char cmd[10];

	strcpy(cmd,"./");
    
	strcat(cmd,fname);

    char buf[BUFSIZE];
    FILE *fp;
//printf("%s",cmd);
    if ((fp = popen(cmd, "r")) == NULL) {
        printf("Error opening pipe!\n");
        return -1;
    }

    while (fgets(buf, BUFSIZE, fp) != NULL) {
        // Do whatever you want here...
        printf("%s", buf);
    }

    if(pclose(fp))  {
      //  printf("Command not found or exited with error status\n");
        return -1;
    }

    return 0;
}
int conv_num(char *num){
	int x=0,i;	
	for( i=0;num[i]!='\0';i++){
		x*=10;
		x+=num[i]-'0';
		//printf("%s",num[i]);

	}
	return x;	

}


main(int argn,char *arga[]){

int i,x=0;
	
	
	x=conv_num(arga[argn-1]);
	/*for(i=1;i<argn-1;i++){
	
		if(strcmp(arga[i],"square")==0){
			x=square(x);
		}else if(strcmp(arga[i],"cube")==0){
			x=cube(x);
		}else if(strcmp(arga[i],"half")==0){
			x=half(x);
		}else if(strcmp(arga[i],"twice")==0){
			x=twice(x);
		}else if(strcmp(arga[i],"thrice")==0){
			x=thrice(x);
		}else{
			printf("command not found %s",arga[i]);
		}
	}*/
	if(argn==2){

		printf("%d",x*x);
		//parse_output("twice 36");
	}else if(argn>2){
	//	printf("Taking default value 3 \n 18");
	
		char files[100];
		strcpy(files,arga[1]);	
		for(i=2;i<argn-1;i++){
			strcat(files," ");			
			strcat(files,arga[i]);
								
		}
		char num[80];
		sprintf(num,"%d",x*x);
		
		strcat(files," ");
		strcat(files,num);		

		parse_output(files);
//printf("%s",files);
	}
}	






Half.c

#include <stdio.h>
#include<string.h>
#define BUFSIZE 128

int parse_output(char *fname) {
    char cmd[10];

	strcpy(cmd,"./");
    
	strcat(cmd,fname);

    char buf[BUFSIZE];
    FILE *fp;
//printf("%s",cmd);
    if ((fp = popen(cmd, "r")) == NULL) {
        printf("Error opening pipe!\n");
        return -1;
    }

    while (fgets(buf, BUFSIZE, fp) != NULL) {
        // Do whatever you want here...
        printf("%s", buf);
    }

    if(pclose(fp))  {
      //  printf("Command not found or exited with error status\n");
        return -1;
    }

    return 0;
}
int conv_num(char *num){
	int x=0,i;	
	for( i=0;num[i]!='\0';i++){
		x*=10;
		x+=num[i]-'0';
		//printf("%s",num[i]);

	}
	return x;	

}


main(int argn,char *arga[]){

int i,x=0;
	
	
	x=conv_num(arga[argn-1]);
	/*for(i=1;i<argn-1;i++){
	
		if(strcmp(arga[i],"square")==0){
			x=square(x);
		}else if(strcmp(arga[i],"cube")==0){
			x=cube(x);
		}else if(strcmp(arga[i],"half")==0){
			x=half(x);
		}else if(strcmp(arga[i],"twice")==0){
			x=twice(x);
		}else if(strcmp(arga[i],"thrice")==0){
			x=thrice(x);
		}else{
			printf("command not found %s",arga[i]);
		}
	}*/
	if(argn==2){

		printf("%d",x/2);
		//parse_output("twice 36");
	}else if(argn>2){
	//	printf("Taking default value 3 \n 18");
	
		char files[100];
		strcpy(files,arga[1]);	
		for(i=2;i<argn-1;i++){
			strcat(files," ");			
			strcat(files,arga[i]);
								
		}
		char num[80];
		sprintf(num,"%d",x/2);
		
		strcat(files," ");
		strcat(files,num);		

		parse_output(files);
//printf("%s",files);
	}
}	






Twice.c
#include <stdio.h>
#include<string.h>
#define BUFSIZE 128

int parse_output(char *fname) {
    char cmd[10];

	strcpy(cmd,"./");
    
	strcat(cmd,fname);

    char buf[BUFSIZE];
    FILE *fp;
//printf("%s",cmd);
    if ((fp = popen(cmd, "r")) == NULL) {
        printf("Error opening pipe!\n");
        return -1;
    }

    while (fgets(buf, BUFSIZE, fp) != NULL) {
        // Do whatever you want here...
        printf("%s", buf);
    }

    if(pclose(fp))  {
      //  printf("Command not found or exited with error status\n");
        return -1;
    }

    return 0;
}
int conv_num(char *num){
	int x=0,i;	
	for( i=0;num[i]!='\0';i++){
		x*=10;
		x+=num[i]-'0';
		//printf("%s",num[i]);

	}
	return x;	

}


main(int argn,char *arga[]){

int i,x=0;
	
	
	x=conv_num(arga[argn-1]);
	/*for(i=1;i<argn-1;i++){
	
		if(strcmp(arga[i],"square")==0){
			x=square(x);
		}else if(strcmp(arga[i],"cube")==0){
			x=cube(x);
		}else if(strcmp(arga[i],"half")==0){
			x=half(x);
		}else if(strcmp(arga[i],"twice")==0){
			x=twice(x);
		}else if(strcmp(arga[i],"thrice")==0){
			x=thrice(x);
		}else{
			printf("command not found %s",arga[i]);
		}
	}*/
	if(argn==2){

		printf("%d",2*x);
		//parse_output("twice 36");
	}else if(argn>2){
	//	printf("Taking default value 3 \n 18");
	
		char files[100];
		strcpy(files,arga[1]);	
		for(i=2;i<argn-1;i++){
			strcat(files," ");			
			strcat(files,arga[i]);
								
		}
		char num[80];
		sprintf(num,"%d",2*x);
		
		strcat(files," ");
		strcat(files,num);		

		parse_output(files);
//printf("%s",files);
	}
}	



