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
    ListNode* smallestNode(vector<ListNode*>& lists) {
        int small=INT_MAX;
        ListNode* temp=nullptr;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i] && lists[i]->val<small)
                small=lists[i]->val;
        }
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i] && lists[i]->val==small)
            {
                temp=lists[i];
                lists[i]=lists[i]->next;
                break;
            }   
        }
        return temp;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=nullptr;
        ListNode* tail=nullptr;
        while(1) {
            ListNode* temp=smallestNode(lists);
            if(!temp){
                if(head)
                    tail->next=nullptr;
                break;
            }
            if(!head){
                head=temp;
                tail=temp;
            } else
            {
                tail->next=temp;
                tail=temp;
            }
        }
        return head;
    }
};
