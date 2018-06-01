/*
int32_t main(int32_t argc, char *argv[])
{
    for (int32_t i = 0; i < argc; i++) {
        puts(argv[i]);
    }
    return 0;
}
*/

.text
.globl main

// int32_t main(int32_t argc, char *argv[])
// int32_t argc : %edi
// char *argv[] : %rsi

// int32_t i => -4(%rbp)
main:
    enter $16, $0
    movl %edi, -8(%rbp)
    movq %rsi, -16(%rbp)
    //int32_t i = 0;
    movq $0, -4(%rbp)
    jmp for

for:
    // i < argc
    cmpl -4(%rbp), %edx
    jle fin_for
    // puts(argv[i])
    movq $0, %rax
    movl -4(%rbp), %eax
    movq (%rsi, %rax, 8), %rdi
    call puts
    movl -8(%rbp), %rdi
    movq -16(%rbp), %rsi
    addl $1, -4(%rbp)
    jmp for

fin_for:
    // return 0;
    movq $0, %eax
    leave
    ret
    
