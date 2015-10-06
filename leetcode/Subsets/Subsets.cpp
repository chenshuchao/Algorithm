#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > vv;
        vector<int> v;
        vv.push_back(v);
        int n = nums.size();
        if(n == 0) return vv;
        sort(nums.begin(), nums.end()); 
        helper(nums, vv, v, 0);
        return vv;
    }
    void helper(vector<int>& nums, vector<vector<int> >& vv, vector<int>& v, int index) {
        int n = nums.size();

        for(int i = index; i < n; i++) {
            v.push_back(nums[i]);
            vv.push_back(v);
            helper(nums, vv, v, i+1);
            v.pop_back();
        } 
    }
};

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
void printVV(vector<vector<int> > vv) {
    for(int i = 0; i < vv.size(); i++) {
        for(int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {

    int arr1[] = {4, 1, 0};
    
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));

    Solution s;
    vector<vector<int> > vv = s.subsets(v1);

    printVV(vv);
    
    return 0;
}

