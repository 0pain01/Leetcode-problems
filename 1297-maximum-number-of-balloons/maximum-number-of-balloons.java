class Solution {
    public int maxNumberOfBalloons(String text) {
        int b = 0, l = 0, a = 0, o = 0, n = 0;

        for (int i = 0; i < text.length(); i++){
            if(text.charAt(i)=='b') 
                b++;
            else if(text.charAt(i)=='a')    
                a++;
            else if(text.charAt(i)=='l')
                l++;
            else if(text.charAt(i)=='o')
                o++;
            else if(text.charAt(i)=='n')
                n++;
        }

        return Math.min(b,(Math.min(a,Math.min(l/2,Math.min(o/2,n)))));
    }
}