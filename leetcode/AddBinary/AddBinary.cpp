#include <iostream>

using namespace std;

class Solution {
    public:
    string addBinary(string a, string b) {

        if(a.size() < b.size()) {
            string s = a;
            a = b;
            b = s;
        }
        int len_a = a.size();
        int len_b = b.size();
        if(len_a == 0) return b;
        if(len_b == 0) return a;

        int pos_a = len_a - 1;
        int pos_b = len_b - 1;
        int carry = 0;
        while(pos_a >=0 && (pos_b >= 0 || carry)) {

            int temp;
            if(pos_b >= 0) {
                temp = (a[pos_a]-'0') + (b[pos_b]-'0') + carry;
                pos_b --;
            } else {
                temp = (a[pos_a]-'0') + carry;
            }
            carry = temp / 2; 
            a[pos_a] = temp % 2 + '0';

            pos_a --;
        }
        if(carry) {
            a = '1' + a;
        }

        return a;
    }
    private:
    int min(int x, int y) {
        return x < y ? x : y;
    }
};

int main() {

    Solution s;
    cout << s.addBinary("110", "11") << endl;
    cout << s.addBinary("", "11") << endl;
    cout << s.addBinary("110", "") << endl;
    cout << s.addBinary("1", "101") << endl;
    cout << s.addBinary("101", "110") << endl;
    cout << s.addBinary("110", "100") << endl;

    return 0;
}
