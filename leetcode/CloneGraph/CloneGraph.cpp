#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        unordered_map<int, UndirectedGraphNode*> m;
        queue<UndirectedGraphNode*> q;

        UndirectedGraphNode* cloneNode = new UndirectedGraphNode(node->label);
        m[cloneNode->label] = cloneNode;
        q.push(node);
        
        while (!q.empty()) {
            UndirectedGraphNode* pNode = q.front();
            q.pop();

            for (int i = 0, len = pNode->neighbors.size(); i < len; i ++) {
                UndirectedGraphNode* newNode = NULL;
                if (m.find(pNode->neighbors[i]->label) == m.end()) {
                    newNode = new UndirectedGraphNode(pNode->neighbors[i]->label);
                    m[newNode->label] = newNode;
                    q.push(pNode->neighbors[i]);
                } else {
                    newNode = m[pNode->neighbors[i]->label]; 
                }
                 
                UndirectedGraphNode* clonepNode = m[pNode->label];
                clonepNode->neighbors.push_back(newNode);
            }
        }
        return cloneNode;
    }
};

int main() {

    UndirectedGraphNode node(0);
    node.neighbors.push_back(&node);
    node.neighbors.push_back(&node);

    for(int i = 0; i < node.neighbors.size(); i ++) {
        cout << node.neighbors[i]->label << endl;
    }

    Solution s;
    UndirectedGraphNode* cloneNode = s.cloneGraph(&node);
    for(int i = 0; i < cloneNode->neighbors.size(); i ++) {
        cout << cloneNode->neighbors[i]->label << endl;
    }
    
    return 0;
}

