# Writeup 2 - Pentesting

Name: Josiah Rapp
Section: 0101

I pledge on my honor that I have not given or received any unauthorized assistance on this assignment or examination.

Digital acknowledgement: Josiah Rapp

## Assignment Writeup

### Part 1 (45 pts)

I found two flags:
-CMSC389R-{html_h@x0r_lulz}
-CMSC389R-{p1ng_as_a_$erv1c3}

The first flag I obtained snooping around the HTML code of the wattsamp website. It was hidden on the home page near the end of the body element.

The second flag I found was a little more tricky. I started my search by using the command provided 'nc wattsamp 1337' in my home terminal. I was then prompted by the server to enter an IP address to ping. I did that and obtained nothing but some ping data. I then remembered some of what we learned in lecture and also in CMSC330 about command injection. These are the commands I entered:
-'1' (i realized the field required some form of number to actually process the input) + ';ls'
	I was able to successfully list all the libraries of the wattsamp server by concatenating a command after a semi-colon
-'1;ls -alh' 
	I added a '-alh' after the l's' in order to see permissions of the file. However, this had an unintended side effect: it displayed the last time those folders/files were editted. The home directory had the date of september 24th (last tuesday) and was the most recently updated file besides the ones that popped up with today's date.
-'1;cd home'
	I cd'd into the directory but I could not list the contents. I could not figure out how to enter multiple commands, as the shell boots you after either 3 seconds or after you enter anything at all. But through some trial and error I was able to successfully figure out that you can enter a new command after each semi-colon.
-'1;cd home;ls'
	enter the home directory then finally list the contents, which in turn displayed the flag
-'1;cd home;cat flag.txt'
	the final command i entered in order to display the requested flag.

I think Edward should really try and sanitize or whitelist his inputs. Kind of how the admin tab on the wattsamp website makes sure you have no funky or suspicious characters after the @ in the email field. This prevents any user from entering malicious code at the end of a seemingly valid input. Or you know, make a whitelist of users that can connect to his server.

### Part 2 (55 pts)

I wrote a script using python in order to run command injection on the wattsamp server. We had a 216 project that required us to write a shell similar to this one, except in python the syntax is much better, I referenced that a lot while I was writing. This is my second time having to write in python so i was quite confused, but found the language to be quite convenient. 

My shell takes the users input and appends a '1;' to the front of it. This is to initiate the commabnd injection, as the wattsamp server reads the number, pings it, then takes the rest of the input as a command. After the semi colon I inject the command passed into the shell so that the server will execute the command. I then concatenate a new line character at the end of the users input to complete the input.

I could not figure out how to go about download, as you can tell by my code. I overheard some other students talking about utilizing the 'cat' function in order to basically make a copy of the requested file and put it in the local path that is passed in. However, when i attempted to implement this, I could not quite figure out how to properly pass the users requested file locations into the payload.