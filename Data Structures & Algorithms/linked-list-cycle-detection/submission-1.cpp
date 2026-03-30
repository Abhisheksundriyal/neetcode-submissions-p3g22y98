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
    unordered_set<ListNode*> mySet;
    bool hasCycle(ListNode* head) {
        if(head!=nullptr)
        {
            if(mySet.find(head)==mySet.end())
            {
                mySet.insert(head);
                return hasCycle(head->next);
            }
            else
                return true;
        }
        return false;
    }
};
