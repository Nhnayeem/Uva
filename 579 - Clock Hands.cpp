#include<stdio.h>
double scan(double* H,double* M)
{
    scanf("%lf:%lf",H,M);
    return *H+*M;
}
int main()
{
    double H,M,D;
    while(scan(&H,&M))
    {
        D=(0.5*(60.0*H-11.0*M));
        if(D<0)
            D=D*-1.0;
        if(D>180)
            D=360-D;
        printf("%.3lf\n",D);
    }
    return 0;
}
