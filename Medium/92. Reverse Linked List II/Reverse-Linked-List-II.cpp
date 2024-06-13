/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
*/

class Solution {
public:
    ListNode* suc = NULL;
    ListNode* recurN(ListNode* head, int n)
    {
        if(n == 1)
        {
            suc = head->next;
            return head;
        }
        
        ListNode* last = recurN(head->next, n-1);
        head->next->next = head;
        head->next = suc;
        return last;
    }
    
    ListNode* recurBtw(ListNode* head, int m, int n)
    {
        if(m == 1) return recurN(head, n);
        head->next = recurBtw(head->next, m-1, n-1);
        return head;
    }
    

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        return recurBtw(head, left, right);
        
    }
};
