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
	newNode->age = 0;
	newNode->mateAge = NULL;
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
void deleteNode(Root * X, infotype nama){
  Node nDel;
  bool del = true;
  nDel = searchNode(*X,nama);
  if (nDel == NULL){
    	 printf("\n\tNama bangsawan tidak ditemukan\n\t", nama);
		 system("pause");
		 del = false;
    } else if(isRoot(*X,nDel)){ // JIKA RAJA WAFAT
		if (nDel->jenisKelamin)
		{
			printf("\tRaja telah wafat ...\n");
		} else{
			printf("\tRatu telah wafat ...\n");	
		}
		
		
		Node nextKing = nDel->nodeFS;
		(*X).root = nextKing;
		if(nextKing == NULL){
		printf("\tTIDAK ADA PENERUS KERAJAAN, BUTUH PEMIMPIN BARU\n\n\t");
		} else {
			printf("\tKini pemimpin baru telah diangkat, yakni %s\n", (*X).root->nama);
			printf("\tTHE ERA OF %s HAS BEGUN !!!!!\n\n\t",(*X).root->nama);
		
		nextKing->nodePR = NULL;
		if (nextKing->nodeFS != NULL) 
		{
			Node Current = nDel;
			Node brother = Current->nodeNB;
			Node myBro;
			Current = Current->nodeFS;
			bool loop = true;
			while (Current != NULL && loop)
			{
					if(Current->nodeNB != NULL){
						myBro = Current->nodeNB;
					} else {
						myBro = NULL;
					}
					

					if (Current->nodeFS == NULL)
					{
						if (Current->nodeNB != NULL)
						{
							Current->nodeFS = Current->nodeNB;
							Node bro =  Current->nodeNB;
							while (bro != NULL)
							{
								bro->nodePR = Current;
								bro = bro->nodeNB;
							}
							loop = false;
						}
					}
						
						Current->nodeNB = brother;
						Node bro =  Current->nodeNB;
						while (bro != NULL)
						{
							bro->nodePR = Current->nodePR;
							bro = bro->nodeNB;
						}
						
						brother = myBro;
					
					Current = Current->nodeFS;
			}
			

		} else if (nextKing->nodeNB != NULL){
						nextKing->nodeFS = nextKing->nodeNB;
						nextKing->nodeNB->nodePR = nextKing; 
						Node bro =  nextKing->nodeNB;
						while (bro != NULL)
						{
							bro->nodePR = nextKing;
							bro = bro->nodeNB;
						}
						nextKing->nodeNB = NULL;
			
		} 
	}
	}
	
	// JIKA YANG MATI ADALAH ANAK PERTAMA
	else if(nDel->nodePR->nodeFS == nDel){ 
		printf("\n\n\tBangsawan %s Telah Meninggal.\n\n\t", nDel->nama );
		if(nDel->nodeFS != NULL){ 				   // Jika nDel memiliki anak 
			 // fs merupakan anak pertama nDel
			nDel->nodeFS->nodePR = nDel->nodePR; // Orang tua dari fs diganti menjadi orang tua nDel
			nDel->nodePR->nodeFS = nDel->nodeFS; // Anak pertama dari Orang tua nDel menjadi fs
		
			Node Current = nDel;
			Node brother = Current->nodeNB;
			Node myBro = Current->nodeNB;
			Current = Current->nodeFS;
			bool loop = true;
			while (Current != NULL && loop)
			{
					if(Current->nodeNB != NULL){
						myBro = Current->nodeNB;
					} else {
						myBro = NULL;
					}
					

					if (Current->nodeFS == NULL)
					{
						if (Current->nodeNB != NULL)
						{
							Current->nodeFS = Current->nodeNB;
							Node bro =  Current->nodeNB;
							while (bro != NULL)
							{
								bro->nodePR = Current;
								bro = bro->nodeNB;
							}
							loop = false;
						}
					}
						
						Current->nodeNB = brother;
						Node bro =  Current->nodeNB;
						while (bro != NULL)
						{
							bro->nodePR = Current->nodePR;
							bro = bro->nodeNB;
						}
						
						brother = myBro;
					
					Current = Current->nodeFS;
			}
			
	} else {
		if(nDel->nodeNB != NULL){
			nDel->nodePR->nodeFS = nDel->nodeNB;
		} else {
			nDel->nodePR->nodeFS = NULL;
		}
	}

	} // JIKA YANG MATI BUKAN ANAK PERTAMA 
	else if(nDel->nodePR->nodeFS != nDel){
		printf("\n\n\tBangsawan %s Telah Meninggal.\n\n\t", nDel->nama );
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
			Node myBro;
			Current = Current->nodeFS;
		bool loop = true;
			while (Current != NULL && loop)
			{
					if(Current->nodeNB != NULL){
						myBro = Current->nodeNB;
					} else {
						myBro = NULL;
					}
					

					if (Current->nodeFS == NULL)
					{
						if (Current->nodeNB != NULL)
						{
							Current->nodeFS = Current->nodeNB;
							Node bro =  Current->nodeNB;
							while (bro != NULL)
							{
								bro->nodePR = Current;
								bro = bro->nodeNB;
							}
							loop = false;
						}
					}
						
						Current->nodeNB = brother;
						Node bro =  Current->nodeNB;
						while (bro != NULL)
						{
							bro->nodePR = Current->nodePR;
							bro = bro->nodeNB;
						}
						
						brother = myBro;
					
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
	if(Pcur->nodeFS != NULL) {
		printf("\n\t============= GARIS SUKSESI =============\n");
		while (Pcur != NULL) {
			if (Pcur->nodeFS != 0 && Resmi) {
				Pcur = Pcur->nodeFS;
				if (!isRoot(X,Pcur))
				{
					printf("\t%d. %s\n", index, Pcur->nama);
					index++;
				}
			} else if (Pcur->nodeNB != NULL) {
				Pcur = Pcur->nodeNB;
				if (!isRoot(X,Pcur))
				{
					printf("\t%d. %s\n", index, Pcur->nama);
					index++;
				}
				Resmi = true;
			} else {
				Pcur = Pcur->nodePR;
				Resmi = false;
			}
		}
	} else {
		printf("\tRAJA BELUM MEMPUNYAI PENERUS\n\t");
	}
}

void displayFamily(Node X, int Level)
/* Menampilkan silsilah kerajaan saat ini (secara keseluruhan yang masih hidup) */
/* I.S : Silsilah kerajaan belum tampil */
/* F.S : Silsilah kerajaan sudah tampil */
{
	if (X != NULL)
    {
    	printf("\t");
        if (X->nama != NULL && strcmp(X->nama, "") != 0)
        {
            int i;
            for (i = 1; i <= Level; i++)
            {
                if (i < Level)
                {
                    printf("\t|  ");
                }
                else
                {
                    printf("\t|--");
                }
            }
            printf("%s\n", X->nama);
        }
        displayFamily(X->nodeFS, Level + 1);
        displayFamily(X->nodeNB, Level);
    }
}

int countChild(Root X ,Node node)
/* Menghitung jumlah anak dari suatu node */
{
	Node Pcur;
	bool Resmi;
	int index;
	
	index = 0;
	Resmi = true;
	Pcur = X.root;
	if(Pcur->nodeFS != NULL) {
		while (Pcur != NULL) {
			if (Pcur->nodeFS != 0 && Resmi) {
				Pcur = Pcur->nodeFS;
				if (!isRoot(X,Pcur))
				{
					if (strcmp(node->nama,Pcur->parent) == 0)
					{ 
						index++;
					}
					
				}
			} else if (Pcur->nodeNB != NULL) {
				Pcur = Pcur->nodeNB;
				if (!isRoot(X,Pcur))
				{
					if (strcmp(node->nama,Pcur->parent) == 0)
					{ index++;}
				}
				Resmi = true;
			} else {
				Pcur = Pcur->nodePR;
				Resmi = false;
			}
		}
	} return index;
}

bool isSingle(Node Person)
/* Mengecek apakah value subvar mate dari node tersebut terisi atau null */
{
	return Person->mate == NULL;
}

void setMate(Node Person, infotype mate, int umur)
/* Mengisi value subvar mate dari suatu node */
/* I.S : Subvar mate pada node masih null */
/* F.S : Subvar mate pada node sudah terisi value */
{
	if (!isSingle(Person)) {
        printf("Orang ini sudah memiliki pasangan.\n");
    } else {
        Person->mate = mate;
		Person->mateAge = umur;
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


void displayDetailKingdom(int tahun,Root X)
/* Menampilkan pilihan ingin melihat aturan atau silsilah kerajaan sebelumnya */
/* I.S : Aturan atau silsilah kerajaan belum tampil di layar */
/* F.S : Aturan atau silsilah kerajaan sudah tampil di layar */
{
	char pilih[10];
	for(;;) {
		system("cls");
		printf("\n\t============= DETAIL KERAJAAN =============\n");
		printf("\tTahun\t\t: %d\n",tahun);
		printf("\tNama Kerajaan\t: Kingdom of England\n");	
		printf("\tNama Raja/Ratu\t: %s \n\n", X.root->nama);
		printf("\t=============== DETAIL LAIN ===============\n");
		printf("\t[1] Tampil Aturan Kerajaan\n");
		printf("\t[2] Tampil Garis Suksesi\n");
		printf("\t[3] Tampil Silsilah Kerajaan Saat Ini\n");
		printf("\t[0] Keluar\n\n");
		printf("\tMasukkan pilihan : ");
		gets(pilih);
		char choice = pilih[0];
		switch(choice) {
			case '1':
				displayRules();
				break;
			case '2':
				garisSuksesi(X);
				system("pause");
				break;
			case '3':
				system("cls");
        		printf("\n\t============= SILSILAH KERAJAAN =============\n\n");
                displayFamily(X.root, 0);
                printf("\n\n\t");
                system("pause");
				break;
			case '0':
				return;
			default:
				printf("\n\tPilihanmu salah, pilih lagi!\n\t");
				system("pause");
				break;
		}
	}
}

void displayDetailNode(Root X,Node node)
/* Menampilkan pasangan, dan jumlah anak */
/* I.S : Detail suatu node belum tampil di layar */
/* F.S : Detail suatu node sudah tampil di layar */
{
		printf("\n\t=============================== DETAIL BANGSAWAN ===============================\n\n");
		
		if (isRoot(X,node))
		{
			printf("\tNama Bangsawan\t: %s\n", node->nama);
			printf("\tUsia\t\t: %d\n",node->age);
			
		} else {
			infotype gender;
			printf("\tUsia\t\t: %d\n",node->age);
			if(node->jenisKelamin == true){
				gender = "son";
			}else {
				gender = "daughter";
			}
			printf("\tNama Bangsawan\t: %s %s of %s \n", node->nama,gender,node->parent);
			printf("\tPewaris Tahta \t: ke-%d\n", detailPenerus(X, node->nama));
		}
		if (isSingle(node))
		{
			printf("\tStatus \t\t: Belum Menikah\n", node->nama);
		} else {
			printf("\tStatus \t\t: Sudah Menikah\n");
			printf("\tPasangan \t: %s\n", node->mate);
			printf("\tUsia Pasangan \t: %d\n", node->mateAge);
			int sumChildren = countChild(X,node);
			printf("\tJumlah Anak\t: %d\n", sumChildren);
			printf("\n");
		}
		system("pause");
//	}
}

int detailPenerus(Root X, infotype nama)
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
	if(Pcur->nodeFS != NULL) {
		while (Pcur != NULL) {
			if (Pcur->nodeFS != 0 && Resmi) {
				Pcur = Pcur->nodeFS;
				if (!isRoot(X,Pcur))
				{
					if (strcmp(nama,Pcur->nama) == 0)
					{ return index;}
					index++;
				}
			} else if (Pcur->nodeNB != NULL) {
				Pcur = Pcur->nodeNB;
				if (!isRoot(X,Pcur))
				{
					if (strcmp(nama,Pcur->nama) == 0)
					{ return index;}
					index++;
				}
				Resmi = true;
			} else {
				Pcur = Pcur->nodePR;
				Resmi = false;
			}
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
    scanf("%c", &pil);

    switch(pil) {
        case '1': 
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

void penambahanTahun(int * tahun, int penambahan, Root X){
	*tahun += penambahan;
	Node Pcur = X.root;
    Pcur->age = Pcur->age + penambahan;
	Pcur->mateAge = Pcur->mateAge +  penambahan;
	bool Resmi = true;
	if(Pcur->nodeFS != NULL) {
		while (Pcur != NULL) {
			if (Pcur->nodeFS != 0 && Resmi) {
				Pcur = Pcur->nodeFS;
				if(!isRoot(X,Pcur)){
                Pcur->age = Pcur->age + penambahan;
				Pcur->mateAge = Pcur->mateAge +  penambahan;
				}
				
			} else if (Pcur->nodeNB != NULL) {
				Pcur = Pcur->nodeNB;
				if(!isRoot(X,Pcur)){
                Pcur->age = Pcur->age + penambahan;
				Pcur->mateAge = Pcur->mateAge +  penambahan;
				}
				Resmi = true;
			} else {
				Pcur = Pcur->nodePR;
				Resmi = false;
			}
		}
	} 
}

void displayNamaKingdom()
/* Menampilkan desain nama kerajaan */
/* I.S : Desain nama kerajaan belum tampil di layar */
/* F.S : Desain nama kerajaan sudah tampil di layar*/
{
	FILE *fp;
	char Text[999];
	
	fp = fopen("Assets//NamaKerajaan.txt", "rt");
	
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
}

void gotoxy(int X, int y)
/* Mengatur titik koordinat kursor */
/* I.S : Titik koordinat kursor belum diatur */
/* F.S : Titik koordinat kursor sudah diatur */
{
	COORD coord;
	coord.X = X;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void introSilan()
/* Menampilkan identitas kelompok */
/* I.S : Identitas kelompok belum tampil di layar */
/* F.S : Identitas kelompok sudah tampil di layar*/
{
	const char sentence[] = "Asri Husnul Rosadi\t221524035\n\t\t\t\t\tM. Fathur Rabbani\t221524045\n\t\t\t\t\tNaia Siti Az-zahra\t221524052\n\n\t\t\t\t\t\t\t1B-D4IT\n";
	int i;

	gotoxy(40, 10);
	for (i = 0; sentence[i]!=0 ; i++) {
		Sleep(50);
		printf("%c", sentence[i]);
	}
	Sleep(100);

	system("cls");
	displayKingdom();
	system("cls");
}