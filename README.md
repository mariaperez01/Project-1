# Project-1

In this readme we will explain how to run each code of each exercise.

## Problem 2

You should first open the file "Problem2a" on your favourite C++ compiler, compile it, link it and execute it. It will generate a file named "test.txt" with values for x and the function u(x). Once you have done it, you have to open the file "Problem2b" on your Python compiler and run it. You will get a plot of the funtion u(x) in a .pdf format.


## Problem 6

You should first open the file "Problem6.cpp" and copy the code inside to the compiler of your choice. Once you've done it, you can introduce the dimension n of the solution v you want to get, any matrix you want(introducing the three vectors that correspond to the three diagonals and the vector g. If you omit this last step, the program will still work, because there is already an example with n=10 in it. After that, you should compile it, link it (including the armadillo extension) and execute it. You are supposed to receive as a feedback the solution v.


## Problem 7

### Section a

You should open the file "Problem7a.cpp" and copy the code that can be found inside in you compiler. Next you can introduce the dimension n of the solution v you want to get (n = 100 is already set as an example). Then you should compile the program, link it (making sure that you have already installed the armadillo extension) and execute it. You should get the solution v and corresponding x printed on screen as well as writen on a file called "vx_solution.txt" (_ stands for the dimension n).

### Section b

First, you should open the file "Problem7b.py", copy the code inside the file in your Python compiler. Then you have to make sure that the diferent files "vx_solution.txt" are in the same folder. In this code the values of the dimension n that are used are the following ones: 10, 100, 1000 and 100000. Once you execute the code you will get diferent plots that compares our numeric solutions for different values of n aiganst the exact solution for u(x) in Eq.2. This plots will be generated in a .pdf format.

## Problem 8

### Section a

You should open the file "Problem8a(graphics).py" on your Python compiler and run it once you have saved the different "vx_solution.txt" in the same folder (_ stands for any of these numbers 10, 100, 1000, 10000 and 100000). You will get a plot of the errors in a .pdf format. This plot represents the logarithm (in base ten) of the absolute error against x for each n.

### Section b

You should open the file "Problem8b(graphics).py" on your Python compiler and run it once you have saved the diferent "vx_solution.txt" in the same folder (_ stands for any of these numbers 10, 100, 1000, 10000 and 100000). You will get a plot of the errors in a .pdf format. This plot represents the logarithm (in base ten) of the relative error against x for each n.

### Section c

You should open the file "Problem8b(table).py" on your Python compiler and run it once you have saved the diferent "vx_solution.txt" in the same folder (_ stands for any of these numbers 10, 100, 1000, 10000 and 100000). You will get an array with the maximun relative error for each n=10^i, where i is the position of each value of the array (starting in 1).


## Problem 9

You should open the file "Problem9.cpp" and copy the code inside to a compiler. Then you have to compile it, link it (making sure that you have installed the armadillo extension) and execute it. After this, you will get the solution vector v.

## Problem 10

For this program you should open the file "Problem10.cpp", copy the code inside to the compiler of your choice, compile it, link it(including the armadillo extension) and execute it. You are supposed to receive as feedback two vector with the timings that each code has used. You'll also receive a .txt document with both vectors. Each time that you run the code, you'll receive slightly different results.
