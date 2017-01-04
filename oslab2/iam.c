#define __LIBRARY__  
#include <unistd.h>  
#include <string.h>  
#include <errno.h>  
#include <stdio.h>  
_syscall1(int,iam,const char*,name)  
  
int main(int argc,char* argv[])  
{  
      
    if(argc>1){  
    if(iam(argv[1])<0){  
        printf("SystemCall Exception!\n");  
        return -1;  
    }  
    }  
    else{  
    printf("Input Exception!\n");  
    return -1;  
    }         
    return 0;  
}  
