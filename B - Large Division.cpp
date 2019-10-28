#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        string a;
        ll b;
        cin>>a;
        cin>>b;
        if(b<0)
            b=b*(-1);
        vector<int>dig;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]>='0'&&a[i]<='9')
            dig.push_back(a[i]-'0');
        }
        //reverse(dig.begin(),dig.end());
        ll num=0;
        for(int i=0;i<dig.size();i++)
        {
            num=num*10+dig[i];
            //cout<<num<<endl;
            if(num>=b)
                num=num%b;
        }
        if(num==0)
            cout<<"Case "<<t<<": divisible"<<endl;
        else
           cout<<"Case "<<t<<": not divisible"<<endl;

    }
}
