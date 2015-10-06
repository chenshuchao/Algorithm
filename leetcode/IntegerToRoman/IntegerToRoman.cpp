#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;
class Solution {

    public:
    string intToRoman(int num) {
        string str = "";
        string map[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int val[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        for(int i = 0; num > 0; i++) {
            while(num >= val[i]) {
                num -= val[i];
                str += map[i];
            }
        }
        return str;
    }
};

int main() {
    Solution s;
    cout << s.intToRoman(1) << endl;
    return 0;
}
