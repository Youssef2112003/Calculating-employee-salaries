#include <iostream>

using namespace std;

class Employee {

protected :
	string name;
	int emp_ID;
	float salary;
public:
	
	Employee() :name("unknown"), emp_ID(0), salary(0.0) {


	}


	Employee(string n,int id,float s) {

		name = n;
		emp_ID = id;
		salary = s;
	}

	virtual float get_Total_salary() = 0;


	virtual void print() {
	
		cout << "Name = " << name << " Emp_ID = " << emp_ID << " Basic Salary = " << salary<<endl;
	
	};



};

class Sales :public Employee
{

private:
	float gross_sales;
	float commission_rate;

public :
	Sales(string n, int id, float s, float gs, float cr) :Employee(n, id, s) {

		gross_sales = gs;
		commission_rate = cr;
	}

	float get_Total_salary() {
		return salary + (gross_sales * commission_rate);
	}
	void print() {

		Employee::print();
		cout << "Gross Sales = " << gross_sales << " commission = " << commission_rate << endl;

	}

};

class Engineer :public Employee
{

private:
	string speciality;
	int experience;
	int overtime_hours;
	float overtime_houre_rate;
public:
	Engineer(string n, int id, float s, string sp, int ex, int oh,float otr) :Employee(n, id, s) {
		speciality = sp;
		experience = ex;
		overtime_hours = oh;
		overtime_houre_rate = otr ;
	}

	float get_Total_salary() {


		return salary + (overtime_hours * overtime_houre_rate);

	}

	void print() {

		Employee::print();
		cout << "speciality = " << speciality << " experience = " << experience <<" overtime_hours = " << overtime_hours << " overtime_hour_rate = " <<overtime_houre_rate<<endl;

	}

};

int main() {

	Employee* emp_ptr;
	Sales s1("Ahmed", 120, 5000, 50000, 0.10);
	Engineer e1("Hassan", 150, 7000, "SW Engineer",5,10,50);
	emp_ptr = &s1;
	emp_ptr->get_Total_salary();
	emp_ptr->print();
	
	emp_ptr = &e1;
	emp_ptr->get_Total_salary();
	emp_ptr->print();


	return 0;
}
