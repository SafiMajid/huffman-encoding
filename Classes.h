#pragma once
#define CLASSES_H

using namespace std;

 
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bitset>
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>


#include<algorithm>
struct mapnode
{
	char character;
	string address;
	mapnode* next;
	mapnode* previous;
};

struct map
{
	mapnode* first;
	mapnode* tail;
	map();
	void insertend(char, string);
	mapnode* search(char);
	string map_to_string(mapnode*);
	void map_print_check();
};


struct node
{
	char character;
	int frequency;
	node *next;
	node *previous;
	node *left;
	node *right;
};

struct treelist
{
	int substractor;
	map bin_codes;
	node *first;
	node *tail;
	string input_stream;
	string encoded_stream;
	string decoded_stream;
	treelist();
	void insertend(char, int);
	void deleteit(int);
	void input_stream_string(string,string);
	void deletelast();
	void printit(node*);
	void traverse(int);
	void deleteall();
	node* search(char);
	void edit(node*);
	void editc(node*);
	bool searchn(char A);
	void swapdata(node*, node*);
	void sort();
	void insert_wrt_freq(node*, int);
	node* combine_node_for_huffman_tree(node*, node*);
	void deleteit(node*);
	void huffman_tree();
	void checktree(node*);
	void treetraverse(node*, string);
	char string_to_char(node*);
};



struct code
{
	/////*friend class boost::serialization::access;
	////template<class Archive>*/
	/*void serialize(Archive & ar, code & g, const unsigned int version)
	{
		ar & g.alpha;
	}*/
	fstream file;
	string input_stream;
	string encoded_stream;
	treelist alpha;
	code(string,bool);
	void stringinitializer();
	void Frequency_tally_and_Input_String_Extracter();
	void encoder();
	void decoder();


};
