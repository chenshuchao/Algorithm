#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > vv;
        vector<int> v;
        vv.push_back(v);
        sort(nums.begin(), nums.end());
        helper(nums, vv, v, 0);
        return vv;
    }
private:
    void helper(vector<int>&nums, vector<vector<int> >& vv, vector<int>& v, int index) {
        if(index >= nums.size()) return;
        for(int i = index; i < nums.size(); i ++) {
            if(i == index || nums[i] != nums[i-1]) {
                v.push_back(nums[i]);
                vv.push_back(v);
                helper(nums, vv, v, i+1);
                v.pop_back();
            }
        }
    }
};
void printVV(vector<vector<int> > vv) {
    for(int i = 0; i < vv.size(); i++) {
        for(int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {

    int arr1[] = {1, 3, 2};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));

    Solution s;
    vector<vector<int> > vv = s.subsetsWithDup(v1);
    
    printVV(vv);
    
    return 0;
}

