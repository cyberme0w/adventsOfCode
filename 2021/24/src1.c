#include <stdio.h>
#include <stdlib.h>
#include "input.h"

// settings
int verbose = 0; // 0 false, 1 true

// alu
int w, x, y, z;
void resetAlu() {w = 0;x = 0;y = 0;z = 0;}

Op *newOp(int optype, int *var, int par, int *parvar) 
{
    Op *op = malloc(sizeof(Op));
    op->optype = optype;
    op->var = var;
    op->par = par;
    op->parvar = parvar;
    return op;
}

void doOp(Op *op) 
{
    if(op->optype == INP) {
        if(verbose) printf("Performing INP:\n");
        if(op->par == 0) {
            printf("\tWaiting for user input (number): ");
            int userInput;
            scanf("%d", &userInput);
            if(verbose) printf("\tuserInput: %d\n", userInput);
            *op->var = userInput;
        } else {
            if(verbose) printf("\tautoInput: %d\n", op->par);
            *op->var = op->par;
        }
    } else if(op->optype == ADD) {
        if(verbose) printf("Performing ADD:\n\t");
        // check if par is val or var
        if(op->parvar != NULL) {
            // par is var
            if(verbose) printf("%d + %d = ", *op->var, *op->parvar);
            *op->var += *op->parvar;
        } else {
            // par is val
            if(verbose) printf("%d + %d = ", *op->var, op->par);
            *op->var += op->par;
        }
        if(verbose) printf("%d\n", *op->var);
    } else if(op->optype == MUL) {
        if(verbose) printf("Performing MUL:\n\t");
        // check if par is val or var
        if(op->parvar != NULL) {
            // par is var
            if(verbose) printf("%d * %d = ", *op->var, *op->parvar);
            *op->var *= *op->parvar;
        } else {
            // par is val
            if(verbose) printf("%d * %d = ", *op->var, op->par);
            *op->var *= op->par;
        }
        if(verbose) printf("%d\n", *op->var);
    } else if(op->optype == DIV) {
        if(verbose) printf("Performing DIV:\n\t");
        // check if par is val or var
        if(op->parvar != NULL) {
            // par is var
            // check for DIVIDE BY 0 error
            if(*op->parvar == 0) {
                perror("[E]Trying to divide by 0");
                exit(EXIT_FAILURE);
            }
            if(verbose) printf("%d / %d = ", *op->var, *op->parvar);
            *op->var /= *op->parvar;
        } else {
            // par is val
            if(op->par == 0) {
                perror("[E]Trying to divide by 0");
                exit(EXIT_FAILURE);
            }
            if(verbose) printf("%d / %d = ", *op->var, op->par);
            *op->var /= op->par;
        }
        if(verbose) printf("%d\n", *op->var);
    } else if(op->optype == MOD) {
        if(verbose) printf("Performing MOD:\n\t");
        // check if a < 0
        if(*op->var < 0) {
            perror("[E]Trying to MOD a \%  b with a < 0");
            exit(EXIT_FAILURE);
        }
        // check if par is val or var
        if(op->parvar != NULL) {
            // par is var
            if(*op->parvar <= 0) {
                perror("[E]Trying to MOD a \%  b with b <= 0");
                exit(EXIT_FAILURE);
            }
            if(verbose) printf("%d % %d = ", *op->var, *op->parvar);
            *op->var %= *op->parvar;
        } else {
            // par is val
            if(op->par <= 0) {
                perror("[E]Trying to MOD a \% b with b <= 0");
                exit(EXIT_FAILURE);
            }
            if(verbose) printf("%d % %d = ", *op->var, op->par);
            *op->var %= op->par;
        }
        if(verbose) printf("%d\n", *op->var);
    } else if(op->optype == EQL) {
        if(verbose) printf("Performing EQL");
        // check if par is val or var
        if(op->parvar != NULL) {
            // par is var
            if(verbose) printf("%d == %d -> ", *op->var, *op->parvar);
            if(*op->var == *op->parvar) *op->var = 1;
            else *op->var = 0;
        } else {
            // par is val
            if(verbose) printf("%d == %d -> ", *op->var, op->par);
            if(*op->var == op->par) *op->var = 1;
            else *op->var = 1;
        }
        if(verbose) printf("%d\n", *op->var);
    } else {
        perror("[E]OpType was bad");
        exit(EXIT_FAILURE);
    }
}

