#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
using namespace std;

stack<char> o;


char m[12][12];

/*

0
5483143223
2745854711
5264556173
6141336146
6357385478
4167524645
2176841721
6882881134
4846848554
5283751526

10
0481112976
0031112009
0041112504
0081111406
0099111306
0093511233
0442361130
5532252350
0532250600
0032240000

*/
int bx[8] = {0,1,-1, 0, 1, -1, 1, -1};
int by[8] = {1,0,0 ,-1, 1, -1, -1, 1}; 
int count_light()
{
    int ans = 0;
    for(int i=0;i<10;i++)
    {
        for(int j=0; j<10; j++)
        {
            if(m[i][j]=='0')
                ans++;
        }
    }
    return ans;
}
void light(int i, int j)
{
    if(i<0 || i >=10 ||j <0 || j >=10)
        return;
    if(m[i][j]=='9')
    {
        m[i][j] ='0';
        for(int it = 0; it<8;it++)
        {
            light(i+bx[it], j+by[it]);
        }
    }
    else if(m[i][j] =='0')
    {
        return;
    }
    else
    {
        m[i][j] +=1;
        return;
    }

}

void step1()
{
    queue< pair<int,int> > lt;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(m[i][j]=='9')
            {
                pair<int, int> p;
                p.first = i;
                p.second = j;
                lt.push(p);
            }
            else
            {
                m[i][j]+=1;
            }
            
        }
    }

    while(!lt.empty())
    {
        pair<int,int> t = lt.front();
        lt.pop();
        light(t.first, t.second);
    }
}

void print()
{
    cout<<"new step"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<m[i]<<endl;
    }
    return;
}
int main()
{

    freopen("input.txt", "r", stdin );
    freopen("output.txt", "w", stdout);
   
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            scanf(" %c", &(m[i][j]));
        }
    }

    int res =0 ;
     for(int step =1; step <=1000; step++)
     {
        step1();
        int dd = count_light();
        if(dd==100)
        {
            cout<<step<<endl;
            break;
        }
        // print();
     }

     cout<<res<<endl;

    
    
    


    return 0;
}