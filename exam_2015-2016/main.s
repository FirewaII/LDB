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

// int32_t argc => %edi
// char *argv[] => %rsi
// int32_t i => -4(%rbp)

main:
    enter $16, $0
    // store argc argv
    movl %edi, -8(%rbp)                                                                                
    movq %rsi, -16(%rbp)                                                                                
    // i = 0
    movl $0, -4(%rbp)
    jmp for

for:
    // i < argc
    movl -8(%rbp), %eax
    cmpl %eax, -4(%rbp)
    jnb fin_for
    // puts(argv[i])
    movq $0, %rax
    movq -4(%rbp), %rax
    movq (%rsi, %rax, 8), %rdi
    call puts
    // restore argc argv
    movl -8(%rbp), %edi
    movq -16(%rbp), %rsi
    // i++
    addl $1, -4(%rbp)
    jmp for

fin_for:
    // return 0
    movq $0, %rax
    leave
    ret
