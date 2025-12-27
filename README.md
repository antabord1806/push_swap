# push_swap

## About the project

- **Objective**: Writing a C program that uses the least amount of moves to sort a stack of integers. To do so I have o implement a sorting algoritm that uses a specified move set and i can also make use of one etra empty stack.
- **Must have**: Before starting the project, one must get familiarized with the concept of algortimic complexity

## Allowed operations

- `sa`, `sb`, `ss`: Swap the first two elements of the stack.
- `pa`, `pb`: Move the top element from one stack to the other.
- `ra`, `rb`, `rr`: Rotate all elements upwards.
- `rra`, `rrb`, `rrr`: Rotate all elements downwards.

## How it works

`make`

- The program receives the numbers as command-line arguments.
`./push_swap 9 1 6 4 2`

- It runs the sorting algorithm and prints the sequence of operations performed to sort the list.
`./push_swap 9 1 6 4 2
pb
pb
sa
rra
pa
pa
ra
pa`

## My approach

In order to complete this project one must get to know th concept of algoritm complexity;



## Main challenge

- The greatest challenge in this project was visualizing how the algorithm works during development.
- Sketching out the steps and writing pseudocode helped a lot to understand the logic, organize the operations, and implement the solution efficiently.

