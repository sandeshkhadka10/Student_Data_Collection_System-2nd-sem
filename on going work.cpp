#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
#include<conio.h>//for getch()
#include<unistd.h>//for sleep()

using namespace std;

const string filename="students_records.dat";

class student
{
	private:
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
	   
	   cout<<"\t\t\t\t\t<== Add Student Information ==>\n\n"<<endl;
	
	   cout<<"\n\t\tName: "<<;
	   cin.getline(obj.name,50);
	
    	cout<<"\n\t\tId no: "<<;
    	cin>>obj.id;
	
    	cout<<"\n\t\tCourse and Semester: "<<;
    	cin.ignore();
    	cin.getline(obj.year,50);
	
    	cout<<"\n\t\tAddress: "<<;
    	cin.getline(obj.address,50);
	
    	cout<<"\n\t\tEmail: "<<;
    	cin.getline(obj.email,50);
	
    	cout<<"\n\t\tPhone no: "<<;
    	cin.getline(obj.phonenumber,50);
	
    	cout<<"\n\t\tGPA: "<<;
    	cin>>obj.gpa;
	
    	cout<<"\n\t\tPaid Amount: "<<;
    	cin>>obj.paidAmount;
	
    	obj.totalAmount=790000;//fixed amount
    	obj.dueAmount=obj.totalAmount-obj.paidAmount;
	
    	cout<<"\t\t__________________________________________"<<endl;
	
    	ofstream fout;
    	fout.open(filename,ios::binary | ios::app);
    	if(!fout)
    	{
    		cout<<"\t\tUnable to open file.\n";
    		return;
		}
    	fout.write((char*)&obj,sizeof(obj));
    	cout<<"\n\t\tDetails added successfully"<<endl;
    	fout.close();
    	
    	cout<<"\n\t\tDo you want to add another record?(Press Y or y)";
    	cin>>another;
    	cin.ignore();
    	
	}while(another == 'y' || another=='Y');	
}
void student::DisplayAllStudent()
{
	student obj;
	
	system("cls");
	
	int recordsfound=0;
	
	cout<<"\t\t\t\t\t<== Student Records ==>\n\n"<<endl;
	
	ifstream fin;
	fin.open(filename,ios::binary);
	{
		if(!fin)
		{
			cout<<"\t\tUnable to open file.\n";
			return;
		}
	}
	fin.seekg(0,ios::beg);
	while(fin.read((char*)&obj,sizeof(obj)))
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
	student obj;
	
	system("cls");
	
	int search=0,found=0;
	
	cout<<"\t\t\t\t\t<== Search Student ==>\n\n"<<endl;
	
	cout<<"Enter the Id you want to search: "<<;
	cin>>search;
	
	ifstream fin;
	fin.open(filename,ios::binary);
	if(!fin)
	{
		cout<<"\t\tUnable to open file.\n";
		return;
	}
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
	fin.close();
	if(found==0)
	{
		cout<<"\n\t\tRecord not found\n"<<endl;
	}
}
void student::EditStudentDetails()
{
	system("cls");
	cout<<"\t\t\t\t\t<== Edit Student Details ==>\n\n"<<endl;
	
	int id=0,found=0,updated=0;
	cout<<"\t\tEnter Id to edit: "<<endl;
	cin>>id;
	
	student updated_student;
	
	ifstream fin;
	fin.open(filename,ios::binary);
	if(!fin)
	{
		cout<<"\t\tUnable to open file.\n";
		return;
	}
	
	student obj;
	while(fin.read((char*)&obj,sizeof(obj)))
	{
		if(obj.id==id)
		{
			updated_student=obj;
			found=1;
			break;
	    }
	}
	fin.close();
	if(found==0)
	{
		cout<<"\n\t\tStudent with ID "<<id<<" not found.\n";
		return;
	}
	
	int choice;
	int repeatMenu=1;
	do
	{
		system("cls");
		cout<<"\t\t\t\t\t<== Edit Student Details ==>\n\n"<<endl;
		cout<<"\t\tSelect Fields to update: \n"<<endl;
		cout<<"\t\t1.Name\n"<<endl;
		cout<<"\t\t2.ID\n"<<endl;
		cout<<"\t\t3.Semester\n"<<endl;
		cout<<"\t\t4.Address\n"<<endl;
		cout<<"\t\t5.Email\n"<<endl;
		cout<<"\t\t6.Phone Number\n"<<endl;
		cout<<"\t\t7.GPA\n"<<endl;
		cout<<"\t\t8.Paid Amount\n"<<endl;
	    cout<<"\t\t9.Exit\n"<<endl;
	    
		cout<<"\t\tEnter your choice(1-9): "<<endl;
		cin>>choice;
		cin.ignore();
		
		switch(choice)
		{
			case 1:
				cout<<"\n\t\tEnter Updated Name: "<<endl;
				fflush(stdin);
						cin.getline(updated_student.name,50);
						updated=1;
						break;
						
					case 2:
						cout<<"\n\t\tEnter Updated Id: "<<endl;
						cin>>updated_student.id;
						updated=1;
						break;
						
					case 3:
						cout<<"\n\t\tEnter Updated Semester: "<<endl;
						cin.getline(updated_student.year,50);
						updated=1;
						break;
						
					case 4:
						cout<<"\n\t\tEnter Updated Address: "<<endl;
						cin.getline(updated_student.address);
						updated=1;
						break;
						
					case 5:
						cout<<"\n\t\tEnter Updated Email: "<<endl;
						cin.getline(updated_student.email);
						updated=1;
						break;
						
					case 6:
						cout<<"\n\t\tEnter Updated Phone number: "<<endl;
						cin.getline(updated_student.phonenumber);
						updated=1;
						break;
						
					case 7:
						cout<<"\n\t\tEnter Updated GPA: "<<endl;
						cin>>updated_student.gpa;
						updated=1;
						break;
						
					case 8:
						cout<<"\n\t\tEnter Updated Payment Amount: "<<endl;
						cin>>updated_student.paidAmount;
						updated_student.dueAmount=updated_student.totalAmount-updated_student.paidAmount;
						updated=1;
						break;
						
					case 9:
						if(updated==1)
						{
							cout<<"\n\t\tStudent details successfully updated.\n"<<endl;
						}
						else
						{
							cout<<"\n\t\tNo updates were made.\n"<<endl;					
						}
						repeatmenu=0;
						break;
						
					default:
						cout<<"\n\t\tInvalid choice!";
						cout<<"\n\t\tPress any key to retry";
						cin.get();
						break;
				}
			}while(repeatMenu);
			fstream finout;
			finout.open(filename,ios::in || ios::out || ios::binary)
			if(!finout)
			{
				cout<<"\t\tUnable to open file.\n";
				return;
			}
			finout.seekg(0,ios::beg);
			while(finout.read((char*)&obj,sizeof(obj)))
			{
				if(obj.id==id)
				{
					int pos=finout.tellg();
					finout.seekp(pos -sizeof(obj),ios::beg);
					finout.write((char*)&obj,sizeof(obj));
					break;
				}
	    	}
	    	finout.close();
}
void student::DeleteStudent()
{
	
}
	
	


