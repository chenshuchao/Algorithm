#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector <int> > vv;
        vector<int> path;
        unordered_map<int, int> m;
        int len = nums.size();
        if(len > 0) {
            for(int i = 0; i < len; i++) {
                ++m[nums[i]];
            }
            dfsHelper(vv, path, m, len);
        }
        return vv;
    }
private:
    void dfsHelper(vector<vector<int> >& vv, vector<int>& path, unordered_map<int, int>& m, int len) {
        if(path.size() == len) {
            vv.push_back(path);
            return;
        }
        for(auto it = m.begin(); it != m.end(); it++) {
            if(it->second) {
                path.push_back(it->first);
                --it->second;
                dfsHelper(vv, path, m, len);
                path.pop_back();
                ++it->second;
            }
        }
    }
};

int main() {

    int arr1[] = {3,3,0,0,2,3,2};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));

    Solution s;
    vector<vector<int> > vv = s.permuteUnique(v1);

    for(int i = 0; i < vv.size(); i++) {
        for(int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl; 
    }

    return 0;
}

