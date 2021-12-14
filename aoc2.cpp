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

vector<char> l;
char str[1001];
map<pair<char, char>, long long> btw;
map<pair<char, char>, long long> tmp;
void up(char a, char b)
{
    // if(a > b)
    // swap(a,b);
    pair<char, char> p (a,b);
    btw[p]++;
}

void down(char a, char b)
{
    // if(a > b)
    // swap(a,b);
    pair<char, char> p(a,b);
    btw[p]--;
}
map< pair<char, char>, char> insert;


void move()
{
    tmp.clear();
    for (auto num: btw) {
        pair<char, char> t = num.first;
        
        if( insert.find(t) == insert.end() )
            continue;
        char ins = insert[t];
        pair<char, char>p1 (num.first.first, ins), p2(ins, num.first.second);

        tmp[p1]+= btw[t];
        tmp[p2]+= btw[t];

        // cout<<num.first.first<<","<<num.first.second;
        // cout<<"insert"<<ins<<endl;
        
    }
    btw = tmp;
}
    char be ;
    char ed ;
long long ans;
void print()
{

    map<char, long long> ct;
    ct[be] = 1;
    ct[ed] = 1;
    for(auto num: btw)
    {
        char a = num.first.first;
        char b = num.first.second;
        long long c = num.second;
        // cout<<num.first.first<<","<<num.first.second<<":"<<num.second<<endl;
        ct[a] += c;
        ct[b] += c;
    }

    long long mx=0, mn=10000000000000;
    for(auto v: ct)
    {
        cout<<v.first<<":"<<v.second<<endl;
        mx = max(mx, v.second);
        mn = min(mn, v.second);
    }
    ans = (mx- mn)/2;
}
int main()
{

    freopen("input.txt", "r", stdin );
    freopen("output.txt", "w", stdout);
    
    
    scanf("%s", str);
    be = str[0];
     ed = str[strlen(str)-1];
    cout<<be<<" "<<ed<<endl;
    for(int i=0;i<strlen(str)-1; i++)
    {
        up(str[i], str[i+1]);
    }

    char ss[111];
    while(scanf("%s %*s %s",str,ss)==2)
    {
        // cout<<str<<" "<<ss<<endl;
        pair<char, char> p(str[0], str[1]);
        insert[p] = ss[0];
    }
  
    for(int step =1 ; step<=40;step++)
    {
        cout<<"Step:"<<step<<endl;
        move();
        print();
    }
    cout<<ans<<endl;

    return 0;
}