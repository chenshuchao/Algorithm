#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        if(size == 0) return 0;
       
        int count = 0;
        for(int i = size - 1, j = i; i >= 0; i--) {
            if(nums[i] != val) continue;
     
            while(j > i && nums[j] == val) j--;
            nums[i] = nums[j];
            j --;
            size --;
        }
        return size;
    }   
};

int main() {
    int arr[] = {1, 2, 3, 5};
    vector<int> v(arr, arr + sizeof(arr)/sizeof(int));

    for(int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");
    
    Solution s;
    int len = s.removeElement(v, 5);
    printf("length: %d\n", len);
    for(int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");
    
    return 0;
}
