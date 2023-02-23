#include <stdio.h>

/* Programma che legge un intero n introdotto dall'utente e crea
 * una matrice con n righe i cui elementi sono quelli del triangolo di Tartaglia */

int main() {
      int n;                // dimensione matrice

      /* leggi dimensione e crea array */
      printf("Quante righe del triangolo di tartaglia vuoi?\n");
      scanf("%d", &n);
      int matrice[n][n];

      /* la prima riga e' speciale: un elemento 1 e tutti gli altri 0 */
      matrice[0][0]=1;
      for(int j=1; j<n; j++)
            matrice[0][j]=0;

      /* guarda tutte le altre righe */
      for(int i=1; i<n; i++) {
            /* la riga con indice i ha i+1 elementi del triangolo */
            for(int j=0; j<=i; j++) {
                  /* il primo e l'ultimo elemento sono pari ad 1 */
                  if(j==0 || j==i)
                        matrice[i][j] = 1;
                  /* ciascun altro elemento e' pari alla somma dei due che gli stanno "sopra" */
                  else
                        matrice[i][j] = matrice[i-1][j-1] + matrice[i-1][j];
            }
            /* gli elementi successivi della riga sono pari a 0 */
            for(int j=i+1; j<n; j++)
                  matrice[i][j] = 0;
      }

      /* visualizza la matrice, allineando a sinistra gli elementi, non visualizzare gli 0.
            il triangolo visualizzato deve essere isoscele */
      printf("\nEcco la tua matrice:\n\n");
      for(int i=0; i<n; i++) {
            /* su una riga devi lasciare un numero iniziale di spazi bianchi pari a
             * 3 x (n-i-1) -- scelta di visualizzare ciascun numero con 3 caratteri */
             for(int j=1; j<=n-i-1; j++)
                   printf("%3c", ' ');
             /* ora visualizza i caratteri */
             for(int j=0; j<=i; j++) {
                   printf("%-3d", matrice[i][j]);
                   /* fra un carattere e l'altro lascia 3 spazi bianchi */
                   if(j<i)
                        printf("%3c", ' ');
             }
             printf("\n");
             system("PAUSE");

      }
}
