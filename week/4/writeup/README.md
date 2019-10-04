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
	I cd'd into the directory however I could not list the contents. I could not figure out how to enter multiple commands, as the shell boots you after either 3 seconds or after you enter anything at all. But through some trial and error I was able to successfully figure out that you can enter a new command after each semi-colon.
-'1;cd home;ls'
	enter the home directory then finally list the contents, which in turn displayed the flag
-'1;cd home;cat flag.txt'
	the final command i entered in order to display the requested flag.

I think Edward should really try and sanitize or whitelist his inputs. Kind of how the admin tab on the wattsamp website makes sure you have no funky or suspicious characters after the @ in the email field. This prevents any user from entering malicious code at the end of a seemingly valid input. Or you know, make a whitelist of users that can connect to his server.

### Part 2 (55 pts)

*Please use this space to detail your approach and solutions for part 2. Don't forget to upload your completed source code to this /writeup directory as well!*
