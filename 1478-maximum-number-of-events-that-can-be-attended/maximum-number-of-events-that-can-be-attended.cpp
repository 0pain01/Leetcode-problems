class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(begin(events),end(events));
        priority_queue<int,vector<int>,greater<>>pq;

        int currDay = events[0][0];
        int res=0;
        int i =0;

        while(!pq.empty() || i<n){
            while(i<n && events[i][0]==currDay){
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()){
                pq.pop();// one event attended
                res++;//day counted
            }

            currDay++;
            while(!pq.empty() && pq.top()<currDay){
                pq.pop();
            }
            
        }
        return res;
    }
};