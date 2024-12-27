#include<stdio.h>


int main() {

    
#include <stdio.h>
#include <string.h>

typedef struct{
	char username[50];
	char password[50];
} Accounts;

void login( Accounts account[], int n );
void reg( Accounts account[], int *n );

int main(){
	int choice, n= 0;
	Accounts account[100];
	
	FILE *fptr = fopen("ss22-lt2.bin", "rb");
	n= fread( account , sizeof(Accounts), 100, fptr );
	fclose(fptr);
	do{
		printf("\n---------Menu-------------");
		printf("\n1. Dang nhap ");
		printf("\n2. Dang ky ");
		printf("\n3. Thoat ");
		printf("\nLua chon cua ban: ");
		scanf("%d", &choice);
		fflush(stdin);
		
		switch(choice){
			case 1:{
				if ( n == 0 ){
					printf("\nDanh sach tai khoan rong!Vui long dang ky!");
				}else{
					login(account, n);
				}
				break;
			}
			case 2:{
				reg(account, &n);
				break;
			}
			case 3:{
				printf("\nBan chon thoat!");
				break;
			}
			default:{
				printf("\nVui long chon dung(1-3)!");
				break;
			}
		}
	}while( choice != 3 );

	return 0;
}

void login( Accounts account[], int n ){
	char username[50], password[50];
	int check  = 0;
	
	printf("\nNhap thong tin tai khoan dang nhap: ");
	do{
		printf("\nNhap username: ");
		fgets(username, 20, stdin );
		username[strlen(username) -1] = '\0' ;
		
		printf("Nhap password: ");
		fgets(password, 20, stdin );
		password[strlen(password) -1] = '\0' ;
		
		FILE *fptr = fopen("ss22-lt2.bin", "rb");
		fread( account , sizeof(Accounts), n, fptr );
		fclose(fptr);
	
		for ( int i=0 ; i<n ; i++){
			if ( strcmp(account[i].username, username) == 0 && strcmp(account[i].password, password) == 0 ){
				printf("\nDang nhap thanh cong!");
				check = 1;
				break;
			}
		}
		if ( check == 0 ) printf("\nTai khoan khong ton tai! Vui long nhap lai!");
	}while( check ==  0 );
}

void reg( Accounts account[], int *n ){
	char username[50], password[50];
	int check ;
	
	if ( *n > 100 ){
		printf("\nMang da full!");
		return;
	}
	
	printf("\nNhap thong tin tai khoan dang ky: ");
	do {
		check = 0 ;
		printf("\nNhap username: ");
		fgets(username, 20, stdin );
		username[strlen(username) -1] = '\0' ;
		
		printf("Nhap password: ");
		fgets(password, 20, stdin );
		password[strlen(password) -1] = '\0' ;
		
		for ( int i=0 ; i< *n ; i++){
			if ( strcmp(account[i].username, username) == 0 && strcmp(account[i].password, password) == 0 ){
				printf("\nTai khoan da ton tai!");
				printf("\nNhap lai thong tin tai khoan dang ky: ");
				check = 1;
				break;
			}
		}
		
		if ( check == 0 ){
			strcpy( account[*n].username, username);
			strcpy( account[*n].password, password);
			FILE *fptr = fopen("ss22-lt2.bin", "ab");
			fwrite( &account[*n] , sizeof(Accounts), 1, fptr );
			fclose(fptr);
			(*n)++;
			printf("\nThem thanh cong!");
		}
		
	}while( check == 1 );
}


    
	return 0;
}

