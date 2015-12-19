#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i ++) {
            res ^= nums[i];
        }
        return res;
    }
};

template <typename T>
void printV(const vector<T>& v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

template <typename T>
void printVV(const vector<vector<T> >& vv) {
    for(int i = 0; i < vv.size(); i++) {
        printV(vv[i]);
    }
}


int main() {

    int arr1[] = {2, 3, 4, 4, 2};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));
    Solution s;
    cout << s.singleNumber(v1) << endl;
    
    return 0;
}

