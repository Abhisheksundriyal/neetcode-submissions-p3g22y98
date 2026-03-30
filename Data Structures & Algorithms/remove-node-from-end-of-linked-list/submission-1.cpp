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

    int findSize(ListNode* head) {
        int count=0;
        while(head!=nullptr)
        {
            count++;
            head=head->next;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=findSize(head),N=sz-n+1,curr=1;
        if(n==sz)
            return head->next;
        ListNode* node=head;
        while(node!=nullptr)
        {
            if(curr==N-1)
            {
                node->next=node->next->next;
                break;
            }
            node=node->next;
            curr++;
        }
        return head;

    }
};
