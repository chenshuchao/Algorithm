#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<string> temp, res;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i ++) {
            for (int j = i-1; j >= 0; j --) {
                if (dp[j] == 1 && wordDict.find(s.substr(j, i-j)) != wordDict.end()) {
                    dp[i] = 1;
                } 
            }
        }
        if (dp[n] == 0) return res;

        helper(s, wordDict, temp, res, dp, 0);
        return res;
    }
    void helper(string s, unordered_set<string>& wordDict, vector<string>& temp, vector<string>& res, vector<int>& dp, int index) {
        if (index == s.size()) {
            string new_str = "";
            for (int i = 0; i < temp.size(); i ++) {
                if (i != 0) {
                    new_str += " ";
                }
                new_str += temp[i];
            }
            res.push_back(new_str);
            return;
        }
        
        string word = "";
        for (int i = index+1, len_s = s.size(); i <= len_s; i ++) {
            word = s.substr(index, i-index);
            if (dp[i] == 1 && wordDict.find(word) != wordDict.end()) {
                temp.push_back(word);
                helper(s, wordDict, temp, res, dp, i);
                temp.pop_back();
            }
        }
    }
};
template <typename T>
void printV(const vector<T>& v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
    cout << endl;
}
int main() {

    string arr1[] = {"cat", "cats", "and", "sand", "dog"};
    unordered_set<string> set1(arr1, arr1 + 5);

    Solution s;
    printV(s.wordBreak("catsanddog", set1));
    return 0;
}

