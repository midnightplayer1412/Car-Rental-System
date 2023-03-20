#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;

class Car{
	private:
		string id;
		string brand;
		string model;
		string plate_number;
		string rent_price;
	public:
		//Constructors 
		Car(){		
			fstream file("car_data.txt");
			if(!file){
				cout<<"There's an error opening car data file"<<endl<<endl;
        		exit(0);
			}
			file.close();
		}
		//Encapsulation
		void set_id(string ID){
			id=ID;
		}
		void set_brand(string Brand){
			brand=Brand;
		}
		void set_model(string Model){
			model=Model;
		}
		void set_plate_number(string Plate_Number){
			plate_number=Plate_Number;
		}
		void set_rent_price(string Rent_Price){
			rent_price=Rent_Price;
		}
		string get_id(){
			return id;
		}
		string get_brand(){
			return brand;
		}
		string get_model(){
			return model;
		}
		string get_plate_number(){
			return plate_number;
		}
		string get_rent_price(){
			return rent_price;
		}
		void view_record(){
			system("cls");
			cout<<"\t\t----------------------------------------------\n";    
		    cout<<"\t\t\tSIMPLE CAR RENTAL SYSTEM \n";
		    cout<<"\t\t\t\tView Record : "<<endl;
		    cout<<"\t\t----------------------------------------------\n"<<endl;
			int i=0;
			string line[1000];
			string line_info[5];
			string delimiter=", ";
			ifstream view("car_data.txt");
			while(!view.eof()){
				getline(view, line[i++]);
			}
			i=0;
			    
			while(line[i]!=""){
				int start=0, end=line[i].find(delimiter);
				for(int j=0; j<5; j++){
					line_info[j]=line[i].substr(start, end-start);
					start=end+delimiter.size();
					end=line[i].find(delimiter, start);
				}
				id=line_info[0];
				brand=line_info[1];
				model=line_info[2];
				plate_number=line_info[3];
				rent_price=(line_info[4]);
				cout<<"\t----------------------------------------------\n";    
			    cout<<"\tCAR ID\t|BRAND\t\t: "<<brand<<endl<<"\t\t|MODEL\t\t: "<<model<<endl<<"\t  "<<id<<"\t|PLAT NUMBER\t: "<<plate_number<<endl<<"\t\t|RENT PRICE\t: RM "<<rent_price<<"\n";
				i++;
			}
				cout<<"\t----------------------------------------------\n";    
			view.close();
		}
		void add_record(){
			system("cls");
			cout<<"\t\t----------------------------------------------\n";    
		    cout<<"\t\t\tSIMPLE CAR RENTAL SYSTEM \n";
		    cout<<"\t\t\t\tAdd Record : "<<endl;
		    cout<<"\t\t----------------------------------------------\n"<<endl;
		    cout<<"\n\n\tEnter Car ID : ";
		    getline(cin, id);
		    cout<<"\n\tEnter Car Brand : ";
		    getline(cin, brand);
			cout<<"\n\tEnter Car Model : ";
		    getline(cin, model);
			cout<<"\n\tEnter Plate Number : ";
		    getline(cin, plate_number);
			cout<<"\n\tEnter Rent Price : RM ";
		    getline(cin, rent_price);
			ofstream add("car_data.txt", ios::app);
			add<<id<<", "<<brand<<", "<<model<<", "<<plate_number<<", "<<rent_price<<endl;
			cout<<"\n\n\tCar details added successfully"<<endl<<endl;
			add.close();
		}
		void search_record(){
			system("cls");
			int search_by;
			string search;
			cout<<"\t\t----------------------------------------------\n";    
		    cout<<"\t\t\tSIMPLE CAR RENTAL SYSTEM \n";
		    cout<<"\t\t\t\tSearch Record : "<<endl;
		    cout<<"\t\t----------------------------------------------\n"<<endl;
		    cout<<"\t[1] ID"<<endl;
			cout<<"\t[2] Brand"<<endl;
			cout<<"\t[3] Model"<<endl;
			cout<<"\t[4] Rent Price"<<endl;
			cout<<"\n\tSearch Record by : ";
			cin>>search_by;
			cin.ignore();
			switch(search_by){
				case 1:
					cout<<"\n\n\tEnter Car ID : ";
		    		getline(cin, search);
		    		search_id(search);
					break;
				case 2:
					cout<<"\n\tEnter Car Brand : ";
		    		getline(cin, search);
		    		search_brand(search);
					break;
				case 3:
					cout<<"\n\tEnter Car Model : ";
		    		getline(cin, search);
		    		search_model(search);
					break;
				case 4:
					cout<<"\n\tEnter Rent Price : RM ";
		    		getline(cin, search);
		    		search_price(search);
					break;
				default:
					cout<<"Invalid Input!"<<endl;
					break;
			}
		}
		void search_id(string);
		void search_brand(string);
		void search_model(string);
		void search_price(string); 
		void edit_record();
		void delete_record();
		void admin_menu(){
			char cont;
			do{
				system("cls");
				int select;
				cout<<"\t\t\t----------------------------------------------\n";    
			    cout<<"\t\t\t\tSIMPLE CAR RENTAL SYSTEM \n";
			    cout<<"\t\t\tWelcome to Our Company ,Choose from the menu : "<<endl;
			    cout<<"\t\t\t----------------------------------------------\n"<<endl;
			    cout<<"\t[1] View Record"<<endl;
			    cout<<"\t[2] Add Record"<<endl;
			    cout<<"\t[3] Search Record"<<endl;
			    cout<<"\t[4] Edit Record"<<endl;
			    cout<<"\t[5] Logout"<<endl;
			    cout<<"\n\n\tPlease select your option : ";
			    cin>>select;
			    switch(select){
			    	case 1:
			    		this->view_record();
			    		system("pause");
			    		break;
			    	case 2:
			    		cin.ignore();
			    		this->add_record();
			    		system("pause");
			    		break;
			    	case 3:
			    		this->search_record();
			    		system("pause");
			    		break;
			    	case 4:
//			    		this->edit_record();
			    		system("pause");
			    		break;
			    	case 5:
			    		return;
			    		break;
			    	default:
			    		cout<<"Invalid option!"<<endl;
			    		system("pause");
			    		this->admin_menu();
			    		break;
				}
				cout<<"Would you like to continue the admin page? [Y/N] : ";
				cin>>cont;
			}while(cont=='Y'||cont=='y');
			
		}
};

