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
    vector<TreeNode*> generateTrees(int n) {
        
    }
private:
    void helper(int left, int right, TreeNode *parent, TreeNode *root, vector<TreeNode*>& res) {
        int mid = parent->val;
        for(int i = left; i < mid; i ++) {
            TreeNode *newRoot1 = cloneTree(root);
            TreeNode *t1 = new TreeNode(i);
            helper(left, mid-1, t1, newRoot1, res);

            TreeNode *newRoot2 = cloneTree(root);
            TreeNode *t2 = new TreeNode(i);
            helper(mid+1, right, t2, root, res);
        }
    }
    TreeNode* cloneTree(TreeNode *root) {
        if(!root) return NULL;
        TreeNode *newRoot = new TreeNode(root->val);
        if(root->left) newRoot->left = cloneTree(root->left);
        if(root->right) newRoot->right = cloneTree(root->right);
        return newRoot;
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
vector<int> treeToVector(TreeNode *root) {
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
int main() {

    int arr1[] = {1, 2, 3, 4, 5, -100, -100, -100, 6};
    vector<int> v(arr1, arr1 + sizeof(arr1)/sizeof(int));
    TreeNode *root = buildTree(v);
    vector<int> tree = treeToVector(root);
    printVector(tree);

    Solution s;
    vector<TreeNode*> res = s.generateTrees(3);
    
    for(int i = 0; i < res.size(); i ++) {
        printVector(treeToVector(res[i]));
    }
    return 0;
}

