#include <iostream>
#include <string>
using namespace std;

string arrcart[20];
float pricearr[50];
float finalprice[50];
float quantity[50];
float total = 0;
string category[7] = { "Meat","Dairy Products", "Fruits","Beverages","Vegetables","Bakeries","pantry" };
int num = 0;
void review();

struct product
{
	int code;
	float price;
	string name;
	string category;
	string Pdate;
	string Edate;
};

product pro[35] = { { 1,100,"chicken","Meat","25-3-2023","30-6-2023"},{ 2,110,"lamp","Meat","22-4-2023","6-6-2023"},
	{ 3,70,"salmon","Meat","3-3-2023","31-7-2023"},{ 4,120,"beef","Meat","21-2-2023","8-6-2023"},
	{ 5,90,"fish","Meat","26-3-2023","23-8-2023"}, { 6,50,"swiss_Cheese","Dairy Products","24-4-2023","24-7-2023"},
	{ 7,30,"butter","Dairy Products","26-1-2023","24-4-2023"}, { 8,4,"yogurt","Dairy Products","23-3-2023","24-7-2023"},
	{ 9,50,"cream","Dairy Products","27-4-2023","10-5-2023"},{ 10,50,"cheedar_Cheese","Dairy Products","24-4-2023","24-7-2023"},
	{ 11,20,"kiwi","fruits","21-3-2023","30-4-2023"},{ 12,18,"banana","fruits","16-3-2023","18-4-2023"},
	{ 13,15,"Orange","fruits","17-3-2023","24-4-2023"},{ 14,20,"watermelon","fruits","23-3-2023","25-4-2023"},
	{ 15,20,"mango","fruits","27-3-2023","15-4-2023"}, { 16,4,"water","Beverages","27-1-2023",""},
	{ 17,7,"pepsi","Beverages","21-3-2023","21-5-2024"},{ 18,30,"red_bull","Beverages","11-4-2023","8-5-2024"},
	{ 19,7,"fanta","Beverages","6-2-2023","1-4-2024"}, { 20,7,"7-up","Beverages","7-7-2022","23-12-2023"},
	{ 21,10,"cucumber","Vegetables","1-3-2023","4-7-2023"}, { 22,5,"tomato","Vegetables","11-2-2023","8-8-2023"},
	{ 23,5,"lettuce","Vegetables","7-3-2023","5-7-2023"},{ 24,10,"broccoli","Vegetables","8-3-2023","9-7-2023"},
	{ 25,10.5,"carrots","Vegetables","10-3-2023","9-7-2023"},{ 26,10,"bread","Bakeries","30-4-2023","30-5-2023"},
	{ 27,40,"cookies","Bakeries","22-4-2023","12-5-2023"},{ 28,50,"muffins","Bakeries","6-4-2023","9-5-2023"},
	{ 29,80,"cake","Bakeries","7-4-2023","11-5-2023"},{ 30,60,"pie","Bakeries","30-4-2023","30-5-2023"},
	{31,20,"rice","pantry","20-12-2022","20-12-2024"},{32,14,"pasta","pantry","12-5-2022","12-5-2024"},
	{33,50,"oil","pantry","13-7-2022","13-7-2025"},{34,20,"sugar","19-1-2023","19-7-2023"},
	{35,15,"vinegar","pantry","28-3-2023","28-9-2023"}

};

struct address {
	int flat, floor, block;
	string street;
};

struct User {
	string name;
	string phonenumber;
	int id;
	address location;
	string password;
};

void welcome()
{
	cout << "\t" << "\t" << "\t" << "\t" << "\t" << "Welcome to our Supermarket\n";
	cout << "\t" << "\t" << "\t" << "\t" << "\t" << "---------------------------\n";
}

void displaycategories()
{

	for (int i = 0; i < 7; i++)
	{
		cout << i + 1 << "- " << category[i];
		cout << endl;
	}
}

