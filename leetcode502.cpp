class Solution {
public:
struct cmp1
    {
        bool operator ()(pair<int,int>a,pair<int,int>b)
        {
            return a.second<b.second;
        }
    };
struct cmp2
    {
        bool operator ()(pair<int,int>a,pair<int,int>b)
        {
            return a.first>b.first;
        }
    };
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp1> A;//按利益排 大顶堆
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp2> B;//按资金排 小顶堆
        for(int i = 0 ; i < Capital.size() ; i++){
           pair<int,int> temp;
           temp.first =  Capital[i];
           temp.second = Profits[i];
           if(Capital[i] <= W) A.push(temp);
           else B.push(temp);
        }
        while(k--){
            if(A.empty()) break;
            W+=A.top().second;
            A.pop();
            while(!B.empty()&&B.top().first <= W){
                pair<int,int> temp = B.top();
                B.pop();
                A.push(temp);
            }
        }
        return W;
    }
};