#include <iostream>
#include <string>
using namespace std;
int i, category_index, category_number;
int v[25];
int item_statu[25];
int temp;
int chek_item_list = 0;
string  usre_email[25];
string usre_passward[25];
string user_name[25];
int suggestion_price;
int vb[25];
int category_counter[10];
int buyed_number = 0;
string temp1, temp2;
string name_item_price_suggestion;
int usre_id[25];
string item_owner[25];
string name_category[25], item_date[25], item_end_date[25];
int item_price[25];
int user_points[25];
int p[25];
struct user_info {
	string user_adress[25];
	int user_phone_number[25];
};
struct user_point {
	int item_rateing;
};
void login();
void signUp();
void selling_item();
void items_list();
void buy_item();
void confirm_buy_item();
void statu_of_item();
void rating_item();
void users_points();
void search_about_item();
void suggest_price();
void user_message_about_suggest_price();
void agree_suggestion();
void refuse_suggestion();
void tob_category();
int main()
{
	system(" COLOR f0 ");              // to return the black screen to white we use this
	cout << "----------------------------Welcome in Online Auction System------------------------" << endl << endl;
	cout << "1- sign up." << endl;
	cout << "2- Log in." << endl;
	cout << "Enter your Choice : ";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
        signUp();                    // sign up function
	}
	else if (choice == 2)
	{
		login();                    // log in function
		cout << "****************************" << endl << endl;
		items_list();
		// item list function will show the available item which has been selled by user
	}
	else {
		// this condition if the user enter wrong choice
		cout << "****************************" << endl << endl;
		cout << "Wrong on choice ... Please press enter to try again." << endl;
		cin.get();
		cin.get();
		// cin.get function makes us press enter first to enter on the second information
		main();
		// the user will try again if he entered wrong number
	}
}
void signUp()
{
	// The user will register here if he does not have an account
	cout << "****************************" << endl << endl;
	// here we ask the user how many peaple you want to regester 
	cout << "How many number of sign up do you want : ";
	int number_signUp;
	cin >> number_signUp;
	user_info user;
	for (i = 0; i < number_signUp; i++)
	{
		/*
		   we ask the user to input his E-mail which will log in by it leter
		   and his passward, he will chose it from numbers only or numbers and word or symbol
		   and his name and his ID and phone number and his adress In order to receive the items if he buy something
		*/
		cout << "****************************" << endl << endl;
		cout << " E-Mail : ";
		cin >> usre_email[i];
		cout << " Password : ";
		cin >> usre_passward[i];
		cout << " Your name : ";
		cin >> user_name[i];
		cout << " ID : ";
		cin >> usre_id[i];
		cout << " Phone number : ";
		cin >> user.user_phone_number[i];
		cout << " Your adress : ";
		cin >> user.user_adress[i];
	}
	// your regstration has been successfuled
	cout << "****************************" << endl << endl;
	cout << "Your regesytretion is successfuled ..Press enter to continuo. " << endl << endl;
	cin.get();
	cin.get();
	// you will return the main to log in with your accounnt 
	main();
}
void login()
{
	// we will ask the user to input his E-mai and his password to log in the progect
	string email, passward;            // the variable which the user input
	cout << "****************************" << endl << endl;
	cout << "Enter your E-Mail : ";
	cin >> email;
	cout << "Enter your password : ";
	cin >> passward;
	for (i = 0; i < 25; i++)
	{
		// here we search about his email and his bassword in the recorded arry
		if (email == usre_email[i] && passward == usre_passward[i])
		{
			// here we found his account....
			cout << "****************************" << endl << endl;
			cout << "Your login is successfuled ... " << endl;
			temp2 = user_name[i];
			// we will break from loop because we found his account, we don't want from it any thing
			break;
		}
	}
	if (i == 25)
	{
		// here if we didn't find the account from recordes....
		cout << "****************************" << endl << endl;
		cout << "Wrong in your name or your password, Please press enter to try again." << endl;
		cin.get();
		cin.get();
		// the user will try log in again..
		login();
	}
}
void selling_item()
{
	// if the user choose this fuction from choices, he will selle items to be added to item list..
	category_number = 1;         // the category number which the user choose it when he want to buy item from item list..
	while (true)
	{
		// this loop to ask the user if he want to selle other item or not..
		cout << "****************************" << endl << endl;
		cout << "The availabe categories: ( cars - accessories - shoes - clothes - sports - electronics - furniture - art - antique - books )" << endl;
		cout << "Enter The The name of category you want to selle: ";
		// the user will choose category from these.. 
		cin >> name_category[category_index];
		cout << "****************************" << endl << endl;
		/*
		  the user will enter the bid price of item and the date of the day which user will selle the
		  item in..
		  and the end date which the item whoud be unavailable in it..
		  and the program will ask user if he want to selle other item or not..
		*/
		cout << "Enetr the bid price of (" << category_number << ") item by dollars : ";
		cin >> item_price[category_index];
		cout << "Enter the item selle date : ";
		cin >> item_date[category_index];
		cout << "Enter the end date of (" << category_number << ") item : ";
		cin >> item_end_date[category_index];
		item_owner[category_number] = user_name[category_index];
		p[category_index] = usre_id[category_index];
		category_number++;
		chek_item_list++;    // this step to chek the item lest is empty or not.......
		cout << endl << "Are you want to selle other item: " << endl << "1- YES." << endl << "2-No." << endl << "Enter your choice:";
		int choice;           cin >> choice;
		if (choice == 1)
		{
			category_index++;
			continue;
			// continue to selle other item..
		}
		else
		{
			break;       // break loop if the user choose not selle other item..

		}
	}
	cout << "****************************" << endl << endl;
	cout << "The items has been salled.. press enter to continuo.." << endl;
	cin.get();
	cin.get();
	// program return the user to the item list to show him his item..
	items_list();
}
void items_list()
{
	// the item list function will show user the selled item to buy from them...
	int item_number = 1;           // number which the user choose it when he want to buy item from item list..
	cout << "****************************" << endl << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	// the program will welcome the user here...
	cout << "Hello " << user_name[i] << endl;
	cout << "------------------------------------------------------------------------------------" << endl << endl;
	cout << "***********[ The items list ]***********" << endl << endl;
	if (chek_item_list == 0)
	{
		// if the chek_item variable == 0 --->  this means that the item list is empty....
		cout << "                                       --Empty--                                         " << endl << endl << endl;
	}
	else
	{
		for (category_index = 0; category_index < category_number; category_index++)
		{
			// this loop will show all the selled items ..
			cout << "( " << item_number << " )" << name_category[category_index] << endl;
			cout << "- The item Price: " << item_price[category_index] << " $" << endl;
			cout << "- The item sale date: " << item_date[category_index] << endl;
			cout << "- The item end date: " << item_end_date[category_index] << endl;
			statu_of_item();  // this function to show if the item available or not..
			cout << "--------------------------------------------------------------------------------" << endl << endl;
			v[category_index] = item_number;    // this step is temp to help on suggest price fuction..
			item_number++;
		}
	}
	// these choices the user will choose from them when the all recorded items had been shown..
	cout << "1- Selling item." << endl;
	// to selle item ..
	cout << "2- Buy item." << endl;
	// to buy item .. 
	cout << "3- Points List" << endl;
	// to show the points list .. 
	cout << "4- Search about special item." << endl;
	// to search about sbecial item..
	cout << "5- My message." << endl;
	// to show your message..
	cout << "6- Log out." << endl;
	// to log out from program..
	cout << "7- Best selling items." << endl;
	// to show the top category .. 
	cout << "Enter your choice : ";
	int choice;          cin >> choice;
	if (choice == 1)
	{
		selling_item();
	}
	else if (choice == 2)
	{
		buy_item();
	}
	else if (choice == 3)
	{
		users_points();
	}
	else if (choice == 4)
	{
		search_about_item();
	}
	else if (choice == 5)
	{
		user_message_about_suggest_price();
	}
	else if (choice == 6)
	{
		main();
	}
	else if (choice == 7)
	{
		tob_category();
	}
	else
	{
		// here if the user input wrong choice..
		cout << "****************************" << endl << endl;
		cout << "Wrong on choice ... Please press enter to try again." << endl;
		cin.get();
		cin.get();
		// the program return the user to item list to again his choice .. 
		items_list();
	}
}
void buy_item()
{
	// here if the user want to buy item from items list
	cout << "****************************" << endl << endl;
	cout << "Enter the number of item you want to buy : ";
	// the program ask the user to enter the number of item on item list 
	int item_number_you_want;      // number of item.....
	cin >> item_number_you_want;
	for (category_index = 0; category_index < 25; category_index++)
	{
		// this loop to search about item which the user entered its number 
		if (item_number_you_want == v[category_index])
		{
			// here the proogram found the item, and will show the item information to confirm the buying operation ..
			cout << "****************************" << endl << endl;
			cout << "------------------------------------------------------------------------------------" << endl;
			cout << "- The category Of item: " << name_category[category_index] << endl;
			cout << "- The item Price: " << item_price[category_index] << " $" << endl;
			cout << "- The item sale date: " << item_date[category_index] << endl;
			cout << "- The item end date: " << item_end_date[category_index] << endl;
			statu_of_item();
			// we will break from loop because we found the choosen item, we don't want from it any thing
			break;
		}
	}
	if (category_index == 25)
	{
		// here if the program not found the choosen item by the user .. 
		cout << "****************************" << endl << endl;
		cout << "Wrong on choice ... Please press enter to try again." << endl;
		cin.get();
		cin.get();
		// the user will try his buying operation again .. 
		buy_item();
	}
	else
	{
		// here if the program found the choosen item by the user ..
		cout << "------------------------------------------------------------------------------------" << endl << endl;
		cout << endl << "Are you sure from this operation: " << endl << "1- YES." << endl << "2- NO." << endl << "Enter your choice: ";
		// here the program ask the user if he sure from his operation or not .. 
		int choice;    cin >> choice;
		if (choice == 1)
		{
			// here if the user sure from his operation .. 
			if (item_statu[category_index] == 1)
			{
				// here if the choosen category is not availabe
				cout << "****************************" << endl << endl;
				cout << "------------------------------------------------------------------------------------" << endl;
				// the program will tell the user .. 
				cout << "This category is not availabe." << endl;
				cout << "------------------------------------------------------------------------------------" << endl << endl;
				cout << "1- Item list." << endl << "2- Main." << endl << "Enter your choice: ";
				int choice1;             cin >> choice1;
				if (choice1 == 1)
					items_list();
				else if (choice1 == 2)
					main();
				else {
					// here if the user input wrong number .. 
					cout << "****************************" << endl << endl;
					cout << "Wrong on choice ... Please press enter to try again." << endl;
					cin.get();
					cin.get();
					// the program will return the user on buy function to try again ..
					buy_item();
				}
			}
			else {
				// here if the choosen item by user is available .. 
				confirm_buy_item();
				main();
			}
		}
		else if (choice == 2)
		{
			// here if the user choose NO, or reverse his decision..
			cout << "****************************" << endl << endl;
			cout << "Your operation has been canceled .. Press enter to continuo..";
			cin.get();
			cin.get();
			// the program will show to the user the item list .. 
			items_list();
		}
		else
		{
			// here if the user input wrong number .. 
			cout << "****************************" << endl << endl;
			cout << "Wrong on choice ... Please press enter to try again." << endl;
			cin.get();
			cin.get();
			// the program will return the user on buy function to try again ..
			buy_item();
		}
	}
}
void confirm_buy_item()
{
	// here if the user sure from his operation and the item is available .. 
	cout << "****************************" << endl << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	// the program will show to the user the bid price of the item tho ask him if he confirm or not ..
	cout << "The Price of item: " << item_price[category_index] << " $" << endl;
	cout << "------------------------------------------------------------------------------------" << endl << endl;
	cout << "1- Confirm the process." << endl << "2- Another price suggestion." << endl << "Enetr your choice: ";
	int choice;     cin >> choice;
	if (choice == 1)
	{
		// here if the user confirm the bid price .. 
		buyed_number++;       // this step is temp to help on tob category function .. 
		item_statu[category_index] = 1;      // this step to show that the item became not available .. 
		cout << "****************************" << endl << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		// the program will congratulat the user on buying the item .. 
		cout << "Congratulation........." << endl;
		cout << "------------------------------------------------------------------------------------" << endl << endl;
		cout << "1- Rate the item." << endl << "2- Main." << endl << "3-Item list" << endl << "Enter your choice: ";
		int choice1;    cin >> choice1;
		if (choice1 == 1)
		{
			rating_item();      // this function to rate the itemif it seek you .. 
		}
		else if (choice1 == 2)
		{
			main();
		}
		else
		{
			items_list();
		}
	}
	else if (choice == 2)
	{
		// here if the user refused the bid price ant want to offer other price on the seller 
		name_item_price_suggestion = name_category[category_index];
		/*
		  these steps are temps to help on suggest price function ..
		*/
		temp = category_index;
		suggest_price();      // this function to offer other price
	}
	else
	{
		// here if the user input wrong choice 
		cout << "****************************" << endl << endl;
		cout << "Wrong on choice ... Please press enter to try again." << endl;
		cin.get();
		cin.get();
		// the program will return user to try agian..
		confirm_buy_item();
	}
}
void statu_of_item()
{
	/*
	  this function to know if the item is available or not
	  the variable (item_statu) will change -- if the item is availabe the variable is equal 0.
	  and if the variable is not available the variable is equal 1.
	*/
	if (item_statu[category_index] == 1 || (item_statu[temp] == 1 && temp == category_index))
	{
		cout << "- The statu: " << "Unavailable(soled)." << endl;
		// the step [ (item_statu[temp] == 1 && temp == category_index) ] is temp for help ... 
	}
	else
	{
		cout << "- The statu: " << "Available." << endl;
	}
}
void rating_item()
{
	// this function to rate the item if the user like it .. 
	user_point item;   // the struct user_point 
	cout << "****************************" << endl << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	// this rating start from 1 and end in 5 -- the program will ask the user..
	cout << "If you like it, you can rate it" << endl << "Rating (1-5) according to your liking" << endl;
	cout << "------------------------------------------------------------------------------------" << endl << endl;
	cout << "Your rating:";
	cin >> item.item_rateing;     // the number of rating 
	if (item.item_rateing >= 1 && item.item_rateing <= 2)
	{
		// here the seller not take any point 
		cout << "****************************" << endl << endl;
		cout << "1- Items list." << endl << "2- Main." << endl << "Enter your choice: ";
		int choice;        cin >> choice;
		if (choice == 1)
		{
			items_list();
		}
		else if (choice == 2)
		{
			main();
		}
		else
		{
			// here if the user enter wrong choice
			cout << "****************************" << endl << endl;
			cout << "Wrong on choice ... Please press enter to try again." << endl;
			cin.get();
			cin.get();
			// try rating again .....
			rating_item();
		}
	}
	else if (item.item_rateing >= 3 && item.item_rateing <= 5)
	{
		// here the seller will take a point 
		cout << "****************************" << endl << endl;
		for (category_index = 0; category_index < 25; category_index++)
		{
			// this loop to search about seller of rated item 
			if (p[category_index] == usre_id[category_index])
			{
				// te program found the seller 
				// the program will gave the seller a point .. 
				user_points[category_index]++;
				// we will break from loop because we found the choosen item, we don't want from it any thing
				break;
			}
		}
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "Congratulation, We seek to like you more." << endl;
		cout << "------------------------------------------------------------------------------------" << endl << endl;
		cout << "1- main" << endl << "2- Items list" << endl << "Enter your choice: ";
		int choice1;            cin >> choice1;
		if (choice1 == 1)
		{
			main();
		}
		else if (choice1 == 2)
		{
			items_list();
		}
		else
		{
			// here if the user input wrong choice .. 
			cout << "****************************" << endl << endl;
			cout << "Wrong on choice ... Please press enter to try again." << endl;
			cin.get();
			cin.get();
			// the program return the user to try again
			rating_item();
		}
	}
	else {
		// here if the user input number less than 1 or more than 5 
		cout << "****************************" << endl << endl;
		cout << "The rating form 1 to 5 not more or less, Press Enter to try again.." << endl;
		cin.get();
		// the program return the user to try again
		rating_item();
	}
}
void users_points()
{
	// this function to show the user the points of users .. 
	int order_number = 1;   // this variable to order the users only
	cout << "****************************" << endl << endl;
	cout << "**********[ The points list ]***********" << endl << endl;
	for (category_index = 0; category_index < 25; category_index++)
	{
		// this loop to find if the user has point at least or not 
		if (usre_id[category_index] == 0)
		{
			// here to find if the seller is the user which lo in now or not
			break;
			// break the loop if the program found the seller
		}
		if (p[category_index] == usre_id[category_index])
		{
			// here to distribute the points .. 
			cout << order_number << "- " << user_name[category_index] << " ----> " << user_points[category_index] << " Points " << endl << endl;
			cout << "----------------------------------------------------------------------------------------" << endl << endl;
		}
		order_number++;
	}
	cout << endl << "1- Buck" << endl << "2- main" << endl << "Enter your choice: ";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		items_list();
	}
	else if (choice == 2)
	{
		main();
	}
	else
	{
		// here if the user input wrong choice 
		cout << "****************************" << endl << endl;
		cout << "Wrong on choice ... Please press enter to try again." << endl;
		cin.get();
		cin.get();
		// the program return the user to try again
		users_points();
	}
}
void search_about_item()
{
	// this function will search about sbecial item by using its name or its name and price .. 
	cout << "****************************" << endl << endl;
	// the program ask the user if he want to search about item by using its name or its name and price
	cout << "1- Search about category only." << endl << "2- Search about category and price." << endl << "Enter your choice: ";
	int choice_search;        cin >> choice_search;
	if (choice_search == 1)
	{
		// here if user choose to search about item by using its name only, he will enter the item name
		cout << "****************************" << endl << endl;
		cout << "Enter the name of category of item you want: ";
		string name_category_search;           cin >> name_category_search;
		for (category_index = 0; category_index < 25; category_index++)
		{
			// here the program will search about input item from recorded items 
			if (name_category_search == name_category[category_index])
			{
				break;
				// we will break from loop because we found the choosen item, we don't want from it any thing
			}
		}
		if (category_index == 25)
		{
			// here if the program not fount the item from items lest, it will warn the user to try again..
			cout << "****************************" << endl << endl;
			cout << "------------------------------------------------------------------------------------" << endl;
			cout << "The entered category is not existing." << endl;
			cout << "------------------------------------------------------------------------------------" << endl << endl;
			cout << "1- Try again." << endl << "2- main" << endl << "Enter your choice: ";
			int choice;          cin >> choice;
			if (choice == 1)
			{
				search_about_item();
			}
			else if (choice == 2)
			{
				main();
			}
			else {
				// here if the user input wrong choice..
				cout << "****************************" << endl << endl;
				cout << "Wrong on choice ... Please press enter to try again." << endl;
				cin.get();
				cin.get();
				// the program will return the user to try his choice again....
				search_about_item();
			}
		}
		else {
			// here if the program found the item in items list  .......
			cout << "****************************" << endl << endl;
			cout << "------------------------------------------------------------------------------------" << endl;
			// the program will show the recorded information of category .. 
			cout << "- The category: " << name_category[category_index] << endl;
			cout << "- The price: " << item_price[category_index] << endl;
			cout << "- The item Date: " << item_date[category_index] << endl;
			cout << "- The item end date: " << item_end_date[category_index] << endl;
			statu_of_item();
			cout << "-------------------------------------------------------------------------------------" << endl << endl;
			// the program will ask the user if want to buy this item or not .. 
			cout << "1- Buy this item." << endl << "2- main." << endl << "Enter your choice: ";
			int choice1;          cin >> choice1;
			if (choice1 == 1)
			{
				// if he want to buy item 
				item_statu[category_index] = 1;
				confirm_buy_item();
			}
			else if (choice1 == 2)
			{
				main();        // if he want to log out 
			}
			else
			{
				// here if the user input wrong choice..
				cout << "****************************" << endl << endl;
				cout << "Wrong on choice ... Please press enter to try again." << endl;
				cin.get();
				cin.get();
				// the program will return the user to try his choice again....
				search_about_item();
			}
		}
	}
	else if (choice_search == 2)
	{
		// here if the user want to search about item by using its name and price .. 
		cout << "****************************" << endl << endl;
		cout << "- Enter the name of category of item you want: ";
		// the program ask him to enter the item name 
		string name_category_search;           cin >> name_category_search;
		cout << "- Enter the price of item you want: ";
		// the program ask him to enter the item price .. 
		int price_item_search;          cin >> price_item_search;
		for (category_index = 0; category_index < 25; category_index++)
		{
			// here the program will search about input item from recorded items 
			if (name_category_search == name_category[category_index] && price_item_search == item_price[category_index])
			{
				break;
				// we will break from loop because we found the choosen item, we don't want from it any thing
			}
		}
		if (category_index == 25)
		{
			// here if the program not fount the item from items lest, it will warn the user to try again..
			cout << "****************************" << endl << endl;
			cout << "------------------------------------------------------------------------------------" << endl;
			cout << "The entered category is not existing." << endl;
			cout << "------------------------------------------------------------------------------------" << endl << endl;
			cout << "1- Try again." << endl << "2- main" << endl << "Enter your choice: ";
			int choice2;          cin >> choice2;
			if (choice2 == 1)
			{
				search_about_item();
			}
			else if (choice2 == 2)
			{
				main();
			}
			else {
				// here if the user input wrong choice..
				cout << "****************************" << endl << endl;
				cout << "Wrong on choice ... Please press enter to try again." << endl;
				cin.get();
				cin.get();
				// the program will return the user to try his choice again....
				search_about_item();
			}
		}
		else {
			// here if the program found the item in items list  .......
			cout << "****************************" << endl << endl;
			cout << "------------------------------------------------------------------------------------" << endl;
			// the program will show the recorded information of category .. 
			cout << "- The category: " << name_category[category_index] << endl;
			cout << "- The price: " << item_price[category_index] << endl;
			cout << "- The item Date: " << item_date[category_index] << endl;
			cout << "- The item eng date: " << item_end_date[category_index] << endl;
			statu_of_item();
			cout << "-------------------------------------------------------------------------------------" << endl << endl;
			// the program will ask the user if want to buy this item or not .. 
			cout << "1- Buy this item." << endl << "2- main." << endl << "Enter your choice: ";
			int choice3;          cin >> choice3;
			if (choice3 == 1)
			{
				// if he want to buy item 
				item_statu[category_index] = 1;
				confirm_buy_item();
			}
			else if (choice3 == 2)
			{
				main();           // if he want to log out 
			}
			else
			{
				// here if the user input wrong choice..
				cout << "****************************" << endl << endl;
				cout << "Wrong on choice ... Please press enter to try again." << endl;
				cin.get();
				cin.get();
				// the program will return the user to try his choice again....
				search_about_item();
			}
		}
	}
	else
	{
		// here if the user input wrong choice..
		cout << "****************************" << endl << endl;
		cout << "Wrong on choice ... Please press enter to try again." << endl;
		cin.get();
		cin.get();
		// the program will return the user to try his choice again....
		search_about_item();
	}
}
void suggest_price()
{
	// this function to suggest other price, if user refused the bid price of item
	cout << "****************************" << endl << endl;
	// the program ask user to enter the suggest price .. 
	cout << "Enter the price you want by dollars: ";
	cin >> suggestion_price;          // suggestion price 
	temp1 = temp2;     // this step to help on the second function 
	cout << "****************************" << endl << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	// the program agreed the price and will offer it to the seller 
	cout << "The suggested Price has been sent to the seller, Wait for approval or rejection soon" << endl;
	cout << "------------------------------------------------------------------------------------" << endl << endl;
	cout << "1- Main." << endl << "2- Items list." << endl << "Enter your choice: ";
	int choice;              cin >> choice;
	if (choice == 1)
	{
		main();
	}
	else if (choice == 2)
	{
		items_list();
	}
	else
	{
		// here if the user input wrong choice..
		cout << "****************************" << endl << endl;
		cout << "Wrong on choice ... Please press enter to try again." << endl;
		cin.get();
		cin.get();
		// the program will return the user to try his choice again....
		suggest_price();
	}
	/*
	   the program will oferr the suggestion price to the seller and this offer will appear
	   on the seller message --- he will agree the price or refuse it
	*/
	user_message_about_suggest_price();  // this function will appear the price to the seller
}
void user_message_about_suggest_price()
{
	// this function to offer the suggestion price on the seller and ask him if he agree or not .... 
	if (vb[category_index] == 1)
	{
		agree_suggestion();          // this function if he agreed
	}
	else if (vb[category_index] == 2)
	{
		refuse_suggestion();        // this function if he refused
	}
	int index = 1;
	if (item_owner[index] == temp2 && suggestion_price >= 1)
	{
		/*
		  the program will chek if the user is the seller or not ..
		  if yes the program will send the offer in his message ..
		  if not the program break this step -----------
		*/
		cout << "****************************" << endl << endl;
		cout << "Someone wants to buy an item (" << name_item_price_suggestion << ") at a price: " << suggestion_price << " $." << endl;
		// the program will ask the seller if he agree or not 
		cout << "1- Agree." << endl << "2- Refuse." << endl << "3- Main." << endl << "Enter your choice: ";
		cin >> vb[category_index];      // seller decision
		if (vb[category_index] == 1)
		{
			// if the seller agreed the offer .. 
			buyed_number++;       // the variable to show how many item buyed ... 
			item_statu[temp] = 1;         // the statu of category in items list 
			suggestion_price = 0;         // this step to not show this message again 
			cout << "****************************" << endl << endl;
			cout << "------------------------------------------------------------------------------------" << endl;
			cout << "The operation has been successfuled" << endl;
			cout << "------------------------------------------------------------------------------------" << endl << endl;
			cout << "1- main." << endl << "2- Item list" << endl << "Enter yor choice: ";
			int choice;            cin >> choice;
			if (choice == 1)
			{
				main();
			}
			else if (choice == 2)
			{
				items_list();
			}
			else
			{
				// here if the user input wrong choice..
				cout << "****************************" << endl << endl;
				cout << "Wrong on choice ... Please press enter to try again." << endl;
				cin.get();
				cin.get();
				// the program will return the user to try his choice again....
				cout << "****************************" << endl << endl;
				cout << "------------------------------------------------------------------------------------" << endl;
				cout << "The operation has been successfuled" << endl;
				cout << "------------------------------------------------------------------------------------" << endl << endl;
				cout << "1- main." << endl << "2- Item list" << endl << "Enter yor choice: ";
				int choice2;            cin >> choice2;
				if (choice2 == 1)
				{
					main();

				}
				else if (choice2 == 2)
				{
					items_list();
				}
			}
		}
		else if (vb[category_index] == 2)
		{
			// here if the seller refused the offer ...
			suggestion_price = 0;     // this step to not show this message again 
			cout << "****************************" << endl << endl;
			cout << "------------------------------------------------------------------------------------" << endl;
			cout << "The operation has been successfuled, the price has been refused." << endl;
			cout << "------------------------------------------------------------------------------------" << endl << endl;
			cout << "1- Main." << endl << "2- Item list." << endl << "Enter your choice: ";
			int choice3;          cin >> choice3;
			if (choice3 == 1)
			{
				main();
			}
			else if (choice3 == 2)
			{
				items_list();
			}
			else
			{
				// here if the user input wrong choice..
				cout << "****************************" << endl << endl;
				cout << "Wrong on choice ... Please press enter to item list." << endl;
				cin.get();
				cin.get();
				// the program will return the user to try his choice again....
				items_list();
			}
		}
		else if (vb[category_index] == 3)
		{
			main();         // here if the seller want to Postpone his dicistion . .
		}
		else
		{
			// here if the user input wrong choice..
			cout << "****************************" << endl << endl;
			cout << "Wrong on choice ... Please press enter to try again." << endl;
			cin.get();
			cin.get();
			// the program will return the user to try his choice again....
			user_message_about_suggest_price();
		}
	}
	else
	{
		// here to return the message function after the seller dicistion 
		cout << "****************************" << endl << endl;
		cout << "************[ Empty ]*************" << endl << endl << endl;
		cout << "1- Main." << endl << "2- Item list." << endl << "Enter your choice: ";
		int choice4;              cin >> choice4;
		if (choice4 == 1)
		{
			main();
		}
		else if (choice4 == 2)
		{
			items_list();
		}
		else
		{
			// here if the user input wrong choice..
			cout << "****************************" << endl << endl;
			cout << "Wrong on choice ... Please press enter to try again." << endl;
			cin.get();
			cin.get();
			// the program will return the user to try his choice again....
			user_message_about_suggest_price();
		}
	}
}
void agree_suggestion()
{
	/*
	   this function if the seller agreed the suggestion price
	   there is message will be sent to the buyer shows that the seller agreed his offer
	   the statu of the item will be not available ----------
	*/
	if (temp1 == temp2)
	{
		// the program chek if the user is the buyer or not to send the message 
		cout << "****************************" << endl << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "The seller Confirmed your price, Congratulation" << endl;
		cout << "------------------------------------------------------------------------------------" << endl << endl;
		// the program ask the user if he want to rate the item or not ...
		cout << "1- Rate The item" << endl << "2- Item list" << endl << "3- Main" << endl << "Enter your choice: ";
		int choice;                      cin >> choice;
		if (choice == 1)
		{
			rating_item();
		}
		else if (choice == 2)
		{
			items_list();
		}
		else if (choice == 3)
		{
			main();
		}
		else
		{
			// here if the user input wrong choice..
			cout << "****************************" << endl << endl;
			cout << "Wrong on choice ... Please press enter to item list." << endl;
			cin.get();
			cin.get();
			// the program will return the user to try his choice again....
			items_list();
		}
	}
}
void refuse_suggestion()
{
	/*
	   this function if the seller refused the suggestion price
	   there is message will be sent to the buyer shows that the seller refused his offer
	*/
	if (temp1 == temp2)
	{
		// the program chek if the user is the buyer or not to send the message 
		cout << "****************************" << endl << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "The seller refused your price." << endl;
		cout << "------------------------------------------------------------------------------------" << endl << endl;
		cout << endl << "1- Item list." << endl << "2- Main." << endl << "Enter your choice: ";
		int choice;          cin >> choice;
		if (choice == 1)
		{
			items_list();
		}
		else if (choice == 2)
		{
			main();
		}
		else
		{
			// here if the user input wrong choice..
			cout << "****************************" << endl << endl;
			cout << "Wrong on choice ... Please press enter to your message." << endl;
			cin.get();
			cin.get();
			// the program will return the user to try his choice again....
			refuse_suggestion();
		}
	}
}
void tob_category()
{
	// this function to calculate the most category has been selled 
	// te category --- > (cars - accessories - shoes - clothes - sports - electronics - furniture - art - antique - books)
	cout << "****************************" << endl << endl;
	int most = 0;
	string most_name;           // this name of tob category ...
	int num, count = 0, a = 0;
	for (int x = 0; x <= buyed_number; x++)
	{
		// here the program chek if the statu of category available or not  
		if (item_statu[x] == 1)
		{
			a = 1;               // this step for help ....
		}
	}
	if (buyed_number == 0 || a != 1)
	{
		// here if there is not one category selled at least .. 
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "No items selled" << endl;
		cout << "--------------------------------------------------------------------------------" << endl << endl;
	}
	else if (buyed_number >= 1)
	{
		/*
			buyed number show to the number of items selled to show
			what is the tob category of them ..
		*/
		for (int x = 0; x <= buyed_number; x++)
		{
			// here the program will chek every selled item to know how mant it selled 
			if (item_statu[x] == 1)
			{
				// here if the statu of category is not available 
				// here the program will chek every selled item to know how mant it selled 
				if (name_category[x] == "cars")
				{
					category_counter[0]++;      // (0) is the index of cars .. 
				}
				else if (name_category[x] == "accessories")
				{
					category_counter[1]++;      // (1) is the index of accessories .. 
				}
				else if (name_category[x] == "shoes")
				{
					category_counter[2]++;      // (2) is the index of shoes .. 

				}
				else if (name_category[x] == "clothes")
				{
					category_counter[3]++;      // (3) is the index of clothes .. 

				}
				else if (name_category[x] == "sports")
				{
					category_counter[4]++;      // (4) is the index of sports .. 
				}
				else if (name_category[x] == "electronics")
				{
					category_counter[5]++;      // (5) is the index of electronics .. 
				}
				else if (name_category[x] == "furniture")
				{
					category_counter[6]++;      // (6) is the index of furniture .. 
				}
				else if (name_category[x] == "art")
				{
					category_counter[7]++;      // (7) is the index of art .. 
				}
				else if (name_category[x] == "antique")
				{
					category_counter[8]++;      // (8) is the index of antique .. 
				}
				else if (name_category[x] == "books")
				{
					category_counter[9]++;      // (9) is the index of books .. 
				}
				for (int k = 0; k <= 9; k++)
				{
					// here the program will chek what is the most selled category .. 
					if (category_counter[k] >= most)
					{
						most = category_counter[k];
						if (k == 0)
						{
							most_name = "cars";
						}
						else if (k == 1)
						{
							most_name = "accessories";
						}
						else if (k == 2)
						{
							most_name = "shoes";
						}
						else if (k == 3)
						{
							most_name = "clothes";
						}
						else if (k == 4)
						{
							most_name = "sports";
						}
						else if (k == 5)
						{
							most_name = "electronics";
						}
						else if (k == 6)
						{
							most_name = "furniture";
						}
						else if (k == 7)
						{
							most_name = "art";
						}
						else if (k == 8)
						{
							most_name = "antique";
						}
						else if (k == 9)
						{
							most_name = "books";
						}
						num = k;
					}
				}
			}
		}
	}
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "The most selled category is: " << most_name << endl;
	cout << "--------------------------------------------------------------------------------" << endl << endl;
	for (int i = 0; i < 10; i++)
	{
		// here the program will empty te indix after finish the function .. 
		category_counter[i] = 0;
	}
	cout << "1- item list." << endl << "2- Main." << endl << "Enter your choice: ";
	int choice;          cin >> choice;
	if (choice == 1)
	{
		items_list();
	}
	else if (choice == 2)
	{
		main();
	}
	else {
		// here if the user enter wrong choice .. 
		cout << "****************************" << endl << endl;
		cout << "Wrong on choice ... Please press enter to try again." << endl;
		cin.get();
		cin.get();
		// here the user will try again ... 
		cout << "****************************" << endl << endl;
		cout << "1- item list." << endl << "2- Main." << endl << "Enter your choice: ";
		int choice;          cin >> choice;
		if (choice == 1)
		{
			items_list();
		}
		else if (choice == 2)
		{
			main();
		}
	}
}