#include <limits.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) return 0;
    int res = nums[0];
    int max_temp = nums[0];
    int min_temp = nums[0];
    
    for (int i = 1; i < size; i ++) {
      if(nums[i] > 0) {
        max_temp = max(max_temp * nums[i], nums[i]);
        min_temp = min(min_temp * nums[i], nums[i]);
      } else {
        int last_max = max_temp;
        max_temp = max(min_temp * nums[i], nums[i]);
        min_temp = min(last_max * nums[i], nums[i]);
      }
      res = max(res, max_temp);
    }
    return res;
  }
};

int main() {
    int arr1[] = {2,3,-2,4};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));
    Solution s;
    cout << s.maxProduct(v1) << endl;
    return 0;
}

