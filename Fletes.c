#include <stdio.h>
#include <string.h>

int carga(char [][8], char [][61], int);
int ingfletes(char[][8],float[][30],int [],int [],int);
int validarIR (int, int);
int buscar(char [][8],char[], int);
float validarFV (int);
void ListadoRecau (char[][8],float[][30],int);
void Orden(char [][61],int [],int);
void ListadoCantidad(char[][61], int[],int);
void mostrardia1(char [][8],int [],int );

int main ()
{
    int cant,maxpos;
    int cantviajes[10]={0};
    int vdia1[10]={0};
    float recaudacion[10][30]={{0}};
    char patente [10][8], apeynom[10][61];

    cant=carga(patente,apeynom,10);
    if (cant!=0)
    {
        maxpos=ingfletes(patente,recaudacion,cantviajes,vdia1,10);
        ListadoRecau(patente,recaudacion,cant);
        Orden(apeynom,cantviajes,cant);
        ListadoCantidad(apeynom,cantviajes,cant);
        printf("\n\nVEHICULO QUE REALIZO MAS FLETES: %s", patente[maxpos]);
        mostrardia1(patente,vdia1,cant);
    }
    else
        printf("\n-NO SE INGRESARON DATOS-");

    getch ();
    return 0;
}

int carga(char pats[][8], char apeynom [][61], int ce)
{
    int i, pos;
    char patt[8], ayn[61];
    i=0;
    printf("-INGRESE LOS DATOS DE LOS VEHICULOS-\n(patente = 'fin' para finalizar)");
    printf("\n\n-VEHICULO %d-",i+1);
    printf("\nPATENTE:");
    fflush(stdin);
    gets(patt);
    while (!((strcmpi(patt,"fin")==0) || i>=ce))
    {
        strcpy(pats[i],patt);
        printf("APELLIDO Y NOMBRE DEL PROPIETARIO: ");
        fflush(stdin);
        gets(ayn);
        strcpy(apeynom[i],ayn);
        i++;
        printf("\n-VEHICULO %d-",i+1);
        do
        {
            printf("\nPATENTE:");
            fflush(stdin);
            gets(patt);
            pos=buscar(pats,patt,10);
            if (pos!=-1)
            {
                printf("\nLa patente ingresada ya existe. Por favor reintentar.\n");
            }
        } while (!(pos==-1));
    }
    printf("\n----INGRESO DE DATOS DE VEHICULOS FINALIZADO----\n");
    return i;
}

int ingfletes(char patentes[][8],float recaudacion[][30],int cantviajes[],int vdia1[],int cf)
{
    int i, dia,pos,max,maxpos;
    float importe;
    char patt[8];
    i=0;

    printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
    printf("\n\n-INGRESE LOS DATOS DE LOS FLETES DEL MES-");
    printf("\n\nVIAJE %d",i+1);
    printf("\nDIA DEL FLETE: ");
    dia=validarIR(0,30);

    while (!(dia==0))
    {
        printf("PATENTE: ");
        do
        {
            fflush(stdin);
            gets(patt);
            pos=buscar(patentes,patt,10);
            if (pos==-1)
                printf("\nPatente inexistente. Reintentar: ");
        } while (!(pos!=-1));
        printf("IMPORTE: $");
        importe=validarFV (0);
        if (dia>15)
            importe=importe*0.95;
        recaudacion[pos][dia-1]+=importe;
        cantviajes[pos]++;
        i++;
        printf("\nVIAJE %d",i+1);
        printf("\nDIA DEL FLETE (ingrese 0 para finalizar): ");
        dia=validarIR(0,30);
    }
    for (i=0;i<cf;i++)
    {
        if (i==0 || cantviajes[i]>max)
        {
            max=cantviajes[i];
            maxpos=i;
        }
    }
    for(i=0;i<cf;i++)
    {
        if (recaudacion[i][0]!=0)
            vdia1[i]=1;
    }
    printf("\n----INGRESO DE DATOS DE FLETES DEL MES FINALIZADO----\n");
    printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");

    return maxpos;
}

int validarIR (int desde, int hasta)
{
    int dato,b;
    b=0;
    do
    {
        if (b!=0)
            printf("\nERROR. Por favor reintentar: ");
        else
            b=1;
        scanf("%d", &dato);
    } while (!(dato>=desde && dato<=hasta));
    return dato;
}

int buscar(char patentes[][8],char buscado[], int cf)
{
    int pos, i;
    i=0;
    pos=-1;
    while (!(pos!=-1 || i>=cf))
    {
        if (strcmpi(patentes[i],buscado)==0)
            pos=i;
        else
            i++;
    }
    return pos;
}

float validarFV (int desde)
{
    int b;
    float dato;
    b=0;
    do
    {
        if (b!=0)
            printf("\nERROR. Por favor reintentar: ");
        else
            b=1;
        scanf("%f", &dato);
    } while (!(dato>=desde));
    return dato;
}

void ListadoRecau (char patentes[][8],float rec[][30],int cc)
{
    int i,j;
    printf("\n\nLISTADO DE RECAUDACION\n");
    printf("\nPATENTE");
    for (i=0;i<cc;i++)
    {
        printf("\t\t %s",patentes[i]);
    }
    for (i=0;i<30;i++)
    {
        printf("\nDIA %d",i+1);
        for (j=0;j<cc;j++)
            printf(" \t\t$%.2f",rec[j][i]);
    }
}

void Orden(char apeynom[][61],int cantviajes[],int cant)
{
    int aux1,ce,i,b;
    char aux2[61];

    ce=cant;
    b=1;

    while (!(b==0))
    {
        b=0;
        for(i=1;i<=ce;i++)
        {
            if (cantviajes[i-1]<cantviajes[i])
            {
                aux1=cantviajes[i-1];
                cantviajes[i-1]=cantviajes[i];
                cantviajes[i]=aux1;

                strcpy(aux2,apeynom[i-1]);
                strcpy(apeynom[i-1],apeynom[i]);
                strcpy(apeynom[i],aux2);

                b=i;
            }
        }
        ce=b;
    }
}

void ListadoCantidad(char apeynom[][61], int cantviajes[],int cf)
{
    int i;
    printf("\n\n\nLISTADO DE VIAJES\n");
    printf("\nPROPIETARIO\t\tVIAJES");
    for (i=0;i<cf;i++)
    {
        printf("\n%s\t\t  %d",apeynom[i],cantviajes[i]);
    }
}

void mostrardia1(char patente[][8],int vdia1[],int ce)
{
    int i;
    printf("\n\nVEHICULOS QUE NO REALIZARON FLETES EL DIA 1:");
    for(i=0;i<ce;i++)
        if (vdia1[i]==0)
        {
            printf("\n-%s",patente[i]);
        }
}
