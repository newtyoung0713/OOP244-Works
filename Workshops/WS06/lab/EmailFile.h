//*****************************************************************************
//  <assessment name example : Workshop - #6 (Part - 1)>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : Mar 12th, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my workshops and assignments.
//*****************************************************************************
/***********************************************************************
// OOP244 Workshop # 6
//
// File:	EmailFile.h
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
#ifndef SENECA_EMAILFILE_H
#define SENECA_EMAILFILE_H
#include <iostream>

namespace seneca{

	const int BUFFER_SIZE = 1024; // Maximum possible size for all the fields of the Email record

	class EmailFile;
	class Email
	{
		char* m_email{ nullptr };
		char* m_name{ nullptr };
		char m_year[5]{'\0'};
		Email() {};
		Email& operator=(const Email&);
		bool load(std::ifstream& in);
		~Email();
		// Prohibit the copy constructor for this class: 
		Email(const Email& uneAutre);
		// Make the EmailFile class a "friend" of the Email class
		friend class EmailFile;
	};

	
	class EmailFile
	{
		Email* m_emailLines{ nullptr };
		char* m_filename{};
		int m_noOfEmails{ 0 }; 
		void setFilename(const char* filename);
		void setEmpty();
		bool setNoOfEmails();
		
	public:
		// Creates an empty EmailFile and sets it to a safe empty state.
		EmailFile();
		/* If the input argument is nullptr sets the EmailFile object to a safe empty state. 
		Otherwise, it will set the filename, 
		set the m_noOfEmails and finally load the Emails 
		(using the corresponding private methods.) */
		EmailFile(const char* filename);
		// Rule of three
		EmailFile(const EmailFile& uneAutre);
		EmailFile& operator=(const EmailFile& uneAutre);
		~EmailFile();
		// Rule of three
		// Load the file m_filename into a dynamic array of Emails pointed by m_emailLines
		void loadEmails();
		// Returns true if the EmailFile is not in an empty state and returns false if it is.
		operator bool()const;
		/* This method takes a Cstring as an input argument 
		and tries to save email information to this file. 
		It gives back a simple 'yes' (true) or 'no' (false) if it could open the file or not.
			First, it tries to create or open the file.
			If it can't open the file, it reports, "Error: Could not open file: [filename]."
		Once the file is open, it proceeds to write the email data:
			It looks at each email saved in its memory 
			(each one is an "Email" object in a big list called "m_emailLines").
			For every email, it writes down the details following the CSV format to the file. */
		bool saveToFile(const char* filename) const;
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
		void fileCat(const EmailFile& obj, const char* name = nullptr);
		std::ostream& view(std::ostream& ostr) const;
	};

	std::ostream& operator<<(std::ostream& ostr, const EmailFile& text);

}
#endif // !SENECA_EMAILFILE_H
