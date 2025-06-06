#pragma once
#include<iostream>
#include<algorithm>
using namespace std;
//*************************************************************
// Author: D.S. Malik
//
// class binaryTreeType
// This class specifies the basic operations to implement a
// binary tree.
//*************************************************************
//Definition of the node
template <class elemType>
struct binaryTreeNode
{
	elemType info;
	binaryTreeNode<elemType>* llink;
	binaryTreeNode<elemType>* rlink;
};
//Definition of the class
template <class elemType>
class binaryTreeType
{
public:
	const binaryTreeType<elemType>& operator=
		(const binaryTreeType<elemType>&);
	//Overload the assignment operator.
	bool isEmpty() const;
	//Returns true if the binary tree is empty;
	//otherwise, returns false.
	void inorderTraversal() const;
	//Function to do an inorder traversal of the binary tree.
	void preorderTraversal() const;
	//Function to do a preorder traversal of the binary tree.
	void postorderTraversal() const;
	//Function to do a postorder traversal of the binary tree.
	int treeHeight() const;
	//Returns the height of the binary tree.
	int treeNodeCount() const;
	//Returns the number of nodes in the binary tree.
	int treeLeavesCount() const;
	//Returns the number of leaves in the binary tree.
	void destroyTree();
	//Deallocates the memory space occupied by the binary tree.
	//Postcondition: root = NULL;
	binaryTreeType(const binaryTreeType<elemType>& otherTree);
	//copy constructor
	binaryTreeType();
	//default constructor
	~binaryTreeType();
	//destructor

	elemType treeMax();

	elemType sumTree();
	elemType findMinTree();
	int countPSCTree();
	int countEvenTree();
	int countInternalNodesTree();

protected:
	binaryTreeNode<elemType>* root;
private:
	void copyTree(binaryTreeNode<elemType>*& copiedTreeRoot,
		binaryTreeNode<elemType>* otherTreeRoot);
	//Makes a copy of the binary tree to which
	//otherTreeRoot points. The pointer copiedTreeRoot
	//points to the root of the copied binary tree.
	void destroy(binaryTreeNode<elemType>*& p);
	//Function to destroy the binary tree to which p points.
	//Postcondition: p = NULL
	void inorder(binaryTreeNode<elemType>* p) const;
	//Function to do an inorder traversal of the binary
	//tree to which p points.
	void preorder(binaryTreeNode<elemType>* p) const;
	//Function to do a preorder traversal of the binary
	//tree to which p points.
	void postorder(binaryTreeNode<elemType>* p) const;
	//Function to do a postorder traversal of the binary
	//tree to which p points.
	int height(binaryTreeNode<elemType>* p) const;
	//Function to return the height of the binary tree
	//to which p points.
	int max(int x, int y) const;
	//Returns the larger of x and y.
	int nodeCount(binaryTreeNode<elemType>* p) const;
	//Function to return the number of nodes in the binary
	//tree to which p points
	int leavesCount(binaryTreeNode<elemType>* p) const;
	//Function to return the number of leaves in the binary
	//tree to which p points

	elemType subTreeMax(binaryTreeNode<elemType>* p, elemType max);
	elemType sumSubTree(binaryTreeNode<elemType>* p);
	elemType findMinSubTree(binaryTreeNode<elemType>* p);
	int countPSC(binaryTreeNode<elemType>* p);
	int countEven(binaryTreeNode<elemType>* p);
	int countInternalNodes(binaryTreeNode<elemType>* p);
};

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
	return (root == NULL);
}

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
	root = NULL;
}
template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
	inorder(root);
}
template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
	preorder(root);
}
template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
	postorder(root);
}
template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
	return height(root);
}
template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
	return nodeCount(root);
}
template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
	return leavesCount(root);
}
template <class elemType>
void binaryTreeType<elemType>::
inorder(binaryTreeNode<elemType>* p) const
{
	if (p != NULL)
	{
		inorder(p->llink);
		cout << p->info << " ";
		inorder(p->rlink);
	}
}
template <class elemType>
void binaryTreeType<elemType>::
preorder(binaryTreeNode<elemType>* p) const
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}
template <class elemType>
void binaryTreeType<elemType>::
postorder(binaryTreeNode<elemType>* p) const
{
	if (p != NULL)
	{
		postorder(p->llink);
		postorder(p->rlink);
		cout << p->info << " ";
	}
}
template <class elemType>
int binaryTreeType<elemType>::
height(binaryTreeNode<elemType>* p) const
{
	if (p == NULL)
		return 0;
	else
		return 1 + max(height(p->llink), height(p->rlink));
}
template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
	if (x >= y)
		return x;
	else
		return y;
}

template <class elemType>
int binaryTreeType<elemType>::nodeCount(binaryTreeNode<elemType>* p) const
{
	if (p == NULL)
		return 0;
	else
		return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
}

template <class elemType>
int binaryTreeType<elemType>::leavesCount(binaryTreeNode<elemType>* p) const
{
	if (p == NULL)
		return 0;
	else if (p->llink == 0 && p->rlink == 0)
		return 1;
	else
		return leavesCount(p->llink) + leavesCount(p->rlink);
}

