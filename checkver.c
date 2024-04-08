#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define COR_VERMELHO     12
#define COR_VERDE        10
#define COR_AMARELO      14
#define COR_AZUL         9
#define COR_BRANCO       15

void setCor(int cor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

void listarInformacoesSO() {
    system("wmic os get Caption, Version > informacoes_sistema.txt");
    system("cls");
    printf("\n------------------------------------------\n");
    printf("[+] Arquivo gerado com sucesso!\n");
    printf("------------------------------------------\n");
    system("start informacoes_sistema.txt");
}

void listarProcessos() {
    system("wmic process get Caption, ProcessId, CommandLine > processos.txt");
    system("cls");
    printf("\n------------------------------------------\n");
    printf("[+] Arquivo gerado com sucesso!\n");
    printf("------------------------------------------\n");
    system("start processos.txt");
}

void verificarAtualizacoes() {
    system("cls");
    system("wmic qfe list");
}

void descompactar_kb() {
    char origem_arquivo[100];
    char destino_arquivo[100];
    char caminho_kb[100];

    printf("Digite o nome do arquivo (KB):");
    scanf("%99s", origem_arquivo);
    printf("Digite o caminho da pasta onde deseja salvar:");
    scanf("%99s", destino_arquivo);

    char executando[200];
    sprintf(executando, "expand -f:* \"%s\" \"%s", origem_arquivo, destino_arquivo);
    system(executando);
}

void instalar_kb(){
    char caminho_kb[100];
    char construir[200];
    printf("Digite o KB onde você descompactou:");
    scanf("%99s", caminho_kb);
    sprintf(construir,"dism /online /Add-Package /PackagePath:\"%s\"",caminho_kb);
    system(construir);

}
int main() {
    int opcao;
    setCor(COR_AZUL);
    SetConsoleOutputCP(65001);

    do {
        printf("\n ");
        printf("\n------------------------------------------\n");
        printf("\n============ Checkver V 1.0 ==============\n");
        printf("\n          By: Anderson B Siva");
        printf("\n------------------------------------------\n");
        setCor(COR_VERDE);
        printf("1. Versão do sistema\n");
        printf("2. Listar processos em execução\n");
        printf("3. Verificar atualizações de software\n");
        printf("4. Descompactar KB de atualização: \n");
        printf("5. Instalar atualização (.cab)\n");
        printf("6. Sair\n");
        setCor(COR_BRANCO);
        printf("Escolha uma opção >>> : ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarInformacoesSO();
                break;
            case 2:
                listarProcessos();
                break;
            case 3:
                verificarAtualizacoes();
                break;
            case 4:
                descompactar_kb();
                break;
            case 5:
                instalar_kb();
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}
