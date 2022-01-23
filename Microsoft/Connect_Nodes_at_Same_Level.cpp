class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root){
       // Your Code Here
       queue<Node*> q;
       q.push(root);
       while(!q.empty()){
           int currSize = q.size();
           for(int i=0;i<currSize;i++){
               Node* curr = q.front();
               q.pop();
               if(i != currSize - 1){
                   curr->nextRight = q.front();
               }
               if(curr->left) q.push(curr->left);
               if(curr->right) q.push(curr->right);
           }
       }
    }    
      
};