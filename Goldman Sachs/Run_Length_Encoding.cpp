string encode(string src){     
  //Your code here 
  char c = src[0];
  int count = 1;
  string ans = "";
  for(int i=1;i<src.size();i++){
      char a = src[i];
      if(a == c){
          ++count;
      }else{
          ans.push_back(c);
          ans += to_string(count);
          c = a;
          count = 1;
      }
  }
   ans.push_back(c);
   ans += to_string(count);
   return ans;
}  