int doTests() 
{
    // TEST_001 (INP)
    printf("Test 001 (INP)\n");
    resetAlu();
    Op *ops_test_1[] = {
        newOp(INP, &w, 0, NULL),
        NULL
    };
    for(int i = 0; ops_test_1[i] != NULL; i++) {
        doOp(ops_test_1[i]);
    }
    printf("End Test 001\n\n");

    // TEST_002 (ADD)
    printf("Test 002 (ADD)\n");
    resetAlu();
    Op *ops_test_2[] = {
        newOp(INP, &w, 0, NULL),
        newOp(ADD, &w, 0, &w),
        NULL
    };
    for(int i = 0; ops_test_2[i] != NULL; i++) {
        doOp(ops_test_2[i]);
    }
    printf("End Test 002\n\n");

    // TEST_003 (MUL)
    printf("Test 003 (MUL)\n");
    resetAlu();
    Op *ops_test_3[] = {
        newOp(INP, &w, 0, NULL),
        newOp(MUL, &w, 2, NULL),
        NULL
    };
    for(int i = 0; ops_test_3[i] != NULL; i++) {
        doOp(ops_test_3[i]);
    }
    printf("End Test 003\n\n");
    
    // TEST_004 (DIV)
    printf("Test 004 (DIV)\n");
    resetAlu();
    Op *ops_test_4[] = {
        newOp(INP, &w, 0, NULL),
        newOp(DIV, &w, 2, NULL),
        NULL
    };
    for(int i = 0; ops_test_4[i] != NULL; i++) {
        doOp(ops_test_4[i]);
    }
    printf("End Test 004\n\n");
    
    // TEST_005 (DIV by 0)
    printf("Test 005 (DIV by 0)\n");
    resetAlu();
    Op *ops_test_5[] = {
        newOp(INP, &w, 0, NULL),
        newOp(DIV, &w, 0, NULL),
        NULL
    };
    for(int i = 0; ops_test_5[i] != NULL; i++) {
        doOp(ops_test_5[i]);
    }
    printf("End Test 005\n\n");

    // TEST_006 (MOD)
    printf("Test 006 (MOD)\n");
    resetAlu();
    Op *ops_test_6[] = {
        newOp(INP, &w, 0, NULL),
        newOp(DIV, &w, 0, NULL),
        newOp(DIV, &w, 0, NULL),
        NULL
    };
    for(int i = 0; ops_test_6[i] != NULL; i++) {
        doOp(ops_test_6[i]);
    }
    printf("End Test 006\n\n");
}

void calcMonad01(int val) {
    Op *ops[] = {
        newOp(INP, &w, val, NULL),
        newOp(MUL, &x, 0, NULL),
        newOp(ADD, &x, 0, &z),
        newOp(MOD, &x, 26, NULL),
        newOp(DIV, &z, 1, NULL),
        newOp(ADD, &x, 14, NULL),
        newOp(EQL, &x, 0, &w),
        newOp(EQL, &x, 0, NULL),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 25, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &y, 1, NULL),
        newOp(MUL, &z, 0, &y),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 0, &w),
        newOp(ADD, &y, 14, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &z, 0, &y),
        NULL
    };
    for(int i = 0; ops[i] != NULL; i++) {
        doOp(ops[i]);
    }
}   

void calcMonad02(int val) {
    Op *ops[] = {
        newOp(INP, &w, val, NULL),
        newOp(MUL, &x, 0, NULL),
        newOp(ADD, &x, 0, &z),
        newOp(MOD, &x, 26, NULL),
        newOp(DIV, &z, 1, NULL),
        newOp(ADD, &x, 14, NULL),
        newOp(EQL, &x, 0, &w),
        newOp(EQL, &x, 0, NULL),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 25, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &y, 1, NULL),
        newOp(MUL, &z, 0, &y),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 0, &w),
        newOp(ADD, &y, 2, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &z, 0, &y),
        NULL
    };
    for(int i = 0; ops[i] != NULL; i++) {
        doOp(ops[i]);
    }
}
void calcMonad03(int val) {
    Op *ops[] = {
        newOp(INP, &w, val, NULL),
        newOp(MUL, &x, 0, NULL),
        newOp(ADD, &x, 0, &z),
        newOp(MOD, &x, 26, NULL),
        newOp(DIV, &z, 1, NULL),
        newOp(ADD, &x, 14, NULL),
        newOp(EQL, &x, 0, &w),
        newOp(EQL, &x, 0, NULL),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 25, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &y, 1, NULL),
        newOp(MUL, &z, 0, &y),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 0, &w),
        newOp(ADD, &y, 1, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &z, 0, &y),
        NULL
    };
    for(int i = 0; ops[i] != NULL; i++) {
        doOp(ops[i]);
    }
}

