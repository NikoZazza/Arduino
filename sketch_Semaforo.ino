int PIN_BTN = 7; /* Questa variabile indica la porta di aruino dove dobbiamo
                  * verificare se il buttone è premuto. Usare questa variabile
                  * semplifica molto la riusabilità del codice, infatti se cambiamo la porta
                  *  del sensore, basta cambiare questa variabile.    
                  */ 

int PIN_R = 3; // Indica la porta dove è collegato il led Rosso
int PIN_Y = 4; // Indica la porta dove è collegato il led Giallo
int PIN_G = 5; // Indica la porta dove è collegato il led Verde

int state = 0; /* Indica lo stato corrente, varia da 0 a 2 e significa: 
*/

/*
 * Questa funzione è chiamata una volta sola quando il programma viene fatto funzionare. 
 * E’ usata per inizializzare il pinMode e deve essere incluso in un programma, anche se non ci sono istruzioni da eseguire.
 * La funzione pinMode deve essere utilizzata SOLO per le porte digitali, per le porte analogiche non bisogna effettuare alcuna 
 * modifica al programma, basta solo fare analogRead().
 */
void setup() {
  pinMode(PIN_BTN, INPUT); // Imposta il pin del buttone come INPUT
  pinMode(PIN_R, OUTPUT); // Imposta il pin del buttone come OUTPUT
  pinMode(PIN_Y, OUTPUT); // Imposta il pin del buttone come OUTPUT
  pinMode(PIN_G, OUTPUT); // Imposta il pin del buttone come OUTPUT
}
/*  Questa funzione (che deve essere presente in ogni programma) viene eseguita di continuo da arduino, 
 *  finche non lo scolleghi dalla corrente. Considerando che Arduino va a 16.000Mhz, in 1ms questa funzione   
 *  verrà eseguita 16.000 volte, quindi in un secondo questa funzione verrà eseguita 16.000.000 volte.
 */
void loop() {
  if(digitalRead(PIN_BTN) == HIGH){ /* Controlliamo se il buttone è premuto, 
                                     * se è premuto restituisce HIGH (+5v), altrimenti se non è premuto restituisce LOW (-0v).
                                     * La funzione digitalRead è composta solo da un parametro: la porta digitale su cui vogliamo leggere il valore.
                                     * Se la porta digitale non è stata impostata su INPUT con la funzione pinMode, il programma non funzionerà.
                                      */
    state++; 
    delay(100); // Aspettiamo 100ms di secondo, se non aspettiamo, il programma andrebbe cosi veloce da cambiare lo stato dei led in brevissimo tempo.
  }
  if(state >= 3) // Se è acceso il led Verde, azzerra la variabile cosi si accenderà il led Rosso.
    state = 0;
  switch(state){ // In base allo stato della variabile, esegue una serie di funzioni
    case 0:
      digitalWrite(PIN_R, HIGH); // Accendiamo il led Rosso
      digitalWrite(PIN_Y, LOW); // Spegniamo il led Giallo
      digitalWrite(PIN_G, LOW); // Spegniamo il led Verde
      break;
    case 1:
      digitalWrite(PIN_R, LOW); // Spegniamo il led Rosso
      digitalWrite(PIN_Y, HIGH); // Accendiamo il led Giallo
      digitalWrite(PIN_G, LOW); // Spegniamo il led Verde
      break;
    case 2:
      digitalWrite(PIN_R, LOW); // Spegniamo il led Rosso
      digitalWrite(PIN_Y, LOW); // Spegniamo il led Giallo
      digitalWrite(PIN_G, HIGH); // Accendiamo il led Verde
      break;
  }
  delay(100); // Aspettiamo 100ms di secondo.
}
