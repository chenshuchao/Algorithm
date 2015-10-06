#include <iostream>
using namespace std;

class Solution {
    public:
    int strStr(string haystack, string needle) {
        int h_size = haystack.length(); 
        int n_size = needle.length();
        if (h_size < n_size) return -1;
        if (h_size == 0 && n_size == 0) return 0;
        
        int pos = 0;
        int t_pos = 0;
        int last_pos = h_size - n_size;
        while(pos <= last_pos) {
            t_pos = pos;
            int i = 0;
            for(; i < n_size; i++, t_pos++) {
                if(haystack[t_pos] != needle[i]) break;
            }
            if(i == n_size) return pos; 
            pos ++;
        }
        
        return -1;
    }
};


int main() {

    Solution s;
    printf("%d\n", s.strStr("", ""));

    return 0;
}

