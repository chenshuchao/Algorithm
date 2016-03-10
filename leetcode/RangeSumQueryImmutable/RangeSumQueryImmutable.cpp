#include <iostream>
#include <vector>

using namespace std;
class NumArray {
 public:
  NumArray(vector<int> &nums) {
    int size = nums.size();
    dp_ = vector<int>(size+1, 0);
    dp_[0] = 0;
    for (int i = 1; i <= size; i ++) {
      dp_[i] = dp_[i-1] + nums[i-1];
    }
  }
  int sumRange(int i, int j) {
    return dp_[j+1] - dp_[i];
  }
 private:
  vector<int> dp_;
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main() {

    int arr1[] = {-2, 0, 3, -5, 2, -1};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));

    NumArray numArray(v1);
    cout << numArray.sumRange(0, 0) << endl;
    cout << numArray.sumRange(0, 1) << endl;
    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(0, 5) << endl;
    return 0;
}

