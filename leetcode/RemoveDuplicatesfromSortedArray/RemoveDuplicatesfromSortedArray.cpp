#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        
        vector<int>::iterator i = nums.begin();
        while(i != nums.end() && i != nums.end() - 1) {
            vector<int>::iterator j = i + 1;
            while(j != nums.end() && *i == *j) j++;
            nums.erase(i+1, j);
            i++;
        }
        return nums.size();
    }
};

int main() {
    int arr[] = {1,1,2,3,3,3,4,4,5};
    vector<int> v(arr, arr + sizeof(arr)/sizeof(int));

    for(int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");
    
    Solution s;
    int len = s.removeDuplicates(v);
    printf("length: %d\n", len);
    for(int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");
    
}

