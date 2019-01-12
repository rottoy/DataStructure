#include <iostream>
#include <conio.h>
#define MAX_SIZE 200
#define ROOT 1

using namespace std;



//insert : heapSize번째에 객체생성
//delete : 우선순위에 의한 객체삭제
class Heap {

public:
	int heap[MAX_SIZE];
	int heapSize; //Insert의 순서에 해당하는 데이터
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
void Heap::InsertHeap(int element) { // 가장 마지막 순서에 삽입
	
	int i = ++(heapSize); //힙 데이터 갯수가 하나 들어났다

	heap[i] = element; // 그 데이터를 마지막 히프 배열에 삽입.
	
	while(element < heap[i / 2]) { // 들어온 값이 부모보다 작으면 부모랑 자리교환.

		if (i != 1) { // i번째가 루트노드가 아니라면(루트노드 = 1)
			
			int temp = element; //자리교환
			element = heap[i / 2];
			heap[i / 2] = temp;
			heap[i] = element; 

			element = temp; // 교환후 다시 비교할 element 재 지정.

			
			i = i / 2; // 한 단계 부모로 올라감. 
		}
		else {break;}
	}
}

void Heap::Show() {
	cout << "히프 인자들 보기" << endl;
	for (int i = 1; i < heapSize+1; i++)
	{
		cout << i << "번째 인자 : " << heap[i] << endl;
	}

}
void Heap::DeleteHeap() {
	int parent=1, child1=2, child2=3;
	bool childSelect = 0;
	if (heapSize != -1)
	{
		heap[ROOT] = heap[heapSize]; // 루트노드값이 마지막노드에있던값으로 바뀜.
		heapSize--; // 힙 갯수 1개 감소.
		 
		while (heapSize>=child1) {
			childSelect = (heap[child1] < heap[child2]);//(0 or 1)1 이면 왼쪽이 더작음. 0이면 오른쪽이 더 작음.

			if (childSelect == 1) //왼쪽이 더작으면 
			{
				if (heap[parent] > heap[child1]) { // 부모가 자식보다 크면 바꾸자!
					int temp = heap[parent]; // 부모(parent)와 왼쪽자식(child1)교환
					heap[parent] = heap[child1];
					heap[child1] = temp;

					parent = child1;
					child1 = parent * 2 ;
					child2 = parent * 2 + 1;
					
				}

				else
				{break;}
			}
			else // 오른쪽이 더작으면
			{
	
				if (heap[parent] > heap[child2]) { // 부모가 자식보다 크면 바꾸자!
					int temp = heap[parent];  // 부모(parent)와 오른쪽자식(child2)교환
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