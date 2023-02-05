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
    int get_len(ListNode* head)
    {
        if(head==NULL) return 0;
        return 1 + get_len(head->next);
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_A=get_len(headA);
        int len_B=get_len(headB);

        if(len_A > len_B)
        {
            for(int i=1;i<=len_A-len_B;i++)
            {
                headA=headA->next;
            }
        } 
        else
        {
            for(int i=1;i<=len_B-len_A;i++)
            {
                headB=headB->next;
            }
        }
        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;

    }
};

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA,*tempB=headB;
        while(headA!=NULL && headB!=NULL)
        {
            headA=headA->next;
            headB=headB->next;   
        }
        if(headA==NULL)
        {
            while(headB!=NULL)
            {
                headB=headB->next;
                tempB=tempB->next;
            }
        }
        else if(headB==NULL)
        {
           while(headA!=NULL)
            {
                headA=headA->next;
                tempA=tempA->next;
            } 
        }
        while(tempA!=tempB)
        {
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
    }
};