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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > vv_res;
        dfs(root, vv_res, 1);
        reverse(vv_res.begin(), vv_res.end());
        return vv_res;
    }
private:
    void dfs(TreeNode *root, vector<vector<int> >& vv_res, int height) {
        if(!root) return;
        int size = vv_res.size();
        if(height > size) vv_res.push_back(vector<int>());
        vv_res[height-1].push_back(root->val);
        dfs(root->left, vv_res, height+1);
        dfs(root->right, vv_res, height+1);
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

    //int arr1[] = {1, 2, 3, 4, 5, -100, -100, -100, 6};
    int arr1[] = {1, 2, 3, 4, -100, -100, 5};
    vector<int> v(arr1, arr1 + sizeof(arr1)/sizeof(int));
    TreeNode *root = buildTree(v);
    vector<int> tree = printTree(root);
    printV(tree);

    Solution s;
    vector<vector<int> > res = s.levelOrderBottom(root);
    
    printVV(res);
    
    return 0;
}

