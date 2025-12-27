# push_swap

## About the project

- **Objective**: Sort a list of integers using only restricted operations between two stacks (A and B).
- **Challenge**: Minimize the number of moves required for sorting, following the project's specific rules.

## How it works

- The program receives the numbers as command-line arguments.
- It runs the sorting algorithm and prints the sequence of operations performed to sort the list.

## Algorithm used

- **Turksort**: This algorithm divides the list into smaller parts, sorts each part, and then combines them, reducing the total number of operations.

## Allowed operations

- `sa`, `sb`, `ss`: Swap the first two elements of the stack.
- `pa`, `pb`: Move the top element from one stack to the other.
- `ra`, `rb`, `rr`: Rotate all elements upwards.
- `rra`, `rrb`, `rrr`: Rotate all elements downwards.

## Main challenge

- The greatest challenge in this project was visualizing how the algorithm works during development.
- Sketching out the steps and writing pseudocode helped a lot to understand the logic, organize the operations, and implement the solution efficiently.

