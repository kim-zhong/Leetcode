/*question:determine if there is a loop in linkedlist
  author:peixuan zhong
  date:13/05/2021
  key idea: use fast and slow pointer and check if they meet
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
    
public:
    bool hasCycle(ListNode *head) {
        if (head==NULL) return false;
        ListNode *small = head;  
        ListNode *large = head->next;
        
        while(small!=large){
            if (large ==NULL || large->next==NULL){
                return false;
            }
            if (small == NULL){
                return false;
            
            }
            small = small->next;
            
            large = large->next->next;
        
        }
        return true;
        
    }
};