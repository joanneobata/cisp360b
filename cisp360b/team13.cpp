//CISP360
//T/TH 1:30-2:50pm
//Spring 2017
//Team 13 Project: Dynamic Study Guide and Random Question Generator for C++
//Write a program for students to study C++ and for instructors to see how 
//well the students are learning C++.

//team13.cpp

#include <iostream>  //cout, cin
#include <cstdlib>   //srand, rand
#include <string>    //string
#include <fstream>   //ifstream
#include <vector>    //vector
#include <algorithm> //swap 
#include <iomanip>   //setw, setprecision

using namespace std;

//Prototypes
void inputValue(string, char &);
void inputStudentID(vector<string>, string);
void valInput(char &);
void selSubject(int &);
void selReport(int &);
void genTest();

int main()
{
	string studentID;
	vector<string> studentVector;
	int subject, report;  
	char yesno,   //Select Y for Yes or N for No
	  stuIns;	  //S for Student or I for Instructor 

	inputValue("Are you a student or instructor? Select S for Student or I for Instructor?", stuIns);
	valInput(stuIns);

	if (stuIns == 'S')
	{
			inputStudentID(studentVector, studentID);
			selSubject(subject);
			cout << "Display Test Name: Area of Study, Date, % incorrect" << endl;
			cout << "Write to Vector Test Name: Area of Study, Date, % incorrect" << endl;
	}
	else
	{
		selReport(report);
	}
	system("pause");
	return 0;
}

//*************************************************************
// Definition of function getYesNo.                           *
// This function validates for a Y for Yes or N for No answer *
//*************************************************************
void valYesNo(char &answer)
{
	do {
		cout << endl;
		//convert lower case to upper case
		if (answer == 'y') {
			answer = 'Y';
		}
		else if (answer == 'n') {
			answer = 'N';
		}
		if (answer != 'Y' && answer != 'N') {
			cout << "Please enter Y for yes or N for N: ";
		}
	} while (answer != 'Y' && answer != 'N');
}
//*************************************************************
// Definition of function getChar. This function validates for*
// an S for Student or I for Instructor answer                *
//*************************************************************
void valInput(char &answer)
{
	do {
		cout << endl;
		//convert lower case to upper case
		if (answer == 's') {
			answer = 'S';
		}
		else if (answer == 'i') {
			answer = 'I';
		}
		if (answer != 'S' && answer != 'I') {
			cout << "Please enter S for student or I for instructor: ";
			cin >> answer;
		}
	} while (answer != 'S' && answer != 'I');
}
//*************************************************************
// Definition of function inputValue.                         *
//  This function displays query and accepts input value      *
//*************************************************************
void inputValue(string description, char &value)
{
	cout << description << endl;
	cin >> value;
}

//*************************************************************
// Definition of function inputStudentID.                     *
// This function displays query and accepts input value for   *
// student ID                                                 *
//*************************************************************
void inputStudentID(vector<string> v, string id)
{
	cout << "Enter ID: ";
	cin >> id;
	v.push_back(id);
}

//*************************************************************
// Definition of function createTest.                         *
// This function randomly generates a list of 10 questions for*
// area of study selected                                     *
//*************************************************************

void selSubject(int &choice)
{
	do {
		cout << "        Subject Menu" << endl;
		cout << "------------------------------" << endl;
		cout << "1. Arrays" << endl;
		cout << "2. Pointers" << endl;
		cout << "3. Vectors" << endl;
		cout << "4. Any" << endl;
		cout << "5. Quit this progam" << endl;
		cout << "------------------------------" << endl;
		cout << "Enter your choice (1-5): ";
		cin >> choice;
		while (cin.fail()) {                      // If cin fails to receive a value matching the declared data type.
			cout << "Data Type not permitted.\n"; // Notify the user of error.
			cin.clear();                          // Clear the error flag within cin.
			cin.ignore(10000, '\n');              // Ignore the newline character in the buffer to prevent an infinite loop.
		}
		while (choice > 5 || choice < 1) //Validate entry for number within 1-5 range
		{
			cout << "The valid choices are 1, 2, 3, 4, and 5. Please choose: ";
			cin >> choice;
		}
		if (choice == 1)
		{
			genTest();
		}
		else if (choice == 2)
		{
			genTest();
		}
		else if (choice == 3)
		{
			genTest();
		}
		else if (choice == 4)
		{
			genTest();
		}

	} while (choice != 5); //If 5 selected exit program
}

