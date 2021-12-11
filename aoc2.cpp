#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

stack<char> o;


int cal( char t)
{
    int tt_score = 0;
    if(t == ')')
    {
        tt_score=3;
    }
    else if(t == ']')
    {
        tt_score= 57;
    }
    else if(t == '}')
    {
        tt_score = 1197;
    }
    else if(t == '>')
    {
        tt_score = 25137;
    }
    return tt_score;
}



int main()
{

    freopen("input.txt", "r", stdin );
    freopen("output.txt", "w", stdout);
   
    long long  tt_score = 0;
    char str[10001];
    char lst;
    vector<long long> scores;
    string tt = "";
    while(scanf("%s", str)==1)
    {
        cout<<strlen(str)<<endl;
        
        for(int i=0;i<strlen(str); i++)
        {
            
            char tmp = str[i];
            if(tmp=='(' || tmp =='[' || tmp =='{' || tmp =='<')
            {
                o.push(str[i]);
            }
            else
            {
                if( (tmp==')' &&o.top()=='(') || (tmp=='}' &&o.top()=='{') || (tmp==']' &&o.top()=='[') || (tmp=='>' &&o.top()=='<')  )
                {
                    // cout<<i<<" "<<tmp<<""<<o.top()<<"  ";
                    o.pop();
                    
                    // cout<<o.size()<<endl;
                }
                else 
                {
                    // cout<<"Error!"<<tmp<<""<<o.top()<<" "<<endl;
                    // tt_score += cal(tmp);
                    while(! o.empty())
                    {
                        // lst = o.top();
                        o.pop();
                    }
                    break;
                
                }
                
                
            }
        }
        

        tt_score = 0;
        tt= "";
        while(! o.empty())
        {
            tt += o.top();
            o.pop();
        }
        
        cout<<tt;
        if(tt=="")
            continue;
        // reverse(tt.begin(), tt.end());

                  
        for(int i=0; i<tt.size();i++)
        {
            lst = tt[i];
            tt_score *= 5;

            if(lst == '(')
                tt_score += 1;
            if(lst == '[')
                tt_score += 2;
            if(lst == '{')
                tt_score += 3;
            if(lst == '<')
                tt_score += 4;

                cout<<tt_score<<" ";
        }
        cout<<tt_score<<endl;
        
        scores.push_back(tt_score);
        
    }

    int len = scores.size();
    sort(scores.begin(), scores.end());

    cout<<"size:"<<len<<endl;
    cout<<scores[(len-1)/2]<<endl;
    

    
    
    


    return 0;
}