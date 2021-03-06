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
        return generateTrees(1, n);
    }
private:
    vector<TreeNode*> generateTrees(int from, int to) {
        vector<TreeNode*> res;
        if(from - to > 0) res.push_back(NULL);
        else if(from - to == 0) res.push_back(new TreeNode(from));
        else {
            for(int i = from; i <= to; i ++) {
                vector<TreeNode*> left = generateTrees(from, i-1);
                vector<TreeNode*> right = generateTrees(i+1, to);
                for(int j = 0; j < left.size(); j ++) {
                    for(int k = 0; k < right.size(); k ++) {
                        TreeNode *node = new TreeNode(i);
                        node->left = left[j];
                        node->right = right[k];
                        res.push_back(node);
                    }
                }
            }
        }
        return res;
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

    Solution s;
    vector<TreeNode*> res = s.generateTrees(3);
    
    for(int i = 0; i < res.size(); i ++) {
        printVector(treeToVector(res[i]));
    }
    return 0;
}

