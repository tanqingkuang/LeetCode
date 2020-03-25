#include "../interface.h"
#include "math.h"
#if 0
void quickSort(int* arr, int numSize){
    int idx, tmp=0;
    int middle = 0;
    int start = 0,end = numSize-1;
    if(numSize<2){
        return;
    }
    for(idx = 0; idx < numSize; idx++){
        if(arr[idx]<arr[0]){
            middle++;
        }
    }
    while(start < middle){
        if(arr[start] < arr[middle] && arr[end] >= arr[middle]){
            start++;
            end--;
        }
        else if(arr[start] < arr[middle] && arr[end] < arr[middle]){
            start++;
        }
        else if(arr[start] > arr[middle] && arr[end] >= arr[middle]){
            end--;
        }
        else if(arr[start] > arr[middle] && arr[end] < arr[middle]){
            tmp = arr[start];
            arr[start] = arr[end];
            arr[end] = tmp;
        }
    }
    quickSort(&arr[0], middle);
    quickSort(&arr[middle+1], numSize-middle-1);
}


void nextPermutation(int* nums, int numsSize)
{
    int idx = 0;
    int number = 0;
    int count = 1, wei = 0;
    int arr[1000] = {0};
    
    /******判断从第几位开始改变排序，并将需
           要改变的以升序结构放在新的数组中******/
    for(idx = numsSize-2; idx >= 0; idx--){
        if(nums[idx] <= nums[numsSize-1]){
            break;
        }
        else{
            count++;
        }
    }
    for(idx = 0; idx < count; idx++){
        arr[idx] = nums[numsSize-count+idx];
    }
    quickSort(arr, count);

    /******如果已经是降序结构，则直接输出升序数组******/
    for(idx = 0; idx < numsSize; idx++){
        if(nums[idx] >= nums[idx+1]){
            wei++;
        }
    }
    if(wei==numsSize){
        for(idx = 0; idx < count; idx++){
            nums[idx] = arr[idx];
        }
        return;
    }


    for(idx = 0; idx < numsSize; idx++){
        number += nums[idx] * 10^(numsSize-idx-1);
    }


}
#endif

int removeDuplicates(int* nums, int numsSize){
    int newNumsSize = 1;
    int i = 0, j = 0;
    int count = 0;
    if(numsSize == 0){
        return 0;
    }
    if(numsSize == 1){
        return 1;
    }
    if(numsSize == 2){
        if(nums[0] ==nums[1]) {
            return 1;
        }
        else {
            return 2;
        }
    }

     for(i = 1; i<= newNumsSize && i<numsSize; i++){
       if((nums[i] == nums[i-1])){ 
            for(j = i; j <= (numsSize - i); j++){
                nums[j] = nums[j+1];
            }
            i--;
        }
        else{
            newNumsSize++;
        }
        count++;
        if(count >= numsSize){
            return newNumsSize;
        }
    }
    return newNumsSize;
}
