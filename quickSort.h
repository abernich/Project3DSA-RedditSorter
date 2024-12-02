#include <iostream>
#include <vector>
using namespace std;

//Quick Sort Code from 6 Slides
//Implementation of partition function
int partition(vector<Reddit>& arr, int low, int high, string sortType){
  double pivot;
  string pivot2;
  if(sortType == "score")
    pivot = arr[low].getScore();
  else if(sortType == "commentCount")
    pivot = arr[low].getCommentCount();
  else if(sortType == "title")
    pivot2 = arr[low].getTitle();
  else if(sortType == "voteRatio")
    pivot = arr[low].getVoteRatio();
  int up = low, down = high;
  while(up < down){
      if(sortType == "score"){
        for(int j = up; j < high; j++){
          if(arr[up].getScore() < pivot)
            break;
          up++;
        }
        for(int j = high; j > low; j--){
          if(arr[down].getScore() > pivot)
            break;
          down--;
        }
        if(up < down)
          swap(arr[up], arr[down]);
      }
      else if(sortType == "commentCount"){
          for(int j = up; j < high; j++){
            if(arr[up].getCommentCount() < pivot)
              break;
            up++;
          }
          for(int j = high; j > low; j--){
            if(arr[down].getCommentCount() > pivot)
              break;
            down--;
          }
          if(up < down)
            swap(arr[up], arr[down]);
      }
      else if(sortType == "title"){
          for(int j = up; j < high; j++){
            if(arr[up].getTitle() > pivot2)
              break;
            up++;
          }
          for(int j = high; j > low; j--){
            if(arr[down].getTitle() < pivot2)
              break;
            down--;
          }
          if(up < down)
            swap(arr[up], arr[down]);
      }
       else if(sortType == "voteRatio"){
          for(int j = up; j < high; j++){
            if(arr[up].getVoteRatio() < pivot)
              break;
            up++;
          }
          for(int j = high; j > low; j--){
            if(arr[down].getVoteRatio() > pivot)
              break;
            down--;
          }
          if(up < down)
            swap(arr[up], arr[down]);
      }
  }
  swap(arr[low], arr[down]);
  return down;
}

//Implementation of quickSort function
void quickSort(vector<Reddit>& arr, int low, int high, string sortType){
  if(low < high)
  {
      int pivot = partition(arr, low, high, sortType);
      quickSort(arr, low, pivot - 1, sortType);
      quickSort(arr, pivot + 1, high, sortType);
  }
}