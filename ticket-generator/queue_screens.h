#ifndef QUEUE_SCREENS
#define QUEUE_SCREENS

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

void ShowQueue() {
    printf("\n");
    PrintingQueue();
    printf("\nX - Voltar a tela principal");
    OptionSelectionQueue();
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

void CallTicket(void) {
    RemovingQueue();
    PrintTicketCallerScreen();
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

#endif