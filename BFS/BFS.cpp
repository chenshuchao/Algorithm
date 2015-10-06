#include <iostream>
#include <climits>
#include <queue>
using namespace std;

const int MAXINT = INT_MAX;
const int maxNum = 100;
// n -- 总点数
// u -- 原点
// w[][] -- 两点间路径权值
// dist[] -- 到原点的路径长度
// prev[] -- 前一个结点,用于确定最终路径
// color[] -- 0 表示白色，1 表示灰色，2 表示黑色

void BFS(int n, int s, int w[maxNum][maxNum], int *dist, int *prev) {
    int *color = new int[n];
    for(int i = 0; i < n; i++) {
        color[i] = 0;
        prev[i] = -1;
        dist[i] = 0;
    }
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i = 0; i < n; i++) {
            if(w[u][i] < MAXINT && color[i] == 0) {
                color[i] = 1;
                dist[i] = dist[u] + 1;
                prev[i] = u;
                q.push(i);
            }
        }
        color[u] = 2;
    }
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
    BFS(5, 0, w, dist, prev);

    for(int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < n; i++) {
        cout << prev[i] << " ";
    }

    return 0;
}

