    #define __LIBRARY__  
    #include <unistd.h>  
    #include <linux/sched.h>  
    #include <linux/kernel.h>  
    #include <asm/segment.h>  
    #include <asm/system.h>  
    #include <signal.h>  
      
    const int  SEM_NUM=20;   
    char sem_name[20][20] = {};  
    sem_t sem_array[20];  
      
    int find_sem(char* name){  
        int i;  
        for(i = 0;i < SEM_NUM; i++)  
        {  
            if(!strcmp(sem_name[i],name))  
            {     
                return i;  
            }  
        }  
        return -1;  
    }  
    char* get_name(const char* name){  
        char tempname[20]={};  
        char temp;  
            int i=0;  
        while((temp = get_fs_byte(name+i))!='\0')  
        {  
            tempname[i] = temp;  
            i++;  
        }  
        tempname[i]='\0';  
        return tempname;      
    }  
    int next(int i)  
    {     
        return (i+1==Maxlength)?0:i+1;   
    }  
      
    void initQue(queue * q)  
    {  
        q->front = 0;  
        q->rear = Maxlength - 1;  
    }  
      
    int empty(queue* q)  
    {  
        if(next(q->rear) == q->front ){  
        printk("isempty\n");  
            return 1;  
        }  
        else  
            return 0;  
    }  
    int isFull(queue* q)  
    {  
        if(q->front==(q->rear+2)%Maxlength){  
        printk("ifFull,%d  %d\n",q->front,q->rear);     
        return 1;  
        }  
        else   
        return 0;     
    }  
    struct task_struct * getFront( queue * q )  
    {  
        int temp;  
        if( !empty(q) )  
        {  
            temp = q->front;  
            q->front = next( q->front );  
            return q->wait[temp];  
        }  
        else  
            return NULL;  
    }  
      
    int insertRear( struct task_struct * child, queue * q)  
    {  
        if(isFull(q))  
            return -1;  
        q->rear = next( q->rear );  
        q->wait[q->rear] = child;  
    }  
      
    void sleep_on_sem(void)  
    {  
            current->state=TASK_UNINTERRUPTIBLE;  
            schedule();  
    }  
      
    void wake_on_sem(struct task_struct *p)  
    {  
          if(p != NULL)  
                (*p).state = TASK_RUNNING;  
    }  
      
    int sys_sem_open(const char *name, unsigned int value)  
    {  
        int i = 0;  
        char* tempname = malloc(sizeof(char)*20);  
          
        tempname=get_name(name);  
        if (!(i=find_sem(tempname))){  
        return &sem_array[i];  
        }  
        for (i = 0; i < SEM_NUM; i++)  
        {  
            if (!sem_array[i].used)  
            {  
                strcpy(sem_name[i],tempname);  
                sem_array[i].value = value;  
                sem_array[i].used = 1;  
                initQue( &(sem_array[i].waitsem));  
                return &sem_array[i];  
            }  
        }  
        return -1;  
    }  
      
    int sys_sem_wait(sem_t* sem)  
    {  
        cli();  
        sem->value--;  
        if(sem->value < 0)  
        {  
            insertRear( current, &(sem->waitsem));  
            sleep_on_sem();  
        }  
        sti();  
        return 0;  
    }  
      
    int sys_sem_post(sem_t * sem)  
    {  
        cli();  
        sem->value++;  
        if(sem->value<=0)  
        {  
            wake_on_sem(getFront(&(sem->waitsem)));  
        }  
        sti();  
        return 0;  
    }  
      
      
    int sys_sem_unlink(const char *name)  
    {  
        int locate = 0;  
        char* tempname = malloc(sizeof(char)*20);  
        tempname=get_name(name);  
        if (!(locate=find_sem(tempname))){  
            sem_array[locate].used = 0;  
            sem_array[locate].value = 0;  
            sem_name[locate][0] = '\0';  
            return 0;  
        }      
        return -1;  
    }  
