#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        if(!n) return 0;
        height.push_back(0);
        stack<int> st;
        int maxHeight = 0;
        for(int i = 0; i < height.size(); i ++) {
            while(!st.empty() && height[st.top()] > height[i]) {
                int h = height[st.top()];
                st.pop();
                int l = st.empty() ? -1 : st.top();
                maxHeight = max(maxHeight, h * (i-1-l));
            }
            st.push(i);
        }
        return maxHeight;
    }
private:
    int max(int x, int y) {
        return x > y ? x : y;
    }
};

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main() {

    int arr1[] = {2,1,5,6,2,3};
    //int arr1[] = {2,1,2};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));

    Solution s;
    cout << s.largestRectangleArea(v1) << endl;
    
    return 0;
}

