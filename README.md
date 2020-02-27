# C Dictionary HASH TABLE Implementation

## Purpose 
To provide an implementation of a dictionary, that contains words with their relevant descriptions, and allow the user to   populate it with large amounts of information and still remain searchable in an acceptable and efficient timeframe.

## Program consist of:

* 'Dictionary.h' -> Contains msotly functions prototypes and Constants.
* 'Dictionary.c' -> Conatins the load, size, check, and Unload function.
* 'speller.c'    -> Conatins the main part of the program and the benchmarking method.

## Usage
1. Run the program by entering the following command into the terminal:
    * `./dictionary_run dictionary_1.txt`
    
2. If you make changes, you can recompile the library and test program using:
    * `make` (alternatively you can use: make all or make dictionary_run)

3. To clean the directory once finished, enter the following command into the terminal:
    * `make clean`

4. To rezip the working directory, enter the command:
    * `make zip`
    
## Implementation Notes

The Implementation is backed by a 'HASH TABLE' also referred to as 'HASH MAPS'.

A hash table uses a hash function to compute an index, also called a hash code, into an array of buckets or slots, from which the desired value can be found.

A data structure with almost a constant time search is a hash table, which is a combination of an array and a linked list. We have an array of linked lists, and each linked list in the array has elements of a certain category. 

For example, in the real world we might have lots of nametags, and we might sort them into 26 buckets, one labeled with each letter of the alphabet, so we can find nametags by looking in just one bucket.

An example of the hash table hierarchy is shown below:

![An example hash table][example]
[example]: /diagram.png

A bucket might have multiple matching values, so we’ll use a linked list to store all of them horizontally. (We call this a collision, when two values match in some way.)But in the worst case, all the names might start with the same letter, so we might end up with the equivalent of a single linked list again. We might look at the first two letters, and allocate enough buckets for 26*26 possible hashed values, or even the first three letters, and now we’ll need 26*26*26 buckets. But we could still have a worst case where all our values start with the same three characters, so the running time for search is O(n). In practice, though, we can get closer to O(1) if we have about as many buckets as possible values, especially if we have an ideal hash function, where we can sort our inputs into unique buckets.
