#ifndef BANK_CLASS
#define BANK_CLASS

#include <iostream>
using std::cout; using std::endl; using std::ostream;
#include <vector>
using std::vector;
#include <algorithm>
using std::transform;
#include <iterator>
using std::ostream_iterator;
#include <sstream>
using std::ostringstream;
#include <map>
using std:: map;
#include <string>
using std::string;
#include<random>
using std::default_random_engine;
using std::uniform_int_distribution;
#include "proj09-bankaccount.h"

//make class Bank with data members
class Bank {
	private:
	string name_;
	long bank_id_;
	map<long, BankAccount>accounts_;
	default_random_engine rand_eng_ ;
	uniform_int_distribution<long> dist{10000, 99999};
	
	public:
	//initialize the methods as public for access
	Bank( string bankName, int randomSeed = 1234);
	long bank_id();
	string bank_name();
	
	long create_account( string account_name, string password, double funds);
	
	double balance(long account_id, string password);
	
	bool transfer(long from_id, string from_password, long to_id, 
	string to_password, double amount);
	
	void print_account(long id, string password, ostream& out);

};
	
#endif
