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
void List::insertAnotherUser() {
	Car new_user;
	new_user.nhapThongTin();
	insertNode(new_user);
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



void List::insertNodeByName(Car item)
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

bool List::searchNodeByID(string a, TreeNode*& nodePtr) {
	if (nodePtr != NULL) {
		if (a == nodePtr->value.getPersonalKey()) {
			return true;
		}
		if (a < nodePtr->value.getPersonalKey()) {
			return searchNodeByID(a, nodePtr->left);
		}
		else {
			return searchNodeByID(a, nodePtr->right);
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
bool List::searchNodeByID(string str) {
	return searchNodeByID(str, root);
}

void List::updateData(string str) {
	if (searchNodeByID(str)) {
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
			NodePtr->value.m_display_concrete.updateUser(updateCar);
			
			NodePtr->value.m_sound_concrete.updateUser(updateCar);
			
			NodePtr->value.m_general_concrete.updateUser(updateCar);
			
			NodePtr->value.updateUser(updateCar);
			
		}
		if (a < NodePtr->value.getPersonalKey()) {
			return updateData(a, NodePtr->left);
		}
		else {
			return updateData(a, NodePtr->right);
		}
	}

}

void List::nhapThongTinDisplay(TreeNode*& NodePtr) {
	static int s_count = 1;
	bool confirm_flag{ false };
	char confirm('c');


	if (NodePtr != NULL) {

		nhapThongTinDisplay(NodePtr->left);

		system("cls");
		cout << "--- Input Display setting ---\n";
		cout << "Car index: " << s_count << endl;
		NodePtr->value.print_user_data();
		if (NodePtr->value.m_display_concrete.getLightLevel() == 1 && NodePtr->value.m_display_concrete.getScreenLightLevel() == 1 && NodePtr->value.m_display_concrete.getTaploLightLevel() == 1) {

			cout << "\n\t->This is car, data will be appended to your list." << endl;
			NodePtr->value.m_display_concrete.nhapThongTin();

		}
		else {
			cout << "\n\t->This car already existed, data will be overwriten.";
			NodePtr->value.m_display_concrete.xuatThongTin();
		}
		++s_count;
		if (s_count <= size()) {
			while (confirm_flag != true) {

				cout << "\nWill input for Car " << s_count << " ? (y/n): ";
				cin >> confirm;

				if (toupper(confirm) == 'N') {

					s_count = 1;

					return;

					confirm_flag = true;
				}
				if (toupper(confirm) == 'Y')
				{
					cin.clear();
					cin.ignore(100, '\n');

					nhapThongTinDisplay(NodePtr->right);
					confirm_flag = true;

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
			s_count = 1;

			return;
		}



	}
}

void List::nhapThongTinSound(TreeNode*& NodePtr) {
	static int s_count = 1;
	bool confirm_flag{ false };
	char confirm('c');
	if (NodePtr != NULL) {
		nhapThongTinSound(NodePtr->left);

		system("cls");
		cout << "--- Input Sound setting ---\n";
		cout << "Car index: " << s_count << endl;
		NodePtr->value.print_user_data();
		if (NodePtr->value.m_sound_concrete.getCallLevel() == 1 && NodePtr->value.m_sound_concrete.getMediaLevel() == 1 && NodePtr->value.m_sound_concrete.getNaviLevel() == 1 && NodePtr->value.m_sound_concrete.getNotificationLevel() == 1) {

			cout << "\n\t->This is car, data will be appended to your list." << endl;
			NodePtr->value.m_sound_concrete.nhapThongTin();

		}
		else {
			cout << "\n\t->This car already existed, data will be overwriten.";
			NodePtr->value.m_sound_concrete.xuatThongTin();
		}
		++s_count;
		if (s_count <= size())
			while (confirm_flag != true) {
				cout << "\nWill input for Car " << s_count << " ? (y/n): ";
				cin >> confirm;

				if (toupper(confirm) == 'N') {
					cin.clear();
					cin.ignore(100, '\n');
					s_count = 1;
					return;
					//flagyn = true;
				}
				if (toupper(confirm) == 'Y')
				{

					cin.clear();
					cin.ignore(100, '\n');
					nhapThongTinSound(NodePtr->right);
					confirm_flag = true;

				}
				else {
					cin.clear();
					cin.ignore(100, '\n');
				}

			}
		else {
			cin.clear();
			cin.ignore(100, '\n');
			s_count = 1;
			return;
		}

	}

}

void List::nhapThongTinGeneral(TreeNode*& NodePtr) {
	static int s_count = 1;
	bool confirm_flag{ false };
	char confirm('c');
	if (NodePtr != NULL) {
		nhapThongTinGeneral(NodePtr->left);

		system("cls");
		cout << "--- Input General setting ---\n";
		cout << "Car index: " << s_count << endl;
		NodePtr->value.print_user_data();
		if (NodePtr->value.m_general_concrete.getLanguage() == "Mandarin (entire branch)" && NodePtr->value.m_general_concrete.getTimezone() == "(GMT-12:00)") {

			cout << "\n\t->This is car, data will be appended to your list." << endl;
			NodePtr->value.m_general_concrete.nhapThongTin();

		}
		else {
			cout << "\n\t->This car already existed, data will be overwriten.";
			NodePtr->value.m_general_concrete.xuatThongTin();
		}
		++s_count;
		if (s_count <= size())
			while (confirm_flag != true) {
				cout << "\nWill input for Car " << s_count << " ? (y/n): ";
				cin >> confirm;

				if (toupper(confirm) == 'N') {
					cin.clear();
					cin.ignore(100, '\n');
					s_count = 1;
					return;

				}
				if (toupper(confirm) == 'Y')
				{

					cin.clear();
					cin.ignore(100, '\n');
					nhapThongTinGeneral(NodePtr->right);
					confirm_flag = true;

				}
				else {
					cin.clear();
					cin.ignore(100, '\n');
				}

			}
		else {
			cin.clear();
			cin.ignore(100, '\n');
			s_count = 1;
			return;
		}

	}

}


void List::nhapThongTinGeneral() {
	nhapThongTinGeneral(root);
}
void List::nhapThongTinSound() {
	nhapThongTinSound(root);
}
void List::nhapThongTinDisplay() {
	nhapThongTinDisplay(root);
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
void List::readfromfileSetting() {
	ifstream ifs_setting;
	string begin_word;
	string string_word, parameter_in_string;
	int parameter{};
	ifs_setting.open("Setting.txt", ios::in);
	if (ifs_setting.fail()) {
		cerr << "Can't open the Setting.txt file to read!";
		return;
	}
	else {
		try {

			ifs_setting.seekg(0, ios::end);
			auto size = ifs_setting.tellg();
			if (size == 0) {
				cout << "Ready to write on file.";
				system("cls");
				cout << "Car number: " << 1 << endl;
				Car new_car;
				new_car.nhapThongTin();
				insertNode(new_car);
			}
			else {
				ifs_setting.seekg(0);
				while (!ifs_setting.eof()) {
					Setting data;

					ifs_setting >> begin_word;
					ifs_setting.seekg(3, 1);
					getline(ifs_setting, string_word, '/');
					data.setCarName(string_word);

					getline(ifs_setting, string_word, '/');
					data.setEmail(string_word);

					getline(ifs_setting, string_word, '/');
					data.setPersonalKey(string_word);

					getline(ifs_setting, parameter_in_string, '/');
					parameter = stoi(parameter_in_string);
					data.setODO(parameter);

					getline(ifs_setting, parameter_in_string, 'S');
					parameter = stoi(parameter_in_string);

					data.setServiceRemind(parameter);


					getline(ifs_setting, begin_word, ':');
					ifs_setting.seekg(4, 1);

					Sound SND(data);

					getline(ifs_setting, parameter_in_string, '/');
					parameter = stoi(parameter_in_string);
					SND.setMediaLevel(parameter);

					getline(ifs_setting, parameter_in_string, '/');
					parameter = stoi(parameter_in_string);
					SND.setCallLevel(parameter);

					getline(ifs_setting, parameter_in_string, '/');
					parameter = stoi(parameter_in_string);
					SND.setNaviLevel(parameter);

					getline(ifs_setting, parameter_in_string, 'D');
					parameter = stoi(parameter_in_string);
					SND.setNotificationLevel(parameter);

					Display DIS(data);

					getline(ifs_setting, begin_word, ':');
					ifs_setting.seekg(2, 1);

					getline(ifs_setting, parameter_in_string, '/');
					parameter = stoi(parameter_in_string);
					DIS.setLightLevel(parameter);

					getline(ifs_setting, parameter_in_string, '/');
					parameter = stoi(parameter_in_string);
					DIS.setScreenLightLevel(parameter);

					getline(ifs_setting, parameter_in_string, 'G');
					parameter = stoi(parameter_in_string);
					DIS.setTaploLightLevel(parameter);


					General GEN(data);



					getline(ifs_setting, begin_word, ':');
					ifs_setting.seekg(2, 1);
					getline(ifs_setting, string_word, '/');
					GEN.setTimezone(string_word);

					getline(ifs_setting, string_word);
					GEN.setLanguage(string_word);
					ifs_setting.ignore(1);
					Car newCar(data, SND, DIS, GEN);
					insertNode(newCar);							//Them cac doi tuong vao binary tree them vao DATA_b de kiem tra

				}

			}
			return;
		}
		catch (...) {
			cerr << "Can't read the Setting.txt file.";
			system("pause");
			return;
		}
	}
	ifs_setting.close();
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

bool List::checkAVL(TreeNode* t) {
	if (t == NULL) 	return true;
	if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1) return false;
	return checkAVL(t->left) && checkAVL(t->right);
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
	while (!checkAVL(root)) {
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
		insertNodeByName(arr[i]);
	}
}


void List::BSTByName() {

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


void List::BSTByID() {
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


void List::xuatThongTinDisplay(TreeNode* NodePtr) {

	if (NodePtr != NULL) {
		xuatThongTinDisplay(NodePtr->left);
		NodePtr->value.xuatThongTinDisplay();
		xuatThongTinDisplay(NodePtr->right);
	}
}
void List::xuatThongTinDisplay() {
	xuatThongTinDisplay(this->root);
}

void List::xuatThongTinSound(TreeNode* NodePtr) {
	if (NodePtr != NULL) {
		xuatThongTinSound(NodePtr->left);
		NodePtr->value.xuatThongTinSound();
		xuatThongTinSound(NodePtr->right);
	}
}
void List::xuatThongTinSound() {
	xuatThongTinSound(this->root);
}


void List::xuatThongTinGeneral(TreeNode* NodePtr) {
	if (NodePtr != NULL) {
		xuatThongTinGeneral(NodePtr->left);
		NodePtr->value.xuatThongTinGeneral();
		xuatThongTinGeneral(NodePtr->right);
	}
}
void List::xuatThongTinGeneral() {
	xuatThongTinGeneral(this->root);
}


void List::xuatThongTinTatCa(TreeNode* NodePtr) {
	if (NodePtr != NULL) {
		xuatThongTinTatCa(NodePtr->left);
		NodePtr->value.xuatThongTin();
		xuatThongTinTatCa(NodePtr->right);
	}
}
void List::xuatThongTinTatCa() {
	xuatThongTinTatCa(this->root);
}