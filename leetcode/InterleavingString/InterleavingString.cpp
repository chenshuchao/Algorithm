#include <iostream>
#include <vector>
using namespace std;

/*
// Time Limit Exceeded
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        
        if(n1 + n2 != n3) return false;
        
        return helper(s1, 0, s2, 0, s3, 0);
    }
    bool helper(string s1, int p1, string s2, int p2, string s3, int p3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(p3 >= n3) return true;
        cout << s3[p3] << " ";
        if((p1 < n1 && s3[p3] == s1[p1] && helper(s1, p1+1, s2, p2, s3, p3+1)) ||
             (p2 < n2 && s3[p3] == s2[p2] && helper(s1, p1, s2, p2+1, s3, p3+1)) ) {
           
            return true;
        }
        return false;
    }
};
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        
        if(n1 + n2 != n3) return false;
        vector<vector<bool> > vv(n1+1, vector<bool>(n2+1, false));
        vv[0][0] = true;
        for(int i = 1; i <= n2; i ++) {
            vv[0][i] = vv[0][i-1] && (s2[i-1] == s3[i-1]);
        }
        for(int i = 1; i <= n1; i ++) {
            vv[i][0] = vv[i-1][0] && (s1[i-1] == s3[i-1]);
        }

        for(int i = 1; i <= n1; i ++) {
            for(int j = 1; j <= n2; j ++) {
               if((vv[i-1][j] && s1[i-1] == s3[i+j-1]) || (vv[i][j-1] && s2[j-1] == s3[i+j-1]))
                    vv[i][j] = true;
            }
        }
        return vv[n1][n2];
    }
};
int main() {
    Solution s;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    cout << s.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa", "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab", "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab") << endl;
    
    return 0;
}

