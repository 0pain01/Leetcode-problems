class ProductOfNumbers {
public:
    ProductOfNumbers() {
    }
    vector<int>arr;
    
    void add(int num) {
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        int prod =1;
        int n = arr.size();
        for(int i=0;i<k;i++){
            prod= prod*(arr[n-1-i]);
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */