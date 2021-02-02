//Bubble Sorting

#include<stdio.h>

int main()
{
    //BUBBLE SORT
    int a[10] = {1,5,7,9,15,17,19,157,159,1579};
    int n=10,temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>=a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

//Done by VEERAKOTI.VAMSHI KRISHNA {B171579}
