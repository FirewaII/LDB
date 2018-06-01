.data
.comm ptr, 8

.text
/*
bool est_present(uint64_t val, struct noeud_t *abr)
{
    if (NULL == abr) {
        return false;
    } else if (val == abr->val) {
        return true;
    } else if (val < abr->val) {
        return est_present(val, abr->fg);
    } else {
        return est_present(val, abr->fd);
    }
}
*/

.globl est_present
// uint64 val => %rdi
// struct noeud_t *abr => %rsi
est_present:
    enter $0, $0
    // if (NULL == abr)
    cmpq $0, %rsi
    jne elif1
    movq $0, %rax
    leave
    ret
    // else if (val == abr->val)
    elif1:
        cmpq %rdi, (%rsi)
        jne elif2
        movq $1, %rax
        leave
        ret
    // else if (val < abr->val)
    elif2:
        cmpq (%rsi), %rdi
        jnb else
        movq 8(%rsi), %rsi
        call est_present
        leave
        ret
    // else
    else:
        movq 16(%rsi), %rsi
        call est_present
        leave
        ret

.globl abr_vers_tab

/*
void abr_vers_tab(struct noeud_t *abr)
{
    if (abr != NULL) {
        abr_vers_tab(abr->fg);
        *ptr = abr->val;
        ptr++;
        struct noeud_t *fd = abr->fd;
        free(abr);
        abr_vers_tab(fd);
    }
}
*/

abr_vers_tab:
    enter $16, $0
    movq %rdi, -8(%rbp)
    // if (abr != NULL)
    cmpq $0, %rdi
    je fin_abr
    //  abr_vers_tab(abr->fg);
    movq 8(%rdi), %rdi
    call abr_vers_tab
    // *ptr = abr->val
    movq -8(%rbp), %rdi
    movq (%rdi), %r10
    movq ptr, %r11
    movq %r10, (%r11)
    movq %r11, ptr
    // ptr++
    addq $8, ptr
    // struct noeud_t *fd = abr->fd;
    movq 16(%rdi), %rax
    movq %rax, -16(%rbp)
    // free(abr)
    movq -8(%rbp), %rdi
    call free
    // abr_vers_tab(fd)
    movq -16(%rbp), %rdi
    call abr_vers_tab
    jmp fin_abr

fin_abr:
    leave
    ret
