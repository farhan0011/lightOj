#include<bits/stdc++.h>
using namespace std;
#define LIM 1003
int G[LIM][LIM];
int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        int n;
        cin>>n;
        int m=2*n-1;
        //cout<<m<<endl;
        for(int i=0;i<LIM;i++)
            {
                for(int j=0;j<LIM;j++)
                    G[i][j]=0;
            }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=i; j++)
            {
                cin>>G[i][j];
            }
        }
        int p = n-1;
        for(int i=n+1;i<=m;i++,p--)
        {
            for(int j=1;j<=p;j++)
            {
                cin>>G[i][j];
            }
        }
//        for(int i=0;i<=m;i++)
//        {
//            for(int j=0;j<=i+1;j++)
//                cout<<G[i][j]<<" ";
//            cout<<endl;
//        }
        int ans = 0,temp1=0;;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
                {
                     G[i][j] = max(G[i][j]+G[i-1][j],G[i][j]+G[i-1][j-1]);
                     //cout<<temp<<" ";
                }
                //cout<<endl;
        }
        p=n+1;
        for(int i=n+1;i<=m;i++,p--)
        {
            for(int j=1;j<=p;j++)
                {
                     G[i][j] = max(G[i][j]+G[i-1][j],G[i][j]+G[i-1][j+1]);
                     //cout<<temp<<" ";
                }
                //cout<<endl;
        }
//        for(int i=1;i<=m;i++)
//        {
//            for(int j=1;j<=i+1;j++)
//                {
//                     cout<<G[i][j]<<" ";
//                     //cout<<temp<<" ";
//                }
//                cout<<endl;
//        }
        cout<<"Case "<<t<<": "<<G[m][1]<<endl;

    }
}
