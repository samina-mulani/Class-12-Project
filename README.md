# Medical Report Generator
***
A programme that allows the user to display, enter, delete or modify a record; each record consisting of patient's personal details, eye test score and graphs depicting BMI and pulse rate. 
When entering a new record, the flow is as follows-
* User is taken to a screen to enter personal details, which are range checked (for details like height and weight)
* The next screen displays a menu with two options from which the user can chose from (Heart and Eye). A help button also exists to guide the user on navigation.
* The eye test generates letters randomly, each with a random colour and size. User is asked to enter the letter in a different screen.
* The heart page takes in details for parameters like pulse rate, cholesterol and blood sugar.
* After completing atleast one of these two sections, the user can generate a report (or go back to give the tests again).
* The report displays all patient details along with two graphs depicting BMI and pulse rate, along with their respective suggested ranges marked in green.
* Records are stored in a DAT file
***
The programme is written in C++ and makes use of the graphics.h header file.

References used for the project-
1.	www.cs.colorado.edu
2.	Virtualoops  YouTube channel
3.	Computer Science with C++ for Class XII  – 2017 by Sumita Arora 
