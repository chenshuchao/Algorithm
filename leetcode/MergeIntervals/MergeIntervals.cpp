#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<Interval> res;
        std::sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
                return a.start < b.start;
        });
      
        int pos = 0; 
        while(pos < n) {
            int i = pos + 1;
            int end = intervals[pos].end;
            while(i < n && end >= intervals[i].start) {
                if(end < intervals[i].end) end = intervals[i].end;
                i ++;
            }
            Interval interval(intervals[pos].start, end);
            res.push_back(interval);
            pos = i;
        }
        return res;
    }
};

int main() {

    Interval a1(1,3);
    Interval a2(2,6);
    Interval a3(8,10);
    Interval a4(15,18);
    Interval a5(3,8);
    vector<Interval> v;
    v.push_back(a1);
    v.push_back(a2);
    v.push_back(a3);
    v.push_back(a4);
    v.push_back(a5);
    Solution s;
    vector<Interval> res = s.merge(v);

    for(int i = 0; i < res.size(); i++) {
        cout << res[i].start << " " << res[i].end << endl;
    }
    return 0;
}
