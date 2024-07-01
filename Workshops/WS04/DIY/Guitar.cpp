/***********************************************************************
// OOP244 Workshop #4 p2: tester program
//
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
//*****************************************************************************
//  <assessment name example : Workshop - #4 (Part - 2)>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : Feb 14th, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my workshops and assignments.
//*****************************************************************************

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Guitar.h"
using namespace std;

namespace seneca{
   const char* GuitarStr::material() const {
      return m_material;
   }
   double GuitarStr::gauge() const {
      return m_gauge;
   }
   GuitarStr::GuitarStr() {};

   GuitarStr::GuitarStr(const char* ma, double ga) {
      strncpy(m_material, ma, MAT_LEN);
      m_gauge = ga;
   };

   Guitar::Guitar(const char *mod) {
      m_strings = nullptr;
      m_numStrings = 0;
      strcpy(m_model, mod);
   }

   Guitar::Guitar(GuitarStr strs[], int ns, const char *mod) {
      if (strs == nullptr || ns <= 0) {
         m_strings = nullptr;
         m_numStrings = 0;
         m_model[0] = '\0';
      } else {
         m_strings = new GuitarStr[ns];
         for (int i = 0; i < ns; ++i) {
            m_strings[i] = strs[i];
         }
         m_numStrings = ns;
         strcpy(m_model, mod);
      }
   }

   Guitar::~Guitar() {
      delete[] m_strings;
      m_strings = nullptr;
   }

   bool Guitar::changeString(const GuitarStr &gs, int sn) {
      if (sn >= 0 && sn < m_numStrings) {
         m_strings[sn] = gs;
         return true;
      }
      return false;
   }

   void Guitar::reString(GuitarStr strs[], int ns) {
      deString();

      m_strings = new GuitarStr[ns];
      for (int i = 0; i < ns; ++i)
         m_strings[i] = strs[i];
      m_numStrings = ns;
   }

   void Guitar::deString() {
      delete[] m_strings;
      m_strings = nullptr;
      m_numStrings = 0;
   }

   bool Guitar::strung() const {
      return m_strings;
   }

   bool Guitar::matchGauge(double ga) const {
      for (int i = 0; i < m_numStrings; ++i) {
         if (m_strings[i].gauge() == ga) {
            return true;
         }
      }
      return false;
   }

   std::ostream& Guitar::display(std::ostream &os) const {
      if (m_numStrings == 0) {
         os << "***Empty Guitar***" << endl;
      } else {
         os << "Guitar Model: " << m_model << endl;
         os << "Strings: " << m_numStrings << endl;

         for (int i = 0; i < m_numStrings; ++i) {
               os << "#" << i + 1;
               os.width(10);
               os << m_strings[i].material() << " | ";
               os << setprecision(1) << m_strings[i].gauge() << endl;
         }
      }
      return os;
   }
}
