#include<bits/stdc++.h>
using namespace std;
int grid[18][18];
int vis[18];
int mask;
int n;
int setbit(int mask,int p)
{
    return mask | (1 << p);
}
int chkbit(int mask,int p)
{
    return mask & (1 << p);
}
int f(int col)
{
    if(col == n)
        return 0;
        int ans = INT_MIN;
    for(int row=0; row<n; row++)
    {
        int cost = grid[row][col];
        if(vis[row])
            continue;
        vis[row] = 1;
        int temp = cost + f(col + 1);
        if(temp>ans)
            ans = temp;
        vis[row] = 0;
    }
    return ans;
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
        cout<<"Case "<<t<<": "<<f(0)<<endl;
    }
}
