//*****************************************************************************
//  <assessment name example : Workshop - #10 (Part - 1)>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : Apr 01st, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my workshops and assignments.
//*****************************************************************************

#ifndef SENECA_MATCHPAIR_H
#define SENECA_MATCHPAIR_H

namespace seneca {
  template<typename T, typename U>
  class Pair {
  public:
    T first;
    U second;
  };

  template<typename T, typename U>
  void addDynamicPairElement(Pair<T, U>*& pArray,const T& first, const U& second, int& size) {
    Pair<T, U>* temp = new Pair<T, U>[size + 1];
    for (int k = 0; pArray && k < size; k++) {
      temp[k] = pArray[k];
    }
    temp[size].first = first;
    temp[size].second = second;
    delete[] pArray;
    pArray = temp;
    size++;
  }

  template<typename T, typename U>
  Pair<T, U>* matches(const T* arr1, const U* arr2, int szArr1, int szArr2, int& newSz) {
    Pair<T, U>* pt{nullptr};
    newSz = 0;
    for (int i = 0; i < szArr1; i++) {
      for (int j = 0; j < szArr2; j++) {
        if (arr1[i] == arr2[j]) addDynamicPairElement(pt, arr1[i], arr2[j], newSz);
      }
    }
    return pt;
  }

  template<typename T>
  void releaseMem(T* arr) {
    if (arr) {
      delete[] arr;
      arr = nullptr;
    }
  }
}

#endif  //  !SENECA_MATCHPAIR_H 