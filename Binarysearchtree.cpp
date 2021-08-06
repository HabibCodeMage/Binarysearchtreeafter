// Binarysearchtree.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include"BST.h"
using namespace std;
int main()
{
	BST<int> obj;
	obj.insert(7);
	obj.insert(4);
	obj.insert(13);
	obj.insert(2);
	obj.insert(6);
	obj.insert(11);
	obj.insert(15);
	obj.insert(1);
	obj.insert(3);
	obj.insert(5);
	obj.insert(9);
	obj.insert(12);
	obj.insert(14);
	obj.insert(16);
	obj.insert(8);
	obj.insert(10);
	cout << "BREDTH FIRST SEARCH:\n";
	obj.bredthfirst(obj.Root());
	obj.removenode(7);
	obj.removenode(15);
	cout << "\nBREDTH FIRST SEARCH:\n";
	obj.bredthfirst(obj.Root());
	cout << "\nINORDER TRAVERSAL:\n";
	obj.inorder(obj.Root());
	cout << "\nHEIGHT OF TREE:\n";
	cout<<obj.height(obj.Root())<<endl;
	cout << "\nDepth of Root->right->left:\n";
	BST<int>::position object = obj.Root();
	cout<<obj.depth(object.right().left());
	cout << "\n Mininimun in BST:\n"
	<<obj.min();
	cout << "\n Maximum in BST:\n"
		<< obj.max();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
