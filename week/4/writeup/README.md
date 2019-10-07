# Writeup 2 - Pentesting

Name: Alex Melvin
Section: *PUT YOUR SECTION NUMBER HERE*

I pledge on my honor that I have not given or received any unauthorized assistance on this assignment or examination.

Digital acknowledgement: *PUT YOUR NAME HERE*

## Assignment Writeup

### Part 1 (45 pts)

I first telneted into the 1337 port of wattsamp.net, receiving a request for an IP address. 

Providing an IP address sends a ping to it. Seeing that giving this response leads to a server ping, I considered that I could try command injection during this interaction with the server

I then made a txt file containing the string “17.*** ; ls” to test if command injection would work. After executing the command nc wattsamp.net 1337 < injection.txt, I saw that the server listed all sub directors of the / directory. 

I then modified my input to see what was inside the home directory; sure enough, there was a file called “flag.txt”. I changed my injection to cat the file, receiving the following flag: 

CMSC389R-{p1ng_as_a_$erv1c3}

Eric should scan all user inputs into the server. Eric can make a blacklist of all characters that should be escaped when scanned, such as “;” to prevent command injections. Also, Eric can add permissions to all commands, so that if anyone accessed the server they would need the root password.

### Part 2 (55 pts)

*Please use this space to detail your approach and solutions for part 2. Don't forget to upload your completed source code to this /writeup directory as well!*
