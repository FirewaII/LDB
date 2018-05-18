    .text
    .globl affiche_asm
/*
  void affiche_asm(char c, uint16_t s)
  {
      affiche_c(c + 1, s - 1);
  }
*/
affiche_asm:
    enter $0, $0
    # %eax => 4 octets
    movl $0, %eax
    # %ax => 2 octets
    movw 12(%ebp), %ax
    # %eax contient %ax, push %eax revient à push %ax sur 4 octects
    subw $1, %ax
    pushl %eax
    movl $0, %eax
    movb 8(%ebp), %al
    addb $1, %al
    pushl %eax
    call affiche_c
    addl $8, %esp
    leave
    ret

