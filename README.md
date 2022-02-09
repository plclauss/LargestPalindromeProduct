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