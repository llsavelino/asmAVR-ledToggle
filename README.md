<img width="100%" src="https://capsule-render.vercel.app/api?type=transparent&height=300&color=gradient&text=asmAVR-ledToggle&fontAlignY=45&descAlign=100&descAlignY=37"/>

![AVR](https://img.shields.io/badge/AVR-Assembly-6E4C13?style=flat&logo=gnu&logoColor=white)
![License](https://img.shields.io/github/license/llsavelino/asmAVR-ledToggle?color=blue)
![Version](https://img.shields.io/badge/version-1.0.0-orange)
![Assembly](https://img.shields.io/badge/Assembly-71.8%25-blueviolet)
![C++](https://img.shields.io/badge/C++-28.2%25-00599C?style=flat&logo=c%2B%2B&logoColor=white)

Um exemplo simples (e propositalmente complicado) de como piscar um LED usando Assembly no AVR, mostrando os detalhes de baixo nível do controle de hardware.

## 🔎 Visão Geral

Este projeto demonstra como acionar um LED em placas baseadas em AVR (como o Arduino Uno) utilizando Assembly puro, ilustrando o funcionamento direto do hardware sem abstrações.

- ✅ Controle preciso dos registradores do microcontrolador  
- 🛠️ Exemplo didático para aprender Assembly AVR  
- 🔬 Sem dependência de bibliotecas externas ou Arduino IDE  
- 💡 Código comentado e organizado para estudo  

### 🟢 Veja em ação

<p align="center">
  <img src="https://blog.eletrogate.com/wp-content/uploads/2023/06/giphy.gif" alt="Demonstração da bomba em funcionamento" width="500"/>
</p>


## 🚀 Funcionalidades Principais

| Feature                     | Descrição                               | Exemplo                        |
| --------------------------- | --------------------------------------- | ------------------------------ |
| ⚡ Controle do LED           | Liga/desliga LED via registrador        | `sbi PORTB, PB5`               |
| ⏱️ Delay Manual             | Rotinas de atraso em Assembly           | Loop de decremento             |
| 📝 Código Didático          | Comentários explicativos no Assembly    | `; Inicia loop de delay`       |
| 🤓 Alternativa em C++       | Versão equivalente em C++ para estudo   | `digitalWrite(LED_BUILTIN, 1);` |

## 📦 Como Rodar

1. **Clone o Repositório**:

   ```bash
   git clone https://github.com/llsavelino/asmAVR-ledToggle.git
   cd asmAVR-ledToggle
   ```

2. **Compile o Assembly** (usando avr-gcc):

   ```bash
   avr-gcc -mmcu=atmega328p -nostartfiles -o led.elf led.asm
   avr-objcopy -O ihex led.elf led.hex
   ```

3. **Grave na Placa** (exemplo com avrdude):

   ```bash
   avrdude -c arduino -p m328p -P /dev/ttyACM0 -b 115200 -U flash:w:led.hex
   ```

   > Ajuste o parâmetro `-P` conforme a porta USB da sua placa.

## 💻 Exemplo de Código

### Assembly (led.asm)

```assembly
; pisca LED no pino PB5 (Arduino Uno LED_BUILTIN)
ldi r16, (1<<PB5)
out DDRB, r16
loop:
    sbi PORTB, PB5    ; Liga LED
    rcall delay
    cbi PORTB, PB5    ; Desliga LED
    rcall delay
    rjmp loop

delay:
    ldi r18, 255
del1:
    ldi r19, 255
del2:
    dec r19
    brne del2
    dec r18
    brne del1
    ret
```

### C++ Equivalente (Para referência)

```cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
```

## 📚 Estrutura do Projeto

- `led.asm` — Código principal em Assembly
- `led.cpp` — (Opcional) Versão em C++ para comparação
- `README.md` — Documentação e instruções

## 🤝 Contribuição

Contribuições são bem-vindas!

[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](https://github.com/llsavelino/asmAVR-ledToggle/pulls)

1. Reporte bugs via Issues
2. Envie Pull Requests com melhorias ou exemplos
3. Compartilhe experiências de uso

---

> “Piscar um LED nunca foi tão trabalhoso — e educativo!”