void calcMonad04(int val) {
    Op *ops[] = {
        newOp(INP, &w, val, NULL),
        newOp(MUL, &x, 0, NULL),
        newOp(ADD, &x, 0, &z),
        newOp(MOD, &x, 26, NULL),
        newOp(DIV, &z, 1, NULL),
        newOp(ADD, &x, 12, NULL),
        newOp(EQL, &x, 0, &w),
        newOp(EQL, &x, 0, NULL),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 25, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &y, 1, NULL),
        newOp(MUL, &z, 0, &y),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 0, &w),
        newOp(ADD, &y, 13, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &z, 0, &y),
        NULL
    };
    for(int i = 0; ops[i] != NULL; i++) {
        doOp(ops[i]);
    }
}

void calcMonad05(int val) {
    Op *ops[] = {
        newOp(INP, &w, val, NULL),
        newOp(MUL, &x, 0, NULL),
        newOp(ADD, &x, 0, &z),
        newOp(MOD, &x, 26, NULL),
        newOp(DIV, &z, 1, NULL),
        newOp(ADD, &x, 15, NULL),
        newOp(EQL, &x, 0, &w),
        newOp(EQL, &x, 0, NULL),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 25, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &y, 1, NULL),
        newOp(MUL, &z, 0, &y),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 0, &w),
        newOp(ADD, &y, 5, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &z, 0, &y),
        NULL
    };
    for(int i = 0; ops[i] != NULL; i++) {
        doOp(ops[i]);
    }
}

void calcMonad06(int val) {
    Op *ops[] = {
        newOp(INP, &w, val, NULL),
        newOp(MUL, &x, 0, NULL),
        newOp(ADD, &x, 0, &z),
        newOp(MOD, &x, 26, NULL),
        newOp(DIV, &z, 26, NULL),
        newOp(ADD, &x, -12, NULL),
        newOp(EQL, &x, 0, &w),
        newOp(EQL, &x, 0, NULL),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 25, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &y, 1, NULL),
        newOp(MUL, &z, 0, &y),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 0, &w),
        newOp(ADD, &y, 5, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &z, 0, &y),
        NULL
    };
    for(int i = 0; ops[i] != NULL; i++) {
        doOp(ops[i]);
    }
}

void calcMonad07(int val) {
    Op *ops[] = {
        newOp(INP, &w, val, NULL),
        newOp(MUL, &x, 0, NULL),
        newOp(ADD, &x, 0, &z),
        newOp(MOD, &x, 26, NULL),
        newOp(DIV, &z, 26, NULL),
        newOp(ADD, &x, -12, NULL),
        newOp(EQL, &x, 0, &w),
        newOp(EQL, &x, 0, NULL),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 25, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &y, 1, NULL),
        newOp(MUL, &z, 0, &y),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 0, &w),
        newOp(ADD, &y, 5, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &z, 0, &y),
        NULL
    };
    for(int i = 0; ops[i] != NULL; i++) {
        doOp(ops[i]);
    }
}

void calcMonad08(int val) {
    Op *ops[] = {
        newOp(INP, &w, val, NULL),
        newOp(MUL, &x, 0, NULL),
        newOp(ADD, &x, 0, &z),
        newOp(MOD, &x, 26, NULL),
        newOp(DIV, &z, 1, NULL),
        newOp(ADD, &x, 12, NULL),
        newOp(EQL, &x, 0, &w),
        newOp(EQL, &x, 0, NULL),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 25, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &y, 1, NULL),
        newOp(MUL, &z, 0, &y),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 0, &w),
        newOp(ADD, &y, 9, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &z, 0, &y),
        NULL
    };
    for(int i = 0; ops[i] != NULL; i++) {
        doOp(ops[i]);
    }
}

void calcMonad09(int val) {
    Op *ops[] = {
        newOp(INP, &w, val, NULL),
        newOp(MUL, &x, 0, NULL),
        newOp(ADD, &x, 0, &z),
        newOp(MOD, &x, 26, NULL),
        newOp(DIV, &z, 26, NULL),
        newOp(ADD, &x, -7, NULL),
        newOp(EQL, &x, 0, &w),
        newOp(EQL, &x, 0, NULL),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 25, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &y, 1, NULL),
        newOp(MUL, &z, 0, &y),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 0, &w),
        newOp(ADD, &y, 3, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &z, 0, &y),
        NULL
    };
    for(int i = 0; ops[i] != NULL; i++) {
        doOp(ops[i]);
    }
}

