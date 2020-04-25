#include<bits/stdc++.h>
using namespace std;
#define mod 10007
#define ll long long
int a,b=0,c,d;
struct matrix
{
    ll mat[4][4];
    matrix (int type)
    {
        memset(mat,0,sizeof mat);
        if(type == 1)
        {
            mat[0][0] = mat[1][1] = mat[2][2] = mat[3][3] = 1;
        }
        if(type == 2)
        {
            mat[0][0] = a;
            mat[0][1] = b;
            mat[0][2] = c;
            mat[0][3] = d;
            mat[1][0] = 1;
            mat[2][1] = 1;
            mat[3][3] = 1;
        }
    }
};
matrix mulMat(matrix p,matrix q)
{
    matrix ans = matrix(0);
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            for(int k=0;k<4;k++)
            {
                ans.mat[i][j] = (ans.mat[i][j]+p.mat[i][k]*q.mat[k][j])% mod;
            }
        }
    }
    return ans;
}
matrix matBigMod(matrix x,int y)
{
    if(!y)return matrix(1);
    if(y%2)
        return mulMat(matBigMod(x,y-1),x);
    matrix ans = matBigMod(x,y/2);
    return mulMat(ans,ans);
}
int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        int n;
        cin>>n>>a>>c>>d;
        if(n<=2)
            cout<<"Case "<<t<<": 0"<<endl;
        else{
            matrix temp = matrix(2);
        temp = matBigMod(temp,n-2);
        ll ans = 0;
        ans = temp.mat[0][3];
        cout<<"Case "<<t<<": "<<ans<<endl;
        }
//        for(int i=0;i<4;i++)
//        {
//            for(int j=0;j<4;j++)
//            {
//                cout<<temp.mat[i][j]<<" ";
//            }
//            cout<<endl;
//        }
    }
}
