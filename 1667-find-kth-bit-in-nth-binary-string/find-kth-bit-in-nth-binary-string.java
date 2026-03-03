class Solution {
    private StringBuilder invert(String str){
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)=='0')
                sb.append("1");
            else
                sb.append("0");
        }
        return sb;
    }

    public char findKthBit(int n, int k) {
        StringBuilder sb = new StringBuilder();
        sb.append("0");

        for(int i=0;i<n-1;i++){
            StringBuilder str = invert(sb.toString());
            sb.append("1");
            str.reverse();
            sb.append(str);
            //System.out.println(sb);
        }

        return sb.toString().charAt(k-1);
    }
}

