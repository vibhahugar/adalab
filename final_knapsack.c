#include<stdio.h>
#include<conio.h>
int n,m,w[10],p[10],v[10][10],x[10];
void knapsack()
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0||j==0)
                v[i][j]=0;
            if(w[i]>j)
                v[i][j]=v[i-1][j];
            else
                v[i][j]=(v[i-1][j]>v[i-1][j-w[i]]+p[i])?v[i-1][j]:v[i-1][j-w[i]]+p[i];
        }
    }
    object_selected();
}
void object_selected()
{
    int i,j;
    printf("Optimal solution:%d\n",v[n][m]);
    for(i=1;i<=n;i++)
        x[i]=0;
        i=n;
        j=m;
    while(i!=0 && j!=0)
    {
        if(v[i][j]!=v[i-1][j])
        {
            x[i]=1;
            j=j-w[i];
        }
        i--;
    }
    for(i=1;i<=n;i++)
    {
        if(x[i]==1)
        {
            printf("Object %d is selected\n",i);
        }
    }
}
void main()
{
    int i;
    printf("Emter number of objects:");
    scanf("%d",&n);
    printf("\nMaximum capacity:");
    scanf("%d",&m);
    printf("\nEnter weights of the objects:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }
    printf("\nEnter profits of the objects:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    knapsack();
}
