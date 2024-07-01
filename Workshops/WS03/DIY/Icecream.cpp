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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Icecream.h"
using namespace std;

namespace seneca {
  void Icecream::getOrder() {
    string response;
    bool flag{};

    cout << "Select flavour:\n";
    line(16);
    cout << "\n1: Chocolate\n"
         << "2: Strawberry\n"
         << "3: Mango\n"
         << "4: Tutti fruit\n"
         << "5: Almond crunch\n";
    line(16);
    cout << endl;
    do {
      flag = true;
      cout << "> ";
      cin >> m_flavorChoice;
      if (cin.fail()) {
        cleanBuffer();
        cout << "Invalid entry, retry" << endl;
        flag = false;
      } else if (m_flavorChoice < 1 || m_flavorChoice > 5) {
        cout << "Invlid value(1<=val<=5)" << endl;
        flag = false;
      }
    } while (!flag);

    cout << "Number of Scoops (max 3)\n> ";
    do {
      flag = true;
      cin >> m_numScoops;
      if (cin.fail()) {
        cleanBuffer();
        cout << "Invalid entry, retry\n> ";
        flag = false;
      } else if (m_numScoops < 1 || m_numScoops > 3) {
        cout << "Invlid value(1<=val<=3)\n> ";
        flag = false;
      } else {flag = true;}
    } while (!flag);

    cout << "Vanilla wafer cone?\n(Y)es/(N)o > ";
    do {
      flag = true;
      cin >> response;
      m_vanillaWafer = (response == "y" || response == "Y");

      if (response != "y" && response != "n") {
        cleanBuffer();
        cout << "Only Y or N are acceptable:\n> ";
        flag = false;
      } else {flag = true;}
    } while (!flag);
  }

  void Icecream::printOrder() {
    cout << "Order details:";
    cout.width(21);
    cout << "Price" << endl;
    line(35);
    cout << "\nNumber of scoops, " << m_numScoops << " total:";
    cout.width(9);
    cout << fixed << setprecision(2) << m_numScoops * 5.00 << endl;

    if (m_flavorChoice == 1) {
      cout << "Chocolate flavour:";
      cout.width(17);
      cout << m_chocolatePrice << endl;
    } else if (m_flavorChoice == 2) {
      cout << "Strawberry flavour:";
      cout.width(16);
      cout << m_strawberryPrice << endl;
    } else if (m_flavorChoice == 3) {
      cout << "Mango flavour" << endl;
    } else if (m_flavorChoice == 4) {
      cout << "Tutti fruit flavour:";
      cout.width(15);
      cout << m_tuttiFruitPrice << endl;
    } else if (m_flavorChoice == 5) {
      cout << "Almond crunch flavour:";
      cout.width(13);
      cout << m_almondCrunchPrice << endl;
    }

    m_waferPrice = m_vanillaWafer ? 5.00 : 0.00;
    cout << "Vanilla Wafer:";
    cout.width(21);
    cout << m_waferPrice << endl;

    m_price = summaryPrice();
    cout << "Price:";
    cout.width(29);
    cout << m_price << endl;
  }

  double Icecream::summaryPrice() {
    m_price = m_numScoops * 5.00;

    if (m_flavorChoice == 1) m_price += 3.00;
    else if (m_flavorChoice == 2) m_price += 3.00;
    else if (m_flavorChoice == 4) m_price += 2.50;
    else if (m_flavorChoice == 5) m_price += 5.00;

    if (m_vanillaWafer) m_price += 5.00;
    m_subTotal = m_price;
    return m_subTotal;
  }

  void Icecream::line(size_t numOfLine) const { for (size_t i = 0; i < numOfLine; i++) {cout << '-';} }
  
  void Icecream::cleanBuffer() const {
    cin.clear();            // Clean error buffer
    cin.ignore(1000, '\n'); // Ignore the wrong input
  }
}