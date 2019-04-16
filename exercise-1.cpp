/*
Nama	: Bandana Irmal Abdillah
NPM		: 140810180025
Tanggal	: 15 April 2019
Deskripsi: exercise phone book
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>>
using namespace std;

struct Contact {
	char name[10];
	char phone[12];
	Contact* next;
};

struct Index{
	char index[20];
	Contact* firstContact;
	Index* next;
};

typedef Index* pointerIn;
typedef Contact* pointerCon;
typedef pointerIn listIn;

void createList(listIn& first){
    first = 0;
}

void createElementIndex(pointerIn& pBaru)
{
    pBaru = new Index;
    cout << "Index : "; cin >> pBaru->index;
    pBaru->next = 0;
    pBaru->firstContact = 0;
}

void createElementCon(pointerCon& pBaru)
{
    pBaru = new Contact;
    cout << "Nama        : "; cin >> pBaru->name;
    cout << "No Telepon  : "; cin >> pBaru->phone;
    pBaru->next = 0;
}

void linearSearch(listIn first, char key[20], int& status, pointerIn& pCari){
	status = 0;
	pCari = first;
	while (status == 0 && pCari != 0) {
		if (strcmp(pCari->index,key) == 0)
			status=1;
		else
			pCari = pCari->next;
	}
}

void insertIn(listIn& first, pointerIn pBaru){
	pointerIn last;
	last = first;
	
	if(first == 0){
		first = pBaru;
	}
	else{
		if(last->next != 0){
			last = last->next;
		}
		else{
			last->next = pBaru;
		}	
	}
}

void insertCon(listIn& first, pointerCon pBaru){
	pointerIn pIndex;
	int ketemu;
	char key[20];
	cout << "Masukkan Index : "; cin >> key;
	linearSearch(first,key,ketemu,pIndex);
	if (ketemu){ 
		cout << "Telah masuk ke index "<< key << endl;
		if (pIndex->firstContact == 0){
			pIndex->firstContact = pBaru;
		}
		else {
			pBaru->next = pIndex->firstContact;
			pIndex->firstContact = pBaru;
		}
	}
	else{
		cout<<"Tidak ditemukan"<<endl;
	}
}

void traversal(listIn first){
	pointerIn pBantuIn;
	pointerCon pBantuCon;
	cout << "List Contact" << endl;
	pBantuIn = first;

	while (pBantuIn != 0){ 
		cout << "INDEX "<< pBantuIn->index << endl;
		pBantuCon = pBantuIn-> firstContact;
		while (pBantuCon != 0) { 
			cout << "\t" << pBantuCon->name << "\t/\t" << pBantuCon->phone << endl;
			pBantuCon = pBantuCon->next;
		}
		pBantuIn=pBantuIn->next;
		cout<<endl;
	}
}

void deleteCon(listIn& first, pointerCon& pHapus){
	pointerIn pIndex;
	int ketemu;
	char key[20];
	cout<<"Masukkan Index : "; cin >> key;
	linearSearch(first,key,ketemu,pIndex);
	if (ketemu) {
		if (pIndex->firstContact == 0){ 
			pHapus = 0;
			cout << "List kosong, tidak ada hapus" << endl;
		}
		else if (pIndex->firstContact->next == 0){
			pHapus = pIndex->firstContact;
			pIndex->firstContact = 0;
		}
		else { 
			pHapus = pIndex->firstContact;
			pIndex->firstContact = pIndex->firstContact->next;
			pHapus->next = 0;
		}
	}else{
		cout << "Tidak ditemukan" << endl;
	}
}

void updateKontak(listIn first, pointerIn& pIndex){
	char key[10];
	int status = 0;

	pointerCon pK,pb;
	pIndex = first;
	pK = pIndex->firstContact;
	cout<<"Masukan nama kontak :"; cin>>key;
	while(pIndex != 0){
		while(status == 0 && pK != 0){
			if(strcmp(pK->name,key) == 0){
				cout << "Masukan Nama :"; cin >> pK->name;
				cout << "Masukan Nomor :"; cin >> pK->phone;
			status = 1;
			}
			else {
				pK = pK->next;
			}
		}

		pIndex = pIndex->next;
	}
}

int main(){
	listIn list;
	pointerIn baruindex,hapusindex;
	pointerCon barucon,hapuscon;
	int nIndex, nContact;
	
	createList(list);
	cout<< "Banyak Index : "; cin >> nIndex;
	for(int i=0; i<nIndex; i++){
		createElementIndex(baruindex);
		insertIn(list,baruindex);
	}
	cout <<"Banyak Contact : "; cin>>nContact;
	for(int i=0;i<nContact;i++){
		createElementCon(barucon);
		insertCon(list,barucon);
	}
	system("cls");
	traversal(list);
	cout<<endl<<"Delete Kontak"<<endl;
	deleteCon(list,hapuscon);
	system("cls");
	traversal(list);
	cout<<endl<<"Update Kontak"<<endl;
	updateKontak(list,baruindex);
	system("cls");
	traversal(list);

}
