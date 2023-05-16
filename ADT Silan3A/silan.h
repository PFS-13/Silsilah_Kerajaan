/* File        : silan.h 													*/  
/* Deskripsi   : Header file untuk ADT Non Binary Tree Silsilah Kerajaan	*/ 
/* Dibuat oleh : Asri Husnul Rosadi			221524035
				 Mochamad Fathur Rabbani	221524045
				 Naia Siti Az-zahra			221524052 						*/
/* Tanggal     : 13-04-2023 												*/ 

#ifndef silan_h
#define silan_h

#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include "boolean.h"

#define data(P) (P)->data
#define firstSon(P) (P)->firstSon
#define nextBrother(P) (P)->nextBrother
#define parent(P) (P)->parent
#define gender(P)	(P)->gender
#define status(P)	(P)->status
#define usia(P)	(P)->usia
#define wife(P) (P)->wife

/*Definisi akses component type */
#define data(P)	(P)->data
#define next(p)	(p)->next 
#define Nil NULL

typedef char* infotype;
typedef struct TNode * Node;
typedef struct TNode{ 
	infotype nama;
	int age;
	bool jenisKelamin;
    infotype mate;
	int mateAge;
	infotype parent;
	Node nodeFS;
	Node nodePR;
	Node nodeNB;
} Tnode;

typedef struct{
	Node root;
} Root;

void createEmptyTree(Root *root);
/* Membuat Tree baru yang masih kosong  */
/* I.S : Tree belum terbuat */
/* F.S : Tree sudah terbuat */

bool isEmpty(Node *node);
/* Mengecek apakah suatu tree kosong atau tidak */

bool isRoot(Root root, Node node);
/* Mengecek apakah suatu node tersebut adalah root atau bukan */

void insertNode(infotype nama, bool jenisKelamin, Node  parent);
/* Membuat node dan memasukkan value kedalam node tersebut lalu mengembalikan node tersebut */

Node searchNode(Root X, infotype nama);
/* Mencari suatu Node berdasarkan subvar nama lalu akan mengembalikan node tersebut jika ketemu */

void deleteNode(Root * X, infotype nama);
/* Menghapus Node dari suatu Tree */
/* I.S : Node belum terhapus */
/* F.S : Node sudah terhapus */

void garisSuksesi(Root X);
/* Menampilkan urutan garis suksesi silsilah secara preOrder */
/* I.S : Node sudah ada */
/* F.S : Node sudah terurut secara preOrder */

void displayFamily(Node X, int level);
/* Menampilkan silsilah kerajaan saat ini (secara keseluruhan yang masih hidup) */
/* I.S : Silsilah kerajaan belum tampil */
/* F.S : Silsilah kerajaan sudah tampil */

int countChild(Root X, Node node);
/* Menghitung jumlah anak dari suatu node */

bool isSingle(Node Person);
/* Mengecek apakah value subvar mate dari node tersebut terisi atau null */

void setMate(Node Person, infotype mate, int umur);
/* Mengisi value subvar mate dari suatu node */
/* I.S : Subvar mate pada node masih null */
/* F.S : Subvar mate pada node sudah terisi value */

void displayRules();
/* Menampilkan aturan pada kerajaan Inggris */
/* I.S : Aturan kerajaan Inggris belum tampil di layar */
/* F.S : Aturan kerajaan Inggris sudah tampil di layar */

void displayDetailNode(Root X,Node node);
/* Menampilkan level, pasangan, dan jumlah anak */
/* I.S : Detail suatu node belum tampil di layar */
/* F.S : Detail suatu node sudah tampil di layar */

void displayDetailKingdom(int tahun,Root X);
/* Menampilkan pilihan ingin melihat aturan atau silsilah kerajaan sebelumnya */
/* I.S : Aturan atau silsilah kerajaan belum tampil di layar */
/* F.S : Aturan atau silsilah kerajaan sudah tampil di layar */

int detailPenerus(Root X, infotype nama);

void displayMenuExit();
/* Menampilkan tampilan menu keluar */
/* I.S : Menu tampil di layar */
/* F.S : Keluar dari program */

void displayKingdom();
/* Menampilkan desain kerajaan */
/* I.S : Desain kerajaan belum tampil di layar */
/* F.S : Desain kerajaan sudah tampil di layar */

void penambahanTahun(int * tahun, int penambahan, Root X);
/* Menambah tahun kerajaan */
/* I.S : Tahun masih sama  */
/* F.S : Tahun sudah bertambah sesuai dengan penambahan */

void displayNamaKingdom();
/* Menampilkan desain nama kerajaan */
/* I.S : Desain nama kerajaan belum tampil di layar */
/* F.S : Desain nama kerajaan sudah tampil di layar*/

void introSilan();
/* Menampilkan identitas kelompok */
/* I.S : Identitas kelompok belum tampil di layar */
/* F.S : Identitas kelompok sudah tampil di layar*/

void gotoxy(int X, int y);
/* Mengatur titik koordinat kursor */
/* I.S : Titik koordinat kursor belum diatur */
/* F.S : Titik koordinat kursor sudah diatur */
#endif