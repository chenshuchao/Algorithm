#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        int i = 0;
        while(i < nums.size()) {
            if(i > 1 && nums[i] == nums[i-1] && nums[i] == nums[i-2]) {
                int left = i;
                do {
                    left ++;
                } while(left < nums.size() && nums[left] == nums[left-1]);
                nums.erase(nums.begin()+i, nums.begin()+left);
            } else {
                i ++;
            }
        }
        return nums.size();
    }
};

// Another solution
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        return i;
    }
};
*/
void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main() {

    int arr1[] = {1};
    
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));

    Solution s;
    cout << s.removeDuplicates(v1) << endl;
    
    return 0;
}

