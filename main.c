#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "auxiliares.h"
#include "valores_felinos.h"
#include "lista_felina.h"
#include <locale.h>

int menu_principal()
{
    caracteres(66, '='); printf("\n");
    setlocale(LC_ALL, "Portuguese");
    printc("Tabela de Informações Felinas", 66);  printf("\n");
    caracteres(66, '='); printf("\n");
    printf("  1 - Mostrar gatos\n");
    printf("  2 - Inserir novos gatos\n");
    printf("  3 - Buscar gato pelo Nome\n");
    printf("  4 - Excluir gato\n");
    printf("  ----------------------\n");
    printf("  0 - Sair do Aplicativo\n");
    printf("\n  Escolha uma Opção: ", 135, 198);
    fflush(stdin);
    return getchar();
}

int submenu()
{
    //limpa_tela();
    caracteres(66, '='); printf("\n");
    printc("Tabela de Informações Felinas", 66); printf("\n");
    caracteres(66, '='); printf("\n");
    printf("  1 - Ordenados pelo Nome\n");
    printf("  2 - Ordenados pela Idade\n");
    printf("  3 - Ordenados pelo Peso\n", 161);
    printf("  ----------------------------\n");
    printf("  0 - Voltar ao menu principal\n");
    printf("\n  Escolha uma Opção: ", 135, 198);
    fflush(stdin);
    return getchar();
}

void inserir_gato(TabelaListaFelinos *lis)
{
    limpa_tela();
    TabelaFelina vn;
    printf("  Nome do gato: ");
    fflush(stdin);
    gets(vn.gatos);
    printf("  Idade do gato: ");
    vn.idades = le_inteiro();
    printf("  Peso do gato: ", 161);
    //vn.pesos = le_real();
    scanf("%f", &vn.pesos);
    inserir_lista_felinos(lis, vn);
}

void buscar_gato(TabelaListaFelinos lis)
{
    int rb;
    char nome[21];
    limpa_tela();
    printf("  Nome do gato: ");
    fflush(stdin);
    gets(nome);
    rb = busca_lis_vn(lis, nome);
    if(rb < 0)
        printf("  gato não cadastrado\n", 198);
    else {
        mostre_valor_nutr(lis.valores[rb]);
    }
}

void excluir_gato(TabelaListaFelinos *lis)
{
    int rb;
    char nome[21];
    printf("  Nome do gato: ");
    fflush(stdin);
    gets(nome);
    rb = busca_lis_vn(*lis, nome);
    if(rb < 0)
        printf("  gato não cadastrado\n", 198);
    else {
        remove_lis_vn(lis, rb);
    }
}

int main()
{
    TabelaListaFelinos lis_vn;
    carrega_lis_vn(&lis_vn);

    char op, op2;
    while(1)
    {
        op = menu_principal();
        if (op == '0')
        {
            salva_lis_vn(lis_vn);
            printf("arquivos salvos com sucesso...");
            printf("\n  ** Fim do aplicativo **");
            sleep(3);
            break;
        }
        switch(op)
        {
            case '1':
                while(1)
                {
                    op2 = submenu();
                    if (op2 == '0')
                    {
                        break;
                    }
                    switch(op2)
                    {
                        case '1':
                            caracteres(66, '-'); printf("\n");
                            printc("Ordenados pelo nome",66); printf("\n");
                            caracteres(66, '-'); printf("\n");
                            qsort(lis_vn.valores, lis_vn.num_ele, sizeof(TabelaFelina), campo_nome);
                            mostra_lista_felina(lis_vn);
                            break;
                        case '2':
                            caracteres(66, '-'); printf("\n");
                            printc("Ordenados pela idade",66); printf("\n");
                            caracteres(66, '-'); printf("\n");
                            qsort(lis_vn.valores, lis_vn.num_ele, sizeof(TabelaFelina), campo_idade);
                            mostra_lista_felina(lis_vn);
                            break;
                        case '3':
                            caracteres(66, '-'); printf("\n");
                            printc("Ordenadas pelo Peso",66); printf("\n");
                            caracteres(66, '-'); printf("\n");
                            qsort(lis_vn.valores, lis_vn.num_ele, sizeof(TabelaFelina), campo_peso);
                            mostra_lista_felina(lis_vn);
                            break;
                        case '4':
                            caracteres(66, '-'); printf("\n");
                            printc("Opção 4 do Submenu",66); printf("\n");
                            caracteres(66, '-'); printf("\n");
                            // Insira seu código aqui
                            break;
                        default:
                            printf("\n\n  *** Op%c%co inv%clida ***\n\n",135,198,160);
                    }
                }
                break;
            case '2':
                caracteres(66, '-'); printf("\n");
                printc("T\xa1tulo da Opção 2", 66); printf("\n");
                caracteres(66, '-'); printf("\n");
                inserir_gato(&lis_vn);
                break;
            case '3':
                caracteres(66, '-'); printf("\n");
                printc("T\xa1tulo da Opção 3", 66); printf("\n");
                caracteres(66, '-'); printf("\n");
                buscar_gato(lis_vn);
                break;
            case '4':
                caracteres(66, '-'); printf("\n");
                printc("T\xa1tulo da Opção 4", 66); printf("\n");
                caracteres(66, '-'); printf("\n");
                excluir_gato(&lis_vn);
                break;
            default:
                printf("\n\n  *** Opção inválida ***\n\n",135,198,160);
        }
    }
    return 0;
}
