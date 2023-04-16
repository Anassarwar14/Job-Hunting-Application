#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<regex>
#include <sstream>
#include <fstream>
#include "user.h"


using namespace std;



bool isEmailValid(string email) {
    const regex pattern("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
    return regex_match(email, pattern);
}
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
    int check_vowel = 0, charr_check = 0;

    // Match one or more letters

    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
        {
            return false;
        }
        if (str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || str[i] == 'u' || str[i] == 'U')
        {
            check_vowel = 1;
        }
        if (!regex_match(str, pattern)) {
            charr_check = 1;
        }
    }

    if (check_vowel == 0 && charr_check == 1) { return false; }

    return true;
}

/*Here, we are creating a regex object named pattern with a regular expression string as an argument. The regular expression string matches an email address that has the following format:
   A username part consisting of one or more of the following characters: letters (a-z, A-Z), digits (0-9), and the following special characters: period (.), underscore (_), percent sign (%), plus sign (+), and hyphen (-).
   An '@' symbol.
   A domain name part consisting of one or more letters (a-z, A-Z), digits (0-9), hyphens (-), and periods (.) separated by hyphens (-).
   A period (.) character.
   A top-level domain (TLD) part consisting of two or more letters (a-z, A-Z).
   The const keyword means that the pattern object is a constant and cannot be modified after it is initialized.*/



class admin
{
private:
    string email, re_entered_email, phone_num, first_name, last_name, education;
    int age, re_checked_email;
    bool check_email, check_age, phone_check, check_fname, check_lname, email_comapre_check;
   vector <user> users;
   vector <employer> employers;

public:
    void admin_check_employer(employer employer);
    void admin_check_user(user user)
    {

        first_name = user.get_first_name();
        last_name = user.get_last_name();
        age = user.get_age();
        education = user.get_education();
        email = user.get_email();
        re_entered_email = user.get_re_entered_email();
        phone_num = user.get_phone_number();
        
        
        
        check_fname = isNameValid(first_name);
        check_lname = isNameValid(last_name);
        check_email = isEmailValid(email);
        re_checked_email = email.compare(re_entered_email);
        phone_check = isPhoneNumValid(phone_num);

        if (re_checked_email == 0)
        {
            email_comapre_check = true;
        }
        else
        {
            email_comapre_check = false;
        }
        
        if (age <= 15)
        {
            check_age = false;
        }
        else {
            check_age = true;
        }


        if (check_email && email_comapre_check && phone_check && check_age && check_fname && check_lname)
        {
            user.setter_valid_account(true);
            user.set_user_id_and_password(users);
            user.writeRecord();
            system("cls");
            SetColor(2);  cout << "Account was successfully created!\n" << endl;  SetColor(0);
            user.display_details("user");
            users.push_back(user); 
        }
        else
        {
            cout << "OoPs! An error occured while creating your account\nUser could not be aunthenticated!" << endl;
            user.setter_valid_account(false);
        }

    }


void JobsSearch() {
        string department, sub_department;
        int  check2, search2 , search3;
        cout << "1. Computer science/IT\n2. Medical\n3. Engineering" << endl;
        cin >> search2;
        switch (search2)
        {
        case 1:
            department = "Comuter Science";
            do
            {
                check2 = 0;
                cout << "\n1.Search by Sub Department \n 2.Search by skills\n4.Show results" << endl;
                cin >> search3;
                switch (search3)
                {
                case 1:
             /*       sub_department = subdepartment_CS();
                    for (i = 0; i < employers.size(); i++)
                    {
                        if (employers[i].get_department() == department && employers[i].get_sub_depart() == sub_department)
                        {
                            //employers[i].displayJobs()
                            cout << "Enter "
                            if()
                            employers[i].display_details(employers[i].get_type());
                            //employers[i].display_employer_min_wageAND_name();
                            //employers[i].display_id();
                        }
                    }
             */
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    for (int i = 0; i < employers.size(); i++)
                    {
                        if (employers[i].get_department() == department)
                        {
                            employers[i].display_details(employers[i].get_type());
                            employers[i].display_employer_min_wageAND_name();
                            employers[i].display_id();
                        }
                    }
                    break;
                default:
                    check2 = 1;
                    break;
                }

            } while (check2 == 1);

            break;
        case 2:
            break;
        case 3:
            break;

        }
        
}

void login(user u) {
        int check1, search1, getch();

        system("cls");
        SetColor(1);
        cout << "Hello " << u.get_first_name() << "! hope you are doing well\n\n" << endl;
        do
        {
            check1 = 0;
            cout << "1. Search for a job\n2. View Account Details \n3. Modify Acccount Details\n4. Logout" << endl;
            cin >> search1;

            switch (search1)
            {
            case 1:
               JobsSearch();
                break;

            case 2:
                u.display_details("user");
                getch();
                system("cls");
                break;

            case 3:
                u.modifyDetails("user");
                break;

            case 4:
                SetColor(5); cout << "\n\t\t\t\t\tLogging out.."; Sleep(300); cout << "."; Sleep(500); SetColor(0);
                check1 = 1;
                break;

            default:
                cout << "Wrong Entry!"; Sleep(400);
                system("cls");
                break;
            }
        } while (check1 == 0);


    }

void readallRecord() {
    vector<string> row;
  
    string line, word, temp;

    int i = 0, n = 0;

    //counting number of records
    fstream file("user.txt", ios::in);

    while (getline(file, line)) {
        n++; 
    }

    file.close();

    users.resize(n);


    //reading records
    file.open("user.txt", ios::in);

    while (getline(file, line)) {

        row.clear();

        istringstream ss(line);

        while (getline(ss, word, ',')) {

            row.push_back(word);

        }

            users[i].set_idPass(row[0], row[1]);
            users[i].set_first_name(row[2]);
            users[i].set_last_name(row[3]);
            users[i].set_age(stoi(row[4]));
            users[i].set_education(row[5]);
            users[i].set_email(row[6]);
            users[i].set_phone_number(row[7]);
            users[i].set_city(row[8]);
            users[i].set_department(row[9]);
            users[i].set_sub_depart(row[10]);
            for (int m = 0 , n = 11; n < row.size(); n+=2, m++) {
                    users[i].set_skill(row[n], row[n+1], m);
            }

            i++;        

    }
}



vector<user> get_users()
{
    return users;
}
vector<employer> get_employers()
{
    return employers;
}


};



