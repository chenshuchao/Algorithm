#include <math.h>
#include <limits.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n+1, INT_MAX);
    for (int i = 1; i <= n; i ++) {
      int x = sqrt(i);
      if (x * x == i) {
        dp[i] = 1;
        continue;
      }

      for (int j = 1; j <= x; j ++) {
        int dif = i - j*j;
        dp[i] = min(dp[i], dp[dif] + 1);
      }
    }
    return dp[n];
  }
};

int main() {

 Solution s;
 cout << s.numSquares(1) << endl;
 cout << s.numSquares(10) << endl;
 cout << s.numSquares(12) << endl;
 cout << s.numSquares(13) << endl;
}
