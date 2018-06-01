/*
uint64_t fact(uint64_t n)
{
  if (n <= 1) {
    return 1;
  } else {
    return n * fact(n - 1);
  }
}
*/

.text
.globl fact
// uint64_t fact(uint64_t n)
// n : %rdi

fact:
  enter $16, $0
  movq %rdi, -16(%rbp)
  // if (n <= 1)
  cmpq $1, %rdi
  ja else

if:
  movq $1, %rax
  jmp fin

else:
  // n * fact(n - 1)
  // n - 1
  subq $1, %rdi
  call fact
  // restore n
  movq -16(%rbp), %rdi
  mulq %rdi
  cmpq $0, %rdx
  je fin
  call erreur_fact

fin:
  leave
  ret