void Car::search_id(string ID){
	int i=0, result=0, lineNumber=0;
	string line[1000];
	string line_info[5];
	string delimiter=", ";
	ifstream check("car_data.txt");
	while(!check.eof()){
		getline(check, line[i++]);
	}
	i=0;
	    
	while(line[i]!=""){
		cout<<i<<endl;
		int start=0, end=line[i].find(delimiter);
		for(int j=0; j<5; j++){
			line_info[j]=line[i].substr(start, end-start);
			start=end+delimiter.size();
			end=line[i].find(delimiter, start);
		}
		id=line_info[0];
		brand=line_info[1];
		model=line_info[2];
		plate_number=line_info[3];
		rent_price=(line_info[4]);
		if(ID==line_info[0]){
			cout<<endl;
			cout<<"\t----------------------------------------------\n";    
	    	cout<<"\tCAR ID\t|BRAND\t\t: "<<brand<<endl<<"\t\t|MODEL\t\t: "<<model<<endl<<"\t  "<<id<<"\t|PLAT NUMBER\t: "<<plate_number<<endl<<"\t\t|RENT PRICE\t: RM "<<rent_price<<"\n";
	    	result++;
		}
		i++;
	}
	if(result==0){
		cout<<"\n\tNo Record Found ... "<<endl;
	}
		cout<<"\t----------------------------------------------\n";    
	check.close();
}

void Car::search_brand(string b){
	int i=0, result=0;
	string line[1000];
	string line_info[5];
	string delimiter=", ";
	ifstream check("car_data.txt");
	while(!check.eof()){
		getline(check, line[i++]);
	}
	i=0;
	    
	while(line[i]!=""){
		int start=0, end=line[i].find(delimiter);
		for(int j=0; j<5; j++){
			line_info[j]=line[i].substr(start, end-start);
			start=end+delimiter.size();
			end=line[i].find(delimiter, start);
		}
		id=line_info[0];
		brand=line_info[1];
		model=line_info[2];
		plate_number=line_info[3];
		rent_price=(line_info[4]);
		if(b==line_info[1]){
			cout<<endl;
			cout<<"\t----------------------------------------------\n";    
	    	cout<<"\tCAR ID\t|BRAND\t\t: "<<brand<<endl<<"\t\t|MODEL\t\t: "<<model<<endl<<"\t  "<<id<<"\t|PLAT NUMBER\t: "<<plate_number<<endl<<"\t\t|RENT PRICE\t: RM "<<rent_price<<"\n";
	    	result++;
		}
		i++;
	}
	if(result==0){
		cout<<"\n\tNo Record Found ... "<<endl;
	}
		cout<<"\t----------------------------------------------\n";    
	check.close();
}

