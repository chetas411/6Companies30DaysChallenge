Class Solution{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here   
        Node *curr = head;
        int count = 1;
        while(curr){
            if(count < M){
                curr = curr->next;
                ++count;
            }
            else{
                Node* nextStart = curr;
                count = 1;
                while(nextStart && count <= N){
                    nextStart = nextStart->next;
                    ++count;
                }
                if(!nextStart){
                    curr->next = NULL;
                    curr = NULL;
                }
                else{
                    curr->next = nextStart->next;
                    curr = nextStart->next;
                }
                count = 1;
            }
        }
    }
};