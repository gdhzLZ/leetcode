class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        vector<int> ttt(1);
        ttt.insert(ttt.begin(),ans.begin(),ans.end());
        stack<pair<int,int>> positive_max;
        int pos = 0;
        int neg = 0;
        while(pos < asteroids.size()){
            if(asteroids[pos] < 0){
                while(!positive_max.empty()){
                    int t = positive_max.top().second;
                    if(asteroids[t] < -asteroids[pos]){
                        positive_max.pop();
                    }
                    else if(asteroids[t] == -asteroids[pos]){
                        
                        positive_max.top().second--;
                        if(positive_max.top().second < positive_max.top().first){
                            positive_max.pop();
                            asteroids[pos] = 0;
                            
                        }
                        break;
                    }
                    else if(asteroids[t] > -asteroids[pos]){                                     
                        break;
                    }
                }
                if(positive_max.empty() && asteroids[pos] != 0){
                    ans.push_back(asteroids[pos]);
                }
                neg = pos + 1;
            }
            else{
                if(pos < asteroids.size() -1 && asteroids[pos] > asteroids[pos+1]){
                   cout <<"pos "<<neg << pos << endl;
                    positive_max.push(make_pair(neg,pos));
                    neg = pos+1;
                    
                }
                else if(pos == asteroids.size() -1 && asteroids[pos] > 0){
                     positive_max.push(make_pair(neg,pos));
                }

            }
            pos++;
        }
        stack<pair<int,int>> reverse;
        while(!positive_max.empty()){
            reverse.push(positive_max.top());
            positive_max.pop();
        }
        cout << reverse.size() << endl;
        
        while(!reverse.empty()){
            int left = reverse.top().first;
            int right = reverse.top().second;
            cout << left << right <<endl;
            for(int i = left ; i <= right ; i++)
                ans.push_back(asteroids[i]);
            reverse.pop();
        }
        return ans;
    }
};