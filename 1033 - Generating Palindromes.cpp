#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
string s;
int f(int i,int j)
{
    if(i>=j)
        return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
    int a = 0,b=0,c=0;
    if(s[i] == s[j])
             {
                  return dp[i][j] = f(i+1,j-1);
             }
           else
           {
                a = 1 + f(i+1,j);
                b = 1 + f(i,j-1);
           }
        //cout<<"a = "<<a<<" b = "<<b<<endl;
    return dp[i][j] = min(a,b);
}
int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        memset(dp,-1,sizeof dp);
        cin>>s;
        int n = s.size();
        cout<<"case "<<t<<": "<<f(0,n-1)<<endl;
    }
}
