class Solution {
    public List<String> readBinaryWatch(int turnedOn) {
        List<String> lst = new ArrayList<>();
        
        for(int hour = 0; hour <12; hour++){
            for(int min = 0; min <60; min++){
                if( (bitCount(hour) + bitCount(min))  == turnedOn){          
                    if(min < 10){
                        lst.add(hour + ":" + "0" + min);
                    }
                    else{
                        lst.add(hour + ":" + min);
                    }
                }
            }
        }
        return lst;
    }

    public int bitCount(int val){
        int count = 0;
        while(val != 0){
            if((val & 1) == 1)
                count++;
            val = val>>1;
        }
        return count;
    }

}