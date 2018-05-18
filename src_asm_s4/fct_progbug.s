    .text
    .globl bug1
bug1:
    enter $16, $0
    movq $10000, %rdi
    call malloc
    movq %rax, -8(%rbp)
    leave
    ret

    .globl bug2
bug2:
    enter $16, $0
    movq $16, %rdi
    call malloc
    movq %rax, -8(%rbp)
    movq %rax, -16(%rbp)
    movq -8(%rbp), %rdi
    call free
    movq -16(%rbp), %rax
    movq $5, (%rax)
    leave
    ret

