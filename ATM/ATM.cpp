#include <iostream>
using namespace std;

class ATM
{
public:
	void SetBalance(double balance)
	{
		m_balance = balance;
	}

	void GetBalance()
	{
		cout << "\nYour balance is: \t" << m_balance << endl;
	}

	void Deposit(double x)
	{
		m_balance += x;
		cout << "\nYour balance after deposit of " << x << " is \t" << m_balance << endl;
	}

	void Withdrawal(double x)
	{
		m_balance -= (x + 1.47);
		cout << "\nYour balance after withdrawal of " << x <<" is: \t" << m_balance << "\n\tFee 1.47 paid.\n" << endl;
	}


private:
	double m_balance;
};

int main()
{
	int error = 0;
	double balance = 0.00;

	do
	{
		error = 0;
		cout << "\nWelcome to your ATM!\n" << endl;
		cout << "\nEnter initial balance of your account: \t";
		cin >> balance;
		if (cin.fail())
		{
			cout << "\nPlease enter a valid account balance.\n" << endl;
			error = 1;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error == 1);
	
	/*
	double balance = 0.00;

	for (;;) {
		cout << "Please enter initial account amount: ";
		if (cin >> balance) {
			break;
		}
		else {
			cout << "Please enter a valid number" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}*/

	ATM myBalance;
	myBalance.SetBalance(balance);
	int x = 4;
	double z = 0.00;
	double y = 0.00;

	do {
		cout << "\n\nWelcome to your ATM. What would you like to do?\n";
		cout << "Press 1 - to view your balance.\n";
		cout << "Press 2 - to deposit cheque.\n";
		cout << "Press 3 - to withrawals (Fee 1.47).\n";
		cout << "Press any key - to EXIT your ATM.\n" << endl;
		cin >> x;

		
		if(x == 1 || x == 2 || x == 3 || x == 7)
		{
		
			switch (x)
			{
				case 1:
					myBalance.GetBalance();
					break;
				case 2:
					do
					{
						error = 0;
						cout << "\nEnter the amount to deposit: \t";
						cin >> y;
						if (cin.fail())
						{
							cout << "\nPlease enter a valid amount.\n" << endl;
							error = 1;
							cin.clear();
							cin.ignore(80, '\n');
						}
					} while (error == 1);
					myBalance.Deposit(y);
					break;
				case 3:
					do
					{
						error = 0;
						cout << "\nEnter the amount to withdraw: \t";
						cin >> z;
						if (cin.fail())
						{
							cout << "\nPlease enter a valid amount." << endl;
							error = 1;
							cin.clear();
							cin.ignore(80, '\n');
						}
					} while (error == 1);
					myBalance.Withdrawal(z);
					break;
				default:
					cout << "\n\nYou hacked the EXIT :-)\n\n";
					break;
			}
			
		}
		else
		{
			cout << "\n\nThank you for using your ATM.";
			cout << "\nSee you next time." << endl;
		}

	} while (x == 1 || x == 2 || x == 3);

	return 0;
}