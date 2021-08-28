class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        reverse(digits.begin(),digits.end());
        
    
        if(digits[0]==9){
            int i=0;
            for(i=0;i<digits.size();i++){
                if(digits[i]<9)
                    break;
            }
            if(i==digits.size()){
                for(int j=0;j<digits.size();j++){
                    digits[j]=0;
                }
                digits.push_back(1);
            }
            else{
                for(int j=0;j<i;j++){
                    digits[j]=0;
                }
                digits[i]+=1;
            }
        }
        else{
            digits[0]+=1;
        }
        
        reverse(digits.begin(),digits.end());
        
        return digits;
    }
};