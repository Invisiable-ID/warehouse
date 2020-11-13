#pragma once
#include<string>

namespace Records
{
	const int kDefaultStartingSalary(30000);

	class Employee
	{
	private:
		std::string mFirstName;
		std::string mLastName;
		int mEmployeeNumber;
		int mSalary;
		bool mHired;
	public:
		Employee();
		void promote(int raiseAmount = 1000);
		void demote(int demeritAmount = 1000);
		void hire();//hires or rehires the employee
		void fire();//dismiss the employee
		void display()const;//outputs employee info to console

		//getters and setters
		void setFirstName(const std::string& mFirstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& mLastName);
		const std::string& getLastName() const;

		void setEmployeeNumber(int mEmployeeNumber);
		int getEmployeeNumber() const;

		void setSalary(int mSalary);
		int getSalary() const;

		bool getIsHired() const;
	};
}
