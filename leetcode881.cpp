class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans = 0;
        int left = 0;
        int right = people.size()-1;
        int canTogetherWihtRightNum = 0;
        while(left <= right){
            ans++;
            if(people[right] < limit){
                int dis = limit-people[right];
                while(left<right&&people[left] <= dis){
                    canTogetherWihtRightNum++;
                    left++;
                }
                if(canTogetherWihtRightNum!=0)
                    canTogetherWihtRightNum--;
            }
            right--;
        }
        int t = (canTogetherWihtRightNum+1)/2;
        return ans+t;
    }
}; 