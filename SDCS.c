#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
#include<conio.h>//for getch()
#include<unistd.h>//for sleep()
class student
{
	public:
		char name[50];
		int id;
		char year[50];
		char address[50];
		char email[50];
		char phonenumber[50];
		float gpa;
		float totalAmount;
		float paidAmount;
		float dueAmount;
	public:
		void AddStudent();
		void DisplayAllStudent();
		void SearchStudent();
		void EditStudentDetails();
		void DeleteStudent();
};
void student::AddStudent()
{
	student obj;
	system("cls");
	cin.ignore();
	cout<<"\t\t\t\t\t<== Add Student Information ==>\n\n"<<endl;
	cout<<"\n\t\tName: "<<endl;
	cin.getline(obj.name,50);
	
	
	
	
}


