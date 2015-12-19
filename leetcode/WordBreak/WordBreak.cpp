#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
/*
// Time Limit Exceeded
class Solution {
    public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        if (n == 0) return wordDict.find(s) != wordDict.end();
        return helper(s, 0, n, wordDict);
    }
    bool helper(string s, int index, int n, unordered_set<string>& wordDict) {
        if (index >= n) return true;
        for (int i = index+1; i <= n; i ++) {
            string sub = s.substr(index, i-index);
            if (wordDict.find(sub) != wordDict.end() && helper(s, i, n, wordDict)) {
                return true;
            }
        }
        return false;
    }
};
*/

class Solution {
    public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        if (n == 0) return wordDict.find(s) != wordDict.end();
        vector<int> dp(n, 0);
        vector<int> trueIndex;
        trueIndex.push_back(-1);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < trueIndex.size(); j ++) {
                if (wordDict.find(s.substr(trueIndex[j]+1, i-trueIndex[j])) != wordDict.end()) {
                    dp[i] = 1;
                    trueIndex.push_back(i);
                    break;
                }
            }
        }
        return dp[n-1] == 1;
    }
};
int main() {

    string arr1[] = {"let"};
    unordered_set<string> set1(arr1, arr1 + 1);

    Solution s;
    cout << s.wordBreak("let", set1) << endl;
    return 0;
}

