
#include<bits/stdc++.h>
using namespace std;
int dp[1010][4];
int dp1[1010][4];
#define mod 10007
int G[4][4] = {
     {1, 1, 1, 1},
     {0, 0, 1, 1},
     {0, 1, 0, 1},
     {1, 0, 0, 0}
};
struct matrix
{
    int mat[4][4];
    matrix(int type)
    {
        memset(mat,0,sizeof mat);
        if(type == 1)
        {
            for(int i=0,j=0;i<4,j<4;i++,j++)
                mat[i][j] = 1;
        }
        else if(type == 2)
        {
            mat[0][0] = mat[0][1] = mat[0][2] = mat[0][3] = 1;
            mat[1][2] = mat[1][3] = 1;
            mat[2][1] = mat[2][3] = 1;
            mat[3][0] = 1;
        }
    }
};
matrix matMul(matrix a,matrix b)
{
    matrix ans = matrix(0);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
                {
                    ans.mat[i][j] =(ans.mat[i][j]+a.mat[i][k]*b.mat[k][j])%mod;
                    ans.mat[i][j]%=mod;
                }
        }
    }
    return ans;
}
matrix matBigmod(matrix x,int y)
{
    if(!y)
        return matrix(1);
    if(y%2)
        return matMul(matBigmod(x,y-1),x);
    matrix ans = matBigmod(x,y/2);
    return matMul(ans,ans);
}
int f(int in,int u)
{
    if(in == 0)
    {
        if(u == 0)
            return 1;
        return 0;
    }
    if(dp[in][u]!=-1)
        return dp[in][u];
    int ans = 0;
    for(int v=0; v<4; v++)
            ans+=G[u][v]*f(in-1,v);
    return dp[in][u] = ans%mod;
}
int g(int n)
{
    memset(dp1,0,sizeof dp1);
    dp1[0][0] = 1;
    for(int in=1; in<=n; in++)
    {
        for(int u=0; u<4; u++)
        {
            dp1[in][u]+= G[u][0]*dp1[in-1][0] + G[u][1]*dp1[in-1][1] + G[u][2]*dp1[in-1][2] + G[u][3]*dp1[in-1][3];
            dp1[in][u]%=mod;
        }
    }
    return dp1[n][0];
}
int mg(int n)
{
    matrix tmp = matrix(2);
    tmp = matBigmod(tmp,n);
//    for(int i=0;i<4;i++)
//    {
//        for(int j=0;j<4;j++)
//            cout<<tmp.mat[i][j]<<" ";
//        cout<<endl;
//    }
    int ans = tmp.mat[0][0];
    return ans;
}
int main()
{
    int T;
    cin>>T;
    memset(dp,-1,sizeof dp);
    for(int t=1; t<=T; t++)
    {
        int n;
        cin>>n;
        cout<<"Case "<<t<<": "<<mg(n)<<endl;
    }
}
