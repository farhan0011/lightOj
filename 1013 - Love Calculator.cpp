#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[35][35];
string A,B;
int f(int i,int j)
{
    if(i == A.size())
        return B.size()-j;
    if(j == B.size())
        return A.size()-i;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans = 0;
    if(A[i] == B[j])
        ans = 1 +f(i+1,j+1);
    else
    ans = 1 + min(f(i+1,j),f(i,j+1));
    dp[i][j] = ans;
}
ll dp1[70][35][35];
ll L;
ll g(int l,int i,int j)
{
    if(i == A.size() && j == B.size())
    {
        if(l == L)
            return 1;
        else
            return 0;
    }
    if(i>A.size() || j>B.size())
        return 0;
    if(dp1[l][i][j]!= -1)
            return dp1[l][i][j];
    ll ans =0;
    if(A[i] == B[j])
        ans = g(l+1,i+1,j+1);
    else
        ans = g(l+1,i+1,j)+ g(l+1,i,j+1);
    return dp1[l][i][j]= ans;
}
int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        memset(dp,-1,sizeof dp);
        memset(dp1,-1,sizeof dp1);
       cin>>A>>B;
        L = f(0,0);
       ll Y = g(0,0,0);
    cout<<"Case "<<t<<": "<<L<<" "<<Y<<endl;
    }

}
