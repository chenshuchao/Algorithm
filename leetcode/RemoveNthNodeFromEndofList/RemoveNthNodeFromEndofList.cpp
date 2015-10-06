#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

    public:
    ListNode* removeNthFromBegin(ListNode* head,int n) {
        ListNode* pNode = head;
        if(n==1) {
            head = head->next;
            delete pNode;
            return head;
        }
        for(int i = 1; i < n - 1; i++) {
            pNode = pNode->next;
        }
        ListNode* r = pNode->next;
        pNode->next = r->next;
        delete r;
        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n < 1) return NULL;
        int len = lenList(head);
        removeNthFromBegin(head,len-n+1);
    }
    
    ListNode* buildList(int A[],int n){
        if(n < 1) return NULL;
        ListNode* head = new ListNode(A[0]);
        ListNode* pNode = head;
        for(int i = 1; i < n; i++) {
            pNode->next = new ListNode(A[i]);
            cout << "pNode->next:" << pNode->next << " ";
            pNode = pNode->next;
            cout << pNode << endl;
        }
        return head;
    }
    
    int lenList(ListNode *head) {
        ListNode *pNode = head;
        int count = 0;
        while(pNode){
            pNode = pNode->next;
            count ++; 
        }
        return count;
    } 

    void printList(ListNode* head){
        ListNode* pNode = head;
        while(pNode){
            cout << pNode->val << endl;
            pNode = pNode->next;
        }
    }

};

int main() {
    Solution s;
    int A[] = {1,2,3,4,5,6};
    ListNode* head = s.buildList(A,6);
    s.printList(head);
    head = s.removeNthFromEnd(head,6);
    s.printList(head);
    return 0;
}
