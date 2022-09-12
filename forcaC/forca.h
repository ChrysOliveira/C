void abertura();
int jaChutou(char letraChutada, char letrasChutadas[26]);
void desenhaForca(char palavraSecreta[20], char letrasChutadas[26], int tentativas);
void chutaLetra(int *tentativas, char letrasChutadas[26]);
int enforcou(int tentativa, int quantidadeDeTentativas, char letrasChutadas[26], char palavraSecreta[20]);
int ganhou(char palavraSecreta[20], char letrasChutadas[26]);
void escolhePalavra(char palavraSecreta[20]);
void adicionaPalavra();