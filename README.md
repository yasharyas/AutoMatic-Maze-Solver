# AutoMatic-Maze-Solver
YSC-Maze Solver (main.cpp)
YSC-Maze Solver is a C++ program that can automatically solve a maze using a Breadth-First Search (BFS) algorithm. The program is designed to find the shortest path from the starting position (S) to the ending position (E) within a maze represented by a grid. The maze may contain open paths (0), walls (1), and the solved path (2). The program provides colorful console output for better visualization.

How to Run the Code
Follow these steps to run the YSC-Maze Solver program:

Compile the Code:
Ensure that you have a C++ compiler installed on your system. You can use g++ or any other C++ compiler of your choice. Open your terminal or command prompt and navigate to the directory containing main.cpp. Compile the code by running:

bash
Copy code
g++ main.cpp -o ysc_maze_solver
This command will generate an executable file named ysc_maze_solver.

Run the Executable:
Once the code is successfully compiled, run the program by executing the following command:

bash
Copy code
./ysc_maze_solver
Input Maze Dimensions and Layout:

You will be prompted to enter the dimensions of the maze, n (number of rows) and m (number of columns).
Next, you will provide the maze layout. Use the following key:
0 for open paths
1 for walls
S for the start position
E for the end position
Input the maze row by row, separating cells with spaces.
Specify Start and End Positions:

You will be prompted to enter the starting and ending positions. Provide the row and column numbers for both positions.
View the Results:

The program will display the solved maze with the path from S to E marked in the maze.
The number of steps taken to reach the end position will be shown.
Exiting the Program:
The program will terminate after displaying the results.

Example Maze Input
Here's an example of how you can input a maze:

plaintext
Copy code
[INPUT x AND y]
5 7

[INPUT YOUR MAZE BELOW]
1 1 0 0 S 0 0
1 0 1 1 1 1 0
0 0 0 1 0 0 0
0 1 0 0 0 1 1
0 0 0 1 0 E 0

[INPUT START]
4 5
[INPUT END]
5 6
In this example, the maze dimensions are 5x7, and S and E represent the start and end positions, respectively.

Notes
The maze solver uses BFS to find the shortest path, ensuring a solution if one exists.
Be cautious to provide valid inputs to avoid issues, such as starting or ending positions on walls.
Feel free to use and modify this YSC-Maze Solver for your own maze layouts.