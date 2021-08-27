#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("stv.in");
ofstream g("stv.out");
int f[101],a[101][101];
int minim(int m)
{
    int poz,mini=110;
    for(int i=1;i<=m;i++)
        if(f[i]!=-1 && f[i]<=mini)
        {
            mini=f[i];
            poz=i;
        }
    return poz;
}
int main()
{
    int n,m,i,j,k,p,x,v[101];
    fin>>n;
    fin>>m;
    for(i=1;i<=n;i++)
    {
        fin>>p;
        for(k=1;k<=p;k++)
        {
            fin>>x;
            a[i][k]=x;
        }
        f[a[i][1]]++;
    }
    for(k=1;k<m;k++)
    {
        x=minim(m);
        v[k]=x;
        f[x]=-1;
        for(i=1;i<=n;i++)
            if(a[i][k]==x)
                f[a[i][k+1]]++;
    }
    g<<minim(m)<<" ";
    for(i=m-1;i>=1;i--)
        g<<v[i]<<" ";
    return 0;
}
