//*****************************************************************************
//  <assessment name example : Workshop - #3 (Part - 2)>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : Feb 07th, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my workshops and assignments.
//*****************************************************************************

#ifndef SENECA_ICECREAM_H
#define SENECA_ICECREAM_H
#include <iostream>
namespace seneca {
  class Icecream {
    int m_flavorChoice{};
    int m_numScoops{};
    bool m_vanillaWafer{};
    double m_chocolatePrice{3.00};
    double m_strawberryPrice{3.00};
    double m_tuttiFruitPrice{2.50};
    double m_almondCrunchPrice{5.00};
    double m_waferPrice{};
    double m_price{};
    double m_subTotal{};
  public:
    void getOrder();
    void printOrder();
    double summaryPrice();
    void line(size_t numOfLine) const;
    void cleanBuffer() const;
  };
}
#endif // !SENECA_ICECREAM_H