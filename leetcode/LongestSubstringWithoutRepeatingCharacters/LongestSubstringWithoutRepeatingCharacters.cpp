//https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
// Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

// #include<iostream>
// #include<string>
// using namespace std;
class Solution {

public: 

    int lengthOfLongestSubstring(string s) {
      int s_size = s.size();
      int length = 0;
      string subStr;
      for(auto i = 0; i < s_size; i++) {
        subStr = "";
        int j = i;
        while((j < s_size) && (subStr.find(s[j]) == string::npos)) {
          subStr = s.substr(i,j-i+1); 
          ++j; 
        }
        if(length < subStr.size()) {
          length = subStr.size();
        }
      }
      return length;
    }
/*
    int lengthOfLongestSubstring(string s) {
        vector<int> lastOccur(128,-1);
        int ans = 0, lastLongest = 0;
        for (int i = 0;i < s.size();++i) {
            if (i-lastOccur[s[i]] <= lastLongest)
                lastLongest = i-lastOccur[s[i]];
            else
                ++lastLongest;
            lastOccur[s[i]] = i;
            ans = max(ans,lastLongest);
        }
        return ans;
    }
*/

};

// int main(){
//   Solution s;
//   string str = "b";
//   int length = s.lengthOfLongestSubstring(str);
//   cout << length << endl;
//   return 0;
// }
