
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<regex>
class user;
class admin;
class employer;
//#include<oop_lab_project.h>
using namespace std;
int id_number = 0;
#pragma once
//#include<iostream>
//#include<string>
//#include"admin.h"
//#include"employeer.h"
//using namespace std;

string id_num = to_string(id_number);

void array_to_null(int arr[])
{
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        arr[i] = 0;
    }
}
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
class user
{
    string latest_education;

    int age;
    int i = 0;
    string first_name;
    string last_name;
    // static int id_number;
protected:
    string type;
    string id;     
    string password;
    string email;
    string city;
    string re_check_email;//for admin to check validity of account
    string phone_number;
    bool valid;//if 1 then valid else non valid
    string skill[15][2];
    string depart;//e.g:CS,medical etc
    string sub_depart;//e.g datascientist

public:
    user()
    {
        type = "user";
    }
    void display_details(string type)
    {
        cout << type << " Details are as follows: " << endl;
        cout << "----------------------------------------" << endl;
        if (type == "user")
        {
            cout << "->PROFILE<-" << endl;
            cout << "First Name: " << first_name << endl;
            cout << "Last Name: " << last_name << endl;
            cout << "Age: " << age << endl;
            cout << "Latest Education: " << latest_education << endl;
        }

        cout << "Email: " << email << endl;
        // cout << "Re-checked Email: " << re_check_email << endl;
        cout << "Phone Number: " << phone_number << endl;
        cout << "City: " << city << endl;

        cout << "Department: " << depart << endl;
        cout << "Field: " << sub_depart << endl;
        cout << "Skills with expertise: " << endl;
        for (int j = 0; j < i; ++j) {
            cout << skill[j][0] << " (" << skill[j][1] << "%)" << endl;//would print only the number of skills chosen due to static i
        }
        if (type == "user")
        {
            cout << "--------------------------------------------" << endl;
        }

    }
    void user_setter(admin& a, string type)
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
                if (age > 80) { cout << "Invalid Age! Re-enter" << endl; }
            }while (age > 80);
            
            cout << "Minimum Education: ";
            cin >> latest_education;
            cout << "City: ";
            cin >> city;

        }
        else {
            cout << "City: ";
            cin >> city;
        }

        do {
            cout << "Enter email: ";
            cin >> email;
            if (email.find("@") == string::npos || email.find(".") == string::npos) { cout << "Invalid Email! Re-enter" << endl;}
        } while (email.find("@") == string::npos || email.find(".") == string::npos);
        cout << "Re-Enter email: ";
        cin >> re_check_email;
        cout << "Enter Phone number (numbers only): ";
        cin >> phone_number;


        //seting_depart_Sub_depart_skills();

        int choice, subdepart, check1 = 0, check2 = 0, check[20], lang, skil;
        string_setter_to_A(skill);
        array_to_null(check);
        do
        {
            cout << "\nChoose from following: " << endl;
            cout << "1.Computer Science\\IT\n2.Medical\n3.Engineering" << endl;
            cin >> choice;
            check1 = 0;
            switch (choice)
            {

            case 1:
                do
                {

                    check2 = 0;
                    cout << "\nComputer Science field list:" << endl;
                    depart = "Comuter Science";
                    cout << "Please select an option:" << endl;
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
                        cout << "Invalid choice! Please try again!" << endl;
                        check2 = 1;
                        break;
                    }
                } while (check2 == 1);
                do
                {
                    check2 = 0;

                    cout << "\nPlease select a programming language:" << endl;
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

                    cin >> lang;

                    switch (lang) {
                    case 1:
                        if (check[0] != 1)
                        {
                            skill[i][0] = "Java";
                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[0] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }


                        break;
                    case 2:
                        if (check[1] != 1)
                        {
                            skill[i][0] = "Python";

                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[1] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }
                        break;
                    case 3:
                        if (check[2] != 1)
                        {
                            skill[i][0] = "JavaScript";

                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++; check[2] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }

                        break;
                    case 4:
                        if (check[3] != 1)
                        {
                            skill[i][0] = "C++";

                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[3] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }
                        break;
                    case 5:
                        if (true)
                        {
                            skill[i][0] = "C#";

                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[4] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }

                        break;
                    case 6:
                        if (check[5] != 1)
                        {
                            skill[i][0] = "PHP";

                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[5] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }

                        break;
                    case 7:
                        if (check[6] != 1)
                        {
                            skill[i][0] = "Swift";

                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[6] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }

                        break;
                    case 8:
                        if (check[7] != 1)
                        {
                            skill[i][0] = "Objective-C";

                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[7] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }
                        break;
                    case 9:
                        if (check[8] != 1)
                        {
                            skill[i][0] = "Kotlin";

                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[8] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }
                        break;
                    case 10:
                        if (check[9] != 1)
                        {
                            skill[i][0] = "Ruby";

                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[9] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }

                        break;
                    case 11:
                        if (check[10] != 1)
                        {
                            skill[i][0] = "Soft Skills";

                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[10] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }


                    case 12:
                        check2 = 3;
                        break;
                    default:
                        cout << "Invalid choice! Please try again!" << endl;
                        check2 = 1;
                        break;
                    }
                } while (check2 == 1 || check2 != 3);



                break;
            case 2:
                do
                {
                    check2 = 0;

                    cout << "\nChoose a medical field from the following:\n";
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
                    cin >> choice;

                    switch (choice) {
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
                        cout << "Invalid choice! Please choose a number between 1 to 10.\n";
                        check2 = 1;
                    }
                } while (check2 == 1);
                do
                {
                    cout << "\nChoose your medical skill from the following:" << endl;
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
                    cout << "\nPress 12 to submit" << endl;
                    cout << "\nEnter your choice (1-12): ";
                    cin >> skil;
                    switch (skil) {
                    case 1:
                        if (check[0] = 1)
                        {
                            skill[i][0] = "Anatomy and Physiology";
                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[0] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }
                        break;
                    case 2:
                        if (check[1] != 1)
                        {
                            skill[i][0] = "Diagnostic Imaging";
                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[1] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }
                        break;
                    case 3:
                        if (check[2] != 1)
                        {
                            skill[i][0] = "Immunology";
                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[2] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }
                        break;
                    case 4:
                        if (check[3] != 1)
                        {
                            skill[i][0] = "Medical Laboratory Technology";
                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[3] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }
                        break;
                    case 5:
                        if (check[4] != 1)
                        {
                            skill[i][0] = "Medical Coding and Billing";
                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[4] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }
                        break;
                    case 6:
                        if (check[5] != 1)
                        {
                            skill[i][0] = "Medical Terminology";
                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[5] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }
                        break;
                    case 7:
                        if (check[6] != 1)
                        {
                            skill[i][0] = "Patient Care";
                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[6] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }
                        break;
                    case 8:
                        if (check[7] != 1)
                        {
                            skill[i][0] = "Pharmacology";
                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[7] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }
                        break;
                    case 9:
                        if (check[8] != 1)
                        {
                            skill[i][0] = "Surgical Technology";
                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[8] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }
                        break;
                    case 10:
                        if (check[9] != 1)
                        {
                            skill[i][0] = "Vital Signs";
                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[9] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }
                        break;
                    case 11:
                        if (check[10] != 1)
                        {
                            skill[i][0] = "Soft skill";
                            cout << "Rate yourself in percentage (e.g 89%): ";
                            cin >> skill[i][1];
                            i++;
                            check[10] = 1;
                        }
                        else
                        {
                            cout << "Already selected!" << endl;
                        }
                        break;
                    case 12:
                        check2 = 3;
                        break;

                    default:
                        cout << "Invalid choice.\n";
                        check2 = 1;
                    }

                } while (check2 == 1 || check2 != 3);



                break;
            case 3:
                do
                {


                    cout << "\nSelect a field of engineering:" << endl;
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
                    cout << "\nEnter your choice: ";
                    cin >> choice;

                    switch (choice) {
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
                        cout << "Invalid choice!" << endl;
                        check2 = 1;
                        break;

                    }
                } while (check2 == 1);
                do
                {
                    cout << "\nChoose an engineering skill from the following:" << endl;
                    cout << "1. Computer Programming" << endl;
                    cout << "2. Data Science and Analytics" << endl;
                    cout << "3. Civil Engineering" << endl;
                    cout << "4. Environmental Engineering" << endl;
                    cout << "5. Materials Science" << endl;
                    cout << "6. Robotics" << endl;
                    cout << "7. Software Engineering" << endl;
                    cout << "8. Structural Engineering" << endl;
                    cout << "9. Systems Engineering" << endl;
                    cout << "10. Telecommunications" << endl;
                    cout << "\nPress 11 to Submit" << endl;
                    cout << "\nEnter your choice (1-11): ";
                    cin >> skil;

                    switch (skil) {
                    case 1:
                        if (check[0] != 1) {
                            skill[i][0] = "Computer Programming";
                            cout << "Enter your expertise level: ";
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
                            skill[i][0] = "Data Science and Analytics";
                            cout << "Enter your expertise level: ";
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
                            skill[i][0] = "Civil Engineering";
                            cout << "Enter your expertise level: ";
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
                            skill[i][0] = "Environmental Engineering";
                            cout << "Enter your expertise level: ";
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
                            cout << "Enter your expertise level: ";
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
                            skill[i][0] = "Robotics";
                            cout << "Enter your expertise level: ";
                            cin >> skill[i][1];
                            i++;
                            check[5] = 1;
                        }
                        else {
                            cout << "You have already selected this skill." << endl;
                        }
                    case 7:
                        if (check[6] != 1) {
                            skill[i][0] = "Software Engineering";
                            cout << "Enter your expertise level: ";
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
                            skill[i][0] = "Structural Engineering";
                            cout << "Enter your expertise level: ";
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
                            skill[i][0] = "Systems Engineering";
                            cout << "Enter your expertise level: ";
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
                            cout << "Enter your expertise level: ";
                            cin >> skill[i][1];
                            i++;
                            check[9] = 1;
                        }
                        else {
                            cout << "You have already selected this skill!" << endl;
                        }
                        break;

                    case 11:
                        check2 = 3;
                        break;

                    default:
                        cout << "Invalid choice. Please enter a number between 1 to 11." << endl;
                        check2 = 1;
                        break;
                    }
                } while (check2 == 1 || check2 != 3);
                break;



                break;

            default:
                check1 = 1;
                break;
            }


        } while (check1 == 1);
        if (type == "user")
        {
            display_details(type);

            verification_request_user(a);//
        }


    }

    int get_age()
    {
        return age;
    }
