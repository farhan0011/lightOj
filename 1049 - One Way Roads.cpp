#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int a,b,c,n,cnl=0,cnr=0;
        cin>>n;
        int left[n],right[n];
        for(int i=0;i<=n;i++)
        {
            left[i]=0;
            right[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            cin>>a>>b>>c;
            if(left[a]==0&&right[b]==0)
            {
                left[a]=1;
                right[b]=1;
                cnl+=c;
            }
            else
            {
                left[b]=1;
                right[a]=1;
                cnr+=c;
            }
        }
        cout<<"Case "<<tc<<": "<<min(cnl,cnr)<<endl;
    }
}
