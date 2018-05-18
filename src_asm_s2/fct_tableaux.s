/*
uint64_t i, j, ix_min;
int32_t tmp;
void tri_min(void)
{
  for (i = 0; i < taille - 1; i++) {
    for (ix_min = i, j = i + 1; j < taille; j++) {
      if (tab[j] < tab[ix_min]) {
        ix_min = j;
      }
    }
    tmp = tab[i];
    tab[i] = tab[ix_min];
    tab[ix_min] = tmp;
  }
}
*/

.data
.comm i, 8
.comm j, 8
.comm ix_min, 8
.comm tmp, 4

.text
.globl tri_min
.globl tri_min_opt

tri_min:
  enter $0, $0
  // i = 0
  movq $0, i

for_loop1:
  // taille - 1
  movq taille, %rax
  subq $1, %rax
  // taille - 1 > i
  cmpq i, %rax
  jnbe end_floop1
  // ix_min = i
  movq i, %rax
  movq %rax, ix_min
  // j = i + 1
  movq i, %rax
  addq $1, %rax
  movq %rax, j

  jmp for_loop2

for_loop2:
  // j < taille
  movq taille, %rax
  // taille - j > 0
  cmpq %rax, j
  jnbe end_floop2

  // if (tab[j] < tab[ix_min])
  // tab[ix_min]
  leaq tab, %r10
  movq ix_min, %r11
  movl (%r10, %r11, 4), %eax
  // tab[ix_min] - tab[j] > 0
  movq j, %r11
  cmpl (%r10, %r11, 4), %eax
  jnbe for_loop2


if_content:
  // ix_min = j
  movq j, %rax
  movq %rax, ix_min
  // j++
  movq j, %rax
  addq $1, %rax
  movq %rax, j
  jmp for_loop2

end_floop2:
  // tmp = tab[i]
  movq i, %r11
  movl (%r10, %r11, 8), %eax
  movl %eax, tmp
  // tab[i] = tab[ix_min]
  movq ix_min, %r11
  movl (%r10, %r11, 4), %eax
  movq i, %r11
  movl %eax, (%r10, %r11, 4)
  // tab[ix_min] = tmp
  movl tmp, %eax
  movq ix_min, %r11
  movl %eax, (%r10, %r11, 4)
  // i++
  movq i, %rax
  addq $1, %rax
  movq %rax, i
  jmp for_loop1

end_floop1:
  leave
  ret

tri_min_opt:
  leave
  ret
