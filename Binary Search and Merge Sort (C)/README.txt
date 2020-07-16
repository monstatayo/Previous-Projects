This assignment demonstrates my ability to write a program that utilized merge sort and binary search.

Prompt:

Problem Scenario

Jeff planned to travel some places during his spring break. However, due to the recent outbreak of the novel
Coronavirus, he has canceled his travel plan and decided to stay home. However, as he enjoys coding, he
wants spend some part his break on coding. He has received a file with several points (x,y) where the virus
cases are found. He wants to write a code that can filter out the points closer to him and then he wants to
make an efficient search system that can search a point (x,y) from the filtered list. He knows that binary
search runs in O(log2 n) which is much faster than a linear search. However, in-order to apply binary search,
he needs to sort the points first. He learned about Merge Sort Algorithm recently and decided to apply Merge
sort algorithm to sort the points of interest.

Problem formulation:

Given the center coordinate point (x,y) and the radius of a circle. Then there are N numbers of coordinate
points also provided as part of the data. You have to filter out all the points those are inside or on the line of
the circle. Next, you have to apply merge sort to sort those filtered points in x-axis major order. If two points
have same x, then you should sort them based on y. After sorting, your program should continuously prompt
the user for an input coordinate point x and y values and your program should perform binary search to
determine whether the point exists in the given list of points or not. If the point is found, the program should
show the position of the number in the filtered sorted list. The program stops taking further search key input
if the provided value of x is -999 or y is -999. Keep reading the next paragraphs for better understanding.

Required Input/Output format:

The inputs related to the circle and points are taken from a text file called in.txt (create your own example
in.txt file or copy them from the example bellow). You have to read the text file (in.txt) for reading the
points. The first line of the file contains 4 numbers separated by space. The numbers are x coordinate of the 
center of the circle, y coordinate of the center of the circle, r the radius of the circle, and N that says how
many points are there in the file. The next N lines of the file contain x and y coordinate values. Note that all
the numbers in this file are integer. They can be both negative and positive numbers (except the radius).
After reading the data, you have to filter all the points inside or on the line of the circle. Let us call it filtered
list. Next, you have to sort those filtered points in x-axis major order (it means that the data will be sorted
based on x first, if multiple point has same x, then it will sort based on y) and then write the output into
another file (out.txt) in the same format, i.e., each line contains one coordinate point x and y and they are
space delimited. After writing the sorted points in the file, your program should display the message “filtered
and sorted data written to out.txt”. After that your program should continuously prompt the user for an input
coordinate point x and y values and your program should perform binary search to determine whether the
point exists in the given list of points. If it is found, it should show “Found” and record number within the
filtered list. The program will stop prompting for x and y, if the search input x=-999 or y=-999