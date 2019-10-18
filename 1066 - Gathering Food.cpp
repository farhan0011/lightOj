#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
map<char,pi>cor;
int dr[]={+1,-1, 0, 0};
int dc[]={ 0, 0,+1,-1};
char g[11][11];
map<pi,int>dis;
void bfs(pi s,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            dis[pi(i,j)]=-1;
    }
    queue<pi>q;
    q.push(s);
    dis[s]=0;
    int sr=s.first,sc=s.second;
    char cmp=g[sr][sc]+1;
    int ans=-1;
    while(!q.empty())
    {
        pi U=q.front();
        q.pop();
        int ur=U.first;
        int uc=U.second;
        for(int i=0;i<4;i++)
        {
            int vr=ur+dr[i];
            int vc=uc+dc[i];
            if(dis[pi(vr,vc)]==-1&&vr>=0&&vr<n&&vc>=0&&vc<n&&g[vr][vc]!='#'&&g[vr][vc]<=cmp)
            {
                //cout<<char(g[sr][sc]+1)<<endl;
                //cout<<ur<<" "<<uc<<" "<<vr<<" "<<vc<<endl;
                dis[pi(vr,vc)]=dis[pi(ur,uc)]+1;
                //cout<<dis[pi(vr,vc)]<<endl;
                q.push(pi(vr,vc));
            }
        }
    }
    /*for(auto it=dis.begin();it!=dis.end();it++)
    {
        pi w=it->first;
        //cout<<w.first<<" "<<w.second<<" "<<it->second<<endl;
    }*/
    //cout<<des.first<<" "<<des.second<<endl;

}
int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int n,nc=0;
        cin>>n;
        char c;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>c;
                g[i][j]=c;
                if(c>='A'&&c<='Z')
                    {
                        nc++;
                        cor[c]=pi(i,j);
                    }
            }
        }
        pi s=pi(cor['A']);
        int cnt=0,x=0;
        //cout<<nc<<endl;
        for(int i=1;i<nc;i++)
        {
            pi des=cor[char('A'+i)];
            //cout<<"des="<<char('A'+i)<<endl;
            //cout<<des.first<<" "<<des.second<<endl;
             bfs(s,n);
             s=des;
             if(dis[des]==-1)
             {
                 x=-1;
                 break;
             }
             else
                x+=dis[des];
        }
        if(x==-1)
            cout<<"Case "<<tc<<": Impossible"<<endl;
        else
            cout<<"Case "<<tc<<": "<<x<<endl;
    }
}
