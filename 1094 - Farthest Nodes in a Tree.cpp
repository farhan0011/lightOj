#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>>G,W;
map<int,int>dis;
void bfs(int s,int n)
{
    queue<int>q;
    q.push(s);
    dis[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            int w=W[u][i];
            //cout<<u<<" to "<<v<<" cost = "<<w<<endl;
            if(dis[v]==-1)
            {
                dis[v]=dis[u]+w;
                q.push(v);
                //cout<<u<<" to "<<v<<" cost = "<<dis[v]<<endl;
                //cout<<v<<" "<<dis[v]<<endl;
            }
        }
    }
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++)
    {
        int n,u,v,w;
        scanf("%d",&n);
        G.clear();
        W.clear();
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back(v);
            G[v].push_back(u);
            W[u].push_back(w);
            W[v].push_back(w);
        }
        for(int i=0;i<n;i++)
            dis[i]=-1;
        bfs(0,n);
        int d=INT_MIN,s;
        for(auto it=dis.begin();it!=dis.end();it++)
        {
            if(d<it->second)
            {
                d=it->second;
                s=it->first;
            }
        }
        for(int i=0;i<n;i++)
            dis[i]=-1;

        //cout<<s<<" "<<d<<endl;
        bfs(s,n);
        d=INT_MIN;
        for(auto it=dis.begin();it!=dis.end();it++)
        {
            //cout<<it->second<<endl;
            if(d<it->second)
            {
                d=it->second;
                //s=it->first;
            }
        }
        dis.clear();
        printf("Case %d: %d\n",t,d);
    }
}
