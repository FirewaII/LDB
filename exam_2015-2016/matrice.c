#include <stdio.h>
#include <inttypes.h>

// on decide (parce qu'on a envie) que la matrice manipulee aura 3 lignes et
//   4 colonnes
// les nombres de lignes et de colonnes sont des variables GLOBALES
const uint32_t nbr_lig = 3;
const uint32_t nbr_col = 4;

// initialisation de la matrice avec des entiers 16 bits signes aleatoires
extern void init(int16_t mat[nbr_lig][nbr_col]);

// renvoie la somme des coefficients de la matrice
extern int16_t somme(int16_t *mat, uint32_t nbr_cases);

// affichage de la matrice
void afficher(int16_t mat[nbr_lig][nbr_col])
{
    printf("Matrice %" PRIu32 "x%" PRIu32 " :\n", nbr_lig, nbr_col);
    for (uint32_t lig = 0; lig < nbr_lig; lig++) {
        for (uint32_t col = 0; col < nbr_col; col++) {
            printf("% 2" PRId16 " ", mat[lig][col]);
        }
        puts("");
    }
    puts("");
}

// fonction principale
int main(void)
{
    // cette matrice contiendra des entiers 16 bits signes
    int16_t mat[nbr_lig][nbr_col];
    // initialiation aleatoire du contenu de la matrice
    init(mat);
    // affichage de la matrice
    afficher(mat);
    // calcul de la somme des coefficients de la matrice
    int16_t som = somme((int16_t *)mat, nbr_lig * nbr_col);
    printf("Somme = %" PRId16 "\n", som);
    return 0;
}

