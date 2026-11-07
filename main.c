#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define TAM_LINHA 50

//Retorna Todos os Dados do Arquivo .txt
void imprimirDados(int numDados, bool duplicidade, char dados[][TAM_LINHA], int *qtd)
{

    char caminho[126] = "";

    //BUSCA O CAMINHO DOS ARQUIVOS TXT C/ OS DADOS
    switch (numDados)
    {
    case 1000:
        if (duplicidade)
        {
            strcpy(caminho, "Dados/1k/Com Duplicidade/Aleatorio/dtaleat1kdup3.txt");
        }
        else {
            strcpy(caminho, "Dados/1k/Sem Duplicidade/Aleatorio/dtaleat1kuni3.txt");
        }
        break;
    
    case 5000:
        if (duplicidade)
        {
            strcpy(caminho, "Dados/5k/Com Duplicidade/Aleatorio/dtaleat5kdup3.txt");
        }
        else {
            strcpy(caminho, "Dados/5k/Sem Duplicidade/Aleatorio/dtaleat5kuni3.txt");
        }
        break;
    
    case 10000:
        if (duplicidade)
        {
            strcpy(caminho, "Dados/10k/Com Duplicidade/Aleatorio/dtaleat10kdup3.txt");
        }
        else
        {
            strcpy(caminho, "Dados/10k/Sem Duplicidade/Aleatorio/dtaleat10kuni3.txt");
        }
        break;
        
    case 100000:
        if (duplicidade)
        {
            strcpy(caminho, "Dados/100k/Com Duplicidade/Aleatorio/dtaleat100kdup3.txt");
        }
        else
        {
            strcpy(caminho, "Dados/100k/Sem Duplicidade/Aleatorio/dtaleat100kuni3.txt");
        }
        break;
        
    default:
        printf("Este tamanho está fora do padrão determinado, selecione apenas estas opções:\n1.000, 5.000, 10.000, 100.000");
        break;
    }

    //ADICIONA OS DADOS A UMA VARIAVEL CHAR

    char buffer[TAM_LINHA];
    *qtd = 0;

    FILE *dadosCSDuplicidade = fopen(caminho, "r");

    if(dadosCSDuplicidade == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        printf("Verifique se o caminho esta correto:\n %s\n", caminho);
        return;
    }

    printf("Arquivo aberto com sucesso\n");

    while (fgets(buffer, sizeof(buffer), dadosCSDuplicidade) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';

        char *inicio = buffer;

        while (isspace((unsigned char)*inicio)) {
            inicio++;
        }

        if (strlen(inicio) == 0) {
            continue;
        }

        if (*qtd >= numDados)
            break;

        strcpy(dados[*qtd], inicio);
        (*qtd)++;
    }

    fclose(dadosCSDuplicidade);
}

