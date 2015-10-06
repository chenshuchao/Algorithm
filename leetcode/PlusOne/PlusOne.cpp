#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> v(digits);
        int n = v.size();
        if(n == 0) return v;

        int carry = 0;
        int i = n-1;
        do {
            if(v[i] < 9) {
                v[i] ++;
                carry = 0;
            } else {
                v[i] = 0;
                carry = 1;
            }
        } while(carry && --i >= 0);
       
        if(carry) {
            v.insert(v.begin(), 1);
        }

        return v;
    }
};

int main() {

    int arr[] = {1, 9, 9};
    vector<int> v(arr, arr + sizeof(arr)/sizeof(int));
    Solution s;
    vector<int> res = s.plusOne(v);

    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
