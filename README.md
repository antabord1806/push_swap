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

I chose the algoritm Turksort, why?
- Since it works directly with the stack nodes, it's easier to visualize;
- It's the least complex algoritm;

This algoritm works in 2 phases: pushing to B and pushing to A, but the "meat" is in what to do before pushing;

1- one must do some parsing of the arguments recieved, reject non numeric char, repeated instances and anything that would overflow the int;

2- Then imedeatly push 2 nodes to B, making sure that theres more then 3 nodes in A;

3- For each number in A I need to find its target in B, that being the number in B that is the closest bigger number, and if there isnt any, the target is the biggest number in B;

` 4
 2
 9
 1

stack A`


## Main challenge

- The greatest challenge in this project was visualizing how the algorithm works during development.
- Sketching out the steps and writing pseudocode helped a lot to understand the logic, organize the operations, and implement the solution efficiently.

