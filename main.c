#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINHAS 1000
#define TAM_LINHA 256

int main(int argc, char const *argv[])
{

    char dados[MAX_LINHAS][TAM_LINHA];
    char buffer[TAM_LINHA];
    int qtd = 0;
    int numDados;
    bool duplicidadeDados;

    switch (numDados)
    {
        case 1000:

            if (duplicidadeDados)
            {
                //ALTERAR ISSO PARA CRIAR UMA FUNÇÃO QUE TEM NO PARAMETRO O LOCAL DO ARQUIVO
                //TIPO void LerDados(true, "Dados/1k/Com Duplicidade...") <- 1-bool duplicidadeDados 2-str localArquivo
                //MAS A FUNÇÃO COMEÇA LÁ NO SWITCH
                FILE *dados1kComDuplicidade = fopen("Dados/1k/Com Duplicidade/Aleatorio/dtaleat1kdup3.txt", "r");

                if(dados1kComDuplicidade == NULL)
                {
                    printf("Erro ao abrir o arquivo com 1000 dados (Com Duplicidade).\n");
                    return 1;
                }

                while (fgets(buffer, sizeof(buffer), dados1kComDuplicidade) != NULL) {
                    buffer[strcspn(buffer, "\n")] = '\0';

                    char *inicio = buffer;

                    while (isspace((unsigned char)*inicio)) {
                        inicio++;
                    }

                    if (strlen(inicio) == 0) {
                        continue;
                    }

                    strcpy(dados[qtd], inicio);
                    qtd++;
                }

                fclose(dados1kComDuplicidade);
                
                printf("Linhas armazenadas:\n");
                for (int i = 0; i < qtd; i++) {
                    printf("%s\n", dados[i]);
                }

            } else {
                FILE *dados1kSemDuplicidade = fopen("Dados/1k/Sem Duplicidade/Aleatвrio/dtaleat1kuni3.txt", "r");

                if(dados1kSemDuplicidade == NULL)
                {
                    printf("Erro ao abrir o arquivo com 1000 dados (Sem Duplicidade).\n");
                    return 1;
                }

                while (fgets(buffer, sizeof(buffer), dados1kSemDuplicidade) != NULL) {
                    buffer[strcspn(buffer, "\n")] = '\0';

                    char *inicio = buffer;

                    while (isspace((unsigned char)*inicio)) {
                        inicio++;
                    }

                    if (strlen(inicio) == 0) {
                        continue;
                    }

                    strcpy(dados[qtd], inicio);
                    qtd++;
                }

                fclose(dados1kSemDuplicidade);
            }

            break;
        
        case 5000:

            if (duplicidadeDados)
            {
                FILE *dados1kComDuplicidade = fopen("Dados/5k/Com Duplicidade/Aleatorio/dtaleat5kdup3.txt", "r");

                if(dados1kComDuplicidade == NULL)
                {
                    printf("Erro ao abrir o arquivo com 1000 dados (Com Duplicidade).\n");
                    return 1;
                }

                while (fgets(buffer, sizeof(buffer), dados1kComDuplicidade) != NULL) {
                    buffer[strcspn(buffer, "\n")] = '\0';

                    char *inicio = buffer;

                    while (isspace((unsigned char)*inicio)) {
                        inicio++;
                    }

                    if (strlen(inicio) == 0) {
                        continue;
                    }

                    strcpy(dados[qtd], inicio);
                    qtd++;
                }

                fclose(dados1kComDuplicidade);
                
                printf("Linhas armazenadas:\n");
                for (int i = 0; i < qtd; i++) {
                    printf("%s\n", dados[i]);
                }

            } else {
                FILE *dados1kSemDuplicidade = fopen("Dados/5k/Sem Duplicidade/Aleatorio/dtaleat5kuni3.txt", "r");

                if(dados1kSemDuplicidade == NULL)
                {
                    printf("Erro ao abrir o arquivo com 1000 dados (Sem Duplicidade).\n");
                    return 1;
                }

                while (fgets(buffer, sizeof(buffer), dados1kSemDuplicidade) != NULL) {
                    buffer[strcspn(buffer, "\n")] = '\0';

                    char *inicio = buffer;

                    while (isspace((unsigned char)*inicio)) {
                        inicio++;
                    }

                    if (strlen(inicio) == 0) {
                        continue;
                    }

                    strcpy(dados[qtd], inicio);
                    qtd++;
                }

                fclose(dados1kSemDuplicidade);
            }

            break;
        
        default:
            break;
    }
    
    //Bubble Sort c/ Duplicidade
    //Bubble Sort s/ Duplicidade

    //Merge Sort c/Duplicidade
    //Merge Sort s/Duplicidade

    //Quick Sort c/ Duplicidade
    //Quick Sort s/ Duplicidade

    return 0;
}

//Bubble Sort
void bubbleSort(int valorOrdenacao, bool duplicidade)
{
    if (duplicidade)
    {
        switch(valorOrdenacao)
        {
            //Ordem Crescente == 0
            case 0:
                

            //Ordem Decrescente == 1
            case 1:

            //Aleatória == 2
            case 2:

            //Côncava == 3
            case 3:

            //Convexa == 4
            case 4:

            default:
                break;
        }
    }
    else
    {
        switch(valorOrdenacao)
        {
            //Ordem Crescente == 0
            case 0:
                

            //Ordem Decrescente == 1
            case 1:

            //Aleatória == 2
            case 2:

            //Côncava == 3
            case 3:

            //Convexa == 4
            case 4:

            default:
                break;
        }
    }
    
    

}

