#ifndef STRUCT_QUEUE
#define STRUCT_QUEUE

    typedef struct {
        int *position;
        int current_size, max_values, end;
    } queue;

    queue queue1;

#endif