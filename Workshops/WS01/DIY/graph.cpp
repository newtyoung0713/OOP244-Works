#include <iostream>
#include "io.h"
#include "graph.h"
using namespace std;

namespace seneca{
  // finds the largest sample in the samples array, if it is larger than GRAPH_WIDTH,
  // otherwise it will return GRAPH_WIDTH. 
  int findMax(int samples[], int noOfSamples){
    int max = samples[0];
    int i;
    for (i = 1; i < noOfSamples; i++){
      if (max < samples[i]) max = samples[i];
    }
    return max < GRAPH_WIDTH ? GRAPH_WIDTH : max;
  }

  // Fills the samples array with the statistic samples
  void getSamples(int samples[], int noOfSamples) {
    int i;
    for (i = 0; i < noOfSamples; i++) {
      line(28);
      cout << "\\ " << (i + 1) << "/";
      printInt(noOfSamples, 2);
      cout << ":                    /";
      goBack(20);
      samples[i] = getInt(1, 1000000);
    }
  }

  // prints a scaled bar relevant to the maximum value in samples array
  void printBar(int val, int max) {
    int i;
    int barlength = GRAPH_WIDTH * val / max;
    cout << "| ";
    for (i = 0; i < barlength; i++) {
      cout << "*";
    }
    cout << " ";
    printInt(val, (GRAPH_WIDTH + 6 - barlength));
    cout << "|" << endl;
  }

  // prints a graph comparing the sample values visually 
  void printGraph(int samples[], int noOfSamples, const char* label) {
    const int EACH_GROUP = 10;
    int i{0}, j{0};
    int markGroup[EACH_GROUP]{0}; //  For collection the students' mark into 10 groups
    int max = findMax(samples, noOfSamples);
    //  For group up the students' mark into each group
    for (i = 0; i < noOfSamples; i++) {
      for (j = 1; j <= EACH_GROUP; j++) {
        if (samples[i] > (j - 1) * EACH_GROUP && samples[i] <= j * EACH_GROUP) {
          markGroup[j - 1]++;
        } else if (j == 1 && samples[i] >= 0 && samples[i] <= EACH_GROUP) {
          markGroup[j - 1]++;
        }
      }
    }
    labelLine(GRAPH_WIDTH + 14, label);
    //  Printing each group number and the width
    //  Then make if statement for different file with different number
    for (i = EACH_GROUP - 1; i >= 0; i--) {
      printInt((i + 1) * EACH_GROUP, 4);
      noOfSamples <= GRAPH_WIDTH ?
      printBar(markGroup[i], GRAPH_WIDTH) :
      printBar(markGroup[i], max - 3);
    }
    line(GRAPH_WIDTH + 14);
  }
}