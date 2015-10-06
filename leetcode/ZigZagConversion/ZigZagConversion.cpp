/*
author:chenshuchao
date:

*/
/*
https://leetcode.com/problems/zigzag-conversion/
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//we can regard the "z" queue as many repeat “v”，and in each "v",the char's position of the same row is symmetrical.
//So we find by rows.
//我们把排成 z 的这个队列看成一个个 v，即一个v 为 一个周期，周期长度为 T= 2(nRows - 1),(nRows >1),在一个周期中同一行的两个字符总是关于v的最低点对称，所以我们根据这个特性可以找出逐行的字符，注意不要重复也不要越界。
class Solution {
public:
    string convert(string s, int nRows) {

        if (nRows == 1) return s;

        int T = 2 * nRows - 2;  // the "v" period
        int length = s.length();

        string new_str = s;
        int new_str_index = 0;

        for(int i = 0; i < nRows; i++) {
            int j = i;
            int index;
            while(j < length) {
                index = j;
                new_str[new_str_index] = s[index];
                new_str_index ++;
                int v_round = j / T;  // round which the current j in,start from 0 
                index =  (2 * v_round + 1) * T - j; // index + j = 2 * ((nRows - 1) + v_round * T) = (2 * v_round + 1) * T
                if(index < length && index >= (v_round * T + nRows) && index < (v_round+1) * T) {
                    new_str[new_str_index] = s[index];
                    new_str_index ++;
                }
                j += T; // next round
            }
        }
        return new_str;
    }
};