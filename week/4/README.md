Pentesting I
======

## Assignment details

This assignment has two parts. It is due by 10/4 at 11:59 PM.
To submit your homework, please follow the guidelines on the front page to edit the README in the /writeup folder and push your completed work to GitHub.

Some information you might find helpful for this assignment can be found [here.](https://www.owasp.org/index.php/Command_Injection)


**There will be a late penalty of 5% off per day late!**

### Part 1

Eric Norman has set up a remote server for performing uptime lookups, to make sure people can always access his new energy website at the modern and sophisticated URL: http://wattsamp.net. He's pretty sure this service is secure, since all it does is run a Linux `ping` command - there's nothing nefarious about performing ICMP requests!

Apparently, Erics's service is vulnerable, however, to *command injection.* Can you find the vulnerability? There might be a flag in it for you!

`$ nc wattsamp.net 1337`

For full credit, write up (step-by-step) how you got the flag and what Elizabeth should do to protect from this vulnerability.

You will earn full credit for answering these questions:

    * The right flag
    * Showing what input you used to obtain the flag.
    * Describing your thought process.
    * Any suggested precautions ejnorman84 could implement to prevent this vulnerability?

### Part 2

Using the provided [stub code](stub.py), implement an interactive shell that leverages the above vulnerability.

You want to be able to conduct the following actions (by calling their respective commands) in this shell:

1) `shell`                               Drop into an interactive shell and allow users to gracefully `exit`
2) `pull <remote-path> <local-path>`     Download files
3) `help`                                Shows this help menu
4) `quit`                                Quit the shell

If any malformed input occurs, be sure to show this usage function.

Note: If you choose to write your own program in another language, please include instructions on how to execute your program including what version of the language you are using. Please add this detail to a README.txt or README.md file. You will NOT receive credit if the TAs cannot run your program.

Note: If you are stuck on this part of the assignment, please let us know. The facilitator staff is open to releasing hints, though we reserve the right to deny releasing specific hints if we deem it appropriate.

Note: Here's a [screenshot](shellimg.png) of what we roughly expect. I'll post a simple "public test" for which you will be graded on. Kindly bear with us here, we're trying something new :)


### Format

Both parts should be written in the same post, clearly separated. Full, grammatical sentences
should be used. Part 1 should be at least 300 words, and part 2 should be at least 200. There
is no penalty for going over these numbers, but there *is* a penalty for padding your work to meet
the minimums.

### Scoring

Part 1 is worth 45 points, and part 2 is worth 55.

### Tips

Reference the slides from lecture 4.


Good luck!
