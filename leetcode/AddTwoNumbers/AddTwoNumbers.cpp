// https://oj.leetcode.com/problems/add-two-numbers/
// You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

// #include<iostream>
// using namespace std;

// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0, num2 = 0, sum = 0;
    ListNode *l3 = l1;
    ListNode *preL1;
    while(l2 != NULL || carry){
      num2 = 0;
      sum = 0;
      if(!l1){
        ListNode *ln = new ListNode(0);
        l1 = ln;
        preL1->next = ln;
      }
      if(l2 != NULL) num2 = l2->val;
      sum = l1->val + num2 + carry;
      carry = sum/10;
      l1->val = sum % 10;
      preL1 = l1;
      l1 = l1->next;
      if(l2 != NULL) l2 = l2->next;
    }
    return l3;
  }
};

// int main(){
//   Solution s;
//   ListNode ln1(5),ln2(4),ln3(9),ln4(6),ln5(0),ln6(7);
//   ListNode *l1 = &ln1,*l2 = &ln2,*l3 = &ln3,*l4 = &ln4,*l5 = &ln5,*l6 = &ln6;
//   l1->next = l2;
//   l2->next = l3;
//   l4->next = l5;
//   l5->next = l6;
//   ListNode *l7 = s.addTwoNumbers(l1,l4);
//   while(l7 != NULL){
//     cout << l7->val <<"->";
//     l7 = l7->next; 
//   }
//   return 0;
// }