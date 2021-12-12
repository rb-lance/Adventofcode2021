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

map<string, vector<string> > m;

int res = 0;

void dfs(string cur, vector<string> path)
{
    if(cur =="end")
    {
        res++;

        // for(int i=0;i<path.size(); i++)
        // {
        //     cout<<path[i]<<" ";
        // }
        // cout<<endl;
        return;
    }
    path.push_back(cur);

    int flag = 0;
    map<string, int> visit;
    for(int i=0; i<path.size(); i++)
    {
        if(islower(path[i][0]))
        {
            if(visit[path[i]]==1)
                flag = 1;
        }
        visit[path[i]]++;
    }
    for(int i=0; i <m[cur].size(); i++)
    {
        string t = m[cur][i];
        if(t=="start")
            continue;

        if( islower(t[0]) )
        {
            if(flag ==1 && visit[t]<1)
            {
                dfs(t, path);
            }
            else if(flag ==0 && visit[t]<2)
            {
                dfs(t, path);
            }
        }
        else
        {
            dfs(t, path);
        }
    }
    return;
}
int main()
{

    freopen("input.txt", "r", stdin );
    freopen("output.txt", "w", stdout);
   
   char str[11], st[101], ed[101];
   while(scanf("%s",str)==1)
   {

       int flag = 0;
       string a = "", b= "";
       for(int i =0; i< strlen(str); i++)
       {
            if(str[i]!='-'&&flag ==0)
            {
                a+= str[i];     
              
            } 
            else if (str[i]=='-')
            {
                flag = 1;
                continue;
            }
            else
            {
                b+=str[i];
            }

       }

        m[a].push_back(b);
        m[b].push_back(a);

       
       
   }

        vector<string> em;
        dfs("start", em);
        
        cout<<res<<endl;
    
    
    


    return 0;
}