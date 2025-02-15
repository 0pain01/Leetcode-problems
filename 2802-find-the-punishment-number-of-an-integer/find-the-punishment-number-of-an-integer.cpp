class Solution {
public:
bool partition(string& s, int l, int r, int target) {
        if (l>r) return target==0;  // all digits used and target is 0, it's valid.
        int x=0;
        for (int m=l; m<=r; m++) {
            x=x*10+(s[m]-'0'); // stoi
            if (x>target) break;  // Stop early
            if (partition(s, m+1, r, target-x)) return 1;
        }
        return 0;
    }

    int punishmentNumber(int n) {
        int sum=0;
        for (int i=1; i<= n; i++) {
            int x=i*i;
            string s=to_string(x);
            if (partition(s, 0, s.size()-1, i)) 
                sum+=x;
        }
        return sum;
    }
};