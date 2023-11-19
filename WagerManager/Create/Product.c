#include <stdio.h>
#include <stdlib.h>
typedef struct{
char ProId[25];
char ProName[25];
float Price;
float Qty;


} ProductInInvo;

int SaveProduct(ProductInInvo *P){
    char filePath[100];
    filePath[0] = '\0';
    strcat(filePath, "./Database/Product/");
    strcat(filePath, P->ProId);
    strcat(filePath, ".txt");

    FILE *fp = fopen(filePath, "w");
    fprintf(fp, "%s\n",P->ProName);
    fprintf(fp, "%f\n", P->Price);

    fclose(fp);
    return 0;
}


void GetProductData(ProductInInvo *Pro){
    static ProductInInvo productInfo;
    char prifix[] = "./Database/Product/";
    char surffix[] = ".txt";
    char filePath[100];
    filePath[0] = '\0';
    strcat(filePath, prifix);
    strcat(filePath, Pro->ProId);
    strcat(filePath, surffix);

    FILE *fp = fopen(filePath, "r");
    filePath[0] = '\0';
    fgets(Pro->ProName, 100, fp);


    fgets(filePath, 100, fp);
    Pro->Price = (float) atof(filePath);

    fclose(fp);

}


int ProductExist(char fileName[]){
    //printf("%s", fileName);

    char prifix[] = "./Database/Product/";
    char surffix[] = ".txt";
    char filePath[100];
    filePath[0] = '\0';
    strcat(filePath, prifix);
    strcat(filePath, fileName);
    strcat(filePath, surffix);


    FILE *fp = fopen(filePath, "r");
     int is_exist = 0;
    if (fp != NULL)
    {
        is_exist = 1;
        fclose(fp);
    }
    return is_exist;
}



