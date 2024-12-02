#include <iostream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

#include "Bridges.h"
#include "DataSource.h"
using namespace bridges;

#include "mergeSort.h"
#include "quickSort.h"

int main(){
  //Intro Message for sorter
  cout << endl;
  cout << "Welcome to Your Subreddit Sorter" << endl;
  cout << "*Enter \"Exit\" anytime to exit the program" << endl << endl;

  //Implement Bridges API
  Bridges bridges(2, "abernich", "997088460878");
  bridges.setTitle("Your Subreddit Sorter");
  DataSource ds (&bridges);

  //Loop for the sorter
  while(true){
    //Get subreddit user wishes to use and associated data if subreddit exists
    string input;
    cout << "Link to Available Subreddits: http://bridges-data-server-reddit.bridgesuncc.org/list" << endl;
    cout << "Enter Subreddit Name: ";
    cin >> input;
    vector<Reddit> redditList;
    vector<Reddit> listForQuick;
    if(input == "Exit")
      break;
    try{
      redditList = ds.getRedditData(input);
      listForQuick = ds.getRedditData(input);
      cout << "Number of Posts: " << redditList.size() << endl << endl;
    }
    catch(const exception& e){
      cout << "Error: Subreddit not found" << endl << endl;
      continue;
    }

    //Get the sorting criteria user wishes to use
    cout << "Which Sorting Criteria Would You Like to Use? (Enter Number)" << endl;
    cout << "1. Score (Upvotes - Downvotes)" << endl;
    cout << "2. Comment Count" << endl;
    cout << "3. Title (Alphabetically)" << endl;
    cout << "4. Vote Ratios (Upvotes/Downvotes)" << endl;
    string choice;
    cin >> choice;
    string sortType;
    if(choice == "Exit")
      break;
    else if(choice == "1"){
      sortType = "score";
    }
    else if(choice == "2"){
      sortType = "commentCount";
    }
    else if(choice == "3"){
      sortType = "title";
    }
    else if(choice == "4"){
      sortType = "voteRatio";
    }
    else{
      cout << "Error: Invalid Choice" << endl;
      cout << "Please Rechoose Subreddit" << endl << endl;
      continue;
    }

    //Call the merge and quick sort functions and time how long they take
    auto start = chrono::high_resolution_clock::now();
    mergeSort(redditList, 0, redditList.size() - 1, sortType);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Merge Sort Time: " << elapsed.count() << " seconds" << endl;

    auto start2 = chrono::high_resolution_clock::now();
    quickSort(listForQuick, 0, listForQuick.size() - 1, sortType);
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed2 = end2 - start2;
    cout << "Quick Sort Time: " << elapsed2.count() << " seconds" << endl;

    //See how many post the user would like to display and diplay them then restart program
    cout << "How many Posts Would You Like to Display? (Enter Number)" << endl;
    cout << "*Must be between 1 and " << redditList.size() << endl;
    string numPosts;
    int num;
    cin >> numPosts;
    if(numPosts == "Exit")
      break;
    try{
      num = stoi(numPosts);
    }
    catch(const exception& e){
      cout << "Error: Invaid Choice" << endl;
      cout << "Please Rechoose Subreddit and Sorting Criteria" << endl << endl; 
      continue;
    }
    if(num < 1 || num > redditList.size()){
      cout << "Error: Invaid Choice" << endl;
      cout << "Please Rechoose Subreddit and Sorting Criteria" << endl << endl; 
      continue;
    }
    else{
      for(int i = 0; i < num; i++){
        cout << "Post " << i + 1 << ": " << redditList[i].getTitle() << endl;
        cout << "Author: " << redditList[i].getAuthor() << endl;
        cout << "Score: " << redditList[i].getScore() << endl;
        cout << "Comment Count: " << redditList[i].getCommentCount() << endl;
        cout << "Vote Ratio: " << redditList[i].getVoteRatio() << endl;
        cout << "URL: " << redditList[i].getURL() << endl << endl;
      }  
    }
  }
  return 0;
}