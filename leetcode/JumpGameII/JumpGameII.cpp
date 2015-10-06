#include <iostream>
#include <vector>
#include <climits>

using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        const int MAXINT = INT_MAX;
        int n = nums.size();
        if(n <= 1) return 0;

        bool *isConfirmed = new bool[n];
        for(int i = 0; i < n; i++)
            isConfirmed[i] = false;
        int *dist = new int[n];
        for(int i = 0; i < n; i++)
            dist[i] = MAXINT;
       
        isConfirmed[0] = true;
        dist[0] = 0;
        
        for(int i = 0; i < n; i++) {
            int j = i + nums[i];
            if(j >= n-1) {
                dist[n-1] = dist[i] + 1;
                break;
            }
            for(; j > i; j --) {
                if(isConfirmed[j]) break;

                isConfirmed[j] = true;
                dist[j] = dist[i] + 1;
            } 
        }

        int lastDist = dist[n-1];
        delete isConfirmed;
        delete dist;

        return lastDist;
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
    cout << s.jump(v1) << endl;
    cout << s.jump(v2) << endl;
    cout << s.jump(v3) << endl;
    cout << s.jump(v4) << endl;
    return 0;
}
