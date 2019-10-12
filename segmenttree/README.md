# segment trees

### xenia.cpp
[339D - Xenia and Bit Operations](http://codeforces.com/contest/339/problem/D) </br>
simple segment tree

### knighttournament.cpp
[356A - Knight Tournament](http://codeforces.com/contest/356/problem/A) </br>
Can be solved by segment tree, trick is to inverse input to not overwrite winners and to take minimum of fights in height of the tree. I think solution is O(M log(N) + N log(N)). There are simpler solutions than segment tree, but it's good practice.

### pashmak.cpp
[459D - Pashmak and Parmida's problem](https://codeforces.com/contest/459/problem/D) </br>
Do the prefix and suffix sum. Do an array of number of occurences of each element in suffix sum. The elements are <= 10^9, but there are only 10^6 of them, so the result array is of the size at most 10^6, so we can do a segment tree on it. Segment tree - query operation is taking sums of intervals, modify operations adds one to each node. Even though it's O(nlogn), still barely in the limit - 2.7s, limit is 3s. There are probably better ways to solve it.

### enemyisweak.cpp
[61E - Enemy is weak](https://codeforces.com/contest/61/problem/E) </br>

Map numbers to [0..n-1]. Iterate from right to left and for each number x count numbers smaller than x (on the right in the array), notice that now we have integers from 0 to n, so we can count numbers greater than x that are on left in the array. Number of triplets with x as middle element is greater_left * smaller_right.

### brackets.cpp
[380C - Sereja and Brackets](https://codeforces.com/contest/380/problem/C) </br>

Build 3 trees - with left unmatched brackets, right unmatched brackets and with fully closed brackets

### antcolony.cpp
[474F - Ant Colony](https://codeforces.com/contest/474/problem/F) </br>

Notice that for ant to survive, its strength has to divide all other strengths in the segment (including self), so gcd of the segment has to be equal to ant strength. We build 2 trees - gcd of the segment and nr of elements equal to gcd in the segment. Result is length of segment minus nr of elements equal to gcd. 

### copyingdata.cpp
[292E - Copying Data](https://codeforces.com/contest/292/problem/E) </br>

Build a tree in which in every node you remember if it is a segment from A or B. If it should be "copied" from A, remember at which index in A to start (we have the length of the segment anyway, so don't have to store that). Also remember in which sequence node was updated. On query go through all height of the tree and return value with the highest sequence number. 

### mishapermutations.cpp
[501D - Misha and Permutations Summation](https://codeforces.com/contest/501/problem/D) </br>

Notice that when having n! permutations, those (n - 1)! permutation are repeated n times. And so are (n - 2)! permutations repeated (n - 1) times. They might be repeated with a different set of numbers, but are basically the same. Remap those permutations. For example remap (0 2 4 1 3) -> (0 1 2 0 0). Respectively: 0 is the smallest element in set (0 2 4 1 3), so give it index 0. 2 is second smallest element in set (2 4 1 3), so give it index 1. 4 is the greatest element in set (4 1 3), so give it index 2. And so on. To find this we can use a segment tree. Find how many elements smaller then a[i] are in the tree and then add a[i] to the tree. Add those two arrays (with the remainder). Now we have to remap back. For example (0 1 2 1 0) -> (0 2 4 3 1) (the smallest is 0, remove 0 from set, second smallest from the remainding set (1 2 3 4) is 2 and so on). We can have a segment tree with 1s in the leaves, and remove element at each selected step, we can find in logn the kth smallest element. 