public:
    void verification_request_user(admin& a);

    void setter_valid_account(bool a)
    {
        valid = a;
    }
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
    bool get_validity()
    {
        return valid;
    }
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
    void set_user_id_and_password()
    {
        id = first_name + "_" + id_num;
        cout << "Your id is " << id << " \nPlease remember this username as it will be used to login into your account" << endl;
        set_password();
    }
    void set_password()
    {
        int check = 0;

        regex pattern("[a-zA-Z0-9]{8,}");
        do
        {
            check = 0;
            cout << "Set Password [Password should contain at least 8 characters and consists of letters and digits only]: " << endl;
            cin >> password;

            if (!regex_match(password, pattern)) {
                cout << "Password does not match the required format please enter password again" << endl;
                check = 1;

            }
            else {

                cout << "Password accepted!" << endl;
            }

        } while (check == 1);


    }
};//
//int user::id_number = 0;

bool isEmailValid(string email) {
    const regex pattern("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
    return regex_match(email, pattern);
}
/*Here, we are creating a regex object named pattern with a regular expression string as an argument. The regular expression string matches an email address that has the following format:

A username part consisting of one or more of the following characters: letters (a-z, A-Z), digits (0-9), and the following special characters: period (.), underscore (_), percent sign (%), plus sign (+), and hyphen (-).
An '@' symbol.
A domain name part consisting of one or more letters (a-z, A-Z), digits (0-9), hyphens (-), and periods (.) separated by hyphens (-).
A period (.) character.
A top-level domain (TLD) part consisting of two or more letters (a-z, A-Z).
The const keyword means that the pattern object is a constant and cannot be modified after it is initialized.*/
bool isPhoneNumValid(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}
bool isNameValid(string str)
{
    regex pattern("[A-Za-z]+");
    int check_vowek = 0, charr_check = 0;

    // Match one or more letters

    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
        {
            return false;
        }
        if (str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || str[i] == 'u' || str[i] == 'U')
        {
            check_vowek = 1;
        }
        if (!regex_match(str, pattern)) {
            charr_check = 1;
        }
    }
    if (check_vowek == 1 && charr_check == 0)
    {
        return true;
    }
}

