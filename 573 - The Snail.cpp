#include<stdio.h>
#include<math.h>
double scan(double* H,double* U,double* D,double* F)
{
    scanf("%lf %lf %lf %lf",H,U,D,F);
    return *H;
}
int main()
{
    double H,U,D,F,day,n;
    while(scan(&H,&U,&D,&F))
    {
        F=((U*F)/100.0);
        n=0;
        day=0;
        while(1)
        {
            day++;
            n=n+U;
            if((U-F)>=0)
                U=U-F;
            if(n<0 || n>H)
                break;
            n=n-D;
            if(n<0 || n>H)
                break;
        }
        if(n>0)
            printf("success on day %d\n",(int)day);
        else
            printf("failure on day %d\n",(int)day);
    }
    return 0;
}
