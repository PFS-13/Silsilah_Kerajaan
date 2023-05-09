/* File        : body.c 												*/  
/* Deskripsi   : Body prototype ADT Non Binary Tree Silsilah Kerajaan	*/ 
/* Dibuat oleh : Asri Husnul Rosadi			221524035
				 Mochamad Fathur Rabbani	221524045
				 Naia Siti Az-zahra			221524052 					*/
/* Tanggal     : 13-04-2023 											*/ 

#include "silan.h"
#include "boolean.h"
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>


bool isEmpty(Node *node)
/* Mengecek apakah suatu tree kosong atau tidak */
{
	return node == NULL;
}

bool isRoot(Root X, Node node)
/* Mengecek apakah suatu node tersebut adalah root atau bukan */
{
	return X.root == node;
}

void insertNode(infotype nama, bool jenisKelamin, Node parent)
/* Membuat node dan memasukkan value kedalam node tersebut lalu mengembalikan node tersebut */
{
	Node newNode = (Tnode*)malloc(sizeof(Tnode));
	if (newNode == NULL) {
		printf("Error, alokasi memori gagal!");
		exit(1);
	}
    newNode->nama = nama;
    newNode->jenisKelamin = jenisKelamin;
    newNode->mate = NULL;
	newNode->parent = parent->nama;
    newNode->nodeFS = NULL;
    newNode->nodeNB = NULL;
    newNode->nodePR = parent;
    if (parent->nodeFS != NULL) {
    	Node temp;
    	temp = parent->nodeFS;
    	while(temp->nodeNB != NULL) {
    		temp = temp->nodeNB;
		}
		temp->nodeNB = newNode;
	} else {
		parent->nodeFS = newNode;
	}
}

Node searchNode(Root X,infotype nama)
/* Mencari suatu Node berdasarkan subvar nama lalu akan mengembalikan node tersebut jika ketemu */
{
	Node Pcur;
	bool Resmi;
	int index;
	
	index = 1;
	Resmi = true;
	Pcur = X.root;
	if (strcmp(nama,Pcur->nama) == 0)
	{ return Pcur;}

	infotype gender;
		while (Pcur != NULL) {
		if (Pcur->nodeFS != 0 && Resmi) {
			Pcur = Pcur->nodeFS;
				if (strcmp(nama,Pcur->nama) == 0)
				{ return Pcur;}
			
		} else if (Pcur->nodeNB != NULL) {
			Pcur = Pcur->nodeNB;

				if (strcmp(nama,Pcur->nama) == 0)
				{ return Pcur;}
			
			Resmi = true;
		} else {
			Pcur = Pcur->nodePR;
			Resmi = false;
		}
	}
	 
}
void deleteNode(Root X, infotype nama){
  Node nDel;
  bool del = true;
  nDel = searchNode(X,nama);
  if (nDel == NULL){
    	 printf("Nama nya tidak ditemukan");
		 del = false;
    } else if(isRoot(X,nDel)){
		printf("Raja telah dibunuh ....\n");
		Node nextKing = nDel->nodeFS;
		X.root = nextKing;
		printf("Kini raja baru telah diangkat, yakni %s\n", nextKing->nama);
		system("pause");
		nextKing->nodePR = NULL;
		if (nextKing->nodeFS != NULL)
		{
			printf("yatta");
			Node Current = nDel;
			Node brother = Current->nodeNB;
			Node myBro;
			Current = Current->nodeFS;
			while (Current != NULL)
			{
					if(Current->nodeNB != NULL){
						myBro = Current->nodeNB;
					} else {
						myBro = NULL;
					}

					Current->nodeNB = brother;
					brother = myBro;
					if (Current->nodeFS == NULL)
					{
						if (Current->nodeNB != NULL)
						{
							Current->nodeNB->nodePR = Current;
						}
					}
					Current = Current->nodeFS;
			}
			printf("HIDUP RAJA BARU !!!!!\n");
			system("pause");

		} else if (nextKing->nodeNB != NULL){
			nextKing->nodeNB->nodePR = nextKing;
		} 
		
	}
	
	// Jika yang mati adalah anak pertama dari suatu node
	else if(nDel->nodePR->nodeFS == nDel){ 
		if(nDel->nodeFS != NULL){ 				   // Jika nDel memiliki anak 
			 // fs merupakan anak pertama nDel
			nDel->nodeFS->nodePR = nDel->nodePR; // Orang tua dari fs diganti menjadi orang tua nDel
			nDel->nodePR->nodeFS = nDel->nodeFS; // Anak pertama dari Orang tua nDel menjadi fs
		
			Node Current = nDel;
			Node brother = Current->nodeNB;
			Node myBro = Current->nodeNB;
			Current = Current->nodeFS;
			while (Current != NULL)
			{
					if(Current->nodeNB != NULL){
						myBro = Current->nodeNB;
					} else {
						myBro = NULL;
					}

					Current->nodeNB = brother;
					brother = myBro;
					if (Current->nodeFS == NULL)
					{
						if (Current->nodeNB != NULL)
						{
							Current->nodeNB->nodePR = Current;
						}
					}
					Current = Current->nodeFS;
			}
			
	} else {
		if(nDel->nodeNB != NULL){
			nDel->nodeNB->nodePR = nDel->nodePR;
		}
	}

	} // JIKA YANG MATI BUKAN ANAK PERTAMA 
	else if(nDel->nodePR->nodeFS != nDel){
		Node bDelete = nDel->nodePR->nodeFS;
		while (bDelete->nodeNB != nDel)
		{
			bDelete = bDelete->nodeNB;
		}
		if (nDel->nodeFS != NULL ) // jika nDel memiliki anak
		{
			bDelete->nodeNB = nDel->nodeFS;
			Node Current = nDel;
			Node brother = Current->nodeNB;
			Node myBro = Current->nodeNB;
			Current = Current->nodeFS;
			while (Current != NULL)
			{
					if(Current->nodeNB != NULL){
						myBro = Current->nodeNB;
					} else {
						myBro = NULL;
					}

					Current->nodeNB = brother;
					brother = myBro;
					if (Current->nodeFS == NULL)
					{
						if (Current->nodeNB != NULL)
						{
							Current->nodeNB->nodePR = Current;
						}
					}
					Current = Current->nodeFS;
			}

		} else if (nDel->nodeFS == NULL){
			bDelete->nodeNB = nDel->nodeNB;
		}
	}
	if (del)
	{
		nDel->nodeFS = NULL;
	nDel->nodeNB = NULL;
	nDel->nodePR = NULL;
	free(nDel);
	}
	
	
}
	/*
	ROOT
	else if (isRoot(X,nDel)){ // Jika raja mati
    	  Node temp; // Anak Pertama Raja (Pangeran)
          temp = X.root->nodeFS;
	   		 if (temp->nodeFS == NULL) {
				 if(temp->nodeNB != NULL){
					temp->nodeNB->nodePR = temp;// Jika Pangeran tidak mempunyai anak, saudara ke dua menjadi FS
				 } 
			}
	    	if(temp->nodeFS->nodeNB != NULL){
				temp->nodeFS->nodeNB->nodePR = temp->nodeFS; // Anak dari Pangeran, menjadi orang tua bagi saudaranya
			} 
	    temp->nodeFS->nodeNB = temp->nodeNB;// Anak pertama dari Pangeran, menjadi saudara dari pangeran lainnya
	    temp->nodeNB->nodePR = temp; // Anak pertama raja menjadi orang tua bagi saudaranya
	    temp->nodePR = NULL; // orang tua anak pertama dihilangkan
	    X.root = temp; // anak pertama menjadi raja
	*/


