class Solution {
    private int [] Counter(String s, int index, char c, int n){
        int streak = 0;
        while(index < n && s.charAt(index) == c){
            streak++;
            index++;
        }
        return new int[] {streak, index};
    }
    
    public int countBinarySubstrings(String s) {
        int size = s.length();

        int i = 0;
        int result = 0;

        while(i < size){

            char firstChar = s.charAt(i);
            int [] firstStreak = Counter(s,i,firstChar,size);
            int firstCount = firstStreak[0];
            int nextIndex = firstStreak[1];

            if(nextIndex >= size) break;

            char secondChar = s.charAt(nextIndex);
            int [] secondStreak = Counter(s,nextIndex,secondChar,size);
            int secondCount = secondStreak[0];

            result+= Math.min(firstCount,secondCount);
            i=nextIndex;
        
        }
        return result;
    }
}