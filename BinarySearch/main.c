//
//  main.c
//  BinarySearch
//
//  Created by Abegael Jackson on 2015-05-05.
//  Copyright (c) 2015 Abegael Jackson. All rights reserved.
//

#include <stdio.h>

struct range {
    int firstOccurance;
    int numberOfOccurances;
};

struct range binarySearch (int target, int numberArray[], int minIndex, int maxIndex);

int main(int argc, const char * argv[]) {
    
    int target;
    target = 27
;
    int numberArray[10] = {3,6,9,11,11,11,14,16,22,24,24,27,31};
    int arraySize = sizeof(numberArray)/sizeof(int);
    
    struct range result = binarySearch(target, numberArray, 0, arraySize);
    
    if  (result.firstOccurance == -1) {
        printf("Target not found in array.\n");
    }
    else {
        printf("The target is first found at index %d and occurs %d times.\n", result.firstOccurance, result.numberOfOccurances);
    }
    
    return 0;
}


struct range binarySearch (int target, int numberArray[], int minIndex, int maxIndex){
    int midpointLocation = (minIndex + maxIndex) / 2;
    
    while (maxIndex >= minIndex) {  // midpoint may be same as maxIndex or minIndex
        if (target < numberArray[midpointLocation]) {
            maxIndex = midpointLocation - 1;
            midpointLocation = (minIndex + maxIndex) / 2;
        }
        else if (target > numberArray[midpointLocation]) {
            minIndex = midpointLocation + 1;
            midpointLocation = (minIndex + maxIndex) / 2;
        }
        else {
            int currentIndex = midpointLocation;
            while (numberArray[currentIndex] == target) {
                currentIndex--;
            }
            
            ++currentIndex;
            struct range index;
            index.firstOccurance = currentIndex;
            index.numberOfOccurances = 0;
            
            
            while (numberArray[currentIndex] == target) {
                ++index.numberOfOccurances;
                ++currentIndex;
            }
            
            return index;
            
        }
    }
    
    struct range result;
    result.firstOccurance = -1;
    result.numberOfOccurances = 0;
    
    return result;
    
}


/* Part 1
 
 int BinarySearch (int target, int numberArray[], int minIndex, int maxIndex){
 
 int midpointLocation = (minIndex + maxIndex) / 2;
 
 while (maxIndex >= minIndex) {  // midpoint may be same as maxIndex or minIndex
 if (target < numberArray[midpointLocation]) {
 maxIndex = midpointLocation - 1;
 midpointLocation = (minIndex + maxIndex) / 2;
 }
 else if (target > numberArray[midpointLocation]) {
 minIndex = midpointLocation + 1;
 midpointLocation = (minIndex + maxIndex) / 2;
 }
 else {
 return midpointLocation;
 }
 }
 
 return -1;
 
 }
 */