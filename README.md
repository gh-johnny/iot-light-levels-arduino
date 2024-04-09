# Light level sensor  🕶 ☀ 

por:
<ul>
<li>Gabriel Barros Cisoto (RM556309)</li>
<li>Pedro Henrique Bizzo de Santana (RM557263)</li>
<li>Pedro Henrique Mendes dos Santos (RM555332)</li>
<li>João Marcelo Furtado Romero (RM555199)</li>
</ul>

<img src="https://github.com/gh-johnny/iot-light-levels-arduino/blob/main/docs/assets/tinkercad-arduino-circuit-printscreen.png?raw=true" alt="print do circuito Arduino/printscreen Arduino circuit"/> 

Link da simulação no <a href=" https://www.tinkercad.com/things/59KuVGgGDhh-glorious-allis-wolt/editel?sharecode=39sw8oEFMq6_Gm3jGtfpTENYOuERSUefURVV_2nzQSM">Tinkercad</a>
<br />
<br />
🇧🇷 - Um programa que mede o nível de luminosidade através de um LDR (Light Dependent Resistor). Esses níveis de luz são visualizados através dos LEDs sendo: 
<br/>
<br/>
<ul>
<li>
    🟢 verde: sem luminosidade ou pouca (ok), 
</li>
<li>
    🟡 amarelo + beep🎵:  luminosidade média (em alerta) 
</li>
<li>
    🔴 vermelho: muita luminosidade (crítico).
</li>
</ul>

## Explicando o <a href="https://github.com/gh-johnny/iot-light-levels-arduino/blob/main/arduino.c">Código</a>

Inicializando os 'ints' antes das funções 'setup' e 'loop' para nossa aplicação já ter acesso a tais valores e variáveis
```c
int ldr_value;
int ldr_good = 790;
int ldr_critic = 870;
```

<hr />

Fazendo o setup do Arduino. Neste passo, diremos ao nosso programa que utilizaremos os pinos de modo saída para poder então enviar sinais
```c
void setup() {
  pinMode(12, OUTPUT);  // LED 🔴 vermelho
  pinMode(11, OUTPUT);  // LED 🟡 amarelo
  pinMode(10,OUTPUT);   // LED 🟢 verde
  pinMode(8, OUTPUT);   // Beep 🎵 
}
```

<hr />
Fazendo o loop do Arduino. Neste passo é onde a lógica principal do programa ocorre.

<br />

Começamos atribuindo o valor analógico do LDR para termos o mesmo sempre atualizado.
E como este código roda em loop quaisquer alterações no valor do LDR são capturadas

```c
void loop() { // Note que não fechamos a função ainda!

    ldr_value = analogRead(0);

```

<hr />

A primeira condição é verificada, se o valor atual do LDR for menor ou igual ao valor que representa o nível aceitável de luminosidade (aquele pré-estabelecido por nós no começo da aplicação), o código do qual acende o LED verde e apaga os outros LED's é executado

```c
    if(ldr_value <= ldr_good)
    {
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
    }
```

<hr />

Caso o valor do LDR for acima do valor que representa um nível aceitável e menor que o valor que representa o nível crítico, significa que ele está em nível de alerta. 
Nesse caso, o código que acende o LED amarelo, apaga os outros e toca especificamente a nota Lá por 3 segundos em intervalos de 2 segundos é executado

```c
    else if((ldr_value > ldr_good) && (ldr_value < ldr_critic))
    {
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      
      tone(8, 440);
      delay(3000);
      noTone(8);
      delay(2000);
    }
```

<hr />

Por último, se nenhuma das outras condições forem satisfeitas, ou seja, o valor do LDR for maior ou igual a aquele que representa o valor do nível crítico, o código que acende o LED vermelho e apaga os outros é executado

```c
    else
    { 
       digitalWrite(12, HIGH);
       digitalWrite(11, LOW);
       digitalWrite(10, LOW);
     }
} // Fechamento da função loop
```
