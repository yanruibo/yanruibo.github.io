#include <iostream>
#include <string>
using namespace std;

class Teacher
{
private:
	string *name;
	int employeeNum;
public:
	void setName(string* name) { this->name = name; }
	void setEmployeeNum(int employeeNum) { this->employeeNum = employeeNum; }
	Teacher() {};
	Teacher(string* name, int employeeNum ) 
	{
		this->name = name;
		this->employeeNum = employeeNum;
	};
	Teacher(Teacher &rhs)
	{
		this->name = new string(*(rhs.name));
		this->employeeNum = rhs.employeeNum;
	}
	Teacher& operator=(const Teacher & rhs)
	{
		this->name = new string(*(rhs.name));
		this->employeeNum = rhs.employeeNum;
		return *this;
	}
	~Teacher()
	{
		cout << "destory " << *name << endl;
		if (NULL != name)
		{
			delete this->name;
			name = NULL;
		}
	}
};

int main(int argc, char* argv[])
{
	
	//string name = "name";
	//string name2 = "name2";
	string* name = new string("name");
	string* name2 = new string("name2");
	Teacher t,s;
	t.setName(name);
	t.setEmployeeNum(1);
	s = t;
	s.setName(name2);
	return 0;
}