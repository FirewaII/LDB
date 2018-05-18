/*
uint64_t taille;
uint64_t taille_chaine(void)
{
  for (taille = 0; chaine[taille] != ’\0’; taille++);
  return taille;
}
*/


.data
.comm taille, 8
.comm dep, 8
.comm ptr, 8
.comm tmp, 1

.text
.globl taille_chaine
.globl inverse_chaine

taille_chaine:
  enter $0, $0
  // taille = 0
  movq $0, taille
  // %r10 = chaine
  leaq chaine, %r10

for_loop:
  // chaine[taille] != '\0'
  movq taille, %r11
  cmpb $0, (%r10,%r11,1)
  je end_floop
  // taille++
  movq $1, %rax
  addq %rax, taille
  jmp for_loop

end_floop:
  //
  movq taille, %rax
  leave
  ret

/*
int64_t dep;
char *ptr;
char tmp;

void inverse_chaine(void)
{
  dep = taille - 1;
  ptr = chaine; // attention : ici, on copie dans ptr l’adresse de la chaine
  while (dep > 0) {
    tmp = *ptr;
    *ptr = ptr[dep];
    ptr[dep] = tmp;
    dep = dep - 2;
    ptr++;
  }
}
*/

inverse_chaine:
  enter $0, $0
  // dep = taille - 1
  movq taille, %rax
  subq $1, %rax
  movq %rax, dep
  // ptr = chaine
  leaq chaine, %rax
  movq %rax, ptr

while_loop:
  // dep > 0
  cmpq $0, dep
  jng end_wloop
  // tmp = *ptr
  movq ptr, %r10
  movb (%r10), %al
  movb %al, tmp
  // *ptr = ptr[dep]
  movq ptr, %r10
  movq dep, %r11
  movb (%r10, %r11, 1), %al
  movb %al, (%r10)
  // ptr[dep] = tmp
  movb tmp, %al
  movq ptr, %r10
  movq dep, %r11
  movb %al, (%r10,%r11)
  // dep = dep - 2
  subq $2, dep
  // ptr++
  addq $1, ptr 
  jmp while_loop

end_wloop:
  leave
  ret
