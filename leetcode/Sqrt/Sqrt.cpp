#include <iostream>
using namespace std;

class Solution {
    public:
    int mySqrt(int x) {
        if(x < 2) return x;

        int left = 0;
        int right = x;
        int mid;
        while(left < right) {
            mid = (left + right) / 2;
            if(x/mid >= mid) left = mid + 1;
            else right = mid;
        }
        return right-1;
    }
};

int main() {

    Solution s;
    cout << s.mySqrt(100) << endl;
    return 0;
}
