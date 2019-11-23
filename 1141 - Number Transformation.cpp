#include<bits/stdc++.h>
using namespace std;
#define LIM 1000
#define pb push_back
vector<int>prime;
int isPrime[LIM+100];
void getPrime()
{
    prime.clear();
   memset(isPrime,0,sizeof(isPrime));
   isPrime[0]=isPrime[1]=1;
   for(int i=4;i<=LIM;i+=2)
       isPrime[i]=1;
   int sq=sqrt(LIM);
   prime.pb(2);
   for(int i=3;i<=sq;i+=2)
   {
       if(!isPrime[i])
       {
           for(int j=i+i;j<=LIM;j=j+i)
            isPrime[j]=1;
       }
   }
   for(int i=3;i<=LIM;i+=2)
   {
       if(!isPrime[i])
        prime.pb(i);
   }
}
int main()
{
    getPrime();
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++)
    {
        int s,t;
        cin>>s>>t;
        queue<int>q;
        q.push(s);
        int ans=INT_MAX;
        int vis[2000]={0};
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            if(u==t)
            {
                ans=min(ans,vis[u]);
                break;
            }
            int uu=u;
            for(int i=0;prime[i]<=uu&&prime[i]<u;i++)
            {
                if(uu%prime[i]==0)
                {
                    while(uu%prime[i]==0)
                        uu/=prime[i];

                        int v=u+prime[i];
                        if(!vis[v]&&v<=t)
                       {
                           vis[v]=vis[u]+1;
                          q.push(v);
                       }
                }
            }
        }
        if(ans==INT_MAX)
            cout<<"Case "<<tc<<": -1"<<endl;
        else
            cout<<"Case "<<tc<<": "<<ans<<endl;
    }
}

