//https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;
        for(auto& t : tokens) 
        {
            if(t == "+" || t == "-" || t == "*" || t == "/") 
            {
                int op1 = s.top(); s.pop();
                int op2 = s.top(); s.pop();
                if(t == "+") 
                    op1 = op2 + op1;
                if(t == "-") 
                    op1 = op2 - op1;
                if(t == "/") 
                    op1 = op2 / op1;
                if(t == "*") 
                    op1 = op2 * op1;   
                
                s.push(op1);
            }
            else s.push(stoi(t)); 
        }
        return s.top(); 
    }
};