class Solution {
    private:
      bool isSafe(vector<vector<char>>& board,int row,int col,int digit){
        //horizontal
               for(int j=0;j<9;j++){
                   if(board[row][j]==digit){
                    return false;
                   }
               }

               // vertical
                for(int i=0;i<9;i++){
                   if(board[i][col]==digit){
                    return false;
                   }
               }

              // in the grid
              int startRow=(row/3)*3;
              int startCol=(col/3)*3;

              for(int i=startRow;i<startRow+3;i++){
                for(int j=startCol;j<startCol+3;j++){
                     if(board[i][j]==digit){
                    return false;
                   }   
                }
              }
          return true;
      }

     bool helper(vector<vector<char>>& board,int row,int col){
         if(row==9){
            return true;
         }
         int nextRow=row;
         int nextCol=col+1;

         if(nextCol==9){
            nextRow=row+1;
            nextCol=0;
         }

         if(board[row][col]!='.'){
            return helper(board,nextRow,nextCol);
         }

         // place the digit

         for(char digit='1';digit<='9';digit++){
                if(isSafe(board,row,col,digit)){
                      board[row][col]=digit;

                     if(helper(board,nextRow,nextCol)){
                        return true;
                     }

                     //backtracking
                     board[row][col]='.';
                }
         }
         return false;
     }

public:
    void solveSudoku(vector<vector<char>>& board) {
           helper(board,0,0);
    }
};