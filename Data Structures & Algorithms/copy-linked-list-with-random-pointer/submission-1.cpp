/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* recur(Node* node,unordered_map<Node*,Node*>& myMap) {
        if(node==nullptr)
            return myMap[node]=nullptr;
        if(myMap.find(node)!=myMap.end())
            return myMap[node];
        Node* temp = new Node(node->val);
        myMap[node]=temp;
        temp->next=recur(node->next,myMap);
        temp->random=recur(node->random,myMap);
        return temp;
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> myMap;
        return recur(head,myMap);
    }
};
