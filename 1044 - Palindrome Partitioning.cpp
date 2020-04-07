#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int dp1[1010];
string s;
int n;
int f(int st,int ed)
{
    if(st>=ed)
        return 1;
        if(dp[st][ed]!= -1)
            return dp[st][ed];
    int ans = 0;
    if(s[st] == s[ed] && f(st+1,ed-1))
        ans = 1;
    return dp[st][ed] = ans;
}
int g(int in)
{
    if(dp1[in]!= -1)
        return dp1[in];
    int ans = INT_MAX;
    if(f(0,in))ans = 1;
    else{
        for(int i=in; i>0; i--)
            {
                if(f(i,in))
                 ans =min(ans ,1 + g(i-1));
            }
    }
    return dp1[in] = ans;
}
int main()
{
   int T;
   cin>>T;
   for(int t=1; t<=T; t++)
   {
       cin>>s;
       memset(dp,-1,sizeof dp);
       memset(dp1,-1,sizeof dp1);
       cout<<"Case "<<t<<": "<<g(s.size()-1)<<endl;
   }
}
