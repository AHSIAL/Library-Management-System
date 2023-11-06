#include<iostream>
#include<fstream>
using namespace std;

// we will create an admin class for an admin to controll the whole library management system like add and modify books, change librarian records
//  change librarian
class admin{
	string username, pass, admin_password, admin_username;
	public:
		void lib_admin();
		void main_menu();
		void librarianrecord();
		
};
// we will create a library class for librarian which is inherited from the admin class, librarian has control to issue book to student 
// search book, view all the issued books, and return the issue books
class library: public admin{
	protected:
	string book_name, author_name;
	string student_name, student_address;
	int student_id;
	int book_id;
	float price;
	public:
		void librarian();
		void search_book();
		void issue_book();
		void view_issue_book();
		void return_book();	 
};
// here we have created a book class to add, remove, edit books, here we have also made a function to check all the books available

class book: public library{
	public:
		void books_menu();
		void add_book();
		void remove_book();
		void modify_book();
		void book_list();
		
};

// here in this class student has the options to check all the available books, check issued books

class student:public book
{
	public:
		void student_menu();
};



void admin::main_menu(){
	library libr;
	int outeroption;
//	book bookss;
	student std;
	cout<<"\n\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t             Library Management System                        \n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    \n";
	cout<<"\n\t\t\t-------Main Menu---------";
	cout<<"\n\t\t\t Select from the given options: ";
	cout<<"\n\t\t\t 1) Admin ";
	cout<<"\n\t\t\t 2) Librarian ";
	cout<<"\n\t\t\t 3) Student ";
	cout<<"\n\t\t\t 4) Exit ";
	cout<<"\n\t\t\tSelect your option: ";
	cin>>outeroption;
	switch(outeroption)
	{ 
		case 1:
		cout<<"Enter Username: ";
		cin>>admin_username;
		cout<<"Enter Password: ";
		cin>>admin_password;
		if(admin_password=="admin" && admin_username=="ADMIN" )
		{
			system("cls");
			lib_admin();	
		}
		else
		{
			system("cls");
			main_menu();
			cout<<"Your password is incorrect \n Please enter from the given options";
			
		}
		break;
	
	case 2:
	
			cout<<"Enter Username: ";
		cin>>username;
		cout<<"Enter Password: ";
		cin>>pass;
		if(pass=="library" && username=="library@email.com" )
		{
			libr.librarian();
		}
		else
		{
			system("cls");
			cout<<"Your password is incorrect \n Please enter from the given options";
		}
	
		break;
	case 3:
	
		std.student_menu();
	
		break;
	case 4:
	
		system("cls");
		exit(0);
	
		break;
	default:
		
		system("cls");
		cout<<"\n\t\tPlease Enter from the given options ";
			
}
}
void admin::lib_admin()
{	
	book bookss;
	int outeroption;
	string password;
	cout<<"\n\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t             Library Management System                        \n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    \n";
	cout<<"\n\t\t\t-------Admin Menu---------";
	cout<<"\n\t\t\t Select from the given options: ";
	cout<<"\n\t\t\t 1) Librarian Record ";
	cout<<"\n\t\t\t 2) Add/Modify books ";
	cout<<"\n\t\t\t 3) Go Back to Main Menu ";
	cout<<"\n\t\t\t 4) Exit Application ";
	cout<<"\n\t\t\tSelect your option: ";
	cin>>outeroption;
	switch(outeroption)
	{
		case 1:
			system("cls");
			librarianrecord();
			break;
		case 2:
			system("cls");
			bookss.books_menu();
			break;
		case 3:
			system("cls");
			main_menu();
			break;
		case 4:
			exit(0);
			break;
		default:
			system("cls");
			lib_admin();
			cout<<"Please enter valid option: ";						
	}
}

