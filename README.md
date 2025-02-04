# Temporizador Periódico - Wokwi

## Autor
**Kauan Souza Teles**

## Descrição
Este projeto implementa um temporizador periódico utilizando a Raspberry Pi Pico. O código acende sequencialmente três LEDs (
vermelho, amarelo e verde) a cada 3 segundos. O código foi testado e executado no simulador [Wokwi](https://wokwi.com/).

## Componentes Utilizados
- Raspberry Pi Pico
- LED vermelho (conectado ao pino 11)
- LED amarelo (conectado ao pino 12)
- LED verde (conectado ao pino 13)

## Funcionamento
1. Inicializa os pinos de saída para os LEDs.
2. Define um temporizador periódico que executa a função `repeating_timer_callback` a cada 3 segundos.
3. A função `repeating_timer_callback`:
   - Desliga todos os LEDs.
   - Liga o LED correspondente ao estado atual.
   - Alterna entre os estados 0 (vermelho), 1 (amarelo) e 2 (verde).
4. No loop principal, exibe o estado atual no terminal a cada segundo.

## Como Executar no Wokwi
1. Abra o projeto no vscode
2. Use a extensão do Wokwi do vscode
3. Compile o codigo fonte
4. Execute o diagrama que está no arquivo diagram.json