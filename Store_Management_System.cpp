#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

string products[]={"Washing_Machine","Air_Condition","Fridge","Microwave_Oven","Television","Generator","Water_Dispenser"};
float proprices[]={10000,20000,15000,8000,10000,12000,7000};
int productno[]={0,1,2,3,4,5,6},quantity[]={5,5,5,5,5,5,5};
string strpayMethod[2]={"On_Full_payment","On_Instalment"};

int id[300];
float monthlyPayment[300],instalments[300];
string name[300],productname[300],phone[300],cnic[300],price[300];
void info();
void enterRecord();
void upInstal();
void showQuantity();
void findRecord();
void showAllRecord();
void upProduct();
void info();

int main(){ //main function
	int i;
	ofstream outfile;
	outfile.open("quantity.txt");
	for(i=0;i<7;i++)
	{
		outfile<<left<<setw(20)<<products[i]<<setw(5)<<quantity[i]<<endl;

		}
	outfile.close();	
	
		info();
		char ch;
		do{
			system("cls");
			cout<<"\n\t\t\t\t=============================================\n";
			cout<<"\t\t\t\t\t\tMAIN MENU\n";
			cout<<"\t\t\t\t=============================================";
		cout<<"\n\n\t\t\t\t\t01. NEW PRODUCT REGISTRATION";
		cout<<"\n\n\t\t\t\t\t02. UPDATE INSTALMENT OF PRODUCT";
		cout<<"\n\n\t\t\t\t\t03. SHOW CUSTOMER'S DETAILS   ";
		cout<<"\n\n\t\t\t\t\t04. SHOW ALL CUSTOMER'S DETAILS";
		cout<<"\n\n\t\t\t\t\t05. SHOW QUANTITY OF AVAILABLE PRODUCTS";
		cout<<"\n\n\t\t\t\t\t06. UPDATE STORE PRODUCTS";
		cout<<"\n\n\t\t\t\t\t07. EXIT";
		cout<<"\n\n\t\t\t\t\tSelect Your Option (1-7) ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
		case '1':
			enterRecord();
			break;
		case '2':
			upInstal();
			break;
		case '3':
			findRecord();
			break;
		case '4': 
			showAllRecord();
			break;
		case '5':
			showQuantity();
			break;
		case '6':
			upProduct();
			break;
		 case '7':
			cout<<"\n\n\tTHANKS FOR USING STORE MANAGEMENT SYSTEM....";
			break;
		 default :
		 cout<<"Invalid Input!! Try Again.. ";
		}
		cin.ignore();
		cin.get();
    }while(ch!='7');
	return 0;
			
}
//function for registeration of product
void enterRecord(){

	int uId,productCode,payMethod,uInstalments=0,i,k;
	string strpayMethod[2]={"On_Full_payment","On_Instalment"};
	string productname[7];

	float uMonthlyPayment=0;
	string uName,uCnic,uPhone;
	
	ifstream infile;
	infile.open("quantity.txt");
	if(!infile)
	{
		cout<<"Cant Connect To File !!";
		return;
	}
	for(i=0;i<7;i++)
	{
		infile>>productname[i]>>quantity[i];
	}
	infile.close();
	cout<<"\n\t\t\t\t****************************************\n";
	cout<<"\t\t\t\t\tNEW PRODUCT REGISTRATION";
	cout<<"\n\t\t\t\t****************************************\n\n";
	cout<<endl<<left<<setw(16)<<"\tProduct Code"<<left<<setw(20)<<"Product"<<setw(20)<<"Price"<<endl;
	cout<<left<<setw(16)<<"\t------------"<<setw(20)<<left<<"------------"<<setw(20)<<"-------------"<<endl<<endl;
		for(i=0;i<7;i++)
		{
			if(quantity[i]!=0) //dont show product if quantity is zero.
			cout<<"\t"<<setw(16)<<productno[i]<<setw(20)<<productname[i]<<setw(20)<<proprices[i]<<endl<<endl;
		}
			cout<<"\nEnter Customer and Product Details.\n\n";
			cout<<"Customer Fullname: ";
			cin>>ws;
			getline(cin,uName);
			for(i=0;i<uName.size();i++)
			{
				if(uName[i]==' ')
				{
					uName[i]='_'; //remove spaces by underscore in name
				}
			}
			cout<<"Selling Product Code: ";
			cin>>productCode;
			if(productCode>6){ 
				cout<<"Invalid Input!! Press Enter To Return.. ";
				return;
			}
	ofstream outfile;
	outfile.open("quantity.txt");
			for(i=0;i<7;i++)
			{
			if(productCode==productno[i])
		{
				quantity[i]-=1;	//decrease in quantity of product by 1 after registering
			}
			outfile<<left<<setw(20)<<productname[i]<<setw(5)<<quantity[i]<<endl;
			}
			outfile.close();
			cout<<"Customer Cnic( Without dashes !): ";
			cin>>ws;
			getline(cin,uCnic);
			cout<<"Phone No:";
			cin>>ws;
			getline(cin,uPhone);
			cout<<"Unique Id For Customer(In Numeric): ";//must be unique .find customer by this.
			cin>>uId;
			cout<<"Payment Details( Press 0 for Full and 1 for Instalment): ";
			cin>>payMethod;

					if(payMethod>1)
			{
				cout<<"Invalid Input!! Press Enter to return..";
				return;
			}
			
			else if(payMethod==1)	//dont show this menu if user select full payment
			{
				cout<<"In How Many Instalments Customer Wants To Pay _??_ : ";
				cin>>uInstalments;
				uMonthlyPayment=proprices[productCode]/uInstalments;
				cout<<"\nCustomer Will Pay RS. "<<uMonthlyPayment<<"/Month..\n";	
			}


	ofstream outfile2;
	outfile2.open("mystore.txt",ios::app);		
	
	outfile2<<left<<setw(20)<<uName<<setw(15)<<uId<<setw(20)<<uCnic;
	outfile2<<setw(16)<<uPhone<<setw(20)<<products[productCode];
	outfile2<<setw(15)<<proprices[productCode]<<setw(20)<<strpayMethod[payMethod];
	outfile2<<setw(10)<<uMonthlyPayment<<setw(5)<<uInstalments<<endl;
			
	cout<<"\nProduct Registered Successfully !! Press Enter to return..\n";
		outfile2.close();	
	
}
void findRecord(){
	int forFind,i,k;
	cout<<"\n\t\t\t\t****************************************\n";
	cout<<"\t\t\t\t\tCUSTOMER'S DETAILS";
	cout<<"\n\t\t\t\t****************************************\n\n";

		ifstream infile;
		infile.open("mystore.txt");
		if(!infile)
		{
			cout<<"File Not Found !! Press Enter to return..";
			return;
		}
		i=0;
	while(!infile.eof())
	{
	
			infile>>name[i]>>id[i]>>cnic[i]>>phone[i];
			infile>>productname[i]>>price[i]>>strpayMethod[i];
			infile>>monthlyPayment[i]>>instalments[i];
			i++;

		}
		cout<<"\tEnter Unique Id Of Customer: ";
		cin>>forFind;	
	
		bool find=false;
		cout<<"\n\n";
		k=0;
		while(k<i)
		{
			if(forFind==id[k])//show customer information if id matched
			{
				cout<<"\n\tCustomer Fullname: "<<name[k]<<"\n\n";
				cout<<"\tCnic No:"<<cnic[k]<<"\n\n";
				cout<<"\tPhone No: "<<phone[k]<<"\n\n";
				cout<<"\tUnique ID: "<<id[k]<<"\n\n";
				cout<<"\tRegistered Product: "<<productname[k]<<"\n\n";
				cout<<"\tProduct Price: "<<price[k]<<"\n\n";
				cout<<"\tPayment Details: "<<strpayMethod[k]<<"\n\n";

				if(monthlyPayment[k]!=0)//only show this info for instalments customers
				{
					cout<<"\tMonthly Paying: RS "<<monthlyPayment[k]<<"\n\n";
					cout<<"\tInstalments Left: "<<instalments[k]<<"\n\n";
				
					if(monthlyPayment[k]!=0&&instalments[k]==0)//show this if all instalments cleared
					{
					cout<<"\tAll Installments Paid.. \n\n";
						}
					}
				find=true;
cout<<"\n Press Enter to return..";
				break;
			}
		k++;
		}
	if(!find)
	cout<<"Record Not Found !! Press Enter to return..";
	infile.close();
	}
