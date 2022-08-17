class Solution {
public:
    unordered_map<char,string> mp;
    int uniqueMorseRepresentations(vector<string>& words) {
        mp['a']=".-";
        mp['b']="-...";
        mp['c']="-.-.";
        mp['d']="-..";
        mp['e']=".";
        mp['f']="..-.";
        mp['g']="--.";
        mp['h']="....";
        mp['i']="..";
        mp['j']=".---";
        mp['k']="-.-";
        mp['l']=".-..";
        mp['m']="--";
        mp['n']="-.";
        mp['o']="---";
        mp['p']=".--.";
        mp['q']="--.-";
        mp['r']=".-.";
        mp['s']="...";
        mp['t']="-";
        mp['u']="..-";
        mp['v']="...-";
        mp['w']=".--";
        mp['x']="-..-";
        mp['y']="-.--";
        mp['z']="--..";
        
        set<string>st;
        for(int i=0;i<words.size();i++)
        {
            string str="";
            for(int j=0;j<words[i].size();j++)
            {
                str+=mp[words[i][j]];
            }
            st.insert(str);
        }
        
        return st.size();
    }
};