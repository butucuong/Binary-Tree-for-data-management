#include "list.h"
#include <vector>
using namespace std;
List::List()
{

	root = nullptr;
	this->treeSize = 0;

}

int List::size() {
	treeSize = countNode(root);
	return this->treeSize;

}

List::~List()
{
	treeSize = 0;
	destroySubTree(root);

}


List& List::operator = (const List& otherTree) {
	if (this != &otherTree)			//avoid self-copy
	{
		if (root != NULL)			//if the binary tree is not empty, 
									//destroy the binary tree
			destroySubTree(root);

		if (otherTree.root == NULL) //otherTree is empty
			root = NULL;
		else
			copyTree(root, otherTree.root);
	}								//end else

	return *this;
}



List::List(const List& g) {

	this->treeSize = g.treeSize;
	if (g.root == nullptr) {
		root = nullptr;
	}
	else {

		copyTree(this->root, g.root);
	}
}






//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------


int List::displayCount() {
	return countNode(root);
}


void List::copyTree(TreeNode*& thisRoot, TreeNode* sourceRoot) {
	if (sourceRoot == nullptr) {
		thisRoot = nullptr;
	}
	else {

		thisRoot = new TreeNode;
		thisRoot->value = sourceRoot->value;
		copyTree(thisRoot->left, sourceRoot->left);
		copyTree(thisRoot->right, sourceRoot->right);
	}
}






void List::insert(TreeNode*& one_node, TreeNode*& newNode)
{
	if (one_node == nullptr)
	{
		one_node = newNode;
		this->treeSize++;
	}
	else if (one_node->value == newNode->value) {
		
		return;

	}
	else if (newNode->value < one_node->value)
	{
		insert(one_node->left, newNode);

	}
	else
	{
		insert(one_node->right, newNode);
	}
}


void List::insert_by_name(TreeNode*& NodePtr, TreeNode*& newNode)
{

	if (NodePtr == nullptr)
	{
		NodePtr = newNode;
		this->treeSize++;
	}

	else if (operator==(NodePtr->value, newNode->value))
	{

		return;
	}
	else if (operator<(newNode->value, NodePtr->value))
	{
		insert_by_name(NodePtr->left, newNode);
	}
	else
	{
		insert_by_name(NodePtr->right, newNode);
	}
}


void List::insertNode(Car item)
{
	if (searchNode(item)) {
		cout << "\n**Duplicate Information**\n";
		return;
	}
	TreeNode* newNode = nullptr;											//create new node to avoid leak memory

	newNode = new TreeNode;
	newNode->value = item;
	newNode->left = newNode->right = nullptr;

	insert(root, newNode);
}



void List::insertNode_by_name(Car item)
{

	TreeNode* newNode = nullptr;

	newNode = new TreeNode;
	newNode->value = item;
	newNode->left = newNode->right = nullptr;

	insert_by_name(root, newNode);
}



void List::destroySubTree(TreeNode*& nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
		nodePtr = nullptr;
	}
}

void List::destroyTree() {
	destroySubTree(root);
}


void List::remove(Car item)
{

	deleteNode(item, root);
}


void List::deleteNode(Car item, TreeNode*& nodePtr)
{
	if (nodePtr == NULL) {
		return;
	}

	if (item < nodePtr->value)
		deleteNode(item, nodePtr->left);
	else if (item > nodePtr->value)
		deleteNode(item, nodePtr->right);
	else {
		makeDeletion(nodePtr);
	}
}


void List::makeDeletion(TreeNode*& nodePtr)
{


	if (nodePtr == nullptr) {									//Neu khong co Node can xoa thi xuat thong bao va thoat
		cout << "Cannot delete empty node." << endl;
		return;
	}
	TreeNode* tempNodePtr = nodePtr;							//Tao 1 con tro tro toi node can xoa
	if (nodePtr->right == NULL)
	{

		nodePtr = nodePtr->left;

	}
	else if (nodePtr->left == NULL)
	{

		nodePtr = nodePtr->right;

	}
	else {														//Neu ca 2 cay con deu rong
		tempNodePtr = nodePtr->left;							//Di ve ben trai (phan tu dung truoc no trong InOrder ) cua Node can xoa
		TreeNode* parent = nodePtr;

		while (tempNodePtr->right != NULL) {					//tempNodePtr se den Node can tim va parent se la Node cha cua no
			parent = tempNodePtr;
			tempNodePtr = tempNodePtr->right;
		}
		nodePtr->value = tempNodePtr->value;
		if (parent == nodePtr) {								//Truong hop dac biet: Node con trai cua Node can remove cung chinh la Node dung truoc no trong InOrder
			nodePtr->left = tempNodePtr->left;
		}
		else {
			parent->right = nodePtr->left;
		}

		delete tempNodePtr;										//Xoa phan tu right cua Node con cua phan tu can Remove
	}
}



