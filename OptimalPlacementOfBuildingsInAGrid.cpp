/* 
    Time Complexity                              :  O((HW Pn) * (H*W)) -- the first one is due to backtracking and the second one is due to bfs.
    Space Complexity                             :  size of grid, queue, visited arrays ~= O(H*W)
    Did this code successfully run on Leetcode   :  Yes
    Any problem you faced while coding this      :  No
*/

#include <bits/stdc++.h> 
using namespace std; 


class Solution {
    private:
        vector<vector<int>> dirs{{-1,0},{1,0},{0,1},{0,-1}};
        vector<vector<int>> grid;
        int mnDistance, h, w;
    public:
        int computeDistance(int H,int W) {
            h = H;
            w = W;
            grid.resize(H,vector<int>(W,-1));
            //place the building
            backtracking(int r,int c);
        }

        void bfs() {
            queue<pair<int,int>> q;
            vector<vector<bool>> visited(h,vector<bool>(w,false));

            for(int i=0;i<h;i++) {
                for(int j=0;j<w;j++) {
                    if(grid[i][j] == 0) {
                        //push the co-ordinates of all the buildings on the grid in the queue
                        q.push({i,j});
                        visited[i][j] = true;
                    }
                }
            }
            int mdistance = 0;
            while(!q.empty()) {
                int sz = q.size();
                for(int i=0;i<sz;i++) {
                    auto [r,c] = q.front();q.pop();
                    for(auto dir : dirs) {
                        int nr = r + dir[0];
                        int nc = c + dir[1];
                        if(nr >=0 and nr < h and nc >=0 and nc < w and !visited[nr][nc] and grid[nr][nc] == -1) {
                            visited[nr][nc] = true;
                            q.push(pair<int,int>{nr,nc});
                        }
                    }

                }
                mdistance++;
            }


            int minDistance = INT_MAX;
            minDistance = min(minDistance, mdistance-1);
        }

        void backtracking(int n, int r, int c) {
            //base
            if(n == 0) {
                bfs();
            }

            if(c == w) {
                r++;
                c = 0;
            }
            //logic
            for(int i=r;i<h;i++) {
                for(int j=c;j<w;j++) {
                    // empty slot
                    if(grid[r][c] == -1) {
                        // the building is placed at this point
                        grid[r][c] = 0;
                        backtracking(n-1,r,c+1);
                        grid[r][c] = -1;
                    }
                }
            }
        }

};