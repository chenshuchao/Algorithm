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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        int count = 0;
        ListNode *cur = head;
        while(cur != NULL && count != k) {
            cur = cur->next;
            count ++;
        }
        if(count == k) {
            cur = reverseKGroup(cur, k);
            while(count -- > 0) {
                ListNode *tmp = head->next;
                head->next = cur;
                cur = head;
                head = tmp;
            }
            head = cur;
        }
        return head;    
    }
};

int main() {
    int A1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode *p1 = createList(A1, 8);

    Solution s;
    printList(p1);

    ListNode *p = s.reverseKGroup(p1, 3);
    printList(p);
    
    return 0;
}

