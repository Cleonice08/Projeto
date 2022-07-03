#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>

struct prefeitura
{
    char nome[32];
    int codigo;
    int totalFuncionarios;
    float arrecadacao;
    int E;
}f;

FILE *fptr;

void cadastro();
void consulta();
void consulta_todas_prefeituras();
void consultaPrefeiturasPorTotalFuncionario(int);
void alteracao();
void exclusao_logica();
void exclusao_fisica();
void ordenacao_codigo();
void recuperarBkpPrefeituras();
int busca_binaria();

int main()
{   char op;
    int codigo,pos;
    do
    {
        printf("\n 1-Cadastro");
        printf("\n 2-Consulta");
        printf("\n 3-Consultar Prefeituras com 2000 ou mais funcionarios");
        printf("\n 4-Alteracao");
        printf("\n 5-Exc. Logica");
        printf("\n 6-Exc. Fisica");
        printf("\n 7-Ordenacao Codigo Ordem Decrecente");
        printf("\n 8-Busca Binaria");
        printf("\n 9- Recuperar Backup das Prefeituras");
        printf("\n s-Sair \n");
        op=getche();
        switch (op)
        {
            case '1':cadastro();
            break;
            case '2':consulta();
            break;
            case '3': consultaPrefeiturasPorTotalFuncionario(2000);
            break;
            case '4':alteracao();
            break;
            case '5':exclusao_logica();
            break;
            case '6':exclusao_fisica();
            break;
            case '7':ordenacao_codigo();
            break;
            case '8':
            printf("\n Digite o codigo a ser procurado: ");
            scanf("%d",&codigo);
            pos=busca_binaria(codigo);
            if(pos==-1)
                printf("\n Codigo nao encontrado");
            else {
             consulta_todas_prefeituras();
             printf("\n Codigo %d esta no registro %d",codigo,pos + 1);
            }
            break;
            case '9': recuperarBkpPrefeituras();
            break;
            case 's':printf("\n Saindo...");
            break;

        }
    } while (op != 's');
    return 0;
}
void cadastro ()
{
    char opc;
    if((fptr=fopen("prefeitura.bi","rb+"))== NULL)
    {
        if((fptr=fopen("prefeitura.bi","wb"))== NULL)
        {
            printf("\n Erro");
            exit(1);
        }
    }
    do
    {
    printf("\n Nome:");
    setbuf(stdin,NULL);
    scanf("%[^\n]",&f.nome);
    printf("\n Codigo:");
    scanf("%d",&f.codigo);
    printf("\n Total de Funcionarios:");
    scanf("%d",&f.totalFuncionarios);
    printf("\n Arrecadacao:");
    scanf("%f",&f.arrecadacao);
    f.E=0;
    fseek(fptr,0,2);
    fwrite(&f,sizeof(f),1,fptr);
    printf("\n Deseja cadastrar outro(S/N)?");
    opc=getche();
    } while ((opc=='S')||(opc=='s'));
    fclose(fptr);
}

void consulta()
{
    if((fptr=fopen("prefeitura.bi","rb"))== NULL)
    {
        printf("Erro");
        exit(1);
    }
    fseek (fptr,0,0);
    printf("\n ------------- PREFEITURAS --------------- \n");
    while (fread(&f,sizeof(f),1,fptr))
    {
        if (f.E==0)
        {
            printf("\n Nome:%s",f.nome);
            printf("\n Codigo:%d",f.codigo);
            printf("\n Total de Funcionarios:%d",f.totalFuncionarios);
            printf("\n Arrecadacao:%.2f",f.arrecadacao);

            printf("\n ------------------------------- \n");
        }
    }
    fclose(fptr);
    printf("\n ----------------------------------------- \n");
}

void consulta_todas_prefeituras()
{
    if((fptr=fopen("prefeitura.bi","rb"))== NULL)
    {
        printf("Erro");
        exit(1);
    }
    fseek (fptr,0,0);
    printf("\n ------------- PREFEITURAS --------------- \n");
    while (fread(&f,sizeof(f),1,fptr))
    {
        if (f.E == 1) {
            printf("\n REGISTRO REMOVIDO LOGICAMENTE");
        }

        printf("\n Nome:%s",f.nome);
        printf("\n Codigo:%d",f.codigo);
        printf("\n Total de Funcionarios:%d",f.totalFuncionarios);
        printf("\n Arrecadacao:%.2f",f.arrecadacao);

        printf("\n ------------------------------- \n");

    }
    fclose(fptr);
    printf("\n ----------------------------------------- \n");
}

void consultaPrefeiturasPorTotalFuncionario(int totalFuncionarios)
{
    if((fptr=fopen("prefeitura.bi","rb"))== NULL)
    {
        printf("Erro");
        exit(1);
    }
    fseek (fptr,0,0);
    printf("\n --- PREFEITURAS COM 2000 OU MAIS FUNCIONARIOS --- \n");
    while (fread(&f,sizeof(f),1,fptr))
    {
        if (f.E==0)
        {
            if(f.totalFuncionarios >= totalFuncionarios) {
                printf("\n Nome:%s",f.nome);
                printf("\n Codigo:%d",f.codigo);
                printf("\n Total de Funcionarios:%d",f.totalFuncionarios);
                printf("\n Arrecadacao:%.2f",f.arrecadacao);

                printf("\n ------------------------------- \n");
            }

        }
    }
    fclose(fptr);
    printf("\n ----------------------------------------- \n");
}

