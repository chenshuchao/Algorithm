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

// O(n^2)
/*
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) return 0;
    vector<int> dp(size, 1);
    int max_len = 1;
    for (int i = 1; i < size; i ++) {
      for (int j = 0; j < i; j ++) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[j]+1, dp[i]);
          max_len = max(max_len, dp[i]);
        }
      }
    }
    return max_len;
  }
};
*/
// O(nlogn)
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) return 0;
    vector<int> arr;
    arr.push_back(nums[0]);
    for (int i = 1; i < size; i ++) {
      if (nums[i] > arr[arr.size()-1]) {
        arr.push_back(nums[i]);
      } else {
        int pos = binarySearch(arr, nums[i]);
        arr[pos] = nums[i];
      }
    }
    return arr.size();
  }

  // return the index of first element which larger than target.
  int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() -1;
    while(left < right) {
      int mid = (left + right) / 2;
      if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};

int main() {
    //int arr1[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int arr1[] = { 3,5,6,2,5,4,19,5,6,7,12 };
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));
    Solution s;
    cout << s.lengthOfLIS(v1) << endl;
    return 0;
}