void admin::librarianrecord()
{
	int choice;
	fstream lib;
	string name, address, phone_no, age, cnic_no;
	
	cout<<"\n\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t             Library Management System                        \n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    \n";
	cout<<"\n\t\t\t-------Info about librarian---------";
	cout<<"\n\t\t\t 1) Change Librarian ";
	cout<<"\n\t\t\t 2) Check all Librarian information ";
	cout<<"\n\t\t\t 3) Go Back to Main Menu ";
	cout<<"\n\t\t\t 4) Exit Application ";
	cout<<"\n\t\tEnter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"\n\t\t\t Enter new librarian name: ";
			cin>>name;
			cout<<"\n\t\t\t Enter new librarian Address: ";
			cin>>address;
			cout<<"\n\t\t\t Enter new librarian Phone number: ";
			cin>>phone_no;
			cout<<"\n\t\t\t Enter new librarian age: ";
			cin>>age;
			cout<<"\n\t\t\t Enter new librarian CNIC NO: ";
			cin>>cnic_no;
			
			

				lib.open("librarian data.docs", ios::app|ios::out);
				lib<<" "<<name<<" "<<address<<" "<<phone_no<<" "<<age<<" "<<cnic_no<<endl;
				lib.close();
			cout<<"\n\t\t\t Librarian record is added ";
			break;
		case 2:
			lib.open("librarian data.docs", ios::app|ios::in);
			cout<<" Name  Address  Phone_no  age  cnic_no "<<endl;
			while(lib>>name>>address>>phone_no>>age>>cnic_no)
			{
				cout<<"\n "<<name<<"   "<<address<<"   "<<phone_no<<"   "<<age<<"   "<<cnic_no<<endl;
			}
			lib.close();
			break;
		case 3:
			system("cls");
			main_menu();
			break;
		case 4:
			exit(0);
			break;
		default :
			system("cls");
			librarianrecord();
			cout<<"\n\t\t Please enter valid option"<<endl;				
			
	}
	
}



void library::librarian(){
	int libroption;
	book b;
	cout<<"\n\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t             Library Management System                        \n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    \n";
	cout<<"\n\t\t\t-------Librarian Menu---------";
	cout<<"\n\t\t\t Select from the given options: ";
	cout<<"\n\t\t\t 1) View Book List ";
	cout<<"\n\t\t\t 2) Search Book ";
	cout<<"\n\t\t\t 3) issue book ";
	cout<<"\n\t\t\t 4) Go back to Main Menu ";
	cout<<"\n\t\t\t 5) Exit Application ";
	cout<<"\n\t\t\tSelect your option: ";
	cin>>libroption;
	switch(libroption)
	{
		case 1:
		b.book_list();
			break;
		case 2:
			search_book();
			break;
		case 3:
			issue_book();
			break;
		case 4:
			main_menu();
			break;
		case 5:
			exit(0);
			break;
		default:
			system("cls");
			librarian();
			cout<<"\n\t\t\tPlease enter valid option";
								
	}
}

void book::book_list()
{
	system("cls");
	fstream book;
	cout<<"\n\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t             Library Management System                        \n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    \n";
	cout<<"\n\t\t\t-------Book List---------";
	cout<<"\n\n\t"<<"ID\tName\tAuthor Name\tPrice per day"<<endl;
	book.open("book.dat", ios::in);
	if(!book)
	{
		cout<<"Book is not available";
	}
	else
	{
		while(book>>book_id>>book_name>>author_name>>price)
		{
			cout<<"\n\t"<<book_id<<"\t"<<book_name<<"\t\t"<<author_name<<"\t\t"<<price<<endl;
			cout<<"\t-------------------------------------------------------------------------------";
		}
	book.close();
	}
	
}

void library::search_book()
{
	int bid;
	char chose;
	string bname;
	int searchoption;
	fstream book;
	cout<<"\n\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t             Library Management System                        \n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    \n";
	cout<<"\n\t\t\t-------Search Book---------";
	cout<<"chose from given options";
	cout<<"\n\t\t\t 1) Search by Book ID ";
	cout<<"\n\t\t\t 2) Search by Book Name ";
	cout<<"\n\t\t\t 3) Go back to main menu ";
	cout<<"\n\t\t select your option: ";
	cin>>searchoption;
	if(searchoption==1)
	{
	  do{
	  	
			cout<<"Enter Book id: ";
			cin>>bid;
		
			book.open("book.dat",ios::in);
			if(!book)
			{
				cout<<"File is not available";
			}
			else{
			
				while(book>>book_id>>book_name>>author_name>>price)
				{
					if(book_id==bid)
					{
						cout<<"\n\n\t"<<"ID\tName\tAuthor Name\tPrice per day"<<endl;
						cout<<"\n\t"<<book_id<<"\t"<<book_name<<"\t\t"<<author_name<<"\t\t"<<price<<endl;
					}
					else
					{
						cout<<"\n\n\t\t This Book is not available";	
					}			
			}
				book.close();
		}
			
	 		cout<<"\n\n Do you want to search another book? if yes then press y: ";
			cin>>chose; 
		
	  }while(chose=='Y'||chose=='y');
		
		
	}
	else if(searchoption==2)
	{
		do{
			cout<<"Enter Book Name: ";
			cin>>bname;
		
			book.open("book.dat",ios::in);
			if(!book)
			{
				cout<<"File is not available";
			}
			else
			{
			
				while(book>>book_id>>book_name>>author_name>>price)
				{
					if(book_name==bname)
					{
						cout<<"\n\n\t"<<"ID\tName\tAuthor Name\tPrice per day"<<endl;
						cout<<"\n\t"<<book_id<<"\t"<<book_name<<"\t\t"<<author_name<<"\t\t"<<price<<endl;
					}	
					else
					{
						cout<<"\n\n\t\t This Book is not available";	
					}	
				}
			book.close();
			}
			
	 		cout<<"\n\n Do you want to search another book? if yes then press y: ";
			cin>>chose; 
			
	  }while(chose=='Y'||chose=='y');
		
	}
	
	else if(searchoption==3)
	{
		main_menu();
	}
	else{
		system("cls");
		search_book();
		cout<<"\n\t\t Please enter valid option";
	}
}

