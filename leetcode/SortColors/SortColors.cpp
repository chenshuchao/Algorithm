#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return;
        int p1 = 0, p2 = n-1;
        while(p1 < n && nums[p1] == 0) p1 ++;
        while(p2 >= 0 && nums[p2] == 2) p2 --;

        int p3 = p1;
        while(p3 <= p2) {
            if(nums[p3] == 0) {
                swap(nums, p1 ++, p3 ++);
            } else if(nums[p3] == 1) {
                p3 ++;
            } else {
                swap(nums, p2 --, p3);
            }
        }
    }

    void swap(vector<int>& nums, int x, int y) {
        int t = nums[x];
        nums[x] = nums[y];
        nums[y] = t;
    }
};

void printv(const vector<int>& v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
int main() {
 
    int arr[] = {0,2,1,2,0,0,1,2,1,1,1,0,2,1,2,1,1,1,1,2,1,0,0,0,1,2,2,0,2,1,0,0,1,2,2,1,2,1,0,0,0,0,2,0,2,1,2,1,1,1,1,0,1,2,0,0,0,0,0,0,2,1,1,0,0,1,1,0,0,0,0,1,1,2,2,0,2,1,1,1,2,0,1,1,1,0,2,1,1,2,2,0,1,0,0,1,0,2,2,1,2,1,2,0,0};
    vector<int> v(arr, arr + sizeof(arr)/sizeof(int));
    printv(v);
    Solution s;
    s.sortColors(v);
    printv(v);

    return 0;
}
