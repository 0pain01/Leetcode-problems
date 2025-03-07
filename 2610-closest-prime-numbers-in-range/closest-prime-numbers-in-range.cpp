class Solution {
public:
void Solver(int l,int n , vector<int>&arr)
{
    vector<bool> prime(n + 1, true);
    prime[0]=prime[1]=false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {

            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = l; p <= n; p++)
        if (prime[p])
            arr.push_back(p);
}
    vector<int> closestPrimes(int left, int right) {
        vector<int>arr;
        Solver(left,right,arr);
        if(arr.size()<=1)
            return{-1,-1};

        int min=INT_MAX,x=0,y=0;

        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i+1]-arr[i]<min){
                min = arr[i+1]-arr[i];
                x=arr[i];
                y=arr[i+1];
            }
        }

        return {x,y};
    }
};