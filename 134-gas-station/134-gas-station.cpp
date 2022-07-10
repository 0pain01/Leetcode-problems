class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalcost = 0;
        int currcost = 0;
        int startIndex = 0;
        
        for(int i =0; i<gas.size(); i++){
            
            totalcost = totalcost + (gas[i] - cost[i]);
            currcost = currcost + (gas[i] - cost[i]);
            

            if(currcost < 0){
                currcost = 0;
                startIndex = i +1;
            }
        }
        

        if(totalcost >= 0)
        return startIndex;
        
        else
        return -1;
    }
};