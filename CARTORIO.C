#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o
#include <locale.h> //biblioteca de aloca��o de texto por regiao
#include <string.h> // biblioteca responsavel por cuidar das string

int registro()// fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das variaveis/string
	printf("digite o CPF a ser cadastrado: ");// coletando informa��es do usuario
	scanf("%s", cpf);// %s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE*file; // cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a");//atualiza��o do arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file=fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}
int consultar()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("nao foi possivel abrir o arquivo, nao foi localizado!. \n");
	}
   	
   	while(fgets(conteudo, 200, file) != NULL)
   	{
   		printf("\nEssas sao as informa��es do usuario: ");
   		printf("%s", conteudo);
   		printf("\n\n");
   		
	}

	system("pause");
	
}	
 int deletar()
 {
 	char cpf[40];
 	
 	printf("digite o cpf do usuario a ser deletado: ");
 	scanf("%s", cpf);
 	
 	remove(cpf);
 	
 	FILE *file;
 	file = fopen(cpf, "r");
 	
 	if(file == NULL)
 	{
 		printf("o usuario nao se encontra no sistema!. \n");
 		system("pause");
 		
	}
 	
 	
 	
 }

int main()
	{
	int opcao=0;// definindo as variaveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### cartorio da EBAC ###\n\n");
	printf("login de administrador!\n\ndigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if (comparacao == 0)
	{
		
		system ("cls");
		for (laco=1;laco==1;)
		{
	
			system("cls");
	
			setlocale(LC_ALL,"portuguese");//definindo a linguagem
			printf("### cartorio da EBAC ###\n\n");//inicio do menu
			printf("escolha a op��o desejada do menu: \n\n");
			printf("\t1 - registrar nomes\n");
			printf("\t2 - consultar nomes\n");
			printf("\t3 - deletar nomes\n");
			printf("\t4 - sair do sistema\n\n");//fim do menu 
	
			scanf("%d", &opcao); //armazenando a escolha do usuario
	
			system("cls");// responsavel por limpar a tela
		
			switch(opcao)// inicio da sele��o do menu
			{
				case 1:
				registro();//chamada de fun��es
				break;
				
				case 2:
				consultar();
				break;
			
				case 3:
		    	deletar();
				break;
			
				case 4:
				printf("obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default: 
				printf("essa op��o nao est� disponivel!\n ");
				system("pause");
				break;
			}//fim da sele��o
		}
	}
	else
	printf("senha incorreta! ");

}

	
