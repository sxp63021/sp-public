#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Brute Force Approach, go over each element
// make another vector of same size to show that you visited the index

class Solution {
public:
    
    vector<vector<int>> visited; // fill all elements with default 0 to show we did not visit
    
#if 0
    void markAllAdjoiningLandVisited(int row, int col, int rowcnt, int colcnt, vector<vector<char>> &grid) {
        // we are in this routine only if the current node is 1
        // check if the next element in the row is 1, if so mark it as visited if not already marked
        int crow = row, ccol = col;
        // check if any element in the other rows below is 1
        //condition2 = (visited[crow+1][col] == 0)
        // condition1 = crow++ < rowcnt
        bool iterate = true;
        do {
          crow++; // check if crow is less than rowcnt
          if (crow == rowcnt) { // end of rows, break out of loop
              iterate = false;
          } else {
            if (visited[crow][ccol] == 1) { // if it has already been visited, return
                iterate = false;
            } else {
                if (grid[crow][col] == '1') { // part of same island as above, mark as visited
                    visited[crow][col] = 1;
					cout << "Marking row: " << crow << " col: " << col << " as " << visited[crow][col] << endl;
					// iterate over the column
					for(int c=col; c < colcnt; c++) {
						if (grid[crow][c] == '1') {
							visited[crow][c] = 1;
						} else {
							break;
						}
					}
                } else {
                    iterate = false;
                }
            }
		  }
        } while(iterate);
        
        // check if any elements in the other col for current row is 1
        iterate = true;
        do {
            ccol++;
            if (ccol == colcnt) { // end of columns, break out of loop
              iterate = false;
            } else {
              if (visited[row][ccol] == 1) { // if it has already been visited, return
                iterate = false;
              } else {
                if (grid[row][ccol] == '1') { // part of same island as above, mark as visited
                    visited[row][ccol] = 1;
					cout << "Marking row: " << crow << " col: " << col << " as " << visited[crow][col] << endl;
					// iterate over the row
					for(int r = row; r < rowcnt; r++) {
						if (grid[r][ccol] == '1') {
							visited[r][ccol] = 1;
						} else {
							break;
						}
					}
                } else {
                    iterate = false;
                }
              }            
			}
        } while(iterate);
        
        return;
    }
#endif
	void markVisitedLookAdj(int row,int col,int rowcnt,int colcnt,vector<vector<char>> &grid){

		if ( (row >= 0) && (row < rowcnt) ) {
			if ( (col >= 0) && (col < colcnt) ) {
				if ((visited[row][col] == 0) && (grid[row][col] == '1')) { 
					visited[row][col] = 1;
					markVisitedLookAdj(row, (col - 1), rowcnt, colcnt, grid);
					markVisitedLookAdj(row, (col + 1), rowcnt, colcnt, grid);
					markVisitedLookAdj((row - 1), col, rowcnt, colcnt, grid);
					markVisitedLookAdj((row + 1), col, rowcnt, colcnt, grid);
				}
			} else {
				return;
			}
		} else {
			return;
		}
	}
    
    int numIslands(vector<vector<char>>& grid) {
        
        // scan through columns and rows
        int rows = grid.size();
        int cols = grid[0].size();
		cout << "Size of matrix: " << rows << " by " << cols << endl;

		for (int r = 0; r < rows; r++) {
			vector<int> v;
			for (int c = 0; c < cols; c++) {
				v.push_back(0);
			}
			visited.push_back(v);
		}
        int islandcount = 0;
        for(int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
				cout << "element[" << i << "][" << j << "]:" << grid[i][j] << endl;
                // if there is 1 in this position, it means it is island
                // check if the node is already visited before bumping the islandcount
                if (grid[i][j] == '1') { // island
                    if (visited[i][j] == 0) { 
                        islandcount++;
#if 0
                        visited[i][j] = 1;
                        // mark all the possible places we can go from here as visited
                        markAllAdjoiningLandVisited(i,j, rows, cols, grid);
#endif
						markVisitedLookAdj(i,j,rows,cols,grid);
                    } else {
                        // nothing to do
                    }
                } else { // don't count
                    // might not need this loop
                }
            }
        }
        return islandcount;
    }
};

int main() {
	
	vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
//	vector<vector<char>> grid = [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]];

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 5; col++) {
			cout << grid[row][col] << " ";
		}
		cout << endl;
	}

	Solution s1;
	cout << "Number of Islands in the given matrix: " << s1.numIslands(grid) << endl;
	return 0;
}


