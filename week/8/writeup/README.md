# Writeup 8 - Binaries II

Name: Josiah Rapp
Section: 0101

I pledge on my honor that I have not given or received any unauthorized assistance on this assignment or examination.

Digital acknowledgement: Josiah Rapp

## Assignment Writeup

### Part 1 (100 pts)
Answer the following questions regarding the server executable (for which source is provided).

1. How is the per-session administrator password generated? Are there any inherent weaknesses in this implementation?

	The passwords are generated with a two step process. The first step is to seed a RNG using the current time. The second step loops through an array size 16 (also the size allocated to the password) and uses the return value (random ascii values in hex) of the previously mentioned RNG and modding it with ('z' - ' '). replicable and not the most intense password generation. Fabricating the computers time stamp is an easy way of taking advantage of the vulnerability.

2. Describe two vulnerabilities in this program. Provide specific line numbers and classifications of the vulnerability. Explain potential ramifications as well as ways to avoid these vulnerabilities when writing code.

	The printf(output) on line 46 is a good example of a format string vulnerability. If there was a malicious attacker, they could input a bunch of stack calls (%p) into the input string (which is used to generate the output string that is later printed) printing memory addresses of the stack out into the console which can then be utilized by the attacker. Can be easily avoided by specifying %s (type string) as the format string.

	The second vulnerability is located at line 68, on the gets(buff) statement. This is a potential buffer overflow exploit waiting to happen, and can be prevented by changing gets to fgets.

3. What is the flag?

	CMSC389R-{expl017-2-w1n}

4. Describe the process you followed to obtain the flag: vulnerabilities exploited, your inputs to the server in a human-readable format, etc. If you create any helper code please include it.

	I started by connecting to the server at 'nc ec2-18-222-89-163.us-east-2.compute.amazonaws.com' using port 22 (recalling from lecture that port 22 is the most common). After combing through the lecture slides, I began to parse through the binary file using GDB. I initially tried to print the password to no avail, but inserting a breakpoint where the password was declared gave me more insight. It provided me with the string '%29$f', i tried entering that into the encrypt field, entering that into the authentication stage which did not work. I then did the reverse, decrypted the string and entered that into authentication and that gave me elevated access. I then proceeded to do what most good computer science students do and spam the command line with commands i knew off top. Ls displayed a flag file, however i could not open it, so back to the server.c file i went. I purused the exec_command method since that's what i wanted, to execute a command. There was a buffer that was 32 bits long , so i attempted to enter my "cat flag" command with 25 other characters in order to trigger a buffer overflow. this worked, and the flag stated above was printed out. 

	note: all of my commands were doubled "ls" was "ls ls" and "cat flag" was "cat flag cat flag"
