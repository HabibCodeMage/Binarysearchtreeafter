#pragma once
#ifndef BST_H
#define BST_H
#include<stddef.h>
#include<iostream>
#include"dequeu.h"
using namespace std;
template<typename T>
class BST
{
private:
	struct node
	{
		T value;
		node* right;
		node* left;
		node* parent;
	};
private:
	void preorder(node* ptr)
	{
		if (ptr)
		{
			cout << ptr->value<<endl;
			if (ptr->left)
				preorder(ptr->left);
			if (ptr->right)
				preorder(ptr->right);
		}
	}
	void inorder(node* ptr)
	{
		if (ptr)
		{

			if (ptr->left)
				inorder(ptr->left);
			cout << ptr->value << endl;
			if (ptr->right)
				inorder(ptr->right);
		}
	}
	void postorder(node* ptr)
	{
		if (ptr)
		{

			if (ptr->left)
				postorder(ptr->left);
			if (ptr->right)
				postorder(ptr->right);
			cout << ptr->value << endl;
		}
	}
private:
	node* root;
	void insert(node*& nodeptr, node*& newnode, node* parent)
	{
		if (nodeptr == NULL)
		{
			nodeptr = newnode;
			nodeptr->parent = parent;
		}
		else if (newnode->value <= nodeptr->value)
			insert(nodeptr->left, newnode, nodeptr);
		else
			insert(nodeptr->right, newnode, nodeptr);
	}
	void makedeletion(node*& nodeptr)
	{
		node* temp;
		if (nodeptr->left == NULL && nodeptr->right == NULL)
		{
			if (nodeptr->parent->left == nodeptr)
			{
				nodeptr->parent->left = NULL;
			}
			else if (nodeptr->parent->right == nodeptr)
			{
				nodeptr->parent->right = NULL;
			}
			delete nodeptr;
		}
		else if (nodeptr->left == NULL)
		{
			temp = nodeptr;
			nodeptr = nodeptr->right;
			nodeptr->parent = temp->parent;
			delete temp;
		}
		else if (nodeptr->right == NULL)
		{
			temp = nodeptr;
			nodeptr = nodeptr->left;
			nodeptr->parent = temp->parent;
			delete temp;
		}
		else
		{
			temp = nodeptr->left;
			while (temp->right)
				temp = temp->right;
			nodeptr->value = temp->value;
			if (temp->parent->left == temp)
			{
				makedeletion(temp->parent->left);
			}
			if (temp->parent->right == temp)
			{
				makedeletion(temp->parent->right);
			}
		}


	}
	void deletenode(const T& value, node*& root)
	{
		if (root->value == value)
			makedeletion(root);
		else if (value < root->value)
			deletenode(value, root->left);
		else
			deletenode(value, root->right);
	}
	void deletsubtrees(node*& nodeptr)
	{
		if (nodeptr)
		{
			if (nodeptr->left != NULL)
				deletsubtrees(nodeptr->left);
			if (nodeptr->right != NULL)
				deletsubtrees(nodeptr->right);
			delete nodeptr;
			nodeptr = NULL;
		}
	}
	int depth(node* u)
	{
		if (u == root)
			return 0;
		else
			return 1 + depth(u->parent);
	}
	int height(node* u)
	{
		if (u == NULL)
			return -1;
		else
			return 1 + (height(u->left) > height(u->right) ? height(u->left) : height(u->right));
		/*if (u->left==NULL && u->right == NULL)
			return 0;
		else
		{
			int x = 0, y = 0;
			if (u->left != NULL)
				x = height(u->left);
			if (u->right != NULL)
				y = height(u->right);
			return 1 + (x > y ? x : y);
		}*/
	}
public:
	class position
	{
	private:
		node* v;
	public:
		position(node* u) :v(u)
		{}
		position getfather() const
		{
			return v->parent;
		}
		position left()
		{
			return v->left;
		}
		position right() const
		{
			return v->right;
		}
		bool isexternal()
		{
			if (v->left == NULL && v->right == NULL)
				return true;
			return false;
		}
		bool isinternal()
		{
			return(v->left != NULL && v->right != NULL);
		}
		T& operator*()
		{
			return v->value;
		}
		friend class BST;
	};
public:
	BST() :root(NULL)
	{}
	void insert(const T& value)
	{
		node* newnode = new node{ value };
		newnode->left = newnode->right = NULL;
		insert(root, newnode, NULL);
	}
	int min()
	{
		node* u = this->root;
		while (u->left!=NULL)
		{
			u = u->left;
		}
		return u->value;
	}
	int max()
	{
		node* u = this->root;
		while (u->right!= NULL)
		{
			u = u->right;
		}
		return u->value;

	}
	bool searchnode(const T& value)
	{
		node* traverse = root;
		while (traverse)
		{
			if (traverse->value == value)
				return true;
			else if (value < traverse->value)
				traverse = traverse->left;
			else
				traverse = traverse->right;
		}
		return false;
	}
	void removenode(const T& value)
	{
		if (root == NULL)
			throw"EMPTY TREE";
		if (!searchnode(value))
			throw"GIVEN VALUE NOT EXIST";
		deletenode(value, root);

	}
	void preorder(const position& ptr)
	{
		preorder(ptr.v);
	}
	void inorder(const position& ptr)
	{
		inorder(ptr.v);
	}
	void postorder(const position& ptr)
	{
		postorder(ptr.v);
	}
	const position Root()
	{
		return position(root);
	}
	int height(const position& obj)
	{
		return height(obj.v);
	}
	int depth(const position& obj)
	{
		return depth(obj.v);
	}
	void bredthfirst(const position& obj)
	{
		deque<node*> object;
		object.insertback(obj.v);
		while (!object.empty())
		{
			cout << object.front()->value << endl;
			if (object.front()->left != NULL)
				object.insertback(object.front()->left);
			if (object.front()->right != NULL)
				object.insertback(object.front()->right);
			object.erasefront();
		}
	}
	~BST()
	{
		deletsubtrees(root);
	}
};
#endif // !BST_H
