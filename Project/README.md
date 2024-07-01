**Patient Management System (C++)**

Developed a comprehensive Patient Management System in C++, incorporating various modules such as Menu, Interface, Time, TestPatient, TriagePatient, Patient, Ticket, PreTriage, and Utils. The system offers a user-friendly interface with the following features:

- **Patient Registration:** Users can register patients by selecting either the Contagion or Triage type. For Contagion, the user inputs the patient's name and OHIP number. For Triage, symptoms are also recorded. Both types receive a ticket with a call number and an estimated wait time.
- **Patient Admission:** Patients are admitted based on their ticket number. The system updates the average wait time for the next patient in the lineup based on the time of the call.
- **Patient Lineup List:** Users can view the patient lineup list by type, displaying details such as name, OHIP number, ticket number, and registration time.
- **Data Export:** Upon exiting the system, it calculates the number of patients for each type and outputs the patient information to a CSV file.

This project ensures efficient patient management and streamlines the registration and admission process, improving overall clinic and hospital operations.
