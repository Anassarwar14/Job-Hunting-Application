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
   string email, re_entered_email, phone_num, first_name, last_name, education;
   int age, re_checked_email;
   bool check_email, check_age, phone_check, check_fname, check_lname, email_comapre_check;
   vector <user> users;
   vector <employer> employers;
   vector <Job> Jobs;

public:
    admin() {
        readUserRecord();
        readJobRecord();
        readEmployerRecord();
    }

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


  /* void displayJobs() {
        for (int i = 0; i < Jobs.size(); i++) {
            cout << Jobs[i].Name << "\t\t\t\t\n";
        }


        for (int i = 0; i < Jobs.size(); i++) {
            cout << "Salary: " << Jobs[i].min_salary + "-" + Jobs[i].max_salary << "\t";
        }
        cout << endl;

        for (int i = 0; i < Jobs.size(); i++) {
            cout << "Location: " << Jobs[i].location << "\t";
        }
        cout << endl;

        for (int i = 0; i < Jobs.size(); i++) {
            cout << "Requirements: " << Jobs[i].requirements << "\t";
        }
        cout << endl;


        cout << Name << endl << Description << endl << experience << endl << min_salary << "-" << max_salary << endl << available_openings << endl;
    }*/


void JobsSearch() {
        string department, sub_department;
        int  check2, search , search2, x = 0, y = 0;

        employer e;
       /* e.JobPost();
        e.JobPost();
        e.JobPost();*/

        employers.push_back(e);

        cout << "Search:\n1. By Industry\n2. By Sub Field\n3. By City\n4. By Skills\n5. By Comapany" << endl;
        cin >> search;
        switch (search)
        {
        case 1:
            cout << "1. Computer science/IT\n2. Medical\n3. Engineering" << endl;
            cin >> search2;
            system("cls");

            for (int i = 0; i < employers.size(); i++)
            {
               //employers[i].displayJobs();
                if (employers[i].get_department() == "Computer Science" && search2 == 1) {
                    employers[i].displayJobs();
                }
                else if (employers[i].get_department() == "Medical" && search2 == 2) {
                    employers[i].displayJobs();
                }
                else if (employers[i].get_department() == "Engineering" && search2 == 3) {
                    employers[i].displayJobs();
                }

            }

            //department = "Comuter Science";
           /* do
            {
                check2 = 0;

                cin >> search3;
                switch (search3)
                {
                case 1:
                    break;

                case 2:*/
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
                /* break;

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

         } while (search != 4);

         break;
     case 2:
         break;
     case 3:
         break;

     }
     */
        }
}

void login(user * u) {
        int check1, search1, getch();

        system("cls");
        SetColor(1);
        cout << "Hello " << u->get_first_name() << "! Welcome to this Wonderful Platform\n\nThe Hunt Begins!\n" << endl;
        SetColor(13);
        do
        {
            check1 = 0;
            if (u->get_type() == "user") {
                cout << "1. Search For A Job";
            }
            else {
                cout << "1. Post A Job";
            }
            cout << "\n\n2. View Account Details\n\n3. Modify Acccount Details\n\n4. Logout\n" << endl;
            cin >> search1;

            switch (search1)
            {
            case 1:
                if (u->get_type() == "user") {
                    JobsSearch();
                }
                else {
                    if (employer* e = dynamic_cast<employer*>(u)) { //needed to call jobpost(), only present in child class(employer)
                        e->JobPost();
                    }
                    else {
                        cout << "Dynamic cast error"; getch();
                    }
                }
                break;

            case 2:
                u->display_details(u->get_type());
                getch();
                system("cls");
                break;

            case 3:
                u->modifyDetails(u->get_type());
                break;

            case 4:
                SetColor(5); cout << "\n\t\t\t\t\tLogging out.."; Sleep(300); cout << "."; Sleep(500); SetColor(0);
               // check1 = 1;
                break;

            default:
                cout << "Wrong Entry!"; Sleep(400);
                system("cls");
                break;
            }
        } while (search1 != 4);

 }

void readUserRecord() {
    vector<string> row;
  
    string line, word;

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

void readEmployerRecord() {
        vector<string> row;

        string line, word;

        int i = 0, n = 0;

        //counting number of records
        fstream file("employer.txt", ios::in);

        while (getline(file, line)) {
            n++;
        }

        file.close();

        employers.resize(n);


        //reading records
        file.open("employer.txt", ios::in);

        while (getline(file, line)) {

            row.clear();

            istringstream ss(line);

            while (getline(ss, word, ',')) {

                row.push_back(word);

            }

            employers[i].set_idPass(row[0], row[1]);
            employers[i].set_company_name(row[2]);
            employers[i].set_email(row[3]);
            employers[i].set_phone_number(row[4]);
            employers[i].set_city(row[5]);
            employers[i].set_department(row[6]);
            employers[i].set_sub_depart(row[7]);
            
            for (int m = 8; m < row.size(); m++) {//finding jobs that match particular employer and adding in its object
                for (auto& Job : Jobs) {
                        if (Job.JobID == stoi(row[m])) {
                            employers[i].Jobs[m - 8] = &Job;
                            employers[i].addJobEmployees(Job);
                        }
                }
            }
            
            i++;

        }
}

void readJobRecord() {
    vector<string> row;

    string line, word;

    int i = 0, n = 0;

    //counting number of records
    fstream file("Jobs.txt", ios::in);

    while (getline(file, line)) {
        n++;
    }

    file.close();

    Jobs.resize(n);


    //reading records
    file.open("Jobs.txt", ios::in);

    while (getline(file, line)) {

        row.clear();

        istringstream ss(line);

        while (getline(ss, word, ',')) {

            row.push_back(word);

        }

        Jobs[i].setJobID(stoi(row[0]));
        Jobs[i].setTitle(row[1]);
        Jobs[i].setDec(row[2]);
        Jobs[i].setExp(stoi(row[3]));
        Jobs[i].setMinMax(stoi(row[4]), stoi(row[5]));
        Jobs[i].setOpenings(stoi(row[6]));
        
        for (int m = 0, n = 7; n < 12; n+=2, m++) {
            if (row[n] != "") {
                Jobs[i].set_skill(row[n], row[n + 1], m);
            }
        }

        for (int n = 12; n < 17; n++) {
            if (row[n] != "") {
                Jobs[i].responsibilities[n-12] = row[n];
                Jobs[i].num_res++;
            }
        }

        int pos1 = line.find("[");
        int pos2 = line.find("]");
        string hiredStr = line.substr(pos1 + 1, pos2 - pos1 - 1);
        istringstream ss2(hiredStr);

            while (getline(ss2, hiredStr, ',')) {
                for (auto& user : users) {
                    if (user.get_username() == hiredStr) {
                        Jobs[i].addHired(user);
                    }
                }
            }

            int pos3 = line.find("^", pos2);
            string AppStr = line.substr(pos2 + 2, pos3 - pos2 - 2);
            istringstream ss3(AppStr);

            while (getline(ss3, AppStr, ',')) {
                for (auto& user : users) {
                    if (user.get_username() == AppStr) {
                        Jobs[i].addApplicant(user);
                    }
                }
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

        employer.setter_valid_account(true);
        employer.set_user_id_and_password(employers);
        employer.writeRecord();
        system("cls");
        SetColor(2);  cout << "Account was successfully created!\n" << endl;  SetColor(0);
        employer.display_details("user");
        employers.push_back(employer);
    }

    else{
        cout << "OoPs! An error occured while creating your account\nUser could not be aunthenticated!" << endl;
        employer.setter_valid_account(false);
    }

}

