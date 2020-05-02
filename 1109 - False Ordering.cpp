#include<bits/stdc++.h>
using namespace std;
#define LIM 1000
bool flag[102];
vector<int>prime;
struct info
{
    int a,b;
};
bool cmp(info p,info q)
{
    if(p.b == q.b)
        return p.a>q.a;
    return p.b<q.b;
}
info fact[LIM+10];
void pre()
{
    fact[1].a = 1;
    fact[1].b = 1;
     for(int i=2;i<=1000;i++)
     {
         int ans=1;
         int n = i;
         for(int j=2;j<=31;j++)
         {
             int cnt=0;
             while(n%j==0)
             {
                 cnt++;
                 n/=j;
             }
             ans*=(cnt+1);
         }
         if(n>1)
            ans*=2;
         fact[i].a=i;
         fact[i].b=ans;

     }
     sort(fact,fact+1001,cmp);

}
int main()
{
    pre();
//    for(int i=1;i<=1000;i++)
//        cout<<fact[i].a<<" "<<fact[i].b<<endl;
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        int n;
        cin>>n;
        cout<<"Case "<<t<<": "<<fact[n].a<<endl;
    }

}
