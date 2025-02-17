class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(),pizzas.end(),greater<>());
        int n = pizzas.size();
        long long days = n/4;
        long long odd = (days%2==0)?days/2:(days/2)+1;
        long long even = days-odd;
        long long sum=0;

        for(int i=0;i<odd;i++){
            sum+=pizzas[i];
        }

        
        for(int i=odd+1;i<(odd+2*even);i+=2){
            sum+=pizzas[i];
        }

        return sum;
    }
};