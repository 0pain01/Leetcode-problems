class MyHashSet {
public:
    vector<int>mp=vector<int>(1000001,0);
    MyHashSet() {
    }
    
    void add(int key) {
        mp[key]++;
    }
    
    void remove(int key) {
        mp[key]=0;
    }
    
    bool contains(int key) {
        if(mp[key]>=1)
            return true;
        else 
            return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */