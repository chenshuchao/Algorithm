#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() < 1 || num2.size() < 1) return "";
/*
        int flag1 = 1;
        if(num1[0] == '-') {
            num1 = num1.substr(1);
            flag1 = -1; 
        }
        int flag2 = 1;
        if(num2[0] == '-') {
            num2 = num2.substr(1);
            flag2 = -1;
        }
 */       
        int size1 = num1.size();
        int size2 = num2.size();
        int size = size1 + size2 + 1;
        
        string res(size, '0');
        for(int i = size2 - 1; i >= 0; i--) {
            int carry = 0;
            for(int j = size1 - 1; j >= 0; j--) {
                int a = charToInt(res[i+j+2]);
                int b = charToInt(num2[i]);
                int c = charToInt(num1[j]);
                int temp = a + b * c + carry;
                carry = temp / 10;
                res[i+j+2] = intToChar(temp - carry * 10);
            }
            res[i+1] = intToChar(carry);
            
        }

        int i = 0;
        for(; i < size; i++) {
            if(res[i] != '0') break;
        }
        res = res.substr(i);
        /*
        int flag = flag1 * flag2;
        if(flag < 0) res = "-" + res;
        */
        return res == "" ?  "0" : res;
    }
private:
    int charToInt(char ch) {
        return ch - '0';
    }
    char intToChar(int i) {
        return '0' + i;
    }
};


int main() {

    Solution s;
    cout << s.multiply("0", "0") << endl;
    return 0;
}

