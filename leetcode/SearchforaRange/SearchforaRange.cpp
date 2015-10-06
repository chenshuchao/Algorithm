#include <iostream>
#include <vector>

using namespace std;
    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int size = nums.size();
            vector<int> res;
            if(size == 0) {
                res.push_back(-1);
                res.push_back(-1);
                return res;
            }
    
            int left = 0;
            int right = size - 1;
            int mid;
            while(left <= right) {
                mid = (left + right) / 2;
                if(nums[mid] == target) break;
                if(target < nums[mid]) right = mid -1;
                if(target > nums[mid]) left = mid + 1;
            }
            if(left <= right) {
                int i = mid, j = mid;
                while(nums[i] == target) i--;
                res.push_back(++i);
                while(nums[j] == target) j++;
                res.push_back(--j); 
            } else {
                res.push_back(-1);
                res.push_back(-1);
            }
    
            return res;
        }
    };

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
int main() {
  
    int arr[] = {0, 0, 0, 1, 2, 3};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
    printVector(v);
    
    Solution s;
    printVector(s.searchRange(v,0));
    return 0;
}

