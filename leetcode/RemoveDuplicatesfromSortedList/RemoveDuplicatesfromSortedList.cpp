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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *p1 = head;
        ListNode *p2;
        while(p1) {
            p2 = p1->next;
            while(p2 && p2->val == p1->val) p2 = p2->next;
            p1->next = p2;
            p1 = p2;
        }
        return head;
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

    int arr1[] = {1, 2, 2, 3, 3};
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
    ListNode *newHead = s.deleteDuplicates(head);

    printList(newHead);
    
    return 0;
}

