class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[1] != b[1])
            return a[1] > b[1];
        else return a[0] > b[0];
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int,vector<int>,greater<int>> Q;
        vector<vector<int>> now(speed.size());
        for(int i = 0 ; i < speed.size() ; i++){
            now[i].push_back(speed[i]);
            now[i].push_back(efficiency[i]);
        }
        sort(now.begin(),now.end(),comp);
        
        int ans = 0;
        long long tempAns = 0; 
        long long sum = 0;
        int pos = 0;
        long long N = pow(10,9)+7;
        while(pos <now.size()){
            long long nowEff = now[pos][1];
            Q.push(now[pos][0]);
            sum+=now[pos][0];
            pos++;
            while(pos < now.size() && now[pos][1] == now[pos-1][1]){
                sum+=now[pos][0];
                Q.push(now[pos][0]);
                pos++;
            }
            while(Q.size() > k){
                sum-=Q.top();
                cout << "erase " << Q.top() << endl;
                Q.pop();
            }
            if(tempAns < ((sum*nowEff)))
                tempAns = (sum*nowEff);
        }
        return tempAns%N;
       
    }
};