void chooseitem(int start, int end) {

	int choiceProduct;
	char addp;
	float quant;
	cout << "product code" << "\t\t" << "product name" << "\t\t" << "product price per one\n\n";
	for (int i = start; i < end; i++)
	{
		cout << pro[i].code << "\t\t\t" << pro[i].name << "\t\t\t" << pro[i].price << "  L.E" << endl;

	}
	cout << "\nChoose a product(by its code): " << endl;
	cin >> choiceProduct;
	for (int i = start; i <= end; i++)
	{


		if (choiceProduct == i)
		{
			cout << "\nChoosen product is " << pro[i - 1].name << endl;
			cout << "Product price is " << pro[i - 1].price << endl;
			cout << "Product production date is " << pro[i - 1].Pdate << endl;
			cout << "Product expiry date is " << pro[i - 1].Edate << endl << endl;
			cout << "Do you want to add this item to the cart? (y/n)" << endl;
			cin >> addp;
			if (addp == 'y' || addp == 'Y')
			{
				arrcart[num] = pro[i - 1].name;
				cout << "enter the quantity you want to buy:";
				cin >> quant;
				quantity[num] = quant;
				pricearr[num] = pro[i - 1].price;
				finalprice[num] = quant * pricearr[num];
				total = finalprice[num] + total;
				num++;
			}
		}
	}
}
void categoryitems()
{

	char answer;
	int ch;
	int cat;
	char addp;
	float quant;

	do
	{
		cout << "Enter a category: " << endl;
		cin >> cat;
		switch (cat)
		{
		case 1:
			cout << "------------------------------------------------------------------------------------------------------\n";
			cout << "\t\t\tcategory: " << category[0] << endl << endl;
			chooseitem(0, 5);
			break;

		case 2:
			cout << "------------------------------------------------------------------------------------------------------\n";
			cout << "\t\t\tcategory: " << category[1] << endl << endl;
			chooseitem(5, 10);
			break;
		case 3:
		{
			cout << "------------------------------------------------------------------------------------------------------\n";
			cout << "\t\t\tcategory: " << category[2] << endl;
			chooseitem(10, 15);
			break;

		}
		case 4:
		{
			cout << "------------------------------------------------------------------------------------------------------\n";
			cout << "\t\t\tcategory: " << category[3] << endl;
			chooseitem(15, 20);
			break;

		}
		case 5:
		{
			cout << "------------------------------------------------------------------------------------------------------\n";
			cout << "\t\t\tcategory: " << category[4] << endl;
			chooseitem(20, 25);
			break;

		}
		case 6:
		{
			cout << "------------------------------------------------------------------------------------------------------\n";
			cout << "\t\t\tcategory: " << category[5] << endl;
			chooseitem(25, 30);
			break;
		}
		case 7:
		{
			cout << "------------------------------------------------------------------------------------------------------\n";
			cout << "\t\t\tcategory: " << category[6] << endl;
			chooseitem(30, 35);
		}
		default:
			cout << "Invalid Choice" << endl;
		}
		cout << "Do you want to choose again? (y/n)" << endl;
		cin >> answer;
		if ((answer != 'y' && answer != 'Y') && (answer != 'n' && answer != 'N'))
			cout << "Invalid Output" << endl;
		else if (answer == 'y' || answer == 'Y')
			displaycategories();

	} while (answer == 'y' || answer == 'Y');

}

void totalprice() {
	string code;
	cout << "The Total price is :                                                        " << total << endl << endl;
	cout << "You have a 10% discount on your order enter the voucher to earn it (valid10)\n";
	cin >> code;
	if (code == "valid10")
	{
		cout << "\nThe Total price is :                                                  " << total * 0.9 << endl << endl;
		cout << "Thanks for ordering from us .\n";
		cout << "-----------------------------------------------------------------------------------------------------------\n\n";
	}
	else {
		cout << "Invalid Voucher \n";
		cout << "\nyout total is:                                                        " << total << endl << endl;
		cout << "Thanks for ordering from us .\n";
		cout << "-----------------------------------------------------------------------------------------------------------\n\n";
	}
}

