class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        for(int i=0;i<9;i++){
            unordered_set<int> s;
            for(int j=0;j<9;j++){
                if(mat[i][j] == 0) continue;
                if(s.find(mat[i][j]) != s.end()){
                    return 0;
                }
                s.insert(mat[i][j]);
            }
        }
        for(int i=0;i<9;i++){
            unordered_set<int> s;
            for(int j=0;j<9;j++){
                if(mat[j][i] == 0) continue;
                if(s.find(mat[j][i]) != s.end()){
                    return 0;
                }
                s.insert(mat[j][i]);
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                unordered_set<int> s;
                for(int p=0;p<3;p++){
                    for(int q=0;q<3;q++){
                        if(mat[i+p][j+q] == 0) continue;
                        if(s.find(mat[i+p][j+q]) != s.end()){
                            return 0;
                        }
                        s.insert(mat[i+p][j+q]);
                    }
                }
            }
        }
        return 1;
    }
};