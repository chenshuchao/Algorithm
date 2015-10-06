#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;

        int left = 0;
        int right = nums.size() - 1; 
        int mid;
        
        while(left <= right) {
            mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            if((nums[mid] >= nums[left] && (target < nums[left] || target > nums[mid])) ||
                 (nums[mid] < nums[left] && target > nums[mid] && target <= nums[right])) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
  
    int arr[] = {1};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
    
    Solution s;
    printf("%d\n", s.search(v, 3));
    return 0;
}

