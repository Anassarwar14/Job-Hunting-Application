#include<iostream>
#include<string>
#include <conio.h>
#include <Windows.h>
#include <iomanip>
#include<vector>
#include"admin.h"


//vector <user> users;//used to access the user objects which would be returned from the admin



string subdepartment_CS()
{
	string sub_depart;
	int check2 = 0, subdepart;
	do
	{

		check2 = 0;
		cout << "Computer Science FIELDS:" << endl;
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
			sub_depart = " Cloud Solutions Architect";

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
			cout << "Invalid choice. Please try again." << endl;
			check2 = 1;
			break;
		}
	} while (check2 == 1);
	return sub_depart;
}
void frame() {
	system("cls");
	int i, j, k;

	SetColor(8);
	for (i = 0; i < 25; i++) {
		for (j = 5; j < 90; j++) {
			gotoxy(j, i);
			cout << " ";

			if (j == 5 || j == 90 - 1) {
					gotoxy(j, i);
					cout << "!";
			}

			
			if (i == 0 || i == 25 - 1) {
				gotoxy(j, i);
				cout << "~";
			}
		}
	}
	gotoxy(15, 3);
	SetColor(0);//default color
}

void intro() {

	system("Color E7");
	frame();
	gotoxy(32, 6);
	SetColor(5);
	cout << "+++++WELCOME TO JOBAL+++++";
	SetColor(1);
	cout << "\n\n\n\n\t\t\t   Ready to hunt for high paying Jobs ? \n\n\t\t\t\tYou are at the right place!" << endl;
	SetColor(8);
	cout << "\n\n\n\t\t\t\tPress any key to continue";

	_getch();
	system("cls");
	//frame();
}


int main()
{
	vector <user> users;//used to access the user objects which would be returned from the admin
	vector <employer> employers;
	int choice, check1 = 0, i = 0, check2 = 0, count = 0, userSize = 0, empSize = 0, incUsername = 0, getch();
	char _end = 'e';
	admin a;
	user u;
	employer e;

	string user_name, password, department, sub_department;
	
	
	//Job j;
	//system("cls");
	//j.displayJob();
	//_getch();
	
	intro();
	
	do
	{	
		system("Color F0");
		frame();
		
		cout << "Enter from the choice of action:\n\t\t1: Sign up as a User\n\t\t2: Sign up as an Employer\n\t\t3: Login as a User\n\t\t4: Login as an Employer \n\n\t\tPress 5 to exit\t\t";
		cin >> choice;
		system("cls");
		switch (choice)
		{

		case 1:
			SetColor(1); cout << "-->Enter User details<--\n" << endl; SetColor(4);
			//u.setType("user");
			u.user_setter(a);
			a.admin_check_user(u);
			getch();

			break;
			
		case 2:
			SetColor(1); cout << "-->Enter Company details<--\n" << endl; SetColor(0);
			e.user_setter(a);
			a.admin_check_employer(e);
			getch();

			break;

		case 3:
			do {
			frame();
			cout << "-----LOGIN-----\n\n\t\t";

			a.readUserRecord();
			users = a.get_users();
			
				cout << "Enter Username: ";
				cin >> user_name;
				


				incUsername = 1;
				for (i = 0; i < users.size(); i++)////Use userSize again if error appears
				{
					if (users[i].get_username() == user_name)//check
					{
						count = 0;
						incUsername = 0;
						do
						{
							gotoxy(16, 7);
							cout << "Enter password: ";
							cin >> password;

							if (users[i].get_password() == password)
							{
								a.login(&users[i]);
								break; //count =3;
							}
							else
							{
								gotoxy(10, 16);
								SetColor(4);
								cout << "Incorrect Password!!\tAttempt: " << count + 1 << "/3" << endl;
								SetColor(0);
								count++;
							}
						} while (count < 3);
						break;
					}
				}

				if (incUsername == 1) {
					gotoxy(9, 18); SetColor(4);  cout << "Incorrect Username! Press any key to continue\n\n\n\t ";
					SetColor(8); cout << "Press 'B' to return"; _end = toupper(getch());
				}

			}while (_end != 'B' && incUsername == 1);
			
			break;


		case 4:
			do {
				frame();
				cout << "-----LOGIN-----\n\n\t\t";

				a.readEmployerRecord();
				employers = a.get_employers();

				cout << "Enter Username: ";
				cin >> user_name;


				incUsername = 1;
				for (i = 0; i < employers.size(); i++)////Use userSize again if error appears
				{
					if (employers[i].get_username() == user_name)//check
					{
						count = 0;
						incUsername = 0;
						do
						{
							gotoxy(16, 7);
							cout << "Enter password: ";
							cin >> password;

							if (employers[i].get_password() == password)
							{
								a.login(&employers[i]);
								break; //count =3;
							}
							else
							{
								gotoxy(10, 16);
								SetColor(4);
								cout << "Incorrect Password!!\tAttempt: " << count + 1 << "/3" << endl;
								SetColor(0);
								count++;
							}
						} while (count < 3);
						break;
					}
				}


				if (incUsername == 1) {
					gotoxy(9, 18); SetColor(4);  cout << "Incorrect Username! Press any key to continue\n\n\n\t "; 
					SetColor(8); cout << "Press 'B' to return"; _end = toupper(getch()); 
				}

			} while ( _end != 'B' && incUsername == 1);

			break;

		case 5://added so it doesnt go to default
			break;

		default:
			frame();
			SetColor(4);
			cout << "Invalid entry! Press any key to continue" << endl;
			getch();
			break;

		}
	} while (choice != 5);

}



//issues/TODO:
//respons in txt missing
//complete individual Job display 
//choice to view applicants in view jobs (interviees employees jobwise also)
//modify details
//premium account subsc etc feature
//.csv/in another branch

