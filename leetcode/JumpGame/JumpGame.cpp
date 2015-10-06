#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 1;

        bool *isConfirmed = new bool[n];
        for(int i = 0; i < n; i++)
            isConfirmed[i] = false;
       
        isConfirmed[0] = true;
        
        for(int i = 0; i < n; i++) {
            if(!isConfirmed[i]) break;

            int j = i + nums[i];
            if(j >= n-1) {
                isConfirmed[n-1] = true;
                break;
            }
            for(; j > i; j --) {
                if(isConfirmed[j]) break;

                isConfirmed[j] = true;
            } 
        }

        bool isReached = isConfirmed[n-1];
        delete[] isConfirmed;

        return isReached;
    }
};
int main() {

    int arr1[] = {};
    int arr2[] = {1};
    int arr3[] = {2,2,1,1,4};
    int arr4[] = {2,2,0,0,4};
    vector<int> v1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> v2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<int> v3(arr3, arr3 + sizeof(arr3) / sizeof(int));
    vector<int> v4(arr4, arr4 + sizeof(arr4) / sizeof(int));
    Solution s;
    cout << s.canJump(v1) << endl;
    cout << s.canJump(v2) << endl;
    cout << s.canJump(v3) << endl;
    cout << s.canJump(v4) << endl;
    return 0;
}

