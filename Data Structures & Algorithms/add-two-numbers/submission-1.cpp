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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* head=nullptr;
        ListNode* tail=nullptr;
        while(l1 || l2){
            int num=carry;
            if(l1){
                num+=l1->val;
                l1=l1->next;
            }
            if(l2){
                num+=l2->val;
                l2=l2->next;
            }
            ListNode* temp = new ListNode(num%10);
            carry=num/10;
            if(!head)
                head=temp;
            else
                tail->next=temp;
            tail=temp;
        }
        if(carry!=0)
        {
            ListNode* temp = new ListNode(carry);
            if(!head)
                head=temp;
            else
                tail->next=temp;
            tail=temp;
        }
        return head;
    }
};
