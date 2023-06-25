
#include<stdio.h>
#include<conio.h>

void dfs(int n,int a[10][10],int v);
int vis[10];

void main()
{
   int n,i,j,src,a[10][10],flag=0;
   clrscr();
   printf("enter the number of vertices\n");
   scanf("%d",&n);
   printf("enter the adjacency matrix\n");
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
     {
       scanf("%d",&a[i][j]);
     }
     vis[i]=0;
    }
    printf("enter the source vertex\n");
    scanf("%d",&src);
    if(src<=n)
    {
	dfs(n,a,src);
	printf("nodes reachable from %d source\n",src);
	for(i=1;i<=n;i++)
	   if(vis[i])
	      printf("%d",i);

    }
    for(i=1;i<=n;i++)
      if(vis[i]!=1)
	 flag=1;
      if(flag)
	 printf("unconnected\n");
      else
	printf("connected\n");
    getch();
}

void dfs(int n,int a[10][10],int v)
{
   int j;
   vis[v]=1;
   for(j=1;j<=n;j++)
   {
       if(a[v][j]==1 && vis[j]==0)
	   dfs(n,a,j);
   }
}

/*OUTPUT:

enter n
4
enter adjacency matrix
0 1 0 1
0 0 1 0
0 0 0 0
0 0 1 0
enter source vertex
1
nodes reachable from 1
1 2 3 4
connected

enter n
4
enter adjacency matrix
0 1 0 1
1 0 0 0
0 0 0 0
0 1 0 0
enter source vertex
1
nodes reachable from 1
1 2 4
unconnected  */
