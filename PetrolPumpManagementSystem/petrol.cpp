#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class movie
{
public:
	char moviename[15], seats[15], viewfuel[10], searchfuel[10], addfuel[10], price[5], pass[10], adrs[20],buffer[100], name[10], movieid[10], num[11], seatnum[10], ind[5], s_num[10], st_no[5];
} stdrec[30];
class fuel {
	public:
	   char date[30],exported[10],sold[10],buffer[100], price[10];
};
movie m2[100];
int main();
void details();
void addemployee();
void searchemployee();
void modifyemp();
void delete_record();
void displayFile();
void addfuel();
void viewfuel();
int get_num_records();
void searchfuel();

void retrieve_details();
void employeedetails();
			
void fueldetails();

int checkid(char movieid[10])
{
	fstream in;
	movie m;
	in.open("employee.txt", ios::in);
	while (!in.eof())
	{
		in.getline(m.ind, 5, '|');
        in.getline(m.movieid, 10, '|');
		in.getline(m.name, 15, '|');
		in.getline(m.num, 15, '|');
		in.getline(m.adrs, 20, '\n');

		if (strcmp(m.movieid, movieid) == 0)
		{
			return 1;
		}
	}
	in.close();
}
// ADMIN LOGIN FUNCTION
void  adminlogin()
{
	fstream in;
	char name[10], pass[10];
	in.open("adminlogin.txt", ios::in);
	if (!in)
	{
		cout << "\nUnable to open the file in input mode";
		return;
	}
	cout << "\nENTER THE USERNAME = ";
	cin >> name;
	cout << "\nENTER THE PASSWORD = ";
	cin >> pass;
	movie m;
	while (!in.eof())
	{
		in.getline(m.name, 10, '|');
		in.getline(m.pass, 10, '\n');

		if (strcmp(m.name, name) == 0 && strcmp(m.pass, pass) == 0)
		{
			cout << "\n LOGGED IN SUCCESFULLY...! \n";
			details();
		}
	}

	cout << "\n ENTER THE VALID USERNAME AND PASSWORD";
	adminlogin();
	return;
}


