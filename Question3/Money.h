/*
Student Name: Nadine
Student Surname: Kaja
Student Numbe : MGI2011-1221
Description:Also create a class called MoneyMarketAccount that is
derived from BankAccount. In a MoneyMarketAccount the user gets 2 free
withdrawals in a given period of time (don’t worry about the time for this
problem). After the free withdrawals have been used, a withdrawal fee of R2.00
is deducted from the balance per withdrawal. Hence, the class must have a data
member to keep track of the number of withdrawals. It also must override the
withdraw definition. For all two classes, the withdraw function should return an
integer indicating the status (either ok or insufficient funds for the withdrawal to
take place). For the purpose of this exercise do not worry about when and how
interest is paid.
*/
#include "Bank.h"
#ifndef MoneyMarketAccount_HEADER
#define MoneyMarketAccount_HEADER
class MoneyMarketAccount : public BankAccount
{
public:
	MoneyMarketAccount(string n = "", int a = 0, double d = 0.0, int num = 0);
	int Withdrawal(double);
	void setWithdrawal(int);
	int numWithdrawal();
	void trackwithdrawals();
private:
	int numberofwithdrawals;
};
MoneyMarketAccount::MoneyMarketAccount(string n, int a, double d,int num) :BankAccount(n, a, d)
{
	numberofwithdrawals=num;
}
int MoneyMarketAccount::Withdrawal(double v)
{
	
	numWithdrawal();
	return BankAccount::Withdrawal(v);
	
}

int MoneyMarketAccount::numWithdrawal(){
	numberofwithdrawals += 1;
	return numberofwithdrawals;
}
void MoneyMarketAccount::trackwithdrawals()
{
	cout << " the number of withdrawals by the client is:" << numWithdrawal() << endl;
}
#endif