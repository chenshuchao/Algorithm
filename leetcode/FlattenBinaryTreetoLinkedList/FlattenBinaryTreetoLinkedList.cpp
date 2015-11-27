#include <iostream>
#include <queue>
#include <stack>
#include <vector>

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
    void flatten(TreeNode* root) {
        TreeNode *now = root;
        while(now) {
            TreeNode *pre = now->left;
            if(pre) {
                while(pre->right) {
                    pre = pre->right;
                }
                pre->right = now->right;
                now->right = now->left;
                now->left = NULL;
            }
            now = now->right; 
        }
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
void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
void printVV(vector<vector<int> > &vv) {
    for(int i = 0; i < vv.size(); i ++) {
        printVector(vv[i]);
    }
}
int main() {

    int arr1[] = {5, 4, 8, 11, -100, 13, 4, 7, 2, -100, -100, 5, 1};
    //int arr1[] = {5, 4, 8, 11, -100, 13, 4, 7, 2, -100, -100, -100, 1};
    //int arr1[] = {1,-2,-3,1,3,-2,-100,-1};
    vector<int> v(arr1, arr1 + sizeof(arr1)/sizeof(int));
    TreeNode *root = buildTree(v);
    vector<int> tree = printTree(root);
    printVector(tree);

    Solution s;
    s.flatten(root);
    printVector(printTree(root));
    
    return 0;
}

