#include <iostream>
#include <cstdlib>
using namespace std;

// Sign In, Attendance, GPA, Courses, Student Search, Academic Calander

bool cor=0;

// For Courses
string co[5];
int a[5], m[5], c[5];

// For Attendance
int ovall;

// For GPA
float gps[5];
float sgpa;

// Enter Course Information
void courses () {
	
	system("CLS");
	cout << "------------------------" << endl;
	cout << "Course Information Input" << endl;
	cout << "------------------------" << endl << endl;
	
	for (int i=0; i<5; i++) {
		cout << "Course " << i+1 << "/5:" << endl;
		cout << "Name: "; cin >> co[i];
		cout << "Marks: "; cin >> m[i];
			if (m[i]>100) { m[i]=100; }
			if (m[i]<0) { m[i]=-m[i]; }
		cout << "Attendance: "; cin >> a[i];
			if (a[i]>100) { a[i]=100; }
			if (a[i]<0) { a[i]=-a[i]; }
		cout << "Credit Hours: "; cin >> c[i];
			if (c[i]>4) { c[i]=4; }
			if (c[i]<0) { c[i]=-c[i]; }
		cout << endl;
	}
	cor = 1;
	
}

// Display Course Information
void cordis () {
	
	system("CLS");
	cout << "------------------" << endl;
	cout << "Course Information" << endl;
	cout << "------------------" << endl << endl;
	
	for (int i=0; i<5; i++) {
		cout << "Course " << i+1 << "/5:" << endl;
		cout << "Name: " << co[i] << endl;
		cout << "Marks: " << m[i] << endl;
		cout << "Attendance: " << a[i] << endl;
		cout << "Credit Hours: " << c[i] << endl;
		cout << endl;
	}

}

// Display Individual & Overall Attendance
void attendance () {
	
	system("CLS");
	cout << "----------" << endl;
	cout << "Attendance" << endl;
	cout << "----------" << endl << endl;
	
	int temp=0;
	for (int i=0; i<5; i++) {
		cout << co[i] << ": " << a[i] << "%" << endl;
		temp += a[i];
	}
	ovall = temp/5;
	cout << "Overall Attendance: " << ovall << "%" << endl;
	
}

// To Calculate Grade Points
float gp(int mr) {
	float g;
	if (mr<55) {
		g=0;
	} else if (mr>=55 && mr<=59) {
		g=1.67;
	} else if (mr>=60 && mr<=64) {
		g=2; 
	} else if (mr>=65 && mr<=69) {
		g=2.33;
	} else if (mr>=70 && mr<=74) {
		g=2.67;
	} else if (mr>=75 && mr<=79) {
		g=3;
	} else if (mr>=80 && mr<=84) {
		g=3.33;
	} else if (mr>=85 && mr<=89) {
		g=3.67;
	} else if (mr>=90) {
		g=4;
	}
	return g;
}

// Display GPA
void gpa () {
	
	system("CLS");
	cout << "------------" << endl;
	cout << "Semester GPA" << endl;
	cout << "------------" << endl << endl;
	
	float temp1=0,  temp2=0, temp3=0;
	for (int i=0; i<5; i++) {
		gps[i] = gp(m[i]);
		temp1=gps[i]*c[i];
		temp2+=c[i];
		temp3+=temp1;
	}
	sgpa =temp3/temp2;
	cout << "GPA = " << sgpa << endl;
	
}

void fees () {
	
	system("CLS");
	cout << "-----------------------------------------------" << endl;
    cout << "University Department Tuition Fees (Six months)" << endl;
    cout << "-----------------------------------------------" << endl << endl;

	string dep[5] = { "Computer Science", "Computer Engineering", "BBA", "Account and Finance", "Arts and Humanities" };
    int fees[5] = {150000, 116000, 120000, 100000, 90000};
    
    for (int i=0; i<5; i++) {
    	cout << dep[i] << ": " << fees[i] << endl;
	}
    
}

void feedback () {
	
	system("CLS");
    cout << "--------------------------------" << endl;
    cout << "University Website Feedback Form" << endl;
    cout << "--------------------------------" << endl << endl;
    
    string name, feedback;
    int rating;
    cin.ignore();
    cout << "Enter your name: "; getline(cin, name);
    cout << "Enter your feedback (max 500 characters): "; getline(cin, feedback);
    cout << "Rate your experience (1-5): "; cin >> rating;
    
    cout << endl << "Thank you for your feedback!" << endl;
    
}

void acadcal () {
	
	system ("CLS");
	cout << "-----------------------------" << endl;
	cout << "Academic Calendar - Fall 2025" << endl;
    cout << "-----------------------------" << endl << endl;
	
	string Discription[7] = { "Semester Start", "Midterm Exams", "Final Examination time table", "Last Day to Withdraw ", "Final Examamination", "Semester Break", "Commencement of classes" };
    string dates[7] = { "February 17,2025", "April 21,2025 to April 26,2025", "May 12,2025 to May 15,2025", "May 16,2025", "June 23,2025 to July 5,2025", "July 5,2025 to  September 6,2025", "September  9,2025" };

	for (int i=0; i<7; i++) {
		cout << Discription[i] << ": " << dates[i] << endl;
	}
	
}





void display () {
	int c;
	do {
		system ("pause");
		system ("CLS");
		cout << "Welcome To The Student Portal" << endl;
		cout << "=============================" << endl;
		cout << "1. Courses" << endl << "2. Attendance" << endl << "3. GPA" << endl << "4. Fees Description" << endl << "5. Feedback" << endl << "6. Academic Calandar" << endl << "0. Exit" << endl;
		cin >> c;
		switch (c) {
			case 1:
				(cor==0) ? courses() : cordis ();
				break;
			case 2:
				if (cor==1) {
					attendance();
				} else {
					cout << "First enter the courses!" << endl;
				}
				break;
			case 3:
				if (cor==1) {
					gpa();
				} else {
					cout << "First enter the courses!" << endl;
				}
				break;
			case 4:
				fees();
				break;
			case 5:
				feedback();
				break;
			case 6:
				acadcal();
				break;
			case 0:
				break;
			default:
				cout << "Invalid" << endl;
				break;
	    }
	} while (c!=0);
}


