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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        do {
            slow = slow->next;
            fast = fast->next->next;
        } while (fast != NULL && fast->next != NULL && fast != slow);
        if (fast != slow) return NULL;

        ListNode *p1 = head;
        ListNode *p2 = fast;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

