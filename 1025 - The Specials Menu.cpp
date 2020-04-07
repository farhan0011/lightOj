#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[80][80];
string s;
int n;
ll f(int i,int j)
{
        if(i>j)
            return 0;
        if(i == j)
            return 1;
    if(dp[i][j] != -1)
        return dp[i][j];
    ll a = 0;
    if(s[i] == s[j])
        a += 1+f(i+1,j-1);
        a += f(i+1,j) + f(i,j-1)-f(i+1,j-1);
    return dp[i][j] = a;
}
int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        cin>>s;
        n = s.size();
        memset(dp,-1,sizeof dp);
        cout<<"Case "<<t<<": "<<f(0,n-1)<<endl;
    }
}
