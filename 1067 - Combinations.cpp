#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000003
#define LIM 1000000
ll fact[LIM+10];
void pre()
{
    fact[0] = fact[1] = 1;
    for(int i=2;i<=LIM;i++)
    {
        fact[i] = (i * fact[i-1])%mod;
        if(fact[i]<0)
            fact[i]+=mod;
    }
}
ll bigmod(int x,int y)
{
    if(!y)
        return 1;
    if(y%2)
        return (x*bigmod(x,y-1))%mod;
    ll ans = bigmod(x,y/2)%mod;
    ans = (ans*ans)%mod;
    if(ans<0)
        ans+=mod;
    return ans;
}
int main()
{
    pre();
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        int n,r;
        cin>>n>>r;
        ll lob = fact[n];
        ll ans = (lob  * bigmod(fact[n-r],mod-2))%mod;
        if(ans<0)
            ans+=mod;
        ans = (ans *bigmod(fact[r],mod-2))%mod;
        //cout<<fact[n]<<" "<<fact[n-r]<<" "<<fact[r]<<endl;
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
}
