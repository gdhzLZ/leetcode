class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int ans = 0;
        vector<int> visited(matrix[0].size(),0);
        for(int i = 0 ; i < matrix.size() ;i++){
            for(int j = 0 ; j < matrix[i].size() ; j++){ 
                if(matrix[i][j] == '1'){
                    visited[j]++;
                }
                else visited[j] = 0;
            }
            stack<int>tag;
            for(int j = 0 ; j < matrix[i].size() ; j++){
                if(tag.empty()){
                    tag.push(j);
                    continue;
                }
                if(visited[j] <= visited[tag.top()]){
                    while(!tag.empty()&&visited[j] <= visited[tag.top()]){
                        int pos = tag.top();
                        tag.pop();
                        if(tag.empty()){
                            int temp = (j)*visited[pos];
                            if(temp > ans) ans = temp;
                        }
                        else{
                            int temp = (j-tag.top()-1)*visited[pos];
                            if(temp > ans) ans = temp;
                        }
                    }
                }
                tag.push(j);
                
            }
            if(!tag.empty()){
                int last = tag.top();
                while(!tag.empty()){
                    int pos = tag.top();
                    tag.pop();
                    if(tag.empty()){
                        int temp = (last+1)*visited[pos];
                        if(temp > ans) ans = temp;
                    }
                    else{
                        int temp = (last-tag.top())*visited[pos];
                        if(temp > ans) ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};