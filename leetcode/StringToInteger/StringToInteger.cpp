/*
author : chenshuchao
date: 2015-4-11
*/
/*
Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
spoilers alert... click to show requirements for atoi.
Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/


#include<iostream>
#include<string>
#include<climits>

using namespace std;

class Solution {

    public:

    int atoi(string str) {
        
        if(!str.size()) return 0;

        int index = 0;
        for(; isspace(str[index]); index++);

        bool isNeg = false;
        if(str[index] == '+' || str[index] == '-') {
            isNeg = (str[index] == '-');
            index ++;
        }

        int abs_x = 0;
        for(int i = index; isdigit(str[i]); i++) {
            int num = str[i] - '0';
            if(isNeg) {
                if((INT_MIN + num)/10 > - abs_x) {
                    return INT_MIN;
                }
            } else {
                if((INT_MAX - num) / 10 < abs_x) {
                    return INT_MAX;
                }
            }

            abs_x = 10 * abs_x + num;
        }

        return isNeg ? -abs_x : abs_x;
    }

};

int main() {
    Solution s;
    int x = 1052254545;
    cout << x << endl;
    cout << 10 * x << endl;
    cout << "   123" << " return "  << s.atoi("  123") << endl;
    cout << "   -123" << " return "  << s.atoi("  -123") << endl;
    cout << "h123" << " return "  << s.atoi(" h123") << endl;
    cout << "   1hi23" << " return "  << s.atoi("  1hi23") << endl;
    cout << "987654321987654" << " return "  << s.atoi("987654321987654") << endl;
    cout << "-987654321987654" << " return "  << s.atoi("-987654321987654") << endl;
    cout << "    10522545459" << " return "  << s.atoi("    10522545459") << endl;
    cout << "10522545459" << " return "  << s.atoi("10522545459") << endl;
    return 0;
}

