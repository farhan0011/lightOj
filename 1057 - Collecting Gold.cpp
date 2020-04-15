#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define MAX 10000007
int G[50][50];
int xr,xc,gold,target;
int dis[50][50];
int dr[]={-1,+1,0,0,+1,+1,-1,-1};
int dc[]={0,0,-1,+1,+1,-1,+1,-1};
int dp[18][(1<<18)+100];
int setbit(int mask,int p)
{
    return mask | (1 << p);
}
int checkbit(int mask,int p)
{
    return mask & (1<<p);
}
void bfs(int n,int m)
{
    dis[1][1] = 0;
    queue<pi>q;
    q.push(pi(1,1));
    while(!q.empty())
    {
        //cout<<"BFS"<<endl;
        pi u=q.front();
        int ur=u.first;
        int uc=u.second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            int vr=ur+dr[i];
            int vc=uc+dc[i];
            if(dis[vr][vc]==-1&&vr>=1&&vr<=n&&vc>=1&&vc<=m)
            {
                dis[vr][vc]=dis[ur][uc]+1;
                q.push(pi(vr,vc));
            }
        }
    }
}

int f(int u,int mask)
{
    if(mask == target)
        return G[u][0];
        if(dp[u][mask] != -1)
            return dp[u][mask];
    int ans = MAX;
    for(int i=1; i<=gold; i++)
    {
        //cout<<"f"<<endl;
        int cost = G[u][i];
        if(checkbit(mask,i))
            continue;
        int temp = cost + f(i,setbit(mask,i));
        if(temp<ans)
            ans = temp;
    }
    return dp[u][mask] = ans;
}
int main()
{
   int T;
   cin>>T;
   for(int t=1; t<=T; t++)
   {
       memset(G,0,sizeof G);
       gold = 0 ;
       int m,n;
       cin>>m>>n;
       int gr[20];
       int gc[20];
       int r = 0,c=0;
       char ch;
       char grid[m][n];
       for(int i=0; i<m; i++)
       {
           for(int j=0; j<n; j++)
           {
               cin>>grid[i][j];
               if(grid[i][j] == 'x')
               {
                   gr[r] = i;
                   gc[c] = j;
                   //cout<<i<<" "<<j<<endl;
                   //cout<<grid[i][j]<<" "<<gr[r]<<" "<<gc[c]<<endl;
                   r++,c++;
                   gold++;
               }
           }
       }
       for(int i=0; i<m; i++)
       {
           for(int j=0; j<n; j++)
           {

               if(grid[i][j] == 'g')
               {
                   gr[r] = i;
                   gc[c] = j;
                   r++,c++;
                   gold++;
               }

           }
       }
       for(int i=0;i<gold;i++)
       {
           //cout<<"YES"<<endl;
           for(int j=i+1; j<gold; j++)
           {
               memset(dis,-1,sizeof dis);
               //cout<<gr[i]+1<<" "<<gc[i]+1<<" to "<<gr[j]<<" "<<gc[j]<<endl;
               int st = abs(gr[i]-gr[j])+1,ed = abs(gc[i]-gc[j])+1;
               bfs(st,ed);
               //cout<<"dis = "<<dis[gr[j]+1][gc[j]+1]<<endl;;
               G[i][j] = dis[st][ed];
               G[j][i] = dis[st][ed];
               //cout<<gr[i]+1<<" "<<gc[i]+1<<" to "<<gr[j]+1<<" "<<gc[j]+1<<" cost = "<<dis[st][ed]<<endl;
           }
       }
//       for(int i=1;i<=gold;i++)
//       {
//           for(int j=1;j<=gold;j++)
//            cout<<G[i][j]<<" ";
//           cout<<endl;
//       }
       //memset(vis,0,sizeof vis);
       //vis[1]=1;
       target = (1<<gold)-1;
       memset(dp,-1,sizeof dp);
       cout<<"Case "<<t<<": "<<f(0,1)<<endl;

   }
}
