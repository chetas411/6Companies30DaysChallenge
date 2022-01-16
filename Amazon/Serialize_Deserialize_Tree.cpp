class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        //Your code here
        if(!root) return {-1};
        vector<int> completeTree = {root->data};
        vector<int> leftSubTree = serialize(root->left);
        vector<int> rightSubTree = serialize(root->right);
        for(auto x : leftSubTree){
            completeTree.push_back(x);
        }
        for(auto x : rightSubTree){
            completeTree.push_back(x);
        }
        return completeTree;
    }
    
    int i = 0;
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A){
       //Your code here
       if(i > A.size() || A.size() == 0 || A[i] == -1) return NULL;
       Node *root = new Node(A[i]);
       ++i;
       Node *leftChild = deSerialize(A);
       ++i;
       Node *rightChild = deSerialize(A);
       root->left = leftChild;
       root->right = rightChild;
       return root;
       
       
    }
};