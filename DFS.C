#include<stdio.h>
#include<conio.h>

void dfs(int);
int i,j,n,a[10][10],vis[10];

void main()
{

   printf("enter the number of vertices\n");
   scanf("%d",&n);
   printf("enter the adjacency matrix\n");

   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
     {
       scanf("%d",&a[i][j]);
     }
   }

   for(i=1;i<=n;i++)
   {
     vis[i]=0;
   }

    printf("dfs traversal\n");
    for(i=1;i<=n;i++)
    {
      if(vis[i]==0)
       dfs(i);
    }
    getch();
}


void dfs(int v)
{
   int i;
   vis[v]=1;
   printf("%d",v);
   for(i=1;i<=n;i++)
   {
       if(a[v][i]==1 && vis[i]==0)
       {
	   dfs(i);
	}
    }
}
