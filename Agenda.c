#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int dia;
	int mes;
	int ano;
}Data;

typedef struct { 
	char rua[20];
	char numero[5];
	char complemento[50];
	char bairro[20];
	char cidade[20];
	char estado[20];
	char pais[20];
	char cep[10];
}Endereco;

typedef struct { 
	char nome[20];
	char ddd[3];
	char telefone[20];
	Data nascimento;
	Endereco residencia;
}Pessoa;

void incluir_registro(FILE *arq);
void listar_registros(FILE *arq);
void ler_data (Data *p);
void mostra_data(Data x);
void ler_pessoa (Pessoa *p);
void ler_endereco (Endereco *p);
void mostra_pessoa(Pessoa x);
void mostra_endereco(Endereco x);

int main(){
	char opcao;
	
	Pessoa pessoas;
	
	ler_pessoa ( &pessoas );
	mostra_pessoa ( pessoas );
	
	return 0;
}
void ler_pessoa (Pessoa *p){

	printf("\nDigite seu nome: ");
	gets(p->nome);
	printf("\nDigite o numero de telefone");
	printf("\nDDD: ");
	gets(p->ddd);
	printf("Numero: ");
	gets(p->telefone);
	ler_data(&p->nascimento);
	ler_endereco(&p->residencia);
}

void ler_data (Data *p){

	printf("\nInsira a data de nascimento\n");
	printf("Dia: ");
	scanf("%d", &p->dia);
	printf("Mes: ");
	scanf("%d", &p->mes);
	printf("Ano: ");
	scanf("%d", &p->ano);
}

void ler_endereco (Endereco *p){
    
    printf("\nInsira seu endereço\n");
    printf("Rua: ");
    gets(p->rua);
    printf("Numero: ");
    gets(p->numero);
    printf("Complemento: ");
    gets(p->complemento);
    printf("Bairro: ");
    gets(p->bairro);
    printf("Cidade: ");
    gets(p->cidade);
    printf("Estado: ");
    gets(p->estado);
    printf("País: ");
    gets(p->pais);
    printf("Cep: ");
    gets(p->cep);
    
}

void mostra_data(Data x) {
	printf("%2d/%2d/%4d\n", x.dia, x.mes, x.ano);
}

void mostra_endereco(Endereco x){
    printf("Rua: %s, nº %s - Bairro: %s \nCidade: %s - Estado: %s - País: %s", x.rua, x.numero, x.bairro, x.cidade, x.estado, x.pais);
    printf("\nComplemento: %s - CEP: %s", x.complemento, x.cep);
}

void mostra_pessoa (Pessoa x){
	printf("\nNome: %s\n", x.nome);
	printf("Telefone: %s-%s\n", x.ddd, x.telefone);
	mostra_data(x.nascimento);
	mostra_endereco(x.residencia);
}
