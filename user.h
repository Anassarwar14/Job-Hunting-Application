#include<iostream>
#include<string>
#include<windows.h>
#include<vector>
#include<regex>
#include <sstream>
#include <fstream>



using namespace std;



class user;
class admin;
class employer;


//string id_num = to_string(id_number);

void string_setter_to_A(string str[15][2])
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            str[i][j] = "A";
        }
    }
}
void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd     color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void gotoxy(short x, short y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


class user
{
    string first_name, last_name, latest_education;
    int age;


protected:
    string type, id, password, email, city, phone_number;
    string re_check_email;//for admin to check validity of account
    string skill[15][2];//skill[][0] contains 'skill' skill[][1] contains 'rating'
    string depart;//e.g:CS,medical etc
    string sub_depart;//e.g datascientist
    int Domain = 0, i = 0, num_skills = 0, payment_to_admin = 0;
    bool valid;//if 1 then valid else non valid

public:
    string Account_Status;
    static int id_number;
    user()
    {
        type = "user";
        Account_Status = "Free";
    }

    void SelectDomain() {
        int option;
        i = 0;

        do {
            SetColor(4);
            cout << "Choose Domain: \n" << endl;
            SetColor(0);
            cout << "1.Computer Science\\IT\n2.Medical\n3.Engineering" << endl;
            cin >> option;


            switch (option) {
            case 1:
                Domain = 1;
                depart = "Computer Science";
                break;
            case 2:
                Domain = 2;
                depart = "Medical";
                break;
            case 3:
                Domain = 3;
                depart = "Engineering";
                break;
            }

            if (option < 1 || option > 3) { cout << "Invalid Choice! Please Enter Again!"; Sleep(600);  system("cls"); }

        } while (option < 1 || option > 3);

    }
    void SelectField() {
        int subdepart;

        switch (Domain)
        {

        case 1:
            do
            {
                SetColor(4);
                cout << "\nComputer Science fields list:" << endl;
                cout << "Please select an option:" << endl;
                SetColor(0);
                cout << "1. Software Developer" << endl;
                cout << "2. Web Developer" << endl;
                cout << "3. Systems Administrator" << endl;
                cout << "4. Database Administrator" << endl;
                cout << "5. Cybersecurity Analyst" << endl;
                cout << "6. Data Scientist" << endl;
                cout << "7. Cloud Solutions Architect" << endl;
                cout << "8. Network Engineer" << endl;
                cout << "9. Machine Learning Engineer" << endl;
                cout << "10. IT Project Manager" << endl;

                cin >> subdepart;


                switch (subdepart) {
                case 1:
                    sub_depart = "Software Developer";

                    break;
                case 2:
                    sub_depart = "Web Developer";

                    break;
                case 3:
                    sub_depart = "Systems Administrator";

                    break;
                case 4:
                    sub_depart = "Database Administrator";

                    break;
                case 5:
                    sub_depart = "Cybersecurity Analyst";

                    break;
                case 6:
                    sub_depart = "Data Scientist";

                    break;
                case 7:
                    sub_depart = "Cloud Solutions Architect";

                    break;
                case 8:
                    sub_depart = "Network Engineer";

                    break;
                case 9:
                    sub_depart = "Machine Learning Engineer";

                    break;
                case 10:
                    sub_depart = "IT Project Manager";

                    break;
                default:
                    cout << "Invalid choice! Please choose a number between 1-10"; Sleep(600);
                    system("cls");
                    break;

                }
            } while (subdepart > 10 || subdepart < 1);

            break;
        case 2:
            do
            {
                SetColor(4);
                cout << "\nMedical fields list:" << endl;
                cout << "Please select an option:" << endl;
                SetColor(0);
                cout << "1. Cardiology" << endl;
                cout << "2. Dermatology" << endl;
                cout << "3. Gastroenterology" << endl;
                cout << "4. Hematology" << endl;
                cout << "5. Neurology" << endl;
                cout << "6. Oncology" << endl;
                cout << "7. Orthopedics" << endl;
                cout << "8. Pediatrics" << endl;
                cout << "9. Psychiatry" << endl;
                cout << "10. Urology" << endl;

                cout << "\nEnter your choice (1-10): ";
                cin >> subdepart;


                switch (subdepart) {
                case 1:
                    sub_depart = "Cardiology";
                    break;
                case 2:
                    sub_depart = "Dermatology";
                    break;
                case 3:
                    sub_depart = "Gastroenterology";
                    break;
                case 4:
                    sub_depart = "Hematology";
                    break;
                case 5:
                    sub_depart = "Neurology";
                    break;
                case 6:
                    sub_depart = "Oncology";
                    break;
                case 7:
                    sub_depart = "Orthopedics";
                    break;
                case 8:
                    sub_depart = "Pediatrics";
                    break;
                case 9:
                    sub_depart = "Psychiatry";
                    break;
                case 10:
                    sub_depart = "Urology";
                    break;
                default:
                    cout << "Invalid choice! Please choose a number between 1-10"; Sleep(600);
                    system("cls");
                    break;
                }
            } while (subdepart > 10 || subdepart < 1);
            break;

        case 3:
            do
            {
                SetColor(4);
                cout << "\nEngineering fields list:" << endl;
                cout << "Please select an option:" << endl;
                SetColor(0);
                cout << "1. Civil Engineering" << endl;
                cout << "2. Mechanical Engineering" << endl;
                cout << "3. Electrical Engineering" << endl;
                cout << "4. Aerospace Engineering" << endl;
                cout << "5. Chemical Engineering" << endl;
                cout << "6. Computer Engineering" << endl;
                cout << "7. Environmental Engineering" << endl;
                cout << "8. Industrial Engineering" << endl;
                cout << "9. Materials Engineering" << endl;
                cout << "10. Nuclear Engineering" << endl;
                cout << "\nEnter your choice(1-10): ";
                cin >> subdepart;

                switch (subdepart) {
                case 1:
                    sub_depart = "Civil Engineering";
                    break;
                case 2:
                    sub_depart = "Mechanical Engineering";
                    break;
                case 3:
                    sub_depart = "Electrical Engineering";
                    break;
                case 4:
                    sub_depart = "Aerospace Engineering";
                    break;
                case 5:
                    sub_depart = "Chemical Engineering";
                    break;
                case 6:
                    sub_depart = "Computer Engineering";
                    break;
                case 7:
                    sub_depart = "Environmental Engineering";
                    break;
                case 8:
                    sub_depart = "Industrial Engineering";
                    break;
                case 9:
                    sub_depart = "Materials Engineering";
                    break;
                case 10:
                    sub_depart = "Nuclear Engineering";
                    break;
                default:
                    cout << "Invalid choice! Please choose a number between 1-10"; Sleep(600);
                    system("cls");
                    break;
                }
            } while (subdepart > 10 || subdepart < 1);
            break;
        }
    }
    void SelectSkills() {
        int skill_option, check[11] = { 0 };

        switch (Domain) {
        case 1:
            do
            {
                system("cls");
                SetColor(4);
                cout << "\nPlease select a programming language:" << endl;
                SetColor(0);
                cout << "1. Java" << endl;
                cout << "2. Python" << endl;
                cout << "3. JavaScript" << endl;
                cout << "4. C++" << endl;
                cout << "5. C#" << endl;
                cout << "6. PHP" << endl;
                cout << "7. Swift" << endl;
                cout << "8. Objective-C" << endl;
                cout << "9. Kotlin" << endl;
                cout << "10. Ruby" << endl;
                cout << "11.Soft skills" << endl;
                cout << "\nPress 12 to Submit" << endl;


                cin >> skill_option;

                switch (skill_option) {
                case 1:
                    if (check[0] != 1)
                    {
                        skill[i][0] = "Java";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[0] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }


                    break;
                case 2:
                    if (check[1] != 1)
                    {
                        skill[i][0] = "Python";

                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[1] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }
                    break;
                case 3:
                    if (check[2] != 1)
                    {
                        skill[i][0] = "JavaScript";

                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++; check[2] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }

                    break;
                case 4:
                    if (check[3] != 1)
                    {
                        skill[i][0] = "C++";

                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[3] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }
                    break;
                case 5:
                    if (check[4] != 1)
                    {
                        skill[i][0] = "C#";

                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[4] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }

                    break;
                case 6:
                    if (check[5] != 1)
                    {
                        skill[i][0] = "PHP";

                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[5] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }

                    break;
                case 7:
                    if (check[6] != 1)
                    {
                        skill[i][0] = "Swift";

                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[6] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }

                    break;
                case 8:
                    if (check[7] != 1)
                    {
                        skill[i][0] = "Objective-C";

                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[7] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }
                    break;
                case 9:
                    if (check[8] != 1)
                    {
                        skill[i][0] = "Kotlin";

                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[8] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }
                    break;
                case 10:
                    if (check[9] != 1)
                    {
                        skill[i][0] = "Ruby";

                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[9] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }

                    break;
                case 11:
                    if (check[10] != 1)
                    {
                        skill[i][0] = "Soft Skills";

                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[10] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }

                    break;

                case 12: //added so it doesnt go to default
                    break;

                default:
                    cout << "Invalid choice! Please try again!" << endl; Sleep(600);
                    break;
                }
            } while (skill_option != 12);

            break;

        case 2:
            do
            {
                system("cls");
                SetColor(4);
                cout << "Choose skills from following(if any):\n" << endl;
                SetColor(0);
                cout << "1. Anatomy and Physiology" << endl;
                cout << "2. Diagnostic Imaging" << endl;
                cout << "3. Immunology" << endl;
                cout << "4. Medical Laboratory Technology" << endl;
                cout << "5. Medical Coding and Billing" << endl;
                cout << "6. Medical Terminology" << endl;
                cout << "7. Patient Care" << endl;
                cout << "8. Pharmacology" << endl;
                cout << "9. Surgical Technology" << endl;
                cout << "10. Vital Signs" << endl;
                cout << "11.Soft skills " << endl;
                cout << "\nPress 12 to Submit" << endl;

                cout << "\nEnter your choice (1-12): ";
                cin >> skill_option;

                switch (skill_option) {
                case 1:
                    if (check[0] != 1)
                    {
                        skill[i][0] = "Anatomy and Physiology";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[0] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }
                    break;
                case 2:
                    if (check[1] != 1)
                    {
                        skill[i][0] = "Diagnostic Imaging";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[1] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }
                    break;
                case 3:
                    if (check[2] != 1)
                    {
                        skill[i][0] = "Immunology";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[2] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }
                    break;
                case 4:
                    if (check[3] != 1)
                    {
                        skill[i][0] = "Medical Laboratory Technology";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[3] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }
                    break;
                case 5:
                    if (check[4] != 1)
                    {
                        skill[i][0] = "Medical Coding and Billing";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[4] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }
                    break;
                case 6:
                    if (check[5] != 1)
                    {
                        skill[i][0] = "Medical Terminology";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[5] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }
                    break;
                case 7:
                    if (check[6] != 1)
                    {
                        skill[i][0] = "Patient Care";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[6] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }
                    break;
                case 8:
                    if (check[7] != 1)
                    {
                        skill[i][0] = "Pharmacology";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[7] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }
                    break;
                case 9:
                    if (check[8] != 1)
                    {
                        skill[i][0] = "Surgical Technology";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[8] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }
                    break;
                case 10:
                    if (check[9] != 1)
                    {
                        skill[i][0] = "Vital Signs";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[9] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }
                    break;
                case 11:
                    if (check[10] != 1)
                    {
                        skill[i][0] = "Soft skill";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[10] = 1;
                    }
                    else
                    {
                        cout << "Already selected!" << endl; Sleep(600);
                    }
                    break;

                case 12: //added so it doesnt go to default
                    break;

                default:
                    cout << "Invalid choice! Please Enter Again!"; Sleep(600);
                    break;
                }

            } while (skill_option != 12);

            break;

        case 3:
            do
            {
                system("cls");
                SetColor(4);
                cout << "\nChoose an engineering skill from the following:" << endl;
                SetColor(0);
                cout << "1. Pressure Management" << endl;
                cout << "2. Technical Writing" << endl;
                cout << "3. Project Management" << endl;
                cout << "4. Computer Programming" << endl;
                cout << "5. Materials Science" << endl;
                cout << "6. Research & Critical Reasoning" << endl;
                cout << "7. Data Science and Analytics" << endl;
                cout << "8. Leadership" << endl;
                cout << "9. Interpersonal Communication" << endl;
                cout << "10. Telecommunications" << endl;
                cout << "11. Time management" << endl;

                cout << "\nPress 12 to Submit" << endl;
                cout << "\nEnter your choice (1-12): ";
                cin >> skill_option;


                switch (skill_option) {
                case 1:
                    if (check[0] != 1) {
                        skill[i][0] = "Pressure Management";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[0] = 1;
                    }
                    else {
                        cout << "You have already selected this skill! " << endl;
                    }
                    break;

                case 2:
                    if (check[1] != 1) {
                        skill[i][0] = "Technical Writing";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[1] = 1;
                    }
                    else {
                        cout << "You have already selected this skill!" << endl;
                    }
                    break;

                case 3:
                    if (check[2] != 1) {
                        skill[i][0] = "Project Management";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[2] = 1;
                    }
                    else {
                        cout << "You have already selected this skill!" << endl;
                    }
                    break;

                case 4:
                    if (check[3] != 1) {
                        skill[i][0] = "Computer Programming";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[3] = 1;
                    }
                    else {
                        cout << "You have already selected this skill!" << endl;
                    }
                    break;

                case 5:
                    if (check[4] != 1) {
                        skill[i][0] = "Materials Science";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[4] = 1;
                    }
                    else {
                        cout << "You have already selected this skill!" << endl;
                    }
                    break;

                case 6:
                    if (check[5] != 1) {
                        skill[i][0] = "Research & Critical Reasoning";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[5] = 1;
                    }
                    else {
                        cout << "You have already selected this skill." << endl;
                    }

                    break;
                case 7:
                    if (check[6] != 1) {
                        skill[i][0] = "Data Science and Analytics";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[6] = 1;
                    }
                    else {
                        cout << "You have already selected this skill!" << endl;
                    }
                    break;

                case 8:
                    if (check[7] != 1) {
                        skill[i][0] = "Leadership";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[7] = 1;
                    }
                    else {
                        cout << "You have already selected this skill!" << endl;
                    }
                    break;

                case 9:
                    if (check[8] != 1) {
                        skill[i][0] = "Interpersonal Communication";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[8] = 1;
                    }
                    else {
                        cout << "You have already selected this skill!" << endl;
                    }
                    break;

                case 10:
                    if (check[9] != 1) {
                        skill[i][0] = "Telecommunications";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[9] = 1;
                    }
                    else {
                        cout << "You have already selected this skill!" << endl;
                    }
                    break;

                case 11:
                    if (check[10] != 1) {
                        skill[i][0] = "Time management";
                        cout << "Rate it in percentage (e.g 89%): ";
                        cin >> skill[i][1];
                        i++;
                        check[10] = 1;
                    }
                    else {
                        cout << "You have already selected this skill!" << endl;
                    }
                    break;

                case 12: //added so it doesnt go to default
                    break;
                default:

                    cout << "Invalid choice! Please enter a number between 1-12"; Sleep(600);
                    break;
                }
            } while (skill_option != 12);

            break;
        }

        num_skills = i;

    }



    virtual void display_details(string type)
    {
        
        if (type == "user")
        {
            cout << type << " details are as follows: " << endl;
            cout << "--------------------------------------------" << endl;
            cout << "->PROFILE<-" << endl;
            cout << "First Name: " << first_name << endl;
            cout << "Last Name: " << last_name << endl;
            cout << "Age: " << age << endl;
            cout << "Latest Education: " << latest_education << endl;
        }

        cout << "Email: " << email << endl;
        cout << "Phone Number: " << phone_number << endl;
        cout << "City: " << city << endl;

        cout << "Department: " << depart << endl;
        cout << "Field: " << sub_depart << endl;

        if (type == "user") {
            cout << "Skills with expertise: " << endl;
            for (int j = 0; j < num_skills; j++) {
                cout << skill[j][0] << " (" << skill[j][1] << "%)" << endl;//would print only the number of skills chosen due to static i
            }
            cout << "--------------------------------------------" << endl; _getch();
        }
       
       


    }
    virtual void modifyDetails() {
        int option;

            do {
                system("cls");
                cout << "Modify:\n1.First Name\n2.Last Name\n3.Age\n4.Email\n5.Phone Number\n6.Education"
                    << "\n7.Academic Details\n\nPress 8 to return to main menu" << endl;
                cin >> option;

                switch (option) {
                case 1:
                    cout << "Set First Name: "; cin >> first_name; cout << "First Name Set to " << first_name << endl; Sleep(650);
                    break;
                case 2:
                    cout << "Set Last Name: "; cin >> last_name; cout << "Last Name Set to " << last_name << endl; Sleep(650);
                    break;
                case 3:
                    cout << "Set Age: "; cin >> age; cout << "Age Set to " << age << endl; Sleep(650);
                    break;
                case 4:
                    cout << "Set Email: "; cin >> email; cout << "Email set to " << email << endl; Sleep(650);
                    break;
                case 5:
                    cout << "Set Phone Number: "; cin >> phone_number; cout << "Phone Number set to " << phone_number << endl; Sleep(650);
                    break;
                case 6:
                    cout << "Set Education: "; cin >> latest_education; cout << "Latest Education set to " << latest_education << endl; Sleep(650);
                    break;
                case 7:
                    system("cls");
                    cout << "Choose from:\n" << "1:Domain\n2:Field\n3:Skills\n\n[Note]: Changing the Domain would\n\trequire a change in all three" << endl; cin >> option;
                    switch (option) {
                    case 1:
                        SelectDomain();
                        string_setter_to_A(skill);
                        SelectField();
                        SelectSkills();
                        break;
                    case 2:
                        SelectField();
                        break;
                    case 3:
                        i = 0;
                        string_setter_to_A(skill);
                        SelectSkills();
                        break;
                    }

                    break;

                case 8: //added so it doesnt go to default
                    break;

                default:
                    cout << "Invalid choice! Enter from 1 to 7" << endl; Sleep(500);
                    break;
                }

                updateRecord();
            } while (option != 8);

        system("cls");
    }


    virtual void user_setter(admin& a)
    {
        if (type == "user")
        {

            cout << "First name: ";
            cin >> first_name;
            cout << "Last name: ";
            cin >> last_name;
            do {
                cout << "Age: ";
                cin >> age;
                if (age > 80 || age < 10) { cout << "Invalid Age! Re-enter" << endl; }
            } while (age > 80 || age < 10);

            cout << "Minimum Education: ";
            cin >> latest_education;

        }

        cout << "Location(city): ";
        cin >> city;
        do {
            cout << "Enter email: ";
            cin >> email;
            if (email.find("@") == string::npos || email.find(".") == string::npos) { cout << "Invalid Email! Re-enter" << endl; }
        } while (email.find("@") == string::npos || email.find(".") == string::npos);
        cout << "Re-Enter email: ";
        cin >> re_check_email;
        cout << "Enter Phone number (numbers only): ";
        cin >> phone_number;
        system("cls");

        string_setter_to_A(skill);

        SetColor(1);
        cout << "-->Enter Academic Details<--\n" << endl;
        SelectDomain();
        SelectField();
        if (type == "user") {
            SelectSkills();
        }

    }

    virtual void writeRecord() {
        fstream file;

        file.open("user.csv", ios::out | ios::app);


        file << id << "," << password << "," << first_name << "," << last_name << "," << Account_Status << "," << age << "," 
            << latest_education << "," << email << "," << phone_number << ","
            << city << "," << depart << "," << sub_depart << ",";

        for (int i = 0; i < num_skills; i++) {
            file << skill[i][0] << "," << skill[i][1] << ",";
        }
        file << "\n";

        file.close();


    }
    virtual void updateRecord() {
        vector<string> lines;
        string line, word;
        int pos = 0, n = 0, i = 0;

        fstream file;
        file.open("user.csv", ios::in);

        while (getline(file, line)) {

            istringstream ss(line);

            getline(ss, word, ',');
            if (id == word) {
                pos = n;
                n--;
            }
            else {
                lines.push_back(line);
            }

            n++;
        }

        file.close();



        file.open("user.csv", ios::out);

        i = 0;
        while (i < n) {

            if (i == pos || (i == n - 1 && n == pos)) {
                file << id << "," << password << "," << first_name << "," << last_name << "," << Account_Status << "," << age << "," 
                    << latest_education << "," << email << "," << phone_number << ","
                    << city << "," << depart << "," << sub_depart << ",";

                for (int a = 0; a < num_skills; a += 2) {
                    file << skill[a][0] << "," << skill[a][1] << ",";
                }
                file << "\n";
            }

            

            file << lines[i] << "\n";
            i++;

        }

        file.close();
    }
    virtual void deleteRecord() {
        string line, word;

        fstream inFile("user.csv", ios::in | ios::out);
        ofstream outFile("temp.csv");


        while (getline(inFile, line)) {

            istringstream ss(line);

            getline(ss, word, ',');
            if (word == id) {
                continue;
            }

            outFile << line << "\n";


        }

        inFile.close();
        outFile.close();

        remove("user.csv");
        rename("temp.csv", "user.csv");
    }


    bool Subscribe() {
        char choice;

        system("cls");
        if (Account_Status == "Free") {
            SetColor(3); cout << "|<<<<< Premimum Subscription Plan >>>>>|\n\n"; SetColor(8);
            cout << "\t\t\t\t\tFree\t     *Premium\n" << endl;
            cout << "Job Application Tracking:\t\t"; SetColor(2); cout << " YES\t\tYES\n\n"; SetColor(8);
            cout << "Multiple Attempts Screening test:\t"; SetColor(4); cout << " NO\t\t"; SetColor(2); cout << "YES\n\n"; SetColor(8);
            cout << "Recommended to Employers:\t\t"; SetColor(4); cout << " NO\t\t"; SetColor(2); cout << "YES\n\n"; SetColor(8);
            cout << "Advanced Search Filters:\t\t"; SetColor(2); cout << " YES\t\tYES\n\n"; SetColor(8);
            cout << "Access to Employer Profiles:\t\t"; SetColor(4); cout << " NO\t\t"; SetColor(2); cout << "YES\n\n"; SetColor(1);

            cout << "Upgrade to Premium in Only $99\n" << endl;
            SetColor(10); cout << "[G]o Ahead\t"; SetColor(4); cout << "[N]o Thanks"; SetColor(5);
            choice = toupper(_getch());
            if (choice == 'G') {
                Account_Status = "Premium";
                payment_to_admin += 99;
                updateRecord();
                system("cls");
                return true;
            }
        }
        else {
            cout << "Already Subscribed!"; Sleep(1000);
        }
       
        system("cls");
        return false;
    }

    //overloading
    bool operator == (user u) {
        if (u.get_username() == id && u.password == password) {
            return true;
        }

        return false;
    }


    //getters
    string get_type()
    {
        return type;
    }
    string get_first_name()
    {
        return first_name;
    }
    string get_last_name()
    {
        return last_name;
    }
    int get_age()
    {
        return age;
    }
    string get_education() { return latest_education; }
    string get_email()
    {
        return email;
    }
    string get_re_entered_email()
    {
        return re_check_email;
    }
    string get_phone_number()
    {
        return phone_number;
    }
    string get_city()
    {
        return city;
    }
    string get_username()
    {
        return id;
    }
    string get_password()
    {
        return password;
    }
    string get_sub_depart()
    {
        return sub_depart;
    }
    string get_department()
    {
        return depart;
    }
    void display_id()
    {
        cout << "id:" << id << endl;
    }
    bool get_validity()
    {
        return valid;
    }
    int getPayment() {
        return payment_to_admin;
    }

    //setters
    void set_first_name(string fname) { first_name = fname; }
    void set_last_name(string lname) { last_name = lname; }
    void set_acc_status(string status) { Account_Status = status; if (status == "Premium") { payment_to_admin += 99; } }
    void set_email(string em) { email = em; }
    void set_age(int a) { age = a; }
    void set_phone_number(string ph) { phone_number = ph; }
    void set_education(string e) { latest_education = e; }
    void set_city(string cty) { city = cty; }
    void set_sub_depart(string s)
    {
        sub_depart = s;
    }
    void set_department(string d)
    {
        depart = d;
        if (depart == "Computer Science") { Domain = 1; }
        if (depart == "Medical") { Domain = 2; }
        if (depart == "Engineering") { Domain = 3; }
    }
    void setter_valid_account(bool a)
    {
        valid = a;
    }
    void setType(string t) { type = t; }
    void set_skill(string new_skill, string percent, int m) { skill[m][0] = new_skill; skill[m][1] = percent; num_skills = m + 1; }

    virtual bool username_verify(string uname, vector<user> u) {

        for (auto& user : u) {
            if (user.id == uname) {
                return true;
            }
        }

        return false;
    }
    virtual void set_user_id_and_password(vector<user> u)
    {
        bool flag;
        do {
            flag = 0;
            cout << "Set Username: " << "\t[Please remember this username to login into your account]" << endl;
            cin >> id;
            if (username_verify(id, u) == true) { cout << "Username already taken! Re-enter!" << endl; flag = 1; }
        } while (flag == 1);
        set_password();
    }
    void set_password()
    {
        int check = 0;

        regex pattern("[a-zA-Z0-9]{8,}");
        do
        {
            check = 0;
            cout << "Set Password: \t[at least 8 characters & of letters|digits only]: " << endl;
            cin >> password;

            if (!regex_match(password, pattern)) {
                cout << "Password does not match the required format! Please enter password again!" << endl;
                check = 1;

            }
            else {

                cout << "Password accepted!" << endl;
            }

        } while (check == 1);


    }
    void set_idPass(string username, string pass) { id = username; password = pass; }//for filing
    

    friend class Job;

};



class Job {
    vector <user> applicants;
    vector <user> hired;
    vector <user> interviewees;
    vector <user> Screeners;

public:
    string Name, Description, Job_skills[5][2], responsibilities[6];
    user temp; //skill selecter
    int experience, min_salary, max_salary, available_openings, num_applicants, hiredEmployees, num_intviews, num_Scr;
    int num_skills, num_res;
    int JobID;
    static int TotalJobs;


    Job(){//needed to make vector in admin
        TotalJobs++;
        num_applicants = 0; hiredEmployees = 0; num_intviews = 0; num_Scr = 0; num_skills = 0;  num_res = 0;
        available_openings = 0;
    } 

    Job(int EmpDomain){
        JobID = ++TotalJobs;
        num_skills = 0; num_applicants = 0; hiredEmployees = 0; num_intviews = 0;  num_Scr = 0;  num_skills = 0;  num_res = 0;

        system("cls");
        cout << "\n->Enter Job Details<-\n";
        cout << "Job Title: ";
        cin.ignore();
        getline(cin, Name);
        cout << "Job Description: ";
        getline(cin, Description);

        cout << "\nList skills required for the Job: \n"; Sleep(650);

        temp.Domain = EmpDomain;
        string_setter_to_A(temp.skill);
        temp.SelectSkills();
        for (int i = 0; i < 5; i++) {
            if (temp.skill[i][0] != "A") {
                Job_skills[i][0] = temp.skill[i][0];
                Job_skills[i][1] = temp.skill[i][1];
                num_skills++;
            }
        }

        cout << "Job Responsibilites: " << endl;
        for (int i = 0; i < 6; i++) {
            cout << "#" << i + 1 << endl;
            cin.ignore();
            getline(cin, responsibilities[i]);
            num_res++;
            cout << "\nPress S to submit or any key to continue" << endl;
            char end = _getch();
            if (end == 'S' || end == 's') { break; }
        }


        cout << "Experience required (in years): ";
        cin >> experience;
        cout << "Salary Range(Enter minimum & maximum): ";
        cin >> min_salary >> max_salary;
        cout << endl;

        cout << "No. of Employees needed: ";
        cin >> available_openings;
    }


    void displayJob() {
        string Title = Name;
        transform(Title.begin(), Title.end(), Title.begin(), ::toupper);

        SetColor(13); cout << "\n\n\t\t\t\t  -----" << Title << "-----"; SetColor(8);
        cout << "\n\n\t\tJob Description: \n\t\t  "; SetColor(9);
        for (int i = 0; i < Description.size(); i++) {

            cout << Description.at(i);
            if (i % 80 == 0 && i > 0) {
                cout << "\n\t\t  ";
                if (Description.at(i) != ' ') { cout << '-'; }
            }
        }
   

        SetColor(8); cout << "\n\n\t\tSkills Required: "; SetColor(9);
        for (int i = 0; i < num_skills; i++) {
            cout << "\n\t\t   " << Job_skills[i][0] << "  (" << Job_skills[i][1] << "%)";
        }
            
        SetColor(8); cout << "\n\n\t\tResponsibilities: "; SetColor(9);
        for (int i = 0; i < num_res; i++) {
            cout << "\n\t\t > " << responsibilities[i];
        }

        SetColor(8); cout << "\n\n\n\t\t\033[4mExperience\033[24m: "; SetColor(9);
        SetColor(13); cout << experience << "+ years\t"; 
        SetColor(8); cout << "\033[4mSalary Range\033[24m: ";
        SetColor(2); cout << "$" << min_salary << "-" << max_salary << endl << endl;
    }
    void modifyJob() {
        int option;

        do {
            system("cls");
            cout << "Modify:\n1.Job Title\n2.Job Description\n3.Experience\n4.Min Salary\n5.Max Salary\n6.Skills Required\n\nPress 7 to return to main menu" << endl;
            cin >> option;

            cin.ignore();
            switch (option) {
            case 1:
                cout << "Enter New Title: "; getline(cin, Name); cout << "Title Changed to " << Name << endl; Sleep(650);
                break;
            case 2:
                cout << "Enter New Description: "; getline(cin, Description);; cout << "Description Changed Successfully!" << endl;
                break;
            case 3:
                cout << "Enter New Experience"; cin >> experience; cout << "Min Experience Set to " << experience << endl; Sleep(650);
                break;
            case 4:
                cout << "Enter New Min Salary"; cin >> min_salary; cout << "Min Salary set to " << min_salary << endl; Sleep(650);
                break;
            case 5:
                cout << "Enter New Max Salary"; cin >> max_salary; cout << "Max Salary set to " << max_salary << endl; Sleep(650);
                break;
            case 6:
                cout << "Enter New Skill Data: ";
                temp.i = 0;
                temp.SelectSkills();

                for (int i = 0; i < temp.num_skills && i < 5; i++) {
                    Job_skills[i][0] = temp.skill[i][0];
                    Job_skills[i][1] = temp.skill[i][1];
                    num_skills++;
                }
                cout << "Skill Data Updated!" << endl; Sleep(650);
                break;

            case 7: //added so it doesnt go to default
                break;

            default:
                cout << "Invalid choice! Enter from 1 to 7" << endl; Sleep(500);
                break;
            }

            updateRecord();
        } while (option != 7);
    }
    void deleteJob() {
        string line, word;

        fstream inFile("Jobs.csv", ios::in | ios::out);
        ofstream outFile("temp.csv");


        while (getline(inFile, line)) {

            istringstream ss(line);

            getline(ss, word, ',');
            if (stoi(word) == JobID) {
                continue;
            }

            outFile << line << "\n";


        }

        inFile.close();
        outFile.close();

        remove("Jobs.csv");
        rename("temp.csv", "Jobs.csv");
    }

    void JobDatatoFile() {
        fstream file;
        file.open("Jobs.csv", ios::out | ios::app);

        file << JobID << "," << Name << "," << Description << "," << experience << ","
            << min_salary << "," << max_salary << "," << available_openings << ",";
        for (int j = 0; j < 5; j++) {
                file << Job_skills[j][0] << "," << Job_skills[j][1] << ",";
        }

   
        for (int j = 0; j < 6; j++) {
                file << responsibilities[j] << ",";
        }


        file << "[";
        for (int j = 0; j < hiredEmployees; j++) {
                file << hired[j].get_username() << ",";
        }
        file << "]";

        file << "^";
        for (int j = 0; j < num_applicants; j++) {
            file << applicants[j].get_username() << ",";
        }
        file << "^";

        file << "~";
        for (int j = 0; j < num_intviews; j++) {
            file << interviewees[j].get_username() << ",";
        }
        file << "~";

        file << "|";
        for (int j = 0; j < num_Scr; j++) {
            file << Screeners[j].get_username() << ",";
        }
        file << "|" << "," << "\n";


    
        file.close();
    }

    void updateRecord() {
        string line, word;

            fstream inFile("Jobs.csv", ios::in | ios::out);
            ofstream outFile("temp.csv");


            while (getline(inFile, line)) {

                istringstream ss(line);

               

                getline(ss, word, ',');
                if (stoi(word) == JobID) {
                    outFile << JobID << "," << Name << "," << Description << "," << experience << ","
                        << min_salary << "," << max_salary << "," << available_openings << ",";
                    for (int j = 0; j < 5; j++) {
                        outFile << Job_skills[j][0] << "," << Job_skills[j][1] << ",";
                    }


                    for (int j = 0; j < 6; j++) {
                        outFile << responsibilities[j] << ",";
                    }


                    outFile << "[";
                    for (int j = 0; j < hiredEmployees; j++) {
                        outFile << hired[j].get_username() << ",";
                    }
                    outFile << "]";

                    outFile << "^";
                    for (int j = 0; j < num_applicants; j++) {
                        outFile << applicants[j].get_username() << ",";
                    }
                    outFile << "^";

                    outFile << "~";
                    for (int j = 0; j < num_intviews; j++) {
                        outFile << interviewees[j].get_username() << ",";
                    }
                    outFile << "~";

                    outFile << "|";
                    for (int j = 0; j < num_Scr; j++) {
                        outFile << Screeners[j].get_username() << ",";
                    }
                    outFile << "|" << "," << "\n";

                    continue;
                }

                outFile << line << "\n";


            }

            inFile.close();
            outFile.close();

            remove("Jobs.csv");
            rename("temp.csv", "Jobs.csv");

    }

    void ApplyJob(user u, bool isEmployee) {
        bool flag = false, eligible = false;
        char choice = 'B';
        int skillmatch = 0;

        for (int i = 0; i < applicants.size(); i++) {
            if (u == applicants[i]) {
                flag = true;
                break;
            }
        }


        if(!flag){
            system("cls");
            displayJob();

            SetColor(10); cout << "\n\n\n\t\t\t\t\t>> [A]pply Now <<";  SetColor(6);  cout << "    |    "; SetColor(12); cout << "[C]ancel"; SetColor(7);
            cout << "\n\t\t\t\t\t  _____________\t\t   ______"; SetColor(5);
            
            choice = toupper(_getch());
            if(choice == 'A'){
                
                for (int i = 0; i < num_skills; i++) {
                    for (int j = 0; j < u.num_skills; j++) {
                        if (Job_skills[i][0] == u.skill[j][0] && stoi(u.skill[j][1]) > stoi(Job_skills[i][1]) ) {
                            skillmatch++;
                        }
                    }
                }

                if (skillmatch == num_skills && !isEmployee ) {
                    eligible = true;
                }
                else if (isEmployee) {
                    SetColor(4); cout << "\n\n\t\tCannot Apply! Your profile indicates you are already employed in this company";
                }

               
                if(u.Domain == temp.Domain && eligible) {
                    addApplicant(u);
                    updateRecord();
                    SetColor(2); cout << "\n\n\t\tSuccessfully Applied! The company will get back to you shortly"; 
                }
                else if (u.Domain != temp.Domain) {
                    SetColor(4); cout << "\n\n\t\tCannot Apply! You are not allowed to apply to Jobs from this domain";
                }
                else if(!eligible){
                    SetColor(4); cout << "\n\n\t\tCannot Apply! Your skills doesn't match the Job's criteria";
                }

                Sleep(2500);
            }
            else {
                
                cout << "\t";
                for (int i = 0; i < 3; i++) {
                    SetColor(4); cout << "\\\b"; Sleep(170); cout << "|\b"; Sleep(170); cout << "/\b"; Sleep(170); cout << "-\b"; Sleep(170);
                }
            }
        }
        else {
            SetColor(4); cout << "\n\nAlready Applied!";
            Sleep(2500);
        }
        
        SetColor(5);
    }


    void isAnsValid(char* ans) {

        *ans = toupper(*ans);
        do {
            if (*ans != 'A' && *ans != 'B' && *ans != 'C' && *ans != 'D') {
                cout << "Invalid Input! Enter Again\n";
                cin >> *ans;
                *ans = toupper(*ans);
            }
        } while (*ans != 'A' && *ans != 'B' && *ans != 'C' && *ans != 'D');

    }
    bool Test(int domain) {

        char ans;
        int score = 0;

        system("cls");
        if (domain == 1) {
            cout << "Computer Science Screening Test. Contains 5 MCQs and each MCQ is worth 5 points.\nAtleast 3 MCQs should be correct to pass the test" << endl;
            cout << "Q1. Which type of memory is volatile?" << endl;
            cout << "A. RAM\nB. ROM\nC. SSD\nD. HDD" << endl;
            cin >> ans; isAnsValid(&ans);
            if (ans == 'A') { score += 5; }
            cout << "\nQ2. What language does the computer understand?" << endl;
            cout << "A. Human Language\nB. Assembly language\nC. Machine code\nD. High level langauge" << endl;
            cin >> ans; isAnsValid(&ans);
            if (ans == 'C') { score += 5; }
            cout << "\nQ3. What is a byte?" << endl;
            cout << "A. Group of 4 bits\nB. Group of 2 bits\nC. Group of 8 bits\nD. Group of 10 bits" << endl;
            cin >> ans; isAnsValid(&ans);
            if (ans == 'B') { score += 5; }
            cout << "\nQ4. Which register holds an address?" << endl;
            cout << "A. MAR\nB. MDR\nC. ALU\nD. CIR" << endl;
            cin >> ans; isAnsValid(&ans);
            if (ans == 'A') { score += 5; }
            cout << "\nQ5. which of the following is not a network protocol" << endl;
            cout << "A. HTTP\nB. XML\nC. SMTP\nD. FTP" << endl;
            cin >> ans; isAnsValid(&ans);
            if (ans == 'B') { score += 5; }

        }
        else if (domain == 2) {
            cout << "Meidical Screening Test. Contains 5 MCQs and each MCQ is worth 5 points.\nAtleast 3 MCQs should be correct to pass the test" << endl;
            cout << "Q1. Which of the following is an autoimmune disease?" << endl;
            cout << "A. Asthma\nB. Multiple Sclerosis\nC. Malaria\nD. Tuberculosis" << endl;
            cin >> ans; isAnsValid(&ans);
            if (ans == 'B') { score += 5; }
            cout << "\nQ2. Which of the following is a symptom of diabetes?" << endl;
            cout << "A. Hypertension\nB. Hyperthyroidism\nC. Hyperglycemia\nD. Hypercholestrolemia" << endl;
            cin >> ans; isAnsValid(&ans);
            if (ans == 'C') { score += 5; }
            cout << "\nQ3. Which of the following is not a viral disease?" << endl;
            cout << "A. Influenza\nB. Meazles\nC. Malaria\nChicken Pox" << endl;
            cin >> ans; isAnsValid(&ans);
            if (ans == 'C') { score += 5; }
            cout << "\nQ4. Which of the following is not a type of cancer?" << endl;
            cout << "A. Leukemia\nB. Melanoma\nC. Cirrhosis\nD. Carcinoma" << endl;
            cin >> ans; isAnsValid(&ans);
            if (ans == 'C') { score += 5; }
            cout << "\nQ5. which of the following is an antibiotic" << endl;
            cout << "A. Aspirin\nB. Penicilin\nC. Acetaminophen\nD. Ibuprofen" << endl;
            cin >> ans; isAnsValid(&ans);
            if (ans == 'B') { score += 5; }

        }
        else if (domain == 3) {
            cout << "Engineering Screening Test. Contains 5 MCQs and each MCQ is worth 5 points.\nAtleast 3 MCQs should be correct to pass the test" << endl;
            cout << "Q1. Which of the following is an example of renewable energy source?" << endl;
            cout << "A. Coal\nB. Natural gas\nC. Solar\nD. Nuclear" << endl;
            cin >> ans; isAnsValid(&ans);
            if (ans == 'C') { score += 5; }
            cout << "\nQ2. Which of the following is not a type of material used in 3d printing?" << endl;
            cout << "A. PLA\nB. ABS\nC. PET\nD. THC" << endl;
            cin >> ans; isAnsValid(&ans);
            if (ans == 'D') { score += 5; }
            cout << "\nQ3. Which of the following is a measure of a material's resistance to deformation under stress?" << endl;
            cout << "A. Strain\nB. Stress\nC. Elastic Modulus\nD. Yield strength " << endl;
            cin >> ans; isAnsValid(&ans);
            if (ans == 'C') { score += 5; }
            cout << "\nQ4. Which of the following is not a type of electrical circuit?" << endl;
            cout << "A. Series circuit\nB. Parallel circuit\nC. Combination circuit\nD. Diagonal circuit" << endl;
            cin >> ans; isAnsValid(&ans);
            if (ans == 'D') { score += 5; }
            cout << "\nQ5. which of the following is a type of bridge" << endl;
            cout << "A. Arch\nB. Wall\nC. Door\nD. Floor" << endl;
            cin >> ans; isAnsValid(&ans);
            if (ans == 'A') { score += 5; }

        }


        SetColor(9); cout << "\nScore: " << score << "/25" << endl; SetColor(5);

        if (score >= 15) { return true; }

        return false;
    }
    void Screening_test(user* u) {
        bool pass = false;
        int premium_tries = 3;
    
        do{
            pass = Test(temp.Domain);

            if (pass) {
                SetColor(10); cout << "Congratulations! You passed the test\n You are Hired!"; SetColor(5);
                addHired(*u);
            }
            else if (!pass && u->Account_Status == "Premium" && --premium_tries != 0) {
                SetColor(4); cout << "\n\nSorry! You Failed!\nStill have " << premium_tries << " tries left!"; SetColor(5);
            }
            else {
                SetColor(4); cout << "\n\nSorry! You Failed!\nTry Applying for a differnt Job"; SetColor(5);
                removeApplicant(*u);
                removeScreener(*u);
            }

            _getch();
        } while (!pass && u->Account_Status == "Premium" && premium_tries != 0);
        updateRecord();
    }




    //setters
    void setJobID(int id) {
        JobID = id;
    }
    void setTitle(string t) {
        Name = t;
    }
    void setDec(string d) {
        Description = d;
    }
    void setExp(int exp) {
        experience = exp;
    }
    void setMinMax(int min, int max) {
        min_salary = min;
        max_salary = max;
    }
    void setOpenings(int o) {
        available_openings = o;
    }
    void set_skill(string new_skill, string percent, int m) {
        Job_skills[m][0] = new_skill; Job_skills[m][1] = percent; num_skills = m + 1;
    }
    void setDomain(int a) {
        temp.Domain = a;
    }
    void addApplicant(user app) {
        applicants.push_back(app);
        num_applicants++;
    }
    void removeApplicant(user app) {
        for (int i = 0; i < num_applicants; i++) {
            if (app == applicants[i]) {
                applicants.erase(applicants.begin() + i);
                num_applicants--;
            }
        }
    }
    void removeScreener(user Scr) {
        for (int i = 0; i < num_Scr; i++) {
            if (Scr == Screeners[i]) {
                Screeners.erase(Screeners.begin() + i);
                num_Scr--;
            }
        }
    }
    void removeHired(user hire) {
        for (int i = 0; i < hiredEmployees; i++) {
            if (hire == hired[i]) {
                hired.erase(hired.begin() + i);
                hiredEmployees--;
                available_openings++;
            }
        }
    }
    void addHired(user hire) {
        if (available_openings != 0) {
            removeApplicant(hire);
            removeScreener(hire);
            hired.push_back(hire);
            hiredEmployees++;
            available_openings--;
        }
        else {
            cout << "Hiring limit for this Job has reached! Cannot Hire more!" << endl; Sleep(800);
        }
    }
    void addInterviewee(user inter) {
        interviewees.push_back(inter);
        num_intviews++;
    }
    void addScreeners(user Scr) {
        Screeners.push_back(Scr);
        num_Scr++;
    }

    //getters
    user getHired(int h) {
        return hired[h];
    }
    user getApplicant(int a) {
        return applicants[a];
    }
    user getInterviewee(int b) {
        return interviewees[b];
    }
    user getScreeners(int c) {
        return Screeners[c];
    }


};

int Job::TotalJobs = 0;


class employer :public user
{
private:
    vector<user> Employees;
    double min_wage;
    string company_name;
    int countJob;

public:
    Job * Jobs[15];
    employer()
    {
        type = "employer";
        countJob = 0;
        min_wage = 0.0;
    }

    void writeRecord() override {
        fstream file;

        file.open("employer.csv", ios::out | ios::app);


        file << id << "," << password << "," << company_name << "," << email << "," << phone_number << ","
            << city << "," << depart << "," << sub_depart << ",";

        file << "\n";

        file.close();


    }
    void updateRecord() override {
        string line, word;

        fstream inFile("employer.csv", ios::in | ios::out);
        ofstream outFile("temp.csv");


        while (getline(inFile, line)) {

            istringstream ss(line);

            getline(ss, word, ',');
            if (word == id) {
                outFile << id << "," << password << "," << company_name << "," << email << "," << phone_number << ","
                    << city << "," << depart << "," << sub_depart << ",";
                    
                for (int j = 0; j < countJob; j++) {
                    outFile << Jobs[j]->JobID << ",";
                }
                outFile << "\n";

                continue;
            }

            outFile << line << "\n";
        }

        inFile.close();
        outFile.close();

        remove("employer.csv");
        rename("temp.csv", "employer.csv");

    }
    void deleteRecord() override {
        string line, word;

        fstream inFile("employer.csv", ios::in | ios::out);
        ofstream outFile("temp.csv");


        while (getline(inFile, line)) {

            istringstream ss(line);

            getline(ss, word, ',');
            if (word == id) {
                for (int i = 0; i < countJob; i++) {
                    Jobs[i]->deleteJob();
                }

                continue;
            }

            outFile << line << "\n";


        }

        inFile.close();
        outFile.close();

        remove("employer.csv");
        rename("temp.csv", "employer.csv");
    }
    void display_details(string type) override {
        cout << "--------------------------------------------" << endl;
        cout << "->PROFILE<-" << endl;
        cout << "Company Name: " << company_name << endl;
        user::display_details("Employer");

        cout << "--------------------------------------------" << endl;
        _getch();
    }
    void modifyDetails() override {
        int option;

        do {
            system("cls");
            cout << "Modify:\n1.Comapany Name\n2.Email\n3.Contact Info\n4.City"
                << "\n5.Department\n6.Sub-Department\n\nPress 7 to return to main menu" << endl;
            cin >> option;

            switch (option) {
            case 1:
                cout << "Set Company Name: "; cin >> company_name; cout << "Company Name Set to " << company_name << endl; Sleep(650);
                break;
            case 2:
                cout << "Set Email: "; cin >> email; cout << "Email Set to " << email << endl; Sleep(650);
                break;
            case 3:
                cout << "Set Contact Number: "; cin >> phone_number; cout << "Contact Number Set to " << phone_number << endl; Sleep(650);
                break;
            case 4:
                cout << "Set City: "; cin >> city; cout << "Location set to " << city << endl; Sleep(650);
                break;
            case 5:
                cout << "Set Department: "; cin >> depart; cout << "Department set to " << depart << endl; Sleep(650);
                break;
            case 6:
                cout << "Set Sub-Department: "; cin >> sub_depart; cout << "Sub-Department set to " << sub_depart << endl; Sleep(650);
                break;


            case 7: //added so it doesnt go to default
                break;

            default:
                cout << "Invalid choice! Enter from 1 to 7" << endl; Sleep(500);
                break;
            }

            updateRecord();
        } while (option != 7);

        system("cls");
    }

    //setters
    void set_company_name(string name)
    {
        company_name = name;
    }
    void set_min_wage(double x)
    {
        min_wage = x;
    }

    //getters
    double get_min_wage()
    {
        return min_wage;
    }
    string get_company_name()
    {
        return company_name;
    }
    int get_jobCount() { return countJob; }
    void display_employer_min_wageAND_name()
    {
        //cout << "Company offers min wage =" << min_wage << endl;
        cout << "Company name: " << company_name << endl;
        cout << "-------------------------------------------------" << endl;
    }
   
    
    void user_setter(admin& a) {
        cout << "Company or Organization Name: ";
        cin >> company_name;
        user::user_setter(a);
        cout << "Enter Minimum Salary Offered: " << endl;
        cin >> min_wage;

    }
    bool username_verify(string uname, vector<employer> e) {

        for (auto& employer : e) {
            if (employer.id == uname) {
                return true;
            }
        }

        return false;
    }
    void set_user_id_and_password(vector<employer> e)
    {
        bool flag;
        do {
            flag = 0;
            cout << "Set Username: " << "\t[Please remember this username to login into your account]" << endl;
            cin >> id;
            if (username_verify(id, e) == true) { cout << "Username already taken! Re-enter!" << endl; flag = 1; }
        } while (flag == 1);
        set_password();
    }

   


    void JobPost() {
        char choice;
        cout << "[For Every Employee Hired From this Job You will be Charged Only $50]\n\n";
        SetColor(10); cout << "[G]o Ahead\t"; SetColor(4); cout << "[R]eturn"; SetColor(5);
        choice = toupper(_getch());

        string line, word;

        if (countJob < 15 && choice == 'G') {
            Jobs[countJob] = new Job(Domain);

 
            fstream inFile("employer.csv", ios::in | ios::out);
            ofstream outFile("temp.csv");

            string line;

            while (getline(inFile, line)) {
               
                istringstream ss(line);

                outFile << line;

                getline(ss, word, ',');
                if (word == id) {
                    outFile << Jobs[countJob]->JobID << ",";
                }
                
                
                outFile << "\n";
                 
                
            }

            inFile.close();
            outFile.close();

            remove("employer.csv");
            rename("temp.csv", "employer.csv");


            Jobs[countJob++]->JobDatatoFile();
        }
        
    }


    void addJobEmployees(Job * job) {
        countJob++;
        job->setDomain(Domain);
        for (int i = 0; i < job->hiredEmployees; i++) {
            Employees.push_back(job->getHired(i));
            payment_to_admin += 50;
        }
     
    }
    bool isEmployee(user u) {

        for (int j = 0; j < Employees.size(); j++){
            if (u == Employees[j]) {
                return true;
            }
        }
        
        return false;
    }

    void AllEmployees() {
        system("cls");
        for (int i = 0; i < Employees.size(); i++) {
            cout << i + 1 << ". "
                << Employees[i].get_first_name() << " "
                << Employees[i].get_last_name() << "\t(@"
                << Employees[i].get_username() << ")";
        }

        if (i == 0) {
            SetColor(4); cout << "No Employees!"; SetColor(5);
        }

        _getch(); system("cls");
    }
   
};


