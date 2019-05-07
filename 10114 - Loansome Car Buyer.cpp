#include<stdio.h>
int main()
{
    int i;
    double M,dP,L,C,D,m;
    while(1)
    {
        scanf("%lf %lf %lf %lf",&M,&dP,&L,&D);
        if(M<0)
            break;
        i=D;
        double Dt[i][2];
        for(i=0;i<D;i++)
        {
            scanf("%lf %lf",&Dt[i][0],&Dt[i][1]);
        }
        i=0;
        m=0;
        C=L+dP;
        dP=L/M;
        C=C-(C*Dt[i][1]);
        while(C<=L)
        {
            m=m+1;
            if((i+1)<D)
                if(m>=Dt[i+1][0])
                    i++;
            L=L-dP;
            C=C-(C*Dt[i][1]);

        }
        printf("%d month",(int)m);
        if(m!=1)
            printf("s");
        printf("\n");
    }
    return 0;
}
