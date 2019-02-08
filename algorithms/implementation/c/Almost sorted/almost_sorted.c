
/*******************************************************
 * Copyright (C) 2019 Ivin Basil Roy
 *
 * This file is the solution to the question:
 * https://www.hackerrank.com/challenges/almost-sorted/problem
 * Used single loop to achieve O(n)
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int arr_size;
    scanf("%d\n",&arr_size);
    int input[arr_size];
    int startIndex=-1;
    int endIndex=-1;
    int count=0;
    if(arr_size==2){ // Array size equal to 2
        scanf("%d %d",&input[0],&input[1]);
        if(input[0]>input[1]){ // Result for 'yes'condition 
            printf("yes\n");
            printf("swap 1 2\n"); 
            return 0; 
        }else{                // Result for already sorted
            printf("yes\n");
            return 0;   
        }
    }else{
        scanf("%d ",&input[0]); // Scan first element
        for(int i=1;i<arr_size;i++){
            scanf("%d ",&input[i]); // scan remaining element
            if(input[i-1]>input[i]){
                if(startIndex==-1){
                    startIndex=i-1;
                    count++;
                }else{
                    endIndex=i;
                    count++;
                }
            }          
        }

        if(count==0){  // Already sorted array
            printf("yes\n");
            return 0;  
        }

       if(count==1){   // next two element swap 
           /*if((startIndex<arr_size-1 && input[startIndex]>input[startIndex+1]) || (startIndex<arr_size-2 && input[startIndex]>input[startIndex+1] && input[startIndex]<input[startIndex+2])){
                endIndex=startIndex+1;
                count++;
            } */
            if( input[startIndex]-input[startIndex+1]==1){
                endIndex=startIndex+1;
                count++;
            }     
        } 

        if(count>2){   // Adjust the count 
            count++;
        }
    }
    if(count==1){  // Result of one element without pair
        printf("no\n");
    }else if(count==2){  // Result of two elements with pair
      if(input[endIndex]<=input[startIndex+1] && input[startIndex]>=input[endIndex-1] ){ // If the array sorted after swap
        printf("yes\n");
        printf("swap %d %d\n",startIndex+1,endIndex+1);
      }else{  // If the array didn't sort after swap
        printf("no\n");
      }
    }else{ // Result of more than 2 elements
        for(int j=startIndex;j<endIndex;j++){
           if(input[j]<input[j+1]){
             printf("no\n");
             return 0;
           }
        }
      // Result of reverse 
        printf("yes\n");
        printf("reverse %d %d\n",startIndex+1,endIndex+1);
    }
    return 0;
}

