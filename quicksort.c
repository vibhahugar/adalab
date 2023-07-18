#include<stdio.h>

void qsort(int a[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=partition(a,low,high);
        qsort(a,low,mid-1);
        qsort(a,mid+1, high);
    }
}

int partition(int a[],int low, int high)
{
    int i,j,temp, pivot;
    pivot=a[low];
    i=low+1;
    j=high;

    while(i<=j)
    {
        while(a[i]<=pivot)
            i++;
        while(a[j]>pivot)
            j--;

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }

    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}

int main()
{
    int a[30],n,i;
    printf("Enter no of elements:");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    qsort(a,0,n-1);
    printf("\nSorted array is :");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);

    return 0;
}
