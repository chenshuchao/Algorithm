#include <iostream>

using namespace std;

class Solution {
    public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        int isPositive = -1;
        if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) isPositive = 1;
        
        int res = dividend / divisor;
        if(res * isPositive < 0) return INT_MAX;

        return res;
    }
};

int main() {

    Solution s;
    printf("%d\n", s.divide(-2147483648, -1));

    return 0;
}

