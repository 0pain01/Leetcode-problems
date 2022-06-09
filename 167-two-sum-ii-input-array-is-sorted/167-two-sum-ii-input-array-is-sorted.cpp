class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int>res;
        
        int i=0,j=n-1;
        while(i<n-1 && i<j )
        {
            int x = target - numbers[i];
            if(numbers[j]==x)
            {
                res.push_back(i+1);
                res.push_back(j+1);
                break;
            }
            else if(numbers[j]>x)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        
        return res;
    }
};