# Simple Hash Table using Linked Lists

## Author: Arlen Feng

## Description:    
This program includes a hash table implemented with chained hashing along with a test driver. 

## Important Notes:    
1. The program does not currently involve table doubling. 
2. The default size for the hash table is 100, but this can be changed in the header file. 
3. A class template was created for the hash table class, but the hash function currently is designed to work for unsigned integers. 
4. The template was designed so that if other data structures are to be used as keys and/or values, one could easily extend from a specific form of the class template and override the hash function and operators. 

## To build:    
1. Run "make". 

## To run the test driver:    
1. Run "./test.out". 
2. The test driver will test for insert, retrieve, and member (as well as allocated/deallocated memory). 

## Potential Future Improvements    
1. Implement table doubling and rehashing when capacity reaches a certain point (e.g. ~70%)
2. Implement an additional constructor taking in a custom initial number of "buckets"
3. Implement support for more hash functions for different data types
4. Implement support for classes that extend from a class of this template for specific types
5. Make improved test drivers
6. Implement unit tests
7. Document/Comment the code more comprehensively