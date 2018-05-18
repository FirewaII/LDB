/*
void inverse(struct cellule_t **l)
{
  struct cellule_t *res, *suiv;
  res = NULL;
  while (*l != NULL) {
    suiv = (*l)->suiv;
    (*l)->suiv = res;
    res = *l;
    *l = suiv;
  }
  *l = res;
}
*/

.text
  .globl inverse
  .globl decoupe
  // struct cellule_t is sizeof(int64_t) and sizeof(ptr)
  // void inverse(struct cellule_t **l)
  // l : %rdi
  // struct cellule_t *res, *suiv;
  // *res : %rbp-8
  // *suiv : %rdx-16

inverse:
  enter $16, $0
  // res = NULL
  movq $0, -8(%rbp)

while:
  // while (*l != NULL)
  cmpq $0, (%rdi)
  je is_null
  // suiv = (*l)->suiv
  movq (%rdi), %rax
  movq 8(%rax), %rax
  movq %rax, -16(%rbp)
  // (*l)->suiv = res;
  movq -8(%rbp), %rax
  movq (%rdi), %r11
  movq %rax, 8(%r11)
  // res = *l
  movq (%rdi), %rax
  movq %rax, -8(%rbp)
  // *l = suiv
  movq -16(%rbp), %rax
  movq %rax, (%rdi)
  jmp while

is_null:
  // *l = res
  movq -8(%rbp), %rax
  movq %rax, (%rdi)
  leave
  ret

  /*
  struct cellule_t *decoupe(struct cellule_t *l,
                            struct cellule_t **l1,
                            struct cellule_t **l2)
  {
    struct cellule_t fictif1, fictif2;
    *l1 = &fictif1;
    *l2 = &fictif2;
    while (l != NULL) {
      if (l->val % 2 == 1) {
        (*l1)->suiv = l;
        *l1 = l;
      } else {
        (*l2)->suiv = l;
        *l2 = l;
      }
      l = l->suiv;
    }
    (*l1)->suiv = NULL;
    (*l2)->suiv = NULL;
    *l1 = fictif1.suiv;
    *l2 = fictif2.suiv;
    return l;
  }
  */
// struct cellule_t *decoupe(struct cellule_t *l,
//                           struct cellule_t **l1,
//                           struct cellule_t **l2)
// l : %rdi
// **l1 : %rsi
// **l2 : %rdx
// struct cellule_t fictif1, fictif2;
// fictif1 : %rbp-8
// fictif2 : %rbp-16

decoupe:
  enter $32, $0
  // *l1 = &fictif1;
  leaq -16(%rbp), %rax
  movq %rax, (%rsi)
  // *l2 = &fictif2;
  leaq -32(%rbp), %rax
  movq %rax, (%rdx)

while_dec:
  // while (l != NULL)
  cmpq $0, %rdi
  je is_null_dec
  // if (l->val % 2 == 1)
  movq %rdi, %rax
  testq $1, 0(%rax)
  jz even_parity
  // (*l1)->suiv = l;
  movq (%rsi), %rax
  movq %rdi, 8(%rax)
  // *l1 = l;
  movq %rdi, (%rsi)
  // l = l->suiv
  movq 8(%rdi), %rdi
  jmp while_dec

even_parity:
  // (*l2)->suiv = l;
  movq (%rdx), %rax
  movq %rdi, 8(%rax)
  // *l2 = l;
  movq %rdi, (%rdx)
  // l = l->suiv
  movq 8(%rdi), %rdi
  jmp while_dec

is_null_dec:
  // (*l1)->suiv = NULL;
  movq (%rsi), %rax
  movq $0, 8(%rax)
  // (*l2)->suiv = NULL;
  movq (%rdx), %rax
  movq $0, 8(%rax)
  // *l1 = fictif1.suiv;
  movq -8(%rbp), %rax
  // -16+8 = -8
  movq %rax, (%rsi)
  // *l2 = fictif2.suiv;
  movq -24(%rbp), %rax
  // -32+8 = -24
  movq %rax, (%rdx)

return:
  // return l;
  movq %rdi, %rax
  leave
  ret
