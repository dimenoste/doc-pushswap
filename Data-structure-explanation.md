
## Data structure choice and explanation
# Double circular linked list

## Why ?

* *Linked list because we want to conserve a particular order between data point*
* Double linked because we will usually operate from one data point to one of his neighbour
* A circular to easily implement rotate operations that are key for most sorting algorithms

## Necessary steps to build a double circular linked
* The first step would be to write a classic double linked list as such in our project.

```
typedef struct s_node
{
	long			value;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;



```
* The second step is to link each node keeping in mind in which stack they belong and their length. 

```
typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	size_t			length;
	t_stack_name	name;
}					t_stack;
```

### Necessary function

* t_bool is_empty_stack(t_stack *lst)
* t_stack *create_stack_empty(size_t length) // pour creer la stack b qui est vide
* t_stack *create_stack(un tableau d'entier depuis le parseur ) 
	* on auras besoin d atoi a en parler avec mehdi


* void push (t_stack *from, t_stack *to);
* void swap (t_stack *stack_name)
```
	int temp;
    temp = stack_name->head->value
	stack_name->head->value = stack_name->head->next->value
	stack_name->head->next->value = temp
```

* void reverse_rotate(t_stack *stack)
		* on rebranche
```
		stack->tail = stack->tail->prev
		stack->head  = stack->tail->next
```

* void rotate(t_stack * stack)
```
stack->head = stack->head->next
stack->tail = stack->head->prev
```
