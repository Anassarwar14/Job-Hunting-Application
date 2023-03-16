#include<iostream>
#include<string>
#include<vector>
//#include"oop_lab_project.h"
#include"admin.h"
//#include"employeer.h"
int main()
{
	int choice, check1 = 0;
	vector <user> users;//used to access the user objects which would be returned from the admin
	vector <employer> employers;
	admin a;
	user u;
	employer e;

	cout << "\t\t\t\t+++++WELCOME TO JOBAL+++++\n\n\t\t\tSearching for High paying reliable Jobs?\n\t\t\t\tYou are at the right place!" << endl;

	do
	{
		cout << "\nEnter from the choice of action:\n1: Sign up as a User \n2: Sign up as an Employer\n\nPress 3 to exit" << endl;
		cin >> choice;

		switch (choice)
		{

		case 1:
			cout << "-->Enter User details<--" << endl;
			u.user_setter(a, u.get_type());
			if (u.get_validity() == false)
			{
				u.~user();
			}
			//else
			//{
			//	users.push_back(u);
			//}
			break;
		case 2:
			cout << "Enter company details: " << endl;
			e.user_setter(a, e.get_type());
			e.set_min_wage();
			e.set_company_name();
			a.admin_check_employer(e);
			if (e.get_validity() == false)
			{
				e.~employer();
			}
			else
			{
				//employers.push_back(e);
				e.display_details(e.get_type());
				e.display_employer_min_wageAND_name();

			}
			break;
		case 3:
			check1 = 1;
			break;
		default:
			cout << "Invalid entry! Please enter again" << endl;
			break;

		}
	} while (check1 == 0);


}