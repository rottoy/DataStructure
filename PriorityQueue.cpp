#include <iostream>
#include <conio.h>
#define MAX_SIZE 200
#define ROOT 1

using namespace std;



//insert : heapSize��°�� ��ü����
//delete : �켱������ ���� ��ü����
class Heap {

public:
	int heap[MAX_SIZE];
	int heapSize; //Insert�� ������ �ش��ϴ� ������
public:
	Heap();
	void InsertHeap(int element);
	void DeleteHeap();
	void Show();

};
Heap::Heap() :heapSize(0){
	for (int i = 0; i < MAX_SIZE; i++) {
		heap[i] = -1;
	}
}
void Heap::InsertHeap(int element) { // ���� ������ ������ ����
	
	int i = ++(heapSize); //�� ������ ������ �ϳ� ����

	heap[i] = element; // �� �����͸� ������ ���� �迭�� ����.
	
	while(element < heap[i / 2]) { // ���� ���� �θ𺸴� ������ �θ�� �ڸ���ȯ.

		if (i != 1) { // i��°�� ��Ʈ��尡 �ƴ϶��(��Ʈ��� = 1)
			
			int temp = element; //�ڸ���ȯ
			element = heap[i / 2];
			heap[i / 2] = temp;
			heap[i] = element; 

			element = temp; // ��ȯ�� �ٽ� ���� element �� ����.

			
			i = i / 2; // �� �ܰ� �θ�� �ö�. 
		}
		else {break;}
	}
}

void Heap::Show() {
	cout << "���� ���ڵ� ����" << endl;
	for (int i = 1; i < heapSize+1; i++)
	{
		cout << i << "��° ���� : " << heap[i] << endl;
	}

}
void Heap::DeleteHeap() {
	int parent=1, child1=2, child2=3;
	bool childSelect = 0;
	if (heapSize != -1)
	{
		heap[ROOT] = heap[heapSize]; // ��Ʈ��尪�� ��������忡�ִ������� �ٲ�.
		heapSize--; // �� ���� 1�� ����.
		 
		while (heapSize>=child1) {
			childSelect = (heap[child1] < heap[child2]);//(0 or 1)1 �̸� ������ ������. 0�̸� �������� �� ����.

			if (childSelect == 1) //������ �������� 
			{
				if (heap[parent] > heap[child1]) { // �θ� �ڽĺ��� ũ�� �ٲ���!
					int temp = heap[parent]; // �θ�(parent)�� �����ڽ�(child1)��ȯ
					heap[parent] = heap[child1];
					heap[child1] = temp;

					parent = child1;
					child1 = parent * 2 ;
					child2 = parent * 2 + 1;
					
				}

				else
				{break;}
			}
			else // �������� ��������
			{
	
				if (heap[parent] > heap[child2]) { // �θ� �ڽĺ��� ũ�� �ٲ���!
					int temp = heap[parent];  // �θ�(parent)�� �������ڽ�(child2)��ȯ
					heap[parent] = heap[child2];
					heap[child2] = temp;

					parent = child2;
					child1 = parent * 2 ;
					child2 = parent * 2 + 1;
				}

				else
				{break;}
			}
		}
		
	}
}
int main() {

	Heap tree;
	tree.InsertHeap(5);
	tree.InsertHeap(2);
	tree.InsertHeap(6);
	tree.InsertHeap(3);
	tree.InsertHeap(1);
	tree.InsertHeap(8);
	tree.InsertHeap(16);
	tree.InsertHeap(4);
	tree.InsertHeap(7);
	tree.DeleteHeap();
	tree.Show();
	_getch();
}