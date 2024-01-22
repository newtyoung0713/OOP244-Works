//*****************************************************************************
//  <assessment name example : Workshop - #1 (Part - 2)>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : Jan 24th, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my workshops and assignments.
//*****************************************************************************

#include <iostream>
#include "StMark.h"
#include "file.h"
#include "io.h"
#include "graph.h"
using namespace std;
namespace seneca {
  bool printReport(const char* filename) {
    int i;
    // Open the file and return false if cannot find the file
    if (!openFile(filename)) {
      return false;
    }

    // Array to store the students' info
    StMark stMark[MAX_NO_RECS]{};

    // Read marks and get the maximum number of students from the file
    int noOfSamples = readMarks(stMark);

    // Create an array to store the marks for the graph
    int markValues[MAX_NO_RECS];
    for (i = 0; i < noOfSamples; ++i) {
      markValues[i] = stMark[i].mark;
    }
    // Print graph of the mark distribution
    printGraph(markValues, noOfSamples, "Students' mark distribution");
    bubbleSorting(stMark, noOfSamples);
    // Print the list of students and their marks
    for (i = 0; i < noOfSamples; ++i) {
      printInt((i + 1), 3);
      cout << ": [";
      printInt(stMark[i].mark, 3);
      cout << "] " << stMark[i].name << " " << stMark[i].surname << endl;
    }

    for (i = 0; i < 40; ++i) cout << "-";
    cout << endl;
    
    // Close the file
    closeFile();

    return true;
  }
  
  void bubbleSorting(StMark stMark[], int max) {
    int i, j;
    // Temp struct for swapping student rate by bubble sort
    StMark temp{};
    for (i = 0; i < max - 1; i++) {
      for (j = 0; j < max - i - 1; j++) {
        if (stMark[j].mark < stMark[j + 1].mark) {
          temp = stMark[j];
          stMark[j] = stMark[j + 1];
          stMark[j + 1] = temp;
        }
      }
    }
  }
}