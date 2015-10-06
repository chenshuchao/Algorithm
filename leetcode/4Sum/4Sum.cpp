#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {

    public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int n = num.size();
        vector<vector<int> > res;
        if(n < 4) return res;
        sort(num.begin(),num.end());
        int last_i = num[0] - 1;
        for(int i = 0; i < n - 3; i++) {
            if(last_i == num[i]) continue;
            int last_j = num[0] - 1;
            for(int j = i+1; j < n - 2; j++) {
                if(last_j == num[j]) continue;
                int low = j + 1;
                int high = n - 1;
                while(low < high) {
                    int sum = num[i] + num[j] + num[low] + num[high];
                    if(sum == target) {
                         vector<int> v;
                         v.push_back(num[i]);
                         v.push_back(num[j]);
                         v.push_back(num[low]);
                         v.push_back(num[high]);
                         res.push_back(v);
                         while(low < n && num[low+1] == num[low]) low ++;
                         while(high > 0 && num[high-1] == num[high]) high --;
                         low ++;
                         high--;
                    } else if(sum < target) {
                        low ++;
                    } else {
                        high --;
                    }
                }
                last_j = num[j];
            }
            last_i = num[i];
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> num =  {0,0,0,0 };
    vector<vector<int> > res = s.fourSum(num,0);
    for(int i = 0; i < res.size(); i++) {
      for(int j = 0; j < res[i].size(); j++) {
        cout << res[i][j] << " ";
      }
      cout << endl;
    }
    return 0;
}
