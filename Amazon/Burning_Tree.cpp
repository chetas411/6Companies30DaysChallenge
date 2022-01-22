class Solution {
  public:
    Node* mapParentNodesAndGetTarget(Node* root,int target, unordered_map<Node*,Node*> &mp ){
        queue<Node*> q;
        Node* targetNode = NULL;
        q.push(root);
        while(!q.empty()){
            Node *curr = q.front();
            q.pop();
            if(curr->data == target) targetNode = curr;
            if(curr->left){
                mp[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return targetNode;
    }
    int BFS(Node* root, unordered_map<Node*,Node*> mp){
        queue<Node*> q;
        unordered_set<Node*> s;
        q.push(root);
        s.insert(root);
        int count = 0;
        while(!q.empty()){
            int currSize = q.size();
            for(int i=0;i<currSize;i++){
                Node* curr = q.front();
                q.pop();
                if(mp.find(curr) != mp.end() && s.find(mp[curr]) == s.end()){
                    s.insert(mp[curr]);
                    q.push(mp[curr]);
                }
                if(curr->left && s.find(curr->left) == s.end()){
                    s.insert(curr->left);
                    q.push(curr->left);
                }
                if(curr->right  && s.find(curr->right) == s.end()){
                    s.insert(curr->right);
                    q.push(curr->right);
                }
            }
            ++count;
        }
        return count;
    }
    int minTime(Node* root, int target){
        // Your code goes here
        unordered_map<Node*,Node*> mp;
        Node* targetNode = mapParentNodesAndGetTarget(root,target,mp);
        return BFS(targetNode,mp)-1;
        
    }
};