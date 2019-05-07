#include<stdio.h>
#include<math.h>
typedef struct
{
    double x;
    double y;
    double cof_g;
    double cof_f;
    double cof_c;
    double d;
}point;
int print_shrt(double g,double f,double c);
int print_long(double g,double f,double c);
int main()
{
    point a1,a2,a3;
    double g,f,c,det_g,det_f,det_c,det_d;
    while(scanf("%lf %lf %lf %lf %lf %lf",&a1.x,&a1.y,&a2.x,&a2.y,&a3.x,&a3.y)!=EOF)
    {
    a1.cof_g=2*a1.x;
    a1.cof_f=2*a1.y;
    a1.d=-(a1.x*a1.x+a1.y*a1.y);
    a2.cof_g=2*a2.x;
    a2.cof_f=2*a2.y;
    a2.d=-(a2.x*a2.x+a2.y*a2.y);
    a3.cof_g=2*a3.x;
    a3.cof_f=2*a3.y;
    a3.d=-(a3.x*a3.x+a3.y*a3.y);
    det_d=(a2.cof_g*a3.cof_f-a3.cof_g*a2.cof_f)-(a1.cof_g*a3.cof_f-a3.cof_g*a1.cof_f)+(a1.cof_g*a2.cof_f-a2.cof_g*a1.cof_f);
    det_g=(a2.d*a3.cof_f-a3.d*a2.cof_f)-(a1.d*a3.cof_f-a3.d*a1.cof_f)+(a1.d*a2.cof_f-a2.d*a1.cof_f);
    det_f=(a2.cof_g*a3.d-a3.cof_g*a2.d)-(a1.cof_g*a3.d-a3.cof_g*a1.d)+(a1.cof_g*a2.d-a2.cof_g*a1.d);
    det_c=a1.cof_g*(a2.cof_f*a3.d-a3.cof_f*a2.d)-a1.cof_f*(a2.cof_g*a3.d-a3.cof_g*a2.d)+a1.d*(a2.cof_g*a3.cof_f-a3.cof_g*a2.cof_f);
    g=det_g/det_d;
    f=det_f/det_d;
    c=det_c/det_d;
    print_shrt(g,f,c);
    print_long(g,f,c);
    }
    return 0;
}
int print_shrt(double g,double f,double c)
{
    printf("(x");
    if(g>=0)
        printf(" + %0.3lf)^2",g);
    else
        printf(" - %0.3lf)^2",g*-1);
    printf(" + (y");
    if(f>=0)
        printf(" + %0.3lf)^2",f);
    else
        printf(" - %0.3lf)^2",f*-1);
    printf(" = %0.3lf^2\n",sqrt(g*g+f*f-c));
    return 0;
}
int print_long(double g,double f,double c)
{
    printf("x^2 + y^2");
    if(g>=0)
        printf(" + %0.3lfx",2*g);
    else
        printf(" - %0.3lfx",-2*g);
    if(f>=0)
        printf(" + %0.3lfy",2*f);
    else
        printf(" - %0.3lfy",-2*f);
    if(c>=0)
        printf(" + %0.3lf = 0",c);
    else
        printf(" - %0.3lf = 0",-1*c);
    printf("\n\n");
    return 0;
}
