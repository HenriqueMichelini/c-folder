#ifndef QUEUE_FUNCTIONS
#define QUEUE_FUNCTIONS

//  This file = CRUD :)

void StartQueue() {
    queue1.position = (int*) malloc(sizeof(int) * 1000);
    queue1.position[0] = 0;
    queue1.end = 0;
    queue1.max_values = 1000;
}

char *NormalOrPreferencial(int queue_value) {
    if(queue_value >= 1001) {
        return "NORMAL";
    }
    else {
        return "PREFERENCIAL";
    }
}

void AddingQueue(int value) {
    TicketTypeReachLimit(); //  Checking if the limit is reached.
    if(queue1.end < queue1.max_values) {
        queue1.position[queue1.end] = value;
        char *ticket_type = NormalOrPreferencial(queue1.position[queue1.end]);
        printf("\nSenha gerada:[%d] %d %s.", queue1.end+1, value, ticket_type);
        queue1.end++;
    }
    else {
        printf("\nLOTACAO MAXIMA ATINGIDA\n");
    }
}

void InsertingQueue(int position_queue, int value) {
    TicketTypeReachLimit(); //  Checking if the limit is reached.
    if(queue1.end < queue1.max_values) {
        queue1.end++;
        position_queue--;
        for(int i = queue1.end; i > position_queue; i--) {
            queue1.position[i] = queue1.position[i-1];
        }
        queue1.position[position_queue] = value;
        char *ticket_type = NormalOrPreferencial(queue1.position[queue1.end]);
        printf("\nSenha gerada:[%d] %d %s.", position_queue, value, ticket_type);
    } else {
        printf("\nLOTACAO MAXIMA ATINGIDA\n");
    }
}

void RemovingQueue(void) {
    if(queue1.position[0] != 0) {
        for(int i = 0; i < (queue1.end - 1); i++) {
        queue1.position[i] = queue1.position[i+1];
        }
        queue1.position[queue1.end] = 0;
        free(queue1.position[queue1.end]);
        queue1.end--;   
    }
}

void PrintingQueue(void) {
    printf("[POSICAO]       [SENHA]       [TIPO]\n\n");
    for(int i = 0; i < queue1.end; i++) {
        char *ticket_type = NormalOrPreferencial(queue1.position[i]);
        //  For example: 0001    1001    NORMAL
        printf("%4c%d] %11c%04d %7c%s\n", '[', i+1, ' ', queue1.position[i], ' ', ticket_type);
    }
}

#endif