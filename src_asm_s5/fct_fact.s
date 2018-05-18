/*
uint32_t fact(uint32_t n)
{
    if (n <= 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}
*/

.text
.globl fact
// uint32_t fact(uint32_t n)
// n : %ebp + 8

fact:
    enter $0, $0

while:
    // if (n <= 1)
    movl 8(%ebp), %eax
    cmpl $1, %eax
    ja is_above
    // return 1;
    movl $1, %eax
    jmp end

is_above:
    // else
    // return n * fact(n - 1)
    pushl 8(%ebp)
    subl $1, (%esp)
    call fact
    addl $4, %esp
    mull 8(%ebp)
    cmpl $0, %edx
    je end
    pushl 8(%ebp)
    call erreur_fact

fin:
    leave
    ret
