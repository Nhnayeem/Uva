#include<stdio.h>
int cyclelen(int n)
{
    int len=1;
    while(n!=1)
    {
        if(n%2==0)
        {
            n=n/2;
        }
        else
        {
            n=3*n+1;
        }
        len++;
    }
    return len;
}
main()
{
   int i,j,k,maxlen;
   while(scanf("%d %d",&i,&j)!=EOF)
   {
       maxlen=0;
       if(i<j)
       {
           for(k=i;k<=j;k++)
            {
                if(cyclelen(k)>maxlen)
                    maxlen=cyclelen(k);
            }
       }
       else
       {
            for(k=j;k<=i;k++)
            {
                if(cyclelen(k)>maxlen)
                    maxlen=cyclelen(k);
            }
       }
       printf("%d %d %d\n",i,j,maxlen);
   }
   return 0;
}
