# Patient Management System (C++)

## Overview
This project is a comprehensive Patient Management System developed in C++, designed to streamline patient registration, admission, and management processes for clinics and hospitals. The system incorporates various modules to ensure efficient functionality and a user-friendly interface.

## Features

### 1. Patient Registration
- **Contagion Type:** Allows users to register patients by entering the patient's name and OHIP number.
- **Triage Type:** In addition to the patient's name and OHIP number, users can also input symptoms. 
- Both patient types receive a ticket with a call number and an estimated wait time.

### 2. Patient Admission
- Patients are admitted based on their ticket number.
- The system updates the average wait time for the next patient in the lineup based on the call time.

### 3. Patient Lineup List
- Users can view the patient lineup list by type.
- The list displays details such as patient name, OHIP number, ticket number, and registration time.

### 4. Data Export
- Upon exiting the system, it calculates the number of patients for each type.
- Outputs the patient information to a CSV file.

## Modules Used
- **Menu**
- **Interface**
- **Time**
- **TestPatient**
- **TriagePatient**
- **Patient**
- **Ticket**
- **PreTriage**
- **Utils**

## Conclusion
This project ensures efficient patient management and streamlines the registration and admission process, improving overall clinic and hospital operations.