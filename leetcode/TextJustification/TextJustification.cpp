#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n  = words.size();
        vector<string> res;
        int left = 0;
        while(left < n) {
            int sum = words[left].size();
            int right = left;
            int num = 1;

            while(right+1 < n && sum + words[right+1].size() + num <= maxWidth) {
                right ++;
                num ++;
                sum = sum + words[right].size();
            }
            int space = maxWidth - sum;
            vector<int> spaceNum(num, 0);
            if(right == n-1) {
                for(int i = 0; i < num-1; i++)
                    spaceNum[i] = 1;
                spaceNum[num-1] = space-num+1;
            } else {
                if(num == 1) {
                    spaceNum[num-1] = space;
                } else {
                    for(int i = num - 2; i >= 0; i--) {
                        int t = space / (i + 1);
                        spaceNum[i] = t;
                        space -= t;
                    } 
                }
            }

            string s = "";
            for(int i = 0; i < num; i++) {
                string t(spaceNum[i], ' ');
                s += words[left+i] + t;
            }
            
            res.push_back(s);
            left = right+1;
        }
        return res; 
    }
};

int main() {
    string arr[] = {"Listen","to","many,","speak","to","a","few."};
    //string arr[] = {"This", "is", "an", "example", "of", "text", "justification", "ma", "l"};
    vector<string> v(arr, arr + 7);
    Solution s;
    vector<string> res = s.fullJustify(v, 6);

    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
