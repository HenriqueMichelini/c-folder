#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "struct_queue.h"
#include "queue_functions.h"

int id_normal = 1001;
int id_preferencial = 1;

void OrganizingQueue(int value) {
    int i = 0;
    while (queue1.position[i] <= 1001) {
        i++;
    }
    // printf("\n\nPrimeiro normal: %d", queue1.position[i]);
    InsertingQueue(i, value);
}

void TicketTypeReachLimit(void) {
    if(id_normal == 2000) {
        id_normal = 1001;
    }
    if (id_preferencial == 1000) {
        id_preferencial = 1;
    } 
}

char OptionInsert(void) {
    printf("\n>: ");
    char option = fgetc(stdin);
    fflush(stdin);
    return option;
}

void PrintMainScreen(void) {
    printf("===============================\n");
    printf("      [SISTEMA DE SENHAS]\n");
    printf("===============================\n");
    printf("    digite a opcao desejada.\n\n");
    printf("1 - Geracao de senha.\n");
    printf("2 - Chamada de senha.\n");
    printf("3 - Listagem de senha.\n\n");
    printf("X - Sair do programa.");
}
void OptionSelectMain() {
    char option = OptionInsert();
    if (option == '1') {
        PrintTicketGeneratorScreen();
        OptionSelectTicketGenerator();
    }
    if (option == '2') {
        if(queue1.position[0] != 0) {
            PrintTicketCallerScreen();
            OptionSelectCallTicket();
        }
        else {
            printf("\nA fila esta vazia.");
            OptionSelectMain();
        }
    }
    if (option == '3') {
        ShowQueue();
    }
    if (option == 'x' || option == 'X') {
        printf("\nO programa foi encerrado.");
        free(queue1.position);
        exit(0);
    }
    if (option != '1' && option != '2' && option != '3' && option != 'x' && option != 'X') {
        printf("\nA opcao digitada nao e valida.");
        OptionSelectMain();
    }
}

void OptionSelectionQueue(void) {
    char option = OptionInsert();
    if(option == 'x' || option == 'X') {
        PrintMainScreen();
        OptionSelectMain();
    }
    else {
        printf("\nA opcao digitada nao e valida.");
        OptionSelectionQueue();
    }
}

void ShowQueue() {
    printf("\n");
    PrintingQueue();
    printf("\nX - Voltar a tela principal");
    OptionSelectionQueue();
}

void PrintTicketGeneratorScreen(void) {
    printf("===============================\n");
    printf("         [GERAR SENHA]\n");
    printf("===============================\n");
    printf("    digite a opcao desejada.\n\n");
    printf("1 - Gerar uma senha NORMAL.\n");
    printf("2 - Gerar uma senha PREFERENCIAL.\n\n");
    printf("X - Voltar a tela principal.");
}

void OptionSelectTicketGenerator(void) {
    char option = OptionInsert();
    if (option == '1') {
        AddingQueue(id_normal);
        id_normal++;
    }
    if (option == '2') {
        OrganizingQueue(id_preferencial);
        id_preferencial++;
    }
    if (option == 'x' || option == 'X') {
        PrintMainScreen();
        OptionSelectMain();
    }
    if (option != '1' && option != '2' && option != 'x' && option != 'X') {
        printf("\nA opcao digitada nao e valida.");
    }
    OptionSelectTicketGenerator();
}

void PrintTicketCallerScreen(void) {
    char *ticket_type;
    if(queue1.position[0] >= 1000) {
        ticket_type = "NORMAL";
    }
    else {
        ticket_type = "PREFERENCIAL";
    }
    printf("===============================\n");
    printf("       [CHAMADA DE SENHA]\n");
    printf("===============================\n");
    printf("    digite a opcao desejada.\n\n");
    printf("Senha chamada: %d\n", queue1.position[0]);
    printf("Tipo: %s\n\n", ticket_type);
    printf("1 - Chamar proxima senha.\n");
    printf("X - Voltar a tela principal.");
}

void OptionSelectCallTicket(void) {
    char option = OptionInsert();
    if (option == '1') {
        CallTicket();
    }
    if (option == 'x' || option == 'X') {
        PrintMainScreen();
        OptionSelectMain();
    }
    if (option != 'x' && option != 'X' && option != '1') {
        printf("\nA opcao digitada nao e valida.");
    }
    OptionSelectCallTicket();
}

void CallTicket(void) {
    RemovingQueue();
    PrintTicketCallerScreen();
}

int main(void) {
    StartQueue();
    PrintMainScreen();
    OptionSelectMain();

    // AddingQueue(3133);

    // char *ticket_type = NormalOrPreferencial(queue1.position[0]);
    // printf("\n%s", ticket_type);

    // AddingQueue(3);
    // AddingQueue(7);
    // AddingQueue(8);
    // AddingQueue(22);
    // AddingQueue(4441);
    // AddingQueue(1111);
    // AddingQueue(4441);
    // AddingQueue(1311);

    // OrganizingQueue();

    // printf("\n");
    // PrintingQueue();

    // RemovingQueue();
    // printf("\n");
    // PrintingQueue();

    // printf("\n");
    // CallTicket();

    // printf("\n");
    // PrintingQueue();

    // printf("\n");
    // CallTicket();

    // printf("\n");
    // PrintingQueue();

    free(queue1.position);
}