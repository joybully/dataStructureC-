#include "Student.h"

void Print(ostream& out, Student stu[], int numelement)
{
	for(int i=0; i<numelement; i++)
	{
		stu[i].Print(out);
	}
}
void Student::Print(ostream& out)
{
	out << id << "\t" << name << "\t" << gpa << endl;
}
void Student::InitValue(int _id, const char* _name, float _gpa)
{
	id = _id;
	strcpy(name,_name);
	gpa = _gpa;
}
void Student::getValue(int& _id, char* _name, float& _gpa)
{
	_id = id;
	strcpy(_name,name);
	_gpa = gpa;	
}
char* Student::getName()
{
	return name;
}

//Student Student::EmptyKey() {
//	return NULL;
//}

void Student::operator = (Student stu)
{
	id = stu.id;
	strcpy(name,stu.name);
	gpa = stu.gpa;
}

bool Student::operator < (Student stu) {
	int result = strcmp(name, stu.name);
	if (result > 0)
		return false;
	else if (result < 0)
		return true;
	else
		return false;
}

bool Student::operator <= (Student stu) {
	int result = strcmp(name, stu.name);
	if (result > 0)
		return false;
	else if (result < 0)
		return true;
	else
		return true;
}

bool Student::operator == (Student stu) {
	int result = strcmp(name, stu.name);
	if (result == 0)
		return true;
	else
		return false;
}

bool Student::operator != (Student stu) {
	int result = strcmp(name, stu.name);
	if (result != 0)
		return true;
	else
		return false;
}

char* Student::Key() {
	return name;
}

void Student::EmptyKey() {
	id = NULL;
	strcpy(name, "ȫ�浿");
	gpa = NULL;
}

void PrintByPointer(ostream& out, Student* values[], int numValues)
{
	for(int i=0; i<numValues; i++)
	{
		(*values[i]).Print(out);
	}
}

