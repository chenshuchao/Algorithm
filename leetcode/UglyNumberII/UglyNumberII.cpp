#include <iostream>
#include <vector>

using namespace std;

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

class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= n; i ++) {
      dp[i] = min(min(2*dp[p2], 3*dp[p3]), 5*dp[p5]);
      if (dp[i] == 2*dp[p2]) p2 ++;
      if (dp[i] == 3*dp[p3]) p3 ++;
      if (dp[i] == 5*dp[p5]) p5 ++;
    }
    return dp[n];
  }
};

int main() {
  Solution s;
  cout << s.nthUglyNumber(1) << endl;
  cout << s.nthUglyNumber(5) << endl;
  cout << s.nthUglyNumber(10) << endl;
  cout << s.nthUglyNumber(11) << endl;
  return 0;
}

