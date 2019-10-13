#include "binarytree.h"

template<class T>
node<T>::node() {
	left = NULL;
	right = NULL;
	parent = NULL;
}

template<class T>
void node<T>::setdata(T data) {
	this->data = data;
}

template<class T>
T node<T>::getdata() {
	return data;
}

template<class T>
void node<T>::setleft(node<T>* left) {
	this->left = left;
}

template<class T>
node<T>* node<T>::getleft() {
	return  left;
}

template<class T>
void node<T>::setright(node<T>* right) {
	this->right = right;
}

template<class T>
node<T>* node<T>::getright() {
	return right;
}

template<class T>
void node<T>::setparent(node<T>* parent) {
	this->parent = parent;
}

template<class T>
node<T>* node<T>::getparent() {
	return parent;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
binarytree<T>::binarytree()
{
	root = NULL;
}

template<class T>
void binarytree<T>::insert(T data) {
	if (root == NULL) {
		root = new node<T>;
		root->setdata(data);
	}
	else {
		bool run = true;
		node<T>* temp = root;
		while (run == true) {
			if (data == temp->getdata()) {//stops duplicates
				cout << "error " << data << " already exists in tree.";
				break;
			}
			else if (data < temp->getdata()) { //data is less than node data
				if (temp->getleft() == NULL) { //checks if left is null if so new node is inserted there with data
					node<T>* temp2 = new node<T>; //dummy node
					temp2 ->setdata(data); //data is put into temp2 and parent is set to temp.
					temp2 ->setparent(temp);
					temp->setleft(temp2);//temp's left child is now temp2
					break;
				}
				else
					temp = temp->getleft(); // increments pointer to left pointer of current node
			}
			else
				if (temp->getright() == NULL) {// data is greater than current node data and if right node is null then its initatiated with data in it.
					node<T>* temp2 = new node<T>; //dummy node 
					temp2->setdata(data);//data is put into temp2 and parent is set to temp.
					temp2->setparent(temp);
					temp->setright(temp2);//temp's right child is now the temp2 node.
					break;
				}
				else
					temp = temp->getright();//increments pointer to the right
		}
	}
}

template<class T>
node<T>* binarytree<T>::search(T data) {
	node<T>* temp = root;//temperory pointer
	while (temp != NULL) {//return a node when that node's data is equal to input data.
		if (temp->getdata() == data)
			return temp;
		else if (temp->getdata() < data) //temp goes left if its input data is smaller than current node data else it goes right
			temp = temp->getright();
		else
			temp = temp->getleft();
	}
}

template<class T>
void binarytree<T>::delnode(T data) {
	node<T>* temp;
	temp = search(data);//return with node pointer with input in it.
	if (temp != NULL) {//node to be deleted cannot be null
		if (temp->getleft() == NULL && temp->getright() == NULL) {//no children
			node<T>* parent = temp->getparent();//parent is parent of node to be deleted
			if (parent->getleft() == temp) {
				delete parent->getleft();//deletes node to be deleted and parent left pointer is now null
				parent->setleft(NULL);
			}
			else {
				delete parent->getright();//deletes node to be deleted and parent right pointer is now null
				parent->setright(NULL);
			}
		}
		else if (temp->getleft() == NULL || temp->getright() == NULL) {//both cant be NULL because of first case(single child case)
			delSingleChild(temp);

		}
		else {//2 child case
			node<T>* successor = temp->getright(); //getting successor by going right once then continously going left.
			while (successor->getleft() != NULL) {
				successor = successor->getleft();
			}

			temp->setdata(successor->getdata());//data from successor is put in node that was to be deleted.
			if (successor->getleft() == NULL && successor->getright() == NULL) {//successer has no children
				node<T>* parent = successor->getparent();//parent is parent of successor
				if (parent->getleft() == successor) {
					delete parent->getleft();//successor is deleted and parent left pointer is now null
					parent->setleft(NULL);
				}
				else {
					delete parent->getright();//successor deleted and parent right pointer in now null
					parent->setright(NULL);
				}
			}
			else
				delSingleChild(successor);

		}
	}
}

template<class T>
void binarytree<T>::delSingleChild(node<T>* delnode) {
	node<T>* child;//child of node being delete
	if (delnode->getright() != NULL) {//finds out if child is left or right
		child = delnode->getright();
		delnode->setdata(child->getdata());//child data put in parent node
		delete delnode->getright();//deletes child and sets right pointer to null
		delnode->setright(NULL);
	}
	else {
		child = delnode->getleft();
		delnode->setdata(child->getdata());//child data put in parent node
		delete delnode->getleft();//deletes child and set left pointer to null
		delnode->setleft(NULL);
	}
}

template<class T>
void binarytree<T>::inorder() {
	inorder(root);
}

template<class T>
void binarytree<T>::inorder(node<T>* node) {
	if (node != NULL) {
		inorder(node->getleft());
		cout << node->getdata() << endl;
		inorder(node->getright());
	}
}

template<class T>
void binarytree<T>::preorder() {
	preorder(root);
}

template<class T>
void binarytree<T>::preorder(node<T>* node) {
	if (node != NULL) {
		cout << node->getdata() << endl;
		preorder(node->getleft());
		preorder(node->getright());
	}
}

template<class T>
binarytree<T>::~binarytree()
{
}