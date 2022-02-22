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

## Final Solution (Pre-Algorithm):

---
So, I solved the problem. It's been a while, and I hadn't really thought of the problem at all, really, but I was getting ready to send a funny video to one of my friends (which talked about the anxieties of the technical question interview world) when I realized the contents of the video was *also* about a palindrome. <br>
In the video ([here](https://www.youtube.com/watch?v=bcH9Tq_FG-U)), the interviewee used the stack to determine whether a string was palindromic. So, I thought I might employ the same strategy. As I began working out the bugs, I realized: "Oh, this doesn't quite work as well with numbers as it would strings." I ended up having to reverse the number and create linked lists of that reversed number, and blah blah blah.
<br>
Honestly, though, I'm not mad about it. It's about time I tackled linked lists and recursion for a project like this. This time, I won't cover the details of my solution. Wouldn't you know it, I'm hungry again and I've spent too much time on this problem. The code, however, will be included, like normal. (And it's commented).  
<br>

## The Algorithm: 

---
The algorithm is broken down into roughly two parts. 
<br>
The first highlights the major issue in a typical approach to this problem (that is, using nested while-loops, which inevitably run the same product multiple times).
<br>
The second re-emphasizes what was learned from the previous problem set (i.e., the mathematics behind prime factorization and/or the Fundamental Theorem of Arithmetic.)
<br>
Technically, there is a third point the document made; however, it's not so hard to grasp. It was pointed out that you're likely to get to the solution faster if you start at the highest possible integers (999 * 999). Though, once you arrive at what I've now called the "second part" of the algorithm, *this* part of the algorithm isn't as useful anymore.
<br>
Really, I need only explain the second part of the algorithm; the other two are simply and make logical sense with a bit of thinking. Thus:
<br><br>
First, let me emphasize the purpose of "part two": ***to speed up the algorithm by skipping numbers we would have encountered more than once.***
<br><br>
**How it works:**
<br>
Since we're working with palindromes formed by the product of two three-digit numbers, take the smallest possible palindromic number satisfying these conditions: 111111 (143 * 777). Notice that this number, *N*, has six digits. This will be the sort of "theme" for all of our possible palindromes in the set from `100 - 999, inclusive`. 
<br>
If we break down *N* into a sum of its components, we see that:
> 111,111 = 100,000 + 10,000 + 1,000 + 100 + 10 + 1

The algorithm suggests we can combine some of the components by assigning each of them a variable, letting the variable's value be some number *n*. See below:
> 111,111 = 100,000x + 10,000y + 1,000z + 100z + 10y + x = 100,001x + 10,010y + 1100z

At first, this seemed arbitrary. Why are we following a backwards pattern of `x, y, z, z, y, x`? But if we let all variables `x - z, inclusive` equal `1`, then we see that:
> 111,111 = 100,001 + 10,010 + 1100 = 111,111

Truthfully, I'm not so sure if these choices for `x - z` were arbitrary or simply convenient for the given number. I'm not sure if this is a pattern for every palindrome. Though, this is the only part I fail the algorithm in my understanding. Nonetheless, the rest of it makes perfect sense.
<br><br>
If we take another look at:
> 111,111 = 100,001x + 10,010y + 1100z

We may factor out a prime:
> 111,111 = 11(9091x + 910y + 100z)

Now, what does this tell us? If we recall the Fundamental Theorem of Arithmetic (FTA), it states that any composite/natural number may be regarded as a sum of prime numbers. Intuitively, this makes sense, and since I've covered this in my last problem set, I won't go into terrible detail here. However, a visual aid will help greatly in taking the FTA a slight step further. Consider the factor tree of `1386`:
```asm
//     1386
     
//   2      693
   
//      99      7
      
//    11   9
        
//        3  3
```

Yes, I know it's hard to read, but look at what's happening in the process of breaking a number down into it's prime factors. We see that:
1. Every step down from the root of the tree contains a prime, and
2. Every step has at least one prime number.

Returning to our example, we know that since `11` is prime, we know that **at least one of the two numbers being multiplied together to produce `111,111` is prime.** We'll call these numbers *a* and *b*, for now.
<br>
With that in mind, if *a* is **NOT** divisible by `11`, we know that *b* is. With this, we now know which numbers, *a* and *b*, we need to multiply.
<br>
If it helps, look at the factor tree again. Recall that *every step down from the root of the tree contains a prime.* 
