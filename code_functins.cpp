#include"Classes.h"

void code::stringinitializer()
{
	encoded_stream = ""; input_stream = "";
}
void code::Frequency_tally_and_Input_String_Extracter()
{
	/*char character;
	file.get(character);
	input_stream = input_stream + character;
	alpha.insertend(character, 1);
	while (!file.eof())
	{
		file.get(character); input_stream = input_stream + character;
		if (alpha.searchn(character))
		{
			alpha.edit(alpha.search(character));
		}
		else
		{
			alpha.insertend(character, 1);
		}


	}
	alpha.editc(alpha.search(character));
	input_stream.erase(input_stream.length() - 1, input_stream.length());*/

	string Full_stream;
	file.seekg(0, ios::end);
	Full_stream.resize(file.tellg());
	file.seekg(0, ios::beg);
	file.read(&Full_stream[0], Full_stream.size());
	input_stream = Full_stream;
	while(Full_stream!="")
	{
		
		alpha.insertend(Full_stream[0], count(Full_stream.begin(), Full_stream.end(), Full_stream[0]));
		char a = Full_stream[0];
		Full_stream.erase(remove(Full_stream.begin(), Full_stream.end(), a), Full_stream.end());
	}
	
}
void code::encoder()
{
	for (int i = 0; i < input_stream.length(); i++)
	{
		encoded_stream += alpha.bin_codes.map_to_string(alpha.bin_codes.search(input_stream[i]));

	}
}
void code::decoder()
{
	/*while (alpha.encoded_stream != "")
	{
		alpha.decoded_stream += alpha.string_to_char(alpha.first);
	}*/

	node* N = alpha.first;
	for (int i = 0; i < alpha.encoded_stream.length(); i++)
	{
		if (alpha.encoded_stream[i] == '0')
		{
			N = N->left;
		}
		else
		{
			N = N->right;
		}
		if (N->left == NULL)
		{
			alpha.decoded_stream += N->character;
			N = alpha.first;
		}
	}

	
}






code::code(string file_path, bool arg)
{

	if (arg == true)
	{
		file.open(file_path);
		stringinitializer();
		Frequency_tally_and_Input_String_Extracter();
		alpha.huffman_tree();
		//alpha.bin_codes.map_print_check();
		file.close();
		//cout << endl << input_stream << endl;
		encoder();
		//cout << endl << encoded_stream << endl;
		alpha.input_stream_string(input_stream, encoded_stream);
		int A = encoded_stream.length();
		file.open("hidden.txt", ios::out);
		file << encoded_stream;
		file.close();
		file.open("output4.txt", ios::out /*| ios::binary*/);
		if (file.is_open())
			cout << "yes";
		string encoded_output = encoded_stream;
		

		string test="";


			while (encoded_output != "")
			{
				if (encoded_output.length() > 8)
				{
					bitset<8> encode(string(encoded_output.substr(0, 8)));
					unsigned int encode_dec = encode.to_ulong();
					char encode_char = static_cast<char>(encode_dec);
					test+= encode_char;
					encoded_output.erase(0, 8);
				}
				else
				{
					alpha.substractor = 8 - encoded_output.length();
					bitset<8> encode(string(encoded_output.substr(0, encoded_output.length())));

					unsigned int encode_dec = encode.to_ulong();
					char encode_char = static_cast<char>(encode_dec);
					test+= encode_char; 
					encoded_output.erase(0, encoded_output.length());
				}

				/*boost::archive::text_oarchive oa(file);
				oa << alpha;*/
			}
			//file << encoded_stream;
			/*file << test;
			file << alpha.substractor;*/
			/*test += "3";*/
			file.write(test.c_str(), sizeof(char)*test.size());
			file << alpha.substractor;
			ostringstream tester;
			tester << alpha.substractor;
			test += tester.str();
		file.close();

	/*}
	else
	{*/
	
		file.open("output4.txt");
		string Full_stream1="";
		file.seekg(0, ios::end);
		Full_stream1.resize(file.tellg());
		file.seekg(0, ios::beg);
		file.read(&Full_stream1[0], Full_stream1.size()); 
		if (Full_stream1 != test) { Full_stream1 = test; }
		/*Full_stream1 = test;*/
		alpha.substractor =static_cast<int>(Full_stream1[Full_stream1.length()-1])-48;
		

		string last_bits,stream;
		
		if (alpha.substractor == -48)
		{
			alpha.substractor = 0;
		}
			stream = Full_stream1.substr(0, Full_stream1.length() - 2);
			char lastchar = Full_stream1[Full_stream1.length() - 2];
			int Lastint = static_cast<int>(lastchar);
			bitset<8> lastbits(Lastint);
			last_bits = lastbits.to_string().substr(alpha.substractor, lastbits.to_string().length());
			string check = alpha.encoded_stream.substr(alpha.encoded_stream.length() - 8, alpha.encoded_stream.length());
		/*}
		else
		{
			stream = Full_stream.substr(0, Full_stream.length() - 1);
			 last_bits = "";
		}*/
		string encoded_file_stream = "";
		
		for (int i = 0; i < stream.length(); i++)
		{
			bitset<8> byte_char(static_cast<int>(static_cast<char>(stream[i])));
			encoded_file_stream += byte_char.to_string();

		}
		encoded_file_stream += last_bits;
		if (alpha.encoded_stream == encoded_file_stream) { cout << "works"; alpha.encoded_stream = encoded_file_stream; };

		
		file.close();
		/*file.open("hidden.txt");
		string check2="";
		while (file.good())
		{
			char c; file.get(c);
			check2 += c;

		}
		if (alpha.encoded_stream == check2)
		{
			cout << "works"; alpha.encoded_stream = check2;
		}
		file.close();
		alpha.encoded_stream = check2;*/
		decoder();
		file.open(/*C:/Users/safim/OneDrive - seecs.edu.pk/Semester 3/data structures/Projects/Project1/Project1/*/"outputd4.txt", ios::out);
		if (file.is_open())
			cout << "yes";
		file << alpha.decoded_stream;
		file.close();
	}
	//cout << endl << alpha.decoded_stream << endl;
	
	
	

}