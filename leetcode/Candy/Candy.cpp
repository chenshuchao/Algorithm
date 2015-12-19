#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n < 1) return 0;

        vector<int> nums(n, 1);
        for (int i = 1; i < n; i ++) {
            if (ratings[i] > ratings[i-1]) {
                nums[i] = nums[i-1] + 1;
            }
        }
        for (int i = n-2; i >= 0; i --) {
            if (ratings[i] > ratings[i+1]) {
                nums[i] = max(nums[i], nums[i+1]+1);
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            sum += nums[i];
        }
        return sum;
    }
};

template <typename T>
void printV(const vector<T>& v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
template <typename T>
void printVV(const vector<vector<T> >& vv) {
    for(int i = 0; i < vv.size(); i++) {
        printV(vv[i]);
    }
}


int main() {

    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {4, 3, 2, 1};
    int arr3[] = {1, 2, 3, 4, 3, 2, 1};
    int arr4[] = {4, 3, 2, 1, 2, 3, 4};
    int arr5[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int arr6[] = {1, 2, 3, 4, 4, 4, 3, 2, 1};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));
    vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(int));
    vector<int> v3(arr3, arr3 + sizeof(arr3)/sizeof(int));
    vector<int> v4(arr4, arr4 + sizeof(arr4)/sizeof(int));
    vector<int> v5(arr5, arr5 + sizeof(arr5)/sizeof(int));
    vector<int> v6(arr6, arr6 + sizeof(arr6)/sizeof(int));

    Solution s;
    cout << s.candy(v1) << endl;
    cout << s.candy(v2) << endl;
    cout << s.candy(v3) << endl;
    cout << s.candy(v4) << endl;
    cout << s.candy(v5) << endl;
    cout << s.candy(v6) << endl;
    
    return 0;
}

