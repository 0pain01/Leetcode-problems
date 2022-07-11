class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string,int>mp;
        map<string,bool>mp1;
        for(int i=0;i<paragraph.size();i++)
        {
            if(paragraph[i]==','||paragraph[i]=='.'||paragraph[i]=='?'||paragraph[i]=='!'||paragraph[i]==';'||paragraph[i]=='\'')
                paragraph[i]=' ';
        }
        
        for(int i=0;i<banned.size();i++)
        {
            mp1[banned[i]]=true;
        }
        transform(paragraph.begin(),paragraph.end(),paragraph.begin(),::tolower);
        stringstream ss(paragraph);
        string w;
        
        while(ss>>w)
        {
            //cout<<w<<" ";
            if(!mp1[w])
                mp[w]++;
        }

        
        int mx=INT_MIN;string word="";
        
        for(auto x:mp)
        {
            cout<<x.first<<" "<<x.second<<endl;
            if(x.second>mx)
            {
                mx=x.second;
                word=x.first;
            }
        }
        
        return word;
    }
};