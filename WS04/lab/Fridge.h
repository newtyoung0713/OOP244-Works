/***********************************************************************
// OOP244 Workshop #4 p2
//
// File	Fridge.h
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
//*****************************************************************************
//  <assessment name example : Workshop - #4 (Part - 1)>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : Feb 10th, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my workshops and assignments.
//*****************************************************************************
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_FRIDGE_H
#define SENECA_FRIDGE_H

#include <cstring>
#include <iostream>

namespace seneca{

   const int NAME_LEN = 20;
   const int FRIDGE_CAP = 3;

   class Food {
      char m_name[NAME_LEN]{};
      int m_weight{};
   public:
      const char* name()const;
      int weight()const;
      Food();
      Food(const char* nm, int wei);
   };

   class Fridge {
      Food m_foods[FRIDGE_CAP]{}; 
      int m_numFoods{};
      char* m_model{};
   public:
      // The default constructor will initialize the data members to an empty state.
      // The m_numFoods will be set to 0 and the m_model set to nullptr.
      // The array of Food items will initialized by default from the provided Food struct code.
      Fridge();
      // The destructor will deallocate the dynamic memory held by the m_model data member.
      ~Fridge();
      // The 3-argument constructor will initialize the data members using the provided parameters based on the following process:
      // First set the the empty state by utilizing the default constructor and assigning that to the current object
      // Validate the parameters by checking if the nf value is greater than 0 and that mod c-string is not nullptr and not the empty string.
      // If the above validation succeeds:
      // set the m_numFoods to the nf value
      // allocate memory to m_model to store the string in the mod value
      // finally loop over the Food array argument (farr) and copy each Food to the m_foods array up till the nf value or the FRIDGE_CAP is met.
      // The mod parameter will have a default value of "Ice Age".
      Fridge(Food farr[], int nf, const char* mod = "Ice Age");
      // This function will attempt to add a Food item to the m_foods array. 
      // If the m_numFoods is less than the FRIDGE_CAP then assign the parameter Food item 
      // to the m_foods array at the index of m_numFoods. Increment the m_numFoods by 1 
      // to reflect the added Food item.
      // This function returns true 
      // if we have successfully added a Food item and false otherwise.
      bool addFood(const Food& f);
      // This function will modify the model_name of the Fridge using the parameter provided 
      // if it is valid (ie not nullptr or the empty string).
      // If it is valid then first deallocate the memory of 
      // the m_model then allocate enough memory to store the provided value 
      // and copy it to m_model.
      void changeModel(const char* m);
      // This function will return whether or not the Fridge is full. 
      // A Fridge is considered to be full if m_numFoods has reached FRIDGE_CAP.
      bool fullFridge() const;
      // This function will attempt to determine whether this Fridge holds a particular Food item 
      // by comparing its name to the parameter value. 
      // If a Food item is found with the same name then return true otherwise return false.
      bool findFood(const char* f) const;
      // This function will display the details of the Fridge to the ostream parameter named os. 
      // Instead of printing to cout we will be using this os parameter as the destination (cout << myvar vs os << myvar).
      // If the current object's m_model is in an empty state then this function will not print anything and only return.
      std::ostream& display(std::ostream& os = std::cout) const;
   };
}

#endif
