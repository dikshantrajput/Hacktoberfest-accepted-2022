import math
import random
import time
import sys
import numpy as np

nodesVisited = 0
def main():
    
    print_help()
    # take multiple inputs
    inputList = []
    maxLengthList = 3
    while len(inputList) < maxLengthList:
        if (len(inputList) == 1 or len(inputList) == 0):
            item = input("Enter your difficulty level: ")
            inputList.append(item)
        if len(inputList) >= 1:
            item = input("Enter your method: ")
            inputList.append(item)
        if len(inputList) >= 2:
            item = input("Enter your number of trial: ")
            inputList.append(item)

    if len(inputList) < 1:
        print_help()
        return 0

    if len(inputList) == 3:
        n_trials = inputList[2]
    else:
        n_trials = 50
    print("Number of trials: " , n_trials)

    run_times = []
    

    ### Easy Puzzle
    easy = [[0, 3, 0, 0, 8, 0, 0, 0, 6],
            [5, 0, 0, 2, 9, 4, 7, 1, 0],
            [0, 0, 0, 3, 0, 0, 5, 0, 0],
            [0, 0, 5, 0, 1, 0, 8, 0, 4],
            [4, 2, 0, 8, 0, 5, 0, 3, 9],
            [1, 0, 8, 0, 3, 0, 6, 0, 0],
            [0, 0, 3, 0, 0, 7, 0, 0, 0],
            [0, 4, 1, 6, 5, 3, 0, 0, 2],
            [2, 0, 0, 0, 4, 0, 0, 6, 0]]

    ### Medium puzzle
    medium = [[3, 0, 8, 2, 9, 6, 0, 0, 0],
              [0, 4, 0, 0, 0, 8, 0, 0, 0],
              [5, 0, 2, 1, 0, 0, 0, 8, 7],
              [0, 1, 3, 0, 0, 0, 0, 0, 0],
              [7, 8, 0, 0, 0, 0, 0, 3, 5],
              [0, 0, 0, 0, 0, 0, 4, 1, 0],
              [1, 2, 0, 0, 0, 7, 8, 0, 3],
              [0, 0, 0, 8, 0, 0, 0, 2, 0],
              [0, 0, 0, 5, 4, 2, 1, 0, 6]]

    ### Hard Puzzle
    hard = [[7, 0, 0, 0, 0, 0, 0, 0, 0],
            [6, 0, 0, 4, 1, 0, 2, 5, 0],
            [0, 1, 3, 0, 9, 5, 0, 0, 0],
            [8, 6, 0, 0, 0, 0, 0, 0, 0],
            [3, 0, 1, 0, 0, 0, 4, 0, 5],
            [0, 0, 0, 0, 0, 0, 0, 8, 6],
            [0, 0, 0, 8, 4, 0, 5, 3, 0],
            [0, 4, 2, 0, 3, 6, 0, 0, 7],
            [0, 0, 0, 0, 0, 0, 0, 0, 9]]

    ### EVIL Puzzle         
    evil = [[0, 6, 0, 8, 0, 0, 0, 0, 0],
            [0, 0, 4, 0, 6, 0, 0, 0, 9],
            [1, 0, 0, 0, 4, 3, 0, 6, 0],
            [0, 5, 2, 0, 0, 0, 0, 0, 0],
            [0, 0, 8, 6, 0, 9, 3, 0, 0],
            [0, 0, 0, 0, 0, 0, 5, 7, 0],
            [0, 1, 0, 4, 8, 0, 0, 0, 5],
            [8, 0, 0, 0, 1, 0, 2, 0, 0],
            [0, 0, 0, 0, 0, 5, 0, 4, 0]]

    puzzles = [easy, medium, hard, evil]

    puzzle = puzzles[int(inputList[0])-1]
    print("Solving the following puzzle: ")
    print_puzzle(puzzle)

    start_time = time.time()

    method_type = int(inputList[1])
    if method_type == 1:
        print("Using backtracking search.")
        result = solve_backtrack(puzzle)
    elif method_type == 2:
        print("Using backtracking with forward checking.")
        result = solve_btfc(puzzle)
    else:
        print("Using backtracking with forward checking and heurisitics.")
        result = solve_btfch(puzzle)

    if result:
        print("It took", time.time() - start_time, "seconds to solve this puzzle.")
    else:
        print("Failed to find a solution! D:")


    for i in range(int(n_trials)):
        start_time = time.time()
        if not solve_backtrack(puzzle ):
            print ("Failed to find a solution! D:")
        else:
            elapsed = time.time() - start_time
            print ("It took", time.time() - start_time, "seconds to solve this puzzle.")
            print ("elapsed:", elapsed)
            run_times.append( elapsed )
            #print("Nodes Visited: ", nodesVisited)
    
    run_times
    ar = np.array(run_times)
    #print(run_times)
    print ("Average run time:", sum(run_times)/int(n_trials))
    print("Standard Deviation: ", ar.std())
    print("Nodes Visited: ", nodesVisited-int(n_trials))


