#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxNum = 1;
        for(int i = 0, len = nums.size(); i < len; i ++) {
            m[nums[i]] = 1;
        }
        for(int i = 0, len = nums.size(); i < len; i ++) {
            int val = nums[i], tempVal = nums[i];
            int tempNum = 0;
            while(m[val]) {
                m[val] = 0;
                val ++;
                tempNum ++;
            }
            while(m[--tempVal]) {
                m[tempVal] = 0;
                tempNum ++;
            }
            maxNum = max(maxNum, tempNum); 
        }
        return maxNum;
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

    int arr1[] = {100, 4, 200, 1, 3, 2};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));

    Solution s;
    cout << s.longestConsecutive(v1) << endl;
    return 0;
}

