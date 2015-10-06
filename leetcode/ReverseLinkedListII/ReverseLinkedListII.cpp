#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *head_prev = new ListNode(0);
        head_prev->next = head;

        ListNode *left = head_prev;
        for(int i = 0; i < m-1; i ++)
            left = left->next;
        ListNode *pm = left->next;
        if(!pm) return head;
        
        ListNode *p2 = pm;
        ListNode *p2_prev = NULL;
        ListNode *p2_next = p2->next;
        for(int i = m; i < n; i ++) {
            p2_prev = p2;
            p2 = p2_next;
            p2_next = p2->next;

            p2->next = p2_prev;
        }
        left->next = p2;
        pm->next = p2_next;
        return head_prev->next;
    }
};

void printList(ListNode *head) {
    ListNode *p = head;
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}
int main() {

    int arr1[] = {1,2,3,4,5};
    int len = sizeof(arr1)/sizeof(int);
    ListNode *head = len > 0 ? new ListNode(arr1[0]) : NULL;
    ListNode *p = head;
    for(int i = 1; i < len; i++) {
        ListNode *t = new ListNode(arr1[i]);
        p->next = t;
        p = p->next;
    }
    printList(head);

    Solution s;
    ListNode *newHead = s.reverseBetween(head, 5, 5);

    printList(newHead);
    
    return 0;
}

