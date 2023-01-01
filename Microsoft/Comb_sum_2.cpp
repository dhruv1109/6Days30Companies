// https://leetcode.com/problems/combination-sum-iii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int st,int k,int n,vector<int> &out,vector<vector<int>> &ans)
    {
        if(k<=0)
        {
            if(n==0) 
                ans.push_back(out);
            return;
        }
        
        for(int i=st;i<=9;i++)    
        {
            out.push_back(i);
            solve(i+1,k-1,n-i,out,ans);
            out.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> out;
        solve(1,k,n,out,ans);
        return ans;
    }
};