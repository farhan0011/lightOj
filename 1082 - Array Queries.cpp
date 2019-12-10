#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define pb push_back
#define LIM 100005
int arr[LIM];
int tree[LIM*3];
void seg(int node,int st,int en)
{
    if(st==en)
    {
        tree[node] = arr[st];
        return;
    }
    int mid=(st+en)/2;
    int left=node*2;
    int right=node*2+1;
    seg(left,st,mid);
    seg(right,mid+1,en);
    tree[node]=min(tree[left], tree[right]);

}
int query(int node,int i,int j,int st,int en)
{
    if(i > en || j < st)
        return INT_MAX;
    if(st ==  en )
         return tree[node];
    int left = node*2;
    int right = node*2+1;
    int mid = (st+en)/2;
    int x = query(left,i,j,st,mid);
    int y = query(right,i,j,mid+1,en);
    //cout<<"x = "<<x<<" y = "<<y<<endl;
    return min(x,y);

}
int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n,q,a;
        scanf("%d %d",&n,&q);
        for(int i = 1; i<=n; i++)
        {
            scanf("%d",&a);
            arr[i]=a;
        }

        //for(auto it=v.begin();it!=v.end();it++)
            //cout<<it->first<<" "<<it->second<<endl;
        seg(1,1,n);
        cout<<"Case "<<t<<":"<<endl;
        while(q--)
        {
            int i,j;
            scanf("%d %d",&i,&j);
            printf("%d\n",query(1,i,j,1,n));
        }

    }
}
