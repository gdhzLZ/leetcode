class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
       
        vector<int> ans;
        int length = 0;
        string s1,s2;
        for(int i = 0 ; i < nums1.size() ; i++){
            char c = nums1[i]+'0';
            s1+=c;
        }
            
         for(int i = 0 ; i < nums2.size() ; i++){
             char c = nums2[i]+'0';
             s2+=c;
         }
            
        string now = "0";
        for(int i = 0 ; i <= k ; i++){
            string now1 = "",now2 = "";
            now1 = maxKsequence(s1,i);
            now2 = maxKsequence(s2,k-i);
            cout << now1 << " " << now2 << endl;
            int pos1 = 0,pos2 = 0;
            string now3 = maxNumber(now1,now2);
            if(now3.size() < k) continue;
            if(now < now3) now = now3;
        }
        for(int i = 0 ; i < now.size() ; i++){
            int t = now[i]-'0';
            ans.push_back(t);
        }
        return ans;
    }
    string maxKsequence(string now, int k){
        int n = now.size() ;
        if (n <= k)
            return now;
        string res;
        int pop = n-k;
        for (int i=0; i<n; i++){
            while(!res.empty() && now[i]>res.back() && pop-->0)
                res.pop_back();
            res.push_back(now[i]);
        }

        while(res.size() > k)
            res.pop_back();
        return res;
    }
    string maxNumber(string nums1,string nums2)
    {
        string ans;
        auto s1=nums1.begin();
        auto s2=nums2.begin();
        auto e1=nums1.end();
        auto e2=nums2.end();
        
        while(s1!=e1||s2!=e2)
            ans.push_back(
                lexicographical_compare(s1,e1,s2,e2)? *s2++: *s1++);
        return ans;
        
    }

};