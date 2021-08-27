#include <iostream>

using namespace std;
int main()
{
    int t,i,n,j,v[300001];
    int stg,dr,ok,curent;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        for(j=1;j<=n;j++)
            cin>>v[j];
        ok=0;
        for(j=1;j<=n&&ok==0;j++)
        {
            curent=v[j];
            ok=1;
            stg=j-1;
            dr=j+1;
            while(ok&&(stg>0||dr<n+1))
                if(stg>0&&dr<n+1)
                    if(curent<=v[stg]&&curent<=v[dr])
                        ok=0;
                    else
                    {
                        if(curent>v[stg])
                        { curent++; stg--; }
                        if(curent>v[dr])
                        { curent++; dr++; }
                    }
                else
                {
                    if(stg>0&&dr==n+1)
                       if(curent<=v[stg]) ok=0;
                       else { curent++; stg--;}
                    else
                        if(stg==0&&dr<n+1)
                            if(curent<=v[dr]) ok=0;
                            else { curent++; dr++;}
                }
            if(ok==1)
                j--;
        }
        if(ok==0)
            cout<<-1<<endl;
        else
            cout<<j<<endl;
    }
    return 0;
}
