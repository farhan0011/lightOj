/*#include<bits/stdc++.h>
using namespace std;
#define LIM 100005
int arr[LIM];
int tree[3*LIM];
void seg(int node, int st, int ed)
{
    if(st == ed)
        {
            tree[node] = arr[st];
            return ;
        }
    int mid = (st+ed)/2;
    int left = node*2;
    int right = left+1;
    seg(left, st , mid);
    seg(right, mid +1, ed);
    tree[node] = tree[left] + tree[right];
}
void update(int node,int b,int e,int i,int newvalue)
{
    //cout<<b<<" "<<e<<endl;
    if(i>e || i<b)
        return;
    if(b>=i && e<=i){
        tree[node]=newvalue;
        return;
    }
    int left =node*2;
    int right = node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]= tree[left]+tree[right];
}

int query(int node,int b,int e,int i, int j)
{
    if(b>j || e<i){
        return 0;
    }
    if(b>=i && e<=j){
        return tree[node];
 }
    int left =node*2;
    int right = node*2+1;
    int mid=(b+e)/2;
    int q1=query(left,b,mid,i,j);
    int q2=query(right,mid+1,e,i,j);
     return q1+q2;
}
int main()
{
    int T;
    cin >> T;
    for(int t  =1; t <= T; t++)
    {
         int n,q;
         cin >> n >>q;
         for(int i = 0; i < n; i++)
         {
             cin >> arr[i];
         }
         seg(1,0,n-1);
         //for(int i = 1;i <= 9; i++)
                        //cout<<tree[i]<<" ";
                    //cout<<endl;
         cout<<"Case "<<t<<": "<<endl;
         while(q--)
         {
             int a,b,c;
             cin >> a;
             if(a == 1)
                {
                    cin >>b;
                    cout<<arr[b]<<endl;
                    arr[b]=0;
                    update(1, 0, n-1, b, 0);
                    //for(int i = 1;i <= 9; i++)
                        //cout<<tree[i]<<" ";
                    //cout<<endl;
                }
             else if(a == 2)
             {
                 cin >> b >>c;
                 arr[b] += c;
                 update(1,0,n-1,b,arr[b]);
                 //for(int i=1;i<=9;i++)
                        //cout<<tree[i]<<" ";
                    //cout<<endl;
             }
             else
             {
                 cin >> b >> c;
                 cout<<query(1,0,n-1,b,c)<<endl;
             }
         }
    }
}*/
#include<bits/stdc++.h>
#define mx 100005
using namespace std;
int arr[mx];
int tree[mx*3];
void init(int node,int b,int e)
{
    if(b==e){
        tree[node]=arr[b];
        return;
    }
    int left =node*2;
    int right = node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]= tree[left]+tree[right];
}
int query(int node,int b,int e,int i, int j)
{
    if(b>j || e<i){
        return 0;
    }
    if(b>=i && e<=j){
        return tree[node];
 }
    int left =node*2;
    int right = node*2+1;
    int mid=(b+e)/2;
    int q1=query(left,b,mid,i,j);
    int q2=query(right,mid+1,e,i,j);
     return q1+q2;
}
void update(int node,int b,int e,int i,int newvalue)
{
    if(i>e || i<b)
        return;
    if(b>=i && e<=i){
        tree[node]=newvalue;
        return;
    }
    int left =node*2;
    int right = node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]= tree[left]+tree[right];
}
int main()
{
    int t,n,q,v,x,y,z;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case %d:\n",i);
        scanf("%d %d",&n,&q);
        for(int j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
            init(1,0,n-1);
        for(int k=0;k<q;k++)
        {
            scanf("%d",&x);
            if(x==1)
            {
                scanf("%d",&y);
                printf("%d\n",arr[y]);
                arr[y]=0;
                update(1,0,n-1,y,0);
            }
            else if(x==2)
            {
                scanf("%d %d",&y,&z);
                arr[y]+=z;
                update(1,0,n-1,y,arr[y]);
                //printf("%d\n",ans);
            }
            else
            {
                scanf("%d %d",&y,&z);
                int ans=query(1,0,n-1,y,z);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

