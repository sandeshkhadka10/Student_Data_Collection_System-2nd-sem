#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <conio.h>  //for getch()
#include <unistd.h> //for sleep()
#define max_pass_len 10
#define max_pin_len 4
using namespace std;

const string filename = "students_records.dat";

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
        cin.ignore();
        cout << "\t\t\t\t\t<== Add Student Information ==>\n\n"
             << endl;
        cout << "\n\t\tName: ";
        cin.getline(obj.name, 50);
        cout << "\n\t\tId no: ";
        cin >> obj.id;
        cin.ignore();
        cout << "\n\t\tCourse and Semester: ";
        cin.getline(obj.year, 50);
        cout << "\n\t\tAddress: ";
        cin.getline(obj.address, 50);
        cout << "\n\t\tEmail: ";
        cin.getline(obj.email, 50);
        cout << "\n\t\tPhone no: ";
        cin.getline(obj.phonenumber, 50);
        cout << "\n\t\tGPA: ";
        cin >> obj.gpa;
        cout << "\n\t\tPaid Amount: ";
        cin >> obj.paidAmount;
        obj.totalAmount = 790000; // fixed amount
        obj.dueAmount = obj.totalAmount - obj.paidAmount;

        cout << "\t\t__________________________________________" << endl;

        ofstream fout;
        fout.open(filename.c_str(), ios::binary | ios::app);
        if (!fout)
        {
            cout << "\t\tUnable to open file.\n";
            return;
        }
        fout.write((char *)&obj, sizeof(obj));
        cout << "\n\t\tDetails added successfully" << endl;
        fout.close();

        cout << "\n\t\tDo you want to add another record?(Press Y or y)";
        cin >> another;
        cin.ignore();

    } while (another == 'y' || another == 'Y');
    cout << "\n\t\tPress any key to go back....." << endl;
    getch();
}
void student::DisplayAllStudent()
{
    student obj;
    system("cls");
    int recordsfound = 0;
    cout << "\t\t\t\t\t<== Student Records ==>\n\n"
         << endl;
    ifstream fin;
    fin.open(filename.c_str(), ios::binary);
    if (!fin)
    {
        cout << "\t\tUnable to open file.\n";
        return;
    }
    fin.seekg(0, ios::beg);
    while (fin.read((char *)&obj, sizeof(obj)))
    {
        recordsfound = 1;
        cout << "\n\t\tStudent Name: " << obj.name << endl;
        cout << "\n\t\tId: " << obj.id << endl;
        cout << "\n\t\tClass and Semester: " << obj.year << endl;
        cout << "\n\t\tAddress: " << obj.address << endl;
        cout << "\n\t\tEmail: " << obj.email << endl;
        cout << "\n\t\tPhone number: " << obj.phonenumber << endl;
        cout << "\n\t\tGPA: " << obj.gpa << endl;
        cout << "\n\t\tTotal Amount: " << obj.totalAmount << endl;
        cout << "\n\t\tPaid Amount: " << obj.paidAmount << endl;
        cout << "\n\t\tDue Amount: " << obj.dueAmount << endl;
        cout << "\n\t\t______________________________________" << endl;
    }
    fin.close();
    if (recordsfound == 0)
    {
        cout << "\n\t\tNo data found!!!!!" << endl;
    }
    cout << "\n\t\tPress any key to go back....." << endl;
    getch();
}
void student::SearchStudent()
{
    student obj;

    system("cls");

    int search = 0, found = 0;

    cout << "\t\t\t\t\t<== Search Student ==>\n\n"
         << endl;

    cout << "Enter the Id you want to search: ";
    cin >> search;

    ifstream fin;
    fin.open(filename.c_str(), ios::binary);
    if (!fin)
    {
        cout << "\t\tUnable to open file.\n";
        return;
    }
    while (fin.read((char *)&obj, sizeof(obj)))
    {
        if (obj.id == search)
        {
            found = 1;
            cout << "\n\t\tStudent Name: " << obj.name << endl;
            cout << "\n\t\tId: " << obj.id << endl;
            cout << "\n\t\tClass and Semester: " << obj.year << endl;
            cout << "\n\t\tAddress: " << obj.address << endl;
            cout << "\n\t\tEmail: " << obj.email << endl;
            cout << "\n\t\tPhone number: " << obj.phonenumber << endl;
            cout << "\n\t\tGPA: " << obj.gpa << endl;
            cout << "\n\t\tTotal Amount: " << obj.totalAmount << endl;
            cout << "\n\t\tPaid Amount: " << obj.paidAmount << endl;
            cout << "\n\t\tDue Amount: " << obj.dueAmount << endl;
            cout << "\n\t\t______________________________________" << endl;
        }
    }
    fin.close();
    if (found == 0)
    {
        cout << "\n\t\tRecord not found\n"
             << endl;
    }
    cout << "\n\t\tPress any key to go back....." << endl;
    getch();
}
void student::EditStudentDetails()
{
    system("cls");
    cout << "\t\t\t\t\t<== Edit Student Details ==>\n\n"
         << endl;

    int id = 0, found = 0, updated = 0;
    cout << "\t\tEnter Id to edit: ";
    cin >> id;

    student updated_student;

    fstream finout;
    finout.open(filename.c_str(), ios::in | ios::out | ios::binary);
    if (!finout)
    {
        cout << "\t\tUnable to open file.\n";
        return;
    }

    student obj;
    while (finout.read((char *)&obj, sizeof(obj)))
    {
        if (obj.id == id)
        {
            updated_student = obj;
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        cout << "\n\t\tStudent with ID " << id << " not found.\n";
        finout.close();
        return;
    }

    int choice;
    int repeatMenu = 1;
    do
    {
        system("cls");
        cout << "\t\t\t\t\t<== Edit Student Details ==>\n\n"
             << endl;
        cout << "\t\tSelect Fields to update: \n";
        cout << "\t\t1.Name\n";
        cout << "\t\t2.ID\n";
        cout << "\t\t3.Semester\n";
        cout << "\t\t4.Address\n";
        cout << "\t\t5.Email\n";
        cout << "\t\t6.Phone Number\n";
        cout << "\t\t7.GPA\n";
        cout << "\t\t8.Paid Amount\n";
        cout << "\t\t9.Exit\n";

        cout << "\t\tEnter your choice(1-9): ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            // cin.ignore();
            cout << "\n\t\tEnter Updated Name: ";
            cin.getline(updated_student.name, 50);
            updated = 1;
            break;

        case 2:
            cout << "\n\t\tEnter Updated Id: ";
            cin >> updated_student.id;
            updated = 1;
            break;

        case 3:
            // cin.ignore();
            cout << "\n\t\tEnter Updated Semester: ";
            cin.getline(updated_student.year, 50);
            updated = 1;
            break;

        case 4:
            cout << "\n\t\tEnter Updated Address: ";
            cin.getline(updated_student.address, 50);
            updated = 1;
            break;

        case 5:
            cout << "\n\t\tEnter Updated Email: ";
            cin.getline(updated_student.email, 50);
            updated = 1;
            break;

        case 6:
            cout << "\n\t\tEnter Updated Phone number: ";
            cin.getline(updated_student.phonenumber, 50);
            updated = 1;
            break;

        case 7:
            cout << "\n\t\tEnter Updated GPA: ";
            cin >> updated_student.gpa;
            updated = 1;
            break;

        case 8:
            cout << "\n\t\tEnter Updated Payment Amount: ";
            cin >> updated_student.paidAmount;
            updated_student.dueAmount = updated_student.totalAmount - updated_student.paidAmount;
            updated = 1;
            break;

        case 9:
            if (updated == 1)
            {
                cout << "\n\t\tStudent details successfully updated.\n"
                     << endl;
            }
            else
            {
                cout << "\n\t\tNo updates were made.\n"
                     << endl;
            }
            repeatMenu = 0;
            break;

        default:
            cout << "\n\t\tInvalid choice!";
            cout << "\n\t\tPress any key to retry";
            // cin.get();
            break;
        }
    } while (repeatMenu);

    // Reset the file pointer to the beginning of the record
    finout.clear();
    finout.seekp((int)finout.tellg() - sizeof(updated_student));

    // Write the updated student object back to the file
    finout.write((char *)&updated_student, sizeof(updated_student));

    finout.close();
    cout << "\n\t\tPress any key to go back....." << endl;
    getch();
}
void student::DeleteStudent()
{
    int found = 0, search;

    student obj;

    system("cls");

    cout << "\t\t\t\t\t<== Delete Student Record ==>\n\n";

    cout << "\t\tEnter the Id you want to delete: ";
    cin >> search;

    ifstream fin;
    fin.open(filename.c_str(), ios::binary);
    if (!fin)
    {
        cout << "\t\tUnable to open file.\n";
        return;
    }
    ofstream fout;
    fout.open("temp_student_data", ios::binary | ios::app);
    if (!fout)
    {
        cout << "\t\tUnable to open file.\n";
    }
    fin.seekg(0, ios::beg);
    while (fin.read((char *)&obj, sizeof(obj)))
    {
        if (obj.id == search)
        {
            found = 1;
            continue; // Skip writing obj to the output file
        }
        else
        {
            fout.write((char *)&obj, sizeof(obj));
        }
    }
    fin.close();
    fout.close();
    remove(filename.c_str());
    rename("temp_student_data", filename.c_str());
    if (found == 1)
    {
        cout << "\t\tStudent with ID " << search << " deleted successfully.\n";
    }
    else
    {
        cout << "\t\tStudent with ID " << search << " not found.\n";
    }
    cout << "\n\t\tPress any key to go back....." << endl;
    getch();
}

