#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n) return 0;
        int left = 0, right = n-1;
        while(left <= right) {
            while(left < right && nums[left] == nums[left+1]) left ++;
            while(right > left && nums[right] == nums[right-1]) right --;

            int mid = (left+right)/2;
            if(nums[mid] == target) return true;
            else if( (nums[mid] >= nums[left] && (target > nums[mid] || target < nums[left])) ||
                    (nums[mid] <= nums[left] && target > nums[mid] && target <= nums[right]))
            {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
void printVV(vector<vector<int> > vv) {
    for(int i = 0; i < vv.size(); i++) {
        for(int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {

    //int arr1[] = {3, 4, 6, 7, 1, 2};
    int arr1[] = {1, 3, 5};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));

    Solution s;
    cout << s.search(v1, 1) << endl;
    cout << s.search(v1, 4) << endl;
    cout << s.search(v1, 6) << endl;
    cout << s.search(v1, 7) << endl;
    cout << s.search(v1, 1) << endl;
    cout << s.search(v1, 2) << endl;
    cout << s.search(v1, -1) << endl;
    cout << s.search(v1, 5) << endl;
    cout << s.search(v1, 8) << endl;
    
    return 0;
}

