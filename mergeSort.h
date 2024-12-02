#include <iostream>
#include <vector>
using namespace std;

//Merge Sort code from Module 6 Slides
//Implementation of merge function
void merge(vector<Reddit>& arr, int left, int mid, int right, string sortType){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    vector<Reddit> leftVec(leftSize);
    vector<Reddit> rightVec(rightSize);
    for(int i = 0; i < leftSize; i++){
        leftVec[i] = arr[left + i];
    }
    for(int i = 0; i < rightSize; i++){
        rightVec[i] = arr[mid + 1 + i];
    }
    int leftPtr = 0, rightPtr = 0;
    int mergedPtr = left;
    while(leftPtr < leftSize && rightPtr < rightSize){
        if(sortType == "score"){
            if(leftVec[leftPtr].getScore() >= rightVec[rightPtr].getScore())
                arr[mergedPtr++] = leftVec[leftPtr++];
            else
                arr[mergedPtr++] = rightVec[rightPtr++];
        }
        else if(sortType == "commentCount"){
            if(leftVec[leftPtr].getCommentCount() >= rightVec[rightPtr].getCommentCount())
                arr[mergedPtr++] = leftVec[leftPtr++];
            else
                arr[mergedPtr++] = rightVec[rightPtr++];
        }
        else if(sortType == "title"){
            if(leftVec[leftPtr].getTitle() <= rightVec[rightPtr].getTitle())
                arr[mergedPtr++] = leftVec[leftPtr++];
            else
                arr[mergedPtr++] = rightVec[rightPtr++];
        }
        else if(sortType == "voteRatio"){
            if(leftVec[leftPtr].getVoteRatio() >= rightVec[rightPtr].getVoteRatio())
                arr[mergedPtr++] = leftVec[leftPtr++];
            else
                arr[mergedPtr++] = rightVec[rightPtr++];
        }
    }
    while(leftPtr < leftSize){
        arr[mergedPtr++] = leftVec[leftPtr++];
    }
    while(rightPtr < rightSize){
        arr[mergedPtr++] = rightVec[rightPtr++];
    }
}

//Implementation of mergeSort function
void mergeSort(vector<Reddit>& arr, int left, int right, string sortType){
    if(left < right){
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, sortType);
        mergeSort(arr, mid + 1, right, sortType);
        merge(arr, left, mid, right, sortType);
    }
}