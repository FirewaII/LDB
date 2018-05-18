/*
uint32_t pgcd(void)
{
    while (a != b) {
        if (a < b) {
            b = b - a;
        } else {
            a = a - b;
        }
    }
    return a;
}
*/
    .text
    .globl pgcd
pgcd:
    enter $0, $0
    // while (a != b) {
while:
    movl a, %eax
    cmpl b, %eax
    je fin_while
    // if (a < b) {
    movl a, %eax
    cmpl b, %eax
    // jmp ssi not(a < b)
    jnb else
    // b = b - a;
    movl a, %eax
    subl %eax, b
    jmp fin_if
else:
    // a = a - b:
    movl b, %eax
    subl %eax, a
fin_if:
    jmp while
fin_while:
    // return a;
    movl a, %eax
    leave
    ret