template <class elemType>
void binaryTreeType<elemType>::copyTree
(binaryTreeNode<elemType>*& copiedTreeRoot,
	binaryTreeNode<elemType>* otherTreeRoot)
{
	if (otherTreeRoot == NULL)
		copiedTreeRoot = NULL;
	else
	{
		copiedTreeRoot = new binaryTreeNode<elemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
		copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
	}
} //end copyTree

template <class elemType>
void binaryTreeType<elemType>::destroy(binaryTreeNode<elemType>*& p)
{
	if (p != NULL)
	{
		destroy(p->llink);
		destroy(p->rlink);
		delete p;
		p = NULL;
	}
}

template <class elemType>
void binaryTreeType<elemType>::destroyTree()
{
	destroy(root);
}

//copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType
(const binaryTreeType<elemType>& otherTree)
{
	if (otherTree.root == NULL) //otherTree is empty
		root = NULL;
	else
		copyTree(root, otherTree.root);
}

//destructor
template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
	destroy(root);
}

//overloading the assignment operator
template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::operator=
(const binaryTreeType<elemType>& otherTree)
{
	if (this != &otherTree) //avoid self-copy
	{
		if (root != NULL) //if the binary tree is not empty,
		//destroy the binary tree
			destroy(root);
		if (otherTree.root == NULL) //otherTree is empty
			root = NULL;
		else
			copyTree(root, otherTree.root);
	}//end else
	return *this;
}

template<class Type>
Type binaryTreeType<Type>::treeMax()
{
	return subTreeMax(root, root->info);
}

template<class Type>
Type binaryTreeType<Type>::subTreeMax(binaryTreeNode<Type>* p, Type max)
{
	if (p == NULL)
		return max;
	else
	{
		Type x = subTreeMax(p->llink, max);
		Type y = subTreeMax(p->rlink, max);

		if (x > y)
			max = x;
		else
			max = y;

		if (p->info > max)
			max = p->info;
		return max;
	}
}

template <class Type>
Type binaryTreeType<Type>::sumTree()
{
	return sumSubTree(this->root);
}

template<class Type>
Type binaryTreeType<Type>::sumSubTree(binaryTreeNode<Type>* p)
{
	if (p == NULL)
		return 0;
	else
		return sumSubTree(p->llink) + p->info + sumSubTree(p->rlink);
}

template <class Type>
Type binaryTreeType<Type>::findMinTree()
{
	return findMinSubTree(this->root);
}

template <class Type>
Type binaryTreeType<Type>::findMinSubTree(binaryTreeNode<Type>* p)
{
	Type min;
	if (p->llink == NULL && p->rlink == NULL)
		return p->info;
	else if (p->llink == NULL)
		min = findMinSubTree(p->rlink);
	else if (p->rlink == NULL)
		min = findMinSubTree(p->llink);
	else
		min = std::min(findMinSubTree(p->llink), findMinSubTree(p->rlink));

	if (min < p->info)
		return min;
	else
		return p->info;
}

template <class Type>
int binaryTreeType<Type>::countPSCTree()
{
	return countPSC(this->root);
}

template <class Type>
int binaryTreeType<Type>::countPSC(binaryTreeNode<Type>* p)
{
	if (p->llink == NULL && p->rlink == NULL)
		return 0;
	else if (p->llink != NULL && p->rlink == NULL)
		return 1 + countPSC(p->llink);
	else if (p->llink == NULL && p->rlink != NULL)
		return 1 + countPSC(p->rlink);
	else
		return countPSC(p->llink) + countPSC(p->rlink);
}

template <class Type>
int binaryTreeType<Type>::countEvenTree()
{
	return countEven(this->root);
}

template <class Type>
int binaryTreeType<Type>::countEven(binaryTreeNode<Type>* p)
{
	int n = 0;
	if (p->llink == NULL && p->rlink == NULL)
	{
		if (p->info % 2 == 0)
			return 1;
		else
			return 0;
	}

	else if (p->llink == NULL)
		n = countEven(p->rlink);

	else if (p->rlink == NULL)
		n = countEven(p->llink);

	else 
		n = countEven(p->llink) + countEven(p->rlink);

	if (p->info % 2 == 0)
		return 1 + n;
	else
		return n;
}

template <class Type>
int binaryTreeType<Type>::countInternalNodesTree()
{
	return countInternalNodes(this->root);
}

template <class Type>
int binaryTreeType<Type>::countInternalNodes(binaryTreeNode<Type>* p)
{
	/*if (p->llink == NULL && p->rlink == NULL)
		return 0;
	else if (p->llink == NULL)
		return 1 + countInternalNodes(p->rlink);
	else if (p->rlink == NULL)
		return 1 + countInternalNodes(p->llink);
	else
		return 1 + countInternalNodes(p->llink) + countInternalNodes(p->rlink);*/

	if (p == NULL)
		return 0;
	else if (p->llink == NULL || p->rlink == NULL)
		return 1 + countInternalNodes(p->llink) + countInternalNodes(p->rlink);
	else
		return  countInternalNodes(p->llink) + countInternalNodes(p->rlink);
}