void library::issue_book()
{
	int bid;
	int issueoption;
	char choice;
	fstream issue, book;
	int std_id;
	cout<<"\n\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t             Library Management System                        \n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    \n";
	cout<<"\n\t\t\t-------Issue Book---------";
	cout<<"chose from given options";
	cout<<"\n\t\t\t 1) Issue Book ";
	cout<<"\n\t\t\t 2) View Issue Book ";
	cout<<"\n\t\t\t 3) Search Student who issued books";
	cout<<"\n\t\t\t 4) Return Book";
	cout<<"\n\t\t\t 5) Go back to main menu";
	cout<<"\n\t\t select your option: ";
	cin>>issueoption;
	switch(issueoption)
	{
		case 1:
		do{
			cout<<"Enter student id: ";
			cin>>student_id;
			cout<<"Enter student name: ";
			cin>>student_name;	
			cout<<"Enter student Address: ";
			cin>>student_address;
			cout<<"Enter Book id: ";
			cin>>bid;
			
			book.open("book.dat", ios::app|ios::in);
			while(book>>book_id>>book_name>>author_name>>price)
			{
				if(bid==book_id){
				issue.open("issue book.dat", ios::app|ios::out);
			    	
					issue<<" "<<student_id<<" "<<student_name<<" "<<student_address<<endl;
				
					issue<<"\n\t"<<book_id<<"\t"<<book_name<<"\t"<<author_name<<"\t"<<price<<endl;
				issue.close();
				}
				
				else{
					cout<<"This book is not avaiable";
				}
			}
			book.close();
			
			issue.close();
			cout<<"\n\t\t\t Book has been issued";
			cout<<"\n\t\t Do you want to issue another book? if yes then press y: ";
			cin>>choice;
		}while(choice=='Y'||choice=='y');
				
			cout<<"\n\t\t Do you want to return to main menu: ";
			cin>>choice;
			if(choice=='Y'||choice=='y')
			{
				main_menu();
			}
			break;
		case 2:
			view_issue_book();
			break;
		case 3:
			cout<<"Enter student id: ";
			cin>>std_id;
			issue.open("issue book.dat", ios::app|ios::in);
			while(issue>>student_id>>student_name>>student_address>>book_id>>book_name>>author_name>>price)
			{
				if(student_id==std_id)
				{
					
					cout<<"Student ID  Student Name  Student Address  BookID  BookName   AuthorName     Price_per_day"<<endl;
					cout<<" "<<student_id<<" \t\t"<<student_name<<" \t\t"<<student_address<<"\t\t"<<book_id<<"\t  "<<book_name<<"\t\t"<<author_name<<"\t\t"<<price<<endl;
//					cout<<"\n "<<"BookID  BookName   AuthorName     Price_per_day"<<endl;
//					cout<<"\n"<<book_id<<"\t  "<<book_name<<"\t\t"<<author_name<<"\t\t"<<price<<endl;
					cout<<"------------------------------------------------------------------------------------------\n";
				}
			}
			issue.close();
			
			break;
		case 4:
			return_book();	
			break;
		case 5:
			main_menu();
			break;
		default:
			system("cls");
			issue_book();
			cout<<"\n\t\tPlease select valid option: ";				
	}	
}

