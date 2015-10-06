#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int num = pow(2, n);
        vector<int> v(num, 0);
        int temp = 1;
        int flag;
        for(int i = 1; i < num; i ++) {
            v[i] = v[i-1] ^ temp;
            if(temp == 1) flag = true;
            if(temp == pow(2, n-1))  flag = false;

            if(flag) temp = temp << 1;
            else temp = temp >> 1;
        }
        return v;
    }
};
/*
class Solution {
public:
    vector<int> grayCode(int n) {
        int num = pow(2, n);
        vector<int> v(num, 0);
        int temp = 2;
        bool flag = true;
        for(int i = 1; i < num; i ++) {
            if(i % 2)  v[i] = v[i-1] ^ 1;
            else {
                v[i] = v[i-1] ^ temp;
                if(temp == 2) flag = true;
                if(temp == pow(2, n-1)) flag = false;

                if(flag) temp = temp << 1;
                else temp = temp >> 1;
            }
        }
        return v;
    }
};
*/
void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
int main() {

    Solution s;
    vector<int> v1 = s.grayCode(4);
    printVector(v1);
    
    return 0;
}

