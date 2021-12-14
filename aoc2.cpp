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



int mt[2001][2001];
char str[1001];
int ins=0;
int m,n;
int xy=0, line = 0;

void convert(char ls[])
{
    int len = strlen(ls);
    if(ls[0]=='x')
    xy = 0;
    else xy = 1;
    line = 0;
    for(int i=2;i<len;i++)
    {
        line=line*10 + ls[i]-'0';
    }
}

void fold()
{
    if(xy==1)
    {
        int a, b;
        for(int i=0;i<=m;i++)
        {
            a= i;
            for(int j=line+1;j<=n;j++)
            {
               
                b = line - (j - line); 
                mt[a][b]= max(mt[a][b], mt[i][j]);
                mt[i][j] = 0;
            }
        }
       n = line - 1;
    }
    else
    {
        int a, b;
        for(int i=line+1;i<=m;i++)
        {
            a= line*2 - i;
            for(int j=0;j<=n;j++)
            {
               
                b = j; 

                // cout<<a<<"ab"<<b<<"|"<<i<<"ij"<<j<<";";
                mt[a][b]= max(mt[a][b], mt[i][j]);
                mt[i][j] = 0;
            }
        }
        m = line - 1;
       
    }
}

int check()
{
    int ans = 0;
    for(int i=0; i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(mt[i][j]==1)
            {
                ans++;
                // cout<<'#';
            }
            else
            {
                // cout<<'.';
            }
        }
        // cout<<endl;
    }
    return ans;
}

void print()
{
   
    for(int j=0;j<=n;j++)
    {
        for(int i=0; i<=m;i++)
        {
            if(mt[i][j]==1)
            {
              
                cout<<'#';
            }
            else
            {
                cout<<'.';
            }
        }
        cout<<endl;
    }
}
int main()
{

    freopen("input.txt", "r", stdin );
    freopen("output.txt", "w", stdout);
   memset(mt, 0, sizeof(mt));
   int a,b;
   n = 0, m = 0;
   while(scanf("%d,%d", &a,&b)==2)
   {
    //    cout<<a<<" "<<b<<endl;
    m = max(a, m);
    n = max(b, n);
       mt[a][b]=1;
   }


    cout<<m<<" "<<n<<endl;
    
   while(scanf("%*s %*s %s",str)==1)
   {
    convert(str);
    cout<<xy<<" "<<line<<endl;
    
    fold();
    print();
    cout<<m<<"<mn>"<<n<<endl;
    cout<<check()<<endl;;
    
   }
  
    

    return 0;
}