// PETROL PUMP TWO MODULES
void details()
{

	int choice;
	for (;;)
	{
		cout << "\n0:EXIT";
		cout << "\n1:FUEL DETAILS OPERATIONS";
		cout << "\n2:EMPLOYEE DETAILS OPERATIONS";
		cout << "\n\nENTER THE CHOICE :";
		cin >> choice;

		switch (choice)
		{
		case 1:
			fueldetails();
			break;
		case 2:
			employeedetails();
			break;
		case 0:
			main();
		default:
			cout << "\nINVALID INPUT...!";
			break;
		}
	}
}
void employeedetails() {

	int choice;
	for (;;)
	{
		cout << "\n0:EXIT";
		cout << "\n1:ADD EMPLOYEE DETAILS";
		cout << "\n2:SEARCH EMPLOYEE DETAILS";
		cout << "\n3:MODIFY EMPLOYEE DETAILS";
		cout << "\n4:VIEW EMPLOYEE DETAILS";
		cout << "\n5:DELETE EMPLOYEE";
		cout << "\n\nENTER YOUR CHOICE :";
		cin >> choice;

		switch (choice)
		{
		case 1:
			addemployee();
			break;
		case 2:
			searchemployee();
			break;
		case 3:
			modifyemp();
			break;
		case 4:
			displayFile();
			break;
		case 5:
		    delete_record();
			break;
		case 0:
			main();
		default:
			cout << "\nINVALID INPUT...";
			break;
		}
	}
}
// FUEL DETAILS OPERATIONS
void fueldetails() {
	int choice;
	for (;;)
	{
		cout << "\n0:exit";
		cout << "\n1:ADD FUEL DETAILS";
		cout << "\n2:VIEW FUEL DETAILS";
		cout << "\n3:SEARCH FUEL DETAILS";
		
		cout << "\n0:EXIT";
		cout << "\n\nENTER YOUR CHOICE :";
		cin >> choice;

		switch (choice)
		{
		case 1:
			addfuel();
			break;
		case 2:
			viewfuel();
			break;
		case 3:
			searchfuel();
			break;
		case 0:
			main();
		default:
			cout << "\n INVALID INPUT...";
			break;
		}
	}
}
// ADD FUEL DETAILS FUNCTION
void addfuel()
{
	fstream app;
	fuel f;
	app.open("fuel.txt", ios::out | ios::app);
	if (!app)
	{
		cout << "cannot open the file in output mode";
		exit(0);
	}
      cout<<"ENTER THE DATE:";
	  cin>>f.date;
      cout<<"ENTER THE QUANTITY OF FUEL IMPORTED:";
	  cin>>f.exported;
	  cout<<"ENTER THE FUEL PRICE:";
	  cin>>f.price;
	  cout<<"ENTER THE QUANTITY OF FUEL SOLD:";
	  cin>>f.sold;
		sprintf(f.buffer, "%s|%s|%s|%s\n",f.date, f.exported, f.price, f.sold);
	    app << f.buffer;


	app.close();
}
// VIEW FUEL DETAILS FUNCTION
void viewfuel() {
	fuel f;
	int c, I;

	fstream in;

	in.open("fuel.txt", ios::in);

	if (!in)
	{
		cout << "\ncannot open the file in output mode";
		return;
	}

	I = 0;
	cout << "date"
		 << "\t\t"
		 << "imported"
		 << "\t\t"
		 << "price"
		 << "\t\t"
		 << "sold" << endl;
	while (!in.eof())
	{
		in.getline(f.date,30,'|');
		in.getline(f.exported, 10, '|');
		in.getline(f.price,10, '|');
		in.getline(f.sold, 10, '\n');
		cout << "\n"
			 << f.date << "\t\t" << f.exported << "\t\t" << f.price << "\t\t" << f.sold<<"\t\t";

		I++;
	}
	in.close();
}
// SEARCH FUEL DETAILS FUNCTION
void searchfuel() {
	int I, flag1;
	char date[30];
	fstream in;

	cout << "\nENTER THE DATE :\n";
	cin >> date;
	in.open("fuel.txt", ios::in);
	if (!in)
	{
		cout << "\nError !\n";
		exit(0);
	}
	flag1 = 0;
	fuel f;
	while (!in.eof())
	{
	    in.getline(f.date,30,'|');
		in.getline(f.exported, 10, '|');
		in.getline(f.price,10, '|');
		in.getline(f.sold, 10, '\n');
		if (strcmp(f.date, date) == 0)
		{

			cout << "\n date    :" << f.date << "\nexported  :" << f.exported << "\nprice :" << f.price << "\nsold    :" << f.sold << "\n";
			flag1 = 1;
			break;
		}
	}
	if (!flag1)
		cout << "\nNO SUCH EMPLOYEE DETAILS FOUND !!\n";
	in.close();
}
// DISPLAY EMPLOYEE DETAILS FUNCTION
void displayFile()
{
	movie m;
	int c, I;

	fstream in;

	in.open("employee.txt", ios::in);

	if (!in)
	{
		cout << "\ncannot open the file in output mode";
		return;
	}

	I = 0;
	cout << "Employee ID"
		 << "\t\t"
		 << "Name"
		 << "\t\t"
		 << "phn Number"
		 << "\t\t"
		 << "Address" << endl;
	while (!in.eof())
	{
		in.getline(m.ind,5,'|');
		in.getline(m.movieid, 10, '|');
		in.getline(m.name, 15, '|');
		in.getline(m.num, 15, '|');
		in.getline(m.adrs, 20, '\n');
		cout << "\n"
			 << m.movieid << "\t\t" << m.name << "\t\t" << m.num << "\t\t" << m.adrs<<"\t\t";

		I++;
	}
	in.close();
}





