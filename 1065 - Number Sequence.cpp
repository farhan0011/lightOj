#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define  MATROW 17
#define  MATCOL 17
#define ll long long
int matRow = 2;
int matCol = 2;
ll mod;
struct matrix
{
    int mat[2][2];
    matrix (int type)
    {
        memset(mat,0,sizeof mat);
        ///type = 0 is identical matrix
        if(type == 1)
        {
            mat[0][0] = mat[1][1]=1;
        }
        ///type = 1 is fibonacci matrix
        if(type == 2)
        {
           mat[0][0] = mat[0][1] = mat[1][0] = 1;
        }
    }
};
matrix matMul(matrix a,matrix b)
{
    matrix ans = matrix(0);
    for(int i=0; i<matRow; i++)
    {
        for(int j=0; j<matCol; j++)
        {
            for(int k=0; k<matCol; k++)
            {
                ans.mat[i][j] = ( ans.mat[i][j]+ a.mat[i][k] * b.mat[k][j] )%mod;
                //cout<<ans.mat[i][j]<<" ";
            }
            //cout<<endl;
        }
    }
    return ans;
}
matrix matBigMod(matrix n,int r)
{
    if(!r)return matrix(1);
    if(r%2)
    {
        //cout<<"power is odd"<<endl;
        matrix co = matMul(matBigMod(n,r-1),n);
//        for(int i=0;i<2;i++)
//        {
//            for(int j=0;j<2;j++)
//                cout<<co.mat[i][j]<<" ";
//            cout<<endl;
//        }
        return co;

    }
    else
    {
        //cout<<"power is even"<<endl;
        matrix ans = matBigMod(n,r/2);
        matrix co = matMul(ans,ans);
//        for(int i=0;i<2;i++)
//        {
//            for(int j=0;j<2;j++)
//                cout<<co.mat[i][j]<<" ";
//            cout<<endl;
//        }
        return co;
    }
}
int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        int a,b,n,m;
        cin>>a>>b>>n>>m;
        mod = 1;
        while(m--)
            mod*=10;
        matrix co = matrix(0);
        co.mat[0][0] = co.mat[0][1] = co.mat[1][0] = 1;
//        for(int i=0;i<2;i++)
//        {
//            for(int j=0;j<2;j++)
//                cout<<co.mat[i][j]<<" ";
//            cout<<endl;
//        }
        co = matBigMod(co,n-1);
        //cout<<"final"<<endl;
//        for(int i=0;i<2;i++)
//        {
//            for(int j=0;j<2;j++)
//                cout<<co.mat[i][j]<<" ";
//            cout<<endl;
//        }
        ll ans = 0;
        ans = (co.mat[0][0]*b+co.mat[0][1]*a)%mod;
        cout<<"Case "<<t<<": "<<ans<<endl;

    }
}
/**
power is even
power is odd
power is even
power is even
power is odd
1 1
1 0
2 1
1 1
5 3
3 2
8 5
5 3
89 55
55 34
final
89 55
55 34
Case 1: 89
*/

