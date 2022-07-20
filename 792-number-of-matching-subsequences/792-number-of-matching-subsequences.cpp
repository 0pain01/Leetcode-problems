class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> alpha (26);
        
		for (int i = 0; i < s.size (); ++i) 
            alpha[s[i] - 'a'].push_back (i);
        
		int res = 0;

		for (const auto& word : words) 
        {
			int x = -1;
			bool found = true;

			for (char c : word) 
            {
                // it provides the iterator which have value greater than x in the vector
				auto it = upper_bound (alpha[c - 'a'].begin (), alpha[c - 'a'].end (), x);
                
                //if that iterator is equal to the end then it means there is not such value and hence not found
				if (it == alpha[c - 'a'].end ()) found = false;
                
                //if it found that value then it will store the position of it
				else x = *it;
			}

			if (found) 
                res++;
		}

		return res;
    }
};