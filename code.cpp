#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<vector>
using namespace std;

void write_account();	
void display_all();		
void all_items(); 
void intro();	
void add_item();
void edit_item(); 
void delete_item(); 
struct Items
    {
        string itemname;
        int price;
    };
vector<Items> item;



class account
{
	int age;
	char name[50];
	char type;
    int total=0;
public:
	void create_account();	
	void show_account() const;	
	void report() const;	
};         

void account::create_account()
{
    int i=1,x=1;
	cout<<"\n\nEnter The Name of customer : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter The age :";
	cin>>age;
	cout<<"\nEnter gender of customer (m/f) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\n\n Customer Created.."<<endl<<endl;
	all_items();
	cout<<endl;
	while(1)
    {
        cout<<"press 0 to submit"<<endl<<endl;
        cout<<"enter the item id you want to purchase"<<endl;
        if(i<=item.size())
        {
        cin>>i;
        if(i==0)
            break;
        cout<<"enter the number of quantity you want of that  item"<<endl;
        cin>>x;
        total=total+(item[i-1].price*x);
        }
        else
            cout<<"invalid entry"<<endl;

    }
    cout<<"your bill is "<<total<<endl;

}

void account::show_account() const
{
	cout<<"\nAge : "<<age;
	cout<<"\ncustomer Name : ";
	cout<<name;
	cout<<"\ngender of customer : "<<type;
}


void account::report() const
{
	cout<<age<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<total<<endl<<endl;
}




int main()
{
	char ch;
    item.push_back({"Idli           ",40});
    item.push_back({"Dosa           ",40});
    item.push_back({"Chicken \n        Biriyani",80});
    item.push_back({"Chilly Mushroom",185});
    item.push_back({"Aloo Gobhi",158});
    item.push_back({"Gobhi Manjurian",158});
    item.push_back({"Kadalai Curry",137});
    item.push_back({"Baby Corn\n         Chilly Fry",168});
    item.push_back({"Arabian Mandi\n     Chicken Biriyani",239});
    item.push_back({"Mutton Biriyani",220});
    item.push_back({"Egg Biriyani",163});
    item.push_back({"Chilly Mushroom",185});
    item.push_back({"Kadhai Paneer",180});
    item.push_back({"Paneer 65",40});
    item.push_back({"Paneer Tikka",233});
    item.push_back({"Fish Meals",135});
    item.push_back({"Chicken Meals",150});
    item.push_back({"Mutton Meals",155});
    item.push_back({"Kadalai Curry",137});
    item.push_back({"Egg Omlet",47});
    item.push_back({"Egg Podimas",63});
    item.push_back({"Egg Stew",165});
    item.push_back({"Chhole Bhature",110});
    item.push_back({"Pao Bhaji",110});
    item.push_back({"Ice Cream",45});
    item.push_back({"Gulab Jamun",60});
    item.push_back({"Mango Mastani",150});
    item.push_back({"Kesar Badam",165});
    item.push_back({"Hot Coffee",30});
    item.push_back({"Cold Coffee",35});
    item.push_back({"Tea        ",35});
    item.push_back({"Mocktails Pina\n            Colada",120});
     item.push_back({"Fresh Lime Soda",40});
     item.push_back({"Strawberry \n             Delight",120});
    item.push_back({"Butter Milk",35});
	intro();
	do
	{
		system("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. NEW CUSTOMER";
		cout<<"\n\n\t02. ALL ITEMS";
		cout<<"\n\n\t03. ADD NEW ITEMS";
		cout<<"\n\n\t04. EDIT ITEM";
		cout<<"\n\n\t05. ALL CUSTOMERS LIST";
		cout<<"\n\n\t06. DELETE ITEM";
		cout<<"\n\n\t07. EXIT";
		cout<<"\n\n\tSelect Your Option (1-7) ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
		    all_items();
            break;
		case '3':
            add_item();
			break;
		case '4':
            edit_item();
			break;
		case '5':
			display_all();
			break;
		case '6':
            delete_item();
			break;
		 case '7':
			cout<<"\n\n\tThanks for using canteen management system\n        Have a good day :)";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
	}while(ch!='7');
	return 0;
}




void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();

}


void  all_items()
{
    int i=0;
    cout<<"item id"<<"\t"<<"itemname"<<"\t\t"<<"price"<<endl<<endl;
    for(i=0;i<item.size();i++)
    {
        cout<<i+1<<"\t"<<item[i].itemname<<"\t\t"<<item[i].price<<endl;
    }

}


void add_item()
{
    string a;
    int b;
    cout<<"enter the item name"<<endl;
    cin>>a;
    cout<<"enter the item price"<<endl;
    cin>>b;
    item.push_back({a,b});
    cout<<"item added successfully"<<endl<<endl;
    all_items();
}

void edit_item()
{
    int j;
    cout<<"enter the id of item"<<endl;
    cin>>j;
    if(j<=item.size()){
    cout<<"enter the item name"<<endl;
    cin>>item[j-1].itemname;
    cout<<"enter the item price"<<endl;
    cin>>item[j-1].price;
    cout<<endl<<"item edited successfully"<<endl;
    }
    else
    {
        cout<<"invalid entry";
    }
}
void delete_item()
{
    int j;
    cout<<"enter the id of item"<<endl;
    cin>>j;
    if(j<=item.size()){
    item.erase(item.begin()+j-1);
    cout<<endl<<"item deleted successfully"<<endl;
    }
    else
    {
        cout<<"invalid entry";
    }
}


void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tCUSTOMER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"Age      NAME           Type      Bill\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}




void intro()
{
	cout<<"\n\n\n\t  CANTEEN";
	cout<<"\n\n\tMANAGEMENT";
	cout<<"\n\n\t  SYSTEM \n\t\t";
	cout<<"\n\n\n\nMADE BY : INDRAYAN MITRA(99)\nHEMALATHA T(107)\nPRANAV VANGAVETY(105)\nSAHIL KUMAR JENA(72)\nAMRITA KUMARI(86)\nSUVANSH SHARMA(97)";
	cin.get();
}
