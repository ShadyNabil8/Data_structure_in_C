# Stack data structure in C

One of the main features of this stack is that it can carry any datatype because The stack is an array of void pointers that point to the pushed data. So the only requirement for anyone using this stack is making the right casting to get the data correctly.

The other feature of this stack is that you can push many elements to the stack at once using a variadic function. You just pass the number of elements and a pointers to these elements. There are mechanisms to handle the errors like number of arguments that may be larger than the stack.


## The stack structure has:

- pointer to the data located in the heap
- Vairable carries the maximum number of elements that the stack can carry.
- Variable carries the index of the first elements in the stack.


## Features

- Function to create the stack
- Function to push elements
- Function to pop elements
- Function to check the status of the stack
- Functions to destroy the stack
- Function to change the size of the stack dynamically
- Function to empty the stack
- Function to print the stack