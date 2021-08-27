#include <iostream>
#include <algorithm>
using namespace std;

int n,m,xf,yf;           ///n sof dungeon, m nr de teleportere
int dx[5]={0,-1,0,1,0};
int dy[5]={0,0,1,0,-1};
struct
{
    int nr,teleporter;
}a[1001][1001];
int minlinie(int x)
{
    int mini=-1;
    for(int j=1;j<=n;j++)
        if(a[x][j].nr>0)
            if(mini==-1)
                mini=a[x][j].nr;
            else
                if(a[x][j].nr<mini)
                    mini=a[x][j].nr;
    if (mini == -1)
        return 1000000001;
    else
        return mini;
}
int mincoloana(int x)
{
int     mini=-1;
    for(int j=1;j<=n;j++)
        if(a[j][x].nr>0)
            if(mini==-1)
                mini=a[j][x].nr;
            else
                if(a[j][x].nr<mini)
                    mini=a[j][x].nr;
    if (mini == -1)
        return 1000000001;
    else
        return mini;
}
void lee(int x,int y)
{
    if(a[x][y].teleporter==1)
        a[x][y].nr=min(a[x][y].nr,min(mincoloana(y),minlinie(x)));
    for(int i=1;i<=4;i++)
    {
        if(x+dx[i]>=0&&x+dx[i]<=n&&y+dy[i]>=0&&y+dy[i]<=n&&a[x+dx[i]][y+dy[i]].nr==0)
        {
        a[x+dx[i]][y+dy[i]].nr=a[x][y].nr+1;
        lee(x+dx[i],y+dy[i]); }
    }
}
int main()
{
    cin>>n>>m;
    int q,b;
    cin>>q>>b;
    cin>>xf>>yf;
    int r1,r2;
    for(int i=1;i<=m;i++)
    {
        cin>>r1>>r2;
        a[r1][r2].teleporter=1;
    }
    a[q][b].nr=1;
    lee(q,b);
    cout<<a[xf][yf].nr-1;
    return 0;
}
