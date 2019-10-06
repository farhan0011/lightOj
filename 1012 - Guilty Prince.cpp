#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
int dr[]={-1,+1, 0, 0};
int dc[]={ 0, 0,+1,-1};
map<pi,int>dis;
int bfs(pi src,int row,int col,map<pi,char>g)
{
    queue<pi>q;
    q.push(src);
    dis[src]=0;
    int cnt=1;
    while(!q.empty())
    {
        pi u=q.front();
        //cout<<g[u][0]<<endl;
        int ur=u.first;
        int uc=u.second;
        q.pop();
        //cout<<ur<<" "<<uc<<endl;
        for(int i=0;i<4;i++)
        {
            int vr=ur+dr[i];
            int vc=uc+dc[i];
            //cout<<g[pi(vr,vc)][0]<<" "<<dis[pi(vr,vc)]<<" "<<vr<<" "<<vc<<endl;
            if((g[pi(vr,vc)]=='.')&&(dis[pi(vr,vc)]==-1)&&(vr>=1&&vr<=row)&&(vc>=1&&vc<=col))
            {
                cnt++;
                //cout<<cnt<<endl;
                q.push(pi(vr,vc));
                dis[pi(vr,vc)]=0;
            }


        }
    }
    return cnt;
}
int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int col,row;
        cin>>col>>row;
        char c;
        pi src;
        dis.clear();
        map<pi,char>g;
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                cin>>c;
                if(c=='@')
                    src=pi(i,j);
                g[pi(i,j)]=c;
                dis[pi(i,j)]=-1;
            }
        }
        //cout<<src.first<<" "<<src.second<<endl;
        cout<<"Case "<<tc<<": "<<bfs(src,row,col,g)<<endl;

    }
}
