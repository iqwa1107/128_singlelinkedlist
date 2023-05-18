#include <iostream>
using namespace std;

struct Node {
	int noMhs;
	string name;
	Node* next;
};

Node* START = NULL;

void addNode() {
	int nim;
	string nama;
	Node* nodeBaru = new Node();
	cout << "Masukan NIM: ";
	cin >> nim;
	cout << "Masukan Nama: ";
	cin >> nama;
	nodeBaru->noMhs = nim;
	nodeBaru->name = nama;

	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs)
		{
			cout << "NIM sudah ada" << endl;
			return;
		}


		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}

	Node* previous = START;
	Node* current = START;

	while ((current != NULL) && (nim >= current->noMhs))
	{
		if (nim == current->noMhs)
		{
			cout << "NIM sudah ada" << endl;
			return;
		}
		previous = current;
		current = current->next;
	}
	nodeBaru->next = current;
	previous->next = nodeBaru;
}

bool seracNode(int nim, Node* current, Node* previous) {
	previous = START;
	current = START;
	while (current != NULL && nim > current->noMhs)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
	{
		return false;
	}
	else if (current->noMhs == nim)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool deletNode(int nim) {
	Node* current = START;
	Node* previous = START;
	if (seracNode(nim, previous, current) == false)
		return false;
	previous->next = current->next;
	if (current == START)
		START = current->next;
	return true;
}
bool listEmpty() {
	if (START == NULL)
		return true;
	else
		return false;
}

void treaverse() {
	if (listEmpty()) {
		cout << "list Kosong" << endl;
		system("paus");
		system("cls");
		return;
	}
	else {

		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << "NIM: " << currentNode->noMhs << ", Nama:" << currentNode->name << endl;
			currentNode = currentNode->next;
		}

	}

}
void searchData() {
	if (listEmpty()) {
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		int nim;
		cout << "Masukan NIM: ";
		cin >> nim;
		Node* currentNode = START;
		while (currentNode != NULL) {
			if (currentNode->noMhs == nim) {
				cout << "NIM: " << currentNode->noMhs << ",Nama:" << currentNode->name << endl;
				return;
			}
			currentNode = currentNode->next;
		

		}
		cout << "Data tidak di temukan" << endl;
	}
}

int main() {
	int pilihan;
	do
	{
		try
		{
			cout << "1. Tambaha Data" << endl;
			cout << "2. Hapus data" << endl;
			cout << "3. Tampikan data" << endl;
			cout << "4. cari data " << endl;
			cout << "5. keluar" << endl;
			cout << "Pilihan" << endl;
			cin >> pilihan;
			switch (pilihan)
			{
			case 1:
				addNode();
				cout << "Data Berhasil Di tambahkan" << endl;
				system("pause");
				system("cls");
				break;

			case 2:
				if (listEmpty())
				{
					cout << "List kosong" << endl;
					system("pause");
					system("cls");
					break;
				}
				int nim;
				cout << "masukan NIM: ";
				cin >> nim;
				if (deletNode(nim)){
					cout << "nim: " << nim << " berhasil di hapus" << endl;
					system("pause");
					system("cls");
				}
				else
					cout << "data tidak ditemukan" << endl;
				break;
			case 3:
				treaverse();
				break;
			case 4:
				searchData();
				break;
			case 5:
				break
			default:
				cout << "Terjadi kesalahan" << endl;
			}
		}
		
	} 
}