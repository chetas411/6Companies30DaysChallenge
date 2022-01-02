class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        int n = min(s1.length(),s2.length());
        int n1 = s1.length(), n2 = s2.length();
        for(int i = n; i>=1; i--){
            if(n1%i == 0 && n2%i == 0){
                int a = 0, b = 0;
                string c1,c2;
                bool flag = true;
                while(a < n1 && b < n2){
                    c1 = s1.substr(a,i);
                    c2 = s2.substr(b,i);
                    if(c1 == c2){
                        a += i;
                        b += i;
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                while(a < n1 && flag){
                    c1 = s1.substr(a,i);
                    if(c1 == c2){
                        a += i;
                    }else{
                        flag = false;
                        break;
                    }
                }
                while(b < n2 && flag){
                    c2 = s2.substr(b,i);
                    if(c1 == c2){
                        b += i;
                    }else{
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    return c1;
                }
            }
        }
        return "";
    }
};