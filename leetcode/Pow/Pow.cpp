#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(equals(x, 0.0) && n <= 0) return 0.0;
        int abs_n;
        abs_n = abs(n);
        double res = pow(x, abs_n);
        return n > 0 ? res : 1.0/res;
    }
private:
    double pow(double x, unsigned int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        
        double res = pow(x, n >> 1);
        res *= res;
        if((n & 0x1) == 1) res *= x;
        return res;
    }
    bool equals(double x, double y) {
        if((x - y > 0.0000001) && (x - y < 0.0000001)) {
            return true;
        }
        return false; 
    }
};

int main() {

    Solution s;
    cout << s.myPow(0, 2) << endl;
    cout << s.myPow(2.1, 4) << endl;
    cout << s.myPow(2.0, -2) << endl;
    cout << s.myPow(-2.0,4) << endl;
    cout << s.myPow(-2.0,-4) << endl;
    cout << s.myPow(3.0, 0) << endl;
    cout << s.myPow(0.00001, 2147483647) << endl;
    cout << s.myPow(1.00000, -2147483648) << endl;
    
    cout << abs(-2147483648.0) << endl;
    
    return 0;
}
