/*
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* findNthNode(ListNode* temp, int k){
            int count = 1;
            while(temp != NULL){
                if(count == k) return temp;
                count++;
                temp = temp->next;
            }
            return temp;
        }

    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || k==0 ) return head;

        int length =1;
        ListNode* tail = head;

        while(tail->next != NULL){
            length++;
            tail = tail->next;
        }
        if(k % length == 0) return head;

        k = k%length;
        tail->next = head;

        ListNode* newLastNode = findNthNode(head, length-k);
        head = newLastNode->next;
        newLastNode-> next = NULL;
        return head;
    }
    
};
