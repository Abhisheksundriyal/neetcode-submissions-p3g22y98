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

    Node* recur(Node* node,unordered_map<Node*,Node*>& myMap)
    {
        Node* newNode=new Node(node->val);
        myMap[node]=newNode;
        if(node->next!=NULL)
        {
            if(myMap[node->next]==NULL)
                myMap[node->next]=recur(node->next,myMap);
            newNode->next=myMap[node->next];
        }
        if(node->random!=NULL)
        {
            if(myMap[node->random]==NULL)
                myMap[node->random]=recur(node->random,myMap);
            newNode->random=myMap[node->random];
        }
        return newNode;
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> myMap;
        if(head==NULL)
            return NULL;
        return recur(head,myMap);
    }
};
