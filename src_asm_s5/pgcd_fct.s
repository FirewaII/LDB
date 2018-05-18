// .text precise que ce qui suit est du code (pas des donnees)
.text
// .globl rend l’etiquette publique
.globl pgcd
// uint32_t pgcd(uint32_t a, uint32_t b)
// a : %ebp + 8
// b : %ebp + 12
// etiquette designant le debut de la fonction
pgcd:
// on decale les instructions d’une tabulation
enter $0, $0
// while (a != b) {
while:
movl 12(%ebp), %eax
cmpl 8(%ebp), %eax
je fin_while
// if (a > b) {
movl 12(%ebp), %eax
cmpl 8(%ebp), %eax
ja else
// a = a - b;
movl 12(%ebp), %eax
subl %eax, 8(%ebp)
jmp fin_if
else:
// b = b - a:
movl 8(%ebp), %eax
subl %eax, 12(%ebp)
fin_if:
jmp while
fin_while:
// return a;
movl 8(%ebp), %eax
leave
ret