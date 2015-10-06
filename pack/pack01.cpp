/*
 * 01 背包问题
 * 一个背包容量 V 为 10， 共有三件物品(N = 3)，价值(C[])分别为 3，4，5，重量(W[])分别为 4，5，6.
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
            for(int j = V; j > 0; j --)
                if(j >= C[i]) {
                    dp[j] = max(dp[j], dp[j-C[i]]+W[i]);
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