void Car::search_model(string m){
	int i=0, result=0;
	string line[1000];
	string line_info[5];
	string delimiter=", ";
	ifstream check("car_data.txt");
	while(!check.eof()){
		getline(check, line[i++]);
	}
	i=0;
	    
	while(line[i]!=""){
		int start=0, end=line[i].find(delimiter);
		for(int j=0; j<5; j++){
			line_info[j]=line[i].substr(start, end-start);
			start=end+delimiter.size();
			end=line[i].find(delimiter, start);
		}
		id=line_info[0];
		brand=line_info[1];
		model=line_info[2];
		plate_number=line_info[3];
		rent_price=(line_info[4]);
		if(m==line_info[2]){
			cout<<endl;
			cout<<"\t----------------------------------------------\n";    
	    	cout<<"\tCAR ID\t|BRAND\t\t: "<<brand<<endl<<"\t\t|MODEL\t\t: "<<model<<endl<<"\t  "<<id<<"\t|PLAT NUMBER\t: "<<plate_number<<endl<<"\t\t|RENT PRICE\t: RM "<<rent_price<<"\n";
		}
		i++;
	}
	if(result==0){
		cout<<"\n\tNo Record Found ... "<<endl;
	}
		cout<<"\t----------------------------------------------\n";    
	check.close();
}

void Car::search_price(string p){
	int i=0, result=0;
	string line[1000];
	string line_info[5];
	string delimiter=", ";
	ifstream check("car_data.txt");
	while(!check.eof()){
		getline(check, line[i++]);
	}
	i=0;
	    
	while(line[i]!=""){
		int start=0, end=line[i].find(delimiter);
		for(int j=0; j<5; j++){
			line_info[j]=line[i].substr(start, end-start);
			start=end+delimiter.size();
			end=line[i].find(delimiter, start);
		}
		id=line_info[0];
		brand=line_info[1];
		model=line_info[2];
		plate_number=line_info[3];
		rent_price=(line_info[4]);
		if(p==line_info[4]){
			cout<<endl;
			cout<<"\t----------------------------------------------\n";    
	    	cout<<"\tCAR ID\t|BRAND\t\t: "<<brand<<endl<<"\t\t|MODEL\t\t: "<<model<<endl<<"\t  "<<id<<"\t|PLAT NUMBER\t: "<<plate_number<<endl<<"\t\t|RENT PRICE\t: RM "<<rent_price<<"\n";
		}
		i++;
	}
	if(result==0){
		cout<<"\n\tNo Record Found ... "<<endl;
	}
		cout<<"\t----------------------------------------------\n";    
	check.close();
}

void Car::edit_record(){
	int i=0, result=0;
	string ID;
	string line[1000];
	string line_info[5];
	string delimiter=", ";
	ifstream check("car_data.txt");
	ifstream inFile("car_data.txt");
    ofstream outFile("temp.txt");
	cout<<"Enter ID : ";
	getline(cin, ID);
	while(!check.eof()){
		getline(check, line[i++]);
	}
	i=0;
	    
	while(line[i]!=""){
		int start=0, end=line[i].find(delimiter);
		for(int j=0; j<5; j++){
			line_info[j]=line[i].substr(start, end-start);
			start=end+delimiter.size();
			end=line[i].find(delimiter, start);
		}
		id=line_info[0];
		brand=line_info[1];
		model=line_info[2];
		plate_number=line_info[3];
		rent_price=(line_info[4]);
		if(ID==line_info[0]){
			cout<<i<<endl;
			cout<<endl;
//			cin.ignore();
			cout<< "Enter car ID want to update: ";
            getline(cin, this->id);
            cout<< "Enter car Brand want to update: ";
            getline(cin, this->brand);
            cout<< "Enter car Model want to update";
            getline(cin, this->model);
            cout<< "Enter car Plate Number want to update";
            getline(cin, this->plate_number);
            cout<< "Enter car Rent Price want to update";
            getline(cin, this->rent_price);
            outFile<<id<< ", " <<brand<< ", "<<model<< ", "<<plate_number<<", "<<rent_price<<endl;
	    	result++;
		}else{
			outFile<<id<<", "<<brand<<", "<<model<<", "<<plate_number<<", "<<rent_price<<endl;
		}
		i++;
	}
	if(result==0){
		cout<<"\n\tNo Record Found ... "<<endl;
	}
	check.close();
	inFile.close();
    outFile.close();

    remove("car_data.txt");
    rename("temp.txt", "car_data.txt");
}

