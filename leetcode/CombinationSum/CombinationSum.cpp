#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        if(candidates.size() == 0 || target < candidates[0]) return res;
        vector<int> temp;
        helper(candidates, target, res, temp, 0);
        return res;
    }
private:
    void helper(vector<int>& candidates, int target, vector<vector<int> >&res, vector<int>&temp, int begin) {
        if(!target) {
            res.push_back(temp);
            return;
        }
        for(int i = begin, len = candidates.size(); i < len && target >= candidates[i]; i++) {
            temp.push_back(candidates[i]);
            helper(candidates, target - candidates[i], res, temp, i);
            temp.pop_back();
        } 
   }
};

void printVector(vector<vector<int> > v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main() {
  
    int arr1[] = {};
    int arr2[] = {7};
    int arr3[] = {2, 3, 6, 7};
    int arr4[] = {8, 7, 4, 3};
    vector<int> v1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> v2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<int> v3(arr3, arr3 + sizeof(arr3) / sizeof(int));
    vector<int> v4(arr4, arr4 + sizeof(arr4) / sizeof(int));
    
    Solution s;
  //  vector<vector<int> > res1 = s.combinationSum(v1, 7);
    vector<vector<int> > res2 = s.combinationSum(v2, 7);
    vector<vector<int> > res3 = s.combinationSum(v3, 7);
    vector<vector<int> > res4 = s.combinationSum(v4, 11);

   // printVector(res1);
    printVector(res2);
    printVector(res3);
    printVector(res4);
    return 0;
}

