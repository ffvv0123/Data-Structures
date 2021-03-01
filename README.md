# Data-Structures

### 00. Basic Concepts

# System Life Cycle

### 1. Requirements 
###### Requirements describe the information that we, the programmers, are given input and the results that we must produce output. We must develop rigorous input and output descriptions that include all cases.

### 2. Analysis
###### We begin to break the problem down into manageable pieces. There are two  approaches to analysis: bottom up and top down. Several alternate solutions to the programming problem are developed and compared during this phase.
###### - bottom up: How to find the answer by calling a small question after visiting the biggest question
###### - top down: How to find the answers to the smallest questions and the answers to the whole question

### 3. Design
###### This phase continues the work done in the analysis phase. The desinger approaches the system from the perspectives of both the data objects that the program needs and the operations performed on them. The first perspective leads to the creation of abstract data types, while the second requires the specification of algorithms and a consideration of algorithm design strategies.

### 4. Refinement and coding
###### We choose representations for our data objects and write algorithms for each operation on them.

### 5. Vertification
###### This phase consists of developing correctness proofs for the program, testing the program with a variety of input data, and removing errors.
###### - Correctness proofs: Programs can be proven correct using the same techniques that abound in mathematics.
###### - Testing: Requrires the working code and sets of test data.

# Pointers and dynamic memory allocation
### Pointers
### 
The actual value of a pointer type is an address of memory. There are two most important operators used with the pointer: & and *.

###### - & the address operator
###### - * the dereferencing (or indirection) operator

The size of a pointer can be different on different computers. The null pointer points to no object or function. Typically the null pointer is represented by the integer 0. The C macro NULL is defined to be this constant.
###
### Dynamic Memory Allocation
###
When program you may not know how much space you will need, nor do tou wish to allocate some very large area that may never be required. To solove this problem C provides a mechanism, called a *heap*, for allocating storage at run-time.

- malloc: Function used when new memory space is needed.
- free: Function used when no longer need an area of memory

Whenever you use malloc function, next you request the amount of memory you need. If memory is available, a pointer to the start of an area of memory of the required size is returned. Else, the pointer NULL is returned.

Whenever you use free function, and return the area of memory to the system.

## Once an area of memory is freed, it is improper to use it.

###

----------------------------
### 01. Data Structures and Algorithms

### 
A Data Scrutures is a collection of data values, the realationships among them, and the functions of operations that can be applied to the data.

The algorithm meets the following conditions

- Input: There must be at least 0 inputs.
- Output: There must be at least 1 outputs.
- Definiteness: The meaning of each instruction should be clear and unambiguous.
- Finiteness: It must be terminated after a limited number of steps.
- Effectiveness: Each instruction must be a piece of paper, a pencil, or a computer-enabled operation.

###

### 
# Description of cal_scores.c
######
A program consists of data structures and algorithms.

In this program, data structure is "int scores[MAX_ELEMENT];", algorithm is "largest = scores[0];"
This simple program shows that difference between data structures and algorithms.
######

# 
A data type is a collection of objects and a set of operations that act on those objects.

Abstract Data Types(ADT) represent abstract and mathematical model for data types.

In ADT, what data or operations are defined, but how data or operations will be implemented on computers is not defined.
#

###
- Users can only use the operations provided by ADT.
- Users should know how to use the operations provided by ADT.
- Users cannot access data inside the ADT.
- Users can use ADT even if they do not know how it is implemented.
- Users can still use ADT in the same way if the interface does not change if another person changes the implementation of ADT.

######
### Description of ADT 1-1 추상 자료형 NatNumber.c

This program is example of express natural numbers.
Unlike integers, natural numbers are valid example because its are not provided by default in computers.

It is the same as part of an integer's operation, except that the result of the operation is zero or natural number.
######

# Analyze algorithm performance

### Description of cal_time.c and cal_time1.c

###
In cal_time.c, clock() function calculates the CPU time used by the calling process.
The clock() function returns the system time in CLOCKS_PER_SEC unit when called.
Further details can be found through the comments of the program.

In cal_time1.c, time() function returns the measured time in seconds.
Further details can be found through the comments of the program.

There are a few precautions.

- Performance time cannot be claimed for unexperimented inputs.
- The results may vary depending on the software environment used.
- To compare algorithms through this method, measurement time must be analyzed using the same hardware.

To solve the above problem, we use the concept of a time complexity function.

###

# Time Complexity Function

###
Time complexity does not represent the absolute performance time of the algorithm, but rather how many operations are performed.
The number of operations performed is usually determined by the input value n. Since n is a variable value, it can be represented as a function, which is called the time complexity function T(n).

# Asymptotic Notation

###
- Big O Notaion
- Big Omega Notation
- Big Theta Notation

See Time Complexity Functions.pdf for a description of the notation above.

# The efficiency of the algorithm

### There are three cases.
- worst case: The algorithm takes the longest time to perform among the data sets.
- best case: The algorithm takes the least time to perform among the data sets.
- average case: The average performance time considering all inputs from the algorithm and the probability that each input occurs.

In most cases, we usually use worst case. This is because average case is hard to get, and best case is often meaningless.
