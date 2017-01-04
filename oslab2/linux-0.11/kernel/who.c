#define __LIBRARY__  
#include <unistd.h>  
#include <errno.h>  
#include <asm/segment.h>  
char temp[64]={0};  
int sys_iam(const char* name)  
{  
   int i=0;  
   while(get_fs_byte(name+i)!='\0')  
        i++;  
   if(i>23){     
        return -EINVAL;  
   }   
   printk("%d\n",i);  
   i=0;  
   while((temp[i]=get_fs_byte(name+i))!='\0'){  
i++;  
    }     
    return i;  
}  
  
  
int sys_whoami(char* name,unsigned int size)  
{  
    int i=0;  
    while (temp[i]!='\0')  
i++;  
    if (size<i)  
    return -1;  
    i=0;  
    while(temp[i]!='\0'){  
put_fs_byte(temp[i],(name+i));  
i++;  
    }  
    return i;  
}  
