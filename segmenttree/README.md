# segment trees

### xenia.cpp
[339D - Xenia and Bit Operations](http://codeforces.com/contest/339/problem/D) </br>
simple segment tree

### knighttournament.cpp
[356A - Knight Tournament](http://codeforces.com/contest/356/problem/A) </br>
Can be solved by segment tree, trick is to inverse input to not overwrite winners and to take minimum of fights in height of the tree. I think solution is O(M log(N) + N log(N)). There are simpler solutions than segment tree, but it's good practice.

### pashmak.cpp
[459D - Pashmak and Parmida's problem](https://codeforces.com/contest/459/problem/D) </br>
Do the prefix and suffix sum. Do an array of number of occurences of each element in suffix sum. The elements are <= 10^9, but there are only 10^6 of them, so the result array is of the size 10^6, so we can do a segment tree on it. Segment tree - query operation is taking sums of intervals, modify operations adds one to each node.

