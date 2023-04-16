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
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

void createEmptyTree(Node *node)
/* Membuat Tree baru yang masih kosong  */
/* I.S : Tree belum terbuat */
/* F.S : Tree sudah terbuat */
{

	
}

bool isEmpty(Root X)
/* Mengecek apakah suatu tree kosong atau tidak */
{
	if(X.root == NULL){
        return true;
    } else {
    	return false;
	}
}

bool isRoot(Root root, Node node)
/* Mengecek apakah suatu node tersebut adalah root atau bukan */
{
	if(root.root == node) {
        return true;
    } else {
        return false;
    }
}

Node* insertNode(infotype nama, bool jenisKelamin)
/* Membuat node dan memasukkan value kedalam node tersebut lalu mengembalikan node tersebut */
{
	Node *newNode;
    newNode = 
	
	
}

void deleteNode(Root X, infotype nama)
/* Menghapus Node dari suatu Tree */
/* I.S : Node belum terhapus */
/* F.S : Node sudah terhapus */
{
//	TNode *currNode = X.root, *parent = NULL. *nDel = NULL;
//    bool found = false;
//    while (currNode != NULL) {
//        if (strcmp(currNode->nama, nama) == 0) {
//            found = true;
//            nDel = currNode;
//            break;
//        }
//        parent = currNode;
//        if (currNode->nodeFS != NULL) {
//            currNode = currNode->nodeFS;
//        } else if (currNode->nodeNB != NULL) {
//            currNode = currNode->nodeNB;
//        } else {
//            currNode = currNode->nodePR;
//        }
//    }
//    if (found) {
//        if (nDel->nodeFS != NULL) {
//            printf("Tidak dapat menghapus node dengan anak pertama\n");
//        } else {
//            if (nDel == X.root) {
//                X.root = NULL;
//            } else if (parent->nodeFS == nDel) {
//                parent->nodeFS = nDel->nodeNB;
//            } else if (parent->nodeNB == nDel) {
//                parent->nodeNB = nDel->nodeNB;
//            } else {
//                parent->nodePR = nDel->nodeNB;
//            }
//            free(nDel);
//            printf("Node %s telah dihapus\n", nama);
//        }
//    } else {
//        printf("Node %s tidak ditemukan\n", nama);
//    }
}

Node* searchNode(Root X, infotype nama)
/* Mencari suatu Node berdasarkan subvar nama lalu akan mengembalikan node tersebut jika ketemu */
{
	Node *currNode = X.root;
    while (currNode != NULL) {
        if (strcmp(currNode->nama, nama) == 0) {
            return currNode;
        } if (currNode->nodeFS != NULL) {
        	currNode = currNode->nodeFS;
        } else if (currNode->nodeNB != NULL) {
            currNode = currNode->nodeNB;
        } else {
            currNode = currNode->nodePR;
        }
    }
    return NULL;
}

void preOrder(Root X)
/* Menampilkan urutan garis suksesi silsilah secara preOrder */
/* I.S : Node sudah ada */
/* F.S : Node sudah terurut secara preOrder */
{
	
}

int level(Node node, infotype nama)
/* Mencari level pada suatu node tertentu */
{
	
}

void levelOrder(Root X)
/* Menampilkan urutan node tree secara levelOrder  */
/* I.S : Node belum terurut secara levelOrder */
/* F.S : Node sudah terurut secara levelOrder */
{
	
}

int depth(Root X)
/* Menghitung depth tree */
{
	
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
    if(node.nodeFS != NULL) { // jika ada anak pertama
        jml++; // tambahkan 1 pada jumlah anak
        Node *child = node.nodeFS->nodeNB;
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
	if(Person.mate == NULL) {
        return true;
    } else {
    	return false;
	}
}

void setMate(Node *Person)
/* Mengisi value subvar mate dari suatu node */
/* I.S : Subvar mate pada node masih null */
/* F.S : Subvar mate pada node sudah terisi value */
{
	infotype input = (infotype) malloc(sizeof(char));
    printf("Masukkan nama pasangan %s: ", Person->nama);
    scanf("%s", input);
    Person->mate = input;
}