class Solution {
    private int binaryStringToInteger(String binStr){
        int num=0;

        for(int i=31;i>=0;i--){
            if(binStr.charAt(i)=='1')
                num += Math.pow(2,31-i);
        }

        return num;
    }
    public int reverseBits(int n) {
        StringBuilder sb = new StringBuilder();

        while(n>0){
            sb.append(Integer.toString(n&1));
            n=n>>1;
        }

        int rem = 32-sb.length();
        for(int i=0;i<rem;i++)
            sb.append("0");

        System.out.println(sb);

        return binaryStringToInteger(sb.toString());
    }
}