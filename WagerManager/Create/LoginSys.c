#include <string.h>
#include <stdio.h>

int * EncryptPassword(char Password[]);

int createUser(char User[], char pass[]){


    char filePath[100];
    filePath[0] = '\0';
    strcat(filePath, "./Database/UserInfo/");
    strcat(filePath, User);
    strcat(filePath, ".txt");
    FILE *fp = fopen(filePath, "w");

    //const int *password = EncryptPassword(pass);
    //printf("%d\n", *(password + 1));
    //printf("\n%d\n", *password);

    for (int i=0; *(EncryptPassword(pass) + i) != -1; i++){

        fprintf(fp, "%d", *(EncryptPassword(pass) + i));

    }

    fclose(fp);
    return 0;
}


int checkUser(char User[]){

    char filePath[100];
    filePath[0] = '\0';
    strcat(filePath, "./Database/UserInfo/");
    strcat(filePath, User);
    strcat(filePath, ".txt");


    FILE *fp = fopen(filePath, "r");
     int is_exist = 0;
    if (fp != NULL)
    {
        is_exist = 1;
        fclose(fp);
    }
    return is_exist;
}

// Please check If user exist before checking password

int checkPassword(char User[], char pass[]){

    char filePath[100];
    //int *password = EncryptPassword(pass);
    char IntStrPass[100];
    char temp[5];
    filePath[0] = '\0';
    strcat(filePath, "./Database/UserInfo/");
    strcat(filePath, User);
    strcat(filePath, ".txt");

    FILE *fp = fopen(filePath, "r");
    filePath[0] = '\0';
    fgets(filePath, 100, fp);

    fclose(fp);

    for(int i=0;  *(EncryptPassword(pass) + i) != -1; i++) {

        sprintf(temp, "%d",*(EncryptPassword(pass) + i));
        strcat(IntStrPass, temp);

            }

    if (strcmp(filePath, IntStrPass) == 0){
        return 1;
    } else {
        return 0;
    }
}

int* EncryptPassword(char Password[]){
    int strLength =  strlen(Password);
    int EncryptedPassword[strLength +1];
    int *Pointer;
    int i;

    for( i=0; *(Password + i) != '\0'; i++) {
        EncryptedPassword[i] = Password[i] + strLength ;

    }
EncryptedPassword[i] = -1;
    Pointer = &EncryptedPassword;

    return Pointer;
}



