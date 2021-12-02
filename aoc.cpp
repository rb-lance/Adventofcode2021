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
    long long ans = 0, num = 0;
    string cm;
    int pre = -1;
    int x=0, y =0, aim = 0;

    while( cin>>cm>> num )
    {
       if(cm=="forward")
       {
           x+=num;
           y+=aim*num;
       }
       if(cm=="down")
       {
        //    y+=num;
            aim += num;
       }
       if(cm=="up")
       {
           aim -= num;
        //    y-=num;
       }
    }
 
    
    cout<<x*y<<endl;
    
    


    return 0;
}