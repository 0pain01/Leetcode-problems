class Solution {
    private int setBitCount(String binaryString){
        int count = 0;
        for(int i = 0; i < binaryString.length(); i++){
            if(binaryString.charAt(i)=='1')
                count++;
        }
        return count;
    }
    public String maximumXor(String s, String t) {
        int countSetBit = setBitCount(t);
        int n = t.length();

        System.out.println(countSetBit);
        int zeroBit = n - countSetBit;
        System.out.println(zeroBit);
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