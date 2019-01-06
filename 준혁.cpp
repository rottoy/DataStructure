#include <iostream>
#include <conio.h>
using namespace std;

class TreeNode {
	
	public:
		TreeNode* leftNode;
		TreeNode* rightNode;
		int data;
		int degree;
	public:
		TreeNode(int inputData, TreeNode* inputLeft, TreeNode* inputRight,int degree) {
			this->data = inputData;
			this->leftNode = inputLeft;
			this->rightNode = inputRight;
			this->degree = degree;
		};


};


class Tree {

	private:
		TreeNode* rootNode;

	public:
		Tree();
		void Add(int inputData);
		void Delete();
		TreeNode* Search(TreeNode* current, int inputData);
		void ShowInDFS(TreeNode* current);
		void Show(TreeNode* current,int degree);
		void ShowInTree(TreeNode* current);
		TreeNode* GetRoot() {return rootNode;}

};
Tree::Tree() {
	rootNode = NULL;

}
void Tree::Add(int inputData) {
	if (rootNode == NULL)
	{
		
		rootNode = new TreeNode(inputData,NULL,NULL,0);

	}
	else
	{
		//cout <<"����" <<inputData << endl;

		if (Search(rootNode, inputData) ==NULL) //"�ߺ��� ���� ���� ��"�� ó���Ѵ�! else������ ����!
		{
			
			TreeNode* parent = NULL;
			TreeNode* current = rootNode; //�ٽ� Ž���ؼ� ���� �־��.
			while (current != NULL)
			{
				parent = current;


				if (current->data > inputData){current = current->leftNode; }
				else {current = current->rightNode;}

			}
			if (parent->data > inputData)
			{
			
				parent->leftNode = new TreeNode(inputData,NULL,NULL,parent->degree+1);

				cout << parent->data << "�� ���� ��忡" << inputData << "�߰��մϴ�." << endl;
			}
			else
			{
				
				parent->rightNode = new TreeNode(inputData, NULL, NULL,parent->degree+1);

				cout << parent->data << "�� ���� ��忡" << inputData << "�߰��մϴ�." << endl;
			}
		}
	
	}

	

}
void Tree::Delete() {

}
TreeNode* Tree::Search(TreeNode* current, int inputData) {
	if (current == NULL) { return NULL; } // ��ġ�� ����(�� �ߺ� X)
	if (current->data == inputData) { return current; } // ��ġ�� ����(�ش� ����ּ� ��ȯ)
	if (current->data > inputData) { return Search(current->leftNode,inputData);} // �Է°��� ���������� ������ ��������
	if (current->data < inputData) { return Search(current->rightNode,inputData);} //�Է°��� ���������� Ŭ �� ����������

	//��û�� �Ǽ��� �Ͽ���. ����Լ����� return ���� ������ �����ְ� search�Լ��� ȣ���Ͽ���.
	//�� search�Լ��� null�� ��ȯ�Ͽ� �����͵� �����Լ����� return�� �����־ �̻��Ѱ���ȣ��Ǿ��� ���̴�.

}

void Tree::ShowInDFS(TreeNode* current)
{	
	if (current != NULL) {
		
		ShowInDFS(current->leftNode);
		Show(current,current->degree);
		ShowInDFS(current->rightNode);
	}
	
}

void Tree::ShowInTree(TreeNode* current) {

}
void Tree::Show(TreeNode* current,int degree)
{
	if (current != NULL)
	{
		for (int i = 0; i < degree; i++) { cout << "    "; }
		cout << current->data <<endl;
	
	}
}
int main() {
	
	Tree tree;
	tree.Add(8);
	tree.Add(3);
	tree.Add(10);
	tree.Add(14);
	tree.Add(2);
	tree.Add(5);
	tree.Add(11);
	tree.Add(16);

	tree.Add(10);

	tree.ShowInDFS(tree.GetRoot());
	_getch();

}