// https://leetcode.com/problems/linked-list-cycle-ii/description/
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        while(fast!=NULL and fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
            {
                break;
            }
        }
        if(fast==NULL or fast->next==NULL) return NULL;
        slow=head;
        // below is code if cycle break karna is our goal
        // while(slow->next!=fast->next)
        // {
        //     slow=slow->next;
        //     fast=fast->next;
        // }
        // // agar cycle break fast->next=NULL

        while(fast!=slow)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};