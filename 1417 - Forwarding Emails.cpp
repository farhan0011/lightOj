#include<bits/stdc++.h>
using namespace std;
#define LIM 50005
vector<int>G[LIM],R[LIM];
int vis[LIM],vis1[LIM];
int cnt[LIM];
stack<int>st;
int dfs(int s)
{
    vis[s] = 1;
    vis1[s] = 1;
    int ans=1;
    for(int i = 0; i<G[s].size(); i++)
    {
        int v = G[s][i];
        if(vis[v] == -1)
            ans +=dfs(v);
    }
    vis[s] = -1;
    return ans;
}
int main()
{
    int T;
    cin>>T;
    for(int t = 1; t<=T; t++)
    {
        int n,u,v;
        cin>>n;
        for(int i=0;i<=n;i++)
        {
            G[i].clear();
        }
        for(int i = 0; i<n; i++)
        {
            cin>>u>>v;
            G[u].push_back(v);
        }
        for(int i=1; i<=n; i++)
            vis[i] = vis1[i] = -1;
        int a = INT_MIN,ans;
        for(int i=1;i<=n;i++)
        {
            //cout<<cnt[i]<<"-";
            if(vis1[i]==-1)
            {
                int tem = dfs(i);
                if(tem>a)
                {
                    ans = i;
                    a = tem;
                }
            }
        }
        cout<<"Case "<<t<<": "<<ans<<endl;
    }

}
