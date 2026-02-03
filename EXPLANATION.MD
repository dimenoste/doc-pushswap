# Push Swap - Data Structure Implementation

*This project has been created as part of the 42 curriculum by yaichi and mberraho*

## Project Overview

Push Swap is a sorting algorithm project that uses two stacks (A and B) and a limited set of operations to sort integers efficiently. The goal is to sort stack A using the minimum number of operations.

## Data Structure: Circular Doubly-Linked List

### Design Choice

We implemented our stacks using a **circular doubly-linked list** for three key reasons:

1. **Doubly-linked**: Provides O(1) access to both next and previous elements, essential for bidirectional operations
2. **Circular**: Eliminates special cases for head/tail operations and enables O(1) rotations
3. **Maintains head and tail pointers**: Direct access to both ends of the stack without traversal

![Circular List Structure](doubly660x177.jpg)

The circular property means that `tail->next` points to `head`, and `head->previous` points to `tail`, forming a closed loop. This allows rotation operations to simply move the head/tail pointers without traversing or modifying the list structure.

### Structure Definitions

```c
typedef struct s_node {
    long          value;      // Integer value to sort
    struct s_node *next;      // Pointer to next node
    struct s_node *previous;  // Pointer to previous node
} t_node;

typedef struct s_stack {
    t_node        *head;      // Top of the stack (first element)
    t_node        *tail;      // Bottom of the stack (last element)
    size_t        length;     // Number of elements (maintained for O(1) access)
    t_stack_name  name;       // Stack identifier (A or B)
} t_stack;
```

## Implementation Details

### Core Operations

All operations maintain the circular structure's invariants:
- If `length > 0`: `tail->next == head` and `head->previous == tail`
- If `length == 0`: both `head` and `tail` are `NULL`
- If `length == 1`: `head == tail` and the node points to itself

### Operations Complexity

| Operation | Complexity | Implementation |
|-----------|------------|----------------|
| `swap` (sa/sb) | O(1) | Swaps values of first two nodes |
| `push` (pa/pb) | O(1) | Removes from one stack, adds to another |
| `rotate` (ra/rb) | O(1) | `head = head->next; tail = head->previous` |
| `reverse_rotate` (rra/rrb) | O(1) | `tail = tail->previous; head = tail->next` |

The circular structure is what makes rotations O(1). In a traditional doubly-linked list, rotation would require traversing to the tail, but here we simply move pointers.

### Rotation Example

For a stack `[A, B, C]` (where A is at the top):

**Rotate (ra):**
```
Before: head → A ↔ B ↔ C ↔ (back to A)
                   ↑________|
After:  head → B ↔ C ↔ A ↔ (back to B)
```
Implementation: `head = head->next` (O(1))

**Reverse Rotate (rra):**
```
Before: head → A ↔ B ↔ C ↔ (back to A)
After:  head → C ↔ A ↔ B ↔ (back to C)
```
Implementation: `tail = tail->previous; head = tail->next` (O(1))

## Key Design Decisions

### 1. Swap Values, Not Nodes

The `swap` operation exchanges values rather than manipulating node pointers:

```c
temp = stack->head->value;
stack->head->value = stack->head->next->value;
stack->head->next->value = temp;
```

**Rationale**: Simpler implementation, no pointer manipulation required, and sufficient for this project's needs.

### 2. Node Isolation in `stack_pop_front`

When a node is popped, its `next` and `previous` pointers are set to `NULL` to clearly indicate it's detached from any stack. The node must be reintegrated using `stack_add_front` or `stack_add_back`, which properly restore the circular structure.

### 3. Length Tracking

We maintain a `length` field in the stack structure rather than counting nodes. This provides O(1) length queries, which are frequently needed for algorithm decisions and edge case handling.

## File Organization

```
push_swap/
├── stack_init.c          # Stack and node creation/destruction
├── stack_ops.c           # Basic stack operations (add, pop)
├── stack_helpers.c       # Utility functions (length, empty check)
├── operations_swap.c     # sa, sb, ss, pa, pb
├── operations_rotate.c   # ra, rb, rr, rra, rrb, rrr
├── operations_list.c     # Operations recording and printing
└── push_swap.h           # Header file with all prototypes
```

Each file contains at most 5 functions to comply with 42 Norm requirements except the make file and test_main.c


## Resources

### Data Structures
- [Circular Doubly Linked List - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/applications-advantages-and-disadvantages-of-circular-doubly-linked-list/)
- [Insertion at Beginning - GeeksforGeeks](https://www.geeksforgeeks.org/problems/insertion-at-the-beginning-of-circular-linked-list/1)
- [Structures de données - Listes chaînées (French)](http://fdrouillon.free.fr/alldocs/_LivreC_CPP/Chap6_%20Strct%20donnees%20listes%20&%20algo.pdf)

### Algorithms
- [Selection Sort - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/)
- [Last In, First Out - Wikipedia (French)](https://fr.wikipedia.org/wiki/Last_in,_first_out)



## Testing

To test the basic operations:

```bash
# Compile
make

# Test with small input
./push_swap 3 2 1

# Test with checker (if available)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

## Notes for Reviewers

- All operations maintain the circular structure's invariants
- Rotation complexity is O(1) thanks to the circular property
- The `push` operation uses `stack_pop_front` then `stack_add_front`, both O(1)
- Edge cases (empty stack, single element) are handled in each operation
- Memory is properly freed in `clear_stack` after breaking the circular link

---

*For implementation details and code documentation, refer to the comments in each source file.*
