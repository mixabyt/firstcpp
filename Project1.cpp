#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include <string>
#include <vector>

using namespace std;

enum Page {
	Main,
	CreateBook,
	ShopingCart,
	Clear
};
Page page = Main;


class kNigga
{
public:
	string title, author;
	double price;
	kNigga(string title, string author, double price)
	{
		this->title = title;
		this->author = author;
		this->price = price;
		

	}
	void show()
	{
		cout << endl 
				<< "____________________________________"
			    << endl<<"| �����: " << title  << " |" << endl
				<< "| �����: " << author << " |" << endl
	 			<< "| �i��: "  << price  << " |" << endl
				<< "------------------------------------"
			 << endl;
	
	}
};

class kNigga_Shop
{
private:
	vector<kNigga> titles;

public:

	void append(kNigga name) 
	{
		titles.push_back(name);

	}
	
	void show_all()
	{
		if (titles.size())
			for (kNigga a : titles)	a.show();

		else cout << "empty" << endl;

		
		
	}
	void trash()
	{
		titles.clear();
	}

	int total_cost()
	{

		double cost, all = 0;
		for (kNigga a : titles)
		{
			cost = a.price;
			all += cost;
		}
		return all;
	}
	
};

kNigga_Shop Shop;

void show_main_menu();
int main()
{
	setlocale(LC_ALL, "RU");
	show_main_menu();
	
		

}
  

void move_pointer(int& x, int pointer)
{
	switch (pointer)
	{
	case 80:
		if(x > 1) break;
		x++;
		break;
	case 72:
		if (x < 1) break;
		x--;
		break;
	default:
		break;

	}
}

void move_menu();
void create_book()
{
	
	cout << "����i�� �����, ������ �� �i��: " << endl;
	string name, author;
	double price;
	
	cout << "�����: "; cin >> name;
	cout << "�����: "; cin >> author; 
	cout << "�i��: ";  cin >> price;
	
	//kNigga book(name, author, price);
	//Shop.append(book);
	int y = 75;
	bool prev = true;
	while (true)
	{
		
		system("CLS");
		cout << "__________________________" << endl;
		cout << "�����: " << name << endl;
		cout << "�����: " << author << endl;
		cout << "�i��: "  << price << endl;
		cout << "__________________________";
		cout << endl << "������ ������?" << endl;

		
		
		
		if (y == 75 || (y == 13 && prev == true) )
		{
			
			cout << ">" << "���" << "<" << "\t" << "�i";
			
			if (y == 13)
			{
				kNigga book(name, author, price);
				Shop.append(book);
				break;
			}
			prev = true;
		}
		else if (y == 77 || (y == 13 && prev == false))
		{
			
			cout << " ���" << "\t" << ">" << "�i" << "<";
			if (y == 13)
			{
				break;
			}
			prev = false;
		}
		y = _getch();
		
		
	}
	system("CLS");
	
	cout << "press enter" << endl;

	
	
	while (true)
	{
		int pointer = _getch();
		if (pointer == 13)
		{
			page = Main;
			break;
		}
	}
	move_menu();
	
}

void shoping_cart()
{
	cout << "-------------�����-------------" << endl;

	Shop.show_all();

	cout << "�������� ����i���: " << Shop.total_cost() << endl << endl;
	
	cout << "������i�� enter ��� ������� � ������� ����" ;
	while (true)
	{
		int pointer = _getch();
		if (pointer == 13)
		{
			page = Main;
			break;
		}
	}
	move_menu();
}


void clear_cart()
{
	Shop.trash();
	cout << "������� ���i��� �������!" << endl << endl << "������i�� enter ��� ����������� � ������� ����";
	while (true)
	{
		int pointer = _getch();
		if (pointer == 13)
		{
			page = Main;
			break;
		}
	}
	move_menu();
	
}


void move_menu()
{

	switch (page)
	{
	case Main:
		system("CLS");
		show_main_menu();
		break;
	case CreateBook:
		create_book();
		break;
	case ShopingCart:
		system("CLS");
		shoping_cart();
		break;
	case Clear:
		system("CLS");
		clear_cart();
		break;
	default:
		break;
	}

}




void show_main_menu()
{
	string names[3] = { "�������� �����", "�����", "�������� �����" };
	int x = 0;
	while (true) 
	{
		if (page == Main)
		{ 
			cout << "-------------����-------------" << endl;
			for (int i = 0; i < 3; i++)
			{
				if (x == i)
				{
					cout << "->  " << names[i] << endl;
				}
				else
				{
					cout << "    " << names[i] << endl;
				}
			}
		}
		int pointer = _getch();
		system("CLS");
		if (pointer == 13) //enter
		{
			switch (x)
			{
			case 0:
				page = CreateBook;
				move_menu();
				break;
			case 1:
				page = ShopingCart;
				move_menu();
				break;
			case 2:
				page = Clear;
				move_menu();
				break;
			};
		}
		else
		{
			move_pointer(x, pointer);
		}
		
		
	
	}
		
}



