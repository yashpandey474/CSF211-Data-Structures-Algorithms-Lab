#include <stdio.h>
#include <stdlib.h>

struct user_id_pointer{
    int user_id;
    int index;

};

struct user_id_node{
    int num_keys;
    struct user_id_pointer keys[3];
    int children[4];
    int isleaf;
};

struct salary_pointer{
    int salary;
    int index;
};

struct salary_pointer_node{
    int num_keys;
    struct salary_pointer keys[3];
    int children[4];
    int isleaf;
};
