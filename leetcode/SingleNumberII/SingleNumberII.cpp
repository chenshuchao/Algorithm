#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> bit(32, 0);
        int num;
        for (int i = 0; i < n; i ++) {
            num = nums[i];
            for (int j = 31; j >= 0; j --) {
                bit[j] += num & 1;
                num >>= 1;
                if (!num) break;
            }
        }
        int res = 0; 
        for (int i = 31; i >= 0; i --) {
            int temp = bit[i] % 3;
            if (temp) res += 1 << (31-i);
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

    int arr1[] = {3, 3, 3,  4, 5, 5, 5};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));

    Solution s;
    cout << s.singleNumber(v1) << endl;
    return 0;
}

