#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string dict(n, 0);
        iota(dict.begin(), dict.end(), '1');

        vector<int> fract(n, 1);
        for(int i = n-3; i >=0; i--) {
            fract[i] = fract[i+1] * (n-1-i);
        }

        --k;

        string ret(n, 0);
        for(int i = 0; i < n; i++) {
            int  select = k / fract[i];
            k %= fract[i];
            ret[i] = dict[select];
            dict.erase(dict.begin() + select, dict.begin() + select + 1);
        }
        return ret;
    }

};

int main() {

    Solution s;
    cout << s.getPermutation(4, 4) << endl;;
    return 0;
}

