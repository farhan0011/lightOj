#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        cin.ignore();
        stack<char>stk;
        int c=0,x=0;
        for(int j=0;j<n;j++)
        {
            if(stk.empty()&&s[j]=='.')
            {
                stk.push(s[j]);
                c++;
                x++;
            }
            else if(!stk.empty())
            {
                x++;
                if(x==3)
                    {
                        stk.pop();
                        x=0;
                    }
            }
        }
        cout<<"Case "<<i<<": "<<c<<endl;
    }
}
