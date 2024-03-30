#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsavel pelas strings (conjunto de info com mais de uma letra ou numero)

int registro() // responsavel por cadastrar usarios no sistema
{
	//inicio criacao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criacao de variaveis/string
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informacoes do usuario
	scanf("%s", cpf); //%s refere a string 
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo com W rite	
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //printf e a pergunta ao usuario
	scanf("%s", nome); //%s para salvar o que o usuario digitar na string
	
	file = fopen(arquivo, "a"); // A tualizando o arquivo ja criado
	fprintf(file, nome); //salvando no arquivo o que o usuario digitar
	fclose(file); // sempre fechar o arquivo
	
	file = fopen(arquivo, "a"); //Atualizando arquivo
	fprintf(file, ","); //organizando variaveis com , 
	fclose(file); // fechando funcao
	
	printf("Digite o sobrenome a ser cadastrado: "); //pergunta para o usuario
	scanf("%s", sobrenome); //salvando o que o usuario digitou na string
	
	file = fopen(arquivo, "a"); //abrindo arquivo ja criado para salvar string
	fprintf(file,sobrenome); // salvando o que o usuario digitou - sobrenome
	fclose(file); // fechando arquivo
	
	file = fopen(arquivo, "a"); //abrindo arquivo 
	fprintf(file,","); //organizando o que o usuario digitou com , - poderia ser - ; 
	fclose(file); // fechando arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //perguntando ao usuario informacao
	scanf("%s",cargo); //salvando o que o usuario digitou na string
	
	file = fopen(arquivo, "a"); //abrindo o que o usuario digitou 
	fprintf(file,cargo); //salvando o que o usuario digitou em arquivo ja criado "int registro"
	fclose(file); // fechando arquivo
	
	system("pause"); // finalizando funcao 
	
}

int consulta() //funcao para usuario ver o que as strings criadas e salvas no arquivo
{
	setlocale (LC_ALL,"Portuguese"); // definindo linguagem
	
	char cpf[40]; //caractere de texto - quantos numeros/palavras incluir entre [] 
	char conteudo[200]; // para conteudo: nome, sobrenome, cargo
	
	printf("Digite o cpf a ser consultado:"); //funcao para perguntar ao usuario
	scanf("%s",cpf); //salvar na string o que o usuario digitar
	
	FILE *file; //abrindo arquivo criado na funcao string
	file = fopen(cpf,"r"); // ler (read) o cpf cadastrado na funcao registro
	
	if(file == NULL) //se o numero de cpf digitado nao no file "NULL" para...
	{
		fclose(file);	
		printf("Nao foi possivel abrir o arquivo, nao localizado!.\n"); //cpf nao localizado em arquivo, mensagem que aparecera para usuario
	}
	
	while(fgets(conteudo, 200, file) != NULL)// mas se o cpf for correto..
	{
		fclose(file);
		printf("\nEssas sao as informacoes do usuario: "); // mostrara string salva em arquivo
		printf("%s", conteudo); // mostrando string do conteudo salvo 
		printf("\n\n"); // espacamento para estetica
	}
	
	system("pause"); // finalizando funcao
}

int deletar() //funcao para deletar usuario
{
		char cpf[40]; //variavel a ser consultada
		
		printf("Digitar o CPF do usuario a ser deletado: "); //pedindo ao usuario numero de cpf a ser deletado
		scanf("%s", cpf); //buscando string salva em arquivo
		
		FILE *file; //abrindo arquivo
		file = fopen(cpf,"r"); //lendo cpf digitada para checar se string existe
		
		if(file == NULL) // Analise de usuario inexistente
		{
			fclose(file);
			printf("O usuario nao se encontra no sistema!.\n"); //cpf digitado errado
			system("pause"); //fechando funcao
		}
		
		else if (file != NULL)
		{
			fclose(file);
			printf("O arquivo foi deletado. \n");
			system("pause"); //pa
			remove (cpf);//cpf removido do banco de dados
		}
			
}

int main() //inicio do menu
{
		int opcao=0;
		int x=1;
			
        for(x=1;x=1;) //loop para repeticao verdadeira 
		{
	
		system("cls"); //limpando tela do usuario 
		
		setlocale (LC_ALL,"Portuguese"); // definindo linguagem
	
		printf(" ###Cartório da EBAC ###\n\n"); // inicio do menu
		printf("Escolha a opção deseja do menu:\n\n"); //opcoes do menu definidas pelo cliente
		printf("\t1 - Registrar nomes\n"); //opcao 1
		printf("\t2 - Consultar nomes\n"); //opcao 2
		printf("\t3 - Deletar nomes\n"); //opcao 2
		printf("Opcao:"); // campo para opcao digitada
	
		scanf("%d", &opcao); // armazenando a escolha do usario
		
		system("cls"); //limpando tela do usuario 
		
		
		switch(opcao) //criacao de varios blocos de codigo 
		{
			
		case 1: // inicio de opcao 
		registro(); //digitar opcao 1 para registro
		break; // encerramento de opcao
		
		case 2:	//inicio de opcao 
		consulta(); //digitar opcao 2 para registro
		break; // encerramento de opcao 
		
		case 3: // incio de opcao 
		deletar(); //digitar opcao 3 para registro
		break; // encerramento de opcao - volta sempre para o loop
		
		
		default: // fim do padrao
		printf("Essa opcao nao esta disponivel!\n"); // fim da selecao
		system("pause"); // encerrando funcao 
		break;//encerramento de opcao 
		}
		}
}//nao esquecer de fechar 
