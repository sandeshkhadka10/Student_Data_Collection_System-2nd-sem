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
	char another;
	do
	{	
	   student obj;
	   system("cls");
	   cin.ignore();
	   cout<<"\t\t\t\t\t<== Add Student Information ==>\n\n"<<endl;
	
	   cout<<"\n\t\tName: "<<endl;
	   cin.getline(obj.name,50);
	
    	cout<<"\n\t\tId no: "<<endl;
    	cin>>obj.id;
	
    	cout<<"\n\t\tCourse and Semester: "<<endl;
    	cin.getline(obj.year,50);
	
    	cout<<"\n\t\tAddress: "<<endl;
    	cin.getline(obj.address,50);
	
    	cout<<"\n\t\tEmail: "<<endl;
    	cin.getline(obj.email,50);
	
    	cout<<"\n\t\tPhone no: "<<endl;
    	cin.getline(obj.phonenumber,50);
	
    	cout<<"\n\t\tGPA: "<<endl;
    	cin>>obj.gpa;
	
    	cout<<"\n\t\tPaid Amount: "<<endl;
    	cin>>obj.paidAmount;
	
    	obj.totalAmount=790000;//fixed amount
    	obj.dueAmount=obj.totalAmount-obj.paidAmount;
	
    	cout<<"\t\t__________________________________________"<<endl;
	
    	ofstream fout;
    	fout.open("studentdata",ios::binary | ios::app);
    	fout.write((char*)&obj,sizeof(obj));
    	cout<<"\n\t\tDetails added successfully"<<endl;
    	fout.close();
	}while(another == 'y' || another=='Y')	
}
void student::DisplayAllStudent()
{
	system("cls");
	int recordsfound=0;
	
	student obj;
	
	cout<<"\t\t\t\t\t<== Student Records ==>\n\n"<<endl;
	
	ifstream fin;
	fin.open("studentdata",ios::binary);
	fin.seekg(0,ios::beg);
	while(fin.read(char*)&obj,sizeof(obj))
	{
		recordsfound=1;
		cout<<"\n\t\tStudent Name: "<<obj.name<<endl;
		cout<<"\n\t\tId: "<<obj.id<<endl;
		cout<<"\n\t\tClass and Semester: "<<obj.year<<endl;
		cout<<"\n\t\tAddress: "<<obj.address<<endl;
		cout<<"\n\t\tEmail: "<<obj.email<<endl;
		cout<<"\n\t\tPhone number: "<<obj.phonenumber<<endl;
		cout<<"\n\t\tGPA: "<<obj.gpa<<endl;
		cout<<"\n\t\tTotal Amount: "<<obj.totalAmount<<endl;
		cout<<"\n\t\tPaid Amount: "<<obj.paidAmount<<endl;
		cout<<"\n\t\tDue Amount: "<<obj.dueAmount<<endl;
		cout<<"\n\t\t______________________________________"<<endl;
	}
	fin.close();
	if(recordsfound==0)
	{
		cout<<"\n\t\tNo data found!!!!!"<<endl;
	}
}
void student::SearchStudent()
{
	system("cls");
	
	int search=0,found=0;
	
	cout<<"\t\t\t\t\t<== Search Student ==>\n\n"<<endl;
	
	cout<<"Enter the Id you want to search: "<<endl;
	cin>>search;
	
	student obj;
	
	ifstream fin;
	fin.open("studentdata",ios::binary);
	while(fin.read((char*)&obj,sizeof(obj)))
	{
		if(obj.id==search)
		{
			found=1;
			cout<<"\n\t\tStudent Name: "<<obj.name<<endl;
	    	cout<<"\n\t\tId: "<<obj.id<<endl;
	    	cout<<"\n\t\tClass and Semester: "<<obj.year<<endl;
	    	cout<<"\n\t\tAddress: "<<obj.address<<endl;
	    	cout<<"\n\t\tEmail: "<<obj.email<<endl;
	    	cout<<"\n\t\tPhone number: "<<obj.phonenumber<<endl;
	    	cout<<"\n\t\tGPA: "<<obj.gpa<<endl;
	    	cout<<"\n\t\tTotal Amount: "<<obj.totalAmount<<endl;
	    	cout<<"\n\t\tPaid Amount: "<<obj.paidAmount<<endl;
	    	cout<<"\n\t\tDue Amount: "<<obj.dueAmount<<endl;
	    	cout<<"\n\t\t______________________________________"<<endl;	
		}	
	}
	if(found)
	
}
void student::EditStudentDetails()
{
	system("cls");
	cout<<"\t\t\t\t\t<== Edit Student Details ==>\n\n"<<endl;
	
	int id=0,found=0,updated=0;
	cout<<"\t\tEnter Id to edit: "<<endl;
	cin>>id;
	
	student obj;
	
	fstream finout;
	finout.open("studentdata",ios::in || ios::out | ios::binary);
	finout.seekg(0,ios::beg);
	while(finout.read((char*)&obj,sizeof(obj)))
	{
		if(obj.id==id)
		{
			up
		}
	}
	
	
}


