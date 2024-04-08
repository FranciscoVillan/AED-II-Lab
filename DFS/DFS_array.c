#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Function to perform DFS on a 2D array
void DFS(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, int row, int col, int visited[MAX_ROWS][MAX_COLS]) {
    // Base case: check if the current cell is out of bounds or already visited
    if (row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col] || matrix[row][col] == 0)
        return;

    if (matrix[row][col] != 1)
        return;
    
    // Mark the current cell as visited
    visited[row][col] = 1;
    printf("(%d, %d) ", row, col);

    // Recursive DFS for adjacent cells
    DFS(matrix, rows, cols, row - 1, col, visited); // Up
    DFS(matrix, rows, cols, row + 1, col, visited); // Down
    DFS(matrix, rows, cols, row, col - 1, visited); // Left
    DFS(matrix, rows, cols, row, col + 1, visited); // Right
}

int adyacent(int row_pos, int colm_pos)
{

}

int main() {
    int matrix[MAX_ROWS][MAX_COLS] = {
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1}
    };
    int rows = 3;
    int cols = 5;
    int visited[MAX_ROWS][MAX_COLS] = {0}; // Initialize all cells as not visited

    printf("DFS traversal of the 2D array:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                DFS(matrix, rows, cols, i, j, visited);
            }
        }
    }

    return 0;
}
