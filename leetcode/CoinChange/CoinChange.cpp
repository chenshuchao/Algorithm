#include <iostream>
#include <vector>
#include <map>
#include <limits.h>

using namespace std;

// Time Limit Exceeded.
/*
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    if (amountDict_.find(amount) != amountDict_.end()) {
      return amountDict_[amount];
    }
    int n = amount + 1;
    for (int i = 0; i < coins.size(); i ++) {
      int cur = 0;
      if (coins[i] <= amount) {
        int next = coinChange(coins, amount-coins[i]);
        if (next >= 0) {
          cur = 1 + next;
        }
      }
      if (cur > 0) {
        n = min(n, cur);
      }
    }
    int res = (n == amount+1) ? -1 : n;
    amountDict_[amount] = res;
    return res;
  }
 private:
  map<int, int> amountDict_;
};
*/

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,INT_MAX);
    dp[0] = 0;

    for(int i=0; i<amount; i++) {
      for(int j=0; j<(int)coins.size(); j++) {
        if(dp[i] != INT_MAX) {
          if(i+coins[j]<=amount) dp[i+coins[j]] = min(dp[i+coins[j]], dp[i]+1);
        }
      }
    }
    return dp[amount]==INT_MAX ? -1 : dp[amount];
  }
  /*
  int coinChange(vector<int>& coins, int amount) {
    if (amount < 1) return 0;
    vector<int> amountDict(amount, 0);
    return helper(coins, amount, amountDict);
  }
  int helper(vector<int>& coins, int amount, vector<int>& amountDict) {
    if (amount < 0) return -1;
    if (amount == 0) return 0;
    if (amountDict[amount] != 0) return amountDict[amount-1];
    int min_num = INT_MAX;
    for (int i = 0; i < coins.size(); i ++) {
      int next = helper(coins, amount-coins[i], amountDict);
      if (next >= 0 && next < min_num) {
        min_num = 1 + next;
      }
    }
    amountDict[amount-1] = (INT_MAX == min_num) ? -1 : min_num;
    return amountDict[amount-1];
  }
  */
};


int main() {
    //int arr1[] = {224,2,217,189,79,343,101};
    int arr1[] = {186,419,83,408};
    vector<int> coins(arr1, arr1 + sizeof(arr1)/sizeof(int));
    Solution s;
    cout << s.coinChange(coins, 3500) << endl;
    return 0;
}

