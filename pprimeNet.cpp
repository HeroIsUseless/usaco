/*
ID:22920179
PROB:pprime
LANG:C++
*/
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
 
long a,b;
set<int> s;
long f[15000];
 
bool isprime(long x)
{
     for(int i=2;i*i<=x;i++)
     {
             if(x%i==0)return 0;
              
     } 
     return 1;
 }
 
void palindrome()
{
     int cnt=0;
     for(int i=1;i<10000;i++)
     {
             long num=i,re;
             for(re=i;num!=0;num/=10)
             {
                 re=re*10+num%10;
             }
             if(isprime(re)){f[cnt]=re;cnt++;}
     
             num=i/10;
             
             for(re=i;num!=0;num/=10)
             {
                 re=re*10+num%10;
             }
             if(isprime(re)){f[cnt]=re;cnt++;}
     }
     sort(f,f+cnt);
 }
 
int main()
{
    palindrome();
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    while(cin>>a>>b&&a&&b)
    {
        
        for(int i=0;f[i]<=b;i++)
        {
                if(f[i]>=a)cout<<(int)f[i]<<endl;
        }
       
    }
    
    return 0;
}                                 
