/*
uint16_t *ptr_mem(uint32_t lig, uint32_t col)
{
    return 0xB8000 + 2 * (lig x 80 + col)
}
*/

.text
.globl ptr_mem
.globl ecrit_car
.globl place_curseur

// uint32_t lig, uint32_t col
// lig : %ebp + 8
// col : %ebp + 12

ptr_mem:
    enter $0, $0
    // = 0xB8000 + 2 * (lig x 80 + col)
    movl 8(%ebp) , %eax
    movl $80, %edx
    mull %edx
    addl 12(%ebp), %eax
    movl $2, %edx
    mull %edx
    addl $0xB8000, %eax
    leave
    ret

/*
void ecrit_car(uint32_t lig, uint32_t col, char c, uint32_t coul_texte, uint32_t coul_fond)
{
    *ptr_mem(lig, col) = c | (coul_texte << 8) | (coul_fond << 12);
}
*/
// uint32_t lig, uint32_t col, char c, uint32_t coul_texte, uint32_t coul_fond
// lig : %ebp + 8
// col : %ebp + 12
// c : %ebp + 16 ( 1 byte )
// coul_texte : %ebp + 20
// coul_fond : %ebp + 24

// uint16_t *ptr

ecrit_car:
    enter $4, $0
    pushl 12(%ebp)
    pushl 8(%ebp)
    call ptr_mem
    addl $8, %esp
    movl 16(%ebp), %ecx
    movl %ecx, (%eax)
    movl 20(%ebp), %ecx
    movl %ecx, textColor
    shll $8, %ecx
    orl %ecx, (%eax)
    movl 24(%ebp), %ecx
    movl %ecx, bgColor
    shll $12, %ecx
    orl %ecx, (%eax)
    leave
    ret


/*
void place_curseur(uint32_t lig, uint32_t col)
{
    // pos= col + lig × 80
    uint16_t pos = col + lig * 80;
    // 7 -> 0
    outb(0x0F,0x3D4);    
    outb(pos && 0xFF00, 0x3D5);
    // 15 -> 8
    outb(0x0E, 0x3D4);
    outb(pos && 0x00FF, 0x3D5);
}
*/

// uint32_t lig, uint32_t col
// lig: %ebp + 8
// col: %ebp + 12

// uint16_t pos

place_curseur:
    enter $2, $0
    //    uint16_t pos = col + lig * 80;
    movl 8(%ebp), %eax
    movw %eax, posY
    movl $80, %ecx
    mull %ecx
    movw 12(%ebp), %ecx
    movw %ecx, posX
    addl 12(%ebp), %eax
    //    outb(0x0F,0x3D4); 
    movb $0x0F, %al
    movw $0x3D4, %dx
    outb %al, %dx
    //    outb(pos && 0xFF00, 0x3D5);
    movw $0x3D5, %dx
    movw 8(%ebp), %ax
    movb %ah, %al
    outb %al, %dx
    //    outb(0x0E,0x3D4); 
    movb $0x0E, %al
    movw $0x3D4, %dx
    outb %al, %dx
    //    outb(pos && 0x00FF, 0x3D5);
    movw 8(%ebp), %ax
    outb %al, %dx
    leave
    ret