void garisSuksesi(Root X)
/* Menampilkan urutan garis suksesi silsilah secara preOrder */
/* I.S : Node sudah ada */
/* F.S : Node sudah terurut secara preOrder */
{
	Node Pcur;
	bool Resmi;
	int index;
	
	index = 1;
	Resmi = true;
	Pcur = X.root;
	infotype gender;
	if(Pcur->nodeFS != NULL) {
	printf("=============\nGARIS SUKSESI\n=============\n");
	while (Pcur != NULL) {
		if (Pcur->nodeFS != 0 && Resmi) {
			Pcur = Pcur->nodeFS;
			if (!isRoot(X,Pcur))
			{
				if (Pcur->jenisKelamin == true)
				{
					gender = "Son";
				} else {
					gender = "Daughter";
				}
				
				printf("%d. %s %s of %s \n", index,Pcur->nama, gender, Pcur->parent);
				index++;
				
			}
		} else if (Pcur->nodeNB != NULL) {
			Pcur = Pcur->nodeNB;
			if (!isRoot(X,Pcur))
			{
				if (Pcur->jenisKelamin == true)
				{
					gender = "Son";
				} else {
					gender = "Daughter";
				}
				
				printf("%d. %s %s of %s \n", index,Pcur->nama, gender, Pcur->parent);
				index++;
				
			}
			Resmi = true;
		} else {
			Pcur = Pcur->nodePR;
			Resmi = false;
		}
	}
	} else {
		printf("RAJA BELUM MEMPUNYAI PENERUS");
	}
}

void displayFamily(Root X)
/* Menampilkan silsilah kerajaan secara levelOrder */
/* I.S : Silsilah kerajaan belum tampil */
/* F.S : Silsilah kerajaan sudah tampil */
{
	
}

int countChild(Node node)
/* Menghitung jumlah anak dari suatu node */
{
	int jml = 0;
    if(node->nodeFS != NULL) { // jika ada anak pertama
        Node child;
        child = node->nodeFS;
        while(child != NULL) { // cek apakah ada saudara sebelah kanan dari anak pertama
            jml++; // jika ada, tambahkan 1 pada jumlah anak
            child = child->nodeNB; // lanjut ke saudara sebelah kanan selanjutnya
        }
    }
    return jml; // kembalikan jumlah anak
}

