/* File        : main.c 															*/  
/* Deskripsi   : Driver / main program untuk ADT Non Binary Tree Silsilah Kerajaan	*/ 
/* Dibuat oleh : Asri Husnul Rosadi			221524035
				 Mochamad Fathur Rabbani	221524045
				 Naia Siti Az-zahra			221524052 								*/
/* Tanggal     : 13-04-2023 														*/ 

#include <stdio.h>
#include <conio.h>
#include "silan.h"

int main() {
	Root king;
	king.root = NULL;	
	int pilMenu;
	displayKingdom();
	
	for(;;) {
		system("cls");
		printf("\n\t\t===== WELCOME TO THE KINGDOM OF WIBU =====\n\n");
		printf("\t[1] Tambah Bangsawan\n");
		printf("\t[2] Tambah Pasangan\n");
		printf("\t[3] Bunuh Bangsawan\n");
		printf("\t[4] Detail Bangsawan\n");
		printf("\t[5] Detail Kerajaan\n");
		printf("\t[6] Keluar\n\n");
		printf("\tMasukkan pilihan : ");
		scanf("%d", &pilMenu);
		
		switch(pilMenu) {
			case 1: 
				infotype name;
				name = (infotype) malloc(sizeof(infotype));
				infotype parent;
				parent = (infotype) malloc(sizeof(infotype));
				char jk;
				bool G;
				if (king.root == NULL)
				{
					printf("=======================\nMEMBUAT PEMIMPIN\n=======================\n");
					printf("Masukkan Nama Bangsawan : ");
					scanf( "%s", name);
					
					do{
						printf("Jenis Kelamin (L/P) : ");
						scanf(" %c", &jk);
						if(jk != 'L' && jk != 'P' && jk != 'l' && jk != 'P' ){
							printf("data jenis kelamin tidak sesuai, silahkan masukkan yang sesuai\n");
						}
					} while (jk != 'L' && jk != 'P' && jk != 'l' && jk != 'P' );
					
					
					infotype status;
					if(jk == 'L' || jk == 'l'){
						G = TRUE;
						status = "Raja";
					} else if (jk == 'P' || jk == 'p')
					{
						G = FALSE;
						status = "Ratu";
					} 
					Node lead;
					lead = (Tnode*)malloc(sizeof(Tnode));
					lead->nama = name;
					lead->jenisKelamin = G;
					lead->nodeFS = NULL;
					lead->nodeNB = NULL;
					lead->nodePR = NULL;
					lead->mate = NULL;
					king.root = lead;
					printf("Selamat kepada %s telah menjadi %s baru\n", king.root->nama,status);
					//system("pause");
				}else {
					Node pr;
					infotype child;
					child = (infotype) malloc(sizeof(infotype));
					parent = (infotype) malloc(sizeof(infotype));
					printf("=======================\nMENAMBAH ANAK\n=======================\n");
					do
					{
					printf("Masukkan Nama Orang Tua Bangsawan : ");
					scanf("%s", parent);
						pr = searchNode(king,parent);
						if(pr == NULL){
							printf("Data '%s' tidak ada, silahkan masukkan nama lain\n", parent);
						} else if(isSingle(pr)){
							printf("%s belum menikah, belum bisa mempunyai anak\n",pr->nama);
						}
					} while (pr == NULL || isSingle(pr));

					do
					{
					printf("Nama Anak : ");
					scanf("%s", child);
						if(searchNode(king,child) != NULL){
							printf("Nama sudah ada, silahkan masukkan nama lain\n");
						}
					} while (searchNode(king,child) != NULL);
					
					do
					{
					printf("Jenis kelamin (L/P) : ");
					scanf(" %c", &jk);
						if(jk != 'L' && jk != 'P' && jk != 'l' && jk != 'P' ){
							printf("data jenis kelamin tidak sesuai, silahkan masukkan yang sesuai\n");
						}
					} while (jk != 'L' && jk != 'P' && jk != 'l' && jk != 'p' );
					infotype gender;
					if(jk == 'L' || jk == 'l'){
						G = TRUE;
						gender = "Putra";
					} else if (jk == 'P' || jk == 'p')
					{
						G = FALSE;
						gender = "Putri";
					}
					insertNode(child,G,pr);
					printf("\nSelamat atas kelahiran nya %s, %s dari %s dan %s, may god bless this family forever\n",child,gender,pr->nama,pr->mate);
					//system("pause");
				}
				break;
			case 2:
			if (king.root == NULL)
			{
				printf("TENTUKAN DULU PEMIMPIN KERAJAAN");
				//system("pause");
			}else {
			infotype bride;
			bride = (infotype) malloc(sizeof(infotype));
			Node mates;
			infotype soulmate;
			soulmate = (infotype) malloc(sizeof(infotype));
			printf("=======================\nMEMILIH PASANGAN\n=======================\n");
			do{
				printf("Nama Bangsawan : ");
				scanf("%s", bride);
				mates = searchNode(king,bride);
						if(mates == NULL){
							printf("Nama tidak ada, silahkan masukkan nama lain\n");
						} else if(mates->mate != NULL){
							printf("Bangsawan ini sudah memiliki pasangan, tidak bisa menikah lagi \n");
							//system("pause");
						} 
					} while (mates == NULL);
					if (mates->mate != NULL)
					{
						break;
					}
					
					if(mates->jenisKelamin == FALSE){
						printf("Nama Suami Bangsawan : ");
					} else{
						printf("Nama Istri Bangsawan : ");
					}
				scanf("%s",soulmate);
				setMate(mates,soulmate);
				printf("Selamat pernikahan atas %s dengan %s, may be forever even after death\n",bride,soulmate);
				//system("pause");
				}
				break;
			case 3:
			if (king.root == NULL)
			{
				printf("TENTUKAN DULU PEMIMPIN KERAJAAN");
			}else {
				printf("=======================\nMEMBUNUH BANGSAWAN\n=======================\n");
				infotype Delete;
				Delete = (infotype) malloc(sizeof(infotype));
				printf("Siapa bangsawan yang akan ada bunuh ? ");
				scanf( "%s", Delete);
				deleteNode(&king,Delete);
				}
				break;
			case 4:
			printf("\n\t==================== MENCARI BANGSAWAN ====================\n\n");
			    if (king.root == NULL) {
			        system("cls");
			        printf("\tTENTUKAN DULU PEMIMPIN KERAJAAN\n\n\t");
			        //system("pause");
			    } else {
			        infotype namaNode;
					namaNode = (infotype) malloc(sizeof(infotype));
			        Node info;
			        system("cls");
			        //do {
			            printf("\tNama Bangsawan : ");
			            scanf("%s", namaNode);
			            info = searchNode(king, namaNode);
			            if (info == NULL) {
			                printf("\n\t=============================== TIDAK DITEMUKAN ===============================\n\n");
			                printf("\n\tNama Bangsawan Salah.\n\n\t");
			                //system("pause");
			            } else {
			                displayDetailNode(king,info);
			            }
			        //} while (info == NULL || info->mate == NULL);
			    }
			    break;
			break;
			case 5:
				displayDetailKingdom(king);
				//system("pause");
				break;
			case 6:
				displayMenuExit();
				break;
			default:
				printf("\n\tPilihanmu salah, pilih lagi!\n\t");
				//system("pause");
				break;
		}
	}
	return 0;
}



