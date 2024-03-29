// https://leetcode.com/problems/n-queens-ii


   
int solve(vector<bool>& col, vector<bool>& diag, vector<bool>& anti_diag, int row) {
	int n = size(col), count = 0;
    if(row == n) return 1;
	for(int column = 0; column < n; column++)           
		if(!col[column] && !diag[row + column] && !anti_diag[row - column + n - 1]){        // check if (row, column) is safe
			col[column] = diag[row + column] = anti_diag[row - column + n - 1] = true;      // place at (row, column)
			count += solve(col, diag, anti_diag, row + 1);                                  // explore for the next row
			col[column] = diag[row + column] = anti_diag[row - column + n - 1] = false;     // backtrack
		}                                
	return count;
}

int totalNQueens(int n) {
	vector<bool> col(n), diag(2*n-1), anti_diag(2*n-1);
	return solve(col, diag, anti_diag, 0);
}