class credentials
{
private:
    char username[50];
    char password[max_pass_len + 1];
    char pin[max_pin_len + 1];
    char p[max_pin_len + 1];
    char temp_un[50];
    char temp_pass[max_pass_len + 1];

public:
    void signup();
    void pi_n();
    int login();
    void forgot_pass();
};
void credentials ::signup()
{
    credentials obj;
    cout << "\n\t\tEnter new username: ";
    cin >> obj.username;
    int i = 0;
    cout << "\t\tEnter new password(10 characters): ";
    while (true)
    {
        char ch = _getch();
        if (ch == 13) // enter key ascii value=13
        {
            break;
        }
        else if (ch == 8) // Backspace key ascii value = 8
        {
            if (i > 0)
            {
                i--;
                cout << "\b \b"; // Move the cursor back and erase the character
            }
        }
        else if (ch == 9 || ch == 32)
        {
            continue;
        }
        else if (i < max_pass_len)
        {
            obj.password[i] = ch;
            cout << '*';
            i++;
        }
    }
    obj.password[i] = '\0';
    ofstream fout;
    fout.open("p_confidentials", ios::trunc | ios::binary);
    fout.write((char *)&obj, sizeof(obj));
    fout.close();
}
void credentials ::pi_n()
{
    credentials obj;
    int j = 0;
    cout << "\n\t\tEnter pin(used while doing forget password/4 character): ";
    while (true)
    {
        char c = _getch();
        if (c == 13)
        {
            break;
        }
        else if (c == 8) // Backspace key ascii value = 8
        {
            if (j > 0)
            {
                j--;
                cout << "\b \b"; // Move the cursor back and erase the character
            }
        }
        else if (c == 9 || c == 32)
        {
            continue;
        }
        else if (j < max_pin_len)
        {
            obj.pin[j] = c;
            cout << "*";
            j++;
        }
    }

    obj.pin[j] = '\0';
    ofstream fout1;
    fout1.open("pin", ios::binary);
    fout1.write((char *)&obj, sizeof(obj));
    fout1.close();
}
int credentials ::login()
{
    credentials obj;
    system("cls");
    cout << "\t\t<<------Log In------>>" << endl;
    cout << "\n\t\tUsername: ";
    cin >> temp_un;
    int i = 0;
    cout << "\t\tPassword(10 characters): ";
    while (true)
    {
        char ch = _getch();
        if (ch == 13)
        {
            break;
        }
        else if (ch == 8) // Backspace key ascii value = 8
        {
            if (i > 0)
            {
                i--;
                cout << "\b \b"; // Move the cursor back and erase the character
            }
        }
        else if (ch == 9 || ch == 32)
        {
            continue;
        }
        else if (i < max_pass_len)
        {
            temp_pass[i] = ch;
            cout << '*';
            i++;
        }
    }
    temp_pass[i] = '\0';
    ifstream fin;
    fin.open("p_confidentials", ios::binary);
    fin.seekg(0, ios::beg);
    fin.read((char *)&obj, sizeof(obj));
    if (strcmp(obj.username, temp_un) == 0 && strcmp(obj.password, temp_pass) == 0)
    {
        cout << endl
             << "\n\t\tLogin successful" << endl;
        cout << "\t\tLogging in . . . ." << endl;
        sleep(3);
        return 1;
    }
    else
    {
        cout << endl
             << "\n\t\tLogin failed! Invalid username or password." << endl;
        cout << "\t\tPress any key to go back" << endl;
        getch();
        return 0;
    }
    fin.close();
}
void credentials ::forgot_pass()
{
    credentials obj;
    system("cls");
    int j = 0;
    cout << "\n\t\tEnter the pin(4 characters):";
    while (true)
    {
        char c = _getch();
        if (c == 13)
        {
            break;
        }
        else if (c == 8) // Backspace key ascii value = 8
        {
            if (j > 0)
            {
                j--;
                cout << "\b \b"; // Move the cursor back and erase the character
            }
        }
        else if (c == 9 || c == 32) // 32 = ' ' and 9 = '\t'
        {
            continue;
        }
        else if (j < max_pin_len)
        {
            p[j] = c;
            cout << '*';
            j++;
        }
    }
    p[j] = '\0';
    ifstream fin;
    fin.open("pin", ios ::binary);
    fin.read((char *)&obj, sizeof(obj));
    if (strcmp(p, obj.pin) == 0)
    {
        cout << endl;
        signup();
    }
    else
    {
        cout << endl
             << "\t\tWrong pin!!!!!" << endl;
    }
    cout << endl
         << "\n\t\tPress any key to go back" << endl;
    getch();
    fin.close();
}

