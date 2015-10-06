#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> temp;
        helper(s, 0, res, temp);
        return res;
    }
private:
    void helper(string s, int index, vector<string>& res, vector<string>& temp) {
        if(index >= s.size()) return;
        if(temp.size() == 3) {
            string subString = s.substr(index, s.size()-index);
            if(isValidSubString(subString)) {
                temp.push_back(subString);
                res.push_back(join(temp, "."));
                temp.pop_back();
            }
            return;
        }

        for(int i = index; i < s.size(); i ++) {
            string subString = s.substr(index, i-index+1);
            if(!isValidSubString(subString)) break;

            temp.push_back(subString);
            helper(s, i+1, res, temp);
            temp.pop_back();
        }
    }
    string join(vector<string>& v, string sign) {
        if(v.size() == 0) return "";
        string s = v[0];
        for(int i = 1; i < v.size(); i ++) {
            s += sign + v[i];
        }
        return s;
    }
    bool isValidSubString(string s) {
        int n = s.size();
        if(n == 0 || (n > 1 && s[0] == '0')) return false;
       
        int sum = 0;
        for(int i = 0; i < n; i ++) {
            sum = 10*sum + s[i] - '0';
            if(sum >= 256) return false;
        }
        return true;
    }
};

void printVector(vector<string>& v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
int main() {

    Solution s;
    vector<string> res1 = s.restoreIpAddresses("25525511135");
    vector<string> res2 = s.restoreIpAddresses("2345");
    vector<string> res3 = s.restoreIpAddresses("234");
    vector<string> res4 = s.restoreIpAddresses("255255111335");
    vector<string> res5 = s.restoreIpAddresses("25525511105");
    vector<string> res6 = s.restoreIpAddresses("2525511135");
    
    printVector(res1);
    printVector(res2);
    printVector(res3);
    printVector(res4);
    printVector(res5);
    printVector(res6);
 
    return 0;
}

