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

    int countLength(ListNode* head) {
        int ans=0;
        while(head!=nullptr)
        {
            ans++;
            head=head->next;
        }
        return ans;
    }

    ListNode* reverseList(ListNode* node) {
        ListNode* prev=nullptr;
        while(node!=nullptr)
        {
            ListNode* temp=node->next;
            node->next=prev;
            prev=node;
            node=temp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        int n=countLength(head),x=n/2,t=1;
        if(n%2==1)
            x++;
        ListNode* node=head;
        while(t<x)
        {
            t++;
            node=node->next;
        }
        node=reverseList(node);
        while(head!=nullptr) {
            ListNode* temp=head->next;
            head->next=node;
            head=temp;

            if(node!=nullptr)
            {
                temp=node->next;
                node->next=head;
                node=temp;
            }
        }
    }
};
