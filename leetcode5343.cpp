class Solution {
public:
    struct cmp
{
    template <typename T, typename U>
    bool operator()(T const &left, U const &right)
    {
        return left.first < right.first;
    }
};
    bool isPossible(vector<int>& target) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> Q;
        long long sum = 0;
        int numOne = 0;
        for(int i = 0 ; i < target.size() ; i++){
            Q.push(make_pair(target[i],i));
            sum+=target[i];
            if(target[i] != 1) numOne++;
            if(target[i] <= 0) return false;
        }
        while(numOne){
            pair now = Q.top();
            Q.pop();
            long long temp = now.first-(sum-now.first);
            if(temp <= 0 ) return false;
            if(temp == 1) numOne--;
            Q.push(make_pair(temp,now.second));
            sum = sum-now.first+temp;
        }
        return true;

    }
};