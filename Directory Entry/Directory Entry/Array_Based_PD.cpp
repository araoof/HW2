#include "Array_Based_PD.h"

//Step 6: Complete Programming Exercise 1.7 (page 121).
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

void Phone_Directory::remove_entry(int index)
{
}
