/* 
    Time Complexity                              :  O(3^N) - exponential
    Space Complexity                             :  O(N) - to store all the individual characters from the original string
    Did this code successfully run on Leetcode   :  Yes
    Any problem you faced while coding this      :  No
*/

#include <bits/stdc++.h> 
using namespace std;  


class Solution {
vector<string> ans;
public:
    vector<string> expand(string s) {
       
        int n = s.size();
        bool flag = false;
        vector<char> temp;
        vector<vector<char>> inp;
        for(int i=0;i<n;i++) {
            if(s[i] == '{') {
                flag = true;
            }
            
            if(flag and s[i] >= 'a' and s[i] <= 'z') {
                temp.push_back(s[i]);
            }
            
            if(s[i] == '}'){
                flag = false;
                inp.push_back(temp);
                temp.clear();
            }
            
            if(flag == false and s[i] >= 'a' and s[i] <= 'z'){
                inp.push_back(vector<char>{s[i]});
            }
        }
        
        backtracking(0,inp,"");
        // sort(begin(ans),end(ans));
        return ans;
    }
    
    void backtracking(int index, vector<vector<char>>& inp, string s) {
        if(index >= inp.size()) {
            ans.push_back(s);
            return;
        }
        
        vector<char> currChars = inp[index];
        if(currChars.size() > 1)
            sort(begin(currChars),end(currChars));
        for(int i=0;i<currChars.size();i++) {
            string currWord = s + currChars[i];
            backtracking(index + 1, inp, currWord);
            currWord.pop_back();
        }
    }
};