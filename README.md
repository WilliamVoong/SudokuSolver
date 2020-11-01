# SudokuSolver - Eliminate then backtrack! 
Sudoku solver in console. I've been thinking about this problem for years and upon reading the wikipedia article https://en.wikipedia.org/wiki/Sudoku_solving_algorithms. The backtracking algorithm sounded trivial so i decided to implement it. 


In this implementation of the sudokusolver i used a double linkedlist to store its solvable values and coordinates. 
The program tries  all valid values and used backtracking whenever a possible solution couldn't be find for a coordinate. 
The program only fails if the sudoku is unsolvable, as it tries every single combination of valid values for all coordinates. 
 



Demonstration of it solving one of the "hardest sudoku puzzle" .

https://www.telegraph.co.uk/news/science/science-news/9359579/Worlds-hardest-sudoku-can-you-crack-it.html


![alt text](https://github.com/WilliamVoong/SudokuSolver/blob/master/pictures/final_sudoku.PNG)



Assuming all combinations are represented in a tree, and each node represents the value of a coordinate in the sudoku.
We can eliminate possible nodes in the grid depending what clues we got from the original puzzle before implementing the backtracking algorithm, thus we greatly lessen the amount of combinations we need to try. 
To expand on this idea you can do this not only from the eliminate combinations with the orignal sudoku clues, but also with the values that you insert. However, this is not implemented and is just an idea on how to further optimze the solver!



Finding a orignal backtrack solution on github, and measuring time. 
The eliminate first before executing the backtracking-algorithm solution is approximately 77% faster (in this case), when solving the puzzle that is shown above.

![alt text](https://github.com/WilliamVoong/SudokuSolver/blob/master/sudoku_backtrack.PNG)

The project that was compared to was https://github.com/rajgopalc/Sudoku-Solver-in-C