//Bubble Sort - 0: Crescente; 1: Decrescente; 2: Aleatorio; 3: Concava; 4: Convexa
void bubbleSort(int valorOrdenacao, int *dados, int qtdTotalLinhas)
{
    int temp;
    bool trocar;

    switch(valorOrdenacao)
    {
        //Ordem Crescente == 0
        case 0:

            for (int i = 0; i < qtdTotalLinhas - 1; i++)
            {
                trocar = false;
                for (int j = 0; j < qtdTotalLinhas - i - 1; j++)
                {
                    if (dados[j] > dados[j+1])
                    {
                        temp = dados[j];
                        dados[j] = dados[j+1];
                        dados[j+1] = temp;
                        trocar = true;
                    }
                }

                if(!trocar)
                {
                    break;
                };
            }
            
            break;

        //Ordem Decrescente == 1
        case 1:
            for (int i = 0; i < qtdTotalLinhas - 1; i++)
            {
                trocar = false;
                for (int j = 0; j < qtdTotalLinhas - i - 1; j++)
                {
                    if (dados[j] < dados[j+1])
                    {
                        temp = dados[j];
                        dados[j] = dados[j+1];
                        dados[j+1] = temp;
                        trocar = true;
                    }
                }

                if(!trocar)
                {
                    break;
                };
            }
            break;

        //Aleatoria == 2
        case 2:
            for (int i = 0; i < qtdTotalLinhas - 1; i++)
            {
                trocar = false;
                for (int j = 0; j < qtdTotalLinhas - i - 1; j++)
                {
                    if (rand() % 2 == 1)
                    {
                        temp = dados[j];
                        dados[j] = dados[j+1];
                        dados[j+1] = temp;
                        trocar = true;
                    }
                }
            }
            break;

        //Concava == 3
        case 3:
            for (int i = 0; i < qtdTotalLinhas - 1; i++)
            {
                trocar = false;
                for (int j = 0; j < qtdTotalLinhas - i - 1; j++)
                {
                    if (j < (qtdTotalLinhas / 2))
                    {
                        if (dados[j] < dados[j+1])
                        {
                            temp = dados[j];
                            dados[j] = dados[j+1];
                            dados[j+1] = temp;
                            trocar = true;
                        }
                    }
                    else
                    {
                        if (dados[j] > dados[j+1])
                        {
                            temp = dados[j];
                            dados[j] = dados[j+1];
                            dados[j+1] = temp;
                            trocar = true;
                        }
                    }
                }
            }
            break;

        //Convexa == 4
        case 4:
            for (int i = 0; i < qtdTotalLinhas - 1; i++)
            {
                trocar = false;
                for (int j = 0; j < qtdTotalLinhas - i - 1; j++)
                {
                    if (j < (qtdTotalLinhas / 2))
                    {
                        if (dados[j] > dados[j+1])
                        {
                            temp = dados[j];
                            dados[j] = dados[j+1];
                            dados[j+1] = temp;
                            trocar = true;
                        }
                    }
                    else
                    {
                        if (dados[j] < dados[j+1])
                        {
                            temp = dados[j];
                            dados[j] = dados[j+1];
                            dados[j+1] = temp;
                            trocar = true;
                        }
                    }
                }
            }
            break;
        default:
            break;
    }
}

