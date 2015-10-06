#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size <= 2) return 0;
        
        int left = 0;
        int right = 0;
        int sum = 0;
        while(left < size - 2) {
            if(height[left] <= height[left+1]) {
                left ++;
                continue;
            }

            right = left + 1;
            int maxRight = right;
            while(height[left] > height[maxRight]) {
                while(right < size - 1 && height[right] >= height[right+1]) {
                    right ++;
                }
                if(right == size - 1) break;
                while(right < size - 1 && height[right] <= height[right+1]) {
                    right ++;
                }
                maxRight = height[right] > height[maxRight] ? right : maxRight;
            }
            
            int interval = maxRight - left - 1;
            int minHeight = min(height[left], height[maxRight]);
            int temp = minHeight * interval;
            for(int i = left + 1; i < maxRight; i++) {
               temp -= min(height[i], minHeight); 
            }
            sum += temp;
            
            left = maxRight;
        }
        return sum;
    }
};


int main() {
    
    int arr1[]  = {0,1,0,2,1,0,1,3,2,1,2,1};
    int arr2[]  = {2, 1, 1, 0, 3, 2, 1};
    int arr3[]  = {0,1,0,2,1,0,1,3,2,1,2,1};
    int arr4[]  = {5,2,1,2,1,5,2,1};
    vector<int> v1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> v2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<int> v3(arr3, arr3 + sizeof(arr3) / sizeof(int));
    vector<int> v4(arr4, arr4 + sizeof(arr4) / sizeof(int));
    Solution s;
    cout << s.trap(v1) << endl;
    cout << s.trap(v2) << endl;
    cout << s.trap(v3) << endl;
    cout << s.trap(v4) << endl;
    return 0;
}
