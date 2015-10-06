#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(int arr[], int n) {
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
            cout << p->val << " ";
            p = p->next;
        }   
    cout << endl;
}

class Solution {
public:
    void swapNodeVal(ListNode *p1, ListNode *p2) {
        int t = p1->val;
        p1->val = p2->val;
        p2->val = t;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head ==  NULL || head->next == NULL) return head;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        do {
            swapNodeVal(p1, p2);
            p1 = p2->next;
            if(p1) {
                p2 = p1->next;
            }
        } while(p1 && p2);
        return head;
    }
};

int main() {
    int A1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode *p1 = createList(A1, 8);

    Solution s;
    ListNode *p = s.swapPairs(p1);
    printList(p);
    
    return 0;
}

