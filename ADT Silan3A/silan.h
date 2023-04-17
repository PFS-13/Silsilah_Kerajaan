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
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include "boolean.h"

#define firstSon(P) (P)->nodeFS
#define nextBrother(P) (P)->nodeNB
#define parent(P) (P)->nodePR
#define gender(P)	(P)->gender

/*Definisi akses component type */

#define Nil NULL

typedef char* infotype;
typedef struct TNode * Node;
typedef struct TNode{ 
	infotype nama;
	bool jenisKelamin;
	infotype mate;
	Node nodeFS;
	Node nodePR;
	Node nodeNB;
} node;

typedef struct{
	Node  root;
} Root;

void createEmptyTree(Node node);
/* Membuat Tree baru yang masih kosong  */
/* I.S : Tree belum terbuat */
/* F.S : Tree sudah terbuat */

bool isEmpty(Root root);
/* Mengecek apakah suatu tree kosong atau tidak */

bool isRoot(Root root, Node node);
/* Mengecek apakah suatu node tersebut adalah root atau bukan */

Node  insertNode(infotype nama, bool jenisKelamin);
/* Membuat node dan memasukkan value kedalam node tersebut lalu mengembalikan node tersebut */

void deleteNode(Root X, infotype nama);
/* Menghapus Node dari suatu Tree */
/* I.S : Node belum terhapus */
/* F.S : Node sudah terhapus */

Node  searchNode(Root X, infotype nama);
/* Mencari suatu Node berdasarkan subvar nama lalu akan mengembalikan node tersebut jika ketemu */

void preOrder(Root X);
/* Menampilkan urutan garis suksesi silsilah secara preOrder */
/* I.S : Node sudah ada */
/* F.S : Node sudah terurut secara preOrder */

int level(Node node, infotype nama);
/* Mencari level pada suatu node tertentu */

void levelOrder(Root X);
/* Menampilkan urutan node tree secara levelOrder  */
/* I.S : Node belum terurut secara levelOrder */
/* F.S : Node sudah terurut secara levelOrder */

int depth(Root X);
/* Menghitung depth tree */

void displayFamily(Root X);
/* Menampilkan silsilah kerajaan secara levelOrder */
/* I.S : Silsilah kerajaan belum tampil */
/* F.S : Silsilah kerajaan sudah tampil */

int countChild(Node node);
/* Menghitung jumlah anak dari suatu node /

bool isSingle(Node Person);
/* Mengecek apakah value subvar mate dari node tersebut terisi atau null */

void setMate(Node Person);
/* Mengisi value subvar mate dari suatu node /
/* I.S : Subvar mate pada node masih null */
/* F.S : Subvar mate pada node sudah terisi value */

//void setNewRoot();
///* Membuat Tree baru yang masih kosong  */
///* IS : Tree belum terbuat */
///* FS : Tree sudah terbuat */

#endif