void showAllRecord(){
	int i,k;
		ifstream infile;
		infile.open("mystore.txt");
		if(!infile)
		{
		cout<<"File Not Found...!! Press Enter to return..";
		return;
	}
		i=0;
	while(!infile.eof())
	{
			infile>>name[i]>>id[i]>>cnic[i]>>phone[i];
			infile>>productname[i]>>price[i]>>strpayMethod[i];
			infile>>monthlyPayment[i]>>instalments[i];
			i++;

		}
	cout<<"\n\t\t\t\t****************************************\n";
	cout<<"\t\t\t\t\tALL CUSTOMER'S DETAILS";
	cout<<"\n\t\t\t\t****************************************\n\n";

	cout<<"________________________________________________________________________________________________________________________________________________________________________\n";
	cout<<left<<setw(20)<<"Full name"<<setw(7)<<"ID"<<setw(16)<<"CNIC NO"<<setw(16)<<"Phone No";
	cout<<setw(20)<<"Registered Product"<<setw(12)<<"Price"<<setw(20)<<"Payment Method";
	cout<<setw(17)<<"Monthly Payment"<<setw(15)<<"Instalments left"<<endl;
	cout<<"________________________________________________________________________________________________________________________________________________________________________\n\n";


	
	for(k=0;k<(i-1);k++)
	{
	cout<<left<<setw(20)<<name[k]<<setw(7)<<id[k]<<setw(16)<<cnic[k];
	cout<<setw(16)<<phone[k]<<setw(20)<<productname[k];
	cout<<setw(12)<<price[k]<<setw(20)<<strpayMethod[k];
	cout<<setw(17)<<monthlyPayment[k]<<setw(17)<<instalments[k]<<endl;
	}
		
	infile.close();
}
void upInstal(){
	int i,k,forFind;
		ifstream infile;
		infile.open("mystore.txt");
		if(!infile)
		{
			cout<<"File Not Found !! Press Enter to return..";
			return;
		}
		i=0;
	while(!infile.eof())
	{
			infile>>name[i]>>id[i]>>cnic[i]>>phone[i];
			infile>>productname[i]>>price[i]>>strpayMethod[i];
			infile>>monthlyPayment[i]>>instalments[i];
			i++;

		}
	cout<<"\n\t\t\t\t****************************************\n";
	cout<<"\t\t\t\t\tUPDATE INSTALMENT OF PRODUCT";
	cout<<"\n\t\t\t\t****************************************\n\n";
		cout<<"\n\tEnter Unique Id Of Customer: ";
		cin>>forFind;
		bool find=false;
		
	ofstream outfile;
	outfile.open("mystore.txt");
	if(!outfile)
	{
		cout<<"File Not Found..Press Enter to return..";
	}
	
	for(k=0;k<(i-1);k++)
		{	
	outfile<<left<<setw(20)<<name[k]<<setw(15)<<id[k]<<setw(20)<<cnic[k];
	outfile<<setw(16)<<phone[k]<<setw(20)<<productname[k];
	outfile<<setw(15)<<price[k]<<setw(20)<<strpayMethod[k];
	outfile<<setw(10)<<monthlyPayment[k];		
			if(forFind==id[k])
		{  
			find=true;
			if(instalments[k]==0)
			{
				cout<<"\n\n\tAll Installments Paid !! Press Enter to return.. ";	
				outfile<<setw(5)<<instalments[k]<<endl;
			}
			else if(instalments[k]>0)//if instalments not zero decrease by 1.
			{
				instalments[k]-=1;
				outfile<<setw(5)<<instalments[k]<<endl;
				cout<<"\n\tInstalment Successfully Updated !!"<<endl<<endl;
				cout<<"\tInstalments Left: "<<instalments[k]<<endl<<endl;
				cout<<"Press Enter To Return.. ";
			}
		}

		else{
			outfile<<setw(5)<<instalments[k]<<endl;
		}
}
		if(!find)
			cout<<"\n\tRecord Not Found !! Press Enter to return..";
}