bool isSingle(Node Person)
/* Mengecek apakah value subvar mate dari node tersebut terisi atau null */
{
	return Person->mate == NULL;
}

void setMate(Node Person, infotype mate)
/* Mengisi value subvar mate dari suatu node */
/* I.S : Subvar mate pada node masih null */
/* F.S : Subvar mate pada node sudah terisi value */
{
	if (!isSingle(Person)) {
        printf("Orang ini sudah memiliki pasangan.\n");
    } else {
        Person->mate = mate;
    }
}

void displayRules()
/* Menampilkan aturan pada kerajaan Inggris */
/* I.S : Aturan kerajaan Inggris belum tampil di layar */
/* F.S : Aturan kerajaan Inggris sudah tampil di layar */
{
	system("cls");
	FILE *fp;
	char Text[999];
	
	fp = fopen("Assets//AturanKerajaan.txt", "rt");
	
	if (fp == NULL) {
		printf("File tidak ditemukan\r\t");
		exit(1);
	}
	
	while ((fgets(Text, 1000, fp)) != NULL) {
		printf("%s\r", Text);
	}
	
	fclose(fp);
	Sleep(500);
	printf("\n\t");
	system("pause");
	system("cls");
}

void displayDetailNode(Root X,Node node)
/* Menampilkan pasangan, dan jumlah anak */
/* I.S : Detail suatu node belum tampil di layar */
/* F.S : Detail suatu node sudah tampil di layar */
{
		printf("\n\t=============================== MEMILIH PASANGAN ===============================\n\n");
		
		if (isRoot(X,node))
		{
			printf("\tNama Bangsawan\t: %s\n", node->nama);
			
		} else {
			printf("\tNama Bangsawan\t: %s\n", node->nama);
			printf("\tNama Orang Tua\t: %s\n", node->parent);
		}
		if (isSingle(node))
		{
			printf("\tStatus \t: Belum Menikah\n", node->nama);
		} else {
			printf("\tStatus \t: Sudah Menikah\n");
			printf("\tPasangan \t: %s\n", node->mate);
			int sumChildren = countChild(node);
			printf("\tJumlah Anak\t: %d\n", sumChildren);
			printf("\n\t");
		}
		system("pause");
		
		
		
	
		
//	}
}

void displayDetailKingdom(Root X)
/* Menampilkan pilihan ingin melihat aturan atau silsilah kerajaan sebelumnya */
/* I.S : Aturan atau silsilah kerajaan belum tampil di layar */
/* F.S : Aturan atau silsilah kerajaan sudah tampil di layar */
{
	int pilih;
	for(;;) {
		system("cls");
		printf("\n\t============= DETAIL KERAJAAN =============\n");
		printf("\tNama Kerajaan\t: Kingdom of England\n");	
		printf("\tNama Raja/Ratu\t:%s \n\n", X.root->nama);
		printf("\t=============== DETAIL LAIN ===============\n");
		printf("\t[1] Tampil Aturan Kerajaan\n");
		printf("\t[2] Tampil Garis Suksesi\n");
		printf("\t[3] Tampil Silsilah Kerajaan Saat Ini\n");
		printf("\t[4] Tampil Silsilah Kerajaan Sebelumnya\n");
		printf("\t[5] Keluar\n\n");
		printf("\tMasukkan pilihan : ");
		scanf("%d", &pilih);
					
		switch(pilih) {
			case 1:
				displayRules();
				break;
			case 2:
				garisSuksesi(X);
				system("pause");
				break;
			case 3:
				displayFamily(X);
				break;
			case 5:
				return;
			default:
				printf("\n\tPilihanmu salah, pilih lagi!\n\t");
				system("pause");
				break;
		}
	}
}

void displayMenuExit()
/* Menampilkan tampilan menu keluar */
/* I.S : Menu tampil di layar */
/* F.S : Keluar dari program */
{
    system("cls");
    int pil;
    printf("\n\t===== EXIT =====\n\n");
    printf("\tYakin mau keluar?\n\n");
    printf("\t[1] Kembali\n");
    printf("\t[Ketik Apapun] Yakin\n\n");
    printf("\tMasukkan pilihan : ");
    scanf("%d", &pil);

    switch(pil) {
        case 1: 
        	system("cls");
            return;
        default:
            exit(1);
    }
}

void displayKingdom()
/* Menampilkan desain kerajaan */
/* I.S : Desain kerajaan belum tampil di layar */
/* F.S : Desain kerajaan sudah tampil di layar */
{
	FILE *fp;
	char Text[999];
	
	fp = fopen("Assets//Kingdom.txt", "rt");
	
	if (fp == NULL) {
		printf("File tidak ditemukan\r\t");
		exit(1);
	}
	
	while ((fgets(Text, 1000, fp)) != NULL) {
		printf("%s\r", Text);
	}
	
	fclose(fp);
	Sleep(500);
	printf("\n\n\t");
	system("pause");
	system("cls");
}
