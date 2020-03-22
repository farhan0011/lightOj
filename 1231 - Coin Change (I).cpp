#include<bits/stdc++.h>
using namespace std;
int arr[55],coin[55],n,k;
#define mod 100000007
#define ll long long
ll dp[55][1010];
ll f(int in,int rem)
{
    if(rem<0)
        return 0;
    if(in  == n)
    {
        if(rem == 0)
            return 1;
        else
            return 0;
    }
    if(dp[in][rem] != -1)
            return dp[in][rem];
    ll ans = 0;
    for(int i=0;i<=coin[in];i++)
        ans+=f(in + 1,rem - i*arr[in])% mod;
    return dp[in][rem] = ans % mod;
}
int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        memset(dp,-1,sizeof dp);
       cin>>n>>k;
       for(int i=0;i<n;i++)
            cin>>arr[i];
       for(int i=0;i<n;i++)
            cin>>coin[i];
        cout<<"Case "<<t<<": "<<f(0,k)<<endl;
    }
}
