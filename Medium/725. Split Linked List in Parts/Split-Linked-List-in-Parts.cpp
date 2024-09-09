/*
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

 

Example 1:


Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].
Example 2:


Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
 
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans; // To store the answer
        
        // Finding size of the LL
        int size=0; 
        ListNode* temp=head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }

        // Size of equal splits
         int splits= size/k;

         // size of additional nodes added to distributed evenly from the starting

         int remsplits=size%k;

         temp=head;
         ListNode * prev=temp;

         for(int i=0;i<k;i++){
            // Creating splits
            ListNode * newHead = temp;
            int currSize=splits;
            if(remsplits>0){
                remsplits--;
                currSize++;
            }
            
            // Traversal to the end of each part
            int j=0;
            while(j<currSize){
                prev=temp;
                if(temp!=NULL){
                    temp=temp->next;
                }
                j++;
            }

            // cutting the each part 

            if(prev!=NULL){
                prev->next=NULL;
            }
            
            ans.push_back(newHead);
         }

        return ans;
    }
};
