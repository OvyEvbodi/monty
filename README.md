## Monty Language Interpreter
***
#### Introduction
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project was to create an interpreter for Monty ByteCodes files.<br>
This project implements the stack and queue data structures, via a toggle feature, to interpret  operations, according to the user's preference.
##### Monty byte code files
Files containing Monty byte codes usually have the .m extension.<br>
Example: ``ovy.m``<br>
Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line.<br>
There can be any number of spaces before or after the opcode and its argument:<br>
Example: ``push 68``<br>
Example: ``     pop``<br>
Monty byte code files can contain blank lines, be empty, or consist of only spaces. Any additional text after the opcode or its required argument is not taken into account:<br>
Example: ``pint in reverse``
***

***
#### Installation
To build this progam:
- Clone this repository, and navigate into it
```shell
git clone git@github.com:OvyEvbodi/monty.git && cd monty
````
- Run this [Makefile](https://github.com/OvyEvbodi/monty/blob/master/Makefile)

##### Usage
The monty program is invoked by calling its name, and passing a monty bytecode file as an argument.
Example: ``./monty <file>``
<br>

**The stack opcode**
- The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program.

`Usage: stack`<br>
<br>
**The queue opcode**
- The opcode queue sets the format of the data to a queue (FIFO).

`Usage: queue`
<br><br>
When switching between modes:<br>

- The top of the stack becomes the front of the queue
- The front of the queue becomes the top of the stack<br>

###### Comments
When the first non-space character of a line is `#`, that line is treated as a comment.

###### Errors
The monty program runs the bytecodes line by line and stop if either:
it executed properly every line of the file
it finds an error in the file
an error occured<br>
Examples:
- If the user does not specify any file or more than one argument to the program, the error message ``USAGE: monty file`` is printed, followed by a new line, and the program is exited with the status EXIT_FAILURE<br>
- If an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>,
and the program fails.

***
#### Permitted Operations
Below, are the opodes for all valid operations that can be interpreted, and performed by the monty language interpreter:
|  opcode    |           Function                               |
|  -----:    | :----------------------------------------------- |
| `push <n>` | Pushes an integer `n` onto the stack/queue       |
| `pop`      | Pops an integer off the stack/queue              |
| `pint`     | Prints the next integer from the stack/queue     |
| `pall`     | Prints all the integers on the stack/queue       |
| `add`      | Replaces the two next integers by the result of their addition|
| `sub`      | Replaces the two next integers by the result of their subtraction|
| `mul`      | Replaces the two next integers by the result of their multiplication|
| `div`      | Replaces the two next integers by the result of their division|
| `swap`     | Swaps the top two elements of the stack/queue
| `nop`      | Does nothing
| `mod`      | Computes the rest of the division of the second top element of the stack/queue by the top element of the stack'queue
| `pchar`    | Prints the char at the top of the stack/queue
| `pstr`     | Prints the string starting at the top of the stack/queue
| `rotl`     | The top element of the stack/queue becomes the last one, and the second top element of the stack/queue becomes the first one
| `rotr`     | The last element of the stack/queue becomes the top element of the stack/queue
| `stack`    | Switches to a stack data structure (LIFO)
| `queue`    | Switches to a queue data structure (FIFO)

**Notes**
For pstr:
The string stops when either:
- The stack is over
- The value of the element is 0
- The value of the element is not in the ascii table
***
##### Examples
- To push an integer ``5`` onto the stack/queue, the following line should be included in the ``.m`` file:<br>
``push 5``
- To print all the elements on a stack/queue, the following line should be included in the ``.m`` file:<br>
``pall``
- To toggle between the stack and queue data structures, simply write ``stack`` or ``queue`` as required.
line 1: ``stack``
line 2: ``push 3``
line 3: ``queue``
line 4: ``push 4``
***
#### Authors
[Ovy Evbodi](https://github.com/OvyEvbodi)
***
#### License
This project is licensed under the MIT License.See [LICENSE](https://github.com/OvyEvbodi/monty/blob/master/LICENSE) for full text.