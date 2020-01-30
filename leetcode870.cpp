/*
贪心算法的水题。先把两个数组排序。从最小开始比，如果A[i] > B[i]
就把这个数相互对应，否则就消耗掉一个最大的B，使得这个A利益最大化。
为了找到排序后的要放的位置，对B的数进行了位置标记。
*/
class Solution {
public:
    typedef struct node{
        int num;
        int pos;
        bool operator<(const struct node& a)const{
            return num < a.num;
        }
    }Bnode;
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size());
        sort(A.begin(),A.end());
        vector<Bnode> BB;
        for(int i = 0 ; i < B.size() ; i++){
            Bnode temp;
            temp.num = B[i];
            temp.pos = i;
    
            BB.push_back(temp);
        }
        sort(BB.begin(),BB.end());
       
        int lefta = 0,leftb = 0,righta = A.size()-1,rightb = BB.size()-1;
        while(lefta <= righta && leftb <= rightb){
            if(A[lefta] <= BB[leftb].num){
                int pos = BB[rightb].pos;
               
                ans[pos] = A[lefta];
                lefta++;
                rightb--;
            }
            else{
                int pos = BB[leftb].pos;
                ans[pos] = A[lefta];
                lefta++;
                leftb++;
            }
        }
        return ans;
    }
};