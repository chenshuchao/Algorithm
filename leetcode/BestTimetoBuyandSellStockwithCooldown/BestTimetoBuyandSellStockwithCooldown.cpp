//https://leetcode.com/discuss/73617/7-line-java-only-consider-sell-and-cooldown
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<int> sell(n, 0);
    vector<int> cooldown(n, 0);
    for (int i = 1; i < n; i ++) {
      sell[i] = max(sell[i-1]-prices[i-1]+prices[i], cooldown[i-1]);
      cooldown[i] = max(sell[i-1], cooldown[i-1]);
    }
    return max(sell[n-1], cooldown[n-1]);
  }
};

int main() {
  int arr1[] = {};
  vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));
  Solution s;
  s.maxProfit(v1);
  return 0;
}

