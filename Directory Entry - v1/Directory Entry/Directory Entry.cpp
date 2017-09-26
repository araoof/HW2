#include<iostream>
#include<string>
using namespace std;
class Directory_Entry
{
public:
	Directory_Entry() { ; }
	Directory_Entry(string new_name, string new_number) { name = new_name; number = new_number; }
	~Directory_Entry() { ; }
	string get_name() const { return name; }
	string get_number() const {return number;}
	void set_number(const string &new_number) { number = new_number;  }

private:
	string name; 
	string number; 

};







int main()

{


	system("pause"); 
	return 0; 
}