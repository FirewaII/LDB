/*
void tri_nain(int32_t tab[], uint32_t taille)
{
    for (uint32_t i = 0; i < taille - 1; ) {
        if (tab[i] > tab[i+1]) {
            int32_t tmp = tab[i];
            tab[i] = tab[i+1];
            tab[i + 1] = tmp;
            if (i > 0) {
                i = i - 1;
            }
        } else {
            i = i + 1;
        }
    }
}
*/

.text
.globl tri_nain
// void tri_nain(int32_t tab[], uint32_t taille)
// tab[] : %ebp + 8
// taille : %ebp + 12
// uint32_t i 
// i : %ebp - 4
// int32_t tmp
// tmp : %ebp - 8

tri_nain:
    enter $8, $0
    // uint32_t i = 0
    movl $0, -4(%ebp)

for:
    // for (uint32_t i = 0; i < taille - 1; )
    // i < taille - 1
    movl 12(%ebp), %eax
    subl $1, %eax
    cmpl %eax, -4(%ebp) 
    jnb end_for
    // if (tab[i] > tab[i+1])
    // tab[i]
    movl 8(%ebp), %eax
    movl -4(%ebp), %edx
    movl (%eax, %edx, 4), %ecx
    // tab[i+1]
    // cmpl %ecx, 4(%eax, %edx, 4)
    cmpl %ecx, 4(%ecx)
    jnbe else 
    // tmp = tab[i];
    movl 8(%ebp), %eax
    movl -4(%ebp), %edx
    movl (%eax, %edx, 4), %ecx
    movl %ecx, -8(%ebp)
    // tab[i] = tab[i+1];
    movl 8(%ebp), %eax
    movl -4(%ebp), %edx
    movl (%eax, %
