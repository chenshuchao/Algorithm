#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int pos = m + n -1;
        while(p1 >= 0 && p2 >= 0) {
            if(nums1[p1] >= nums2[p2]) {
                nums1[pos] = nums1[p1];
                p1 --;
            } else {
                nums1[pos] = nums2[p2];
                p2 --;
            }
            pos --;
        }
        if(p2 >= 0) {
            for(int i = p2; i >= 0; i --)
                nums1[i] =  nums2[i];
        }
    }
};
void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main() {

    int arr1[] = {1, 3, 5, 6, 7, 10, 10};
    int arr2[] = {1, 2, 3, 4, 7, 8, 9};
    int m = sizeof(arr1)/sizeof(int);
    int n = sizeof(arr2)/sizeof(int);
    vector<int> v1(m+n, 0);
    vector<int> v2(n, 0);
    for(int i = 0; i < m; i ++)
        v1[i] = arr1[i];
    for(int i = 0; i < n; i ++)
        v2[i] = arr2[i];

    Solution s;
    printVector(v1);
    s.merge(v1, m, v2, n);
    
    printVector(v1);
    return 0;
}

