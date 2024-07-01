//*****************************************************************************
//  <assessment name example : Workshop - #6 (Part - 1)>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : Feb 21st, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my workshops and assignments.
//*****************************************************************************
/***********************************************************************
// OOP244 Workshop # 6
//
// File: EmailFile.cpp
// Version 1.0
// Date:
// Author: Sina Talebi Moghaddam
// Description
// This file must be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <cstring>
#include "EmailFile.h"

using namespace std;
namespace seneca
{

    Email& Email::operator=(const Email& rhs) {

        if (this != &rhs && rhs.m_email && rhs.m_name) {
            delete[] m_email;
            m_email = nullptr;
            m_email = new char[strlen(rhs.m_email) + 1];
            strcpy(m_email, rhs.m_email);
            delete[] m_name;
            m_name = nullptr;
            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(m_name, rhs.m_name);
            strcpy(m_year, rhs.m_year);
        }

        return *this;
    }

    bool Email::load(std::ifstream& in) {

        char buffer[BUFFER_SIZE];
        bool result = false;

        if (in.getline(buffer, BUFFER_SIZE, ',')) {
            delete[] m_email;
            m_email = new char[strlen(buffer) + 1];
            strcpy(m_email, buffer);

            if (in.getline(buffer, BUFFER_SIZE, ',')) {
                delete[] m_name;
                m_name = new char[strlen(buffer) + 1];
                strcpy(m_name, buffer);

                if (in.getline(buffer, BUFFER_SIZE, '\n')) {
                    strcpy(m_year, buffer);
                    result = true;
                }
            }
        }

        return result;
    }

   Email::~Email() {
      delete[] m_name;
      delete[] m_email;
   }

    void EmailFile::setFilename(const char* filename)
    {
        delete[] m_filename;
        m_filename = nullptr;
        if (filename)
        {
            m_filename = new char[strlen(filename) + 1];
            m_filename[0] = '\0';
            strcpy(m_filename, filename);
        }
    }

    void EmailFile::setEmpty()
    {
        delete[] m_emailLines;
        delete[] m_filename;
        m_emailLines = nullptr;
        m_filename = nullptr;
        m_noOfEmails = 0;
    }

    bool EmailFile::setNoOfEmails() {

        bool isValid = false;
        ifstream file(m_filename);

        if (!file.is_open()) {
            cout << "Failed to open file: " << m_filename << endl;
        }
        else
        {
            m_noOfEmails = 0;
            while (file) {
                m_noOfEmails += (file.get() == '\n');
            }
            file.close();

            if (m_noOfEmails == 0)
            {
                delete[] m_filename;
                m_filename = nullptr;
            }
            else {
                m_noOfEmails++;
                isValid = true;
            }
        }
        return isValid;
    }

    //////////  Implement
    // Creates an empty EmailFile and sets it to a safe empty state.
    EmailFile::EmailFile() : m_emailLines(nullptr), m_filename(nullptr), m_noOfEmails(0) {}
    /* If the input argument is nullptr sets the EmailFile object to a safe empty state. 
    Otherwise, it will set the filename, 
    set the m_noOfEmails and finally load the Emails 
    (using the corresponding private methods.) */
    EmailFile::EmailFile(const char* filename) {
      if (filename == nullptr) {
        m_emailLines = nullptr;
        m_filename = nullptr;
        m_noOfEmails = 0;
      } else {
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
      }

    }
    // Implement rule of three
    EmailFile::EmailFile(const EmailFile& uneAutre) {
      setFilename(uneAutre.m_filename);
      m_emailLines = uneAutre.m_emailLines;
      m_noOfEmails = uneAutre.m_noOfEmails;
    }
    EmailFile& EmailFile::operator=(const EmailFile& uneAutre) {
      if (this != &uneAutre && uneAutre.m_emailLines && uneAutre.m_filename) {
        delete[] m_emailLines;
        m_emailLines = nullptr;
        m_emailLines = uneAutre.m_emailLines;
        delete[] m_filename;
        m_filename = nullptr;
        m_filename = new char[strlen(uneAutre.m_filename) + 1];
        strcpy(m_filename, uneAutre.m_filename);
        m_noOfEmails = uneAutre.m_noOfEmails;
      }
      return *this;
    }
    EmailFile::~EmailFile() {
      setEmpty();
    }
    // Implement rule of three
    // Load the file m_filename into a dynamic array of Emails pointed by m_emailLines
    void EmailFile::loadEmails() {
      ifstream importFile(m_filename);
      if (!importFile.is_open()) {
        cout << "Failed to open file: " << m_filename << endl;
      } else {
        m_noOfEmails = 0;
        while (importFile.ignore(10000, '\n')) m_noOfEmails++;
        importFile.clear();
        importFile.seekg(0,ios::beg);
        m_emailLines = new Email[m_noOfEmails];
        for (int i = 0; i < m_noOfEmails; i++) {
          importFile.getline(m_emailLines[i].m_email, 255, ',');
          importFile.getline(m_emailLines[i].m_name, 255, ',');
          importFile.getline(m_emailLines[i].m_year, 5, '\n');
        }
      }
      importFile.close();
    }
    /* Returns true if the EmailFile is not in an empty state 
    and returns false if it is. */
    EmailFile::operator bool()const {
      return m_filename && m_noOfEmails;
    }
    /* This method takes a Cstring as an input argument 
    and tries to save email information to this file. 
    It gives back a simple 'yes' (true) or 'no' (false) if it could open the file or not.
        First, it tries to create or open the file.
        If it can't open the file, it reports, "Error: Could not open file: [filename]."
    Once the file is open, it proceeds to write the email data:
        It looks at each email saved in its memory 
        (each one is an "Email" object in a big list called "m_emailLines").
        For every email, it writes down the details following the CSV format to the file. */
    bool EmailFile::saveToFile(const char* filename) const {
      ofstream exportFile(filename);
      if (!exportFile.is_open()) {
        cout << "Error: Could not open file: " << filename << "." << endl;
      } else {
        for (int i = 0; i < m_noOfEmails; ++i) {
          exportFile << m_emailLines[i].m_email << "," << m_emailLines[i].m_name << "," << m_emailLines[i].m_year << "\n";
        }
      }
      exportFile.close();
      return exportFile.is_open();
    }
    /* The fileCat method merges emails from another EmailFile object into the current object 
    and optionally renames the resulting file. 
    Here's a breakdown of its actions:
    1. Initial Check: It first ensures both the current EmailFile 
        and the one provided as an argument is in a valid state. 
        If either doesn't, it exits silently.
    2. Counting Emails: It totals up the number of emails from both files, 
        preparing to consolidate them.
    3. Preparing Space: If there are emails in either file, 
        it makes room to gather all emails from both into one combined space.
    4. Combining Emails: The method then brings all emails together. 
        It starts with emails from the current object, 
        followed by those from the provided object, 
        assembling them into one comprehensive list.
    5. Cleaning Up: It discards the previous, 
        separate lists since they've been merged into a larger, unified one.
    6. Handling File Name: If a specific name is provided 
        (meaning the second argument isn't nullptr), 
        it renames the file accordingly. 
        Otherwise, it retains the original name.
    7. Saving: To finalize, 
        it saves the unified list of emails under the designated file name 
        (whether original or newly assigned) to preserve the merged data.*/
    void EmailFile::fileCat(const EmailFile& obj, const char* name) {
      if (m_filename && obj.m_filename) {
        EmailFile emptyRoom;
        emptyRoom.m_noOfEmails = m_noOfEmails + obj.m_noOfEmails;
        emptyRoom.m_emailLines = new Email[emptyRoom.m_noOfEmails];
        for (int i = 0; i < m_noOfEmails; ++i) {
          emptyRoom.m_emailLines[i] = m_emailLines[i];
        }
        for (int i = 0; i < obj.m_noOfEmails; ++i) {
          emptyRoom.m_emailLines[m_noOfEmails + i] = obj.m_emailLines[i];
        }
        if (emptyRoom.m_noOfEmails > 0) {
          name = (name == nullptr) ? m_filename : name;
          saveToFile(name);
        }
      }
    }
    //////////

    std::ostream& EmailFile::view(std::ostream& ostr) const
    {
        if (m_filename) {
            ostr << m_filename << endl;
            ostr.width(strlen(m_filename));
            ostr.fill('=');
            ostr << "=" << endl;
            ostr.fill(' ');
            for (int i = 0; i < m_noOfEmails; i++) {
                ostr.width(35);
                ostr.setf(ios::left);
                ostr << m_emailLines[i].m_email;
                ostr.width(25);
                ostr << m_emailLines[i].m_name;
                ostr << "Year = " << m_emailLines[i].m_year << endl;
            }
        }

            return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const EmailFile& text)
    {
        return text.view(ostr);
    }

}