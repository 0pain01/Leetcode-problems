class Solution {

    public String maximumXor(String s, String t) {
        int n = t.length();
        int countSetBit = 0;

        for(char c : t.toCharArray()){
            if(c =='1') countSetBit++;
        }
        
        int zeroBit = n - countSetBit;
        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < n; i++){
            if(s.charAt(i) == '0' && countSetBit > 0){
                countSetBit--;
                sb.append('1');
            }
            else if(s.charAt(i) == '1'  && zeroBit > 0){
                zeroBit--;
                sb.append('1');
            }
            else{
                sb.append('0');
            }
        }

        return sb.toString();
    }
}