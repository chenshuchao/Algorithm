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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode *head_prev = new ListNode(x-1);
        head_prev->next = head;
        ListNode *p1 = head_prev;
        while(p1->next && p1->next->val < x) p1 = p1->next;

        ListNode *p2_prev = p1;
        ListNode *p2 = p2_prev->next;
        while(p2) {
            while(p2 && p2->val >= x) {
                p2_prev = p2;
                p2 = p2->next;
            }
            if(!p2) break;
            
            ListNode *p3 = p2;
            while(p3->next && p3->next->val < x) p3 = p3->next;
            
            ListNode *p1_next = p1->next;
            ListNode *p3_next = p3->next;
            p1->next = p2;
            p3->next = p1_next;
            p2_prev->next = p3_next;
            p1 = p3;
            p2 = p3_next;
        }
        
        ListNode *newHead = head_prev->next;
        delete head_prev;
        return newHead;
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

    int arr1[] = {1,3,-1,5,2,1};
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
    ListNode *newHead = s.partition(head, 3);

    printList(newHead);
    
    return 0;
}