void Car::delete_record(){
    ifstream inFile("car_data.txt");
    ofstream outFile("temp.txt");

    int lineToDelete;
    cout << "Enter the line number to delete: ";
    cin >> lineToDelete;

    int lineNumber = 0;
    string line;

    while (getline(inFile, line)) {
        lineNumber++;
        if (lineNumber != lineToDelete) {
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();

    remove("car+.txt");
    rename("temp.txt", "car+.txt");

}

class Customer:public Car{
	private:
		string name;
		string ic;
		string contact;
		string car_id;
		double total_price;
	public:
		Customer(){
			fstream file("rent_records.txt");
			if(!file){
				cout<<"There's an error opening rent data file"<<endl<<endl;
        		exit(0);
			}
			file.close();
		}
		void view(){
			char like;
			cout<<"\tDo you want to search for the car model you like? [Y/N] : ";
			cin>>like;
			if(like=='Y'||like=='y'){
				system("cls");
				int search_by;
				string search;
				cout<<"\t\t----------------------------------------------\n";    
			    cout<<"\t\t\tSIMPLE CAR RENTAL SYSTEM \n";
			    cout<<"\t\t\t\tSearch Record : "<<endl;
			    cout<<"\t\t----------------------------------------------\n"<<endl;
				cout<<"\t[1] Brand"<<endl;
				cout<<"\t[2] Model"<<endl;
				cout<<"\t[3] Rent Price"<<endl;
				cout<<"\n\tSearch Record by : ";
				cin>>search_by;
				cin.ignore();
				switch(search_by){
					case 1:
						cout<<"\n\tEnter Car Brand : ";
			    		getline(cin, search);
			    		search_brand(search);
			    		system("pause");
						break;
					case 2:
						cout<<"\n\tEnter Car Model : ";
			    		getline(cin, search);
			    		search_model(search);
			    		system("pause");
						break;
					case 3:
						cout<<"\n\tEnter Rent Price : RM ";
			    		getline(cin, search);
			    		search_price(search);
			    		system("pause");
						break;
					default:
						cout<<"Invalid Input!"<<endl;
			    		system("pause");
						break;
				}
			}else{
				system("cls");
				view_record();
				system("pause");
			}
		}
		void rent(){
			char confirm;
			double total, car_price=250.50; // need to change this to double	check this website->https://www.programiz.com/cpp-programming/string-float-conversion
			int days, line_num=0;
			string linedata;
			do{
				system("cls");
	    		cout<<"\t\t----------------------------------------------\n";    
			    cout<<"\t\t\tSIMPLE CAR RENTAL SYSTEM \n";
			    cout<<"\t\t----------------------------------------------\n"<<endl;
			    cout<<"\t\tPlease Enter the following details :- \n"<<endl;
				cout<<"\tEnter your car ID : ";
				getline(cin, car_id);
				int i=0, result=0;
				string line[1000];
				string line_info[5];
				string delimiter=", ";
				ifstream record("car_data.txt");
				while(!record.eof()){
					getline(record, line[i++]);
				}
				i=0;
				    
				while(line[i]!=""){
					int start=0, end=line[i].find(delimiter);
					for(int j=0; j<5; j++){
						line_info[j]=line[i].substr(start, end-start);
						start=end+delimiter.size();
						end=line[i].find(delimiter, start);
					}
					this->set_id(line_info[0]);
					this->set_brand(line_info[1]);
					this->set_model(line_info[2]);
					this->set_plate_number(line_info[3]);
					this->set_rent_price(line_info[4]);
					if(car_id==this->get_id()){
						cout<<"\t----------------------------------------------\n";    
				    	cout<<"\tCAR ID\t|BRAND\t\t: "<<this->get_brand()<<endl<<"\t\t|MODEL\t\t: "<<this->get_model()<<endl<<"\t  "<<this->get_id()<<"\t|PLAT NUMBER\t: "<<this->get_plate_number()<<endl<<"\t\t|RENT PRICE\t: RM "<<this->get_rent_price()<<"\n";
				    	cout<<"\t----------------------------------------------\n";
						result++;
						break; 
					}
					i++;
				}
				if(result==0){
					cout<<"\n\tNo Record Found ... "<<endl;
					break;
				}else{
					cout<<"Do you confirm with the car you selected ? [Y/N] : ";
					cin>>confirm;
					cin.ignore();
					if(confirm=='Y'||confirm=='y'){
						cout<<endl<<endl;
						cout<<"\tEnter your name : ";
						getline(cin, name);
						cout<<"\tEnter your ic : ";
						getline(cin, ic);
						cout<<"\tEnter your contact : ";
						getline(cin, contact);
						cout<<"\tHow many days you want to rent : ";
						cin>>days;
						//need to change this to double
						total=days*car_price;
						cout<<total<<endl;
						ofstream add_record("rent_records.txt", ios::app);
						ifstream check_index("rent_records.txt");
						while(getline(check_index, linedata)){
							line_num++;
						}
						add_record<<line_num+1<<", "<<this->car_id<<", "<<this->name<<", "<<this->ic<<", "<<this->contact<<", "<<this->get_rent_price()<<", "<<days<<", "<<total<<endl;
						cout<<endl<<"Record added, rent succesfully, the total amount to paid is RM "<<total<<endl;
					}
				}
				record.close();
			}while(confirm=='N'||confirm=='n');
			
		}
};

// GLOBAL DECLARATION FOR OBJECT
Car car, temp;
Customer customer;

void login(){
	system("cls");
	string user="", pass ="";
	char ch;
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t  Simple Car Rental System Login";
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Username: ";
	getline(cin,user);
	cout<<"\n\n\n\t\t\t\t\t\tEnter Password: ";
	ch=getch();
	while(ch != 13){//character 13 is enter
    	pass.push_back(ch);
    	cout <<"*";
    	ch=getch();
	}
   	if(pass=="admin" && user=="admin"){
        cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
        system("PAUSE");
        car.admin_menu();
      
   }else{
      cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
      system("PAUSE");
      login();
   }
};

void selection(){
	system("cls");
	int a;
	cout<<"\t\t\t----------------------------------------------\n";    
    cout<<"\t\t\t\tSIMPLE CAR RENTAL SYSTEM \n";
    cout<<"\t\t\tWelcome to Our Company ,Choose from the menu : "<<endl;
    cout<<"\t\t\t----------------------------------------------\n"<<endl;
    cout<<"\t[1] View Car"<<endl;
    cout<<"\t[2] Rent Car"<<endl;
    cout<<"\t[3] Return"<<endl;
    cout<<"\n\n\tPlease select your option : ";
    cin>>a;
    switch(a){
    	case 1:
    		customer.view();
			selection();
    		break;
    	case 2:
    		cin.ignore();
    		customer.rent();		    
    		system("pause");
    		break;
    	case 3:
    		break;
    	default:
    		cout<<"Invalid Input!"<<endl;
	    	system("pause");
	}
};

void menu(){
	char choice;
	do{
		system("cls");
		int option;
		cout<<"\t\t\t----------------------------------------------\n";    
	    cout<<"\t\t\t\tSIMPLE CAR RENTAL SYSTEM \n";
	    cout<<"\t\t\tWelcome to Our Company ,Choose from the menu : "<<endl;
	    cout<<"\t\t\t----------------------------------------------\n"<<endl;
	    cout<<"\t[1] Login"<<endl;
	    cout<<"\t[2] Car Selection"<<endl;
	    cout<<"\t[3] Exit"<<endl;
	    cout<<"\n\n\tPlease select your option : ";
	    cin>>option;
	    
	    switch(option){
	    	case 1:
	    		cin.ignore();
	    		login();
	    		break;
	    	case 2:
	    		selection();
	    		break;
	    	default:
	    		cout<<"\n\tGOODBYE";
	    		exit(0);
	    		break;
		}
		system("cls");
		cout<<"Would you like to continue the main page? [Y/N] : ";
		cin>>choice;
	}while(choice=='Y'||choice=='y');
	

};

int main(){
	menu();
}
