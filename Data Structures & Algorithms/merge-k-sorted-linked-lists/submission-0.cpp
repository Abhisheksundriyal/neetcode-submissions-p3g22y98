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

    ListNode* returnSmall(vector<ListNode*>& lists){
        int n=lists.size();
        ListNode* node=nullptr;
        for(int i=0;i<n;i++)
        {
            if(lists[i]!=nullptr)
            {
                if(node==nullptr || ((lists[i]->val) < (node->val)))
                    node=lists[i];
            }
        }
        if(node==nullptr)
            return node;
        for(int i=0;i<n;i++)
        {
            if(lists[i]==node)
            {
                lists[i]=lists[i]->next;
                break;
            }
        }
        return node;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* node=nullptr;
        ListNode* curr=node;
        ListNode* smallNode=returnSmall(lists);
        while(smallNode!=nullptr)
        {
            if(node==nullptr)
                node=smallNode;
            if(curr==nullptr)
                curr=smallNode;
            else
            {
                curr->next=smallNode;
                curr=curr->next;
            }
            smallNode=returnSmall(lists);
        }
        return node;
    }
};
