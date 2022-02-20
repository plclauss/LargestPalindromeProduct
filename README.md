# Project Euler: Problem 4 - Largest Palindrome Product

---
## First Thoughts:

Our goal is to find the largest palindromic number from the product of two 3-digit numbers. This *sounds* fairly easy, but time will tell.<br><br>
I'm thinking of at least two functions: <br>
`isPalindrome()`, which will be passed in the product of two random 3-digit numbers and determine if it's a palindrome, <br>
and some other function which multiplies two 3-digit numbers, and passes the product into `isPalindrome()`.<br><br>
Since we're looking for the largest palindromic number, I believe we can just start with both numbers at `999` and decrement until we find a palindromic number.<br>
The simplest possible approach would be a nested for-loop, so that's what I will do.
<br>

## Update on First Thoughts:

---
After working through some bugs, I figured it best to take a different approach. Here's what I did, though: <br>
From main I called `int product()`, which contained a double for-loop where `i = 999` and `j = 998`, decrementing both by 1. Inside the nested for-loop was a call to `int createList(int prod)`, which took the product of `i*j`, and put each digit into an `int*` array. <br>
Glossing over some details, `createList` called `void isPalindrome(int* arr, int arrSize)`, which used another nested for-loop to determine whether the number was a palindrome.<br><br>
This did not work, but there's probably some bugs I haven't worked out yet. Though, I will probably revamp the whole solution, as I didn't spend as much time sitting and thinking about the problem as I would've liked. <br>
For now, it's lunchtime, and I have other school work to attend to.

## Update 2:

---
So, I solved the problem. It's been a while, and I hadn't really thought of the problem at all, really, but I was getting ready to send a funny video to one of my friends (which talked about the anxieties of the technical question interview world) when I realized the contents of the video was *also* about a palindrome. <br>
In the video ([here](https://www.youtube.com/watch?v=bcH9Tq_FG-U)), the interviewee used the stack to determine whether a string was palindromic. So, I thought I might employ the same strategy. As I began working out the bugs, I realized: "Oh, this doesn't quite work as well with numbers as it would strings." I ended up having to reverse the number and create linked lists of that reversed number, and blah blah blah.
<br>
Honestly, though, I'm not mad about it. It's about time I tackled linked lists and recursion for a project like this. This time, I won't cover the details of my solution. Wouldn't you know it, I'm hungry again and I've spent too much time on this problem. The code, however, will be included, like normal. (And it's commented).  