class admin
{
private:
    vector <user> users;
    vector <employer> employers;
public:
    void admin_check_employer(employer employer);
    void admin_check_user(user user)
    {

        string email, re_entered_email, phone_num, first_name, last_name;
        int age, re_checked_email;
        bool check_email, check_age, user_check, phone_check, check_fname, check_lname, email_comapre_check;
        email = user.get_email();
        re_entered_email = user.get_re_entered_email();
        phone_num = user.get_phone_number();
        age = user.get_age();
        first_name = user.get_first_name();
        last_name = user.get_last_name();
        check_email = isEmailValid(email);
        re_checked_email = email.compare(re_entered_email);
        if (re_checked_email == 0)
        {
            email_comapre_check = true;
        }
        else
        {
            email_comapre_check = false;
        }
        phone_check = isPhoneNumValid(phone_num);
        if (age <= 15)
        {
            check_age = false;
        }
        else {
            check_age = true;
        }
        check_fname = isNameValid(first_name);
        check_lname = isNameValid(last_name);
        if (check_email == true && email_comapre_check == true && phone_check == true && check_age == true && check_fname == true && check_lname == true)
        {
            cout << "Account was successfully created!" << endl;
            user_check = true;
            user.setter_valid_account(user_check);
            user.set_user_id_and_password();
            id_number++;

            users.push_back(user);
        }
        else
        {
            cout << "OoPs! An error occured while creating your account\nUser could not be aunthenticated!" << endl;
            user_check = false;
            user.setter_valid_account(user_check);
        }

    }
    vector<user> get_users_information()
    {
        return users;
    }
    vector<employer> get_employers_information()
    {
        return employers;
    }

};

