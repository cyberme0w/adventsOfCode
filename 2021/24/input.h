#ifndef __INPUT_H__
#define __INPUT_H__

#include <stdio.h>

enum OpType{INP, ADD, MUL, DIV, MOD, EQL};

typedef struct {
    int optype;
    int *var;
    int par;
    int *parvar;
} Op;

Op *newOp(int optype, int *var, int par, int *parvar);
void doOp(Op *op);

#endif // input.h
