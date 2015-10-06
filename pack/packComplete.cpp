/*
 * 完全背包问题
 * 一个背包容量 V 为 10， 共有三种物品，数量不限，重量(C[])分别为 3，4，5，价值(W[])分别为 4，5，6.
 * 求如何选择装入背包的物品使得背包中物品价值最大？
 */

#include <iostream>
#include <vector>
using namespace std;

class Pack {
public:
    int getMaxVal(int V, int N, int C[], int W[]) {
        vector<int> dp(V+1, 0);
        
        for(int i = 0; i < N; i ++) {
            for(int j = 0; j <= V; j ++)
                for(int k = 1; k * C[i] <= j; k ++) {
                    dp[j] = max(dp[j], dp[j-k*C[i]] + k*W[i]);
                }
        }

        return dp[V];
    }
};

int main() {
    int V = 10, N = 3;
    int C[] = {3, 4, 5};
    int W[] = {4, 5, 6};

    Pack p;
    cout << p.getMaxVal(V, N, C, W) << endl;
}

