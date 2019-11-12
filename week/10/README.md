# Writeup 10 - Crypto I

## Assignment details

This assignment has three parts. It is due by 11/20/19 at 11:59PM.

**There will be a late penalty of 5% per day late!**

### Part 1 (45 Pts)

Wattsamp Energy has created a ledger that is "perfectly secure" so that they
can keep all of their secrets safe in case of compromise. The bank has done
their best to secure the ledger using mechanisms such as encryption and hashing.
In good mind, they have solicited CMSC389R students' help in auditing the system
so that they can be sure of their system.

The software engineers at Wattsamp have shared their program and all resources required
to build it, as well as their private ledger which has been secured using the program.
Can you determine if there are any vulnerabilities or misuses in the program?

[ledger.c](ledger.c)
[ledger.bin](ledger.bin)

1. What is the structure of the ledger file format? Include exact byte offsets when static.

2. What specific cryptographic implementations are used by the program? I.e. not "hashing", but a specific algorithm. Why might this pose a risk?

3. What information, if any, are you able to derive from [ledger.bin](ledger.bin) without decrypting it at all?

4. How does the application ensure Confidentiality? How is the encryption key derived?

5. How does the application ensure Integrity? Is this flawed in any way?

6. How does the application ensure Authenticity? Is this flawed in any way?

7. How is the initialization vector generated and subsequently stored? Are there any issues with this implementation?

### Part 2 (45 Pts)

It is clear to see that the software engineers at Wattsamp did not make security a priority. Write a program that derives a password capable of decrypting the provided [ledger.bin](ledger.bin), and use this to discover the company's secrets.

1. Develop the crack utility in a language of your choice. We have provided a start file [crack.c](crack.c) because this is the language the ledger program is written in. You can feel free to use the provided crypto files [crypto.c](crypto.c).

We should be able to execute your program as such so as to access the ledger:

./ledger `./crack`

If you are using a language other than C, this may require the use of a [shebang](https://en.wikipedia.org/wiki/Shebang_(Unix)

For full credit, your crack program should **not** be calling the ledger directly. It is okay if your crack program is not instantaneous, but if it is taking so long that you have time to make a cup of tea you are probably doing something unnecessary.

2. What is the flag?

### Part 3 (10 Pts)

There is an argument to be made that intentionally obfuscating the scheme you are using makes it more difficult for attackers to perform attacks. In this particular case, it is certainly true that having access to the ledger's source makes it much easier for an attacker to exploit it. Explain where you think the deal balance lies between [security through obscurity](https://en.wikipedia.org/wiki/Security_through_obscurity) and converse ideologies such as [Kerckhoff's principle](https://en.wikipedia.org/wiki/Kerckhoffs%27s_principle). Examine and refute one counter argument to your point, referencing concrete examples from class.

#### Important notes

Make sure to submit **all** of the code you write, even if based on `crack.c`!

### Scoring

This assignment is worth 100 points, broken down between question answering/analysis (45 points), cracking the file (45 points), and part 3.

### Tips

Remember to document your steps for maximum credit. We want to know how you approached and solved this challenge!

Look at the Crypto I slides for guidance. Specifically, the symmetric key slides and the key takeaway slides.

When writing crack.c, remember that the output of md5_hash will be raw bytes which means that they may not be passable to the ledger binary.

There are no (intentional) vulnerabilities in common.c or crypto.c -- you can look at these files if you want but their headers should be sufficient in understanding exactly how they are used.

You should not have to perform complex math or low-level attacks (such as cracking md5) in any of your solutions.