# Recursive backtracking algorithm to solve puzzle     
def solve_backtrack(puzzle):
    global nodesVisited
    nodesVisited += 1
    # store all the possible values remaining for a square
    domain = list(range(1, 10))

    # get a list of the empty squares (remaining variables)
    empty_squares = get_empty_squares(puzzle)

    # if there are no remaining empty squares we're done
    if len(empty_squares) == 0:
        print("Woohoo, success! Check it out:")
        print_puzzle(puzzle)
        print("Nodes Visited: ", nodesVisited)
        return 1

    square = get_random_square(empty_squares)
    row = square[0]
    col = square[1]

    while len(domain) != 0:
        # get a random value out of the list of remaining possible values
        value = domain[int(math.floor(random.random() * len(domain)))]
        #domain.remove(value)
        domain = [i for i in domain if i != value]
        # check the value against theconstraints
        if check_row(square, value, puzzle):
            if check_col(square, value, puzzle):
                if check_block(square, value, puzzle):
                    puzzle[row][col] = value
                    if solve_backtrack(puzzle):                    
                        return 1
                    else:
                        
                        puzzle[row][col] = 0
    return 0


# Backtracking with forward-checking algorithm
# Stores a list with all the variables and their potentially legal 
# values - stops when there are no empty squares remaining
# Randomly selects the next cell and the value
def solve_btfc(puzzle):
    global nodesVisited
    nodesVisited += 1
    # get a list of the empty squares (remaining variables)
    empty_squares = get_empty_squares(puzzle)

    # if there are no remaining empty squares we're done
    if len(empty_squares) == 0:
        print("Woohoo, success! Check it out:")
        print_puzzle(puzzle)
        return 1

    square = get_random_square(empty_squares)
    row = square[0]
    col = square[1]

    remaining_values = get_remaining_values(puzzle)

    values = list(remaining_values[col + row * 9])

    while len(values) != 0:
        value = values[int(math.floor(random.random() * len(values)))]
        values.remove(value)
        if forward_check(remaining_values, value, row, col):
            puzzle[row][col] = value
            if solve_btfc(puzzle):
                return 1
            else:
                puzzle[row][col] = 0

    return 0


# Solves the sudoku puzzle using forward checking and 3 heuristics:
# minimum remaining values, degree, and least constraining value heuristics
def solve_btfch(puzzle):
    global nodesVisited
    nodesVisited += 1
    # get a list of the empty squares (remaining variables)
    empty_squares = get_empty_squares(puzzle)

    # if there are no remaining empty squares we're done
    if len(empty_squares) == 0:
        print("Woohoo, success! Check it out:")
        print_puzzle(puzzle)
        return 1

    # find the most constrained square (one with least remaining values)
    remaining_values = get_remaining_values(puzzle)
    mrv_list = []
    [mrv_list.append(len(remaining_values[square[0] * 9 + square[1]])) for square in empty_squares]
    # make a list of the squares with the minimum remaining values (mrv)
    mrv_squares = []
    minimum = min(mrv_list)
    for i in range(len(mrv_list)):
        value = mrv_list[i]
        if value == minimum:
            mrv_squares.append(empty_squares[i])

    # if there are no ties, take the square with the MRV
    if len(mrv_squares) == 1:
        square = mrv_squares[0]
    else:
        # otherwise, find the most constraining variable (variable with highest degree)
        degree_list = []
        for cell in mrv_squares:
            degree = get_degree(cell, puzzle)
            degree_list.append(degree)

            max_degree = max(degree_list)
            max_degree_squares = []
            for i in range(len(degree_list)):
                value = degree_list[i]
                if value == max_degree:
                    max_degree_squares.append(mrv_squares[i])
            # just take the first square as a tie-breaker      
            square = max_degree_squares[0]

    row = square[0]
    col = square[1]

    values = list(remaining_values[col + row * 9])

    while len(values) != 0:

        lcv_list = get_lcv(values, row, col, remaining_values)
        # take the least constraining value
        value = values[lcv_list.index(min(lcv_list))]
        values.remove(value)
        if forward_check(remaining_values, value, row, col):
            puzzle[row][col] = value
            if solve_btfch(puzzle):
                return 1
            else:
                puzzle[row][col] = 0

    return 0


# counts the number of times a value appears in constrained cells
def get_lcv(values, row, col, remaining_values):
    lcv_list = []

    for value in values:
        count = 0
        for i in range(9):
            if i == col:
                continue
            x = remaining_values[row * 9 + i]
            if value in x:
                count += 1

        for i in range(9):
            if i == row:
                continue
            x = remaining_values[col + 9 * i]
            if value in x:
                count += 1

        block_row = int(row / 3)
        block_col = int(col / 3)
        for i in range(3):
            for j in range(3):
                if [block_row * 3 + i, block_col * 3 + j] == [row, col]:
                    continue
                x = remaining_values[block_col * 3 + j + (block_row * 3 + i) * 9]
                if value in x:
                    count += 1

        lcv_list.append(count)

    return lcv_list


