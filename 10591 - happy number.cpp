#include<iostream>
using namespace std;
int sum_of_sqre(int n)
{
    if(n==0)
        return 0;
    return ((n%10)*(n%10))+sum_of_sqre(n/10);
}
int main()
{
    int N,i,num,test;
    cin>>N;
    for(i=1;i<=N;i++)
    {
        cin>>num;
        test=sum_of_sqre(num);
        while((test/10)!=0)
        {
            test=sum_of_sqre(test);
        }
        if(test==1)
            cout<<"Case #"<<i<<": "<<num<<" is a Happy number."<<endl;
        else
            cout<<"Case #"<<i<<": "<<num<<" is an Unhappy number."<<endl;

    }
    return 0;
}
