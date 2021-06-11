#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <algorithm>


#include "Car.h"
using namespace std;

class List {																//store the data by Binary Tree
private:

	//Node for Binary Tree
	struct TreeNode
	{
		Car value;														//object
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
		

	};

	int treeSize;

	void insert_by_name(TreeNode*&, TreeNode*&);						//insert by Name
	void insert(TreeNode*&, TreeNode*&);								//insert by ID 			
	void copyTree(TreeNode*& thisRoot, TreeNode* sourceRoot);
	void destroySubTree(TreeNode*&);									//destroy sub-tree
	void deleteNode(Car, TreeNode*&);								//destroy node
	void makeDeletion(TreeNode*&);									//when no sub-tree remain 


	int treeLevel(TreeNode* nodePtr);
	int countNode(TreeNode*);



	void BST2vector(TreeNode*, vector<Car>&);							//De quy lay du lieu tu cay them vao vector

	void vector2BST_by_name(TreeNode*& NodePtr);						//Chuyen du lieu tu vector ve cay
	void vector2BST_by_ID(TreeNode*& NodePtr);							//Chuyen du lieu tu vector ve cay

	bool searchNode(Car, TreeNode*&);									//search elemen
	bool searchNodebyID(string a, TreeNode*&);
	void updateData(string a, TreeNode*&);
	void nhap_thong_tin_display( TreeNode*&);
	void nhap_thong_tin_general(TreeNode*&);
	void nhap_thong_tin_sound(TreeNode*&);


	void xuat_thong_tin_tat_ca(TreeNode* NodePtr);
	void xuat_thong_tin_display(TreeNode* NodePtr);
	void xuat_thong_tin_sound(TreeNode* NodePtr);
	void xuat_thong_tin_general(TreeNode* NodePtr);

	void writetofileSetting(TreeNode* Nodeptr);

	TreeNode* turnRight(TreeNode*& a);
	TreeNode* turnLeft(TreeNode*& a);
	TreeNode* updateTreeAvl(TreeNode* t);
protected:
	TreeNode* root;
public:
	List& operator =(const List&);
	List(const List& g);
	List();
	~List();
	void destroyTree();
	void insertNode(Car);
	void insertNode_by_name(Car);
	bool checkAvl(TreeNode* t);

	
	void updateTreeAVL();

	int size();
	bool searchNode(Car item);
	bool searchNodebyID(string);
	void remove(Car);
	int displayCount();

	void updateData(string str);
	void nhap_thong_tin_display();
	void nhap_thong_tin_sound();
	void nhap_thong_tin_general();

	void BST_by_name();													//Sort binary tree by name
	void BST_by_ID();													//Sort binary tree by ID

	void xuat_thong_tin_tat_ca();
	void xuat_thong_tin_display();
	void xuat_thong_tin_sound();
	void xuat_thong_tin_general();

	void writetofileSetting();
};