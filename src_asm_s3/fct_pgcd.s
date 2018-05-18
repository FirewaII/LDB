/*
uint32_t pgcd(uint32_t a, uint32_t b)
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
    // uint32_t pgcd(uint32_t a, uint32_t b)
    // a : %edi
    // b : %esi
pgcd:
    enter $0, $0
    // while (a != b) {
while:
    cmpl %edi, %esi
    je fin_while
    // if (a > b) {
    cmpl %edi, %esi
    jnb else
    // a = a - b;
    subl %esi, %edi
    jmp fin_if
else:
    // b = b - a:
    subl %edi, %esi
fin_if:
    jmp while
fin_while:
    // return a;
    movl %edi, %eax
    leave
    ret

