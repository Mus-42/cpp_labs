#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>

// Lab 7 Task 18

// compute P(Q(x)) for given P, Q
// inputs:  
// pn, pc - P
// qn, qc - Q
// pqn, pqc - out for PQ 
// accum_buf1, accum_buf2 - buffers for accumulator
// pqc & accum buf must be at least pn*qn+1 elements long
void compute_pq(int pn, const int* pc, int qn, const int* qc, int* pqn, int* pqc, int* accum_buf1, int* accum_buf2) {
    // leading term: x^pqn = (x^qn)^pn = x^(qn*pn)
    *pqn = qn*pn;
    memset(pqc, 0, sizeof(int) * (pn * qn + 1));

    // accum - store value of Q^ip
    int accum_n = 0; 
    accum_buf1[0] = 1;

    for (int ip = 0; ip <= pn; ip++) {
        // accum now Q^ip
        // add ip-th term of P to answer
        for (int ia = 0; ia <= accum_n; ia++) {
            pqc[ia] += pc[ip] * accum_buf1[ia];
        }

        // accum *= Q 
        memset(accum_buf2, 0, sizeof(int) * (accum_n+qn+1));
        for (int ia = 0; ia <= accum_n; ia++)
            for (int iq = 0; iq <= qn; iq++) {
                accum_buf2[ia + iq] += accum_buf1[ia] * qc[iq];
            }

        // swap buf pointers
        int* accum_prev = accum_buf1;
        accum_buf1 = accum_buf2;
        accum_buf2 = accum_prev;

        accum_n += qn;
    }
}

int main(void) {
    // example:
    // P(x) = 2x^2 + 3x + 4
    // Q(x) = 5x + 1

    const int p[] = {4, 3, 2};
    const int q[] = {1, 5};

    int acc_buf1[8];
    int acc_buf2[8];
    int pq[8];  
    int pqn;

    compute_pq(2, p, 1, q, &pqn, pq, acc_buf1, acc_buf2);

    // result
    printf("%d", pq[0]);
    for (int i = 1; i <= pqn; i++) {
        printf(" + %dx^%d", pq[i], i);
    }

    // P(Q(x)) = P(5x+1) = 2(5x+1)^2 + 3(5x+1) + 4 = 50x^2 + 35x + 9
}