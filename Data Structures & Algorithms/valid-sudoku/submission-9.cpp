class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string,int> hashbox;
        unordered_map<string,int> hashcolumn;
        unordered_map<string,int> hashrow;
       for(int i = 0; i<81; i++){
        int row = i/9;
        int column = i%9;
        if(board[row][column] == '.'){
            continue;
        }
        char key = board[row][column];
        int first = row/3;
        int second = column/3;

        string result = string(1, key) + to_string(first) + to_string(second);
        if(hashbox.find(result) != hashbox.end()){
            return false;
        }
        hashbox[result]++;

        result = board[row][column] + to_string(row);
        if(hashrow.find(result) != hashrow.end()){
            return false;
        }
        hashrow[result]++;

        result = board[row][column] + to_string(column);
         if(hashcolumn.find(result) != hashcolumn.end()){
            return false;
        }
        hashcolumn[result]++;
       }
       return true;
    }
};
// clear 3x3 check
// clear other 3x3 using cleared 3x3

//keeps tracks of columns and rows and stores values in those
//every element is being stored twice since ther ein subspace
//and in row/column nvm 3 times