# returns the number of variables constrained by the specified square
def get_degree(square, puzzle):
    row = square[0]
    col = square[1]

    degree = 0

    for i in range(9):
        if i == col:
            continue
        if puzzle[row][i] == 0:
            degree += 1

    for i in range(9):
        if i == row:
            continue
        if puzzle[i][col] == 0:
            degree += 1

    block_row = int(row / 3)
    block_col = int(col / 3)
    for i in range(3):
        for j in range(3):
            if [block_row * 3 + i, block_col * 3 + j] == [row, col]:
                continue
            if puzzle[block_row * 3 + i][block_col * 3 + j] == 0:
                degree += 1

    return degree


# checks to see if the value being removed is the only one left
def forward_check(remaining_values, value, row, col):
    for i in range(9):
        if i == col:
            continue

        x = remaining_values[row * 9 + i]

        if len(x) == 1:
            if x[0] == value:
                return 0

    for i in range(9):
        if i == row:
            continue

        x = remaining_values[col + 9 * i]
        if len(x) == 1:
            if x[0] == value:
                return 0

    block_row = int(row / 3)
    block_col = int(col / 3)
    for i in range(3):
        for j in range(3):

            if [block_row * 3 + i, block_col * 3 + j] == [row, col]:
                continue

            x = remaining_values[block_col * 3 + j + (block_row * 3 + i) * 9]
            if len(x) == 1:
                if x[0] == value:
                    return 0
    return 1

# Returns a list of the remaining potential values for each of the 81 squares
# The list is structured row by row with respect to the puzzle
# Only gets called once, at the beginning of the BT-FC search to initialize
def get_remaining_values(puzzle):
    remaining_values = []
    # initialize all remaining values to the full domain
    [remaining_values.append(range(1, 10)) for i in range(81)]
    for row in range(len(puzzle)):
        for col in range(len(puzzle[1])):
            if puzzle[row][col] != 0:
                # remove the value from the constrained squares  
                value = puzzle[row][col]
                remaining_values = remove_values(row, col, value, remaining_values)

    return remaining_values


# Removes the specified value from constrained squares and returns the new list
def remove_values(row, col, value, remaining_values):
    # use a value of zero to indicate that the square is assigned
    remaining_values[col + row * 9] = [0]

    # Remove the specified value from each row, column, and block if it's there
    for x in remaining_values[row * 9:row * 9 + 9]:
        try:
            #x.remove(value)
            x = [i for i in x if i != value]
        except ValueError:
            pass

    for i in range(9):
        try:
            #remaining_values[col + 9 * i].remove(value)
            remaining_values[col + 9 * i] = [i for i in remaining_values[col + 9 * i] if i != value]
        except ValueError:
            pass

    block_row = int(row / 3)
    block_col = int(col / 3)
    for i in range(3):
        for j in range(3):
            try:
                #remaining_values[block_col * 3 + j + (block_row * 3 + i) * 9].remove(value)
                remaining_values[block_col * 3 + j + (block_row * 3 + i) * 9] = [i for i in remaining_values[block_col * 3 + j + (block_row * 3 + i) * 9] if i != value]
            except ValueError:
                pass

    return remaining_values


# return a randomly selected square from the list of empties
def get_random_square(empty_squares):
    # randomly pick one of the empty squares to expand and return it
    return empty_squares[int(math.floor(random.random() * len(empty_squares)))]


# return the list of empty squares indices for the puzzle
def get_empty_squares(puzzle):
    empty_squares = []
    # scan the whole puzzle for empty cells
    for row in range(len(puzzle)):
        for col in range(len(puzzle[1])):
            if puzzle[row][col] == 0:
                empty_squares.append([row, col])
    return empty_squares


# checks the 9x9 block to which the square belongs
def check_block(square, value, puzzle):
    row = square[0]
    col = square[1]
    block_row = int(row / 3)
    block_col = int(col / 3)

    for i in range(3):
        for j in range(3):
            if [i, j] == square:
                continue
            if puzzle[block_row * 3 + i][block_col * 3 + j] == value:
                return 0
    return 1


# checks the row of the specified square for the same value
def check_row(square, value, puzzle):
    row = square[0]
    col = square[1]
    for i in range(len(puzzle)):
        if i == square[0]:
            continue
        if puzzle[row][i] == value:
            return 0

    return 1


# checks the column of the specified square for the same value
def check_col(square, value, puzzle):
    row = square[0]
    col = square[1]
    for i in range(len(puzzle[1])):
        if i == square[1]:
            continue
        if puzzle[i][col] == value:
            return 0

    return 1


def print_puzzle(puzzle):
    for row in puzzle:
        print(row)


def print_help():
    print("Usage: python sudoku.py <difficulty=1,2,3,4> <method=1,2,3>")
    print("Method 1: Backtracking Search")
    print("Method 2: Backtracking with Forward Checking")
    print("Method 3: Backtracking with Forward Checking and Heurisitics")
    # y = input()


if __name__ == "__main__":
    main()
