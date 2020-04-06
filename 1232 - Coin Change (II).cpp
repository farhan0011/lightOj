#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000007
int dp[105][10005];
int A[105];
int n,k;
//ll f(int in,int rem)
//{
//    if(rem < 0)
//        return 0;
//    if(in == n)
//    {
//        if(rem == 0)
//            return 1;
//        else
//            return 0;
//    }
//    if(dp[in][rem] != -1)
//        return dp[in][rem];
//    ll a = f(in,rem - A[in]) % mod;
//    ll b = f(in + 1,rem) % mod;
//    return dp[in][rem] = (a+b) % mod;
//}
ll g(int c,int r)
{
    dp[n][0] = 1;
    for(int i=1;i<=10000;i++)
        dp[n][i] = 0;
    for(int in = n-1; in>=0; in--)
    {
        ll a = 0,b = 0;
        for(int rem = 0;rem<=10000; rem++)
        {
            if(rem-A[in]>=0)
            a = dp[in][rem-A[in]] % mod;
            b = dp[in+1][rem] % mod;
            dp[in][rem] = (a+b) % mod;
        }
    }
    return dp[c][r];
}
int main()
{
    int T;
    cin>>T;

    for(int t=1; t<=T; t++)
    {
        memset(dp,-1,sizeof dp);
        cin>>n>>k;
        for(int i=0; i<n; i++)
            cin>>A[i];
        cout<<"Case "<<t<<": "<<g(0,k)<<endl;
    }
}
