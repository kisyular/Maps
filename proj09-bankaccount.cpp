/*
2016-03-31
proj09-bankaccount.cpp
Your Comments
*/

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
//using std::mt19937_64;
using std::uniform_int_distribution;
#include "proj09-bankaccount.h"

//make a constructor and initialize the variables
BankAccount::BankAccount( string name, string password, double funds = 0){
	string passwords= " ";
	name_ = name;
	password_ =password;
	
	//make sure the funds are not negative number, if they are, make  funds to be zero
	funds_ = funds;
	if (funds_<=0){
		funds_=0;
	}
}

//print function
ostream& operator<<(ostream & out, BankAccount & bankaccount){
	out <<"( ID " <<bankaccount.name_<<","<<bankaccount.funds_<<")";
    return out;
}

