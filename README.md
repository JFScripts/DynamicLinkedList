# Dynamic Linked List in C

This repository is dedicated to an assignment from my Data Structures II class. The objective was to take a simple linked list and transform it into a dynamic linked list.

## Project Overview

In this project, I refactored a simple linked list into a dynamic (doubly) linked list. The implementation supports the following operations:

- **Insertion:** Adding nodes to the beginning of the list.
- **Deletion:** Removing nodes based on their value.
- **Search:** Finding nodes by their stored value.
- **Display:** Printing the list and showing each node's previous and next pointers.

## Original Code

The original simple linked list implementation provided by my professor can be found in:

📂     DynamicLinkedList/

   >📄 Projeto(listaencadeadadinamica).c

## Modifications & Improvements

The improved dynamic linked list now includes:

✅ Doubly Linked List: Each node has both next and prev pointers.

✅ Memory Safety: Proper dynamic memory allocation and deallocation.

✅ Flexible Operations: Insert, delete, search, and print functions.

## Features

- **Dynamic Memory Allocation:** Nodes are created and freed dynamically.
- **Doubly Linked List:** Each node has pointers to both the previous and the next node.
- **Basic Operations:** Insert, remove, search, and display functionalities are implemented.

## Files

- **main.c:** Contains the implementation of the dynamic linked list.
- **Projeto(listaencadeadadinamica).c** Original professor's code
- **README.md:** This file, which explains the project.

## Requirements

- A C compiler (e.g., `gcc`).
- A compatible development environment (Linux, macOS, or Windows with appropriate tools).

## How to Compile and Run

1. Open your terminal and navigate to the repository directory.
2. Compile the program using a C compiler. For example, with gcc:

   gcc main.c -o dynamic_linked_list

3. Run the executable:

   ./dynamic_linked_list

## Description

This project implements a dynamic linked list in C, featuring:

- **Initialization:** Starting with an empty list.
- **Insertion:** Adding nodes at the beginning of the list.
- **Deletion:** Removing nodes by their value, with proper adjustment of pointers.
- **Display:** Printing the list and showing both the previous and next pointers for each node.
- **Memory Management:** Freeing all allocated memory to prevent leaks.

This assignment helped deepen my understanding of dynamic memory management and data structures in C.

## License

Feel free to use and modify the code as needed.
