#include<bits/stdc++.h>
using namespace std;
int pref[1000006];
string text,pat;
void generatePrefix()
{
    pref[0] = -1;
    pref[1] = 0;
    for(int i=2,j=0;i<pat.size();i++)
    {
        while(j>=0 && pat[j+1]!=pat[i])
            j = pref[j];
        if(pat[j+1]==pat[i])
            {
                pref[i] = j+1;
                j++;
            }
        else
            {
                pref[i] = 0;
                j = 0;
            }
    }
//    for(int i=1;i<pat.size();i++)
//        cout<<pref[i]<<" ";
//    cout<<endl;
}
int patmatch()
{
    //cout<<"YRS"<<endl;
    int cnt = 0;
    for(int i=0,j=0;i<text.size();i++)
    {
        while(j>=0 && text[i] != pat[j+1])
            j = pref[j];
        if(text[i] == pat[j+1])
            j++;
        else
            j=0;
        if(j == pat.size()-1)
            {
                cnt++;
                //cout<<"cnt = "<<cnt<<endl;
            }
    }
    return cnt;
}
int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
     {
         memset(pref,0,sizeof pref);
         cin>>text>>pat;
         pat ="#"+pat;
         generatePrefix();
         cout<<"Case "<<t<<": "<<patmatch()<<endl;
     }
}
