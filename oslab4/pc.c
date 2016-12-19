    #define   __LIBRARY__  
    #include <sys/stat.h>  
    #include <sys/types.h>  
    #include  <unistd.h>  
    #include <fcntl.h>  
    #include <stdio.h>  
    #include <stdlib.h>  
    #include <semaphore.h>  
    int input_num(FILE* fp, int put_pos,int num){  
        fseek( fp, put_pos*sizeof(int) , SEEK_SET );  
        int run_code=fwrite( &num, 1, sizeof(num), fp);       
        fflush(fp);  
        return run_code;      
    }  
    int output_num(FILE* fp, int get_pos,int* num){  
        fseek( fp, get_pos*sizeof(int) , SEEK_SET );  
        return fread( num, sizeof(int),1, fp);    
    }  
    int main()  
    {  
        int const NUM=100;  
        int const PRONUM=5;  
        int const MAXSIZE=10;  
        int  i,j,k;  
        int  cost_num;  
        int  get_pos = 0;  
        int  put_pos = 0;  
        sem_t   *empty, *full, *mutex;  
        FILE *fp = NULL;  
        empty =(sem_t *)sem_open("empty",O_CREAT,0064,10);  
        full  = (sem_t *)sem_open("full",O_CREAT,0064,0);  
        mutex = (sem_t *)sem_open("mutex",O_CREAT,0064,1);  
        fp=fopen("filebuffer.txt", "wb+");  
        input_num(fp,10,get_pos);  
      
        if( !fork() )  
        {  
          
            for( i = 0 ; i < NUM; i++)  
            {  
                sem_wait(empty);  
                sem_wait(mutex);  
            input_num(fp,put_pos,i);  
                put_pos = ( put_pos + 1)% MAXSIZE;  
                sem_post(mutex);  
                sem_post(full);  
            }  
            exit(0);  
        }  
      
        for( k = 0; k < PRONUM ; k++ )  
        {  
            if( !fork() )  
            {  
                for( j = 0; j < NUM/PRONUM; j++ )  
                {  
                    sem_wait(full);  
                    sem_wait(mutex);  
            fflush(stdout);  
                    output_num(fp,10,&get_pos);  
                    output_num(fp,get_pos,&cost_num);  
                    printf("%d:   %d\n",getpid(),cost_num);  
                    fflush(stdout);  
                    get_pos = (get_pos + 1) % MAXSIZE;  
            input_num(fp,10,get_pos);  
                    sem_post(mutex);  
                    sem_post(empty);  
                }  
               exit(0);  
            }  
        }  
        wait(NULL);  
      
        sem_unlink("empty");  
        sem_unlink("full");  
        sem_unlink("mutex");  
      
        fclose(fp);  
        return 0;  
    }  
