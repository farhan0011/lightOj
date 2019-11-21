#include<bits/stdc++.h>
using namespace std;
#define LIM 100005
vector<int>G[LIM];
int vis[LIM];
int c[LIM];
void bfs(int s)
{
    memset(vis,-1,sizeof(vis));
    queue<int>q;
    q.push(s);
    c[s]++;
    vis[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            if(vis[v]==-1)
            {
                q.push(v);
                vis[v]=0;
                c[v]++;
            }
        }
    }
}
int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        int k,n,m;
        cin>>k>>n>>m;
        int people[k];
        for(int i=0;i<k;i++)
            cin>>people[i];
        int u,v;
        for(int i=1;i<=n;i++)
            G[i].clear();
        for(int i=0;i<m;i++)
          {
              cin>>u>>v;
              G[u].push_back(v);
          }
        memset(c,0,sizeof(c));
        for(int i=0;i<k;i++)
        {
            bfs(people[i]);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(c[i]==k)
                ans++;
        }
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
}
