//ATTENZIONE!!!
//NON PREMERE DUE PULSANTI CONTEMPORANEAMENTE
/*
 Si è reso necessario interdire la lettura dei tasti appena dopo che ne è stato
 letto uno, poichè altrimenti il pin impostato ad OUTPUT e HIGH a seguito della pressione di un tasto,
 viene letto come HIGH nella sezione del programma che legge i tasti e blocca il sistema.
*/

// vettori che rappresentano i due dischi
char disco_1[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char disco_2[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char disco_2_m[26];

// pin di ciascuna lettera
byte A = 22;
byte B = 23;
byte C = 24;
byte D = 25;
byte E = 26;
byte F = 27;
byte G = 28;
byte H = 29;
byte I = 30;
byte J = 31;
byte K = 32;
byte L = 33;
byte M = 34;
byte N = 35;
byte O = 36;
byte P = 37;
byte Q = 38;
byte R = 39;
byte S = 40;
byte T = 41;
byte U = 42;
byte V = 43;
byte W = 44;
byte X = 45;
byte Y = 46;
byte Z = 47;

// variabile che segue il percorso di criptazione dopo la pressione di un tasto
int indice;

// variabili di servizio
bool interdizione = false;

// variabili di lettura della combinazione
String stringa;
int s = 0;

// variabili per il tempo
unsigned long t = 0;
int t_out = 20;


void setup() {
  Serial.begin(9600);
  Serial.println("Inizializzazione");
  
  // Eseguo una demo per controllare i led e i collegamenti
  
  // Imposto ogni pin ad output e li accendo tutti in sequenza
  for(int a=22;a<=47;a++) {
    pinMode(a,OUTPUT);
    digitalWrite(a,HIGH);
    delay(50);
    digitalWrite(a,LOW);
  }
  
  // Imposto tutti i pin a input
  for(int a=22;a<=47;a++) {
    pinMode(a,INPUT);
  }
  
  // Allineo il secondo disco e lo stampo
  for(int a=0;a<=25;a++) {
    disco_2_m[a] = disco_2[a];
    Serial.print(disco_2_m[a]);
  }
  Serial.print("\n");
  
  Serial.println("Fine inizializzazione");
}



// Funzione che restituisce l'indice fisso a cui è collegata la lettera sul secondo disco (correlazioni riflessore)
int relazioneFissa(int i) {
  int b = 0;
  
  switch(disco_2_m[i]) {
    
    case 'A':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'F') {
        b = a;
        break;
      }
    }
    break;
    
    case 'B':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'V') {
        b = a;
        break;
      }
    }
    break;
    
    case 'C':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'P') {
        b = a;
        break;
      }
    }
    break;
    
    case 'D':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'J') {
        b = a;
        break;
      }
    }
    break;
    
    case 'E':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'I') {
        b = a;
        break;
      }
    }
    break;
    
    case 'F':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'A') {
        b = a;
        break;
      }
    }
    break;
    
    case 'G':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'O') {
        b = a;
        break;
      }
    }
    break;
    
    case 'H':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'Y') {
        b = a;
        break;
      }
    }
    break;
    
    case 'I':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'E') {
        b = a;
        break;
      }
    }
    break;
    
    case 'J':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'D') {
        b = a;
        break;
      }
    }
    break;
    
    case 'K':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'R') {
        b = a;
        break;
      }
    }
    break;
    
    case 'L':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'Z') {
        b = a;
        break;
      }
    }
    break;
    
    case 'M':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'X') {
        b = a;
        break;
      }
    }
    break;
    
    case 'N':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'W') {
        b = a;
        break;
      }
    }
    break;
    
    case 'O':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'G') {
        b = a;
        break;
      }
    }
    break;
    
    case 'P':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'C') {
        b = a;
        break;
      }
    }
    break;
    
    case 'Q':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'T') {
        b = a;
        break;
      }
    }
    break;
    
    case 'R':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'K') {
        b = a;
        break;
      }
    }
    break;
    
    case 'S':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'U') {
        b = a;
        break;
      }
    }
    break;
    
    case 'T':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'Q') {
        b = a;
        break;
      }
    }
    break;
    
    case 'U':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'S') {
        b = a;
        break;
      }
    }
    break;
    
    case 'V':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'B') {
        b = a;
        break;
      }
    }
    break;
    
    case 'W':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'N') {
        b = a;
        break;
      }
    }
    break;
    
    case 'X':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'M') {
        b = a;
        break;
      }
    }
    break;
    
    case 'Y':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'H') {
        b = a;
        break;
      }
    }
    break;
    
    case 'Z':
    for(int a=0;a<=25;a++) {
      if(disco_2_m[a] == 'L') {
        b = a;
        break;
      }
    }
    break;
    
  }
  return b;
}


