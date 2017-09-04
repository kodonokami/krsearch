#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "krs.h"

int main(int argc, char **argv){
	int cont_arg, cont_arq, cont_search, search_tam, file_tam, *diferenca, temp = 0, temp2 = 0, rela = 0, igual = 1;
	long long int pos;
	char *arg_search = NULL, *arg_file = NULL, byt, byt2;
	FILE *arquivo;
	
	//argumento menor que 2
	if(argc < 3){
		khelp();
		return 0;
	}
	
	//argumento
	for(cont_arg = 1; cont_arg < argc; cont_arg++){
		if((!strcmp(argv[cont_arg],"--help")) || (!strcmp(argv[cont_arg],"-h"))){
			khelp();
			return 0;
		}
		else if((!strcmp(argv[cont_arg],"--search")) || (!strcmp(argv[cont_arg],"-s"))){
			cont_arg++;
			arg_search = argv[cont_arg];
			search_tam = strlen(arg_search);
		}
		else if((!strcmp(argv[cont_arg],"--relative")) || (!strcmp(argv[cont_arg],"-r"))){
			cont_arg++;
			arg_search = argv[cont_arg];
			rela = 1;
			search_tam = strlen(arg_search);
		}
		else{
			arg_file = argv[cont_arg];
			file_tam = kgettam(arg_file);
			if(file_tam == -1){
				printf("erro ao abrir arquivo\n");
			}
		}
	}
	
	if(arg_file != NULL){
		arquivo = fopen(arg_file,"rb");
	}
	if(arg_search == NULL){
		printf("busca nao especificada\n");
		return 0;
	}
	
	
	//aloca espaço para a palavra
	diferenca = (int *) malloc(sizeof(int) * search_tam+2);
	
	//pega a diferença no argumento search e atribui para diferenca
	temp = (int) arg_search[0];
	for(cont_search = 1; cont_search < search_tam; cont_search++){
		temp = (int) arg_search[cont_search] -temp;
		diferenca[cont_search - 1] = temp;
		temp =  arg_search[cont_search];
	}
	
	//exibe a diferença relativa, argumento -r
	if(rela == 1){
		for(cont_search = 0; cont_search < search_tam -1; cont_search++){
			temp = diferenca[cont_search];
			printf("%d ",temp);
		}
		printf("\n");
		return 0;
	}
	
	//uma gambiarra aqui kkkk
	for(cont_arq = 0; cont_arq < file_tam; cont_arq++){
		pos = ftell(arquivo);
		byt = fgetc(arquivo);
		byt2 = byt;
		igual = 0;
		for(cont_search = 0; cont_search < search_tam -1; cont_search++){
			byt = fgetc(arquivo);
			byt2 = byt-byt2;
			if(byt2 == diferenca[cont_search]){
				igual = 1;
			}
			else{
				fseek(arquivo,pos+1,temp2);
				igual = 0;
				break;
			}
			byt2 = byt;
		}	
		if(igual == 1){
			printf("%x: a = 0x%x\n",ftell(arquivo) - search_tam,(unsigned char) byt - (temp - 0x61));
		}
	}
	
	return 0;
}
