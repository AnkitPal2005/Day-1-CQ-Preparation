#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    printf("Total arguments:%d\n",argc-1);
 
  int sum=0;
  for(int i=1;i<argc;i++){
    sum=sum+atoi(argv[i]);
  }
  printf("%d",sum);
  return 0;
    }
    
