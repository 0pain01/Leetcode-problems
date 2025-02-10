class Solution {
public:
    bool isPalindrome(int i, int j, string &s){
        while(i<=j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }

    void solver(int idx, string &s, vector<string>&arr,vector<vector<string>>&ans){
        if(idx==s.size()){
            ans.push_back(arr);
            return;
        }

        for(int i=idx;i<s.size();i++){
            if(isPalindrome(idx,i,s)){
                arr.push_back(s.substr(idx,i-idx+1));
                solver(i+1,s,arr,ans);
                arr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>arr;
        vector<vector<string>>ans;
        solver(0,s,arr,ans);
        return ans;
    }
};