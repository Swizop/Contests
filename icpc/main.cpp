/*#include <iostream>

using namespace std;

int n,K,a[604][604];
int dx[5]={0,0,1,0,-1};
int dy[5]={0,1,0,-1,0};

int main()
{
    int i,j,nr,k;
    char lit;
    cin>>K;
    for(int iK=1;iK<=K;iK++)
    {
        cin>>n;
        nr=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                cin>>lit;
                if(lit=='#')
                    a[i][j]=1;
                else
                    a[i][j]=0;
            }
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(a[i][j]==1)
                   for(k=1;k<=4;k++)
                        if(a[i+dx[k]][j+dy[k]]==1)
                        {
                            nr++;
                            a[i][j]=a[i+dx[k]][j+dy[k]]=0;
                            k=5;
                        }
        cout<<"Case "<<iK<<": "<<nr<<endl;
    }
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
int v[51];
int maxim(int n)
{
    int maxi=v[1];
    for(int i=2;i<=n;i++)
        if(v[i]>maxi)
            maxi=v[i];
    return maxi;
}
int minim(int n)
{
    int mini=v[1];
    for(int i=2;i<=n;i++)
    {
        if(v[i]<mini)
            mini=v[i];
    }
    return mini;
}
int diferenta(int n)
{
    int maxi=0;
    for(int i=2;i<=n;i++)
        if(v[i]-v[i-1]>maxi)
            maxi=v[i]-v[i-1];
    return maxi;
}
int main()
{
    int K,n,i,j;
    cin>>K;
    for(i=1;i<=K;i++)
    {
        cin>>n;
        for(j=1;j<=n;j++)
            cin>>v[j];
        cout<<"Class "<<i<<endl;
        sort(v+1,v+n+1);
        for(j=1;j<=n;j++)
            cout<<v[j]<<" ";
        cout<<"Max "<<maxim(n)<<", Min "<<minim(n)<<", Largest gap "<<diferenta(n)<<endl;
    }
    return 0;
}
///5 68 100 32 41 12
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

///functie pentru aceiasi zi -> x e dat inainte, z dupa si y e corect
int aceeasizi(int xh, int xm, int yh,int ym, int zh, int zm)
{
    int sumax,sumaz;
    sumax=sumaz=0;
    if(xh==yh)
        sumax=ym-xm;
    else
    {
        if(xm!=0)
        {
            sumax= 60 - xm;
            xh++;
        }
        sumax += (yh - xh) * 60;
        sumax += ym;
    }
    if(yh==zh)
        sumaz=zm-ym;
    else
    {
        sumaz = zm;
        sumaz += (zh - (yh+1))*60;
        sumaz += 60 - ym;
    }

    if(sumaz == sumax)
        return 1;
    else
        return 0;
}

///functie in care x e inainte de 12, y e dupa
int varianta2(int xh, int xm, int yh,int ym, int zh, int zm)
{
    int sumax,sumaz;
    sumax=sumaz=0;

    sumax = (12-xh)*60;
    sumax += 60 - xm;   /// e ora 1 de aici
    sumax += yh - 1;
    sumax += ym;

    if(yh==zh)
        sumaz=zm-ym;
    else
    {
        sumaz = zm;
        sumaz += (zh - (yh+1))*60;
        sumaz += 60 - ym;
    }

    if(sumaz == sumax)
        return 1;
    else
        return 0;
}

/// functie pt cand x e in aceeasi zi, z e dupa 1
int varianta3(int xh, int xm, int yh,int ym, int zh, int zm)
{
    int sumax,sumaz;
    sumax=sumaz=0;
    if(xh==yh)
        sumax=ym-xm;
    else
    {
        if(xm!=0)
        {
            sumax= 60 - xm;
            xh++;
        }
        sumax += (yh - xh) * 60;
        sumax += ym;
    }

    sumaz = zm;
    sumaz += zh-1;
    sumaz += 60 - ym;
    sumaz += 12 - yh;

    if(sumaz == sumax)
        return 1;
    else
        return 0;
}

int main()
{
    int T,i,k,j,cont,solh,solm;
    int ore[4],minute[4];
    char s[40],x[7];
    cin>>T;
    cin.getline(s,40);
    for(i=1;i<=T;i++)
    {
        cin.getline(s,40);
        j=0;
        cont=1;
        while(cont<=3)
        {
            k=0;
            while(s[j]!=':')
            {
                x[k]=s[j];
                k++;
                j++;
            }
            x[k]='\0';
            ore[cont]=atoi(x);
            j++;
            x[0]=s[j];
            j++;
            x[1]=s[j];
            j+=2;
            x[2]='\0';
            minute[cont]=atoi(x);
            cont++;
        }
        ///cout<<ore[1]<<':'<<minute[1]<<" ";
        ///cout<<ore[2]<<':'<<minute[2]<<" "<<ore[3]<<':'<<minute[3]<<endl;
        ok=0;
        if (aceeasizi(ore[1],minute[1],ore[2],minute[2],ore[3],minute[3]))
        {
            ok+=1;
            solh=ore[2];
            solm=minute[2];
        }
        if (aceeasizi(ore[3],minute[3],ore[2],minute[2],ore[1],minute[1]))
        {
            ok+=1;
            solh=ore[2];
            solm=minute[2];
        }
        if (aceeasizi(ore[2],minute[2],ore[1],minute[1],ore[3],minute[3]))
        {
            ok+=1;
            solh=ore[1];
            solm=minute[1];
        }
        if (aceeasizi(ore[3],minute[3],ore[1],minute[1],ore[2],minute[2]))
        {
            ok+=1;
            solh=ore[1];
            solm=minute[1];
        }
        if (aceeasizi(ore[1],minute[1],ore[2],minute[2],ore[3],minute[3]))
        {
            ok+=1;
            solh=ore[2];
            solm=minute[2];
        }
        if (aceeasizi(ore[3],minute[3],ore[2],minute[2],ore[1],minute[1]))
        {
            ok+=1;
            solh=ore[2];
            solm=minute[2];
        }
    }
    return 0;
}
