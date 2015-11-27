#include <iostream>
#include <queue>
#include <stack>
using namespace std;

const int NULL_NODE = -100;
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
    public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        int num = 1;
        while(!q.empty()) {
            for(int i = 0; i < num; i ++) {
                TreeLinkNode *node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(i == num -1) node->next = NULL;
                else node->next = q.front(); 
            }
            num *= 2;
        }
    }
};

TreeLinkNode* buildTree(vector<int>& v) {
    int n = v.size();
    if(n == 0) return NULL;
    TreeLinkNode *root = new TreeLinkNode(v[0]);
    queue<TreeLinkNode*> q;
    q.push(root);
    int pos = 1;
    while(pos < n) {
        TreeLinkNode *p = q.front();
        q.pop();
        if(v[pos] != NULL_NODE) {
            TreeLinkNode *t = new TreeLinkNode(v[pos]);
            p->left = t;
            q.push(t);
        }
        pos ++;
        if(pos < n && v[pos] != NULL_NODE) {
            TreeLinkNode *t = new TreeLinkNode(v[pos]);
            p->right = t;
            q.push(t);
        }
        pos ++;
    }
    return root;
}
vector<int> printTree(TreeLinkNode *root) {
    vector<int> v;
    if(!root) return v;
    queue<TreeLinkNode*> q;
    q.push(root);
    v.push_back(root->val);
    while(!q.empty()) {
        TreeLinkNode *t = q.front();
        q.pop();
        if(t->left) {
            v.push_back(t->left->val);
            q.push(t->left);
        } else {
            v.push_back(NULL_NODE);
        }
        if(t->right) {
            v.push_back(t->right->val);
            q.push(t->right);
        } else {
            v.push_back(NULL_NODE);
        }
    }
    return v;
}
void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
int main() {

    //int arr1[] = {5, 4, 8, 11, -100, 13, 4, 7, 2, -100, -100, -100, 1};
    int arr1[] = {1,-2,-3,1,3,-2,-100,-1};
    vector<int> v(arr1, arr1 + sizeof(arr1)/sizeof(int));
    TreeLinkNode *root = buildTree(v);
    vector<int> tree = printTree(root);
    printVector(tree);

    Solution s;
    s.connect(root);
    printVector(printTree(root));
 
    return 0;
}