class employer :public user
{
private:
    double min_wage;
    string company_name;
public:
    employer()
    {
        type = "employer";

    }
    void set_id_and_password_employer()
    {
        id = company_name + "_" + id_num;
        set_password();
    }
    void set_min_wage()
    {
        cout << "Enter minimum salary being offered: " << endl;
        cin >> min_wage;
    }
    void set_company_name()
    {
        cout << "Enter Company Name: ";
        cin >> company_name;
    }
    double get_min_wage()
    {
        return min_wage;
    }
    string get_company_name()
    {
        return company_name;
    }
    void display_employer_min_wageAND_name()
    {
        //cout << "Company offers min wage =" << min_wage << endl;
        cout << "Company name: " << company_name << endl;
        cout << "-------------------------------------------------" << endl;
    }
};
//function for user to be verified
void user::verification_request_user(admin& a)
{

    a.admin_check_user(*this);


}
void admin::admin_check_employer(employer employer)
{

    string email1, re_entered_email1, phone_num1;
    double minWage;

    int  re_checked_email1;

    bool check_email1, employer_check1, check_min_wage, phone_check1, email_comapre_check1;
    minWage = employer.get_min_wage();
    if (minWage < 20000 || minWage>300000)
    {
        check_min_wage = false;
    }
    else
    {
        check_min_wage = true;
    }
    email1 = employer.get_email();

    re_entered_email1 = employer.get_re_entered_email();

    phone_num1 = employer.get_phone_number();




    check_email1 = isEmailValid(email1);

    re_checked_email1 = email1.compare(re_entered_email1);

    if (re_checked_email1 == 0)

    {

        email_comapre_check1 = true;

    }

    else

    {

        email_comapre_check1 = false;

    }

    phone_check1 = isPhoneNumValid(phone_num1);






    if (check_email1 == true && check_min_wage == true && email_comapre_check1 == true && phone_check1 == true)

    {

        cout << "Account was successfully created!" << endl;

        employer_check1 = true;

        employer.setter_valid_account(employer_check1);
        employer.set_id_and_password_employer();
        employers.push_back(employer);

    }

    else

    {

        cout << "OoPs! An error occured while creating your account\nUser could not be aunthenticated!" << endl;

        employer_check1 = false;

        employer.setter_valid_account(employer_check1);

    }




}

