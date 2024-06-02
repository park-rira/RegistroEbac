#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacao de texto por regiao
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()  //Fun��o responsavel por cadastrar os usuarios no sistema
{
	setlocale(LC_ALL, "Portuguese");  //definindo a linguagem
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado:   ");  //coletando informa��o do usuario
	scanf("%s", cpf);  //%s refere-se a string
	
	strcpy(arquivo, cpf);  //responsavel por copiar os valores dos strings
	
	FILE *file;  //cria o arquivo 
	file = fopen(arquivo, "w");  //cria o arquivo e o w significa escrever
	fprintf(file, cpf);  //salvo o valor da variavel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //para atualizar o arquivo
	fprintf(file,",");  //dar o espaco
	fclose(file);  //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:   ");  //cadastrando a informa��o do usuario
	getchar();   //Limpa o caractere de nova linha pendente no buffer
	fgets(nome,sizeof(nome),stdin);  //Le uma linha inteira, incluindo espaco em branco
	nome[strcspn(nome,"\n")]='\0';  //Remove a nova linha do final do nome
	
	file = fopen(arquivo, "a");  //abre o arquivo e atualiza a informa��o
	fprintf(file,nome);  //salva o valor da variavel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //abre o arquivo e atualiza a infoma��o
	fprintf(file,",");  //dar espa�o
	fclose(file);  //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:  ");
	fgets(sobrenome,sizeof(sobrenome),stdin);  //L� uma linha intiera, incluindo espa�o em branco
	sobrenome[strcspn(sobrenome,"\n")]='\0';  //Remove a nova linha do final do sobrenome
	
	file = fopen(arquivo, "a");  //abre o arquivo e atualiza a informa��o
	fprintf(file,sobrenome);  //salva o valor da variavel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");  //abre o arquivo e atualiza a informa��o
	fprintf(file, ",");  //dar espa�o
	fclose(file);  //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:   ");
	scanf("%s", cargo);  //%s refere-se a string
	
	file = fopen(arquivo, "a");  //abre o arquivo e atualiza a informa��o
	fprintf(file,cargo);  //salva o valor da variavel
	fclose(file);  //fecha o arquivo
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
		
	printf("Digite o CPF a ser consultado:  ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)  //arquivo for igual nulo
	{
		printf("N�o foi poss�vel abrir o arquivo. N�o localizado. \n\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n\n");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser DELETADO:   ");
	scanf("%s",cpf);
	
	FILE *file;  //cria o arquivo
	file = fopen(cpf,"r");  //abre o arquivo, r de l� o arquivo
	fclose(file);
	
	if(file == NULL)  //arquivo for igual a nulo
	{
		printf("\nCPF n�o cadastrado!\n\n");
		system("pause");
	}
	
	remove(cpf);
	
	if(file != NULL)  //arquivo for diferente de nulo
	{
		printf("\nCPF deletado com sucesso!\n\n");
		system("pause");
	}
	
}
	
int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)  //lapso de repeti��o da variavel
	{
		system("cls");  //responsavel por limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("\tBem-vindo � EBAC\n\n\n");
		printf("Escolha abaixo as op��es do menu:\n\n\n");
		printf("\t1 - Registro de aluno\n");
		printf("\t2 - Consulta de aluno\n");
		printf("\t3 - Exclus�o de aluno\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");   //responsavel por limpar a tela
	
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro();  //chamada de fun��es
			break;
				
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigada por utilizar o sistema\n");
			return 0;
			break;
									
			default:
			printf("Esta op��o n�o est� dispon�vel. Tente novamente. \n\n\n\n");
			system("pause");
			break;	
		}  //fim da sele��o
	}
}			

