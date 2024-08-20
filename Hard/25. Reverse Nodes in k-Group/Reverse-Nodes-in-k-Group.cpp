/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 
*/

class Solution {
public:
    ListNode* reverse(ListNode *head) {
        ListNode* temp = head;  
        ListNode* prev = NULL;  
        while(temp != NULL) {  
            ListNode* front = temp->next;  
            temp->next = prev;  
            prev = temp;    
            temp = front; 
        }
        return prev;  
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;
        while(temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while(temp != NULL) {
            ListNode* KthNode = getKthNode(temp, k);

            if(KthNode == NULL) {
                if (prevNode != NULL) {
                    prevNode->next = temp;
                }
                break;
            }

            ListNode* nextNode = KthNode->next;
            KthNode->next =  NULL;
            ListNode* reversedHead = reverse(temp);

            if(temp == head) {
                head = reversedHead;
            } else {
                prevNode->next = reversedHead;
            }

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
