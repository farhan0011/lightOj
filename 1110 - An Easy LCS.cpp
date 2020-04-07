#include<bits/stdc++.h>
using namespace std;
string dp[105][105];
int dr[105][105];
string A,B;
string f(int i,int j)
{
    if(i == A.size() || j == B.size())
        return "";
    if(dr[i][j]!= -1)
    {
        return dp[i][j];

    }
    string a ="",b="",c="";
    if(A[i] == B[j])
        {
            dr[i][j] = 1;
            a = A[i] + f(i+1,j+1);
            return dp[i][j] = a;
        }
    b = f(i+1,j);
    c = f(i,j+1);
    dr[i][j] = 1;
    if(b.size()>c.size())
     return dp[i][j] = b;
    else if(b.size()<c.size())
        return dp[i][j] = c;
    else
    {
        return dp[i][j] = min(b,c);
    }
}
int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        memset(dr,-1,sizeof dr);
        for(int i=0;i<105;i++)
        {
            for(int j=0;j<105;j++)
                dp[i][j] = "";
        }
        cin>>A>>B;
        string s = f(0,0);
        if(s.size()==0)
            cout<<"Case "<<t<<": :("<<endl;
        else
            cout<<"Case "<<t<<": "<<s<<endl;

    }
}
