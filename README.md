# SudokuSolver - Eliminate then backtrack! 
Sudoku solver in console. In this implementation of the sudokusolver i used a double linkedlist to store its solvable values and coordinates. 
The program tries  all valid values and used backtracking whenever a possible solution can't be find for a coordinate. 
The program only fails if the sudoku is unsolvable, as it tries every single combination of valid values for all coordinates. 
 



Demonstration of it solving one of the "hardest sudoku puzzle" .

https://www.telegraph.co.uk/news/science/science-news/9359579/Worlds-hardest-sudoku-can-you-crack-it.html


![alt text](https://github.com/WilliamVoong/SudokuSolver/blob/master/hardestpuzzle.PNG)



Assuming all combinations are represented in a tree, and each node represents the value of a coordinate in the sudoku.
We can eliminate possible nodes in the grid depending what clues we got from the original puzzle before implementing the backtracking algorithm, thus we greatly lessen the amount of combinations we need to try.

Finding a orignal backtrack solution on github, and measuring time. 
The eliminate then backtrack solution is approximately 77% faster, when solving the puzzle that is shown above


![alt text](https://github.com/WilliamVoong/SudokuSolver/blob/master/sudoku_backtrack.PNG)

The project that was compared to was https://github.com/rajgopalc/Sudoku-Solver-in-C
