/*
Questo programma esegue un quiz di tre domande, ciascuna con tre opzioni possibili.
Funzionamento:
1. Mostra all'utente una breve introduzione del gioco;
2. Mostra all'utente un menu di scelta A)Inizia partita B)Esci dal gioco; Gestisce convalida input diverso da A o B;
3. Riceve nome in input in caso di nuova partita;
4. Presenta un set di domande e accetta la risposta dell'utente da input;
5. Aggiorna il punteggio dell'utente in base alle risposte corrette;
6. Mostra il punteggio alla fine del gioco e ripropone il Menu iniziale all'utente. 
*/


#include <stdio.h>

// Definizioni dei colori
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

// La funzione introduzione presenta il gioco all'utente
void introduzione() {
    printf(CYAN "\t\t\tBenvenuto nel quiz!\n" RESET);
    //printf("\n******************");
    printf("\nTi verrà fatta una domanda per volta e dovrai scegliere la risposta corretta.\n");
    printf("Ogni risposta corretta vale 1 punto.\n");
    printf("Rispondi correttamente a tutte le domande per ottenere il punteggio più alto possibie.\n");
    //printf("******************");
}

// La funzione stampaMenu presenta il Menu all'utente
void stampaMenu() {
    printf(YELLOW "\n\tMenu:\n" RESET);
    printf("======================\n");
    printf("\nA) Inizia una nuova partita\n");
    printf("\nB) Esci dal gioco\n");
}

// La funzione giocaPartita contiene funzioni e condizioni per giocare la partita o uscire dal gioco
void giocaPartita(){

    char nome[20] = {'\0'};
    // 1D Array, contiene domande
    char *domande[] = {
        "In quale Paese si trova il Fuji?",
        "In che anno ebbe luogo la Rivoluzione Francese?",
        "Qual è il pianeta più vicino al sole?"
    };
    
    // 2D Array, contiene risposte
    char *risposte[][3] = {
        {"Giappone", "Cina", "Corea"},
        {"1792", "1492", "1789"},
        {"Venere", "Terra", "Mercurio"}
    };

    // Indica le risposte corrette
    char risposteCorrette[] = {1, 3, 3};

    // Variabile per salvare e aggiornare il punteggio in fase di iterazione loop
    int punteggio = 0;

    char scegli = '\0';

    // Gioca la partita se l'utente non sceglie di uscire dal gioco
    while (scegli != 'B'){
		stampaMenu();
		printf(BLUE"\n\nCosa vuoi fare? Scegli un'opzione.\n\n"RESET);
		scanf(" %c", &scegli); //eventuali valori residui, come \n, verranno cancellati  dal buffer
        
        // Switch per presentare il menu o uscire in base alla scelta dell'utente
		switch (scegli) 
		{
			case'A':
			case'a'://Esegue fino al break
                printf("\nInserisci il tuo nome: \n\n");
                scanf(" %s", nome); // Ottiene il nome dell'utente
                printf(CYAN"\n\nPerfetto %s, iniziamo a giocare!\n"RESET, nome);
				//Percorre l'array per porre le domande
                for (int i = 0; i < 3; i++) {
                    printf("\nDomanda %d: %s\n", i + 1, domande[i]);
                    for (int j = 0; j < 3; j++) {
                        printf("%d) %s\n", j + 1, risposte[i][j]);
                    }
                    printf("\nRisposta: \n\n");  
                    int risposta;
                    scanf("%d", &risposta);
                    
                    // In caso di risposta corretta, incrementa la variabile punteggio di 1
                    if (risposta == risposteCorrette[i]) {
                        printf(GREEN"\n Corretto!\n"RESET);
                        punteggio++;
                    }
                    else {
                        printf(RED"\nSbagliato! La risposta corretta era: %s \n" RESET, risposte[i][risposteCorrette[i]-1]);
                    }
                }
                printf("\n" MAGENTA "%s, il tuo punteggio finale è: %d\n" RESET, nome, punteggio);
				break;
			case 'b':
			scegli = 'B';
				printf(GREEN "\nGrazie per aver giocato! Arrivederci!" RESET);
				break;
			default:
				printf(RED "Scelta non valida. Per favore, riprova: " RESET);
                getchar() != '\n'; // Pulisce il buffer
			break;
		}
	}
}

int main() {
    introduzione();
    giocaPartita();
    return 0;
}