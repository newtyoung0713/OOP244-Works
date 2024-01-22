#ifndef SENECA_GRAPH_H // replace with relevant names
#define SENECA_GRAPH_H
namespace seneca{

// Your header file content goes here

// Maximum number of samples in an graph
const int MAX_NO_OF_SAMPLES = 20; 
const int GRAPH_WIDTH = 65;
// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples);
// Finds the largest sample in the samples array, if it is larger than 70,
// Otherwise it will return 70. 
int findMax(int samples[], int noOfSamples);
// Prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max);
// Prints a graph comparing the sample values visually 
void printGraph(int samples[], int noOfSamples, const char* label);

}
#endif