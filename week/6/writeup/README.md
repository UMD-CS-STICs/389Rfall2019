# Writeup 6 - Binaries I

Name: Josiah Rapp
Section: 0101

I pledge on my honor that I have not given or received any unauthorized assistance on this assignment or examination.

Digital acknowledgement: Josiah Rapp

## Assignment Writeup

### Part 1 (50 pts)

CMSC389R-{di5a55_0r_d13}

### Part 2 (50 pts)

There were 3 checks I had to clear in order to obtain this flag. I started this process by running './crackme' to get my bearings. Nothing happened as expected and i proceeded to run binary ninja on the c file. I decided to start with the main method at the direction of one of the professors, and followed the comparison branches labled 'cmp'. From my limited 216 and 411 knowledge I was able to deduce that there were some string comparisons taking place within the last line of the main method. On an incorrect comparison, it would branch right, and a correct comparison would branch left. Obviously I wanted a correct answer so i proceeded left. Reading this block helped me understand some of what the code did: it was a lot of shifting around of registers and pointer arithmetic to pass certain variables around, but most importantly, calling a function called 'update_flag'. check1 seems to do a strcmp between some register and "Oh God". I ran './crackme "Oh God"' successfully which cleared the first check and updated the flag, which was stored in a register. Check2 required a little more thinking; i noticed there was a getenv call, but couldnt figure out why or what it did. Research led me to learn about environments as a whole and understand that the assembly was trying to retrieve the value of a certain environment named FOOBAR. i ran the command 'export FOOBAR = ""' (which makes a new environment) and ran './crackme' again. It did not pass the check as the value it was comparing too was incorrect, so i tried 'export FOOBAR="seye ym "'. This also did not work, i analyzed the add and comparison statements and realized that the desired string shown after the check2 call was backwards, resulting in 'export FOOBAR=" my eyes"' and cleared the check/updated the flag. check3 ran open, which opens a file named 'sesame' and reads it byte by byte, specifically with a switch statement analyzing each character of a string and comparing it to a hex value. I converted said hex value into ASCII to reveal it was equality checking " they burn". I entered 'nano sesame' into the command line, entered " they burn" into the file and saved it. I then ran './crackme "Oh God"' one last time that revealed the flag above.
