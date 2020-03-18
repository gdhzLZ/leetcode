class Solution {
public:
    static bool compare(vector<int> a,vector<int> b)
    {
        if(a[0] != b[0])
            return a[0] > b[0];
        else return a[1] < b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(),people.end(),compare);
        if(people.size() == 0) return ans;
        for(int i = 0 ; i < people.size() ; i++){
            if(people[i][1] < ans.size()){
                ans.insert(ans.begin()+people[i][1],people[i]);
            }
            else{
                ans.push_back(people[i]);
            }
        }
        return ans;
    }
};