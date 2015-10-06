#include <iostream>
#include <climits>
using namespace std;

const int MAXINT = INT_MAX;
const int maxNum = 100;
// n -- 总点数
// u -- 原点
// w[][] -- 两点间路径权值
// dist[] -- 到原点的路径长度
// prev[] -- 前一个结点,用于确定最终路径
// color[] -- 0 表示白色，1 表示灰色，2 表示黑色

void DFS_visit(int n, int u, int w[maxNum][maxNum], int *dist, int *prev, int *color) {
    color[u] = 1;
    if(prev[u] >= 0) dist[u] = dist[prev[u]] + 1;

    for(int i = 0; i < n; i++) {
        if(w[u][i] < MAXINT && color[i] == 0) {
            prev[i] = u;
            DFS_visit(n, i, w, dist, prev, color);
        }
    }
    color[u] = 2;
}
void DFS(int n, int u, int w[maxNum][maxNum], int *dist, int *prev) {
    int *color = new int[n];
    for(int i = 0; i < n; i++) {
        color[i] = 0;
        prev[i] = -1;
        dist[i] = 0;
    }
    DFS_visit(n, u, w, dist, prev, color);
    delete color;
}


int main() {
   
    const int n = 5;
    int w[maxNum][maxNum] = {
        {MAXINT, 10, MAXINT, 30, 100},
        {MAXINT, MAXINT, 50, MAXINT, MAXINT},
        {MAXINT, MAXINT, MAXINT, MAXINT, 10},
        {MAXINT, MAXINT, 20, MAXINT, 60},
        {MAXINT, MAXINT, MAXINT, MAXINT, MAXINT}
    };

    int dist[n];
    int prev[n];

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++)
            cout << w[i][j] << " ";
        cout << endl;
    }
    DFS(5, 0, w, dist, prev);

    for(int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < n; i++) {
        cout << prev[i] << " ";
    }

    return 0;
}

