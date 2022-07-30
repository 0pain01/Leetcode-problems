class Solution {
public:
    static int count1(int n)
    {
        int cnt=0;
        while (n) 
        {
            cnt += n & 1;
            n >>= 1;
        }
        return cnt;
    }
    
    static bool solver(int &a,int &b)
    {
        int countA = count1(a);
        int countB = count1(b);
        return countA==countB ? a<b:countA<countB;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),solver);
        return arr;
    }
};