int main()
{
    credentials obj;
    ifstream fin;
    fin.open("p_confidentials", ios::binary);
    if (!fin.is_open())
    {
        system("cls");
        cout << "\t\t<<------Sign up------>>" << endl;
        obj.signup();
        obj.pi_n();
    }
    fin.close();
flag:
    int loggedin = 0;
    char ch;
    while (loggedin == 0)
    {
        system("cls");
        cout << "\n\t\ta.Login" << endl
             << "\t\tb.Forgot password" << endl
             << "\t\tc.Exit" << endl;
        cout << "\n\t\tEnter your choice(a-c):";
        cin >> ch;
        switch (ch)
        {
        case 'a':
        {
            loggedin = obj.login();
            break;
        case 'b':
            obj.forgot_pass();
            break;
        case 'c':
            exit(0);
        default:
            system("cls");
            cout << "\t\tInvalid choice!!!!!" << endl;
            cout << "\n\t\tPress any key to go to back" << endl;
            getch();
            break;
        }
        }
    }
    while (1)
    {
        char choice;
        student s;
        system("cls");
        cout << "\t\t\t\t\t<== Student Management System ==>\n";
        cout << "\t\t*********************************************************************************\n";
        fflush(stdin);
        cout << "\n\t\ta. Add Student\n";
        cout << "\t\tb. Display All Students\n";
        cout << "\t\tc. Search Student\n";
        cout << "\t\td. Edit Student Details\n";
        cout << "\t\te. Delete Student\n";
        cout << "\t\tf. Log Out\n";
        cout << "\n\t\tEnter your choice(a-f): ";
        cin >> choice;

        switch (choice)
        {
        case 'a':
            s.AddStudent();
            break;

        case 'b':
            s.DisplayAllStudent();
            break;

        case 'c':
            s.SearchStudent();
            break;

        case 'd':
            s.EditStudentDetails();
            break;

        case 'e':
            s.DeleteStudent();
            break;

        case 'f':
            system("cls");
            exit(0);
        default:
            system("cls");
            cout << "\t\tInvalid Choice...." << endl;
            cout << "\t\tPlease Enter from a to d" << endl;
            cout << "\n\t\tPress any key to go to menu....." << endl;
            getch();
            break;
        }
    }

    return 0;
}
