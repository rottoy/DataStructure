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
		//cout <<"나는" <<inputData << endl;

		if (Search(rootNode, inputData) ==NULL) //"중복된 값이 없을 때"만 처리한다! else구문은 없다!
		{
			
			TreeNode* parent = NULL;
			TreeNode* current = rootNode; //다시 탐색해서 값을 넣어보자.
			while (current != NULL)
			{
				parent = current;


				if (current->data > inputData){current = current->leftNode; }
				else {current = current->rightNode;}

			}
			if (parent->data > inputData)
			{
			
				parent->leftNode = new TreeNode(inputData,NULL,NULL,parent->degree+1);

				cout << parent->data << "의 좌측 노드에" << inputData << "추가합니다." << endl;
			}
			else
			{
				
				parent->rightNode = new TreeNode(inputData, NULL, NULL,parent->degree+1);

				cout << parent->data << "의 우측 노드에" << inputData << "추가합니다." << endl;
			}
		}
	
	}

	

}
void Tree::Delete() {

}
TreeNode* Tree::Search(TreeNode* current, int inputData) {
	if (current == NULL) { return NULL; } // 서치에 실패(값 중복 X)
	if (current->data == inputData) { return current; } // 서치에 성공(해당 노드주소 반환)
	if (current->data > inputData) { return Search(current->leftNode,inputData);} // 입력값이 기존값보다 작을때 왼족으로
	if (current->data < inputData) { return Search(current->rightNode,inputData);} //입력값이 기존값보다 클 때 오른쪽으로

	//엄청난 실수를 하였다. 재귀함수에서 return 값을 지정을 안해주고 search함수만 호출하였다.
	//즉 search함수가 null을 반환하여 가져와도 다음함수에서 return을 안해주어서 이상한값이호출되었던 것이다.

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