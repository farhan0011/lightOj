#include<bits/stdc++.h>
using namespace std;
int dp[55][55][55];
string A,B,C;
int f(int i,int j,int k)
{
    if(i == A.size() || j == B.size() || k == C.size())
        return 0;
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    int a=0,b=0,c=0,d=0;
    if(A[i] == B[j] && A[i] == C[k])
    {
        a = 1 + f(i+1,j+1,k+1);
    }
    b = f(i+1,j,k);
    c = f(i,j+1,k);
    d = f(i,j,k+1);
    return dp[i][j][k] = max(a,max(b,max(c,d)));
}
int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        memset(dp,-1,sizeof dp);
        cin>>A>>B>>C;
        cout<<"Case "<<t<<": "<<f(0,0,0)<<endl;
    }
}
