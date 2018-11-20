#include"Classes.h"
map::map() 
{
	first = NULL;
	tail = NULL;
}
string map::map_to_string(mapnode* A)
{
	return A->address;
}
void map::insertend(char A,string B)
{
	mapnode* C = new mapnode;
	C->character = A;
	C->address = B;
	C->next = NULL;
	if (first == NULL)
	{
		C->previous = NULL;
		first = C;
		tail = C;
	}
	else
	{
		C->previous = tail;
		tail->next = C;
		tail = C;
	}

}
mapnode* map::search(char character)
{
	mapnode* A = new mapnode;
	A = first;
	while (A->character!=character)
	{
		A = A->next;
	}
	if (A != NULL)
	{
		return A;
	}
	else
	{
		cerr << endl << "character not found";
	}
}
void map::map_print_check()
{
	mapnode* A = first;
	while (A != NULL)
	{
		if (A->character != '\n' && A->character != ' ' && A->character != '\t') {
			cout << A->character << "\t\t" << A->address << endl; 
		}
		else if (A->character == '\n')
		{
			cout << "Enter" << "\t\t" << A->address << endl; 
		}
		else if (A->character == ' ')
		{
			cout << "Space" << "\t\t" << A->address << endl; 
		}
		else if (A->character == '\t')
		{
			cout << "Tab" << "\t\t" << A->address << endl; 
		}
		A = A->next;
	}
}