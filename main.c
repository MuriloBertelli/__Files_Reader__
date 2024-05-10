#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NUMEROS 20

// Função para abrir um arquivo
FILE *abrirArquivo(const char *nome, const char *modoAcesso)
{
    FILE *arquivo = fopen(nome, modoAcesso);

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s!!!\n", nome);
        exit(1);
    }
    return arquivo;
}
// Função para escrever um vetor em um arquivo
void escreverVetor(FILE *arquivo, int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        fprintf(arquivo, "%d ", vetor[i]);
    }
}

// Função para calcular estatísticas dos números no vetor
void gerarStatitica(int vetor[], int tamanho)
{
    int positivos = 0, negativos = 0, zero = 0, pares = 0, impares = 0;
    FILE *arquivo = abrirArquivo("estatisticas.txt", "w");

    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] > 0)
            positivos++;
        else if (vetor[i] < 0)
            negativos++;
        else
            zero++;
        if (vetor[i] % 2 == 0)
            pares++;
        else
            impares++;
    }

    fprintf(arquivo, "Quantidade de numeros positivos: %d\n", positivos);
    fprintf(arquivo, "Quantidade de numeros negativos: %d\n", negativos);
    fprintf(arquivo, "Quantidade de numeros zero: %d\n", zero);
    fprintf(arquivo, "Quantidade de numeros pares: %d\n", pares);
    fprintf(arquivo, "Quantidade de numeros impares: %d\n", impares);

    fclose(arquivo);
}

// Função para ordenar o vetor
void ordenaVet(int vetor[], int tamanho)
{
    int temp;
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            if (vetor[j] < vetor[j + 1])
            {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Função para encontrar números distintos e escrevê-los em um arquivo
void encontrarDist(int vetor[], int tamanho)
{
    FILE *arquivo = abrirArquivo("distintos.txt", "w");

    for (int i = 0; i < tamanho; i++)
    {
        bool repetido = false;
        for (int j = 0; j < i; j++)
        {
            if (vetor[i] == vetor[j])
            {
                repetido = true;
                break;
            }
        }
        if (!repetido)
        {
            fprintf(arquivo, "%d ", vetor[i]);
        }
    }
    fclose(arquivo);
}

void encontraDistOrd(int vetor[], int tamanho)
{
    ordenaVet(vetor, tamanho);
    FILE *arquivo = abrirArquivo("distintos_ordenado.txt", "w");

    for (int i = 0; i < tamanho; i++)
    {
        bool repetido = false;
        for (int j = 0; j < i; j++)
        {
            if (vetor[i] == vetor[j])
            {
                repetido = true;
                break;
            }
        }
        if (!repetido)
        {
            fprintf(arquivo, "%d ", vetor[i]);
        }
    }
    fclose(arquivo);
}

// Programa principal
int main()
{
    int quantidade;
    int numeros[MAX_NUMEROS];
    FILE *arquivo;

    arquivo = abrirArquivo("dados.txt", "r");
    fscanf(arquivo, "%d", &quantidade);
    if (quantidade > MAX_NUMEROS)
    {
        printf("A quantidade de numeros é maior do que a capacidade do vetor!\n");
        fclose(arquivo);
        exit(1);
    }

    for (int i = 0; i < quantidade; i++)
    {
        fscanf(arquivo, "%d", &numeros[i]);
    }

    fclose(arquivo);

    gerarStatitica(numeros, quantidade);

    encontrarDist(numeros, quantidade);

    encontraDistOrd(numeros, quantidade);

    arquivo = abrirArquivo("ordenado.txt", "w");
    escreverVetor(arquivo, numeros, quantidade);
    fclose(arquivo);

    return 0;
}
