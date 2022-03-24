class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        
        int i=0,j=n-1;
        int cnt=0;
        
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                cnt++;
                i++;
                j--;
            }
            else
            {
                if(people[i]>=limit)
                {
                    i++;
                    j--;
                    cnt+=2;
                }
                else
                {
                    cnt++;
                    j--;
                }
            }
        }
        
        return cnt;
    }
};