#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int hashf(char ch)
{
    if('0'<=ch && ch<='9')
        return ch-48;
    if('A'<=ch && ch<='Z')
        return ch-55;
}
int main()
{
    int i,len,is_pal=1,is_mir=1;
    char s[21];
    char rev[]="01SE0Z0080A000300HIL0JM0O0002TUVWXY5";
    while(scanf("%s",s)!=EOF)
    {
        is_pal=1;
        is_mir=1;
        len=strlen(s);
        for(i=0;i<len/2;i++)
        {
            if(s[i]!=s[len-i-1])
            {
                is_pal=0;
                break;
            }

        }
        for(i=0;i<=(len/2);i++)
        {
            if(s[i]!=rev[(hashf(s[len-i-1]))])
            {
                is_mir=0;
                break;
            }

        }
        if(is_pal==0 && is_mir==0) cout<<s<<" -- is not a palindrome."<<endl;
        else if(is_pal==1 && is_mir==0) cout<<s<<" -- is a regular palindrome."<<endl;
        else if(is_pal==0 && is_mir==1) cout<<s<<" -- is a mirrored string."<<endl;
        else cout<<s<<" -- is a mirrored palindrome."<<endl;
        cout<<endl;
    }
    return 0;
}
