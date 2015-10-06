#include <iostream>
#include <queue>
#include <stack>
using namespace std;

const int NULL_NODE = -100;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        vector<int> nums;

        ListNode *p = head;
        while(p) {
            nums.push_back(p->val);
            p = p->next;
        }
        return sortedArrayToBST(nums);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        if(!size) return NULL;
        return sortedArrayToBST(nums, 0, size-1);
    }
    TreeNode* sortedArrayToBST(vector<int>&nums, int left, int right) {
        TreeNode *proot = NULL;
        if(left <= right) {
            int mid = (left + right) / 2;
            proot = new TreeNode(nums[mid]);
            proot->left = sortedArrayToBST(nums, left, mid-1);
            proot->right = sortedArrayToBST(nums, mid+1, right);
        }
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
ListNode* createList(int arr[], int n) {
    if(n <= 0) return NULL;
    ListNode *head = new ListNode(arr[0]);
    ListNode *index = head;
    for(int i = 1; i < n; ++i) {
        ListNode *pt = new ListNode(arr[i]);
        index->next = pt;
        index = index->next; 
    }
    return head;
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

    int arr1[] = {1, 2, 3, 4, 5};
    ListNode *head = createList(arr1, 5);
    Solution s;
    TreeNode *root = s.sortedListToBST(head);

    vector<int> tree = printTree(root);
    printV(tree);
    
    return 0;
}

