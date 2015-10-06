#include <iostream>
#include <queue>
#include <stack>
using namespace std;

const int NULL_NODE = -100;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > vv_res;
        if(!root)  return vv_res;
        
        stack<TreeNode*> q1, q2;
        q1.push(root);
        while(!q1.empty() || !q2.empty()) {
            vector<int> v;
            if(!q1.empty()) {
                while(!q1.empty()) {
                    TreeNode *node = q1.top();
                    q1.pop();
                    v.push_back(node->val);
                    if(node->left) q2.push(node->left);
                    if(node->right) q2.push(node->right);
                }
            } else {
                while(!q2.empty()) {
                    TreeNode *node = q2.top();
                    q2.pop();
                    v.push_back(node->val);
                    if(node->right) q1.push(node->right);
                    if(node->left) q1.push(node->left);
                }
            }
            vv_res.push_back(v);
        }
        return vv_res;
    }
};

TreeNode* buildTree(vector<int>& v) {
    int n = v.size();
    if(n == 0) return NULL;
    TreeNode *root = new TreeNode(v[0]);
    queue<TreeNode*> q;
    q.push(root);
    int pos = 1;
    while(pos < n) {
        TreeNode *p = q.front();
        q.pop();
        if(v[pos] != NULL_NODE) {
            TreeNode *t = new TreeNode(v[pos]);
            p->left = t;
            q.push(t);
        }
        pos ++;
        if(pos < n && v[pos] != NULL_NODE) {
            TreeNode *t = new TreeNode(v[pos]);
            p->right = t;
            q.push(t);
        }
        pos ++;
    }
    return root;
}
vector<int> printTree(TreeNode *root) {
    vector<int> v;
    if(!root) return v;
    queue<TreeNode*> q;
    q.push(root);
    v.push_back(root->val);
    while(!q.empty()) {
        TreeNode *t = q.front();
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
template <typename T>
void printV(const vector<T>& v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
template <typename T>
void printVV(const vector<vector<T> >& vv) {
    for(int i = 0; i < vv.size(); i++) {
        printV(vv[i]);
    }
}

int main() {

    int arr1[] = {1, 2, 3, 4, 5, -100, -100, -100, 6, 7};
    vector<int> v(arr1, arr1 + sizeof(arr1)/sizeof(int));
    TreeNode *root = buildTree(v);
    vector<int> tree = printTree(root);
    printV(tree);

    Solution s;
    vector<vector<int> > res = s.zigzagLevelOrder(root);
    
    printVV(res);
    
    return 0;
}