bool List::searchNode(Car data, TreeNode*& nodePtr) {								//search element


	if (nodePtr != NULL) {
		if (data == nodePtr->value) {
			return true;
		}
		if (data < nodePtr->value) {
			return searchNode(data, nodePtr->left);
		}
		else {
			return searchNode(data, nodePtr->right);
		}
	}
	else {
		return false;
	}
}

bool List::searchNodebyID(string a, TreeNode*& nodePtr) {
	if (nodePtr != NULL) {
		if (a == nodePtr->value.getPersonalKey()) {
			return true;
		}
		if (a < nodePtr->value.getPersonalKey()) {
			return searchNodebyID(a, nodePtr->left);
		}
		else {
			return searchNodebyID(a, nodePtr->right);
		}
	}
	else {
		return false;
	}
}

bool List::searchNode(Car item)
{
	return searchNode(item, root);
}
bool List::searchNodebyID(string str) {
	return searchNodebyID(str, root);
}

void List::updateData(string str) {
	if (searchNodebyID(str)) {
		updateData(str, root);

	}
	else {
		return;
	}
}
void List::updateData(string a, TreeNode*& NodePtr) {
	if (NodePtr != NULL) {
		if (a == NodePtr->value.getPersonalKey()) {
			Setting updateCar;
			cin.ignore(1);
			updateCar.nhapThongTin();
			NodePtr->value.l_display.setCarName(updateCar.getCarName());
			NodePtr->value.l_display.setPersonalKey(updateCar.getPersonalKey());
			NodePtr->value.l_display.setServiceRemind(updateCar.getServiceRemind());
			NodePtr->value.l_display.setEmail(updateCar.getEmail());
			NodePtr->value.l_display.setODO(updateCar.getODO());

			NodePtr->value.l_sound.setCarName(updateCar.getCarName());
			NodePtr->value.l_sound.setPersonalKey(updateCar.getPersonalKey());
			NodePtr->value.l_sound.setServiceRemind(updateCar.getServiceRemind());
			NodePtr->value.l_sound.setEmail(updateCar.getEmail());
			NodePtr->value.l_sound.setODO(updateCar.getODO());

			NodePtr->value.l_general.setCarName(updateCar.getCarName());
			NodePtr->value.l_general.setPersonalKey(updateCar.getPersonalKey());
			NodePtr->value.l_general.setServiceRemind(updateCar.getServiceRemind());
			NodePtr->value.l_general.setEmail(updateCar.getEmail());
			NodePtr->value.l_general.setODO(updateCar.getODO());

			NodePtr->value.setCarName(updateCar.getCarName());
			NodePtr->value.setPersonalKey(updateCar.getPersonalKey());
			NodePtr->value.setServiceRemind(updateCar.getServiceRemind());
			NodePtr->value.setEmail(updateCar.getEmail());
			NodePtr->value.setODO(updateCar.getODO());
		}
		if (a < NodePtr->value.getPersonalKey()) {
			return updateData(a, NodePtr->left);
		}
		else {
			return updateData(a, NodePtr->right);
		}
	}

}

void List::nhap_thong_tin_display(TreeNode*& NodePtr) {
	static int countdis = 1;
	bool flagyn{ false };
	char continues('c');


	if (NodePtr != NULL) {

		nhap_thong_tin_display(NodePtr->left);

		system("cls");
		cout << "--- Input Display setting ---\n";
		cout << "Car index: " << countdis << endl;
		NodePtr->value.print_user_data();
		if (NodePtr->value.l_display.get_light_level() == 1 && NodePtr->value.l_display.get_screen_light_level() == 1 && NodePtr->value.l_display.get_taplo_light_level() == 1) {

			cout << "\n\t->This is car, data will be appended to your list." << endl;
			NodePtr->value.l_display.nhapThongTin();

		}
		else {
			cout << "\n\t->This car already existed, data will be overwriten.";
			NodePtr->value.l_display.xuatThongTin();
		}
		++countdis;
		if (countdis <= size()) {
			while (flagyn != true) {

				cout << "\nWill input for Car " << countdis << " ? (y/n): ";
				cin >> continues;

				if (toupper(continues) == 'N') {

					countdis = 1;

					return;

					flagyn = true;
				}
				if (toupper(continues) == 'Y')
				{
					cin.clear();
					cin.ignore(100, '\n');

					nhap_thong_tin_display(NodePtr->right);
					flagyn = true;

				}
				else {
					cin.clear();
					cin.ignore(100, '\n');
				}

			}


		}
		else {
			cin.clear();
			cin.ignore(100, '\n');
			countdis = 1;

			return;
		}



	}
}

