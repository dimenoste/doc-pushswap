## Data Structure: Circular Doubly-Linked List

### Why This Structure?

We chose a **circular doubly-linked list** for our stack implementation because:

1. **Linked list** - Preserves a specific order between data points
2. **Doubly-linked** - Allows easy access to both next and previous neighbors, essential for stack operations
3. **Circular** - Simplifies rotate operations by connecting the tail back to the head

![Circular List Structure](https://i.imgur.com/U70meCL.png)
*Figure: Circular doubly-linked list with head and tail connections*

### Implementation

#### Node Structure
```c
typedef struct s_node {
    long          value;      // Integer value to sort
    struct s_node *next;      // Pointer to next node
    struct s_node *previous;  // Pointer to previous node
} t_node;
```

#### Stack Structure
```c
typedef struct s_stack {
    t_node        *head;   // Top of the stack
    t_node        *tail;   // Bottom of the stack
    size_t        length;  // Number of elements
    t_stack_name  name;    // Either 'a' or 'b'
} t_stack;
```

### Key Operations

#### Rotate (ra/rb)
Shifts all elements up by one. The first element becomes the last.
```
head = head->next
tail = head->previous
```

#### Reverse Rotate (rra/rrb)
Shifts all elements down by one. The last element becomes the first.
```
tail = tail->previous
head = tail->next
```

#### Swap (sa/sb)
Swaps the first two elements at the top of the stack.
```c
int temp = stack->head->value;
stack->head->value = stack->head->next->value;
stack->head->next->value = temp;
```

#### Push (pa/pb)
Takes the first element from one stack and puts it at the top of the other.

### Required Functions

- `t_bool is_empty_stack(t_stack *stack)` - Check if stack is empty
- `t_stack *create_empty_stack(void)` - Create an empty stack (for stack B)
- `t_stack *create_stack(int *array, int size)` - Create and populate stack from array
- `void push(t_stack *from, t_stack *to)` - Push operation
- `void swap(t_stack *stack)` - Swap operation
- `void rotate(t_stack *stack)` - Rotate operation
- `void reverse_rotate(t_stack *stack)` - Reverse rotate operation

## Resources

### 1. Doubly-Linked Lists
- [Structures de données - Listes chaînées (French)](http://fdrouillon.free.fr/alldocs/_LivreC_CPP/Chap6_%20Strct%20donnees%20listes%20&%20algo.pdf)
- [Programmation MPI - Listes (French)](https://www.informatique-mpi.fr/files/pdf/chap_7.2.pdf)
- [Wikibooks - Algorithmic Programming (French)](https://fr.wikibooks.org/wiki/Programmation_algorithmique/)
- https://www.geeksforgeeks.org/dsa/applications-advantages-and-disadvantages-of-circular-doubly-linked-list/

**Note:** A doubly-linked list improves complexity for insertion and deletion operations compared to a singly-linked list, while also allowing backward traversal. However, it requires an additional pointer per element.

### 2. Stacks (LIFO)
- [Wikipedia - Last In, First Out](https://fr.wikipedia.org/wiki/Last_in,_first_out)
