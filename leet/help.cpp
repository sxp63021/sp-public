#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	
	vector<vector<char>> grid = { {'1','2','3'},
								 {'4','5','6'},
								 {'7','8','9'}
							   };
#if 0
	vector<vector<int>> grid = { {1,2,3},
								 {4,5,6},
								 {7,8,9}
							   };
#endif

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
		

	return 0;
}
