#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
class Solution {
    public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if(size <= 1) return;

        helper(nums, size - 2);
    }

    private:
    void helper(vector<int>& nums, int index) {
        int size = nums.size();
        if(size <= 1) return;

        if(index == -1){
            sort(nums.begin(), nums.end());
            return;
        }
        int temp = -1;
        for(int i = index + 1; i < size; i++) {
            if(nums[i] > nums[index]) {
                if(temp < 0) {
                    temp = i;
                    continue;
                }
                if(nums[i] < nums[temp]) temp = i;
           }
        }
        if(temp > 0) {
            int t = nums[index];
            nums[index] = nums[temp];
            nums[temp] = t;
            sort(nums.begin()+index+1, nums.end()); 
        } else {
            helper(nums, index - 1);
        }
        return;
    }
};
*/
class Solution {
    public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1, k = i;
        while (i > 0 && nums[i-1] >= nums[i])
            i--;
        for (int j=i; j<k; j++, k--)
            swap(nums[j], nums[k]);
        if (i > 0) {
                k = i--;
                while (nums[k] <= nums[i])
                    k++;
                swap(nums[i], nums[k]);
            }
    }
};

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) 
        printf("%d ", v[i]);
    printf("\n");
}
int main() {
    
    Solution s;
    int arr[] = {1, 4, 2, 3};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
    printVector(v);
    s.nextPermutation(v);
    printVector(v);

    return 0;
}
