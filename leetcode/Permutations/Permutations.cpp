#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector <int> > vv;
        int pos = 0;
        vv.push_back(nums);
        if(nums.size() <= 1) return vv;
        
        while(pos < nums.size()-1) {
            int size = vv.size();
            for(int i = 0; i < size; i++) {
                for(int j = pos+1; j < vv[i].size(); j++) {
                    vector<int> v = vv[i];
                    int t = v[j];
                    v[j] = v[pos];
                    v[pos] = t;
                    vv.push_back(v); 
                }
            } 
            pos ++;
        }
        return vv;
    }
};

int main() {

    int arr1[] = {1, 2, 3};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));

    Solution s;
    vector<vector<int> > vv = s.permute(v1);

    for(int i = 0; i < vv.size(); i++) {
        for(int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl; 
    }

    return 0;
}

