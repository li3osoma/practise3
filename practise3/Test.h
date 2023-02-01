#ifndef _TEST_H
#define _TEST_H

#include "BinaryFileManage.h"
#include "HashTableManage.h"
#include "BinaryFileAndHashTableManage.h"
#include <ctime>

//вставка без коллизии
void test1(HashTable* HTable) {
	string binfile;

	cout << "Insertion without collison" << endl;
	cout << "Binary file name (without .txt): ";
	cin >> binfile;

	cout <<endl<< "Hash-table containing before insertion: " << endl;
	HTable->tableContaining();

	for (int i = 0;i < 3;i++) {
		recordFromBinaryToTable(binfile + ".txt", i, HTable);
	}

	cout <<endl<< "Hash-table containing after insertion: " << endl;
	HTable->tableContaining();

	cout << "Insertion without collision is finished" << endl << endl;
}

//вставка с коллизиями
void test2(HashTable* HTable) {
	string binfile;

	cout << "Insertion with collison" << endl;
	cout << "Binary file name (without .txt): ";
	cin >> binfile;

	cout <<endl<<"Hash-table containing before insertion: " << endl;
	HTable->tableContaining();

	for (int i = 3;i < 5;i++) {
		recordFromBinaryToTable(binfile + ".txt", i, HTable);
	}

	cout <<endl<< "Hash-table containing after insertion: " << endl;
	HTable->tableContaining();

	cout << "Insertion with collision is finished" << endl << endl;
}

//вставка с рехешированрием
void test3(HashTable* HTable) {
	string binfile;

	cout << "Insertion with rehash" << endl;
	cout << "Binary file name (without .txt): ";
	cin >> binfile;

	cout << endl << "Hash-table containing before insertion: " << endl;
	HTable->tableContaining();

	for (int i = 6;i < 11;i++) {
		recordFromBinaryToTable(binfile + ".txt", i, HTable);
	}

	cout << endl << "Hash-table containing after insertion: " << endl;
	HTable->tableContaining();

	cout << "Insertion with rehash is finished" << endl << endl;
}

//удаление ключа из таблицы
void test4(HashTable* HTable, int key) {
	string binfile;

	cout << "Deleting key from the table" << endl;
	cout << "Binary file name (without .txt): ";
	cin >> binfile;
	cout << "Key for deleting: " << key << endl;
	cout << endl << "Hash-table containing before deleting: " << endl;
	HTable->tableContaining();

	int res = deleteFromTableAndFromFile(binfile + ".txt", HTable, key);
	if (res == 1) cout << endl << "Can't find the file" << endl << endl;
	else if (res == 2) cout << endl << "Can't find a node with such key" << endl;
	else {
		cout << endl << "Hash-table containing after deleting: " << endl;
		HTable->tableContaining();
	}
	cout << endl << "Deleting is complete" << endl << endl;
}

//поиск ключа в таблице
void test5(HashTable* HTable, int key) {
	film* F=new film();
	string binfile;

	cout << "Searching key in the table" << endl;
	cout << "Binary file name (without .txt): ";
	cin >> binfile;
	cout << "Key for searching: " << key << endl;
	int res = getFromBinByKey(binfile + ".txt", key, HTable, F);
	if (res == 1) cout << endl << "Can't find the file" << endl << endl;
	else if (res == 2) cout << endl << "Can't find a film with such key" << endl;
	else {
		cout << endl<<"Found film: " << endl << F->id << endl << F->theatre 
			<< endl << F->title << endl << F->freeplaces << endl;
	}
	cout << endl << "Searching is finished" << endl << endl;

}

void test6(HashTable* HTable) {
	film* F = new film();
	string binfile;
	int key;
	double time1,time2,time3;

	cout << "Time of searching the key in the table" << endl;
	cout << "Binary file name (without .txt): ";
	cin >> binfile;
	HTable->tableContaining();
	key = 1;
	cout << "Key for searching: " << key << endl;

	time1 = clock();
	getFromBinByKey(binfile + ".txt", key, HTable, F);
	time1 = clock() - time1;
	cout << "Time of searching the key in the begin of the table: " << time1 << endl;

	key = 9;
	cout << "Key for searching: " << key << endl;

	time2 = clock();
	getFromBinByKey(binfile + ".txt", key, HTable, F);
	time2 = clock() - time2;
	cout << "Time of searching the key in the middle of the table: " << time2 << endl;

	key = 44;
	cout << "Key for searching: " << key << endl;

	time3 = clock();
	getFromBinByKey(binfile + ".txt", key, HTable, F);
	time3 = clock() - time3;
	cout << "Time of searching the key in the end of the table: " << time3 << endl;
}

void testAll() {
	HashTable* HTable = new HashTable(6);
	test1(HTable);
	test2(HTable);
	test3(HTable);

	test4(HTable,10); //ключ существует и не удален
	test4(HTable,10); //ключ был удален из таблицы
	test4(HTable,12); //ключа не существует

	test5(HTable,44); //ключ существует и не удален
	test5(HTable,10); //ключ был удален из таблицы
	test5(HTable,12); //ключа не существует

	test6(HTable);//время поиска ключа в начале, середине и конце таблицы
}


#endif
