/*
Questo programma esegue un quiz di tre domande, ciascuna con tre opzioni possibili.
Funzionamento:
1. Mostra all'utente una breve introduzione del gioco;
2. Mostra all'utente un menu di scelta A)Inizia partita B)Esci dal gioco; Gestisce convalida input diverso da A o B;
3. Riceve nome in input in caso di nuova partita; Convalida input nome utente;
4. Presenta un set di domande e accetta la risposta dell'utente da input; Convalida input risposta utente;
5. Aggiorna il punteggio dell'utente in base alle risposte corrette;
6. Mostra il punteggio alla fine del gioco e ripropone il Menu iniziale all'utente.
*/

#include <stdio.h>
#include <string.h> //per funzioni di manipolazione stringhe

// Definizioni dei colori
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

// La funzione introduzione presenta il gioco all'utente
void introduzione()
{
    printf(CYAN "\t\t\tBenvenuto nel quiz!\n" RESET);
    printf("\n\nTi verrà fatta una domanda per volta e dovrai scegliere la risposta corretta.\n");
    printf("\n\nOgni risposta corretta vale 1 punto.\n");
    printf("\n\nRispondi correttamente a tutte le domande per ottenere il punteggio più alto possibie.\n");
}

// La funzione stampaMenu presenta il Menu all'utente
void stampaMenu()
{
    printf(YELLOW "\n\tMenu:\n" RESET);
    printf("======================\n");
    printf("\nA) Inizia una nuova partita\n");
    printf("\nB) Esci dal gioco\n");
}

// Il puntatore *nome punta alla memoria che contiene la stringa di caratteri char nome
// Il valore int della variabile lunghezza controlla che i caratteri non superino la lunghezza massima consentita
void nomeUtente(char *nome, int lunghezza)
{
    int nomeValido = '\0';
    while (!nomeValido)
    {
        printf("\nInserisci il tuo nome (massimo %d caratteri): \n", lunghezza - 1);
        printf("\n");
        scanf(" %[^\n]", nome); // Legge tutti i caratteri (nome completo inclusi spazi)fino al carattere di new line
        fgets(nome + strlen(nome), lunghezza - strlen(nome), stdin);
        if (strlen(nome) >= lunghezza)
        {
            printf(RED "Il tuo nome è troppo lungo! Per favore, inserisci un nome di al massimo 19 caratteri (spazi inclusi).\n" RESET);
            getchar() != '\n'; // Pulisce il buffer
        }
        else
        {
            nome[strcspn(nome, "\n")] = '\0'; // Trova la posizione del newline nel nome e, se presente, assegna a quella posizione il marker di endpoint della stringa '\0'
            nomeValido = 1;                   // Se il nome è valido, esce dal loop
            printf(CYAN "\nCiao %s, iniziamo a giocare!\n" RESET, nome);
        }
    }
}

// La funzione giocaPartita contiene funzioni e condizioni per giocare la partita o uscire dal gioco
void giocaPartita()
{

    char nome[20] = {'\0'};

    // 1D Array, contiene domande
    char *domande[] = {
        "In quale Paese si trova il Fuji?",
        "In che anno ebbe luogo la Rivoluzione Francese?",
        "Qual è il pianeta più vicino al sole?"};

    // 2D Array, contiene risposte
    char *risposte[][3] = {
        {"Giappone", "Cina", "Corea"},
        {"1792", "1492", "1789"},
        {"Venere", "Terra", "Mercurio"}};

    // Indica le risposte corrette
    char risposteCorrette[] = {1, 3, 3};

    // Variabile per salvare e aggiornare il punteggio in fase di iterazione loop
    int punteggio = '\0';

    char scegli = '\0';

    // Gioca la partita se l'utente non sceglie di uscire dal gioco
    while (scegli != 'B')
    {
        stampaMenu();
        printf(BLUE "\n\nCosa vuoi fare? Scegli un'opzione.\n\n" RESET);
        scanf(" %c", &scegli); // eventuali valori residui, come \n, verranno cancellati  dal buffer

        // Switch per presentare il menu o uscire in base alla scelta dell'utente
        switch (scegli)
        {
        case 'A':
        case 'a': // Esegue fino al break
            nomeUtente(nome, sizeof(nome));
            // Percorre l'array per porre le domande
            for (int i = 0; i < 3; i++)
            {
                printf("\nDomanda %d: %s\n", i + 1, domande[i]);
                for (int j = 0; j < 3; j++)
                {
                    printf("%d) %s\n", j + 1, risposte[i][j]);
                }
                printf("\nRisposta: \n\n");
                int risposta;
                int inputValido = '\0';
                // Ciclo `while` per gestire input non valido
                while (!inputValido)
                {
                    if (scanf(" %d", &risposta) != 1 || risposta < 1 || risposta > 3)
                    {
                        printf(RED "Risposta non valida. Inserisci un numero tra 1 e 3. \n" RESET);
                        printf("\nLa tua risposta: \n\n");
                        getchar() != '\n';
                    }
                    else
                    {
                        inputValido = 1;
                        break; // Esce dal ciclo while se l'input è valido
                    }
                }

                // In caso di risposta corretta, incrementa la variabile punteggio di 1
                if (risposta == risposteCorrette[i])
                {
                    printf(GREEN "\n Corretto!\n" RESET);
                    punteggio++;
                }
                else
                {
                    printf(RED "\nSbagliato! La risposta corretta era: %s \n" RESET, risposte[i][risposteCorrette[i] - 1]);
                }
            }
            printf("\n" MAGENTA "%s, il tuo punteggio finale è: %d\n" RESET, nome, punteggio);
            break; // Esce dal ciclo dopo aver completato il gioco

        case 'b':
            scegli = 'B';
            printf(GREEN "\nGrazie per aver giocato! Arrivederci!\n" RESET);
            break;
        default:
            printf(RED "\nScelta non valida. Per favore, riprova.\n" RESET);
            getchar() != '\n'; 
            break;
        }
    }
}

int main()
{
    introduzione();
    giocaPartita();
    return 0;
}