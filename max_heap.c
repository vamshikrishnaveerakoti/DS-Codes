//Implementation of Max_Heap

#include<stdio.h>
int n=10;
int swap(int i,int min,int a[n])
{
    int temp = a[i];
    a[i] = a[min];
    a[min] = temp;
}

int heapify(int a[10],int i)
{
    int l = (2*i)+1;
    int r = (2*i)+2;
    int max =-1;
    if(n>r)
    {
        if(a[l]<=a[r])
        {
            max = r;
        }
        else 
        {
            max = l;
        }
    }
    else if(n>l)
    {
        max = l;
    }
    if(a[i]<=a[max] && max!=-1)
    {
        swap(i,max,a);
        heapify(a,max);
        
    }
}

int main()
{
    int a[10] = {1,5,7,9,15,17,19,157,159,1579};
    for(int i=n/2;i>=0;i--)
    {
        heapify(a,i);
    }
    for(int i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
}

//done By VEERAKOTI.VAMSHI KRISHNA {B171579}
