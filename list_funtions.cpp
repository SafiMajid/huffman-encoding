#include"Classes.h"
treelist::treelist()
{
	first = NULL;
	tail = NULL;

}
void treelist::insertend(char A, int B)
{
	node *naya = new node;
	naya->character = A;
	naya->frequency = B;
	naya->left = NULL;
	naya->right = NULL;
	naya->next = NULL;

	if (first == NULL)
	{
		naya->previous = NULL;
		first = naya;
		tail = naya;
	}
	else
	{
		naya->previous = tail;
		tail->next = naya;
		tail = naya;
	}

}
node* treelist::search(char A)
{
	node* B = first;
	while (B != NULL)
	{
		if (B->character == A)
			return B;
		else
			B = B->next;
	}

}
bool treelist::searchn(char A)
{
	node* B = first;
	while (B != NULL)
	{
		if (B->character == A)
			return true;
		else
			B = B->next;
	}
	return false;
}
void treelist::edit(node* A)
{
	A->frequency = A->frequency + 1;
}
void treelist::editc(node* A)
{
	A->frequency = A->frequency - 1;
}
void treelist::deletelast()
{
	if (first->next == NULL)
	{
		deleteit(1);
	}
	else {
		node *A = new node;
		node *B = new node;
		A = first;
		while (A->next != NULL)
		{
			B = A;
			A = A->next;
		}
		B->next = NULL;
		delete A;
		A = NULL;
		tail = B;
	}
}
void treelist::deleteit(int pos)
{
	node *A = first;
	 if (pos == 1)
	{
		if (first->next != NULL)
		{
			first->next->previous = NULL;
			first = first->next;				//first to point at next of first node
			delete A;							//deleting A
			A = NULL;
		}
		else if (first==tail)
		{
			delete A;
			A = NULL;
			first = NULL;
			tail = NULL;

		}
	}
}
void treelist::printit(node *thisnode)
{

	if (thisnode->character != '\n' && thisnode->character != ' ')
		std::cout << thisnode->character << "\t" << thisnode->frequency << endl;
	else if (thisnode->character == '\n')
		std::cout << "Enter" << "\t" << thisnode->frequency << endl;
	else
		std::cout << "Space" << "\t" << thisnode->frequency << endl;
}
void treelist::traverse(int num)
{
	node *A = NULL;
	A = first;
	if (num == -1)
	{
		if (first == NULL)
			std::cout << "empty list";
		while (A != NULL)
		{
			printit(A);
			A = A->next;

		}
	}
	else if (num == 1)
	{
		printit(first);
	}
	else if (num == 0)
	{
		std::cout << "nothing to move and print as you inputted 0" << std::endl;
	}


}
void treelist::deleteall()
{
	while (first != NULL)
	{
		deletelast();
	}


}
void treelist::swapdata(node* A, node* B)
{
	//if (A==first || B==first || A==tail || B== tail)
	//{
	//	if (A == first)
	//	{
	//		if (B == tail)
	//		{
	//			node* temp = first;
	//			while (temp->next != tail)
	//				temp = temp->next;
	//			temp->next = A;
	//			B->next = A->next;
	//			A->next = NULL;
	//			first = B;
	//			tail = A;
	//			
	//			
	//		}
	//		else
	//		{
	//		/*	node* temp = first;
	//			while (temp->next != B)
	//				temp = temp->next;
	//			A->next = B->next;
	//			temp->next = A;
	//			B->next = first->next;
	//			first = B;*/
	//			
	//		}
	//		
	//	
	//	}
	//}
	//else
	//{
	//}

	int freq = A->frequency;
	char character = A->character;
	node* Al = A->left;
	node* Ar = A->right;
	A->character = B->character;
	A->frequency = B->frequency;
	A->left = B->left;
	A->right = B->right;
	B->character = character;
	B->frequency = freq;
	B->left = Al;
	B->right = Ar;
}
void treelist::sort()
{
	node* B = first;
	while (B !=  tail)
	{
		node* A = first;

		while (A != tail)
		{

			if (A->frequency > A->next->frequency)
			{
				swapdata(A, A->next);
			}
			A = A->next;
		}
		B = B->next;
	}
}
void treelist::insert_wrt_freq(node* A, int freq)
{
	if (tail == NULL && first == NULL)
	{
		first = A;
		tail = A;
		A->next = NULL;
		A->previous = NULL;
	}
	else if (A==NULL)
	{ }
	else
	{
		if (freq < tail->frequency && freq > first->frequency && first != tail)
		{
			node* B = first;
			while (B->frequency <= freq)
				B = B->next;
			A->previous = B->previous;
			B->previous->next = A;
			B->previous = A;
			A->next = B;
		}
		else if (freq >= tail->frequency )
		{
			tail->next = A;
			A->previous = tail;
			A->next = NULL;
			tail = A;
		}
		else if (freq <= first->frequency && first != tail)
		{
			if (freq < first->frequency)
			{
				A->next = first;
				first->previous = A;
				first = A;
				A->previous = NULL;
			}
			else
			{
				A->next = first->next;
				first->next->previous = A;
				first->next = A;
			}
		}
		else if (first == tail)
		{
			if (freq > first->frequency)
			{
				first->next = A;
				A->previous = first;
				A->next = NULL;
				tail = A;
			}
			else
			{
				A->next = first;
				A->previous = NULL;
				first->previous = A;
				first = A;
			}
		}
	}
}
void treelist::deleteit(node* A)
{
	if (A == first)
	{
		deleteit(1);
	}
	else if (A == tail)
	{
		deletelast();
	}
	else if (first == NULL || tail == NULL)
	{
		delete A;
		A = NULL;
	}
	else
	{
		A->previous->next = A->next;
		A->next->previous = A->previous;
		delete A;
		A = NULL;
	}
}
node* treelist::combine_node_for_huffman_tree(node* A, node* B)
{
	if (A != NULL && B != NULL)
	{
		node* C = new node;
		node* L = new node;
		node* R = new node;
		L->next = NULL;
		L->previous = NULL;
		L->character = A->character;
		L->left = A->left;
		L->right = A->right;
		L->frequency = A->frequency;
		R->character = B->character;
		R->frequency = B->frequency;
		R->next = NULL;
		R->left = B->left;
		R->right = B->right;
		R->previous = NULL;
		C->left = L;
		C->right = R;
		C->frequency = L->frequency + R->frequency;
		C->character = NULL;
		deleteit(A);
		deleteit(B);

		return C;
	}
	else if (A == NULL && B != NULL)
	{
		return B;
	}
	else if (A != NULL && B== NULL)
	{
		return A;
	}
}
void treelist::huffman_tree()
{
	sort();
	node* A = first;
	while (A->next != NULL)
	{
		node* B = new node;B = combine_node_for_huffman_tree(A, A->next);
		insert_wrt_freq(B, B->frequency);
		A = first;
	}
	treetraverse(first, "");
}
void treelist::checktree(node* A)
{
	if (A == NULL)
		return;
	checktree(A->left);
	cout << A->frequency<<endl;
	checktree(A->right);
}
void treelist::treetraverse(node* A, string code)
{
	if (A->left != NULL)
	{
		treetraverse(A->left, code + '0');
	}
	if (A->right != NULL)
	{
		treetraverse(A->right, code + '1');
	}
	if(A->left== NULL && A->right==NULL)
	{
		bin_codes.insertend(A->character, code); return;
		
	}

}
char treelist::string_to_char(node* N)
{
	/////*while (A != "")
	////{
	////	if (A[0] == '0')
	////	{
	////		if (N->left != NULL)
	////		{
	////			A.erase(0, 1);
	////			string_to_map(N->left, A, B + '0');
	////		}
	////		if (N->left == NULL)
	////		{
	////			A.erase(0, 1);
	////			decodemap.insertend(N->character, B); return;
	////		}
	////	}
	////	if (A[0] == '1')
	////	{
	////		if (N->right != NULL)
	////		{
	////			A.erase(0, 1);
	////			string_to_map(N->right, A, B + '1');
	////		}
	////		if (N->right == NULL)
	////		{
	////			A.erase(0, 1);
	////			decodemap.insertend(N->character, B); return;
	////		}
	////	}
	////}*/

	while (N != NULL)
	{
		if (encoded_stream[0] == '0')
		{
			if (N->left != NULL)
			{
				N = N->left; encoded_stream.erase(0, 1);
				
			}
			else
				return N->character;

		
		}
		if (encoded_stream[0] == '1')
		{
			if (N->right != NULL)
			{
				N = N->right; encoded_stream.erase(0, 1);
				
			}
			else
				return N->character;
		}
		if (encoded_stream == "")
			return N->character;
			
	}




}
void treelist::input_stream_string(string A,string B)
{
	input_stream = A;
	decoded_stream = "";
	encoded_stream = B;
}
