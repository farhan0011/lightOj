#include<bits/stdc++.h>
using namespace std;
#define MX 100005
#define ll long long int
ll tree[4*MX+100];
ll A[MX];
#define mod 1000000007
int n;
void update(int node,int st,int ed,int ind,int v)
{
    //cout<<"IN U"<<endl;
    if(st>ind || ed<ind)
        return ;
    if(st == ind && ed == ind)
    {
        tree[node] = (tree[node]   + v)%mod;
        return;
    }
    int lf = 2 * node;
    int rg = 1 + lf;
    int md = (st + ed)/2;
    update(lf,st,md,ind,v);
    update(rg,md+1,ed,ind,v);
    tree[node] = (tree[lf]  +tree[rg] ) % mod;
    return ;
}
ll query(int node,int st,int ed,int i,int j)
{
    //cout<<"IN Q"<<endl;
    if(st>j ||ed<i)
        return 0;
    if(st>=i && ed<=j)
        return tree[node] % mod;
    int md = (st+ed)/2;
    ll lf = 2 * node;
    ll rg = 1 + lf;
    ll a = query(lf,st,md,i,j) ;
    ll b = query(rg,md+1,ed,i,j) ;
    return tree[node] = (a+b) % mod;
}
ll f()
{
    //cout<<"IN_F"<<endl;
    int ans = 1;
    for(int in = 0; in<n; in++)
    {
        int mx = 1 + query(1,0,MX,0,A[in] - 1) ;
        //cout<<"A[in] = "<<A[in]<<" mx = "<<mx<<endl;
        update(1,0,MX,A[in],mx);
    }
    return tree[1];
}

int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        cin>>n;
        ll arr[n],arr1[n];
        memset(A,0,sizeof A);
        memset(tree,0,sizeof tree);
        map<ll,ll>mp;
        for(int i=0; i<n; i++)
            {
                cin>>arr[i];
                arr1[i] = arr[i];
            }
            sort(arr,arr+n);
            for(int i=0; i<n; i++)
            {
                if(mp[arr[i]]==0)
                    mp[arr[i]] = i+1;
            }
            int ind = 0;
            for(int i=0;i<n;i++)
                A[i] = mp[arr1[i]];
//            for(int i=0;i<n;i++)
//                cout<<A[i]<<" ";
//                cout<<endl;
        cout<<"Case "<<t<<": "<<f()<<endl;
    }
}