void editcart()
{
	string chooseProduct;
	int chooseEdit;
	float addreduce;
	float previous;
	cout << "\t\t---------" << endl;
	cout << "\t\tEdit Menu" << endl;
	cout << "\t\t---------" << endl;
	cout << "1- Remove item" << endl;
	cout << "2- Add item" << endl;
	cout << "3-add quantity" << endl;
	cout << "4-reduce quantity" << endl;

	cin >> chooseEdit;
	switch (chooseEdit) {
	case 1:
		cout << "enter the item you want to remove: ";
		cin >> chooseProduct;
		for (int m = 0; m < num; m++) {
			if (chooseProduct == arrcart[m]) {
				num--;
				total -= finalprice[m];
				arrcart[m] = arrcart[m + 1];
				quantity[m] = quantity[m + 1];
				pricearr[m] = pricearr[m + 1];
				finalprice[m] = finalprice[m + 1];
			}
		}
		cout << "object removed succesfully\n";
		review();
		break;
	case 2:
		cout << "-----------------------------------------------------------------------------------------------------------------\n";
		displaycategories();
		categoryitems();
		review();
		break;
	case 3:
		cout << "enter the item: ";
		cin >> chooseProduct;
		cout << "add by: ";
		cin >> addreduce;
		for (int m = 0; m < num; m++) {
			if (chooseProduct == arrcart[m]) {
				quantity[m] += addreduce;
				previous = finalprice[m];
				finalprice[m] = quantity[m] * pricearr[m];
				total += finalprice[m] - previous;
			}
		}
		review();
		break;
	case 4:
		cout << "enter the item: ";
		cin >> chooseProduct;
		cout << "reduce by: ";
		cin >> addreduce;
		for (int m = 0; m < num; m++) {
			if (chooseProduct == arrcart[m]) {
				quantity[m] -= addreduce;
				previous = finalprice[m];
				finalprice[m] = quantity[m] * pricearr[m];
				total += finalprice[m] - previous;
			}
		}
		review();
		break;
	}
}

void review()
{
	int ans;
	cout << "----------------------------------------------------------------------------------------------------------------------\n";
	cout << "\t\t\t\t\t\t\t" << "review order\n";
	cout << "----------------------------------------------------------------------------------------------------------------------\n";
	cout << "you bought" << "\t\t" << "quantity" << "\t\t" << "price per one" << "\t\t" << "final price\n";
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			for (int m = 0; m < num; m++) {
				cout << arrcart[m] << "\t\t\t" << quantity[m] << "\t\t\t" << pricearr[m] << "\t\t\t" << finalprice[m];
				cout << endl;
			}
		}
	}
	cout << "----------------------------------------------------------------------------------------------------------------------\n";
	cout << "total:                                                                                    " << total << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------\n";
	cout << "1- Edit Menu " << endl;
	cout << "2- Checkout" << endl;
	cin >> ans;
	if (ans == 1)
	{
		editcart();
	}
	else if (ans == 2)
	{
		totalprice();
	}
	else
		cout << "Invalid input,please try again" << endl;
}

void signUp(User& user)
{

	cout << "Enter your name :";
	cin.ignore();
	getline(cin, user.name);
	cout << "Enter your ID (Numbers Only): ";
	cin >> user.id;
	cout << "Enter your location :\n ";
	cout << "--------------------\n";
	cout << "Enter the street :";
	cin.ignore();
	getline(cin, user.location.street);
	cout << "Enter the block number :";
	cin >> user.location.block;
	cout << "Enter the floor number :";
	cin >> user.location.floor;
	cout << "Enter the flat number :";
	cin >> user.location.flat;
	cout << "Enter your phone number (11 digits only) :";
	cin >> user.phonenumber;
	while (user.phonenumber.length() != 11)
	{
		cout << "Invalid phone number. Please enter 11 digits: ";
		cin >> user.phonenumber;
	}
	cout << "Enter your password (From 8 to 16 characters) : ";
	cin >> user.password;
	while (user.password.length() < 8 || user.password.length() > 16)
	{
		cout << "Invalid password. Please enter from 8 to 16 characters: ";
		cin >> user.password;
	}
	cout << "Sign up successful!\n";
	cout << "You have got a 10% discount on your first order\n";
	cout << "use code (valid10)\n";
	cout << "---------------------------------------------------------------------------------------\n";

}

