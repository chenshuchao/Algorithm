#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j) {
            if(i+1 == nums[i]) i++;
            else if(nums[i] > j + 1 || nums[i] < 1 || nums[i] == nums[nums[i] - 1])  {
                swap(nums, i, j--);
            } else {
                swap(nums, i, nums[i] - 1);
            }
        }
        return j + 2; 
    }
private:
    void swap(vector<int>& nums, int i, int j)  {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
};

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
int main() {
  
    int arr[] = {1, 2 , 0};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
    printVector(v);
    
    Solution s;
    printf("%d\n", (s.firstMissingPositive(v)));
    return 0;
}

