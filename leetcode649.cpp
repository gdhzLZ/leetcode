class Solution {
public:
    string predictPartyVictory(string senate) {
        while(1){
           
            for(int i = 0  ;i < senate.size() ; i++){
                if(senate[i] == 'D'){
                    if(senate.find('R') == -1)
                        return "Dire";
                    int pos = senate.find('R',i);
                    if(pos != -1){
                        senate.erase(senate.begin()+pos);
                    }
                    else{
                        int pos = senate.find('R');
                        senate.erase(senate.begin()+pos);
                        i--;
                    }
                    
                }
                else if(senate[i] == 'R'){
                    if(senate.find('D') == -1)
                        return "Radiant";
                    int pos = senate.find('D',i); 
                    if(pos != -1){
                        senate.erase(senate.begin()+pos);
                    }  
                    else{
                        int pos = senate.find('D');
                        senate.erase(senate.begin()+pos);
                        i--;
                    }
                     
                }
            }
        
        }
    }
};