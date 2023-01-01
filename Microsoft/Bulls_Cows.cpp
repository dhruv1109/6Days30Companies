// https://leetcode.com/problems/bulls-and-cows/submissions/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        
        vector<int> S(10, 0);
        vector<int> G(10, 0);

        int bulls=0, cows=0;
        for (int i{0}; i<secret.size(); ++i) 
        {
            if (secret[i]==guess[i]) 
                bulls++;
            else 
            {
                S[secret[i]-'0']++;
                G[guess[i]-'0']++;
            }
        }

        for (int i{0}; i<G.size(); ++i) 
        {
            cows+=min(G[i], S[i]);
        }
        return to_string(bulls)+'A'+to_string(cows)+'B';
    }
};