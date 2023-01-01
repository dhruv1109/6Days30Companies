//https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include<bits/stdc++.h>
using namespace std;

// Method 1
// T->O(N)    S->O(N)

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


// Method 2
// T->O(N)    S->O(1)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        int top = 0;
        for(auto& t : tokens) 
        {
            if(t == "+" || t == "-" || t == "*" || t == "/") 
            {
                int op1 = stoi(tokens[--top]); 
                int op2 = stoi(tokens[--top]); 
                if(t == "+") 
                    op1 = op2 + op1;
                if(t == "-") 
                    op1 = op2 - op1;
                if(t == "/") 
                    op1 = op2 / op1;
                if(t == "*") 
                    op1 = op2 * op1;   
                tokens[top++] = to_string(op1);
            }
            else tokens[top++] = t;
        }
        return stoi(tokens[0]);
    }
};
