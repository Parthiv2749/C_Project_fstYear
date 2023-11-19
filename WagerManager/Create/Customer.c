#include <stdio.h>
#include <string.h>

 typedef struct  {
 char Name[100];
 char Contact[11];
 char Email[100];

} Customer;



int SaveCust(Customer *C){

    char filePath[100];
    filePath[0] = '\0';
    strcat(filePath, "./Database/Customer/");
    strcat(filePath, C->Contact);
    strcat(filePath, ".txt");

    FILE *fp = fopen(filePath, "w");
    fprintf(fp, "%s\n",C->Name);
    fprintf(fp, "%s\n", C->Email);

    fclose(fp);

return 0;
}

int CustomerExist(Customer *C){

    char prifix[] = "./Database/Customer/";
    char surffix[] = ".txt";
    char filePath[100];
    filePath[0] = '\0';
    strcat(filePath, prifix);
    strcat(filePath, C->Contact);
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

void GetCustomeData(Customer *C){


    char filePath[100];
    filePath[0] = '\0';
    strcat(filePath, "./Database/Customer/");
    strcat(filePath, C->Contact);
    strcat(filePath, ".txt");

    FILE *fp = fopen(filePath, "r");

    fgets(C->Name, 100, fp);
    fgets(C->Email, 100, fp);


    fclose(fp);

}
