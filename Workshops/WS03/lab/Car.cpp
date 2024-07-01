//*****************************************************************************
//  <assessment name example : Workshop - #3 (Part - 1)>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : Feb 3rd, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my workshops and assignments.
//*****************************************************************************

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Car.h"
using namespace std;

namespace seneca {
  bool Car::isEmpty() const {
    return (m_makeModel == nullptr || m_makeModel[0] == '\0') ||
           (m_serviceDesc == nullptr || m_serviceDesc[0] == '\0');
  }

  void Car::setEmpty() {
    m_licencePlate[0] = '\0';
    delete[] m_makeModel;
    m_makeModel = nullptr;
    delete[] m_serviceDesc;
    m_serviceDesc = nullptr;
    m_cost = 0.0;
  }

  void Car::deallocateMemory() {
    setEmpty();
  }

  void Car::set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost) {
    setEmpty(); // Initialized everything to empty status

    // Checking the input is valid or not
    if (plateNo[0] != '\0' && carMakeModel != nullptr && carMakeModel[0] != '\0' &&
        serviceDesc != nullptr && serviceDesc[0] != '\0') {
      
      strcpy(m_licencePlate, plateNo);
      m_licencePlate[8] = '\0'; // Ensure null-termination

      // Setting serviceCost to m_cost and using dynamic memory for m_makeModel and m_serviceDesc
      m_makeModel = new char[strlen(carMakeModel) + 1];
      strcpy(m_makeModel, carMakeModel);

      m_serviceDesc = new char[strlen(serviceDesc) + 1];
      strcpy(m_serviceDesc, serviceDesc);

      m_cost = serviceCost;
    }
  }

  void Car::display() const {
    if (!isEmpty()) {
      cout << left << setw(15) << "License Plate:" << right << setw(20) << m_licencePlate << endl;
      cout << left << setw(15) << "Model:" << right << setw(20) << m_makeModel << endl;
      cout << left << setw(15) << "Service Name:" << right << setw(20) << m_serviceDesc << endl;
      cout << left << setw(15) << "Service Cost:" << fixed << setprecision(2) << right << setw(20) << m_cost << endl;
    }
  }
}