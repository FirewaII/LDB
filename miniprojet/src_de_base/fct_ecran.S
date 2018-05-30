#define MEM_VIDEO 0xB8000
#define PORT_CMD 0x3D4
#define PORT_DATA 0x3D5
#define cmd_low 0x0F
#define cmd_high 0x0E
//uint32_t pos_x, pos_y;


.text
// uint16_t *ptr_mem(uint32_t lig, uint32_t col)
.globl ptr_mem
ptr_mem:
  // uint16_t *ptr : %ebp - 4
  enter $0, $0
  movl 8(%ebp), %eax
  movl $80 , %edx
  mull %edx
  movl 12(%ebp), %edx
  addl %edx, %eax
  movl $2 , %ecx
  mull %ecx
  addl $MEM_VIDEO, %eax
  leave
  ret


  /*
  void ecrit_car(uint32_t lig, uint32_t col, char c)
  {
      uint16_t * ptr = ptr_mem(lig, col);
      // little endian : chars de contrôle aux grands indices
      *ptr = c | (cf << 12) | (ct << 8);
  }
  */
  .text
  // void ecrit_car(uint32_t lig, uint32_t col, char c, uint32_t coul_texte, uint32_t coul_fond)
  .globl ecrit_car
  // lig : %ebp + 8
  // col : %ebp + 12
  // c : %ebp + 16
  // coul_texte : %ebp + 20
  // coul_fond : %ebp + 24
  ecrit_car:
   enter $0, $0
   pushl 12(%ebp)
   pushl 8(%ebp)
   call ptr_mem
   addl $8, %esp
   movl %eax, %ecx
   movb 16(%ebp), %al
   movb 24(%ebp), %ah
   shlb $4, %ah
   orb 20(%ebp), %ah
   movw %ax , (%ecx)
   leave
   ret

/*
void place_curseur(uint32_t lig, uint32_t col){
    pos_x=col;
    pos_y=lig;
   uint16_t pos  =col+lig*80;
    outb(0x0F,PORT_CMD);
    outb(pos, PORT_DATA);
    outb(0x0E,PORT_CMD);
    outb(pos>>8, PORT_DATA);
}
*/


   .text
   .globl place_curseur
   //void place_curseur(uint32_t lig, uint32_t col)
   // lig : %ebp + 8
   // col : %ebp + 12
   place_curseur:
   enter $0, $0
   movl 8(%ebp) ,%ecx
   movl %ecx, pos_y
   movl 12(%ebp), %ecx
   movl %ecx, pos_x

   movl 8(%ebp), %eax
   movl $80 , %ecx
   mull %ecx
   addl 12(%ebp), %eax
   movb %al , %cl
   movb $cmd_low, %al
   movw $PORT_CMD, %dx
   outb %al , %dx
   movb %cl , %al
   movw $PORT_DATA, %dx
   outb %al , %dx
   movb $cmd_high, %al
   movw $PORT_CMD, %dx
   outb %al, %dx
   movw $PORT_DATA, %dx
   movb %ah,%al
   outb %al , %dx
   leave
    ret