bool login(User& user) {
	for (int i = 3; i >= 1; i--) {
		int checkid;
		string checkpassword;
		cout << "Enter your Id: ";
		cin >> checkid;
		cout << "enter your password: ";
		cin >> checkpassword;
		if (checkid == user.id && checkpassword == user.password) {
			cout << "Login successful!\n ";
			cout << "---------------------------------------------------------------------------------------\n";
			cout << "Products Menu" << endl;
			cout << "------------" << endl;
			displaycategories();
			categoryitems();
			review();
			return true;
		}
		else if (checkid != user.id || checkpassword != user.password) {
			if (i == 1) {
				cout << "Sorry !! something went wrong ";
				exit(0);
			}
			cout << "\nInvalid ID or password.try again\n" << i - 1 << " trials left\n\n";

		}
	}
}

void edit_info(User& user) {
	char ans;
	do
	{
		int choice;
		cout << "---------------------------------------------------------------------------------------\n";
		cout << "Edit Menu\n";
		cout << "1. Edit name\n";
		cout << "2. Edit ID \n";
		cout << "3. Edit location\n";
		cout << "4. Edit phone number\n";
		cout << "5. Edit password\n";
		cout << "Enter your choice: ";
		cin >> choice;
		char space;
		switch (choice) {
		case 1:
			cout << "Enter your new name:\n ";
			cin.ignore();
			getline(cin, user.name);
			cout << "Name updated successfully!\n";
			break;
		case 2:
			cout << "Enter your new ID: ";
			cin >> user.id;
			cout << "ID updated successfully!\n";
			break;
		case 3:
			cout << "Enter your location :\n ";
			cout << "--------------------\n";
			cout << "Enter the street :";
			cin.ignore();
			getline(cin, user.location.street);
			cout << "Enter the block number :";
			cin >> user.location.block;
			cout << "Enter the floor number :";
			cin >> user.location.floor;
			cout << "Enter the flat number :";
			cin >> user.location.flat;
			cout << "Location updated successfully!\n";
			break;
		case 4:
			cout << "Enter your new phone number : ";
			cin >> user.phonenumber;
			while (user.phonenumber.length() != 11)
			{
				cout << "Invalid phone number. Please enter 11 digits: ";
				cin >> user.phonenumber;
			}
			cout << "Phone number updated successfully!\n";
			break;
		case 5:
			cout << "Enter your new password : ";
			cin >> user.password;
			while (user.password.length() < 8 || user.password.length() > 16)
			{
				cout << "Invalid password. Please enter from 8 to 16 characters: ";
				cin >> user.password;
			}
			cout << "Password updated successfully!\n";
			break;
		default:
			cout << "Invalid choice!\n";
		}
		cout << "Do you want to edit something else ? (y/n)\n";
		cin >> ans;
		if (ans == 'n')
		{

			cout << "---------------------------------------------------------------------------------------\n";
			cout << "login : \n";
			login(user);

		}

	} while (ans == 'y');
}
void main_menu(User& user)
{
	int choice;
	cout << "Main Menu\n";
	cout << "---------\n";
	cout << "1. Sign up\n";
	cout << "2. Exit\n";
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		signUp(user);
		cout << "1. login\n";
		cout << "2. logout\n";
		cout << "3. Edit your information\n";
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "---------------------------------------------------------------------------------------\n";
			cout << "Login:\n";
			login(user);


			break;
		case 2:
			cout << "Goodbye!\n";
			break;
		case 3:
			edit_info(user);
			cout << "---------------------------------------------------------------------------------------\n";
			cout << "Products Menu" << endl;
			cout << "------------" << endl;
			displaycategories();
			categoryitems();
			review();


			break;
		default:
			cout << "Invalid choice!\n";
		}
	}
	else if (choice == 2)
		cout << "Goodbye!\n";
	else
		cout << "Invalid choice!\n";
}

int main() {

	welcome();
	User user;
	main_menu(user);
	system("pause");
	return 0;
}