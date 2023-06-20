#include<stdio.h>
void dfs(int);
int a[10][10], vis[10],n;
void main()
{
int i,j;
printf("Enter the number of vertices : ");
scanf("%d",&n);
printf("Enter adjacency matrix\n");
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
printf("DFS Traversel\n");
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
dfs(i);
}
}
