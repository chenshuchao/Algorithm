#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* pos1 = l1;
        ListNode* pos1_pre;
        ListNode* pos2 = l2;
        ListNode* pos2_pre;
        ListNode* head;
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val <= l2->val) head = l1;
        else head = l2;

        while(pos1 && pos2) {
            if(pos2->val >= pos1->val) {
                while(pos1 && pos2->val >= pos1->val) {
                    pos1_pre = pos1;
                    pos1 = pos1->next;
                }
                pos1_pre->next = pos2;
            } else {
                while(pos2 && pos1->val >= pos2->val){
                    pos2_pre = pos2;
                    pos2 = pos2->next;
                }
                pos2_pre->next = pos1;
            }
        }
        if(!pos1) pos1_pre->next = pos2;
        if(!pos2) pos2_pre->next = pos1;
        return head;
    }
    ListNode *doMerge(vector<ListNode*>& lists, int left, int right) {
        if(left == right) {
            return lists[left];
        } else if(left + 1 == right) {
            return mergeTwoLists(lists[left], lists[right]);
        } else {
            ListNode *p1 = doMerge(lists, left, (left + right) / 2);
            ListNode *p2 = doMerge(lists, (left + right) / 2 + 1, right);
            return mergeTwoLists(p1, p2);
        } 
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(size <= 0) return NULL;
        if(size == 1) return lists[0];

        return doMerge(lists, 0, size - 1);
    }
};

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

void printList(ListNode *p) {
    int a = 1;
    while(p) {
        cout << p << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int A1[] = {0,1,2};
    int A2[] = {-10,-8,-5,-4};
    int A3[] = {-3};
    int A4[] = {-10,-9,-6,-4,-3,-2,-2,-1,2};
    int A5[] = {-9,-9,-2,-1,0,1};
    int A6[] = {-9,-4,-3,-2,2,2,3,3,4};
    ListNode *p1 = createList(A1, 3);
    ListNode *p2 = createList(A2, 4);
    ListNode *p3 = NULL;
    ListNode *p5 = createList(A3, 1);
    ListNode *p4 = NULL;
    ListNode *p6 = createList(A4, 9);
    ListNode *p7 = createList(A5, 6);
    ListNode *p8 = createList(A6, 9);
    /*
    printList(p1);
    printList(p2);
    printList(p3);
    printList(p4);
    printList(p5);
    printList(p6);
    printList(p7);
    printList(p8);
    */
    //printList(p3);
    vector<ListNode*> lists;
    lists.push_back(p1);
    lists.push_back(p2);
    lists.push_back(p3);
    lists.push_back(p4);
    lists.push_back(p5);
    lists.push_back(p6);
    lists.push_back(p7);
    lists.push_back(p8);

    Solution s;
    vector<ListNode*> v;
    v.push_back(p4);
    ListNode *p = s.mergeKLists(lists);
    
    printList(p);
    
    return 0;
}
