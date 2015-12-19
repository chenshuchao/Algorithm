#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> dict;
        RandomListNode* newHead = helper(head, dict);
        return newHead;
    }
    RandomListNode* helper(RandomListNode *node, unordered_map<RandomListNode*, RandomListNode*>& dict) {
        if (node == NULL) return NULL;
        if (dict[node] != NULL) return dict[node];
        
        RandomListNode* newNode = new RandomListNode(node->label);
        dict[node] = newNode;
        RandomListNode* nextNode = helper(node->next, dict);
        RandomListNode* randomNode = helper(node->random, dict);
        newNode->next = nextNode;
        newNode->random = randomNode;

        return newNode;
    }
};

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

    int arr1[] = {};
    vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(int));

    Solution s;
    
    return 0;
}

