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
    ListNode* findNthNode(ListNode* node,int n) {
        int count=1;
        while(count<n)
        {
            node=node->next;
            count++;
        }
        return node;
    }
    int findSize(ListNode* head)
    {
        int count=0;
        while(head)
        {
            head=head->next;
            count++;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N=findSize(head);
        n=N-(n-1);
        ListNode* Nth=findNthNode(head,n);
        if(head==Nth)
            return head->next;
        ListNode* temp=head;
        while(1)
        {
            if(head->next==Nth)
            {
                head->next=Nth->next;
                break;
            }
            head=head->next;
        }
        return temp;
    }
};
