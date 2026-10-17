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
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        queue<Node*> q; 
        unordered_map<Node*, Node*> mapping; 
        mapping[node] = new Node(node->val); 
        q.push(node); 

        while(!q.empty()){
            auto x = q.front(); 
            q.pop(); 
            for(auto i : x->neighbors){
                if(mapping.find(i) == mapping.end()){
                    q.push(i);
                    mapping[i] = new Node(i->val);
                }
                mapping[x]->neighbors.push_back(mapping[i]); 
            }
        }
        return mapping[node]; 
    }
};