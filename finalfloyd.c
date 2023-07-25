#include<stdio.h>
#include<conio.h>
int c[10][10],d[10][10],n;
void floyd()
{
    int i,j,k;
    for(i=1;i<=n;i++)
    {

        for(j=1;j<=n;j++)
        {
            d[i][j]=c[i][j];
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                d[i][j]=(d[i][j]<d[i][k]+d[k][j])?d[i][j]:(d[i][k]+d[k][j]);
            }
        }

    }
}
void main()
{
    int i,j;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the weight of adjacency matrix: \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
    floyd();
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d\t",d[i][j]);
        }
        printf("\n");
    }

    printf("\n The shortest paths are:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++) {
		if(i!=j&& d[i][j]!=999)
        printf("\n <%d,%d>=%d",i,j,d[i][j]);
        }

}
