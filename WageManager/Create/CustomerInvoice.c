<<<<<<< HEAD
#include <stdio.h>

char *createInvoice(int INum, char CNum[]){
char invoiceNum[10];
static char filePath[100];
sprintf(invoiceNum, "%d", INum);
strcat(filePath, "./Database/Invoice/");
strcat(filePath, invoiceNum);
strcat(filePath, "_");
strcat(filePath, CNum);
strcat(filePath, ".txt");
FILE *fp = fopen(filePath, "w");
fclose(fp);

FILE *fil = fopen("./Database/Setting/Invoice.ini", "w");

fprintf(fil, "%d",INum+1);
fclose(fil);

return filePath;
}

void AddProductToInvoice(char *filePath, ProductInInvo *P){

    FILE *fp = fopen(filePath, "a");

    fprintf(fp, "%s\n", P->ProId);
    fprintf(fp, "%0.2f\n", P->Price);
    fprintf(fp, "%0.2f\n", P->Qty);

    fclose(fp);

}


/*void AddInfoToInvoice(char *filePath, ProductInInvo *P){

    FILE *fp = fopen(filePath, "a");

    fprintf(fp, "%s\n", P->ProId);


    fclose(fp);

}
*/
int getInvoiceNum(){

    char InvoiceNum[5];

    int invInt=0;
    FILE *fp = fopen("./Database/Setting/Invoice.ini", "r");
    fscanf(fp, "%d", &invInt);
    fclose(fp);


    return invInt;

    }






=======
#include <stdio.h>

char *createInvoice(int INum, char CNum[]){
char invoiceNum[10];
static char filePath[100];
sprintf(invoiceNum, "%d", INum);
strcat(filePath, "./Database/Invoice/");
strcat(filePath, invoiceNum);
strcat(filePath, "_");
strcat(filePath, CNum);
strcat(filePath, ".txt");
FILE *fp = fopen(filePath, "w");
fclose(fp);

FILE *fil = fopen("./Database/Setting/Invoice.ini", "w");

fprintf(fil, "%d",INum+1);
fclose(fil);

return filePath;
}

void AddProductToInvoice(char *filePath, ProductInInvo *P){

    FILE *fp = fopen(filePath, "a");

    fprintf(fp, "%s\n", P->ProId);
    fprintf(fp, "%0.2f\n", P->Price);
    fprintf(fp, "%0.2f\n", P->Qty);

    fclose(fp);

}


/*void AddInfoToInvoice(char *filePath, ProductInInvo *P){

    FILE *fp = fopen(filePath, "a");

    fprintf(fp, "%s\n", P->ProId);


    fclose(fp);

}
*/
int getInvoiceNum(){

    char InvoiceNum[5];

    int invInt=0;
    FILE *fp = fopen("./Database/Setting/Invoice.ini", "r");
    fscanf(fp, "%d", &invInt);
    fclose(fp);


    return invInt;

    }






>>>>>>> d9468e13c8973194b9afcfee964dbf960d9ab6e5
