#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int total = 0;
        int res = 0;
        for (int i = 0, len = gas.size(); i < len; i ++) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                total += sum;
                sum = 0;
                res = i + 1;
            }
        }
        total += sum;
        return total < 0 ? -1 : res;
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

    int arr1[] = {2, 4, 1, 5};
    int arr2[] = {3, 1, 1, 7};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));
    vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(int));

    Solution s;
    cout << s.canCompleteCircuit(v1, v2) << endl;
    return 0;
}

