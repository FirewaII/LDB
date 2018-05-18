/*
bool palin(char *chaine)
{
    uint32_t inf, sup;
    for (inf = 0, sup = strlen(chaine) - 1;
        (inf < sup) && (chaine[inf] == chaine[sup]);
        inf++, sup--);
    return inf >= sup;
}
*/

.text
.globl palin
// bool palin(char *chaine)
// chaine : (%ebp)+8
// uint32_t inf, sup;
// inf : (%ebp)-4
// sup : (%ebp)-8

palin:
    enter $8, $0
    // inf = 0
    movl $0, -4(%ebp)
    // sup = strlen(chaine) - 1
    pushl 8(%ebp)
    call strlen
    addl $4, %esp
    subl $1, %eax
    movl %eax, -8(%ebp)

for:
    // (inf < sup) 
    movl -4(%ebp), %eax
    movl -8(%ebp), %ecx
    cmpl %eax, %ecx
    jna end_for
    // (chaine[inf] == chaine[sup])
    // %al = chaine[inf]
    movl 8(%ebp), %edx
    movb (%edx, %eax), %al
    cmpb %al, (%edx, %ecx)
    jne end_for
    // inf++
    addl $1, -4(%ebp)
    // sup--
    subl $1, -8(%ebp)
    jmp for

end_for:
    // inf >= sup;
    movl -8(%ebp), %eax
    cmpl %eax, -4(%ebp)
    setae %al
    leave
    ret
