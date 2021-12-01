#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int main()
{

    freopen("input.txt", "r", stdin );
    vector<int> v;
    map<char, int> m;
    int start = 0, end=0;
    char dash,c, str[100];
    v.clear();
    m.clear();
    int ans = 0;
    int pre = -1;

    while( cin>>start )
    {
        v.push_back(start);
    }
 
    for(int i=2;i<v.size();i++)
    {
        int value = v[i-2]+v[i-1]+v[i];
        if(pre==-1)
        {
            pre=value;
            continue;
        }
        if(value > pre)
        {
            ans++;
        }
        pre = value;
    }
    cout<<ans<<endl;
    
    


    return 0;
}