void List::nhap_thong_tin_sound(TreeNode*& NodePtr) {
	static int countsnd = 1;
	bool flagyn{ false };
	char continues('c');
	if (NodePtr != NULL) {
		nhap_thong_tin_sound(NodePtr->left);

		system("cls");
		cout << "--- Input Sound setting ---\n";
		cout << "Car index: " << countsnd << endl;
		NodePtr->value.print_user_data();
		if (NodePtr->value.l_sound.get_call_level() == 1 && NodePtr->value.l_sound.get_media_level() == 1 && NodePtr->value.l_sound.get_navi_level() == 1 && NodePtr->value.l_sound.get_notification_level() == 1) {

			cout << "\n\t->This is car, data will be appended to your list." << endl;
			NodePtr->value.l_sound.nhapThongTin();

		}
		else {
			cout << "\n\t->This car already existed, data will be overwriten.";
			NodePtr->value.l_sound.xuatThongTin();
		}
		++countsnd;
		if (countsnd <= size())
			while (flagyn != true) {
				cout << "\nWill input for Car " << countsnd << " ? (y/n): ";
				cin >> continues;

				if (toupper(continues) == 'N') {
					cin.clear();
					cin.ignore(100, '\n');
					countsnd = 1;
					return;
					//flagyn = true;
				}
				if (toupper(continues) == 'Y')
				{

					cin.clear();
					cin.ignore(100, '\n');
					nhap_thong_tin_sound(NodePtr->right);
					flagyn = true;

				}
				else {
					cin.clear();
					cin.ignore(100, '\n');
				}

			}
		else {
			cin.clear();
			cin.ignore(100, '\n');
			countsnd = 1;
			return;
		}

	}

}

void List::nhap_thong_tin_general(TreeNode*& NodePtr) {
	static int countgen = 1;
	bool flagyn{ false };
	char continues('c');
	if (NodePtr != NULL) {
		nhap_thong_tin_general(NodePtr->left);

		system("cls");
		cout << "--- Input General setting ---\n";
		cout << "Car index: " << countgen << endl;
		NodePtr->value.print_user_data();
		if (NodePtr->value.l_general.get_language() == "Mandarin (entire branch)" && NodePtr->value.l_general.get_timeZone() == "(GMT-12:00)") {

			cout << "\n\t->This is car, data will be appended to your list." << endl;
			NodePtr->value.l_general.nhapThongTin();

		}
		else {
			cout << "\n\t->This car already existed, data will be overwriten.";
			NodePtr->value.l_general.xuatThongTin();
		}
		++countgen;
		if (countgen <= size())
			while (flagyn != true) {
				cout << "\nWill input for Car " << countgen << " ? (y/n): ";
				cin >> continues;

				if (toupper(continues) == 'N') {
					cin.clear();
					cin.ignore(100, '\n');
					countgen = 1;
					return;

				}
				if (toupper(continues) == 'Y')
				{

					cin.clear();
					cin.ignore(100, '\n');
					nhap_thong_tin_general(NodePtr->right);
					flagyn = true;

				}
				else {
					cin.clear();
					cin.ignore(100, '\n');
				}

			}
		else {
			cin.clear();
			cin.ignore(100, '\n');
			countgen = 1;
			return;
		}

	}

}


void List::nhap_thong_tin_general() {
	nhap_thong_tin_general(root);
}
void List::nhap_thong_tin_sound() {
	nhap_thong_tin_sound(root);
}
void List::nhap_thong_tin_display() {
	nhap_thong_tin_display(root);
}


void List::writetofileSetting() {
	ofstream f;
	f.open("Setting.txt", ios_base::out | ios_base::trunc);
	if (f.fail()) {
		cerr << "Can't open the Setting.txt file to read!";
		return;
	}
	else {
		try {
			writetofileSetting(root);
			cout << "Completed to write the data into file." << endl;
		}
		catch (...) {
			cerr << "Can't read the Setting.txt file.";
			return;
		}
	}
	f.close();


}

void List::writetofileSetting(TreeNode* NodePtr) {
	if (NodePtr != NULL) {
		writetofileSetting(NodePtr->left);
		NodePtr->value.writetofileSetting();
		writetofileSetting(NodePtr->right);
	}
}

