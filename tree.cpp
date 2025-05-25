#include <iostream> 
#include "binarySearchTree.h" 
using namespace std; 

int main() 
{ 
	bSearchTreeType<int> treeRoot; 
	int num; 
	cout << "Enter numbers ending with -999"<< endl; 
	cin >> num; 
	while (num != -999) 
	{ 
		treeRoot.insert(num); 
		cin >> num; 
	} 
	cout << endl << "Tree nodes in inorder: "; 
	treeRoot.inorderTraversal(); 
	cout << endl << "Tree Height: "
		<< treeRoot.treeHeight()
		<< endl << endl; 

	cout << endl << "Tree Height: "
		<< treeRoot.treeHeight() << endl;

	cout << endl << "Nodes count: " << treeRoot.treeNodeCount() << endl;
	cout << endl << "Leaves count: " << treeRoot.treeLeavesCount() << endl;

	cout << endl << endl;

	bSearchTreeType<int> tree;
	tree.insert(2);
	tree.insert(1);
	tree.insert(3);
	tree.insert(7);
	tree.insert(8);
	tree.preorderTraversal();
	tree.incrementByWrapper(5);
	cout << endl;
	tree.preorderTraversal();
	cout << endl;

	bSearchTreeType<int> t1;
	/*t1.insert(5);
	t1.insert(13);
	t1.insert(1);
	t1.insert(7);
	t1.insert(3);
	t1.insert(27);
	t1.insert(15);
	t1.insert(10);*/
	t1.insert(37);
	t1.insert(24);
	t1.insert(42);
	t1.insert(32);
	t1.insert(7);
	t1.insert(2);
	t1.insert(40);
	t1.insert(45);
	t1.insert(120);
	cout << t1.treeMax() << endl;

	cout << endl;
	t1.inorderTraversal();
	cout << endl;
	cout << t1.treeHeight() << endl;

	cout << t1.sumTree() << endl;

	cout << endl;
	t1.inorderTraversal();
	cout << endl << t1.findMinTree() << endl << endl;

	cout << t1.countPSCTree() << endl << endl;

	cout << t1.countEvenTree() << endl << endl;

	cout << t1.countInternalNodesTree() << endl << endl;

	return 0; 
} 
