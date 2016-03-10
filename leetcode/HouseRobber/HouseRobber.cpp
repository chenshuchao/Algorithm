#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if(0 == n) return 0;
    if(1 == n) return nums[0];
    if(2 == n) return nums[1] > nums[0] ? nums[1] : nums[0];

    vector<int> dp(n,0);
    dp[0] = nums[0];
    dp[1] = nums[1] > nums[0] ? nums[1] : nums[0];
    for(int i = 2; i < n; i++) {
      dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
    }   
    return dp[n-1];
  }
};

int main() {

    int arr1[] = {};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));

    Solution s;
    
    return 0;
}

