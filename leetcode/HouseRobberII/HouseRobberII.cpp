#include <iostream>
#include <vector>

using namespace std;

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

class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    vector<int> v1(nums.begin(), nums.end()-1);
    vector<int> v2(nums.begin()+1, nums.end());
    return max(robOriginal(v1), robOriginal(v2));
  }
  int robOriginal(vector<int>& nums) {
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

