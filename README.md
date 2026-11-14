# TP Lab 2 and 3 in DSA3

Lab work for the DSA3 module, L2 Computer Science, at ESST. Semester 3, Dr. B. Bessaa. Everything is written in C.

## Lab 2, linked lists

The subject is in `Lab-2-1.pdf`.

- `Lab2-1.c` singly linked lists. Create a list with LIFO and with FIFO, display it, delete a value, delete duplicates, check if a list is a prefix of another.
- `Lab2-2.c` doubly linked list. Create, display, delete a value, right rotation, check if a list is a suffix of another.
- `Lab2-3.c` circular linked list. Builds the word made of A, B and C step by step (A becomes BAC, B becomes CAB, C is deleted) and prints it at each step.

## Lab 3, stacks and queues

The subject is in `Lab-3.pdf`.

- `Lab3-1.c` stack functions. Create, display, count occurrences of a value, delete the multiples of a value, reverse the last K elements, check if a stack is a prefix of another.
- `Lab3-2.c` the same functions for a queue.
- `Lab3-3.c` reverses the first K elements of a queue.
- `LibStackQueue.c` stack and queue code used by the Lab 3 files.

`TP Lab 3.cbp` is the Code::Blocks project file.

## Compiling

Each Lab file has its own main, so compile them one at a time:

```
gcc Lab2-1.c -o lab2-1
./lab2-1
```

On Windows PowerShell the second line is `.\lab2-1.exe`.

If a Lab 3 file doesn't compile on its own, put `LibStackQueue.c` in the same folder.