// Funzione che dà l'output
void output(int i) {
  
  switch(disco_1[i]) {
    
    case 'A':
    pinMode(A,OUTPUT);
    digitalWrite(A,HIGH);
    Serial.println("A acceso");
    break;

    case 'B':
    pinMode(B,OUTPUT);
    digitalWrite(B,HIGH);
    break;

    case 'C':
    pinMode(C,OUTPUT);
    digitalWrite(C,HIGH);
    break;

    case 'D':
    pinMode(D,OUTPUT);
    digitalWrite(D,HIGH);
    break;

    case 'E':
    pinMode(E,OUTPUT);
    digitalWrite(E,HIGH);
    break;

    case 'F':
    pinMode(F,OUTPUT);
    digitalWrite(F,HIGH);
    break;
    
    case 'G':
    pinMode(G,OUTPUT);
    digitalWrite(G,HIGH);
    break;

    case 'H':
    pinMode(H,OUTPUT);
    digitalWrite(H,HIGH);
    break;

    case 'I':
    pinMode(I,OUTPUT);
    digitalWrite(I,HIGH);
    break;

    case 'J':
    pinMode(J,OUTPUT);
    digitalWrite(J,HIGH);
    break;

    case 'K':
    pinMode(K,OUTPUT);
    digitalWrite(K,HIGH);
    break;

    case 'L':
    pinMode(L,OUTPUT);
    digitalWrite(L,HIGH);
    break;

    case 'M':
    pinMode(M,OUTPUT);
    digitalWrite(M,HIGH);
    break;

    case 'N':
    pinMode(N,OUTPUT);
    digitalWrite(N,HIGH);
    break;

    case 'O':
    pinMode(O,OUTPUT);
    digitalWrite(O,HIGH);
    break;

    case 'P':
    pinMode(P,OUTPUT);
    digitalWrite(P,HIGH);
    break;

    case 'Q':
    pinMode(Q,OUTPUT);
    digitalWrite(Q,HIGH);
    break;

    case 'R':
    pinMode(R,OUTPUT);
    digitalWrite(R,HIGH);
    break;

    case 'S':
    pinMode(S,OUTPUT);
    digitalWrite(S,HIGH);
    break;

    case 'T':
    pinMode(T,OUTPUT);
    digitalWrite(T,HIGH);
    break;

    case 'U':
    pinMode(U,OUTPUT);
    digitalWrite(U,HIGH);
    Serial.println("U acceso");
    break;

    case 'V':
    pinMode(V,OUTPUT);
    digitalWrite(V,HIGH);
    break;

    case 'W':
    pinMode(W,OUTPUT);
    digitalWrite(W,HIGH);
    break;

    case 'X':
    pinMode(X,OUTPUT);
    digitalWrite(X,HIGH);
    break;

    case 'Y':
    pinMode(Y,OUTPUT);
    digitalWrite(Y,HIGH);
    break;

    case 'Z':
    pinMode(Z,OUTPUT);
    digitalWrite(Z,HIGH);
    break;
  }
  
}

// Funzione che azzera (spegne e imposta a input)
void azzera() {
  Serial.println("spengo tutto");
  for(int a=22;a<=47;a++) {
    digitalWrite(a,LOW);
  }
  
  for(int a=22;a<=47;a++) {
    pinMode(a,INPUT);
  }
}


void loop() {
  
  // LETTURA COMBINAZIONE
  if(Serial.available() > 0) {
    // allineo il secondo disco modificato al disco 2
    for(int a=0;a<=25;a++) {
      disco_2_m[a] = disco_2[a];
    }
    // leggo dalla seriale lo spostamento del disco
    stringa = Serial.readString();
    s = stringa.toInt();
    if(s>=0 && s<=25) {
      // scifto il disco modificato avanti di 1 per 's' volte
      for(int a=1;a<=s;a++) {
        char d = disco_2_m[0];
        for(int c=0;c<=24;c++) {
          disco_2_m[c] = disco_2_m[c+1];
        }
        disco_2_m[25] = d;
      }
      // stampo il vettore sciftato
      for(int a=0;a<=25;a++) {
        Serial.print(disco_2_m[a]);
      }
      Serial.print("\n");
    }
    else {
      Serial.println("Numero non valido");
    }
  }
  
  // LETTURA TASTIERA
  if(!interdizione) {
    for(int a=22;a<=47;a++) {
      if(digitalRead(a)) {
        indice = a-22;
        indice = relazioneFissa(indice);
        output(indice);
        interdizione = true;
        t = millis();
        break;
      }
    }
  }
  
  // AZZERAMENTO (dopo il tempo di output)
  if((millis()-t >= t_out) && interdizione) {
    azzera();
    interdizione = false;
  }
  
}
