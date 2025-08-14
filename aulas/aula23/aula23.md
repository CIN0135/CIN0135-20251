# Laboratório: Árvores N-árias

Em vários jogos entre dois oponentes, como o Xadrez, temos uma determinada configuração (ou *estado*) inicial do jogo `S0`, sobre a qual os oponentes realizam jogadas de forma alternada, modificando progressivamente o estado corrente do jogo: `S0→S1→S2→S3→...`. Dado uma determinada configuração, `Si`, podemos ter 0 ou mais jogadas válidas. Por exemplo, a partir da configuração inicial do Xadrez, temos 20 jogadas válidas para as peças brancas (avançar uma ou duas casas com cada um dos peões além de duas jogadas possíveis para cada cavalo). Caso não haja nenhuma jogada válida, temos uma **configuração final** que indica que o jogo terminou, sendo possível determinar quem venceu ou se houve um empate. 

Dessa forma, um jogo assim pode ser representado por uma árvore N-ária em que cada nó corresponde a um estado do jogo, e os seus filhos correspondem aos estados alcançáveis a partir dele via jogadas válidas. As folhas da árvore correspondem a configurações finais.

No **Jogo do Cuscuz** (assim batizado por analogia a uma saudável brincadeira de criança brasileira) temos inicialmente um monte (o cuscuz) de tamanho `N` (inteiro positivo). Cada um dos oponentes pode retirar, alternadamente, um pedaço do cuscuz de tamanho `P` de `1` a `M < N`. Sendo `P1, P2, P3,...` os pedaços retirados alternadamente pelos dois jogadores, o cuscuz terá os tamanhos `S0=N, S1=S0-P1, S2=S1-P2, S3=S2-P3,...`, sendo esses os **estados** do jogo. O jogo termina quando o cuscuz acaba, ou seja `Si=0`, e vence o jogador que retirou o último pedaço do cuscuz.


## Tarefa 1:

Escrever um programa que lê `N` e `M` e constrói a árvore N-ária correspondente a todas as possíveis partidas do jogo do cuscuz com essa configuração.

## Tarefa 2:

Dada uma sequência de retiradas `P1, P2,..., Pk` determinar se o próximo jogador a jogar tem uma estratégia vencedora, ou seja, se ele ainda pode vencer a partir da próxima jogadas.

### Exemplo

Se `N=10, M=3`, e a sequência de retiradas é `P1=3, P2=2`, então o jogador #1 tem uma estratégia vencedora. Porém, se a sequência for `P1=3, P2=3, P3=1` então o jogador #2 não tem estratégia vencedora.
