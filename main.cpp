#include <iostream>
using namespace std;
#include "binarytree.h"
#include "binarytree.cpp"

int main() {

	binarytree<int> tree;
	tree.insert(10);
	tree.insert(15);
	tree.insert(12);
	tree.insert(8);
	tree.insert(9);
	tree.insert(11);
	cout << "tree before deletions \n";
	tree.inorder();
	tree.delnode(10);
	tree.delnode(15);
	tree.delnode(8);

	cout << "\ntree after deletions\n";
	tree.inorder();
	cout << endl;
	cout << "tree preorder after deletions\n";
	tree.preorder();
}