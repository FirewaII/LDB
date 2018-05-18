/*
bool palin(char *chaine)
{
  uint64_t inf, sup;
  for (inf = 0, sup = strlen(chaine) - 1;
  (inf < sup) && (chaine[inf] == chaine[sup]);
  inf++, sup--);
  return inf >= sup;
}
*/

.text
.globl palin
// bool palin(char *chaine)
// *chaine : %rdi
// uint64_t inf, sup;
// inf => -8(%rbp) => %r10
// sup => -16(%rbp) => %r11

palin:
  enter $32, $0
  movq %rdi, -24(%rbp)
  // inf = 0
  movq $0, -8(%rbp)
  // sup = strlen(chaine) - 1
  call strlen
  movq -24(%rbp), %rdi
  subq $1, %rax
  movq %rax, -16(%rbp)

for:
  // inf < sup
  movq -8(%rbp), %rax
  movq -16(%rbp), %r11
  cmpq %rax, %r11
  jna end_for
  // chaine[inf] == chaine[sup]
  movb (%rdi, %rax, 1), %al
  cmpb %al, (%rdi, %r11)
  jne end_for
  // inf++
  addq $1, -8(%rbp)
  subq $1, -16(%rbp)
  jmp for

end_for:
  // return inf >= sup
  movq -16(%rbp), %rax
  cmpq %rax, -8(%rbp)
  setae %al
  leave
  ret
  
the_end:
