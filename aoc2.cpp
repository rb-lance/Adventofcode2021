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

int m, n;

int matrix[1001][1001];
char line[1001];

int res = 0;

int tx[] = {0,0,1,-1};
int ty[] = {1,-1,0,0};
int flood(int i, int j)
{
    if(matrix[i][j]==9)
    return 0;
    if(i<0||i>=m||j<0||j>=n)
    return 0;
    int ct = 1;
    matrix[i][j] = 9;
    for(int t=0; t<4; t++)
    {
        ct+= flood(i+tx[t], j+ty[t]);
    }
    return ct;
}
int main()
{

    freopen("input.txt", "r", stdin );
    freopen("output.txt", "w", stdout);
   
    while(scanf("%s",line)==1)
    {
        n = strlen(line);
        
        for(int i=0;i<n;i++)
        {
            matrix[m][i]=line[i] - '0';
        }
        m++;
    }
   
   vector<int> res;
   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(matrix[i][j]!=9)
            res.push_back(flood(i,j));
       }
   }

   sort(res.begin(), res.end());
//    for(int i=0;i<res.size();i++)
//    cout<<res[i]<<endl;
    int len = res.size();
   cout<<res[len-1]*res[len-2]*res[len-3]<<endl;

    

    return 0;
}