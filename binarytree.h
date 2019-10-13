#pragma once
#include <iostream>
using namespace std;


template<class T>
class node {
private:
	node<T>* parent;
	node<T>* left;
	node<T>* right;
	T data;
public:
	node();
	void setdata(T);
	T getdata();
	void setparent(node<T>*);
	node<T>* getparent();
	void setleft(node<T>*);
	node<T>* getleft();
	void setright(node<T>*);
	node<T>* getright();
};


template<class T>
class binarytree
{
private:
	node<T>* root;
	void inorder(node<T>*); // recursive function
	void preorder(node<T>*);
	void delSingleChild(node<T>*);
public:
	binarytree();
	~binarytree();
	void insert(T);
	void inorder(); // calls recursiver version
	void preorder();
	node<T>* search(T);
	void delnode(T);
};