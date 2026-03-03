*This project has been created as part of the 42 curriculum by chbenhiz.*

## Description
The Push_swap project is an algorithm and data sorting exercise. The objective is to sort a stack of integers in ascending order using two stacks (A and B) and a very limited set of instructions (sa, pb, ra, rra, etc.). The program must calculate and display the shortest possible sequence of operations to achieve this sorting.

## Instructions
**Compilation:**
A `Makefile` is provided to compile the project. To generate the `push_swap` executable, run the following command at the root of the repository:
`make`

**Execution:**
The program is executed by passing the list of integers to be sorted as arguments. The first argument corresponds to the top of the stack.
Example with separate arguments:
`./push_swap 2 1 3 6 5 8`
Example with a single string of characters:
`./push_swap "2 1 3 6 5 8"`

## Resources
* **Push_swap — The least amount of moves with two stacks (Turkish Algorithm)**: Explanatory article on the cost-calculation sorting algorithm (cheapest node) used in this project.
* **Artificial Intelligence**: AI was used as an assistant to resolve a Git submodule issue with the `libft`, and to provide advice on function splitting to comply with the school's Norm.