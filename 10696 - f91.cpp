#include<iostream>
using namespace std;
int f91(int n)
{
    if(n<=100)
        return f91(f91(n+11));
    if(n>=101)
        return n-10;
}
int main()
{
    int N;
    cin>>N;
    while(N)
    {
        cout<<"f91("<<N<<") = "<<f91(N)<<endl;
        cin>>N;
    }
    return 0;
}
