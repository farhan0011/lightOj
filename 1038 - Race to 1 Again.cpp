#include<bits/stdc++.h>
using namespace std;
int cod[100005];
double dp[100005];
int vis[100005];
map<int,vector<int> >mp;
void div()
{
    for(int i=2;i<=100000;i++)
    {
        int p = i;
        int q = 1;
        mp[i].push_back(i);
        for(int j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
                {
                    mp[i].push_back(j);
                    if(j != i/j)
                        mp[i].push_back(i/j);
                }
        }
    }
}
double f(int n)
{
    if(n == 1)
        return 0;
        if(vis[n] == 1)
            return dp[n];
    double ans = 0;
    int sz = mp[n].size();
    //cout<<n<<" size = "<<sz<<endl;
    for(int i=0; i<sz; i++)
    {
        //cout<<n<<" = "<<mp[n][i]<<endl;
        ans+=1.0+f(n/mp[n][i]);
    }
    ans = (ans)/(1.0*(sz));
    vis[n] = 1;
    return dp[n] = ans;
}
int main()
{
    div();
//    for(int i=1;i<=100;i++)
//        cout<<cod[i]<<" ";
//    cout<<endl;
    int T;
    cin>>T;
    memset(vis,-1,sizeof vis);
    for(int t=1; t<=T; t++)
    {
        int n;
        cin>>n;
        if(n == 1)
        cout<<"Case "<<t<<": 0"<<endl;
        else
        cout<<"Case "<<t<<": "<<fixed<<setprecision(6)<<1+f(n)<<endl;
    }
}
