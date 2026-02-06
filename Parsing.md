

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
If no parameters are specified, the program must not display anything and give the prompt back.
• In case of error, it must display "Error" followed by a \n on the standard error. Error include, for example: arguments that are not integers, integers outside the valid range, or duplicate values.

Error handled can be from : 
A string or sequence of number that exceed INT limits

User needs to pass as argument of the program a string contatining a sequence of the number or a sequence of strings containing each a specific number

Example 1
Each number is contained in a string and accessed with argv[i]
In this example, argc = 9 and argv[2] = "2"
```bash
./pushswap 5 2 3 6 9 45 -87 -4 

```
	Example of a sequence of string each containing a number


Example 2
Each number is contained in a string and accessed with argv[i]
In this example, there are 9 arguments,  argc = 9 and argv[4] = "25 16 86"


```bash
./pushswap 5 2 3 "25 16 86" 6 9 45 -87 
```
```plaintext
<p style="text-align:center;">
```Example of a sequence of string each containing one or multiple number


A valid string is a string containing :
- any number of spaces is tolerated as long as there are numbers
- number needs to be relative numbers (negative or positive numbers). They can be started by a "-" before only for negative numbers. No other sign or character will be accepted (except for space).
- A space is the characher " " (whose decimal representation is 32 in the ascii table).
-example : +15 is NOT ok, -15 is ok. ab15 or 15ab is not ok
* No duplicate

All invalid string or  sequence of  strings numbers are ERRORS

Conversation
- number will be converted into INT type using *atoi* function. So no number exceeding INT_MAX should be passed.
- 

```text
--input /data/run42 --mode fast --threshold 0.85
```
If the string passed as argument does not respect all the rules above, no stack will be returned





## Functions

### Assert method = check precondition
write a method that checks a precondition and abort the function if it is not met
### check_number_arguments 

input :  number of arguments (int argc)
output : return if program should continue


### get position of options (benchmark and strategy)
precondition : output of check_number_arguments should RUN;
post-condition : position of argument 





## How many numbers maximum can be passed ? 






## Linked list

Every succesfully parsed 




