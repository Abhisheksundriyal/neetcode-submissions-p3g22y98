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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=nullptr;
        ListNode* node=nullptr;
        while(list1!=nullptr || list2!=nullptr) {
            ListNode* temp=nullptr;
            if(list1!=nullptr && list2!=nullptr)
            {
                if(list1->val<=list2->val)
                {
                    temp=list1;
                    list1=list1->next;
                }
                else
                {
                    temp=list2;
                    list2=list2->next;
                }
            }
            else if(list1!=nullptr)
            {
                temp=list1;
                list1=list1->next;
            }
            else
            {
                temp=list2;
                list2=list2->next;
            }
            if(head==nullptr)
                head=temp;
            if(node==nullptr)
                node=temp;
            else
            {
                node->next=temp;
                node=temp;
            }
        }
        return head;
    }
};
