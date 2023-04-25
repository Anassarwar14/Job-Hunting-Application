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
    int age, i = 0, num_skills = 0;


protected:
    string type, id, password, email, city, phone_number;
    string re_check_email;//for admin to check validity of account
    string skill[15][2];//skill[][0] contains 'skill' skill[][1] contains 'rating'
    string depart;//e.g:CS,medical etc
    string sub_depart;//e.g datascientist
    int Domain = 0;
    bool valid;//if 1 then valid else non valid

public:
    static int id_number;
    user()//////////////////////////this will be called in employer class also!!!!!!!//but then employer cnstcr called so its fine
    {
        type = "user";

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
            cout << "--------------------------------------------" << endl;
        }
       
       


    }
    void modifyDetails(string type) {
        int option;

        if (type == "user") {
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


        }
        /* else {
             cout << ""
         }*/

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

        file.open("user.txt", ios::out | ios::app);


        file << id << "," << password << "," << first_name << "," << last_name << "," << age << "," << latest_education << "," << email << "," << phone_number << ","
            << city << "," << depart << "," << sub_depart << ",";
        for (int i = 0; i < num_skills; i++) {
            file << skill[i][0] << "," << skill[i][1] << ",";
        }
        file << "\n";

        file.close();


    }
    void updateRecord() {
        vector<string> lines;
        string line, word;
        int pos = 0, n = 0, i = 0;

        fstream file;
        file.open("user.txt", ios::in);

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



        file.open("user.txt", ios::out);

        i = 0;
        while (i < n) {

            if (i == pos || (i == n - 1 && n == pos)) {
                file << id << "," << password << "," << first_name << "," << last_name << "," << age << "," << latest_education << "," << email << "," << phone_number << ","
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

    //setters
    void set_first_name(string fname) { first_name = fname; }
    void set_last_name(string lname) { last_name = lname; }
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

public:
    string Name, Description, Job_skills[5][2], responsibilities[6];
    user temp; //skill selecter
    int experience, min_salary, max_salary, available_openings, num_applicants, hiredEmployees, num_skills, num_res;
    int JobID;
    static int TotalJobs;


    Job(){//needed to make vector in admin
        TotalJobs++;
        num_applicants = 0; hiredEmployees = 0; num_skills = 0;  num_res = 0;
        available_openings = 5;
    } 

    Job(int EmpDomain){
        JobID = ++TotalJobs;
        num_skills = 0; num_applicants = 0; hiredEmployees = 0; num_skills = 0;  num_res = 0;

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

        available_openings = 5;
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

            
            //endl << experience << endl << min_salary << "-" << max_salary << endl << available_openings << endl;
    }


    void JobDatatoFile() {
        fstream file;
        file.open("Jobs.txt", ios::out | ios::app);

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
        file << "^" << "," << "\n";
    
        file.close();
    }

    void updateRecord() {
        string line, word;

            fstream inFile("Jobs.txt", ios::in | ios::out);
            ofstream outFile("temp.txt");


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
                    outFile << "^" << "," << "\n";

                    continue;
                }

                outFile << line << "\n";


            }

            inFile.close();
            outFile.close();

            remove("Jobs.txt");
            rename("temp.txt", "Jobs.txt");

    }

    void ApplyJob(user u, bool isEmployee) {
        bool flag = false, eligible = false;
        char choice = 'B';
        int skillmatch = 0;

        //employee na ho company ka

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

            }

            Sleep(2500);
        }
        else {
            SetColor(4); cout << "\n\nAlready Applied!";
            Sleep(2500);
        }
        

        SetColor(5);
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
    void set_skill(string new_skill, string percent, int m) { Job_skills[m][0] = new_skill; Job_skills[m][1] = percent; num_skills = m + 1; }
    void setDomain(int a) {
        temp.Domain = a;
    }
    void addApplicant(user app) {
        applicants.push_back(app);
        num_applicants++;
    }
    void addHired(user hire) {
        hired.push_back(hire);
        hiredEmployees++;
        available_openings--;

        /*bool flag = false;

        for (int j = 0; j < employers.size(); j++) {
            for (int k = 0; k < employers[j].get_jobCount(); k++) {
                if (Jobs[i].JobID == employers[j].Jobs[k]->JobID) {
                    if (employers[j].get_company_name() == employers[x - 1].get_company_name()) {
                        index.push_back(i);
                    }
                }

            }
        }


        for (int j = 0; j < countJob; j++) {
            if (JobID == Jobs[j]->JobID) {
                flag = true;
                break;
            }
        }*/
    }

    //getters
    user getHired(int h) {
        return hired[h];
    }
    user getApplicant(int a) {
        return applicants[a];
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


    void display_details(string type) {
        cout << "--------------------------------------------" << endl;
        cout << "->PROFILE<-" << endl;
        cout << "Company Name: " << company_name << endl;
        user::display_details("Employer");

        cout << "--------------------------------------------" << endl;
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

    void writeRecord() {
        fstream file;

        file.open("employer.txt", ios::out | ios::app);


        file << id << "," << password << "," << company_name << "," << email << "," << phone_number << ","
            << city << "," << depart << "," << sub_depart << ",";

        file << "\n";

        file.close();


    }



    void JobPost() {
        string line, word;

        if (countJob < 15) {
            Jobs[countJob] = new Job(Domain);

 
            fstream inFile("employer.txt", ios::in | ios::out);
            ofstream outFile("temp.txt");

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

            remove("employer.txt");
            rename("temp.txt", "employer.txt");


            Jobs[countJob++]->JobDatatoFile();
        }
        
    }


    void addJobEmployees(Job * job) {
        countJob++;
        job->setDomain(Domain);
        for (int i = 0; i < job->hiredEmployees; i++) {
            Employees.push_back(job->getHired(i));
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


   /* void displayJobs() {
        static int m = 0, x = 5, y = 4;
        for (int i = 0; i < countJob; i++) {


            gotoxy(x, y);
            SetColor(8); cout << "   --------JOB#" << ++m << "--------";


            gotoxy(x, ++y);
            SetColor(1); cout << "|>" << Jobs[i]->Name << "<|";


            gotoxy(x, ++y);
            SetColor(6); cout << "[" << company_name << "]"; SetColor(8);

            gotoxy(x, ++y);
            cout << "Salary: "; SetColor(2);  cout << "$" << Jobs[i]->min_salary << "-" << Jobs[i]->max_salary; SetColor(8);


            gotoxy(x, ++y);
            cout << "Location: "; SetColor(4); cout << city; SetColor(8);

            gotoxy(x, ++y);
            cout << "Openings Left: "; SetColor(3); cout << Jobs[i]->available_openings; SetColor(8);
            y = 4;
            x += 45;

            SetColor(7);
            gotoxy(2, 13);
            for (int k = 0; k < 29; k++) {
                cout << "____";
            }
            SetColor(3); gotoxy(3, 15); cout << "<[P:Prev\t\t\t\t\t\tS:Select\t\t\t\t\t     More:M]>"; SetColor(5);



            //cases for moving accross pages
            //if (j == JobsTobePrinted - 1 && m % 3 != 0) {
            //    x = 5, y = 4;
            //    do {
            //        choice = toupper(_getch());
            //        if (choice == 'P' && m > 3 && (m % 2) - 1 == 0) {
            //            m -= 5;
            //            j -= 5;//although m and i j have 1 unit dist diff i j gets ++ once the cycle repeats
            //            i -= 5;//in the case of showall
            //            break;
            //        }
            //        else if (choice == 'P' && m > 3 && (m % 3) - 1 == 0) {
            //            m -= 4;
            //            j -= 4;
            //            i -= 4;
            //            break;
            //        }
            //    } while (choice != 'S');
            //    system("cls");

            //}
            //else if (j != JobsTobePrinted - 1 && m % 3 == 0) {
            //    x = 5, y = 4;
            //    do {
            //        choice = toupper(_getch());
            //        if (choice == 'P' && m > 3) {
            //            m -= 6;
            //            j -= 6;
            //            i -= 6;
            //            break;
            //        }
            //    } while (choice != 'M' && choice != 'S');
            //    system("cls");

            //}
            //else if (j == JobsTobePrinted - 1 && m <= 3) {
            //    do {
            //        choice = toupper(_getch());
            //    } while (choice != 'S');
            //    //system("cls");
            //}


            //if (choice == 'S') {
            //    //Jobs[i].ApplyJob()
            //    break;
            //}






                /* static int m = 0;
                 for (int i = 0; i < countJob; i++) {
                     SetColor(8); cout << "  \t--------JOB#" << ++m << "--------\t\t\t";
                 }
                 cout << endl;

                 for (int i = 0; i < countJob; i++) {
                     SetColor(1); cout << "\t|>" << Jobs[i]->Name << "<|" << "\t";
                 }
                 cout << endl;

                 for (int i = 0; i < countJob; i++) {
                     SetColor(6); cout << "\t[" << company_name << "]" << "\t\t\t"; SetColor(8);
                 }
                 cout << endl;

                 for (int i = 0; i < countJob; i++) {
                     cout << "\tSalary: "; SetColor(2);  cout << "$" << Jobs[i]->min_salary << "-" << Jobs[i]->max_salary << "\t\t\t"; SetColor(8);
                 }
                 cout << endl;

                 for (int i = 0; i < countJob; i++) {
                     cout << "\tLocation: "; SetColor(4); cout << city << "\t\t\t"; SetColor(8);
                 }
                 cout << endl;

                 for (int i = 0; i < countJob; i++) {
                     cout << "\tOpenings Left: "; SetColor(3); cout << Jobs[i]->available_openings << "\t\t\t"; SetColor(8);
                 }

                 SetColor(5);
                 //}
        }
    }*/

    //HireEmployee(); check that employee not already there
    // for(i < countJob){}
    // Employees.pushback(u)
    //setuseridpass
    
};


