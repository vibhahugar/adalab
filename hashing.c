#include <stdio.h>
#include<stdlib.h>
int i,j,tsize,n,j,arr[20],hasht[20],ch,key,key1,t;
int hashh(int a){
    int i;
    i=a%20;
    return(i);
}

int probel(int a){
    int i;
    i=(a+1)%20;
    return(i);
}
int probeq(int a,int j){
    int i;
    i=(a+(j*j))%20;
    return(i);
}
int probed(int key,int val,int j){
    int i;
    i=key+j*((13-(val%13))%20);
    return(i);
}

int main()
{
    printf("Enter no of table ele \n");
    scanf("%d",&n);
    printf("Enter the ele \n");
    for(i=0;i<n;i++) {
      printf("Enter the %d th ele \n",i);
      scanf("%d",&arr[i]);
    }
    for(i=0;i<20;i++){
        hasht[i]=-1;
    }

    printf(" \n 1. Linear Probing \n 2. Quad Probing \n 3. Double hashing \n 4. Exit \n");
   printf("Enter your choice \n");
   scanf("%d",&ch);
   switch(ch) {
       case 1:
       for(i=0;i<n;i++){
        key=hashh(arr[i]);
        while(hasht[key]!=-1){
            key=probel(key);
        }
        hasht[key]=arr[i];
        printf(" \n Ele %d inserted at %d \t",arr[i],key);
       }
       break;

        case 2:
       for(i=0;i<n;i++){
        key=hashh(arr[i]);
        j=1;
        key1=key;
        while(hasht[key1]!=-1){
            key1=probeq(key,j);
            j++;
        }
        hasht[key1]=arr[i];
         printf("\n Ele %d inserted at %d \t",arr[i],key1);
       }
       break;

       case 3:
        for(t=0;t<n;t++){
        key=hashh(arr[t]);
        j=1;
        key1=key;
        while(hasht[key1]!=-1){
            key1=probed(key,arr[t],j);
            j++;
        }
        hasht[key1]=arr[t];
         printf("\n Ele %d inserted at %d %d %d \t",arr[t],key1,t,n);
       }
       break;


       case 4:
       exit(0);
       break;

       default:
       printf("Wrong choice \n");
       break;

   }

    return 0;
}
