#include<stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>


int q[2000],top=-1,front=-1,rear=-1,a[2000][2000],vis[2000],stack[2000];
int delete();
void add(int item);
void bfs(int s,int n);
void dfs(int s,int n);
void push(int item);
int pop();

double
now()
{
 struct timeval tv;
 gettimeofday(&tv, 0);
 return tv.tv_sec + tv.tv_usec / 1000000.0;
}

void main()
{
int n,i,s,ch,j;
char c,dummy;
  double t1, t0;

 //printf("ENTER THE NUMBER VERTICES ");
scanf("%d",&n);
printf("NUMBER OF VERTICES : %d",n);
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
 //printf("ENTER 1 IF %d HAS A NODE WITH %d ELSE 0 ",i,j);
scanf("%d",&a[i][j]);
}
}
//printf("THE ADJACENCY MATRIX IS\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
//printf(" %d",a[i][j]);
}
//printf("\n");
}

do
{
for(i=1;i<=n;i++)
vis[i]=0;
// printf("\nMENU");
// printf("\n1.B.F.S");
// printf("\n2.D.F.S");
// printf("\nENTER YOUR CHOICE\n");
scanf("%d",&ch);
// printf("ENTER THE SOURCE VERTEX :");
scanf("%d",&s);

switch(ch)
{	
case 1:
printf("\nThe result from bfs is as follows: \n");
t0=now();
bfs(s,n);
t1=now();
 printf("\nCompletion time for bfs = %f\n", t1-t0);

break;
case 2:
printf("\nThe result from dfs is as follows: \n");
t0=now();
dfs(s,n);
t1=now();
 printf("\nCompletion time for dfs = %f\n", t1-t0);

break;
}
// printf("DO U WANT TO CONTINUE(Y/N) ?\n ");
scanf("%c",&dummy);
scanf("%c",&c);
}while((c=='y')||(c=='Y'));
printf("\n");
}


//**************BFS(breadth-first search) code**************//
void bfs(int s,int n)
{
int p,i;
add(s);
vis[s]=1;
p=delete();
if(p!=0)
printf(" %d",p);
while(p!=0)
{
for(i=1;i<=n;i++)
if((a[p][i]!=0)&&(vis[i]==0))
{
add(i);
vis[i]=1;
}
p=delete();
if(p!=0)
printf(" %d ",p);
}
for(i=1;i<=n;i++)
if(vis[i]==0)
bfs(i,n);
}


void add(int item)
{
if(rear==1999)
printf("QUEUE FULL");
else
{
if(rear==-1)
{
q[++rear]=item;
front++;
}
else
q[++rear]=item;
}
}
int delete()
{
int k;
if((front>rear)||(front==-1))
return(0);
else
{
k=q[front++];
return(k);
}
}


//***************DFS(depth-first search) code******************//
void dfs(int s,int n)
{
int i,k;
push(s);
vis[s]=1;
k=pop();
if(k!=0)
printf(" %d ",k);
while(k!=0)
{
for(i=1;i<=n;i++)
if((a[k][i]!=0)&&(vis[i]==0))
{
push(i);
vis[i]=1;
}
k=pop();
if(k!=0)
printf(" %d ",k);
}
for(i=1;i<=n;i++)
if(vis[i]==0)
dfs(i,n);
}
void push(int item)
{
if(top==1999)
printf("Stack overflow ");
else
stack[++top]=item;
}
int pop()
{
int k;
if(top==-1)
return(0);
else
{
k=stack[top--];
return(k);
}
}

/* Output of BFS(breadth-first search) and DFS(depth-first search) program */

