#include<bits/stdc++.h>
using namespace std;
int grid[18][18];
int dp[18][(1<<18)+100];
int target;
int n;
int setbit(int mask,int p)
{
    return mask | (1 << p);
}
int chkbit(int mask,int p)
{
    return mask & (1 << p);
}
int f(int col,int mask)
{
    if(mask == target)
        return 0;
        if(dp[col][mask] != -1)
            return dp[col][mask];
        int ans = INT_MIN;
    for(int row=0; row<n; row++)
    {
        int cost = grid[row][col];
        if(chkbit(mask,row))
            continue;
        int temp = cost + f(col+1,setbit(mask,row));
        if(temp>ans)
            ans = temp;
    }
    return dp[col][mask] = ans;
}
int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cin>>grid[i][j];
        }
        memset(dp,-1,sizeof dp);
        target = (1<<n) - 1;
        cout<<"Case "<<t<<": "<<f(0,0)<<endl;
    }
}

