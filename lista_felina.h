#ifndef LISTA_FELINA_H_INCLUDED
#define LISTA_FELINA_H_INCLUDED
struct lista_felina
{
    int num_ele;
    TabelaFelina valores[50];
};
typedef struct lista_felina TabelaListaFelinos;

void inserir_lista_felinos(TabelaListaFelinos *lis, TabelaFelina val)
{
    lis->valores[lis->num_ele] = val;
    lis->num_ele++;
}

void mostra_lista_felina(TabelaListaFelinos lis)
{
    int i;
    limpa_tela();
    for(i=0; i<lis.num_ele; i++)
        mostre_valor_nutr(lis.valores[i]);
}

int busca_lis_vn(TabelaListaFelinos lis, char *gato)
{
    int i;
    for(i=0; i<lis.num_ele; i++)
        if(strcmp(gato, lis.valores[i].gatos) == 0)
            return i;
    return -1;
}

TabelaFelina remove_lis_vn(TabelaListaFelinos *lis, int ind)
{
    int i;
    TabelaFelina res = lis->valores[ind];
    for(i=ind; i<lis->num_ele-1; i++)
        lis->valores[i] = lis->valores[i+1];
    lis->num_ele--;
    return res;
}

void altera_lis_vn(TabelaListaFelinos *lis, int ind, TabelaFelina novo_val)
{
    lis->valores[ind] = novo_val;
}

void salva_lis_vn(TabelaListaFelinos lis)
{
    FILE *fp = fopen("tabelaFelinos.arq", "wb");
    fwrite(&lis.num_ele, sizeof(int), 1, fp);
    fwrite(lis.valores, sizeof(TabelaFelina), lis.num_ele, fp);
    fclose(fp);
}

void carrega_lis_vn(TabelaListaFelinos *lis)
{
    FILE *fp = fopen("tabelaFelinos.arq", "rb");
    fread(&lis->num_ele, sizeof(int), 1, fp);
    fread(lis->valores, sizeof(TabelaFelina), lis->num_ele, fp);
    fclose(fp);
}





#endif // LISTA_FELINA_H_INCLUDED
