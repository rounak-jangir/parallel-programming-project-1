#include<stdio.h>
#include<pthread.h>
#include<time.h>

void *matrix_multiply(void *);
clock_t start, end ;

//Declaration of the initial matrix
int a[500][500];
int b[500][500];
int c[500][500];


int row1,col1,row2,col2;
int temp;


int main()
{
  start=clock(); // Noting the starting time of the clock.
    
  int i,j,k;

  pthread_t tid; // Declaring the array of the threads
  
  // Code snippet for initializing the array a
  for(i=0;i<500;i++)
  {
     for(j=0;j<500;j++)
     {
        a[i][j]=1;
     }
  }

  printf("\n");

  for(i=0;i<500;i++)
  {
     for(j=0;j<500;j++)
     {
        b[i][j]=1;
     }
  }
    // Checking the condition if column of first matrix is equal to row of the second matrix 
    if(col1!=row2)
    {
      printf("Matrix multipliclation is not possible");
    }
    
    else
    {
      for(i=0;i<500;i++)
      {  
        for(j=0;j<500;j++)
        {
           int a[2];
           a[0]=i;
           a[1]=j;
	      temp=i%500;
           // Creating the pthread
           pthread_create(&tid,NULL,matrix_multiply,(void *)&a);
           // Joining all the threads
           pthread_join(tid,NULL);
        } 
      }
    }

      
    double cpu_time_used;
    end=clock(); // Noting the end time of the clock
    cpu_time_used=((double)(end-start));
   // printf("CPU time taken is %lf",cpu_time_used);
    return 0;
}

void *matrix_multiply(void *p)
{  
     int k,i;
     int *q;
  
     int sum=0;
     q=(int *)p;

     for(k=0;k<col1;k++)
     { 
        sum+=a[*q][k]*b[k][*(q+1)];
     }
     
     c[*q][*(q+1)]=sum;
       
     pthread_exit(NULL);
}
