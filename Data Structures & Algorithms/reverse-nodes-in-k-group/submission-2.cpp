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
    ListNode* findKth(ListNode* head,int k) {
        while(head && k) {
            head=head->next;
            k--;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* groupPrev=dummy;
        while(1) {
            ListNode* Kth=findKth(groupPrev,k);
            if(!Kth)
                break;
            ListNode* groupNext=Kth->next;
            ListNode* prev=groupNext;
            ListNode* curr=groupPrev->next;
            while(curr!=groupNext) {
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            ListNode* temp=groupPrev->next;
            groupPrev->next=Kth;
            groupPrev=temp;
        }
        return dummy->next;
    }
};
