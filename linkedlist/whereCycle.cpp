/*question: determine where the loop starts
  author:peixuan zhong
  date:13/05/2021
  key idea:use fast and slow pointer check if they meet to determine if there is a loop
  if there is, after they meet, let slow point to head and ask slow and fast move one node forward 
  eact time when they meet again return the node. The reason can be shown by drawing a graph and indicating
  that fast distance = 2 slow distance.

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
    ListNode *detectCycle(ListNode *head){
        if (head==NULL||head->next==NULL)return NULL; 
        ListNode *fast = head;
        ListNode *slow = head;
        fast = head->next->next;
        slow=head->next;
        int flag = 0;
        while (true){
            if (fast==NULL || fast->next==NULL ||slow==NULL){
                return NULL;
            }
            
            if (fast == slow){
                if (flag==0){
                    slow=head;
                    flag =1;
                    continue;
                }else{
                    return slow;
                }
            }
            if(flag==0){
                slow=slow->next;
                fast=fast->next->next;
            }else{
                slow=slow->next;
                fast=fast->next;
            }
            
        }
    }
};