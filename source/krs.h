#ifndef __KRS_H__
#define __KRS_H__

void khelp(void){
	printf("   [<o>] Kodo Relative Search [<o>]\n\n"
	"coder: kodo no kami (fb/hacker.fts315)\n"
	"forum: https://eofclub.in/forum (fb/forumeof)\n"
	"discord: https://discordapp.com/invite/cmzeMPv (kodo#0010)\n"
	"um salve para os romhackers da RHBR \\o\n\n"
	"sintaxe:\n    ./krsearch [option] rom\n\n"
	" --search (-s)   busca determinada palavra no arquivo\n"
	" --relative (-r) exibe a sequencia relativa da palavra\n"
	"\nexemplo:\n    ./krsearch --search \"pikachu\" pokemon.gbc\n"
	"    ./krsearch --relative \"kodo\"\n\n"
	);
}

long long int kgettam(const char *arq){
	FILE *arquivo = fopen(arq,"rb");
	if(arquivo == NULL){
		return -1;
	}
	int tam = 0;
	fseek(arquivo,0,SEEK_END);
	tam = ftell(arquivo);
	fclose(arquivo);
	return tam;
}

#endif
