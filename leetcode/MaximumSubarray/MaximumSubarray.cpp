#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); 
        int *sum = new int[n];
        sum[0] = nums[0];
        int m = nums[0];
        for(int i = 1; i < n; i++) {
            sum[i] = max(nums[i], nums[i] + sum[i-1]);
            m = max(m, sum[i]);
        }
        delete[] sum;
        return m;
    }
    private:
    int max(int x, int y) {
        return x > y ? x : y;
    }
};

int main() {

    int arr1[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v(arr1, arr1 + sizeof(arr1)/sizeof(int)); 
    Solution s;
    cout << s.maxSubArray(v) << endl;
    return 0;
}