int List::countNode(TreeNode* nodePtr)								//count all element in TREE 
{
	int count = 1;
	if (nodePtr->left != nullptr)
	{
		count += countNode(nodePtr->left);
	}
	if (nodePtr->right != nullptr)
	{
		count += countNode(nodePtr->right);
	}
	return count;
}


int List::treeLevel(TreeNode* nodePtr)
{
	if (nodePtr == NULL)
	{
		return 0;
	}

	else
		return 1 + max(treeLevel(nodePtr->right), treeLevel(nodePtr->left));



}

bool List::checkAvl(TreeNode* t) {
	if (t == NULL) 	return true;
	if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1) return false;
	return checkAvl(t->left) && checkAvl(t->right);
}


List::TreeNode* List::turnLeft(TreeNode*& a) {
	TreeNode* b = a->right;
	TreeNode* c = b->left;
	a->right = c;
	b->left = a;
	return b;
}

List::TreeNode* List::turnRight(TreeNode*& a) {
	TreeNode* b = a->left;
	TreeNode* d = b->right;
	a->left = d;
	b->right = a;
	return b;
}

List::TreeNode* List::updateTreeAvl(TreeNode* t) {
	if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1) {
		if (treeLevel(t->left) > treeLevel(t->right)) {
			TreeNode* p = t->left;
			if (treeLevel(p->left) >= treeLevel(p->right)) {
				t = turnRight(t);
			}
			else {
				t->left = turnLeft(t->left);
				t = turnRight(t);
			}
		}
		else {
			TreeNode* p = t->right;
			if (treeLevel(p->right) >= treeLevel(p->left)) {
				t = turnLeft(t);
			}
			else {
				t->right = turnRight(t->right);
				t = turnLeft(t);

			}
		}
	}
	if (t->left != NULL) t->left = updateTreeAvl(t->left);
	if (t->right != NULL) t->right = updateTreeAvl(t->right);
	return t;
}
void List::updateTreeAVL() {
	while (!checkAvl(root)) {
		root = updateTreeAvl(root);
	}
}

void List::vector2BST_by_name(TreeNode*& NodePtr) {
	vector<Car> arr;
	BST2vector(NodePtr, arr);

	if (NodePtr != NULL) {
		destroySubTree(NodePtr);

	}
	for (int i = 0; i < arr.size(); i++) {
		insertNode_by_name(arr[i]);
	}
}


void List::BST_by_name() {

	vector2BST_by_name(root);
}




void List::vector2BST_by_ID(TreeNode*& NodePtr) {
	vector<Car> arr;
	BST2vector(NodePtr, arr);
	if (NodePtr != NULL) {
		destroySubTree(NodePtr);

	}
	for (int i = 0; i < arr.size(); i++) {
		insertNode(arr[i]);
	}
}


void List::BST_by_ID() {
	vector2BST_by_ID(root);

}



void List::BST2vector(TreeNode* nodePtr, vector<Car>& arr)
{

	if (nodePtr)
	{

		BST2vector(nodePtr->left, arr);
		arr.push_back(nodePtr->value);
		BST2vector(nodePtr->right, arr);
	}


}


void List::xuat_thong_tin_display(TreeNode* NodePtr) {

	if (NodePtr != NULL) {
		xuat_thong_tin_display(NodePtr->left);
		NodePtr->value.xuatThongTinDisplay();
		xuat_thong_tin_display(NodePtr->right);
	}
}
void List::xuat_thong_tin_display() {
	xuat_thong_tin_display(this->root);
}

void List::xuat_thong_tin_sound(TreeNode* NodePtr) {
	if (NodePtr != NULL) {
		xuat_thong_tin_sound(NodePtr->left);
		NodePtr->value.xuatThongTinSound();
		xuat_thong_tin_sound(NodePtr->right);
	}
}
void List::xuat_thong_tin_sound() {
	xuat_thong_tin_sound(this->root);
}


void List::xuat_thong_tin_general(TreeNode* NodePtr) {
	if (NodePtr != NULL) {
		xuat_thong_tin_general(NodePtr->left);
		NodePtr->value.xuatThongTinGeneral();
		xuat_thong_tin_general(NodePtr->right);
	}
}
void List::xuat_thong_tin_general() {
	xuat_thong_tin_general(this->root);
}


void List::xuat_thong_tin_tat_ca(TreeNode* NodePtr) {
	if (NodePtr != NULL) {
		xuat_thong_tin_tat_ca(NodePtr->left);
		NodePtr->value.xuatThongTin();
		xuat_thong_tin_tat_ca(NodePtr->right);
	}
}
void List::xuat_thong_tin_tat_ca() {
	xuat_thong_tin_tat_ca(this->root);
}