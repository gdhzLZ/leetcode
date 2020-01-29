class Solution {
public:
    string alphabetBoardPath(string target) {
        string board[6] = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        int nowx = 0, nowy = 0;
        string ans = "";
        for(int i = 0 ; i < target.size() ; i++){
            int tarx = (target[i]-'a')/5;
            int tary = (target[i]-'a')%5;
            if(tarx == 5 && tary == 0){
                while(nowy>0){
                    nowy--;
                    ans+='L';
                }
            }
            else if(nowx == 5 && nowy == 0){
                nowx--;
                ans+='U';
            }
            while(1){
                if(board[nowx][nowy] == target[i]){
                    ans += '!';
                    break;
                }
                
                if(tarx < nowx){
                    nowx--;
                    ans+='U';
                }
                else if(tarx == nowx){
                    if(tary > nowy){
                        nowy++;
                        ans+='R';
                    }
                    else{
                        nowy--;
                        ans+='L';
                    }
                }
                else{
                    nowx++;
                    ans+='D';
                }
            
            }
            
        }
        return ans;
    }
};