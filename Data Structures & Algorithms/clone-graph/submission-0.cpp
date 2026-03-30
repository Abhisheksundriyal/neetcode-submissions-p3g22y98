/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    unordered_map<Node*,Node*> myMap;

    Node* cloneGraph(Node* node) {
        if(node==nullptr)
            return nullptr;
        Node* newNode = new Node(node->val);
        myMap[node]=newNode;
        int n=node->neighbors.size();
        for(int i=0;i<n;i++)
        {
            Node* nextNode=node->neighbors[i];
            if(myMap.find(node->neighbors[i])==myMap.end())
                myMap[node->neighbors[i]]=cloneGraph(node->neighbors[i]);
            newNode->neighbors.push_back(myMap[node->neighbors[i]]);
        }
        return newNode;
    }
};
