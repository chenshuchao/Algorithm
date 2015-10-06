#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string> > vv_str;
        if(n < 2) {
            vv_str.push_back(strs);
            return vv_str;
        }

        map<string, int> m;
        for(int i = 0; i < n; i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            if(m.find(word) != m.end()) {
                vv_str[m[word]].push_back(strs[i]);
            } else {
                vector<string> v_str;
                v_str.push_back(strs[i]);
                vv_str.push_back(v_str);
                m.insert(pair<string, int>(word, vv_str.size()-1));
            }
        }
        for(int i = 0; i < vv_str.size(); i++) {
            sort(vv_str[i].begin(), vv_str[i].end());
        }
        return vv_str;
    }
};

int main() {

    string arr1[] = {"eat", "tea", "tan", "", "ate", "nat", "bat"};
    vector<string> v1(arr1, arr1 + 7);

    Solution s;
    vector<vector<string> > vv = s.groupAnagrams(v1);

    for(int i = 0; i < vv.size(); i++) {
        for(int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << "|";
        }
        cout << endl; 
    }

    return 0;
}
