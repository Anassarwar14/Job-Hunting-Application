#include<iostream>
#include<string>
#include<vector>
//#include"user_emp.h"
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

int main()
{
	vector <user> users;//used to access the user objects which would be returned from the admin
	vector <employer> employers;
	int choice, check1 = 0, i = 0, check2 = 0, search1, search2, search3, count = 0, userSize = 0, empSize = 0;
	admin a;
	user u;
	employer e;

	string user_name, password, department, sub_department;
	



	cout << "\t\t\t\t+++++WELCOME TO JOBAL+++++\n\n\t\t\tSearching for High paying reliable Jobs?\n\t\t\t\tYou are at the right place!" << endl;

	do
	{
		cout << "\nEnter from the choice of action:\n1: Sign up as a User\n2: Sign up as an Employer\n3. Login as a User\n4. Login as an Employee \n\nPress 5 to exit" << endl;
		cin >> choice;

		switch (choice)
		{

		case 1:
			cout << "-->Enter User details<--" << endl;
			u.setType("user");
			u.user_setter(a, u.get_type());
			a.admin_check_user(u);
			
			if(u.get_validity() == true)
			{
				users.push_back(u);

			}
			break;

		case 2:
			cout << "Enter company details: " << endl;
			e.user_setter(a, e.get_type());
			e.set_min_wage();
			e.set_company_name();
			a.admin_check_employer(e);
			if (e.get_validity() == true)
			{
				employers.push_back(e);
				e.display_details(e.get_type());
				e.display_employer_min_wageAND_name();
			}
			break;

		case 3:
			cout << "Enter Username: ";
			cin >> user_name;
			users = a.get_users();//////////////
			userSize = users.size();
			employers = a.get_employers();
			empSize = employers.size();
			if (users.size() == 0)//////////////////
			{
				cout << "NO account of user exist" << endl;
			}
			else
			{
				for (i = 0; i < userSize; i++)
				{
					u = users[i];
					//cout << u.get_username() << endl;
					if (users[i].get_username() == user_name)//check
					{
						count = 0;
						do
						{
							cout << "Enter password: ";
							cin >> password;
							if (users[i].get_password() == password)
							{
								cout << "Hello " << users[i].get_first_name() << "! hope you are doing well" << endl;
								do
								{
									check1 = 0;
									cout << "enter 1 if you want to search for a job\n 2.see personal details" << endl;
									cin >> search1;
									switch (search1)
									{
									case 1:
										cout << "enter 1 if related to computer science/IT\n2 if related to medical field\n enter 3 if from engineering" << endl;
										cin >> search2;
										switch (search2)
										{
										case 1:
											department = "Comuter Science";
											do
											{
												check2 = 0;
												cout << "press:\n1.search by sub_department \n 2.Search by skills\n3.search by sub department and skills\n4.Show results" << endl;
												cin >> search3;
												switch (search3)
												{
												case 1:
													sub_department = subdepartment_CS();
													for (i = 0; i < empSize; i++)
													{
														if (employers[i].get_department() == department && employers[i].get_sub_depart() == sub_department)
														{
															employers[i].display_details(employers[i].get_type());
															employers[i].display_employer_min_wageAND_name();
															employers[i].display_id();
														}
													}

													break;
												case 2:
													break;
												case 3:
													break;
												default:
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
										break;
									default:
										check1 = 1;
										break;
									}
								} while (check1 == 1);

							}
							else
							{

								cout << "Incorrect Password!!" << endl;
								cout << "Attempt: " << count+1 << "/3" << endl;
								count++;
							}
						} while (count < 3);


					}
				}
			}
			break;

		case 5:
			check1 = 1;
			break;
		default:
			cout << "Invalid entry! Please enter again" << endl;
			break;

		}
	} while (check1 == 0);


}