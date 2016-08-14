# MaxSubArray
COMS2004 Project: Maximum Subarray sum algorithm analysis

You are required to research 3 algorithms that solve this problem:
1. The Brute force/Naïve Method
2. The Divide and Conquer Method 3. Kadane’s Algorithm
There are two important submissions for this assignment: a code submission, where you simply submit all of your code you used for the analysis; and a writeup, where you state the details of the experiment. Your experiment writeup should address the following:
• The hardware used in the experiment (this includes the CPU, RAM, e.t.c.)
• The software tools used (this includes Gnuplot, G++, e.t.c.)
• The empirical and theoretical complexities of all 3 algorithms and state why they behave the way they do
• The main data structures used in each implementation
• An evaluation of input array sizes from 0- 30 000
• Each array should contain randomly generated values in the range -50 to 50. (use std::rand())
• a graphical comparison between the algorithms
Your written document should not be more than 1 page and bonus marks will be given for students who use L TEX. One document should be submitted per group. Your program output should look something like this:

"
Input Size  Brute Force     Divide and Conquer  Kadane’s Algorithm
101         2               1                   1
201         14              9                   2
301         76              13                  2
401         108             21                  3
501         190             55                  3
601         296             33                  3
701         641             49                  3
801         612             44                  3
901         825             53                  4
1001        1020            58                  4
1101        1256            65                  4
1201        1557            75                  5
1301        1365            81                  5
1401        2154            88                  6
...         ...             ...                 ...
33201       1.44158e+06     2811                79
33301       1.41839e+06     2894                81
33401       1.42892e+06     2539                95
33501       1.42674e+06     2755                81
33601       1.44132e+06     2768                81
33701       1.43997e+06     2777                77
33801       1.45012e+06     3154                97
33901       1.47716e+06     2586                109
34001       1.47672e+06     2803                75
34101       1.51964e+06     3231                102
34201       1.49281e+06     2928                81
34301       1.50697e+06     3035                90
"

When you plot the log-log graph using gnuplot. Your graphs should be very spiky, account for this ’spikiness’ in your written document. You can smooth-out your graphs by calculating the average of every n consecutive values (the sliding window) in your time-series data. This is known as the moving average or rolling mean. Calculate the moving average for each algorithm’s time-series and plot the new ’average’ time-series data. Your graphs should be much smoother now, account for your choice of window size in your written document.

Additional Reading
1. Geeks for Geeks: Maximum Subarray Sum
http://www.geeksforgeeks.org/divide-and-conquer-maximum-sum-subarray/

2. Gnuplot Homepage
http://www.gnuplot.info

3. Wiki: Maximum subarray problem
https://en.wikipedia.org/wiki/Maximum_subarray_problem

4. Writing a Simple L TEXDocument
http://www.electronics.oulu.fi/latex/examples/example_1/

5. Moving Average WIKI 6. Recursion
https://en.wikipedia.org/wiki/Moving_average

7. Getting Gnuplot on Xubuntu
https://en.wikipedia.org/wiki/Moving_average

DOCUMENTATION:

Doxygen code documentation and dependency diagrams can be found by through doc/html/index.html (this page)

USAGE:

./main [number and max length of input arrays]

Running the main executable (intended to be compiled with the executable name main) with a required input value ( the number, and maximum length of the input arrays or random integers).

LICENCE:

This software project was developed as part of an undergraduate degree course at the University of the Witswatersand. It makes use of standard C++ libraries and was developed using Apple's XCode 7.3,the Clang/g++ compiler, along with macVIM and other open-source software. Where applicable, the code contained in the project that is not already subject to academic and copyright restrictions of the applicable copyright holder is intended to be distributed under the MIT License (MIT): Copyright © 2016 Tyson Cross and University of the Witwatersrand

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
