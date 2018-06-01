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
// int32_t argc : %rdi
// char *argv[] : %rsi

// int32_t i => -8(%rbp)
main:
    enter $32, $0
    //int32_t i = 0;
    movq $0, -8(%rbp)
    //save argc
    movq %rdi, -16(%rbp)
    //save argv
    movq %rsi, -24(%rbp)
    jmp for

for:
    // restore i
    movq -8(%rbp), %r11
    // restore argc
    movq -16(%rbp), %r9
    // i < argc
    cmpq %r9, %r11
    jnb fin_for
    // recup argv[i]
    movq (%rsi, %r11, 8), %rdi
    call puts
    movq %rax, %rdi
    // restore argv
    movq -24(%rbp), %rsi
    // i++
    movq -8(%rbp), %r11
    addq $1, %r11
    movq %r11, -8(%rbp)
    jmp for

fin_for:
    // return 0;
    movq $0, %rax
    leave
    ret
    
