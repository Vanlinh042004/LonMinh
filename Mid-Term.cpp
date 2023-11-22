#include "C++.h"
using namespace std;
struct SinhVien {
	int id;
	char ten[30];
};
using SV = SinhVien;

struct Node {
	SV data;
	Node* next;
};
using node = Node*;
node MakeNode(SV sv) {
	cout << "Nhap id: "; cin >> sv.id;
	cin.ignore();
	cout << "Nhap ten: "; cin.getline(sv.ten, 30);
	node p = new Node;
	p->data = sv;
	p->next = NULL;
	return p;
}
void InsertFirst(node& head, SV sv) {
	node temp = MakeNode(sv);
	if (head == NULL) head = temp;
	else {
		temp->next = head;
		head = temp;
	}
}
#pragma region WriteFile
void Print(SV sv, ofstream& Out) {
	Out << sv.id << " " << sv.ten;
	Out << endl;
}
void PrintList(node head, ofstream& Out) {
	Out.open("Out.txt", ios_base::out);
	if (!Out.is_open()) return;
	if (head == NULL) {
		Out << "Khong co sinh vien nao!\n";
		return;
	}
	while (head != NULL) {
		Print(head->data, Out);
		head = head->next;
	}
	Out.close();
}
#pragma endregion
#pragma region ReadFile
node MakeNode1(SV sv) {
	node p = new Node;
	p->data = sv;
	p->next = NULL;
	return p;
}
void InsertFirst1(node& head, SV sv) {
	node temp = MakeNode1(sv);
	if (head == NULL) head = temp;
	else {
		temp->next = head;
		head = temp;
	}
}
void Read(ifstream &In, node &List) {
	In.open("Out.txt", ios_base::in);
	if (!In.is_open()) return;
	char id1[10] = " ";
	char ten1[30]=" ";
	SV sv;
	while (!In.eof()) {
		In.getline(id1, 10,' ');
		In.getline(ten1, 30, '\n');
		sv.id = atoi(id1);
		if (sv.id == 0) break;
		strcpy_s(sv.ten, ten1);
		InsertFirst1(List, sv);
	}
	In.close();
}
void Print(SV sv) {
	cout << sv.id << " " << sv.ten << " ";
	cout << endl;
}
void PrintList(node head) {
	if (head == NULL) {
		cout << "Khong co sinh vien nao!\n";
		return;
	}
	while (head != NULL) {
		Print(head->data);
		head = head->next;
	}
}
#pragma endregion


void main() {
	ifstream In;
	ofstream Out;
	SV sv{};
	node head = NULL;
	node head_Read = NULL;
	InsertFirst(head,sv);
	InsertFirst(head,sv);
	PrintList(head);
}