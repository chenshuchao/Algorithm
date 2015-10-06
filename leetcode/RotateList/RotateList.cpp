#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len = 1;
        ListNode *p = head;
        while(p->next) {
            p = p->next;
            len ++;
        }
        ListNode *tail = p;
        
        k = k % len;
        if(!k) return head;

        int index = len - k;
        p = head; 
        while(-- index) {
            p = p->next;
        }
        
        ListNode *newHead = p->next;
        p->next = NULL;
        tail->next = head;
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

    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    ListNode *n6 = new ListNode(6);
    ListNode *n7 = new ListNode(7);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    printList(n1);

    Solution s;
    //ListNode *newHead0 = s.rotateRight(n1, 0);
    ListNode *newHead1 = s.rotateRight(n1, 6);
/*
    ListNode *newHead2 = s.rotateRight(n1, 2);
    ListNode *newHead3 = s.rotateRight(n1, 3);
    ListNode *newHead4 = s.rotateRight(n1, 4);
    ListNode *newHead5 = s.rotateRight(n1, 5);
    ListNode *newHead6 = s.rotateRight(n1, 6);
    ListNode *newHead7 = s.rotateRight(n1, 7);
    ListNode *newHead8 = s.rotateRight(n1, 8);
*/
    //printList(newHead0);
    printList(newHead1);
/*
    printList(newHead2);
    printList(newHead3);
    printList(newHead4);
    printList(newHead5);
    printList(newHead6);
    printList(newHead7);
    printList(newHead8);
*/
    return 0;
}
