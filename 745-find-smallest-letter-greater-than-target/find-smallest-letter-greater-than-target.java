class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        char firstLetter = letters[0];
        Arrays.sort(letters);

        int flag=0;
        for(int i=0;i<letters.length;i++){
            if(flag==0 && target<letters[i]){
                flag=1;
                return letters[i];
            }
        }

        return firstLetter;
    }
}