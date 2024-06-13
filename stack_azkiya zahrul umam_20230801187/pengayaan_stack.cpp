/*Azkiya Zahrul Umam
	20230801187
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;
stack<string> undostack;//objek yang disimpan string
stack<string> redostack;//onjeknya itu tuh redostack/udnstck
string simpenanteks = "";

bool emptyundo(){//karna ini sifatnya ngecek jadi pake bool
	return undostack.empty();
}

bool emptyredo(){
	return redostack.empty();
}

void print(){
	cout<<"teks tersimpan :"<<simpenanteks<<endl;//ini maksud dari yang di atas
}

void ketik(string kata)//parameter
{
	undostack.push(simpenanteks);// Simpan status teks saat ini sebelum perubahan ke stack undo
	simpenanteks += kata;// Tambahkan teks baru ke teks saat ini
	redostack = stack<string>();//reset redo stack
}

void undo(){
	if(!undostack.empty()){
		redostack.push(simpenanteks);// Simpan status teks saat ini ke stack redo
		simpenanteks = undostack.top();// Ambil status teks sebelumnya dari stack undo
		undostack.pop();// Hapus status teks yang telah di-undo dari stack undo

	}
}

void redo(){
	if (!redostack.empty()){
		undostack.push(simpenanteks);// Simpan status teks saat ini ke stack undo
		simpenanteks = redostack.top();// Ambil status teks yang telah di-undo dari stack redo
		redostack.pop();// Hapus status teks yang telah di-redo dari stack redo
	}
}


int main(){
	int pilih;
	string kata;
	while(true){
	
	cout<<"1. tambah Kata"<<endl;
	cout<<"2. undo"<<endl;
	cout<<"3. redo"<<endl;
	cout<<"4. isEmpty undo"<<endl;
	cout<<"5. isEmpty redo"<<endl;
	cout<<"pilih menu: ";
	cin>>pilih;
	
	if (pilih == 1){
		cout<<"Masukan Kata :";
		cin>>kata;
		ketik(kata);
		print();
	}
	else if (pilih == 2){
		undo();
		print();
	}
	else if(pilih == 3){
		redo();
		print();
	}
	else if(pilih == 4){
		cout<<"isEmpty undo? "<<(emptyundo()?" Yes" : "No")<<endl;
		
	}
	else if(pilih == 5){
		cout<<"isEmpty redo? "<<(emptyredo()? "Yes" : "No")<<endl;
		
	}
}
	
	return 0;
}
