class Solution {
public:
    static bool com(vector<int> a,vector<int> b){
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),com);
        priority_queue<int> Q;
        int nowDay = 0;
        int num = 0;
        for(int i = 0 ; i < courses.size() ; i++){
           if(nowDay+courses[i][0] <= courses[i][1]){
               num++;
               nowDay += courses[i][0];
               Q.push(courses[i][0]);
           }
           else{
               if(!Q.empty() && Q.top() > courses[i][0]){
                    nowDay = nowDay-Q.top()+courses[i][0];
                    Q.pop();
                    Q.push(courses[i][0]);
               }
           }
        }
        return num;
    }
};