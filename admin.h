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
   string adminID, adminPass, email, re_entered_email, phone_num, first_name, last_name, education;
   int age, re_checked_email;
   bool check_email, check_age, phone_check, check_fname, check_lname, email_comapre_check;
   vector <user> users;
   vector <employer> employers;
   vector <Job> Jobs;

public:
    admin() {
        adminID = "anas"; //can take user input to set(just saving time)
        adminPass = "anas123";
        readUserRecord();
        readJobRecord();
        readEmployerRecord();
    }


    string get_username() {
        return adminID;
    }
    string get_password() {
        return adminPass;
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


    bool isUserEmployee(user u) {
        for (int i = 0; i < employers.size(); i++) {
            if (employers[i].isEmployee(u)) {
                return true;
            }
        }

        return false;
    }
    void cursorBack() {
        for (int i = 0; i < 21; i++) {
            cout << "\b \b";
        }
        cout << "\x1b[1A\t\t   \b\b";
    }

    //Admin
    void ControlPanel() {
        int manage, option, x;
        
        do {
            system("cls");
            cout << "1. Manage Jobs\n2. Manage Employers\n3. Manage Users\n\nPress 4 to return to main menu\n\n";
            cin >> manage;
            switch (manage) {
            case 1:
                system("cls");
                for (int i = 0; i < Jobs.size(); i++) {

                    if (i == 0) { cout << "Total Jobs: " << Jobs.size() << "\n---Jobs---\n\n"; }

                    SetColor(0); cout << i + 1 << ". " << Jobs[i].Name << endl
                        << "   Applicants: " << Jobs[i].num_applicants
                        << "   Hired: " << Jobs[i].hiredEmployees
                        << "   Interviewing: " << Jobs[i].num_intviews
                        << "   Openings: " << Jobs[i].available_openings << endl << endl;
                }

                cout << "1. View\n2. Modify\n3. Remove\n\n";
                cin >> option;

                cout << "\n\nEnter Job-Number: ";
                do {
                    cin >> x;
                } while (x > Jobs.size());
                --x;

                if (option == 1) {
                    system("cls");
                    Jobs[x].displayJob();
                    SetColor(10); cout << "\n\n\n\t\t\t\t\t[C]ontinue";
                    cout << "\n\t\t\t\t\t ________"; SetColor(0);  _getch();
                }
                else if (option == 2) {
                    Jobs[x].modifyJob();
                    readJobRecord();
                }
                else {
                    Jobs[x].deleteJob();
                    readJobRecord();
                    readEmployerRecord();
                    cout << "Job Successfully Removed!"; Sleep(700);
                }

                break;

            case 2:
                system("cls");
                for (int i = 0; i < employers.size(); i++) {

                    if (i == 0) { cout << "Total Employers: " << employers.size() << "\n---Employers---\n\n"; }

                    SetColor(0); cout << i + 1 << ". " << employers[i].get_company_name() << endl
                        << "   Jobs Posted: " << employers[i].get_jobCount()
                        << "   Charged Uptil Now: $" << employers[i].getPayment() << endl << endl;
                }

                cout << "1. View\n2. Modify\n3. Remove\n\n";
                cin >> option;

                cout << "\n\nEnter Employer-Number: ";
                do {
                    cin >> x;
                } while (x > employers.size());
                --x;

                if (option == 1) {
                    system("cls");
                    employers[x].display_details("Employer");
                }
                else if (option == 2) {
                    employers[x].modifyDetails();
                }
                else {
                    employers[x].deleteRecord();
                    readJobRecord();
                    readEmployerRecord();
                    cout << "Employer Successfully Removed!"; Sleep(700);
                }

                break;

            case 3:
                system("cls");
                for (int i = 0; i < users.size(); i++) {
                    if (i == 0) { cout << "Total Users: " << users.size() << "\n---Users---\n\n"; }

                    SetColor(0); cout << i + 1 << ". " << users[i].get_first_name() << " " << users[i].get_last_name() << "\t(@" << users[i].get_username() << ")" << endl
                        << "   Major: " << users[i].get_department() << endl
                        << "   Account Status: " << users[i].Account_Status << "|  Paid: $" << users[i].getPayment() << endl << endl;
                }

                cout << "1. View\n2. Modify\n3. Remove\n\n";
                cin >> option;

                cout << "\n\nEnter User-Number: ";
                do {
                    cin >> x;
                } while (x > users.size());
                --x;

                if (option == 1) {
                    system("cls");
                    users[x].display_details("user");
                }
                else if (option == 2) {
                    users[x].modifyDetails();
                }
                else {
                    users[x].deleteRecord();
                    readUserRecord();
                    cout << "User Successfully Removed!"; Sleep(700);
                }
                break;
                
            case 4:
                break;

            default:
                cout << "Wrong Entry!"; Sleep(800);
                system("cls");
                break;
            }
        } while (manage != 4);
    }
    void ViewProfits() {
        int total_profit = 0, choice = 0, m = 0;
        system("cls");
        do {
            cout << "1. Total Profits\n2. Profit Summary\n\n";
            cin >> choice;
        } while (choice > 2);

        system("cls");
        for (int i = 0; i < users.size(); i++) {
            total_profit += users[i].getPayment();
            if (choice == 2 && users[i].getPayment() != 0) {
                SetColor(0); cout << ++m << ". " << users[i].get_first_name() << " " << users[i].get_last_name() << "\t(@" << users[i].get_username() << ")" << endl
                    << "   Charged: $" << users[i].getPayment() << endl << endl;
            }
        }
        for (int i = 0; i < employers.size(); i++) {
            total_profit += employers[i].getPayment();
            if (choice == 2 && employers[i].getPayment() != 0) {
                SetColor(0); cout << ++m << ". " << employers[i].get_company_name() << endl
                    << "   Charged: $" << employers[i].getPayment() << endl << endl;
            }
        }
        
        cout << "\n\nTotal Profit: $" << total_profit; _getch();
            
    }

    
    //User
    void EmpSub(user * u) {
        bool x;
        if (u->get_type() == "user") {
            x = u->Subscribe();
            if (x == true) {
                readUserRecord();
            }
            
        }
        else {
            if (employer* e = dynamic_cast<employer*>(u)) {
                e->AllEmployees();
            }
        }

    }

    void viewJobs(user * u) {
        int m = 0, x = 0, y = 0, z = 0;
        char choice;
        vector<bool> flag;
        system("cls");
        if (u->get_type() == "user") {
            flag.resize(Jobs.size());
            for (int i = 0; i < Jobs.size(); i++) {
                for (int j = 0; j < Jobs[i].num_applicants; j++) {

                    if (u->get_username() == Jobs[i].getApplicant(j).get_username()) {
                        if (m == 0) { cout << "---Applied To---\n\n"; }

                        SetColor(6); cout << ++m << ". " << Jobs[i].Name << " ";

                        for (int k = 0; k < Jobs[i].num_intviews; k++) {
                            if (Jobs[i].getApplicant(j) == Jobs[i].getInterviewee(k)) {
                                SetColor(11); cout << "\t{Shortlisted For Interview}"; SetColor(5);
                            }
                        }

                        for (int k = 0; k < Jobs[i].num_Scr; k++) {
                            if (Jobs[i].getApplicant(j) == Jobs[i].getScreeners(k)) {
                                SetColor(11); cout << "\t{Instant Hire after Screening test}"; SetColor(5);
                                flag[i] = true;
                            }
                        }

                        SetColor(6); cout << endl << "   Total Applicants: " << Jobs[i].num_applicants << endl << endl; SetColor(5);
                    }
                }

                for (int j = 0; j < Jobs[i].hiredEmployees; j++) {
                    if (*u == Jobs[i].getHired(j)) {
                        SetColor(5); cout << "---Currently Employed As---\n\n"; SetColor(6); cout << ++m << ". " << Jobs[i].Name << "\n   Collegues: " << Jobs[i].hiredEmployees - 1 << endl; SetColor(5);

                    }
                }
                    
                
            }

            if (m != 0) {
                cout << "\n\nEnter Job-Number: ";
                do {
                    cin >> x;
                } while (x > m);
                --x;

                if (flag[x] == true) {
                    cout << "\n1:Take the Screening Test\n2:Display Job\n";
                    cin >> y;

                    if (y == 1) {
                        Jobs[x].Screening_test(u);
                        readJobRecord();
                        readEmployerRecord();
                    }
                }

                system("cls");
                Jobs[x].displayJob();
                SetColor(10); cout << "\n\n\n\t\t\t\t\t[C]ontinue";
                cout << "\n\t\t\t\t\t ________";  _getch();
            }
            else {
                cout << "Not Applied Anywhere!"; _getch();
            }
           
            system("cls");
        }
        else {
            if (employer* e = dynamic_cast<employer*>(u)) {
                if (m == 0) { cout << "Total Jobs Posted: " << e->get_jobCount() << "\n---Jobs Posted---\n\n"; }
                for (int j = 0; j < e->get_jobCount(); j++) {
                    SetColor(6); cout << ++m << ". " << e->Jobs[j]->Name << endl
                        << "   Applicants: " << e->Jobs[j]->num_applicants
                        << "   Hired: " << e->Jobs[j]->hiredEmployees
                        << "   Interviewing: " << e->Jobs[j]->num_intviews
                        << "   Openings: " << e->Jobs[j]->available_openings << endl << endl;
                }

                if (m != 0) {
                    cout << "\n\nEnter Job-Number: ";
                    do {
                        cin >> x;
                    } while (x > m);

                    --x;
                    system("cls");
                    e->Jobs[x]->displayJob();

                    SetColor(6); cout << "\n\n\n\t\t\t\t[M]odify Details"; SetColor(10); cout << "\t[V]iew Applicants"; SetColor(12); cout << "\t[C]ancel"; SetColor(7);
                    cout << "\n\t\t\t\t ______________\t\t _______________\t ______"; SetColor(5);

                    choice = toupper(_getch());
                    if (choice == 'M') {
                        e->Jobs[x]->modifyJob();
                    }
                    else if (choice == 'V') {
                        system("cls");
                        flag.clear();
                        flag.resize(e->Jobs[x]->num_applicants);

                        cout << "-^-\033[4mApplicants\033[24m-^-\n";
                        for (int i = 0; i < e->Jobs[x]->num_applicants; i++) {
                            cout << i + 1 << ". "
                                << e->Jobs[x]->getApplicant(i).get_first_name() << " "
                                << e->Jobs[x]->getApplicant(i).get_last_name() << "\t(@"
                                << e->Jobs[x]->getApplicant(i).get_username() << ")";

                            if (e->Jobs[x]->getApplicant(i).Account_Status == "Premium") {
                                SetColor(9); cout << " [*Recommended]"; SetColor(5);
                            }

                            for (int k = 0; k < e->Jobs[x]->num_intviews; k++) {
                                if (e->Jobs[x]->getApplicant(i) == e->Jobs[x]->getInterviewee(k)) {
                                    SetColor(11); cout << "\t{Interviewing}"; SetColor(5);
                                    flag[i] = true;
                                }
                            }

                            for (int k = 0; k < e->Jobs[x]->num_Scr; k++) {
                                if (e->Jobs[x]->getApplicant(i) == e->Jobs[x]->getScreeners(k)) {
                                    SetColor(11); cout << "\t{Pending Screening test}"; SetColor(5);
                                    flag[i] = true;
                                }
                            }

                            cout << endl;
                        }


                        if (e->Jobs[x]->num_applicants != 0) {
                            cout << "\n\nEnter Applicant-Number: ";
                            cin >> y;
                            --y;

                            e->Jobs[x]->getApplicant(y).display_details("user"); _getch();

                            if (!flag[y]) {
                                SetColor(4); cout << "\nChoice of Action:"; SetColor(5); cout << "\n1. Hire Applicant\n2. Shortlist for Interview\n3. Selection by Screening test\n\nEnter any num to contiue\n";
                                cin >> z;

                                if (z == 1) {
                                    e->Jobs[x]->addHired(e->Jobs[x]->getApplicant(y));
                                    for (int i = 0; i < Jobs.size(); i++) {
                                        Jobs[i].removeHired(e->Jobs[x]->getApplicant(y));
                                    }
                                }
                                else if (z == 2) { e->Jobs[x]->addInterviewee(e->Jobs[x]->getApplicant(y)); }
                                else if (z == 3) { e->Jobs[x]->addScreeners(e->Jobs[x]->getApplicant(y)); }

                                e->Jobs[x]->updateRecord();
                            }

                        }
                        else {
                            SetColor(4); cout << "Sorry! No Applicants Yet!"; Sleep(800); SetColor(5);
                        }
                    }

                    readJobRecord();
                    readEmployerRecord();
                
                }
                else {
                    cout << "No Jobs Posted!"; _getch();
                }
            
                system("cls");
            }    
               
        }
            
        SetColor(5);
    }

    void displayAllJobs(vector<int> T, user * u) {
            int m = 0, x = 5, y = 6, a = 0;
            int n = 0, JobsTobePrinted = Jobs.size();
            char choice = 'A';

            if (!T.empty()) {
                JobsTobePrinted = T.size();
            }

            for (int i = 0, j = 0; j < JobsTobePrinted; i++, j++) {

                if (!T.empty()) { i = T[j]; }


                for (int z = 0; z < employers.size(); z++) {
                    for (int w = 0; w < employers[z].get_jobCount(); w++) {
                        if (Jobs[i].JobID == employers[z].Jobs[w]->JobID) {
                            n = z;
                        }
                    }
                }


                gotoxy(x, y);
                SetColor(8); cout << "   --------JOB#" << ++m << "--------";


                gotoxy(x, ++y);
                SetColor(1); cout << "|>" << Jobs[i].Name << "<|";


                gotoxy(x, ++y);
                SetColor(6); cout << "[" << employers[n].get_company_name() << "]"; SetColor(8);

                gotoxy(x, ++y);
                cout << "Salary: "; SetColor(2);  cout << "$" << Jobs[i].min_salary << "-" << Jobs[i].max_salary; SetColor(8);


                gotoxy(x, ++y);
                cout << "Location: "; SetColor(4); cout << employers[n].get_city(); SetColor(8);

                gotoxy(x, ++y);
                cout << "Openings Left: "; SetColor(3); cout << Jobs[i].available_openings;
                y = 6;
                x += 45;
  
            
                SetColor(7);
                gotoxy(2, 16);
                for (int k = 0; k < 29; k++) {
                    cout << "____";
                }
                SetColor(3); gotoxy(3, 18); cout << "<[P:Prev\t\t\t\t\t\tS:Select\t\t\t\t\t     More:M]>";
                SetColor(11); gotoxy(1, 28); cout << "Press 'E' to exit"; SetColor(5);

            

                //cases for moving accross pages
                if (j == JobsTobePrinted - 1 && m % 3 != 0) {
                    x = 5, y = 6;
                    do {
                        choice = toupper(_getch());
                        if (choice == 'P' && m > 3 && (m - 2) % 3 == 0) {
                            m -= 5;
                            j -= 5;//although m and i j have 1 unit dist diff i j gets ++ once the cycle repeats
                            i -= 5;//in the case of showall
                            system("cls");
                            break;
                        }
                        else if (choice == 'P' && m > 3 && (m - 1) % 3 == 0) {
                            m -= 4;
                            j -= 4;
                            i -= 4;
                            system("cls");
                            break;
                        }
                    } while (choice != 'S' && choice != 'E');

                }
                else if (j != JobsTobePrinted - 1 && m % 3 == 0) {
                    x = 5, y = 6;
                    do {
                        choice = toupper(_getch());
                        if (choice == 'P' && m > 3) {
                            m -= 6;
                            j -= 6;
                            i -= 6;
                            system("cls");
                            break;
                        }

                        if (choice == 'M') { system("cls"); }
                    } while (choice != 'M' && choice != 'S' && choice != 'E');
                    
                }
                else if (j == JobsTobePrinted - 1 && m <= 3) {
                    do {
                        choice = toupper(_getch());
                    } while (choice != 'S' && choice != 'E');
                }




                if (choice == 'S') {
                    gotoxy(1, 23); cout << "Enter Job-Num#: ";
                    do {
                        cin >> a;

                        if (a > m || a < 0) { 
                            cout << "Unavailable Re-enter!"; Sleep(500); 
                            cursorBack();
                        }
                    } while (a > m || a < 0);
                
                
                    a--;
                    if(!T.empty()){ a = T[a]; }
                
               
                    Jobs[a].ApplyJob(*u, isUserEmployee(*u));

                    x = 5; y = 6; m = 0; i = -1; j = -1; choice = 'B';
                    system("cls");
                    
                }
                else if (choice == 'E') { system("cls"); break; }


            }

        }

    void JobsSearch(user * u) {
            int search, search2, x = 0, y = 0;
            string cities[] = { "Karachi", "Lahore", "Islamabad" };
            vector<string>skills; vector<int> index;
            bool flag = false;

            system("cls");
            cout << "Search:\n1. By Industry\n2. By City\n3. By Skills\n4. By Comapany\n5. Show All\n\nPress 6 to go to main menu" << endl;
            cin >> search;

            readJobRecord();
            readEmployerRecord();
            system("cls");
            switch (search)
            {
            case 1:
                cout << "1. Computer science\\IT\n2. Medical\n3. Engineering" << endl;
                cin >> search2;
                system("cls");

                for (int i = 0; i < Jobs.size(); i++) {
                    for (int j = 0; j < employers.size(); j++)
                    {
                        for (int k = 0; k < employers[j].get_jobCount(); k++) {
                            if (Jobs[i].JobID == employers[j].Jobs[k]->JobID) {
                                if (employers[j].get_department() == "Computer Science" && search2 == 1) {
                                    index.push_back(i);
                                }
                                else if (employers[j].get_department() == "Medical" && search2 == 2) {
                                    index.push_back(i);
                                }
                                else if (employers[j].get_department() == "Engineering" && search2 == 3) {
                                    index.push_back(i);
                                }
                            }
                        }

                    }
                }
                displayAllJobs(index, u); index.clear();
                break;
        
            case 2:
                for (int i = 1; i <= 3; i++) {
                    cout << i << ". " << cities[i - 1] << endl;
                }
                cin >> x;
                system("cls");

                for (int i = 0; i < Jobs.size(); i++) {
                    for (int j = 0; j < employers.size(); j++){
                        for (int k = 0; k < employers[j].get_jobCount(); k++) {
                            if (Jobs[i].JobID == employers[j].Jobs[k]->JobID) {
                                if (employers[j].get_city() == cities[x - 1]) {
                                    index.push_back(i);
                                }
                            }

                        }
                    }
                }
                displayAllJobs(index, u); index.clear();
                break;
            
            case 3:
                for (int i = 0; i < Jobs.size(); i++) { //preventing duplicate skills being printed
                    for (int j = 0; j < 5; j++, y++) {
                        for (int k = 0; k < skills.size(); k++) {
                            if (Jobs[i].Job_skills[j][0] == skills[k]) {
                                flag = true;
                            }
                        }

                        if (flag) { flag = false; continue; }
                        if (Jobs[i].Job_skills[j][0] == "") { continue; }

                           skills.push_back(Jobs[i].Job_skills[j][0]);
                       
                    }
                
                }

                for (int i = 0; i < skills.size(); i++) {
                    cout << i + 1 << ". " << skills[i] << endl;
                }
                cin >> x;
                system("cls");


                for (int i = 0; i < Jobs.size(); i++) { //preventing duplicate skills being printed
                    for (int j = 0; j < 5; j++) {
                        if (skills[x-1] == Jobs[i].Job_skills[j][0]) {
                            index.push_back(i);
                        }
                    }
                }

                displayAllJobs(index, u); index.clear();
                break;
     
            case 4:        
                for (int i = 0; i < employers.size(); i++) {
                    SetColor(6); cout << i + 1 << ". |" << employers[i].get_company_name() << "|"; SetColor(3); cout << "\n   " << employers[i].get_department() << "\n\n";
                }
                SetColor(5);
                cin >> x;
                
                --x;
                if (u->Account_Status == "Premium") {
                    cout << "1: Employer Profile\n2: Continue to Jobs";
                    cin >> y;

                    if (y == 1) {
                        employers[x].display_details("Employer");
                    }
                }

                system("cls");
                for (int i = 0; i < Jobs.size(); i++) {
                    for (int j = 0; j < employers.size(); j++) {
                        for (int k = 0; k < employers[j].get_jobCount(); k++) {
                            if (Jobs[i].JobID == employers[j].Jobs[k]->JobID) {
                                if (employers[j].get_company_name() == employers[x].get_company_name()) {
                                    index.push_back(i);
                                }
                            }

                        }
                    }
                }
                displayAllJobs(index, u); index.clear();
                break;
        
            case 5:
                displayAllJobs(index, u);
                break;
        
            case 6:
                break;

            default:
                cout << "Invalid Input!" << endl; Sleep(650);
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
                if (u->get_type() == "user") {
                    cout << "1. Search For A Job\n\n2. View Hired/Applied to Jobs\n\n3. Subscribe to Premium*";
                }
                else {
                    cout << "1. Post A Job\n\n2. View Jobs Posted\n\n3. All Employees";
                }
                cout << "\n\n4. View Account Details\n\n5. Modify Acccount Details\n\n6. Logout\n" << endl;
                cin >> search1;

                switch (search1)
                {
                case 1:
                    if (u->get_type() == "user") {
                        JobsSearch(u);
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
                    viewJobs(u);
                    break;


                case 3:
                    EmpSub(u);
                    break;

                case 4:
                    u->display_details(u->get_type());
                    system("cls");
                    break;

                case 5:
                    u->modifyDetails();

                    readUserRecord();
                    readJobRecord();
                    readEmployerRecord();
                    break;

                case 6:
                    SetColor(5); cout << "\n\t\t\t\t\tLogging out.."; Sleep(300); cout << "."; Sleep(500); SetColor(0);
                    break;

                default:
                    cout << "Wrong Entry!"; Sleep(400);
                    system("cls");
                    break;
                }
            } while (search1 != 6);

     }
    void login() {
        int search;

        do
        {
            system("cls");
            cout << "1. Control Panel\n\n2. View Profits\n\n3. Logout\n\n";
            cin >> search;
            switch (search)
            {
            case 1:
                ControlPanel();
                break;

            case 2:
                ViewProfits();
                break;

            case 3:
                SetColor(5); cout << "\n\t\t\t\t\tLogging out.."; Sleep(300); cout << "."; Sleep(500); SetColor(0);
                break;

            default:
                cout << "Wrong Entry!"; Sleep(400);
                system("cls");
                break;
            }
        } while (search != 3);

    }




    void readUserRecord() {
        vector<string> row;
  
        string line, word;

        int i = 0, n = 0;

        //counting number of records
        fstream file("user.csv", ios::in);

        getline(file, line);
        while (getline(file, line)) {
            n++; 
        }

        file.close();

        users.resize(n);


        //reading records
        file.open("user.csv", ios::in);

        getline(file, line);
        while (getline(file, line)) {

            row.clear();

            istringstream ss(line);

            while (getline(ss, word, ',')) {

                row.push_back(word);

            }

                users[i].set_idPass(row[0], row[1]);
                users[i].set_first_name(row[2]);
                users[i].set_last_name(row[3]);
                users[i].set_acc_status(row[4]);
                users[i].set_age(stoi(row[5]));
                users[i].set_education(row[6]);
                users[i].set_email(row[7]);
                users[i].set_phone_number(row[8]);
                users[i].set_city(row[9]);
                users[i].set_department(row[10]);
                users[i].set_sub_depart(row[11]);
                for (int m = 0 , n = 12; n < row.size(); n+=2, m++) {
                        users[i].set_skill(row[n], row[n+1], m);
                }

                i++;        

        }
    }

    void readEmployerRecord() {
            vector<string> row;

            string line, word;

            int i = 0, n = 0;
            employers.clear(); 

            //counting number of records
            fstream file("employer.csv", ios::in);

            getline(file, line);
            while (getline(file, line)) {
                n++;
            }

            file.close();

            employers.resize(n);


            //reading records
            file.open("employer.csv", ios::in);

            getline(file, line);
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
                                employers[i].addJobEmployees(&Job);
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
        Jobs.clear();

        //counting number of records
        fstream file("Jobs.csv", ios::in);

        getline(file, line);
        while (getline(file, line)) {
            n++;
        }

        file.close();

        Jobs.resize(n);


        //reading records
        file.open("Jobs.csv", ios::in);

        getline(file, line);
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

            for (int n = 17; n < 23; n++) {
                if (row[n] != "") {
                    Jobs[i].responsibilities[n-17] = row[n];
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

                pos3 = line.find_last_of("^");
                int pos4 = line.find_last_of("~");
                string IntStr = line.substr(pos3 + 2, pos4 - pos3 - 3);
                istringstream ss4(IntStr);


                while (getline(ss4, IntStr, ',')) {
                    for (auto& user : users) {
                        if (user.get_username() == IntStr) {
                            Jobs[i].addInterviewee(user);
                        }
                    }
                }

                pos4 = line.find_last_of("~");
                int pos5 = line.find_last_of("|");
                string ScrStr = line.substr(pos4 + 2, pos5 - pos4 - 3);
                istringstream ss5(ScrStr);


                while (getline(ss5, ScrStr, ',')) {
                    for (auto& user : users) {
                        if (user.get_username() == ScrStr) {
                            Jobs[i].addScreeners(user);
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

