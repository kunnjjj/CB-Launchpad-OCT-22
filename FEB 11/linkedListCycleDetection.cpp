// https://leetcode.com/problems/linked-list-cycle/description/
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
        ListNode* fast=head,*slow=head;
        // int *a,*b;

        while(fast!=NULL and fast->next!=NULL)
        {
            // if(fast==NULL or fast->next==NULL) break;
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast) return true; 
        }
        return false;
    }
};