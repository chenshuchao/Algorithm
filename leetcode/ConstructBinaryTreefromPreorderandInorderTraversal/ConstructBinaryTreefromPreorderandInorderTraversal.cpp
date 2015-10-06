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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        if(size == 0) return NULL;

        int index = 0;
        return buildTree(preorder, &index, inorder, 0, size-1);
    }
    TreeNode* buildTree(vector<int>& preorder, int *index, vector<int>& inorder, int in_left, int in_right) {
        int val = preorder[*index];
        int pos = in_left;
        while(pos <= in_right && inorder[pos] != val) pos ++;
        if(pos > in_right) return NULL;
       
        TreeNode *proot = new TreeNode(val);
        (*index) ++;
        proot->left = buildTree(preorder, index, inorder, in_left, pos-1);
        proot->right = buildTree(preorder, index, inorder, pos+1, in_right);
        return proot;
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

    int arr1[] = {1, 2, 4, 5, 7, 3, 6};
    int arr2[] = {4, 2, 7, 5, 1, 3, 6};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));
    vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(int));

    Solution s;
    TreeNode *root = s.buildTree(v1, v2);
    
    printV(printTree(root));
    
    return 0;
}

