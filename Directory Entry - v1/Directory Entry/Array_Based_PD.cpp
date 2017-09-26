#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <istream>
#include "Array_Based_PD.h"


Phone_Directory::Phone_Directory():

	size(0), capacity(100), the_directory(new Directory_Entry[100]),
		source_name("") {}


Phone_Directory::~Phone_Directory()
{
	delete[] the_directory;
}

void Phone_Directory::load_data(const std::string & source_name)
{
	// Remember the source name for use by save.
	this->source_name = source_name;
	// Create an input stream for this file.
	ifstream in(source_name.c_str());
	if (in) { // Stream exists.
		string name;
		string number;
		while (getline(in, name)) {
			if (getline(in, number)) {
				add(name, number);
			}
		}
		// Close the file.
		in.close();
	}
}

string Phone_Directory::lookup_entry(const string & name) const
{
	int index = find(name);
	if (index != -1) {
		return the_directory[index].get_number();
	}
	else {
		return "";
	}
}

string Phone_Directory::add_or_change_entry(const string & name, const std::string & number)
{
	string old_number = "";
	int index = find(name);
	if (index != -1) {
		old_number = the_directory[index].get_number();
		the_directory[index].set_number(number);
	}
	else {
		add(name, number);
	}
	modified = true;
	return old_number;
}

//Step 6: Complete Programming Exercise 1.7 (page 121) Code the remove_entry function.
std::string Phone_Directory::remove_entry(const std::string & name)
{
	int remove_entry = find(name);
	if (remove_entry != -1)
	{
		for (int i = remove_entry; i < size - 1; i++)
		{
			the_directory[i] = the_directory[i + 1];
			size--;
		}
		return " ";
	}
	else
	{
		return " ";
	}
}

void Phone_Directory::save()
{
	if (modified) {  // if not modified, do nothing
					 // Create an output stream.
		ofstream out(source_name.c_str());
		for (int i = 0; i < size; i++) {
			out << the_directory[i].get_name() << "\n";
			out << the_directory[i].get_number() << "\n";
		}
		// Close the output stream.
		out.close();
		modified = false;
	}
}

int Phone_Directory::find(const std::string & name) const
{
	for (int i = 0; i < size; i++) {
		if (the_directory[i].get_name() == name)
			return i;
	}
	return -1;
}

void Phone_Directory::add(const std::string & name, const std::string & number)
{
	if (size == capacity) // If no room, reallocate.
		reallocate();
	// Increment size and add new entry.
	the_directory[size] = Directory_Entry(name, number);
	size++;
}

void Phone_Directory::remove_entry(int index)
{
}

void Phone_Directory::reallocate()
{
	// Double the capacity.
	capacity *= 2;
	// Create a new directory array.
	Directory_Entry* new_directory = new Directory_Entry[capacity];
	// Copy the old to the new
	for (int i = 0; i < size; i++) {
		new_directory[i] = the_directory[i];
	}
	// Return the memory occupied by the old directory.
	delete[] the_directory;
	// Set the_directory to point to the new directory.
	the_directory = new_directory;
}
