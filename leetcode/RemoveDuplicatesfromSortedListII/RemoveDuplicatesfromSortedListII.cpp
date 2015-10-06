#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return 0;
        if (!head->next) return head;

        int val = head->val;
        ListNode* p = head->next;

        if (p->val != val) {
            head->next = deleteDuplicates(p);
            return head;
        } else {
            while (p && p->val == val) p = p->next;
            return deleteDuplicates(p);
        }
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *p1 = NULL;
        ListNode *p2 = head;
        while(p2 && ((p1 && p2->val == p1->val) || (p2->next && p2->next->val == p2->val))) {
            p1 = p2;
            p2 = p2->next;
        }
        ListNode *newHead = p2;
       
        if(!newHead || !newHead->next) return newHead;

        ListNode *p = newHead; 
        p1 = newHead;
        p2 = p1->next;

        while(p2) {
            while(p2 && ((p2->val == p1->val) || (p2->next && p2->next->val == p2->val))) {
                p1 = p2;
                p2 = p2->next;
            }
            p->next = p2;
            if(p2) {
                p = p->next;
                p1 = p2;
                p2 = p2->next;
            }
        }
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

    int arr1[] = {1,2,3};
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

