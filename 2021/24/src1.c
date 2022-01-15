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
        if(verbose) printf("Performing INP:\t");
        if(op->par == 0) {
            printf("Waiting for user input (number): ");
            int userInput;
            scanf("%d", &userInput);
            if(verbose) printf("\tuserInput: %d\n", userInput);
            *op->var = userInput;
        } else {
            if(verbose) printf("autoInput: %d\n", op->par);
            *op->var = op->par;
        }
    } else if(op->optype == ADD) {
        if(verbose) printf("Performing ADD:\t");
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
        if(verbose) printf("Performing MUL:\t");
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
        if(verbose) printf("Performing DIV:\t");
        // check if par is val or var
        if(op->parvar != NULL) {
            // par is var
            // check for DIVIDE BY 0 error
            if(*op->parvar == 0) {
                return;
            }
            if(verbose) printf("%d / %d = ", *op->var, *op->parvar);
            *op->var /= *op->parvar;
        } else {
            // par is val
            if(op->par == 0) {
                return;
            }
            if(verbose) printf("%d / %d = ", *op->var, op->par);
            *op->var /= op->par;
        }
        if(verbose) printf("%d\n", *op->var);
    } else if(op->optype == MOD) {
        if(verbose) printf("Performing MOD:\t");
        // check if a < 0
        if(*op->var < 0) {
            return;
        }
        // check if par is val or var
        if(op->parvar != NULL) {
            // par is var
            if(*op->parvar <= 0) {
                perror("[E]Trying to MOD a mod b with b <= 0");
            }
            if(verbose) printf("%d mod %d = ", *op->var, *op->parvar);
            *op->var = *op->var % *op->parvar;
        } else {
            // par is val
            if(op->par <= 0) {
                perror("[E]Trying to MOD a mod b with b <= 0");
            }
            if(verbose) printf("%d mod %d = ", *op->var, op->par);
            *op->var = *op->var % op->par;
        }
        if(verbose) printf("%d\n", *op->var);
    } else if(op->optype == EQL) {
        if(verbose) printf("Performing EQL\t");
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
    }
    
    // cleanup
    free(op);
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

void calcMonad01Lazy(int val) {
    w = val;
    x = 1;
    y = val + 14;
    z = val + 14;
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

void calcMonad02Lazy(int val) {
    x = 1;
    y = 26;
    z *= 26;
    y = val + 2;
    z += y;
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

void calcMonad03Lazy(int val) {
    x = 1;
    z *= 26;
    y = val + 1;
    z += y;
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

void calcMonad04Lazy(int val) {
    x = 1;
    z *= 26;
    y = val + 13;
    z += y;
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

void calcMonad05Lazy(int val) {
    x = 1;
    z *= 26;
    y = val + 5;
    z += y;
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

int calcMonad(int v1, int v2, int v3, int v4, int v5, int v6,
              int v7, int v8, int v9, int v10, int v11, int v12, int v13, int v14) {
    calcMonad01(v1);
    calcMonad02(v2);
    calcMonad03(v3);
    calcMonad04(v4);
    calcMonad05(v5);
    calcMonad06(v6);
    calcMonad07(v7);
    calcMonad08(v8);
    calcMonad09(v9);
    calcMonad10(v10);
    calcMonad11(v11);
    calcMonad12(v12);
    calcMonad13(v13);
    calcMonad14(v14);

    printf("CalcMonad(%d%d%d%d%d%d%d%d%d%d%d%d%d%d): w = %d, x = %d, y = %d, z = %d\n", v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,w,x,y,z);
    
    return z;
}

int calcMonadLazy(int v1, int v2, int v3, int v4, int v5, int v6,
              int v7, int v8, int v9, int v10, int v11, int v12, int v13, int v14) {
    calcMonad01Lazy(v1);
    calcMonad02Lazy(v2);
    calcMonad03Lazy(v3);
    calcMonad04Lazy(v4);
    calcMonad05Lazy(v5);
    calcMonad06(v6);
    calcMonad07(v7);
    calcMonad08(v8);
    calcMonad09(v9);
    calcMonad10(v10);
    calcMonad11(v11);
    calcMonad12(v12);
    calcMonad13(v13);
    calcMonad14(v14);

    printf("LazyMonad(%d%d%d%d%d%d%d%d%d%d%d%d%d%d): w = %d, x = %d, y = %d, z = %d\n", v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,w,x,y,z);
    
    return z;
}
int main() 
{
    // Test 1
    resetAlu();
    calcMonad(1, 3, 5, 7, 9, 2, 4, 6, 8, 9, 9, 9, 9, 9);
    resetAlu();
    calcMonadLazy(1, 3, 5, 7, 9, 2, 4, 6, 8, 9, 9, 9, 9, 9);

    // Test 2
    resetAlu();
    calcMonad(1, 2, 5, 8, 9, 2, 4, 4, 8, 2, 9, 1, 9, 9);
    resetAlu();
    calcMonadLazy(1, 2, 5, 8, 9, 2, 4, 4, 8, 2, 9, 1, 9, 9);

    // Test 3
    resetAlu();
    calcMonad(1, 3, 1, 7, 1, 2, 2, 3, 8, 9, 4, 4, 9, 5);
    resetAlu();
    calcMonadLazy(1, 3, 1, 7, 1, 2, 2, 3, 8, 9, 4, 4, 9, 5);

    // Find first valid number by looping from largest to smallest until
    // z = 0 at some point.

    resetAlu();
    int stop = 0;
    for(int v1=9;v1>0 && stop == 0;v1--) {
     for(int v2=9;v2>0 && stop == 0;v2--) {
      for(int v3=9;v3>0 && stop == 0;v3--) {
       for(int v4=9;v4>0 && stop == 0;v4--) {
        for(int v5=9;v5>0 && stop == 0;v5--) {
         for(int v6=9;v6>0 && stop == 0;v6--) {
          for(int v7=9;v7>0 && stop == 0;v7--) {
           for(int v8=9;v8>0 && stop == 0;v8--) {
            for(int v9=9;v9>0 && stop == 0;v9--) {
             for(int v10=9;v10>0 && stop == 0;v10--) {
              for(int v11=9;v11>0 && stop == 0;v11--) {
               for(int v12=9;v12>0 && stop == 0;v12--) {
                for(int v13=9;v13>0 && stop == 0;v13--) {
                 for(int v14=9;v14>0 && stop == 0;v14--) {
                  resetAlu();
                  if(calcMonadLazy(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14) == 0) {
                    printf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d is the largest possible modelno.\n",
                            v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14);
                    exit(EXIT_SUCCESS);
                  }
                 }
                }
               }
              }
             }
            }
           }
          }
         }
        }
       }
      }
     }
    }
}
