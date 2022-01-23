//Function to count number of subtrees having sum equal to given sum.
pair<int,int> countSubtreesHelper(Node* root, int X){
    if(!root) return {0,0};
    pair<int,int> leftT, rightT;
    leftT = countSubtreesHelper(root->left, X);
    rightT = countSubtreesHelper(root->right, X);
    int count = leftT.first + rightT.first;
    if(root->data + leftT.second + rightT.second == X) ++count;
    return {count,root->data + leftT.second + rightT.second};
}
int countSubtreesWithSumX(Node* root, int X){
	// Code here
	return countSubtreesHelper(root,X).first;
}