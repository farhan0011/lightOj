#include<bits/stdc++.h>
using namespace std;
double pre[1000002];
int main()
{
    for(int i=1;i<1000002;i++)
    {
       pre[i] = pre[i-1]+log(i);
    }
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        int n,b;
        cin>>n>>b;
        if(n==0 || n==1)
        {
            cout<<"Case "<<t<<": "<<1<<endl;
            continue;
        }
        double ans = pre[n]/log(b);
        cout<<"Case "<<t<<": "<<(int)ceil(ans)<<endl;
    }
}