void showQuantity(){
	string productname[7];
	int i,k,quantity[7];
	ifstream infile;
	infile.open("quantity.txt");
	if(!infile)
	{
		cout<<"File Not Found !! Press Enter to return..";
	return;	
	}
	cout<<"\n\t\t\t\t*********************************************\n";
	cout<<"\t\t\t\t\tQUANTITY OF AVAILABLE PRODUCTS";
	cout<<"\n\t\t\t\t*********************************************\n\n";
	cout<<" _________________________________________\n";
	cout<<left<<setw(20)<<"\tProduct"<<setw(10)<<"Quantity\n";
	cout<<"_________________________________________\n\n";


	for(i=0;i<7;i++)
	{
		infile>>productname[i]>>quantity[i];

	}
	infile.close();
	for(i=0;i<7;i++)
	{
	
		cout<<left<<"\t"<<setw(20)<<productname[i]<<setw(10)<<quantity[i]<<endl<<endl;

	}
	
	cout<<"Press Enter to return..";
}
void upProduct(){
	int i,k,productcode,upQuantity,quantity[7];
	string productname[7];

	ifstream infile;
	infile.open("quantity.txt");

	if(!infile)
	cout<<"File not found !! Press Enter to return..";

	cout<<"\n\t\t\t\t****************************************\n";
	cout<<"\t\t\t\t\tUPDATE STORE PRODUCTS";
	cout<<"\n\t\t\t\t****************************************\n\n";

	for(i=0;i<7;i++)
	{
			infile>>productname[i]>>quantity[i];
	}
	infile.close();
	cout<<left<<setw(15)<<"\tProduct code"<<setw(20)<<"Product name"<<setw(20)<<"Product Quantity"<<endl;
	cout<<left<<setw(15)<<"\t------------"<<setw(20)<<"------------"<<setw(20)<<"-------------"<<endl;

	for(i=0;i<7;i++)
	{
		cout<<"\t"<<left<<setw(15)<<i<<setw(20)<<productname[i]<<setw(20)<<quantity[i]<<endl<<endl;
	}
	cout<<"\tEnter Product Code: ";
	cin>>productcode;
	bool find=false;

	ofstream outfile;
	outfile.open("quantity.txt");

	for(i=0;i<7;i++)
	{
		if(productcode==productno[i]&&productcode<7)//if product code exists and less than 7 show this info
		{
			cout<<"\n\tNo Of New "<<productname[i]<<"s : ";
			cin>>upQuantity;
			quantity[i]+=upQuantity;
			cout<<"\tTotal No Of "<<productname[i]<<"s : "<<quantity[i];
			cout<<"\n\nProduct Quantity Updated !! Press Enter To Return..";
		find=true;
		}
		
	outfile<<left<<setw(20)<<productname[i]<<setw(5)<<quantity[i]<<endl;
	
	}
	outfile.close();
	
	if(!find)
		cout<<"\n\nInvalid Input!! Press Enter To Return.. ";

}
void info()
{ 
cout<<endl;
	cout<<"  *****  *****  *****  *****  *****    *      *  *****  *     *  *****  ******  *****  *      *  *****  *     *  *****"<<endl;
	cout<<"  *        *    *   *  *  *   *        * *  * *  *   *  * *   *  *   *  *       *      * *  * *  *      * *   *    *  "<<endl;
	cout<<"  *****    *    *   *  * *    *****    *  **  *  *****  *  *  *  *****  * ****  *****  *  **  *  *****  *  *  *    *  "<<endl;
	cout<<"      *    *    *   *  *  *   *        *      *  *   *  *   * *  *   *  * *  *  *      *      *  *      *   * *    *  "<<endl;
	cout<<"  *****    *    *****  *   *  *****    *      *  *   *  *     *  *   *  * *  *  *****  *      *  *****  *     *    *  "<<endl;
	cout<<"\n\n\n";
	cout<<"\n,---.|              |        ,--.                 |                        \n";
    cout<<"|---||---.,---..   .|---     |   |,---..    ,,---.|    ,---.,---.,---.,---.\n";
    cout<<"|   ||   ||   ||   ||        |   ||---' \\  / |---'|    |   ||   ||---'|    \n";
    cout<<"`   '`---'`---'`---'`---'    `--' `---'  `'  `---'`---'`---'|---'`---'`    \n";
    cout<<"                                                            |              \n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t1) AHMER MUNAF  ( BSIT ) 2"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t--------------------------------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t2) WAlEED UllAH  ( BSIT) 2"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t--------------------------------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t3) OWAIS ALI  ( BSIT ) 2"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t--------------------------------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t4) MUHAMMAD USAMA  ( BSIT ) 2"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t--------------------------------"<<endl<<endl<<endl;
    cout<<"  Press Enter To Continue.....";
	cin.get();
}

