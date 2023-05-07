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
    newNode->nodeFS = NULL;
    newNode->nodePR = NULL;
    newNode->nodeNB = parent;
    
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
	bool Resmi = true;
	Pcur = X.root;
	if (strcmp(Pcur->nama,nama) == 0){
		return Pcur;
	}
	while(Pcur != NULL){
		if (Pcur->nodeFS != NULL && Resmi){
			if (strcmp(Pcur->nama, nama) == 0) {
				return Pcur;
			}
			Pcur = Pcur->nodeFS;
		} else if (Pcur->nodeNB != NULL) {
			Pcur = Pcur->nodeNB;
			if (strcmp(Pcur->nama, nama) == 0) {
				return Pcur;
			}
			Resmi = true;
		}
			else {
				Pcur = Pcur->nodePR;
				Resmi = false;
			}
		}
	return Pcur;
	}


void deleteNode(Root X, infotype nama){


  Node nSearch;
  Node nParent;
  Node nChild;
  nSearch = searchNode(X,nama);
  nParent = nSearch->nodePR;
  nChild = nSearch->nodeFS;
  if (nSearch == NULL){
    	 printf("Nama nya tidak ditemukan");
    }
	 else if (isRoot(X,nSearch)){
    	  Node temp;
          temp = X.root->nodeFS;
	   		 if (temp->nodeFS == NULL) {
				temp->nodeNB->nodePR = temp;
			}
	    temp->nodeFS->nodeNB->nodePR = temp->nodeFS;
	    temp->nodeFS->nodeNB = temp->nodeNB;
	    temp->nodeNB->nodePR = temp;
	    temp->nodePR = NULL;
	    X.root = temp;
		} else {	
		Node temp;
		Node tempPR;
		Node tempFS;
		Node tempNB;
	    if (nSearch == nParent->nodeFS){
			temp = nSearch;
       		tempPR = temp->nodePR;
             tempFS = temp->nodeFS;
             tempNB = temp->nodeNB;
			tempPR->nodeFS = tempFS;
		 
		 
while (temp->nodeFS != NULL) {
            temp->nodeFS->nodeNB = temp->nodeNB;
			  temp = temp->nodeFS;
}

}else {
			temp = nParent->nodeFS ;
			while (temp->nodeNB != nSearch){ 
            temp = temp->nodeNB;
		  }
 	            
	if (nSearch->nodeFS == NULL){
		temp->nodeNB = temp->nodeNB->nodeNB;
	}else {
		nSearch->nodeFS->nodeNB = nSearch->nodeNB;
		temp->nodeNB = nSearch->nodeFS;
		temp = nSearch->nodeFS;
 	         while (temp != NULL){
                    temp->nodeFS->nodeNB = temp->nodeNB;
			  		temp = temp->nodeFS;
			} 
	}
}
		}
free(nSearch);
	}



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
	
	while (Pcur != NULL) {
		if (Pcur->nodeFS != 0 && Resmi) {
			Pcur = Pcur->nodeFS;
			if (!isRoot(X,Pcur))
			{
				printf("%d. &s", index, Pcur->nama);
				index++;
			}
		} else if (Pcur->nodeNB != NULL) {
			Pcur = Pcur->nodeNB;
			if (!isRoot(X,Pcur))
			{
				printf("%d. &s", index, Pcur->nama);
				index++;
			}
			Resmi = true;
		} else {
			Pcur = Pcur->nodePR;
			Resmi = false;
		}
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

void displayDetailNode()
/* Menampilkan level, pasangan, dan jumlah anak */
/* I.S : Detail suatu node belum tampil di layar */
/* F.S : Detail suatu node sudah tampil di layar */
{
	
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
