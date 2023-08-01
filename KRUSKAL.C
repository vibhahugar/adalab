#include<stdio.h>
int parent[10]={0};
int find_parent(int);
int is_cyclic(int,int);
int main()
{
    int cost[10][10],min_cost=0,min,i,j,n,no_e=1,a,b,u,v,x;
    printf("Enter number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the weight in the form of an adjacency matrix:\n");

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
              cost[i][j]=999;
        }
    }


    while(no_e<n)
    {
        min=999;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }

        u=find_parent(u);
        v=find_parent(v);
        x=is_cyclic(u,v);
        if(x==1)
        {
            printf("\n%d to %d cost=%d",a,b,min);
            no_e++;
            min_cost+=min;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("\nMinimum cost of the spanning tree is %d",min_cost);
    return 0;
}


int find_parent(int a)
{
    while(parent[a]!=0)
      a=parent[a];
    return a;
}


int is_cyclic(int a ,int b)
{
    if(a!=b)
    {
        parent[b]=a;
        return 1;
    }
    return 0;
}