void admin::admin_check_employer(employer employer)
{

    string email1, re_entered_email1, phone_num1;
    double minWage;

    int  re_checked_email1;

    bool check_email1, employer_check1, check_min_wage, phone_check1, email_comapre_check1;
    minWage = employer.get_min_wage();

    if (minWage < 20000 || minWage>300000){
        check_min_wage = false;
    }

    else {
        check_min_wage = true;
    }

    email1 = employer.get_email();
    re_entered_email1 = employer.get_re_entered_email();
    phone_num1 = employer.get_phone_number();
    check_email1 = isEmailValid(email1);
    re_checked_email1 = email1.compare(re_entered_email1);

    if (re_checked_email1 == 0){
        email_comapre_check1 = true;
    }
    else {
        email_comapre_check1 = false;
    }

    phone_check1 = isPhoneNumValid(phone_num1);



    if (check_email1 == true && check_min_wage == true && email_comapre_check1 == true && phone_check1 == true){
        cout << "Account was successfully created!" << endl;

        employer_check1 = true;
        employer.setter_valid_account(employer_check1);
 //       employer.set_user_id_and_password(employers);
        employers.push_back(employer);
    }

    else{
        cout << "OoPs! An error occured while creating your account\nUser could not be aunthenticated!" << endl;
        employer_check1 = false;
        employer.setter_valid_account(employer_check1);
    }

}

