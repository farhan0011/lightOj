#include<bits/stdc++.h>
using namespace std;
bool flag[102];
vector<int>prime;
void sv()
{
    for(int i=4;i<=100;i+=2)
        flag[i] = true;
    for(int i=3;i<=10;i+=2)
    {
        if(!flag[i])
        {
            for(int j=i*2;j<=100;j+=i)
                flag[j] = true;
        }
    }
    prime.push_back(2);
    for(int i=3;i<=100;i+=2)
    {
        if(!flag[i])
            prime.push_back(i);
    }
}
int main()
{
    sv();
//    for(int i=0;i<prime.size();i++)
//        cout<<prime[i]<<" ";
//    cout<<endl;
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        int n;
        cin>>n;
        map<int,int>mp;
        for(int i=0;i<prime.size();i++)
        {
            int cnt=0;
            int p = prime[i];
            while(n>=p)
            {
                cnt+=n/p;
                p*=prime[i];
            }
            if(cnt>0)
            mp[prime[i]] = cnt;
        }
        cout<<"Case "<<t<<": "<<n<<" = ";
        vector<int>v1,v2;
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            v1.push_back(it->first);
            v2.push_back(it->second);
        }
        for(int i=0;i<v1.size()-1;i++)
            cout<<v1[i]<<" ("<<v2[i]<<") * ";
        cout<<v1[v1.size()-1]<<" ("<<v2[v2.size()-1]<<")"<<endl;

    }
}
