#define __LIBRARY__  
#include <unistd.h>  
#include <string.h>  
#include <errno.h>  
#include <stdio.h>  
  
_syscall2(int,whoami,char*,name,unsigned int,size)  
  
int main()  
{  
    int counter;  
    char buff[128]={0};  
      
    counter=whoami(buff,128);  
    if(counter < 0)  
    {  
       printf("SystemCall Exception!");  
       return -1;  
        }  
    else{  
        printf("%s\n",buff);  
        }  
    return 0;  
} 
