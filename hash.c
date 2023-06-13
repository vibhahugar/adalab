#include<stdio.h>
#include<conio.h>
void linearInsert(int h[10])
{
    int key,i,hkey,index,choice;
    while(1)
    {
       printf("Enter the number:");
       scanf("%d",&key);
        hkey=key%10;
        for(i=0;i<10;i++)
        {
            index=(hkey+i)%10;
            if(h[index]==-1)
            {
                h[index]=key;
                break;
            }
        }
        if(i==10)
        {
            printf("Element cannot be inserted\n");
        }
        printf("Do you want to insert another element yes=1,no=0:");
        scanf("%d",&choice);
        if(choice==0)
            break;
    }
}
void quadraticInsert(int h[10])
{
    int key,i,hkey,index,choice;
    while(1)
    {
       printf("Enter the number:");
       scanf("%d",&key);
        hkey=key%10;
        for(i=0;i<10;i++)
        {
            index=(hkey+(i*i))%10;
            if(h[index]==-1)
            {
                h[index]=key;
                break;
            }
        }
        if(i==10)
        {
            printf("Element cannot be inserted\n");
        }
        printf("Do you want to insert another element yes=1,no=0:");
        scanf("%d",&choice);
        if(choice==0)
            break;
    }
}
void doubleHashInsert(int h[10])
{
    int key,i,hkey,index,choice,rehash;
    while(1)
    {
       printf("Enter the number:\t");
       scanf("%d",&key);
        hkey=key%10;
        rehash=7-key%7;
        for(i=0;i<10;i++)
        {
            index=(hkey+(i*rehash))%10;
            if(h[index]==-1)
            {
                h[index]=key;
                break;
            }
        }
        if(i==10)
        {
            printf("Element cannot be inserted\n");
        }
        printf("Do you want to insert another element yes=1,no=0:");
        scanf("%d",&choice);
        if(choice==0)
            break;
    }
}
void display(int h[10])
{
    for(int i=0;i<10;i++)
    {
        if(h[i]!=-1)
        {
            printf("%d element is inserted at %d position\n",h[i],i);
        }

    }
}

void main()
{
   int ch,h[10];
   for(int i=0;i<10;i++)
    {
        h[i]=-1;
    }
    printf("1.Linear Probing\t2.Quadratic Probing\t3.Double Hashing\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:linearInsert(h);
                break;
        case 2:quadraticInsert(h);
                break;
        case 3:doubleHashInsert(h);
                break;
        default:printf("wrong choice");
    }
 display(h);
}
