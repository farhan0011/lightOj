#include<bits/stdc++.h>
using namespace std;
int dp[25][4];
int A[25][4];
int n;
int f(int in,int last)
{
    if(in == n)
        return 0;
    if(dp[in][last]!=-1) return dp[in][last];
    int a=0,b=0;
    if(last == 0)
     {
         a = A[in][1]+f(in + 1,1);
         b = A[in][2]+f(in + 1,2);
     }
     else if(last == 1)
     {
         a = A[in][0]+f(in + 1,0);
         b = A[in][2]+f(in + 1,2);
     }
     else if(last == 2)
     {
         a = A[in][1]+f(in + 1,1);
         b = A[in][0]+f(in + 1,0);
     }

    dp[in][last] = min(a,b);
}
int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            for(int j=0;j<3;j++)
                cin>>A[i][j];
        }
        int last,v ;
        cout<<"Case "<<t<<": ";
        memset(dp,-1,sizeof dp);
        int a = A[0][0] + f(1,0);
        memset(dp,-1,sizeof dp);
        int b = A[0][1] + f(1,1);
        memset(dp,-1,sizeof dp);
        int c = A[0][2] + f(1,2);
        cout<<min(a,min(b,c))<<endl;
    }
}
