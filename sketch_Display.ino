int PIN_LUX = A0; /*  Questa variabile indica la porta di aruino dove dobbiamo
                   *  leggere il valore (Analogico) del fotoresistore. Usare questa variabile
                   *  semplifica molto la riusabilità del codice, infatti se cambiamo la porta
                   *  del sensore, basta cambiare questa variabile.    
                   */
int val = 0;      /*  Questa variabile serve a memorizzare il valore letto dal sensore
                   *  collegato alla porta PIN_LUX. Questo valore analogico ha un range da 0 a 1024.
                   */
#include <LiquidCrystal.h>  // Qui importiamo la libreria del display lcd.
                             
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // Dichiariamo la variabile lcd specificando le porte che sono connessi al display
/*
 * Questa funzione è chiamata una volta sola quando il programma viene fatto funzionare. 
 * E’ usata per inizializzare il pinMode e deve essere incluso in un programma, anche se non ci sono istruzioni da eseguire.
 * La funzione pinMode deve essere utilizzata SOLO per le porte digitali, per le porte analogiche non bisogna effettuare alcuna 
 * modifica al programma, basta solo fare analogRead().
 */
void setup() {
  lcd.begin(16, 2);   /* Indichiamo la grandezza del nostro lcd. Ogni lcd è considerato come una matrice, in questo caso 
                       * una matrice 16x2, cioè il nostro display è composto da due righe dove ogni riga può contenere al massimo 16 caratteri.                      *
                       */
  lcd.setCursor(0, 0);  // Indichiamo la posizione dove vogliamo scrivere qualcosa, in questo caso puntiamo la prima riga e la prima lettera.
  lcd.print("Gruppo n.5");  // Scrive sul display a partire dalla posizione 0 e dalla prima riga "Gruppo n.5".
  delay(2000); // Attendiamo 2sec prima che il programma inizi a leggere i valori dal fotosensore.
}
/*  Questa funzione (che deve essere presente in ogni programma) viene eseguita di continuo da arduino, 
 *  finche non lo scolleghi dalla corrente. Considerando che Arduino va a 16.000Mhz, in 1ms questa funzione   
 *  verrà eseguita 16.000 volte, quindi in un secondo questa funzione verrà eseguita 16.000.000 volte.
 */
void loop() {
  val = analogRead(PIN_LUX); // Leggiamo il valore analogico della porta PIN_LUX e lo inseriamo nella variabile val
  lcd.setCursor(0, 2);  // Indichiamo la posizione dove vogliamo scrivere qualcosa, in questo caso puntiamo la seconda riga e la prima lettera. 
  lcd.print("               ");  /* Cancelliamo i valori stampati precedentemente cosi il valore letto sarà quello reale. Da notare lo spazio visto che 
                                  * dobbiamo cancellare il vecchio valore e scriverne un'altro, i caratteri vuoti verranno scritti sul display. (Ci sono 16 spazi)
                                  */
  lcd.setCursor(0, 2); // Indichiamo la posizione dove vogliamo scrivere qualcosa, in questo caso puntiamo la seconda riga e la prima lettera.  
  lcd.print(val); // Scriviamo sul display il valore prelevato nella seconda riga 
  delay(300); /* Aspettiamo 300ms di secondo, serve questa pausa visto che al convertitore Analogico/Digitale servono circa 20ms
               * solo per prelevare un valore senza avere dei "difetti". Il valore impostato a 300ms permette la visualizzazione
               * della variazione della luminosità.
               */
}
