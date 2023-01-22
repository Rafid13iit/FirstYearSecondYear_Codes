#include<stdio.h>
#define WHITE 0
#define GREY 1
#define BLACK 2

#define INFINITY 1000000

int mtx[200][200],d[200],queue[200],v,count=0,i1=-1,i2=-1;
int colour[200],prev[200];
void BFS(int mtx[200][200],int s,int v);
int dequeue();
void print(int v);
void enqueue(int x);
int queueSize();
int main()
{
    int i,j,v,x,y,s,val,ed;
    printf("Enter the num of vertices:\n");
    scanf("%d",&v);
    for(i=0;i<=v;i++)
    {
        for(j=0;j<=v;j++)
        {
            mtx[i][j]=0;
        }
    }
    for(i=1;i<=v;i++)
    {
        scanf("%d",&val);
        mtx[0][i]=val;
        mtx[i][0]=val;
    }
    printf("Enter the num of edges:\n");
    scanf("%d",&ed);
    while(ed--)
    {
        printf("enter vertices share edge:\n");
        scanf("%d %d",&x,&y);
        mtx[x][y]=1;
        mtx[y][x]=1;
    }
    for(i=0;i<=v;i++)
    {
        for(j=0;j<=v;j++)
        {
            printf("%d ",mtx[i][j]);
        }
        printf("\n");
    }
    printf("Enter source:\n");
    scanf("%d",&s);
    BFS(mtx,s,v);
    print(v);
return 0;
}

void BFS(int mtx[200][200],int s,int v)
{
    int i,j,u;
    if(count==0)
    {
        for(i=1;i<=v;i++)
        {
            colour[i]=WHITE;
            prev[i]=-1;
            d[i]=INFINITY;
        }
    }
    colour[s]=GREY;
    prev[s]=-1;
    d[s]=0;

    enqueue(s);
    while(queueSize()!=0)
    {
       u=dequeue();
       //printf("%d ",v);
       for(i=1;i<=v;i++)
       {
           //printf("%d %d\n",mtx[u][i],mtx[0][i]);
           if(mtx[u][i]==1&&colour[i]==WHITE)
           {
               //printf("%d ",mtx[0][i]);
            colour[i]=GREY;
            prev[i]=u;
            d[i]=d[u]+1;
            //printf("%d",mtx[0][i]);
            enqueue(i);
           }
       }
      colour[u]=BLACK;
    }
   count++;
}

void enqueue(int x)
{
    if(i1==-1){
        queue[0]=x;i1++;i2++;
    }
    else { i2++;
            queue[i2]=x;
    }
}
int queueSize()
{
if(i1>i2) return 0;
else return 1;
}
int dequeue()
{
    int i=i1;
    i1++;
    return queue[i];
}
void print(int v)
{
    int i;
    for(i=1;i<=v;i++)
    {
        printf("%d ",mtx[0][i]);
    }
    printf("\n");
    for(i=1;i<=v;i++)
    {
        printf("%d ",colour[mtx[0][i]]);
    }
    printf("\n");
    for(i=1;i<=v;i++)
    {
        printf("%d ",d[mtx[0][i]]);
    }
    printf("\n");
    for(i=1;i<=v;i++)
    {
        printf("%d ",prev[mtx[0][i]]);
    }
    printf("\n");
}