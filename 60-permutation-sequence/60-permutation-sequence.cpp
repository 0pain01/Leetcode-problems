class Solution {
public:
    int perm(int n)
    {
        if(n==0)
            return 1;
        
        return n * perm(n-1);
    }
    string getPermutation(int n, int k) {
        int f = perm(n-1);
        
        vector<int>arr;
        
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        
        string str = "";
        k=k-1;
        
        while(1)
        {
            str+= to_string(arr[k/f]);
            arr.erase(arr.begin()+k/f);
            if(arr.size()==0)
                break;
            k=k%f;
            f=f/arr.size();
        }
        return str;
    }
};