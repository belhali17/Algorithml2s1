#include <stdio.h>
 #define N 4
 int board[N][N];
 int isSafe(int row, int col)
{
  for (int i = 0; i < col; i++)
{
  if (board[row][i] == 1)
{
 return 0;
    } }
 for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
 {
 if (board[i][j] == 1)
 {
     return 0;
} }
  for (int i = row, j = col; j >= 0 && i < N; i++, j--)
  {
 if (board[i][j] == 1)
  { return 0;
    } }
return 1;
}
 int solveNQueens(int col)
  {
    if (col >= N)
{
return 1;
 }
  for (int i = 0; i < N; i++)
   {
 if (isSafe(i, col))
  { board[i][col] = 1;
  if (solveNQueens(col + 1))
{
return 1; }
 board[i][col] = 0;
 } }
 return 0;
 }
