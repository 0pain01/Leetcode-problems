class Solution {
public:
    bool isValid(string s) {
        stack <int> st;
        int flag=0;
        
        for(int i=0;i<s.length();i++){ 
            if(s[i]=='(')
                st.push('(');
            if(s[i]=='{')
                st.push('{');
            if(s[i]=='[')
                st.push('[');
            if(st.empty() && (s[i]=='}' || s[i]==']' || s[i]==')'))
                return false;
            if(s[i]==')'){
                if(st.top()=='(')
                    st.pop();
                else
                    flag=1;
            }
            if(s[i]=='}'){
                if(st.top()=='{')
                    st.pop();
                else
                    flag=1;
            }
            if(s[i]==']'){
                if(st.top()=='[')
                    st.pop();
                else
                    flag=1;
            }
            
        }
        if(flag==1)
            return false;
        if(st.empty())
            return true;
        
        
            
        
    return false;
    }
};