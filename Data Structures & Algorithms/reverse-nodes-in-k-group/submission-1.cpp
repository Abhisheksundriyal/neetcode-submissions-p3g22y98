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

    ListNode* findKth(ListNode* node,int k) {
        while(node && k)
        {
            node=node->next;
            k--;
        }
        return node;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0,head);
        ListNode* groupPrev=dummy;
        while(1)
        {
            ListNode* Kth = findKth(groupPrev,k);
            if(!Kth)
                break;
            ListNode* groupNext = Kth->next;
            
            ListNode* prev = Kth->next;
            ListNode* curr = groupPrev->next;
            while(curr!=groupNext)
            {
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            ListNode* temp = groupPrev->next;
            groupPrev->next = Kth;
            groupPrev=temp;
        }
        return dummy->next;
    }
};
