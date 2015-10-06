// source: https://oj.leetcode.com/problems/two-sum/

// Given an array of integers, find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

// You may assume that each input would have exactly one solution.

// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        int size = numbers.size();
        vector<int> copy = numbers;
        int i = 0, j = size - 1;
        int num1,num2;
        sort(copy.begin(),copy.end());
        while(i < j)
        {
            if(copy[i] + copy[j] == target)
            {
                num1 = copy[i];
                num2 = copy[j];
                break;
            } else {
                (copy[i] + copy[j] > target) ? j-- : i++;
            }
        }
        vector<int>::iterator v1 = find(numbers.begin(),numbers.end(),num1);
        vector<int>::iterator v2 = find(numbers.begin(),numbers.end(),num2);
        if(v1 == v2) {
          v2 = find(v2 + 1,numbers.end(),num2);
        }
        int index1 = v1 - numbers.begin();
        int index2 = v2 - numbers.begin();
        int temp;
        if(index1 > index2) {
           temp = index1;
           index1 = index2;
           index2 = temp;
        }
        result.push_back(index1 + 1);
        result.push_back(index2 + 1);
        return result;
        }
};

// int main()
// {
//     vector<int> numbers = {3,2,4};
//     int target = 6;
//     vector<int> result;
//     Solution s;
//     result = s.twoSum(numbers,target);
//     vector<int>::iterator vi;
//     for(vi = result.begin(); vi != result.end(); ++vi)
//     {
//         cout << *vi << endl;
//     }
//     return 0;
// }
