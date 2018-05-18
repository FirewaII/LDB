/*
uint64_t mult(uint64_t x, uint64_t y);
{
    uint64_t res = 0;
    while (y != 0) {
        res = res + x;
        y--;
    }
    return res;
}
*/
    .text
    // uint64_t mult(uint64_t x, uint64_t y);
    .globl mult
    // x : %rdi
    // y : %rsi
mult:
    // uint64_t res : %rbp - 8
    // on aligne sur un multiple de 16
    enter $16, $0
    // res = 0;
    movq $0, -8(%rbp)
    // while (y != 0) {
while:
    cmpq $0, %rsi
    je fin_while
    // res = res + x;
    addq %rdi, -8(%rbp)
    // y--;
    subq $1, %rsi
    jmp while
fin_while:
    // return res;
    movq -8(%rbp), %rax
    leave
    ret

