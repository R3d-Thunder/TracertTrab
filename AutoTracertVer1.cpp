#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*IDEIA USAR STRCAT PARA MONTAR O CMD cmd /c ping 10.85.147.193 >> C:\\Users\\10219853681\\Desktop\\aaaaaaaaaaaaa\\Cod\\10.85.147.193.txt depois rodar usando system(X)*/
//system("cmd /c ping 10.85.147.193 >> C:\Users\10219853681\Desktop\aaaaaaaaaaaaa\Cod\10.85.147.193.txt");

char AUX[20] = "cmd /c Tracert -d ";  //define o comnado a ser usado (cmd /c e para fazer um comando por vez)
char Caminho[100];

int Monta_Comando(char X[20]){
	
	char Y[200];
	
	strcpy(Y,AUX);
	strcat(Y,X);
	strcat(Y," >> ");
	strcat(Y,Caminho);
	strcat(Y,X);
	strcat(Y,".txt");
	
	//printf("%s\n",Y);
	
	system(Y);
	
	return 1;
	
}

int Monta_Comando1(char X[20]){
	
	char Y[200];
	
	strcpy(Y,AUX);
	strcat(Y,X);
	
	if(z == 0){
		
		strcat(Y," > ");
		z = 1;
		
	}else{
		
		strcat(Y," >> ");
		
	}
	
	strcat(Y,Caminho);
	strcat(Y,"Geral.txt");
	
	//printf("%s\n",Y);
	
	system(Y);
	
	return 1;
	
}

int Monta_Caminho(){
	
	FILE *arq;
	char buffer;
	int k=0;
	
	arq= fopen("Caminho.txt","r");
	
	if(arq == NULL){
		
		printf("ERRO");
		return 0;
		
	}else{
	
		while((buffer=fgetc(arq)) != EOF){
			
			Caminho[k]= buffer;
			k++;
			
		}
		
		//printf("%s\n",Caminho);
		
		return 1;
		
	}
	
	return 0;
	
}

main(){
	
	strcpy(Caminho,"0"); //zera caminho
	Monta_Caminho();
	//printf("%s\n",Caminho);
	
	FILE *arq;
	char buffer;
	char x[20];
	int k= 0;
	
	for(k;k<20;k++){
		
		x[k]= '\0';
		
	}
	
	k=0;
	
	arq = fopen("IP.txt","r");
	
	if(arq == NULL){
		
		printf("ERRO");
		
	}else{
		
		while((buffer=fgetc(arq)) != EOF){
			
			//printf("%c",buffer);
			
			switch(buffer){
				
				/*case '\n':
					
					if(x[0] == '\n'){
						
						break;
						
					}
					
					printf("%s\n",x);
					Monta_Comando(x);
					for(k;k>=0;k--){
						
						x[k]='\0';
						
					}
					printf("\n%s\n",x);
					k= 0;
					
					break;
					*/
				case ',':
					
					if(x[0] == ','){
						
						break;
						
					}
					
					//printf("%s\n",x);
					Monta_Comando(x);
					Monta_Comando1(x);
					for(k;k>=0;k--){
						
						x[k]='\0';
						
					}
					k= 0;
					
					break;
				case ';':
					
					if(x[0] == ';'){
						
						break;
						
					}
					
					//printf("%s\n",x);
					Monta_Comando(x);
					Monta_Comando1(x);
					for(k;k>=0;k--){
						
						x[k]='\0';
						
					}
					k= 0;
					
					break;
				case ' ':
					
					if(x[0] == ' '){
						
						break;
						
					}
					
					//printf("%s\n",x);
					Monta_Comando(x);
					Monta_Comando1(x);
					for(k;k>=0;k--){
						
						x[k]='\0';
						
					}
					k= 0;
					
					break;
				default:
					
					x[k] = buffer;
					k++;
					
					break;
					
			}
			
		}
		
	}
	
	Monta_Comando(x);
	Monta_Comando1(x);
	
	fclose(arq);

}

















