Pentesting I
======

## Assignment details

This assignment has two parts. It is due by 10/11 at 11:59 PM.
To submit your homework, please follow the guidelines on the front page to edit the README in the /writeup folder and push your completed work to GitHub.


**There will be a late penalty of 5% off per day late!**

### Part 1

Download Binary Ninja or IDA community. I find that Binary Ninja has a less
steep learning curve, but the trial version only allows a session to last a
maximum of 30 seconds. I used Binary Ninja but the choice is yours. Ghidra
should not be used for this assignment.

This week's directory contains a binary, 'crackme'. This is a 32-bit ELF file,
built for an x86 machine. Get this program to print a flag in the typical
format.

What is the flag?

### Part 2

Describe the various inputs which you had to provide to the program. From where
did the program read user input? In other words, how did you provide data to the program
so as to impact control flow?

Explain what checks took place. What did the checks have in common? What differed
from check to check?

How was the flag stored in memory? A tool such as 'strings' can be used to locate
contiguous sequences of printable characters in a any file; however, strings
does not succeed at locating the flag in 'crackme'. How do we retrieve the flag
in order to print it?

### Format

Both parts should be written in the same post, clearly separated. Full, grammatical sentences
should be used. Part 1 should just contain the flag, and part 2 should be at least 300 words -- enough to
explain the control flow of the program. There is no penalty for going over these numbers, but there
*is* a penalty for padding your work to meet the minimums.

### Scoring

Part 1 is worth 50 points, and part 2 is worth 50.

### Tips

Reference the slides from lecture 5.

+ Often times it is not efficient to reverse engineer a program from top-to-bottom.
I often skip the intros and outros of functions as they are simply creating memory
space for local variables and performing cleanup.
+ Local variables exist on the stack, and are usually references as an offset of
ebx. Thus, [ebx-0x4] is probably a local variable.
+ It is often productive to use a tool's graphical view to find points of atypical
control flow, and work backwards from these junctures to figure out the inputs
which impact the variables deciding which jumps to take.
+ Look up library functions in the C man pages if you don't understand its return
values, parameters, etc.
+ For the most part, if you aren't able to understand individual lines it might
be helpful to skip them and just return back to them if you later find they're
necessary to understand the program.
+ When I am pushing parameters to a function, they are pushed in reverse order.
For example to call "int add(int x, int y)" I will push y then x.

Good luck!
