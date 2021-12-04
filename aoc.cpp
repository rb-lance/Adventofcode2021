#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <string>
using namespace std;


int bi2dec(string bi)
{
    cout<<bi<<endl;
    int res = 0;
    for(int i=0; i<bi.size(); i++)
    {
        res=res*2+bi[i]-'0';
        cout<<res<<endl;
    }
    return res;
}
int day3_sol2(int flag, vector< string > candidates, int pos)
{
    int len = candidates.size();
    vector< string > can;
    
    if(candidates.size()==1)
    {
        return bi2dec(candidates[0]);
    }

    int ct = 0;
    for(int i=0;i<candidates.size(); i++)
    {
        if(candidates[i][pos]-'0'==1)
            ct++;
    }
    
    for(int i=0;i<candidates.size(); i++)
    {
        int signal = (ct >= (len+1)/2) ^ (flag ==1);
        // flag = 1, majority =1, signal = 1, 
        // flag = 1, majority =0. signal = 0, 
        // falg = 0, majority =1, signal = 0,
        // flag = 0, majority =0, signal = 1;
        if(candidates[i][pos]-'0' == 1-signal)
            can.push_back(candidates[i]);
    }
    if(can.size()==1)
    {
        return bi2dec(can[0]);
    }
    return day3_sol2(flag, can, pos+1);


}

int main()
{

    freopen("input.txt", "r", stdin );
    freopen("output.txt", "w", stdout);
    vector<int> v;
    map<char, int> m;
    int start = 0, end=0;
    char dash,c, str[100];
    int bit[100], ct[100];
    v.clear();
    m.clear();
    long long ans = 0, num = 0;
    string cm;
    int pre = -1;
    int x=0, y =0, aim = 0;
    int len = 0;
    memset(ct,0,sizeof(ct));
    int tt_num =0;

    vector<string> cand;
    while( scanf("%s", str) ==1)
    {
        len = strlen(str);
        for(int i=0;i<len;i++)
        {
            ct[i]+=str[i]- '0';
        }
        string tmp(str);
        cand.push_back(tmp);
        tt_num++;
    }

    int oxygen = day3_sol2(1, cand, 0);
    int co2 = day3_sol2(0, cand, 0);
    cout<<oxygen<<endl;
    cout<<co2<<endl;
    cout<<oxygen*co2<<endl;
    
    


    return 0;
}