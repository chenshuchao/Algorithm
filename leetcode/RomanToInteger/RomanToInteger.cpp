#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;
class Solution {

    public:
    int romanToInt(string s) {
        int n = s.size();
        if(!n) return 0;
        string map[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int map_size = 13;
        int val[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int sum = 0;
        int index = 0;
        for(int i = 0; i < map_size ; i++) {
            while(index < n && map[i].size() == 1 && s.substr(index,1) == map[i]) {
                sum += val[i];
                index ++;
            }
            while(index < n && map[i].size() == 2 && s.substr(index,2) == map[i]){
                sum += val[i];
                index += 2;
            }
        }
        return sum;
    }
};

int main() {
    Solution s;
    cout << s.romanToInt("") << endl;
    return 0;
}
