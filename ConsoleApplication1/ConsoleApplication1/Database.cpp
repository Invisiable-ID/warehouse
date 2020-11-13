#include "Database.h"
#include <stdexcept>

using namespace std;

namespace Records
{
	Database::Database():
}
Database::Database():mNextEmployeeNumber(kFirstEmployeeNumber)
{ }

Employee & Database::addEmployee(const string & firstName, const string & lastName)
{
	Employee theEmployee;
	theEmployee.setFirstName(firstName);
	theEmployee.setLastName(lastName);
	theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
	theEmployee.hire();
	mEmployees.push_back(theEmployee);
	return mEmployees[mEmployees.size() - 1];
	// TODO: insert return statement here
}

