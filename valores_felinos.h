#ifndef VALORES_FELINOS_H_INCLUDED
#define VALORES_FELINOS_H_INCLUDED
struct valores_felinos
{
    char gatos[21];
    int idades;
    float pesos;
};
typedef struct valores_felinos TabelaFelina;

void mostre_valor_nutr(TabelaFelina vn)
{
    printf("  %-20s %3d   %.2f g\n", vn.gatos, vn.idades, vn.pesos);
}

int campo_nome(const void *a, const void *b)
{
    TabelaFelina *vna = (TabelaFelina *) a;
    TabelaFelina *vnb = (TabelaFelina *) b;
    return strcmp(vna->gatos, vnb->gatos);
}

int campo_idade(const void *a, const void *b)
{
    TabelaFelina *vna = (TabelaFelina *) a;
    TabelaFelina *vnb = (TabelaFelina *) b;
    return vna->idades - vnb->idades;
}

int campo_peso(const void *a, const void *b)
{
    TabelaFelina *vna = (TabelaFelina *) a;
    TabelaFelina *vnb = (TabelaFelina *) b;
    int va = (int) (vna->pesos * 100);
    int vb = (int) (vnb->pesos * 100);
    return va - vb;
}


#endif // VALORES_FELINOS_H_INCLUDED