void library::view_issue_book()
{
	fstream issue;
	cout<<"\n\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t             Library Management System                        \n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    \n";
	cout<<"\n\t\t\t-------View Issued Book---------\n";
	issue.open("issue book.dat", ios::app|ios::in);
	while(issue>>student_id>>student_name>>student_address>>book_id>>book_name>>author_name>>price)
	{
		cout<<"Student ID  Student Name  Student Address  BookID  BookName   AuthorName     Price_per_day"<<endl;
		cout<<" "<<student_id<<" \t\t"<<student_name<<" \t\t"<<student_address<<"\t\t"<<book_id<<"\t  "<<book_name<<"\t\t"<<author_name<<"\t\t"<<price<<endl;
//		cout<<"\n "<<"BookID  BookName   AuthorName     Price_per_day"<<endl;
//		cout<<"\n"<<book_id<<"\t  "<<book_name<<"\t\t"<<author_name<<"\t\t"<<price<<endl;
		cout<<"------------------------------------------------------------------------------------------\n";
	}
	if(!issue)
	{
		cout<<"No book has been issued";
	}
	
	issue.close();
}

void library::return_book()
{
	char returnchoice;
	int bid, token=0;
	fstream issue, returns, book;
	int std_id;
	int days;
	float total;
	cout<<"\n\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t             Library Management System                        \n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    \n";
	cout<<"\n\t\t\t-------Return Book---------";
	cout<<"Enter Student ID: ";
	cin>>std_id;
	issue.open("issue book.dat", ios::app|ios::in);
	if(!issue)
	{
		cout<<"File does not exist";
	}
	
	else{
		returns.open("issue book1.dat", ios::app|ios::out);
		while(issue>>student_id>>student_name>>student_address>>book_id>>book_name>>author_name>>price)
		{
		
			if(student_id==std_id)
			{
				cout<<"How many days has the book had been borrowed: ";
				cin>>days;
				total=days*price;
				cout<<"Your total bill is: "<<price;
				token++;
			}
			else{
				cout<<"Student ID  Student Name  Student Address"<<endl;
				cout<<" "<<student_id<<" "<<student_name<<" "<<student_address<<endl;
				cout<<" "<<"BookID  BookName   AuthorName     Price_per_day"<<endl;
				cout<<"\n\t"<<book_id<<"\t"<<book_name<<"\t"<<author_name<<"\t"<<price<<endl;
				cout<<"------------------------------------------------------------------------------------------";
		
				}
		}
			issue.close();
			returns.close();
			remove("issue book.dat");
			rename("issue book1.dat", "issue book.dat");
	
			if(token==0)
			{
				cout<<"Record not found ";
				cout<<"\nDo you want to return another another book?";
				cin>>returnchoice;
				if(returnchoice=='y'||returnchoice=='Y')
				 return_book();
		
			}
			
	
	}

}

void book::books_menu()
{
	int bookoption;
	book bookss;
	cout<<"\n\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t             Library Management System                        \n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    \n";
	cout<<"\n\t\t\t-------Books Menu---------";
	cout<<"\n\t\t\t Select from the given options: ";
	cout<<"\n\t\t\t 1) Add Book ";
	cout<<"\n\t\t\t 2) Remove Book ";
	cout<<"\n\t\t\t 3) Modify Book ";
	cout<<"\n\t\t\t 4) Go back to Main Menu ";
	cout<<"\n\t\t\t 5) Exit ";
	cout<<"\n\t\t\tSelect your option: ";
	cin>>bookoption;
	switch(bookoption)
	{
	 	case 1:
		 	add_book();
			 break;
		case 2:
			remove_book();
			break;
		case 3:
			modify_book();
			break;
		case 4:
			main_menu();
			break;
		case 5:
			exit(0);
		default:
			system("cls");
			cout<<"\n\t\t please chose from the given option: ";
			books_menu();
								 	
	}
	
	
}

void book::add_book()
{
	system("cls");
	fstream books;
	char choice;
	int id, token=0;
	string bname, authname;
	float pricee;
	cout<<"\n\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t             Library Management System                        \n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    \n";
	cout<<"\n\t\t\t-------Books Menu---------\n";
	cout<<"\n\t\t-----Add book-------\n";
	do
	{
		cout<<"Enter Book ID: ";
		cin>>book_id;
		cout<<"Enter Book Name: ";
		cin>>book_name;
		cout<<"Enter Author Name: ";
		cin>>author_name;
		cout<<"Enter Book price per day: ";
		cin>>price;
		books.open("book.dat", ios::app|ios::in);
		if(!books)
		{
			books.open("book.dat", ios::app|ios::out);
			books<<"  "<<book_id<<"  "<<book_name<<"  "<<author_name<<"  "<<price<<endl;
			books.close();
		}
		else
		{
			while(books>>id>>bname>>authname>>pricee);
			{
				if(id==book_id)
					token++;
			}
			books.close();
			
			if(token==1)
			{
				system("cls");
				cout<<"Book is already added";
				books_menu();
			}
			else
			{
				books.open("book.dat", ios::app|ios::out);
				books<<"  "<<book_id<<"  "<<book_name<<"  "<<author_name<<"  "<<price<<endl;
				books.close();
			}
		}
		cout<<"Record Added"<<endl;
		cout<<"Do you want to add more books? If yes then press y: ";
		cin>>choice;
			
	}while(choice=='Y'||choice=='y');
	system("cls");
	books_menu();
	
}

