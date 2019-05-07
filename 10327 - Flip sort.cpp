#include<stdio.h>
int main()
{
    int n,i,j,temp,c;
    bool flip;
    int data[10001];
    while(scanf("%d",&n)!=EOF)
    {
        c=0;
        for(i=0;i<n;i++)
            scanf("%d",&data[i]);
        for(i=0;i<n-1;i++)
        {
            flip=false;
            for(j=0;j<n-i-1;j++)
            {
                if(data[j]>data[j+1])
                {
                    temp=data[j];
                    data[j]=data[j+1];
                    data[j+1]=temp;
                    c++;
                    flip=true;
                }
            }
            if(flip==false)
                break;
        }
        printf("Minimum exchange operations : %d\n",c);
    }
    return 0;
}
