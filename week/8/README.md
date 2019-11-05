Binaries II
======

## Assignment details

This assignment has one part. It is due 11/4 at 11:59pm.
To submit your homework, please follow the guidelines on the front page to edit the README in the /writeup folder and push your completed work to GitHub.


**There will be a late penalty of 5% off per day late!**

### Part 1 (100 pts)
Answer the following questions regarding the server executable (for which source is provided).

1. How is the per-session administrator password generated? Are there any inherent weaknesses in this implementation?

2. Describe two vulnerabilities in this program. Provide specific line numbers and classifications of the vulnerability. Explain potential ramifications as well as ways to avoid these vulnerabilities when writing code.

3. What is the flag?

4. Describe the process you followed to obtain the flag: vulnerabilities exploited, your inputs to the server in a human-readable format, etc. If you create any helper code please include it.


### Tips
Before even bothering to connect to the remote host, try running and attacking
the binary locally. Determine the steps that you would have to follow to locate
and dump a flag from the remote server. You are given both the source and the
compiled binaries: it will be immensely helpful to you to either a) run
program in GDB to get an idea of what's going on or b) add print statements
to the binary to confirm your idea of what's going on. If you edit / recompile
the file, it may not produce the exact same binary. As such, you should make
sure that any attack you execute works on the original binary.

Break the problem down into subcomponents. What is my objective? How can I get closer to that?
What functions will I have to call to do so? What inputs will I have to provide to these functions?

Good luck!
