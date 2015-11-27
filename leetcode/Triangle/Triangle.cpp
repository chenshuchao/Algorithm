#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        int n = triangle.size();
        if(n == 0) return 0;
        vector<int> dp(triangle[n-1]);
        for(int i = n - 2; i >= 0; i --) {
            for(int j = 0; j < triangle[i].size(); j ++) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
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
    int arr1[] = {2};
    int arr2[] = {3, 4};
    int arr3[] = {6, 5, 7};
    int arr4[] = {4, 1, 8, 3};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));
    vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(int));
    vector<int> v3(arr3, arr3 + sizeof(arr3)/sizeof(int));
    vector<int> v4(arr4, arr4 + sizeof(arr4)/sizeof(int));
    
    vector<vector<int> > vv;
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    vv.push_back(v4);

    Solution s;
    cout << s.minimumTotal(vv) << endl;   

    return 0;
}