int get_num_records()
{
	int I = 0;
	fstream file2;

	file2.open("employee.txt", ios::in);
	if (!file2)
	{
		return 0;
	}
	while (!file2.fail())
	{
		file2.getline(stdrec[I].ind, 5, '|');
		file2.getline(stdrec[I].movieid, 10, '|');
		file2.getline(stdrec[I].name, 10, '|');
		file2.getline(stdrec[I].num, 11, '|');
		file2.getline(stdrec[I].adrs, 20, '\n');
		I++;
	}
	I--;
	file2.close();
	return I;
}
// ADD EMPLOYEE DETAILS
void addemployee()
{
	fstream app;
	movie m;
	int emp_no, i, cnt;
	cnt = get_num_records();
	app.open("employee.txt", ios::out | ios::app); //Open file in append mode
	if (!app)
	{
		cout << "cannot open the file in output mode";
		exit(0);
	}

	cout << "ENTER THE NUMBER OF EMPLOYEE DETAILS YOU WANT TO ADD =";
	cin >> emp_no;
	for (i = cnt; i < (cnt + emp_no); i++)
	{
		while (1)
		{
			cout << "\nENTER THE EMOLOYEE ID   \t\t\t=\t";
			cin >> m.movieid;
			if (checkid(m.movieid) == 1)
			{
				cout << "EMPLOYEE ID ALREADY EXISTS";

			}
			else
			{
				break;

			}
		}
		cout << "\nENTER YOUR NAME                   \t\t=\t";
		cin >> m.name;
		cout << "\nENTER YOUR MOBILE NUMBER          \t\t=\t";
		cin >> m.num;
		if (strlen(m.num) != 10)
		{
			cout << "ENTER THE VALID 10 DIGIT NUMBER :\t";
			cin >> m.num;
		}
		cout << "\nENTER THE ADDRESS                 \t\t=\t";
		cin >> m.adrs;
		sprintf(m.buffer, "%d|%s|%s|%s|%s\n", i,m.movieid, m.name, m.num, m.adrs);
	app << m.buffer;
        cout << "\nRECORD ADDED SUCCESFULLY...!\n\n";
	}


	app.close();
}

void retrieve_details(char st_no[5])
{
	int no, j, i;
	fstream app;
	movie m;
	no = get_num_records();
	for (i = 0; i < no; i++)
	{
		if (strcmp(stdrec[i].ind, st_no) == 0)
		{
			cout << "\n\n"
				 << "EMPLOYEE DETAILS : ";
			cout << "\nempid    :" << stdrec[i].movieid << "\nName   :" << stdrec[i].name << "\nNumber  :" << stdrec[i].num << "\naddress    :" << stdrec[i].adrs << "\n";
}
}
}
// SEARCH EMPLOYEE DETAILS FUNCION
void searchemployee()
{
	int I, flag1;
	char mid[10], snum[10];
	fstream in;

	cout << "\nENTER THE EMPLOYEE ID :\n";
	cin >> mid;
	in.open("employee.txt", ios::in);
	if (!in)
	{
		cout << "\nError !\n";
		exit(0);
	}
	flag1 = 0;
	movie m;
	while (!in.eof())
	{
		in.getline(m.ind, 5, '|');
		in.getline(m.movieid, 10, '|');
		in.getline(m.name, 10, '|');
		in.getline(m.num, 11, '|');
		in.getline(m.adrs, 20, '\n');
		if (strcmp(m.movieid, mid) == 0)
		{

			retrieve_details(m.ind);
			flag1 = 1;
			break;
		}
	}
	if (!flag1)
		cout << "\nNO SUCH EMPLOYEE DETAILS FOUND...!!\n";
	in.close();
}

