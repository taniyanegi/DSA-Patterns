// approach 1

   #include <iostream>
   #include <bits/stdc++.h>
    using namespace std;

    // void helper(vector<vector<int>>& mat, int r, int c,
    //             string path, vector<string>& ans,
    //             vector<vector<bool>>& vis){

    //     int n = mat.size();

    //     if(r < 0 || c < 0 || r >= n || c >= n ||
    //        mat[r][c] == 0 || vis[r][c] == true){
    //         return;
    //     }

    //     if(r == n-1 && c == n-1){
    //         ans.push_back(path);
    //         return;
    //     }

    //     vis[r][c] = true;

    //     // Down
    //     helper(mat, r+1, c, path+"D", ans, vis);

    //     // Left
    //     helper(mat, r, c-1, path+"L", ans, vis);

    //     // Right
    //     helper(mat, r, c+1, path+"R", ans, vis);
        
    //      // Up
    //     helper(mat, r-1, c, path+"U", ans, vis);

    //     // Backtracking
    //     vis[r][c] = false;
    // }

    // vector<string> ratInMaze(vector<vector<int>>& maze) {

    //     int n = maze.size();

    //     vector<string> ans;
    //     if(maze[0][0] == 0 || maze[n-1][n-1]==0)
    //         return ans;
    //     vector<vector<bool>> vis(n, vector<bool>(n, false));

    //     string path = "";

    //     helper(maze, 0, 0, path, ans, vis);

    //     return ans;
    // }



// approach 2-optimized


    void helper(vector<vector<int>>& mat, int r, int c,
                string path, vector<string>& ans){

        int n = mat.size();

        if(r < 0 || c < 0 || r >= n || c >= n ||
           mat[r][c] == 0 || mat[r][c] == -1){
            return;
        }

        if(r == n-1 && c == n-1){
            ans.push_back(path);
            return;
        }

        mat[r][c] = -1;

        // Down
        helper(mat, r+1, c, path+"D", ans);

        // Left
        helper(mat, r, c-1, path+"L", ans);

        // Right
        helper(mat, r, c+1, path+"R", ans);
        
         // Up
        helper(mat, r-1, c, path+"U", ans);

        // Backtracking
        mat[r][c] = 1;
    }



    vector<string> ratInMaze(vector<vector<int>>& maze) {

        int n = maze.size();

        vector<string> ans;
        if(maze[0][0] == 0 || maze[n-1][n-1]==0)
            return ans;
        string path = "";

        helper(maze, 0, 0, path, ans);

        return ans;
    }

    int main(){
        vector<vector<int>> maze={{1,0,0,0},
                                   {1,1,0,1},
                                   {1,1,0,0},
                                   {0,1,1,1}};
        vector<string> ans=ratInMaze(maze);
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
        return 0;
    }