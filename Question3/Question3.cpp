/*
Student Name: Nadine
Student Surname: Kaja
Student Numbe : MGI2011-1221
Description:Write a program with a base class for a bank account and one derived class (as
described below) representing an account with a different rule for withdrawing
funds. Also write a function that transfers funds from one account of any type to
another. A transfer is a withdrawal from one account and a deposit into the other.
Since the transfer can be done at any time with any type of account the withdraw
function in the classes must be virtual. Write a main program that creates three
accounts one from each class and tests the transfer function.
*/
#include<iostream>
#include<string>
#include "Bank.h"
#include "Money.h"

using namespace std;

void withdraw(BankAccount * stdPtr,MoneyMarketAccount *market,double &wi,int &checkingamount);
void deposit(BankAccount * stdPtr, double &dep );
int main()
{
	BankAccount * stdPtr ;
	MoneyMarketAccount *market;
	double withdrawamount = 0.0;
	double depositamount=0.0;

	string name = " ";
	int checkingamount = 0;
	int option = 0;
	double amount = 0.0;
	
	cout << "Welcome to the Bank Account program" << endl;
	cout << endl;
	cout << "Enter full names" << endl;
	getline(cin, name);
	while (name=="")
		{
			cout << "Enter full names" << endl;
			getline(cin, name);
		}
	cout << "Enter account number" << endl;
	signed long long int accnum;
	cin >> accnum;
	//checking if the account number is an interger and not less than 0
	while (cin.fail()||accnum<=0)
	{
		cin.clear();
		cin.ignore();
		cout << "Please enter digits for account number and less than zero \n";
		cin >> accnum;
	}
	
	system("cls");
	cout << "Account Number :" <<accnum<<endl;
	cout << endl;
	cout << "Select an option to deposit or withdraw" << endl;
	cout << "1.Deposit" << endl;
	cout << "2.Withdrawals" << endl;
	cout << "3.Quit" << endl;
	cin >> option;
	stdPtr = new BankAccount(name, accnum, depositamount);
	market = new MoneyMarketAccount(name, accnum, depositamount);
           
	while (option != 3)
	{
		
		switch (option)
		{
		case 1:
		{
			cout << " Enter Deposit amount R:__";
			double depositamount;
			cin >> depositamount;
			//checking if the account number is an interger and not less than 0
			while (cin.fail() || depositamount <= 0)
			{
				cin.clear();
				cin.ignore();
				cout << " Enter Deposit amount R10,R50,R1000:__";
				cin >> depositamount;
			}
		
			deposit(stdPtr, depositamount);
			cout << "Account holder :" << stdPtr->getName() << endl;
			cout << "Amount R:" << stdPtr->getBalance() << endl;
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			cout << " Enter Withdrawal amount R:__";
			double withdrawamount;
			cin >> withdrawamount;
			//checking if the account number is an interger and not less than 0
			while (cin.fail() || withdrawamount <= 0)
			{
				cin.clear();
				cin.ignore();
				cout << " Enter Withdrawal amount R10,R50,R1000:__";
				cin >> withdrawamount;
			}
			withdraw(stdPtr, market, withdrawamount, checkingamount);
			system("pause");
			system("cls");
		}
			break;
		case 3:
		{
			cout << "Quitting the program" << endl;
			system("pause");
			return 0;
		}
			break;
		default:
			cout << "Choose select the correct option" << endl;
		}
		cout << "Account Number :" << accnum << endl;
		cout << endl;
		cout << "Select an option to deposit or withdraw" << endl;
		cout << "1.Deposit" << endl;
		cout << "2.Withdrawals" << endl;
		cout << "3.Quit" << endl;
		cin >> option;
	} 

	system("pause");
	return 0;
}
void withdraw(BankAccount * stdPtr, MoneyMarketAccount *market, double &wi, int &checkingamount)
{
	checkingamount = stdPtr->Withdrawal(wi);
	if (checkingamount == 1)
	{
		cout << "  Status is ok " << stdPtr->getName()<<endl;
		cout << endl;
		cout << " The new balance is :R" << stdPtr->getBalance() << endl;
		market->trackwithdrawals();
		cout << endl;

	}
	else{
		cout << "Insufficient funds for the withdrawal to take place" << endl;
	}
	system("pause");
}

void deposit(BankAccount * stdPtr, double &dep)
{
	stdPtr->Deposit(dep);
}