void modifyemp()
{
	fstream in;
	char eid[5], buffer[45];
	int I, j;
	movie m1[100];

	in.open("employee.txt", ios::in);

	if (!in)
	{
		cout << "\nUnable to open the file in input mode";
		return;
	}

	cout << "\nENTER THE EMPLOYEE ID :";
	cin >> eid;
	I = 0;
	while (!in.eof())
	{
		// cout<<"hh";
		in.getline(m1[I].ind, 5, '|');
		in.getline(m1[I].movieid, 5, '|');
		in.getline(m1[I].name, 10, '|');
		in.getline(m1[I].num, 11, '|');
		in.getline(m1[I].adrs, 20, '\n');
		// in.getline(extra,45,'\n');
		I++;
	}

	I--;

	for (j = 0; j < I; j++)
	{
		if (strcmp(eid, m1[j].movieid) == 0)
		{
			// cout<<"hh";
			// cout << "\nTHE OLD VALUES OF THE RECORD WITH USN " << usn << " are ";
			// cout << "\nname   = " << m1[j].ind;
			cout << "\n EMPLOYEE ID    = " << m1[j].movieid;
			cout << "\n NAME    \t = " << m1[j].name;
			cout << "\n PHONE NUMBER    = " << m1[j].num;
			cout << "\n ADDRESS \t = \n" << m1[j].adrs;

			cout << "\nENTER THE NEW VALUES :\n";
			cout << "\nEMPLOYEE ID  = ";
			cin >> m1[j].movieid;
			cout << "\nNAME  = ";
			cin >> m1[j].name;
			cout << "\nPHONE NUMBER   = ";
			cin >> m1[j].num;
			cout << "\nADDRESS    = ";
			cin >> m1[j].adrs;
			

			break;
		}
	}

	if (j == I)
	{
		cout << "\nEMPLOYEE DETAILS WITH THIS ID IS NOT THERE";
		return;
	}

	in.close();
	fstream out1;
	out1.open("employee.txt", ios::out);
	if (!out1)
	{
		cout << "\nUnable to open the file in output mode";
		return;
	}

	for (j = 0; j < I; j++)
	{
		strcpy(buffer, m1[j].ind);
		strcat(buffer, "|");
		strcat(buffer, m1[j].movieid);
		strcat(buffer, "|");
		strcat(buffer, m1[j].name);
		strcat(buffer, "|");
		strcat(buffer, m1[j].num);
		strcat(buffer, "|");
		strcat(buffer, m1[j].adrs);

		strcat(buffer, "\n");
		out1 << buffer;
	}

	out1.close();
}
// DELETE EMPLOYEE DETAILS FUNCTION
void delete_stdrecord(char st_no[5])
{

	fstream file1;
	char ch;
	int I = 0, no;
	no = get_num_records();
	int flag = -1;
	for (I = 0; I < no; I++) //Check for the record'stdrec existence
	{
		if (strcmp(stdrec[I].ind, st_no) == 0)
		{
			cout << "ARE YOU SURE WANT TO DELETE THE EMPLOYEE DETAILS !((Y)es/(N)o) :";
			cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				flag = I;
				break;
			}
			else if (ch == 'N' || ch == 'n')
			{
				return;
			}
			else
			{
				cout << "invalid";
				cin >> ch;
			}
		}
	}
	if (flag == -1) //Record not found
	{
		cout << "\nError !\n";
		return;
	}
	if (flag == (no - 1)) //Delete found last record
	{
		no--;
		cout << "\n DELETED... !\n";
	}
	else
	{
		for (I = flag; I < no; I++)
		{
			stdrec[I] = stdrec[I + 1];
		}
		no--;
		cout << "\nDELETED...!\n";
	}

	file1.open("employee.txt", ios::out);
	for (I = 0; I < no; I++)
	{
		file1 << stdrec[I].ind << "|" << stdrec[I].movieid << "|" << stdrec[I].name << "|" << stdrec[I].num << "|" << stdrec[I].adrs << "\n";
	}
	file1.close();
	return;
}

void delete_record()
{
	int I, flag;
	char mid[10], snum[10];
	fstream in;

	cout << "\nENTER THE EMPLOYEE ID :\t";
	cin >> mid;
	in.open("employee.txt", ios::in);
	if (!in)
	{
		cout << "\nError !\n";
		exit(0);
	}
	flag = 0;
	movie m;
	while (!in.eof())
	{
		in.getline(m.ind, 5, '|');
		in.getline(m.movieid, 10, '|');
		in.getline(m.name, 10, '|');
		in.getline(m.num, 11, '|');
		in.getline(m.adrs, 20, '\n');
		if (strcmp(m.movieid, mid) == 0)
		{
			delete_stdrecord(m.ind);
			flag = 1;
			break;
		}
	}
	if (!flag)
		cout << "\nDELETION FAILED...!\n";
	in.close();
}

int main()
{

	int choice;

	for (;;)
	{
		cout << "\n !============================== PETROL PUMP MANAGEMENT SYSTEM ==============================!";
		cout << "\n\n\n\n0:EXIT";
		cout << "\n1:ADMIN LOGIN";
		cout << "\n\n\n\nENTER THE CHOICE :  ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			adminlogin();
			break;
		// case 2:
		// 	existinguser();
		// 	break;
		// case 3:
		// 	forgotpass();
		// 	break;
		case 0:
			exit(0);
		default:
			cout << "\nINVALID INPUT....";
			break;
		}
	}
}