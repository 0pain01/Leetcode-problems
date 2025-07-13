class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(begin(players),end(players));
        sort(begin(trainers),end(trainers));
        int n = players.size(),m=trainers.size();
        int cnt=0,i=n-1,j=m-1;
        while(i<n && j<m && i>=0 && j>=0){
            if(players[i]<=trainers[j]){
                cnt++;
                i--;j--;
            }
            else if(players[i]>trainers[j]){
                i--;
            }
            else{
                j--;
            }
        }

        return cnt;
    }
};