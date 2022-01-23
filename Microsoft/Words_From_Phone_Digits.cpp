class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<vector<char>> v = {
        {' '},
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}
    };
    void getWords(int i, int a[], int N, string curr, vector<string> &words){
        if(i == N) {
            words.push_back(curr);
            return;
        }
        for(auto c : v[a[i]-1]){
            getWords(i+1,a,N,curr+c,words);   
        }
        return;
    }
    vector<string> possibleWords(int a[], int N){
        //Your code here
        vector<string> words;
        string curr = "";
        getWords(0,a,N,curr,words);
        return words;
    }
};