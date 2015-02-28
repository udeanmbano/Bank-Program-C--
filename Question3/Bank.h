/*
Student Name: Nadine
Student Surname: Kaja
Student Numbe : MGI2011-1221
Description:For the classes, create a base class called BankAccount that has the name (a
string) and number (an int) of the owner of the account and the balance in the
account (double) as data members. Include member functions deposit and
withdraw (each with a double for the amount as an argument) and assessor
functions getName and getBalance. 
*/
#include<iostream>
#include<string>

#ifndef BankAccount_HEADER
#define BankAccount_HEADER

using namespace std;
class BankAccount
{
public:
	BankAccount(string n,int num,double b );
		double getBalance();
		string getName();
	virtual void Deposit(double);
	virtual int Withdrawal(double);

private:
	string name;
	int number;
	double balance;
};
BankAccount::BankAccount(string n, int num, double b){
	name = n;
	number = num;
	balance = b;
	}
void BankAccount::Deposit(double a){
	balance += a;
}
int BankAccount::Withdrawal(double v){
	if (balance < 0)
		return -1;
	else if (v>balance)
		return -1;
	else
	{
		balance = balance - v - 2;
		return 1;
	}
}

double  BankAccount::getBalance(){
	return balance;
}
string BankAccount::getName(){
	return name;
}
#endif