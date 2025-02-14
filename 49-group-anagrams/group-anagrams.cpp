class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) { 
        map<string,vector<string>>mp1;
        for(int i=0;i<strs.size();i++){
            map<int,int>mp2;
            for(auto j:strs[i]){
                mp2[j]++;
            }
            string temp;
            for(auto it:mp2)
            {
                temp+=(to_string(it.first)+to_string(it.second));
            }
            mp1[temp].push_back(strs[i]);
            
        }

        vector<vector<string>>ans;
        for(auto it:mp1){
            vector<string>arr;
            for(auto i:it.second){
                arr.push_back(i);
            }
            ans.push_back(arr);
        }
        return ans;
    }
};