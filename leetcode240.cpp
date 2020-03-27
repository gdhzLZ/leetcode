class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int posx = 0,posy = matrix[0].size()-1;
        while(1){
            if(posx < 0 || posx >= matrix.size() || posy < 0 || posy >= matrix[0].size()){
                return false;
            }
            if(matrix[posx][posy] == target)
                return true;
            if(matrix[posx][posy] < target)
                posx++;
            else posy--;
        }
        return false;
    }
};