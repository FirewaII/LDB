/*
uint64_t fibo(uint64_t n);
{
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}
*/
    .text
    .globl fibo
    // uint64_t fibo(uint64_t n)
    // n : %rdi
fibo:
    // on reserve de la place pour la sauvegarde de %rdi et %rax
    enter $16, $0
    // sauvegarde du parametre %rdi = n dans la pile
    movq %rdi, -16(%rbp)
    // if (n == 0)
    cmpq $0, %rdi
    jne elsif
    // return 0;
    movq $0, %rax
    jmp fin
elsif:
    // else if (n == 1)
    cmpq $1, %rdi
    jne else
    // return 1;
    movq $1, %rax
    jmp fin
else:
    // return fibo(n - 1) + fibo(n - 2);
    // on commence par appeler fibo(n - 1)
    subq $1, %rdi
    call fibo
    // restauration du %rdi = n initial
    movq -16(%rbp), %rdi
    // sauvegarde de %rax = fibo(n - 1) dans la pile
    movq %rax, -8(%rbp)
    // on appelle maintenant fibo(n - 2)
    subq $2, %rdi
    call fibo
    // et on calcule la somme finale
    addq -8(%rbp), %rax
fin:
    leave
    ret

