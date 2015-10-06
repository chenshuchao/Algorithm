#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0) return 0;
        int left = 0;
        int right = size - 1;
        int mid;

        while(left <= right) {
            mid = (left + right) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
            
        return left;
    }
};

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
int main() {
  
    int arr[] = {0, 1, 2, 3, 5};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
    printVector(v);
    
    Solution s;
    printf("%d\n", (s.searchInsert(v, 4)));
    return 0;
}

