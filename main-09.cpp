
#include <iostream>
using std::cout;
using std::endl;
using std::boolalpha;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iomanip>
using std::setprecision;
using std::fixed;
#include <limits>
using std::numeric_limits;
#include "proj09-bank.h"
#include "proj09-bankaccount.h"

bool double_element(const vector<long>& vect, const long& target) {
	auto location = find(vect.begin(), vect.end(), target);
	bool status = (location != vect.end()) ? true : false;
	return status;
}

int main () {
  // Set output formatting flags for standard-out
  cout << boolalpha << setprecision(2) << fixed;

	//
	// Create a new bank object
	//
	const string bank_name = "Bank of Evil";
	Bank evil_bank(bank_name);

	cout << "Bank Name : " << evil_bank.bank_name() << endl;
	cout << "Bank ID   : " << evil_bank.bank_id() << endl << endl;

	//
	// Create two accounts and print them
	//
	const string bill_name = "bill punch";
	const string bill_pword = "abc123";
	const auto bill_amount = 1000;
	long bill_id = evil_bank.create_account(bill_name, bill_pword, bill_amount);
	cout << "Bill's ID: " << bill_id << endl;

	const string homer_name = "homer simpson";
	const string homer_pwrod = "password";
	const auto homer_amount = -10;
	long homer_id = evil_bank.create_account(homer_name, homer_pwrod, homer_amount);
	cout << "Homer's ID: " << homer_id	<< endl;

	evil_bank.print_account(bill_id, "abc12", cout);      // bad password
	evil_bank.print_account(bill_id+1, bill_pword, cout); // wrong account
	evil_bank.print_account(bill_id, bill_pword, cout);   // success!
	evil_bank.print_account(homer_id, homer_pwrod, cout); // funds at 0 not -10
	cout << endl;

	//
	// Perform a transfer
	//
	bool result = evil_bank.transfer(bill_id, bill_pword, homer_id, homer_pwrod, 100);
	cout << "Was it successful : " << result << endl;
	cout << "Bill new amount   : " << evil_bank.balance(bill_id, bill_pword) << endl;
	cout << "Homer new amount  : " << evil_bank.balance(homer_id, homer_pwrod) << endl;
	cout << endl;

	//
	// Try some invalid operations
	//

	// Make @be's account
	const string abe = "@be";
	const string abe_pwd = "abc123";
	const auto abe_amount = 999999.99;
	long abe_id = evil_bank.create_account(abe, abe_pwd, abe_amount);
	cout << "@be's ID: " << abe_id	<< endl;
	
	cout << endl;

	// Bad id and password.
	double query = evil_bank.balance(123, "abc");
	if (query == numeric_limits<double>::min()) {
		cout << "Bad Balance Inqury" << endl;
	}

	cout << endl;

	// Insufficient funds
	result = evil_bank.transfer(bill_id, bill_pword, homer_id, homer_pwrod, 1000);
	cout << "Result: " << result << endl;

	cout << endl;

	// Negative transfer request
	result = evil_bank.transfer(bill_id, bill_pword, homer_id, homer_pwrod, -1000);
	cout << "Result: " << result << endl;

	cout << endl;

	// Transfer to same account
	result = evil_bank.transfer(abe_id, abe_pwd, abe_id, abe_pwd, .99);
	evil_bank.print_account(abe_id, abe_pwd, cout);
	cout << "Result: " << result << endl;

	cout << endl;

	// Liquify account
	result = evil_bank.transfer(abe_id, abe_pwd, homer_id, homer_pwrod, 999999.99);
	evil_bank.print_account(abe_id, abe_pwd, cout);
	evil_bank.print_account(homer_id, homer_pwrod, cout);
	cout << "Result: " << result << endl;

	// Try to simulate account_id collisions
	vector<long> ids = {};
	for (int i = 0; i < 10000; i++) {
		const string bill_name = "bill punch";
		const string bill_pword = "abc123";
		const auto bill_amount = 1000;
		long bill_id = evil_bank.create_account(bill_name, bill_pword, bill_amount);
		if (!double_element(ids, bill_id)) {
			ids.push_back(bill_id);
		} //else { cout << "Collision encountered with id's and not accounted for." << endl; }
	}
	if (ids.size() == 10000)
		cout << "\nNo collisions encountered when creating accounts." << endl;
}
