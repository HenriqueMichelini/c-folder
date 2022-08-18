#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//  Global varibles. Why not?
int id_normal = 1001;
int id_preferencial = 1;

#include "struct_queue.h"
#include "queue_functions.h"
#include "queue_screens.h"

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

int main(void) {
    StartQueue();
    PrintMainScreen();
    OptionSelectMain();

    //  For testing purposes

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