class Solution{
public:
    string decodedString(string s){
        // code here
        stack<char> st;
        string ans = "";
        for(auto c : s){
            if(c == ']'){
                string r = "";
                char a = '#';
                while(a != '['){
                    a = st.top();
                    st.pop();
                    if(a != '[') r.push_back(a);
                }
                reverse(r.begin(),r.end());
                string num = "";
                while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
                    a = st.top();
                    st.pop();
                    num.push_back(a);
                }
                reverse(num.begin(),num.end());
                int count = stoi(num);
                while(count--){
                    for(auto x : r){
                        st.push(x);
                    }
                }
            }
            else{
                st.push(c);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};