void book::modify_book()
{
	fstream books, books1;
	char choice;
	int bookoption;
	int id, bid, token=0;
	string bname, authname;
	float pricee;
	cout<<"\n\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t             Library Management System                        \n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    \n";
	cout<<"\n\t\t\t-------Books Menu---------";
	cout<<"\n\t\t-----Modify book-------";
	cout<<"\n\n\t\t Enter book ID: ";
	cin>>id;
	books.open("book.dat", ios::app|ios::in);
	if(!books)
	{
		cout<<"file does not exist";
	}
	else
	{
		books1.open("book1.dat", ios::app|ios::out);
		while(books>>book_id>>book_name>>author_name>>price)
		{
			if(book_id==id)
			{
				cout<<"Enter Book ID: ";
				cin>>bid;
				cout<<"Enter Book Name: ";
				cin>>bname;
				cout<<"Enter Author Name: ";
				cin>>authname;
				cout<<"Enter Book price per day: ";
				cin>>pricee;	
				books1<<"  "<<bid<<"  "<<bname<<"  "<<authname<<"  "<<pricee<<endl;
				cout<<"Book has been added";
				token++;
			}
			else
			{
				books1<<"  "<<book_id<<"  "<<book_name<<"  "<<author_name<<"  "<<price<<endl;	
			}
		}
			books.close();
			books1.close();
			remove("book.dat");
			rename("book1.dat", "book.dat");
	
			if(token==0)
			{
				cout<<"Record not found ";
				cout<<"\nDo you want to edit another another book?";
				cin>>choice;
				if(choice=='y'||choice=='Y')
				 modify_book();
		
			}
	}
}
void book::remove_book()
{
	fstream books, books1;
	char choice;
	int id, token=0;
	cout<<"\n\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t             Library Management System                        \n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    \n";
	cout<<"\n\t\t\t-------Books Menu---------";
	cout<<"\n\t\t-----Modify book-------";
	cout<<"\n\n\t\t Enter book ID: ";
	cin>>id;
	books.open("book.dat", ios::app|ios::in);
	if(!books)
	{
		cout<<"file does not exist";
	}
	else
	{
		books1.open("book1.dat", ios::app|ios::out);
		while(books>>book_id>>book_name>>author_name>>price)
		{
			if(student_id==id)
			{
				cout<<"\n\t\t\t Book deleted successfully ";
				token++;
			}
			else
			{
				books1<<"  "<<book_id<<"  "<<book_name<<"  "<<author_name<<"  "<<price<<endl;
			}
		}
		books.close();
		books1.close();
		remove("book.dat");
		rename("book1.dat", "book.dat");
	
		if(token==0)
		{
			cout<<"Record not found ";
			cout<<"\nDo you want to remove another book?";
			cin>>choice;
			if(choice=='y'||choice=='Y')
			 remove_book();
		
		}
	}
}

void student::student_menu(){
	int studentoption;
	cout<<"\n\n\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t             Library Management System                        \n";
	cout<<"                                                                    \n";
	cout<<"\t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    \n";
	cout<<"\n\t\t\t-------Student Menu---------";
	cout<<"\n\t\t\t Select from the given options: ";
	cout<<"\n\t\t\t 1) View Book List ";
	cout<<"\n\t\t\t 2) Search Book ";
	cout<<"\n\t\t\t 3) Go back to Main Menu ";
	cout<<"\n\t\t\t 4) Exit Application ";
	cout<<"\n\t\t\tSelect your option: ";
	cin>>studentoption;
	switch(studentoption)
	{
		case 1:
			book_list();
			break;
		case 2:
			search_book();
			break;
		case 3:
			main_menu();
			break;
		case 4:
			exit(0);
			break;
		default:
			system("cls");
			librarian();
			cout<<"\n\t\t\tPlease enter valid option";
								
	}
}

int main()
{
	admin ad;
	ad.main_menu();
	
	
	return 0;
}