void alteracao()
{
    int codaux;
    if((fptr=fopen("prefeitura.bi","rb+"))== NULL)
    {
        printf("\n Erro");
        exit (1);
    }
    printf("\n Entre com o codigo da prefeitura para alterar seus dados:");
    scanf("%d",&codaux);
    while (fread(&f,sizeof(f),1,fptr))
    {
        if (f.E==0)
        {
            if(f.codigo== codaux)
            {
                printf("\n Nova Quantidade de funcionarios:");
                scanf("%d",&f.totalFuncionarios);

                printf("\n Nova Arrecadacao:");
                scanf("%f",&f.arrecadacao);
                fseek(fptr,ftell(fptr)-sizeof(f),0);
                fwrite(&f,sizeof(f),1,fptr);
                fseek(fptr,0,2);
            }
        }
    }
    fclose(fptr);
}

void exclusao_logica(){

	int codaux;

	if((fptr = fopen("prefeitura.bi", "rb+"))==NULL){
		printf("\n Erro");
		exit(1);
	}

	printf ("\n Entre com o codigo da prefeitura para exclui-la: ");
	scanf("%d", &codaux);

	while(fread(&f, sizeof(f), 1, fptr)){
		if(f.E == 0){
			if(f.codigo == codaux){
				f.E = 1;

				fseek(fptr, ftell(fptr)-sizeof(f), 0);
				fwrite(&f, sizeof(f), 1, fptr);
				fseek(fptr, 0, 2);
			}
		}
	}

	 fclose(fptr);
}

void exclusao_fisica ()
{
    FILE *fptrback,*fptraux;
    int codaux;

    if((fptr=fopen("prefeitura.bi","rb"))== NULL)
    {
        printf("\n Erro");
        exit(1);
    }

    if((fptrback=fopen("back.bi","rb+"))== NULL)
    {
        if ((fptrback=fopen("back.bi","wb"))== NULL)
        {
            printf("\n Erro");
            exit(1);
        }
    }

    if ((fptraux=fopen("auxiliar.bi","wb+"))== NULL)
    {
        printf("\n Erro");
        exit(1);
    }

	printf("\n REMOVENDO PREFEITURAS... ");
    while (fread(&f,sizeof(f),1,fptr))
    {
        if (f.E == 0) {
            fseek(fptraux,0,2);
            fwrite(&f,sizeof(f),1,fptraux);
        }else {
            fseek(fptrback,0,2);
            fwrite(&f,sizeof(f),1,fptrback);
        }
    }

    fclose(fptr);
    fclose(fptraux);
    fclose(fptrback);

    remove("prefeitura.bi");
    rename("auxiliar.bi","prefeitura.bi");

    printf("\n PREFEITURAS REMOVIDAS COM SUCESSO! ");
}

void ordenacao_codigo ()
{
    int N,I,J;
    struct prefeitura fi,fj;
    if ((fptr=fopen("prefeitura.bi","rb+"))==NULL)
    {
        printf("\n Erro");
        exit(1);
    }
    fseek(fptr,0,2);
    N=ftell(fptr)/sizeof(f);
    for(I=0;I<N-1;I++)
        for(J=I+1;J<N;J++)
    {
        fseek(fptr,I*sizeof(f),0);
        fread(&fi,sizeof(f),1,fptr);
        fseek(fptr,J*sizeof(f),0);
        fread(&fj,sizeof(f),1,fptr);
        if(fi.codigo<fj.codigo)
        {
           fseek(fptr,I*sizeof(f),0);
           fwrite(&fj,sizeof(f),1,fptr);
           fseek(fptr,J*sizeof(f),0);
           fwrite(&fi,sizeof(f),1,fptr);
        }
    }
    fclose(fptr);
}

int binaria(int elem, int N, int A[100])
{   struct prefeitura fmid;
    int mid,low,high;
    low=0;
    high=N-1;
    while (low<=high)
    {
        mid=(low+high)/2;
        if(fmid.codigo>elem)high=mid-1;
        else if (A[mid]<elem) low=mid+1;
        else return mid;
    }
    return -1;
}

int busca_binaria (int codigo)
{
    ordenacao_codigo();

    struct prefeitura fmid;
    int mid,low,high,N;
    if ((fptr=fopen("prefeitura.bi","rb"))== NULL)
    {
        printf("\n Erro");
        exit(1);
    }
    fseek(fptr,0,2); N=ftell(fptr)/sizeof(f);low=0;high=N-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        fseek(fptr,mid*sizeof(f),0);
        fread(&fmid,sizeof(f),1,fptr);

        if(fmid.codigo < codigo)
            high=mid-1;
        else if(fmid.codigo>codigo)
        low=mid+1;
        else {
            fclose(fptr);
            return mid;
        }
    }

    fclose(fptr); return -1;
}

void recuperarBkpPrefeituras() {

    FILE *fptrback, *fptr;

    if ((fptrback=fopen("back.bi","rb"))== NULL)
    {
        printf("\n Nao existe BKP's de prefeituras");
        return;
    }

    if ((fptr=fopen("prefeitura.bi","ab"))== NULL)
    {
        printf("\n Erro");
        exit(1);
    }

    int opcao = 0;
    while(opcao < 1 || opcao > 2) {
        printf("\n Deseja manter os registros como 'REMOVIDOS LOGICAMENTE' ? 1 - SIM | 2 - NAO: ");
        scanf("%d", &opcao);
    }

    printf("\n Recuperando BKP ...");

    if(opcao == 1) {
        while(fread(&f, sizeof(f), 1, fptrback)) {
            fseek(fptr,0,2);
            fwrite(&f,sizeof(f),1,fptr);
        }
    } else {
        while(fread(&f, sizeof(f), 1, fptrback)) {
            fseek(fptr,0,2);
            f.E = 0;
            fwrite(&f,sizeof(f),1,fptr);
        }
    }

    fclose(fptrback);
    fclose(fptr);

    remove("back.bi");
    printf("\n BKP Recuperado com sucesso!");
}
