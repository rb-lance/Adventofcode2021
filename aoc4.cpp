#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <cctype>
#include <queue>

using namespace std;

int code[1024];
int m[2001][2001];
int tm[2001][2001];
int lx=1000, ly=1000, hx=1000, hy=1000;

int tx[]={-1,-1,-1,0,0,0,1,1,1};
int ty[]={-1,0,1,-1,0,1,-1,0,1};
void expend(int i, int j)
{
    int ind = 0;
    for(int t=0;t<9;t++)
    {
        int x = tx[t] + i;
        int y = ty[t] + j;
        ind = ind*2 + m[x][y];
    }
    tm[i][j] = code[ind];

}


void step()
{
    for(int i=lx-1;i<=hx+1;i++)
    {
        for(int j=ly-1;j<=hy+1;j++)
        {
             expend(i,j);
        }
         
    }

    for(int i=lx-1;i<=hx+1;i++)
    {
        for(int j=ly-1;j<=hy+1;j++)
        {
             m[i][j] = tm[i][j];
        }
         
    }
    
}
int res=0;
void print()
{
    res = 0;
    lx++;
    hx--;
    ly++;
    hy--;
    for(int i=lx;i<=hx;i++)
    {
        for(int j=ly;j<=hy;j++)
        {
            
            cout<<(m[i][j]==1?'#':'.');
            if(m[i][j]==1)
                res++;
        }
        cout<<endl;
       
    }
     cout<<"Res:"<<res<<endl;
}

int main()
{

    freopen("input.txt", "r", stdin );
    freopen("output.txt", "w", stdout);
    memset(m,0,sizeof(m));

    for(int i=0;i<512; i++)
    { 
        char tmp;
        scanf(" %c",&tmp );
        if(tmp=='#')
            code[i] = 1;
        else 
            code[i]=0;

        // cout<<tmp;
    }

    char tin[2001][2001];
    int cx=1000, cy = 1000;

    int ct = 0;
    while(scanf(" %s", tin[ct])==1)
    {
        int len = strlen(tin[ct]);
        for(int i=0; i<len;i++)
        {
            m[cx+ct][cy+i] = (tin[ct][i]=='#'?1:0);
            if(m[cx+ct][cy+i]==1)
            {
                lx = min(lx, cx+ct);
                hx = max(hx, cx+ct);
                ly = min(ly, cy+i);
                hy = max(hy, cy+i);
            }
        }

        ct++;

    }
        lx-=200;
        ly-=200;
        hx+=200;
        hy+=200;
    for(int s=1;s<=50;s++)
    {
        res = 0;
        cout<<"Step:"<<s<<endl;
        step();
        print();
        // lx-=10;
        // ly-=10;
        // hx+=10;
        // hy+=10;
        
    }

    
    


    return 0;
}