void merge(int *dados, int inicio, int meio, int fim, int valorOrdenacao)
{
    int i, j, k;

    int tamEsq = meio - inicio + 1;
    int tamDir = fim - meio;

    int *E = malloc(tamEsq * sizeof(int));
    int *D = malloc(tamDir * sizeof(int));

    for (int i = 0; i < tamEsq; i++)
    {
        E[i] = dados[inicio + i];
    }

    for (int j = 0; j < tamDir; j++)
    {
        D[j] = dados[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;
    
    while (i < tamEsq && j < tamDir)
    {
        bool condicao;

        if(valorOrdenacao == 0) {
            condicao = (E[i] <= D[j]);
        } else if (valorOrdenacao == 1) {
            condicao = (E[i] >= D[j]);
        } else if (valorOrdenacao == 2) {
            condicao = (rand() % 2 == 1);
        }

        if (condicao) {
            dados[k] = E[i];
            i++;
        } else {
            dados[k] = D[j];
            j++;
        }

        k++;
    }

    while(i < tamEsq) {
        dados[k] = E[i];
        i++;
        k++;
    }

    while (j < tamDir)
    {
        dados[k] = D[j];
        j++;
        k++;
    }

    free(E);
    free(D);
    
}

void mergeRecursivo (int *dados, int inicio, int fim, int valorOrdenacao)
{
    if(inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeRecursivo(dados, inicio, meio, valorOrdenacao);
        mergeRecursivo(dados, meio + 1, fim, valorOrdenacao);

        merge(dados, inicio, meio, fim, valorOrdenacao);
    }
}

//Merge Sort - 0: Crescente; 1: Decrescente; 2: Aleatorio; 3: Concava; 4: Convexa
void mergeSort(int valorOrdenacao, int *dados, int qtdTotalLinhas)
{

    int meio = qtdTotalLinhas / 2;

    switch(valorOrdenacao)
    {
        //Ordem Crescente == 0
        case 0:
            mergeRecursivo(dados, 0, qtdTotalLinhas - 1, valorOrdenacao);
            break;

        //Ordem Decrescente == 1
        case 1:
            mergeRecursivo(dados, 0, qtdTotalLinhas - 1, valorOrdenacao);
            break;

        //Aleatoria == 2
        case 2:
            mergeRecursivo(dados, 0, qtdTotalLinhas - 1, valorOrdenacao);
            break;

        //Concava == 3
        case 3:
            mergeRecursivo(dados, 0, meio - 1, 1);
            mergeRecursivo(dados, meio, qtdTotalLinhas - 1, 0);
            break;

        //Convexa == 4
        case 4:
            mergeRecursivo(dados, 0, meio - 1, 0);
            mergeRecursivo(dados, meio, qtdTotalLinhas - 1, 1);
            break;

        default:
            break;
    }
}

int particionarQuickSort(int *dados, int inicio, int fim, int valorOrdenacao)
{
    int temp;
    int pivo = dados[fim];
    int i = (inicio - 1);

    for (int j = inicio; j < fim; j++)
    {
        bool condicao = false;

        if (valorOrdenacao == 0) {
            condicao = (dados[j] <= pivo);
        } else if (valorOrdenacao == 1) {
            condicao = (dados[j] >= pivo);
        } else if (valorOrdenacao == 2) {
            condicao = (rand() % 2 == 1);
        }

        if (condicao) 
        {
            i++;
            temp = dados[i];
            dados[i] = dados[j];
            dados[j] = temp;
        }
    }

    temp = dados[i + 1];
    dados[i + 1] = dados[fim];
    dados[fim] = temp;

    return (i + 1);
}

void quickRecursivo(int *dados, int inicio, int fim, int valorOrdenacao)
{
    if (inicio < fim) {
        int indicePivo = particionarQuickSort(dados, inicio, fim, valorOrdenacao);

        quickRecursivo(dados, inicio, indicePivo - 1, valorOrdenacao);
        quickRecursivo(dados, indicePivo + 1, fim, valorOrdenacao);
    }
}

//Quick Sort - 0: Crescente; 1: Decrescente; 2: Aleatorio; 3: Concava; 4: Convexa
void quickSort(int valorOrdenacao, int *dados, int qtdTotalLinhas)
{
    int meio = qtdTotalLinhas / 2;

    switch(valorOrdenacao)
    {
        //Ordem Crescente == 0
        case 0:
            quickRecursivo(dados, 0, qtdTotalLinhas - 1, valorOrdenacao);
            break;

        //Ordem Decrescente == 1
        case 1:
            quickRecursivo(dados, 0, qtdTotalLinhas - 1, valorOrdenacao);
            break;

        //Aleatoria == 2
        case 2:
            quickRecursivo(dados, 0, qtdTotalLinhas - 1, valorOrdenacao);
            break;

        //Concava == 3
        case 3:
            quickRecursivo(dados, 0, meio - 1, 1);
            quickRecursivo(dados, meio, qtdTotalLinhas - 1, 0);
            break;

        //Convexa == 4
        case 4:
            quickRecursivo(dados, 0, meio - 1, 0);
            quickRecursivo(dados, meio, qtdTotalLinhas - 1, 1);
            break;

        default:
            break;
    }
}

int main(int argc, char const *argv[])
{
    int opcaoMenu = -1;
    int subEscolha;

    int qtd = 0;
    int numDados = 1000;
    int opcaoOrdem = 0;
    int tipoOrdemDados = 0;
    bool duplicidadeDados = true;

    while (opcaoMenu != 404)
    {
        switch (opcaoMenu)
        {
            case -1:
            {
                printf("\n=========================================\n");
                printf("    ESCOLHA UMA DAS OPCOES A SEGUIR:      \n");
                printf("=========================================\n");
                printf(" 1. INICIAR ORDENACAO DE DADOS\n");
                printf(" 2. CONFIGURACOES DA ORDENACAO\n");
                printf(" 3. SAIR\n");
                printf("=========================================\n");
                printf("Escolha uma opcao (de 1 a 3): \n");
                scanf("%d", &opcaoMenu);
                break;
            }
            case 1:
                opcaoMenu = 7;
                break;
            
            case 2: 
            {
                printf("\n=========================================\n");
                printf("      ESCOLHA O TAMANHO DOS DADOS:        \n");
                printf("=========================================\n");
                printf(" 1. 1.000 DADOS;\n");
                printf(" 2. 5.000 DADOS;\n");
                printf(" 3. 10.000 DADOS;\n");
                printf(" 4. 100.000 DADOS;\n");
                printf(" 5. VOLTAR.\n");
                printf(" 6. SAIR.\n");

                printf("Escolha uma opcao (de 1 a 6): \n");
                scanf("%d", &subEscolha);
                    if (subEscolha == 1) {numDados = 1000; opcaoMenu = 4;}
                    else if (subEscolha == 2) {numDados = 5000; opcaoMenu = 4;}
                    else if (subEscolha == 3) {numDados = 10000; opcaoMenu = 4;}
                    else if (subEscolha == 4) {numDados = 100000; opcaoMenu = 4;}
                    else if (subEscolha == 5) opcaoMenu = -1;
                    else if (subEscolha == 6) opcaoMenu = 3;
                    else printf("Opcao invalida! Escolha entre 1 ao 6.\n");
                
                break;
            }

            case 3:
                printf("Encerrando...");
                return 0;
                break;

            case 4:
            {
                printf("\n=========================================\n");
                printf("    ESCOLHA A DUPLICIDADE DOS DADOS:      \n");
                printf("=========================================\n");
                printf(" 1. COM Duplicidade;\n");
                printf(" 2. SEM Duplicidade;\n");
                printf(" 3. VOLTAR.\n");
                printf(" 4. SAIR.\n");

                printf("Escolha uma opcao (de 1 a 4): \n");
                scanf("%d", &subEscolha);
                    if (subEscolha == 1) {duplicidadeDados = true; opcaoMenu = 5;}
                    else if (subEscolha == 2) {duplicidadeDados = false; opcaoMenu = 5;}
                    else if (subEscolha == 3) opcaoMenu = 2;
                    else if (subEscolha == 4) opcaoMenu = 3;
                    else printf("Opcao invalida! Escolha entre 1 ao 4.\n");
                break;
            }
            
            case 5:
            {
                printf("\n=========================================\n");
                printf(" ESCOLHA O TIPO DE ORDENACAO DOS DADOS:   \n");
                printf("=========================================\n");
                printf(" 1. BUBBLE SORT;\n");
                printf(" 2. MERGE SORT;\n");
                printf(" 3. QUICK SORT;\n");
                printf(" 4. VOLTAR.\n");
                printf(" 5. SAIR.\n");

                printf("Escolha uma opcao (de 1 a 5): \n");
                scanf("%d", &subEscolha);
                    if (subEscolha == 1) {tipoOrdemDados = 0; opcaoMenu = 6;}
                    else if (subEscolha == 2) {tipoOrdemDados = 1; opcaoMenu = 6;}
                    else if (subEscolha == 3) {tipoOrdemDados = 2; opcaoMenu = 6;}
                    else if (subEscolha == 4) opcaoMenu = 4;
                    else if (subEscolha == 5) opcaoMenu = 3;
                    else printf("Opcao invalida! Escolha entre 1 ao 5.\n");
                break;
            }
            
            case 6:
            {
                printf("\n=========================================\n");
                printf("        ESCOLHA A ORDEM DOS DADOS:        \n");
                printf("=========================================\n");
                printf(" 1. CRESCENTE;\n");
                printf(" 2. DECRESCENTE;\n");
                printf(" 3. ALEATORIO\n");
                printf(" 4. CONCAVA;\n");
                printf(" 5. CONVEXA;\n");
                printf(" 6. VOLTAR.\n");
                printf(" 7. SAIR.\n");

                printf("Escolha uma opcao (de 1 a 7): \n");
                scanf("%d", &subEscolha);
                    if (subEscolha == 1) {opcaoOrdem = 0; opcaoMenu = 7;}
                    else if (subEscolha == 2) {opcaoOrdem = 1; opcaoMenu = 7;}
                    else if (subEscolha == 3) {opcaoOrdem = 2; opcaoMenu = 7;}
                    else if (subEscolha == 4) {opcaoOrdem = 3; opcaoMenu = 7;}
                    else if (subEscolha == 5) {opcaoOrdem = 4; opcaoMenu = 7;}
                    else if (subEscolha == 6) opcaoMenu = 5;
                    else if (subEscolha == 7) opcaoMenu = 3;
                    else printf("Opcao invalida! Escolha entre 1 ao 7.\n");
                break;
            }
            
            case 7:
            {
                printf("\n=========================================\n");
                printf("        ORDENACAO DE DADOS INICIADA       \n");
                printf("=========================================\n");
                printf("Tamanho dos Dados: %d\n", numDados);
                printf("Duplicidade dos Dados: %s\n", duplicidadeDados ? "Com Duplicidade" : "Sem Duplicidade");
                printf("Tipo de Ordenacao: %s\n", tipoOrdemDados == 0 ? "Bubble Sort" : (tipoOrdemDados == 1 ? "Merge Sort" : "Quick Sort"));
                printf("Ordem dos Dados: %s\n", opcaoOrdem == 0 ? "Crescente" : (opcaoOrdem == 1 ? "Decrescente" : (opcaoOrdem == 2 ? "Aleatorio" : (opcaoOrdem == 3 ? "Concava" : "Convexa"))));
                opcaoMenu = 404;
                break;
            }

            default:
                opcaoMenu = -1;
                break;
        }
    }
    
    char (*dados)[TAM_LINHA] = malloc(numDados * sizeof(*dados));

    if (dados == NULL)
    {
        printf("Erro ao alocar memória para dados.\n");
        return 1;
    }

    //IMPRIME OS DADOS NA VARIÁVEL DADOS
    imprimirDados(numDados, duplicidadeDados, dados, &qtd);

    if (qtd > numDados) {
        printf("Aviso: 'qtd' (%d) maior que 'numDados' (%d). Ajustando limite para evitar crash.\n", qtd, numDados);
        qtd = numDados;
    }

    int *valor = malloc(qtd * sizeof(*valor));
    if (valor == NULL)
    {
        printf("Erro ao alocar memória para valor.\n");
        return 1;
    }

    //STRING DADOS PARA INT VALOR
    for (int i = 0; i < qtd; i++) {
        valor[i] = (int)strtol(dados[i], NULL, 10);
    }
    
    switch (tipoOrdemDados) {
        case 0:
            printf("Executando Bubble Sort...\n");
            bubbleSort(opcaoOrdem, valor, qtd);
            break;
        case 1:
            printf("Executando Merge Sort...\n");
            mergeSort(opcaoOrdem, valor, qtd);
            break;
        case 2:
            printf("Executando Quick Sort...\n");
            quickSort(opcaoOrdem, valor, qtd);
            break;
        default:
            printf("Tipo de ordenacao invalido.\n");
            return 1;
    }

    //PRINT DOS DADOS.
    for (int i = 0; i < qtd; i++) {
        //printf("[%d]: %d\n", i, valor[i]);
        printf("%d\n", valor[i]);
    }

    //APENAS QUANDO O USUARIO SAIR DO PROGRAMA DÁ FREE NOS DADOS
    free(dados);
    free(valor);
    return 0;
}