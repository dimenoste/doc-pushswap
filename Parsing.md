

GOAL

transform the argument passed to the program into a well formatted sequence of number.
If the string is valid. a linked list containing all the numbers inside the string is created. 
## Parsing of the numbers 

3 arguments must be passed, one mandatory and two optionals :
- mandatory : the sequence of numbers to sort
- optional : the strategy selector among {--simple, --medium, --complex, --adaptive }
- 

ALL scenarios taken into account :

### 1st scenario :
No list numbers is 
User needs to pass as argument of the program a string contatining a sequence of the number.

A valid string is a string containing :
- any number of spaces is tolerated as long as there are numbers
- number needs to be relative numbers (negative or positive numbers). They can be started by a "-" before only for negative numbers. No other sign or character will be accepted (except for space).
- A space is the characher " " (whose decimal representation is 32 in the ascii table).
-example : +15 is NOT ok, -15 is ok. ab15 or 15ab is not ok

Conversation
- number will be converted into INT type using *atoi* function. So no number exceeding INT_MAX should be passed.

```text
--input /data/run42 --mode fast --threshold 0.85
```
If the string passed as argument does not respect all the rules above, no stack will be returned


## How many numbers maximum can be passed ? 


## Linked list

Every succesfully parsed 