void calcMonad10(int val) {
    Op *ops[] = {
        newOp(INP, &w, val, NULL),
        newOp(MUL, &x, 0, NULL),
        newOp(ADD, &x, 0, &z),
        newOp(MOD, &x, 26, NULL),
        newOp(DIV, &z, 1, NULL),
        newOp(ADD, &x, 13, NULL),
        newOp(EQL, &x, 0, &w),
        newOp(EQL, &x, 0, NULL),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 25, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &y, 1, NULL),
        newOp(MUL, &z, 0, &y),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 0, &w),
        newOp(ADD, &y, 13, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &z, 0, &y),
        NULL
    };
    for(int i = 0; ops[i] != NULL; i++) {
        doOp(ops[i]);
    }
}

void calcMonad11(int val) {
    Op *ops[] = {
        newOp(INP, &w, val, NULL),
        newOp(MUL, &x, 0, NULL),
        newOp(ADD, &x, 0, &z),
        newOp(MOD, &x, 26, NULL),
        newOp(DIV, &z, 26, NULL),
        newOp(ADD, &x, -8, NULL),
        newOp(EQL, &x, 0, &w),
        newOp(EQL, &x, 0, NULL),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 25, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &y, 1, NULL),
        newOp(MUL, &z, 0, &y),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 0, &w),
        newOp(ADD, &y, 2, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &z, 0, &y),
        NULL
    };
    for(int i = 0; ops[i] != NULL; i++) {
        doOp(ops[i]);
    }
}

void calcMonad12(int val) {
    Op *ops[] = {
        newOp(INP, &w, val, NULL),
        newOp(MUL, &x, 0, NULL),
        newOp(ADD, &x, 0, &z),
        newOp(MOD, &x, 26, NULL),
        newOp(DIV, &z, 26, NULL),
        newOp(ADD, &x, -5, NULL),
        newOp(EQL, &x, 0, &w),
        newOp(EQL, &x, 0, NULL),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 25, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &y, 1, NULL),
        newOp(MUL, &z, 0, &y),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 0, &w),
        newOp(ADD, &y, 1, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &z, 0, &y),
        NULL
    };
    for(int i = 0; ops[i] != NULL; i++) {
        doOp(ops[i]);
    }
}

void calcMonad13(int val) {
    Op *ops[] = {
        newOp(INP, &w, val, NULL),
        newOp(MUL, &x, 0, NULL),
        newOp(ADD, &x, 0, &z),
        newOp(MOD, &x, 26, NULL),
        newOp(DIV, &z, 26, NULL),
        newOp(ADD, &x, -10, NULL),
        newOp(EQL, &x, 0, &w),
        newOp(EQL, &x, 0, NULL),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 25, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &y, 1, NULL),
        newOp(MUL, &z, 0, &y),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 0, &w),
        newOp(ADD, &y, 11, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &z, 0, &y),
        NULL
    };
    for(int i = 0; ops[i] != NULL; i++) {
        doOp(ops[i]);
    }
}

void calcMonad14(int val) {
    Op *ops[] = {
        newOp(INP, &w, val, NULL),
        newOp(MUL, &x, 0, NULL),
        newOp(ADD, &x, 0, &z),
        newOp(MOD, &x, 26, NULL),
        newOp(DIV, &z, 26, NULL),
        newOp(ADD, &x, -7, NULL),
        newOp(EQL, &x, 0, &w),
        newOp(EQL, &x, 0, NULL),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 25, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &y, 1, NULL),
        newOp(MUL, &z, 0, &y),
        newOp(MUL, &y, 0, NULL),
        newOp(ADD, &y, 0, &w),
        newOp(ADD, &y, 8, NULL),
        newOp(MUL, &y, 0, &x),
        newOp(ADD, &z, 0, &y),
        NULL
    };
    for(int i = 0; ops[i] != NULL; i++) {
        doOp(ops[i]);
    }
}

int main() 
{
    resetAlu();
 
    printf("Inputing val 1 for monad calc 01\n");   
    for(int i = 1; i < 2; i++) {
        calcMonad01(i);
        printf("w: %d, x: %d, y: %d, z: %d\n", w, x, y, z);
    }


}
