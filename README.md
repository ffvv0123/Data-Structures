# Data-Structures
# Documents for studying data structures

### 01. Data Structures and Algorithms

###### A Data Scrutures is a collection of data values, the realationships among them, and the functions of operations that can be applied to the data.

###
The algorithm meets the following conditions

- Input: There must be at least 0 inputs.
- Output: There must be at least 1 outputs.
- Obviousness: The meaning of each instruction should be clear and unambiguous.
- Finiteness: It must be terminated after a limited number of steps.
- Validity: Each instruction must be a piece of paper, a pencil, or a computer-enabled operation.

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

# Time Complexity
