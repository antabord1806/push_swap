# push_swap

## About the Project

* **Objective**: Write a C program that sorts a stack of integers using the **minimum number of operations**. The program must implement a sorting algorithm that operates on a restricted set of moves and may use **one extra empty stack**.
* **Must-have**: Before starting the project, it is essential to understand the concept of **algorithmic complexity**.


## Allowed Operations

* `sa`, `sb`, `ss` — Swap the first two elements of a stack.
* `pa`, `pb` — Push the top element from one stack to the other.
* `ra`, `rb`, `rr` — Rotate all elements upwards.
* `rra`, `rrb`, `rrr` — Rotate all elements downwards.


## How It Works

```bash
git@github.com:antabord1806/push_swap.git push_swap
```

```bash
cd push_swap
```

```bash
make
```

The program receives the numbers as command-line arguments:

```bash
./push_swap 9 1 6 4 2 8 10
```

It then runs the sorting algorithm and prints the sequence of operations required to sort the stack:

```bash
pb
pb
rr
rra
rb
pb
rr
rra
pb
ra
pa
rra
pa
rra
pa
rra
pa
rra
rra
rra
pa
```


## My Approach

I chose the **Turksort** algorithm for the following reasons:

* It operates directly on stack nodes, making it easier to visualize.
* It has relatively low algorithmic complexity.

The algorithm works in **two main phases**: pushing elements to stack **B** and then pushing them back to stack **A**. However, the core complexity lies in deciding *when* and *what* to push.

### Step-by-step

1. **Input parsing**: Validate the arguments by rejecting non-numeric characters, duplicate values, and numbers that overflow an `int`.

2. **Initial setup**: Push two nodes from stack **A** to stack **B**, ensuring that at least three nodes remain in **A**.

3. **Selecting target (A → B)**: For each number in **A**, determine its target in **B**. The target is the closest larger number in **B**; if none exists, the target is the largest number in **B**.

4. **Calculation cost**: For each `(number, target)` pair, compute the cost to bring both nodes to the top of their respective stacks. The algorithm accounts for whether nodes are in the first or second half of a stack, since this affects whether rotations (`ra`) or reverse rotations (`rra`) are cheaper. When possible, combined operations such as `rr` or `rrr` are used to reduce the total number of moves.

5. **Push cheapest node**: Push the node with the lowest calculated cost to stack **B** and repeat the process until only three nodes remain in **A**.

6. **Sort 3 nodes nodes**: Sort the three remaining nodes in **A** using a simple bubble-sort-like logic.

7. **Selecting target (B → A)**: For each number in **B**, find its target in **A**. This time, the target is the closest smaller number; if none exists, the smallest number in **A**.

8. **Final merge**: Rotate stack **A** so that each target is on top, then push all elements from **B** back to **A**.


## Limitations of My Approach

While this algorithm performs very efficiently with smaller input sizes, it does not scale as well for larger datasets. This is mainly because some combined operations are not fully accounted for during cost calculation, which can lead the algorithm to select suboptimal node pairs. Improving this aspect is a goal for future work.

<p align="center">
 <img src="assets/pus swap 100 nbr.gif" alt="graph1" width="400">
 <img src="assets/push swap 500 nbr.gif" alt="graph2" width="400">
</p>

## Main Challenge

* The biggest challenge in this project was **visualizing the algorithm’s behavior during execution**.
* Sketching diagrams, breaking down steps, and writing pseudocode were essential to understanding the logic, organizing operations, and implementing the solution correctly.


## Closing Remarks

This project was an excellent opportunity to deepen my understanding of sorting algorithms and algorithmic complexity. It also helped me significantly improve my skills in implementing and working with **linked lists** in C.