//*************************************************************
// Definition of function genTest. This function generate a   *
// test                                                       *
//*************************************************************
void genTest()
{
	const int NUM_QUESTIONS = 50;
	const int NUM_ASKED = 10;

	ifstream fin1("questions.txt");
	if (!fin1)
		cout << "Error in opening questions.txt file";

	vector<string> questions;
	string line;
	while (getline(fin1, line))
		questions.push_back(line);

	ifstream fin2("answers.txt");
	if (!fin2)
		cout << "Error in opening answers.txt file";

	vector<string> answers;
	string tf;
	while (getline(fin2, tf))
		answers.push_back(tf);

	string inp;
	int count = 0;
	int r;
	int remaining = NUM_QUESTIONS;
	double score = 0;

	cout << "\nEnter 'True' or 'False'. Press enter for next question. \n\n";
	while (count != NUM_ASKED) {
		srand(time_t(0));
		//srand((unsigned int)time_t(NULL));
		cin.ignore(10000, '\n');              // Ignore the newline character in the buffer to prevent an infinite loop.
		
		// Random numbers divided into 'remaining' buckets, instead of using rand() % remaining.
		// Adding 'count' pushes the random number past the range of already-used questions and answers
		r = count + (int)(remaining * rand() / (RAND_MAX + 1.0));	
	    //r = rand() % 50;         //Create random number 1 max 50

	  	// Ask a question and get an answer
		cout << questions[r] << endl;
		getline(cin, inp);

		if (inp == answers[r]) {
			cout << "Correct!\n";
			score += 1;
		}
		else {
			cout << "Incorrect.\n";
		}

		questions[r].swap(questions[count]);
		answers[r].swap(answers[count]);
		count += 1;
		remaining -= 1;
	}
	fin1.close();
	fin2.close();
	double correct = score / NUM_ASKED;
	cout << "\nYour score is " << right << fixed << setprecision(0) << correct *100 << "%.\n\n";
}
//*************************************************************
// Definition of function selReport.                          *
// This function generates a list of reports                  *
//*************************************************************

void selReport(int &choice)
{
	do {
		cout << "        Report Menu" << endl;
		cout << "------------------------------" << endl;
		cout << "1. Report by Student ID - Descending Order - Student ID, Subject, Date, Grade" << endl;
		cout << "2. Report by Subject - Subject, Date, Average Score" << endl;
		cout << "3. Report by Date - Descending Order. Date, StudentID, Subject, Grade, " << endl;
		cout << "4. Report by Subject Scores below 90% - Descending Order. Subject, Scores" << endl;
		cout << "5. Quit this progam" << endl;
		cout << "------------------------------" << endl;
		cout << "Enter your choice (1-5): ";
		cin >> choice;
		while (cin.fail()) {                      // If cin fails to receive a value matching the declared data type.
			cout << "Data Type not permitted.\n"; // Notify the user of error.
			cin.clear();                          // Clear the error flag within cin.
			cin.ignore(10000, '\n');              // Ignore the newline character in the buffer to prevent an infinite loop.
		}
		while (choice > 5 || choice < 1) //Validate entry for number within 1-5 range
		{
			cout << "The valid choices are 1, 2, 3, 4, and 5. Please choose: ";
			cin >> choice;
		}
		if (choice == 1)
		{
			cout << "Do Something\n";
		}
		else if (choice == 2)
		{
			cout << "Do Something\n";
		}
		else if (choice == 3)
		{
			cout << "Do Something\n";
		}
		else if (choice == 4)
		{
			cout << "Do Something\n";
		}

	} while (choice != 5); //If 5 selected exit program
}