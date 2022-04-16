class ATM {
public:
    ATM() {}
    
    vector<long long>acc{0,0,0,0,0};
    vector<int>val{20, 50, 100, 200, 500};
    
    void deposit(vector<int> banknotesCount) 
    {
        for (int i = 0; i < 5; ++i)
            acc[i] += banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) 
    {
        vector<int>w(5);
        for (int i = 4; i >= 0; --i) 
        {
            if(acc[i]<amount/val[i])
                w[i]=acc[i];
            else
                w[i]=amount/val[i];
            //w[i] = min(acc[i], amount / val[i]);
            amount -= w[i] * val[i];
        }
        if (amount)
            return { -1 };
        
        for (int i = 0; i < 5; ++i)
            acc[i] -= w[i];   
        
        return w;
    }
};
