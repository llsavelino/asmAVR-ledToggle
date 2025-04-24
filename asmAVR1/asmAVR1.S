; [_] aves06914@gmail.com / savelino852@gmail.com [_]
;$--------------------------$
#define __SFR_OFFSET 0x00  
; ~~~~~~~~~~~~~~~~~~~~~~~~~ ; ~~~ alternativa para 0x20 ~~~
;.,.,.,.,.,.,.,.,.,.,.,.,.,.,
#include "avr/io.h"
;$--------------------------$
.org 0x0000                 ; [Colacoremos o programa asm no endereço de mémoria 0x00]
  JMP led_off               ;
;$=_=_=_=_=_=_=_=_=_=_=_=_=_$
; #$ Assembly coding $#
;-.-.-.-.-.-.-.-.-.-.-.-.-.-.
.text                       ; # A partir daqui, vem código que será carregado para execução, na CPU.
;............................
; ~~ Etiquetas / funções ~~
.global               start ; | <- pode ser chamado pela linguamgem C ou C++ por ser global.
.global                 led ; | <- pode ser chamado pela linguamgem C ou C++ por ser global.
.global               tenLed; | <- pode ser chamado pela linguamgem C ou C++ por ser global.
;............................
;<><><><><><>:::><><><><><><>
start:
;.,.,.,.,.,.,.,.,.,.,.,.,.,.,
  LDI r18, (0x80)           ; pino 13.
    OUT DDRB, r18           ; [set Bit]: colacamos OUTPUT em reg DDRB.
  EOR r18, r18              ; Zeramos r18 com xor -> opicional.
    OUT PORTB, r18          ; Inicializa reg PORTB -> opicinal.
  NOP                       ; No operation -> opicional.
RET                         ; [retorno tipo void]
;............................
led:                        ; # label recebe argumento do tipo int.
;.,.,.,.,.,.,.,.,.,.,.,.,.,.,
  CPI r24, (0x00)           ; [Compare with Immediate]: compararemos valor de r24 com (0).
  BREQ led_off              ; Caso os valores for iguais linha ignorada. 
  SBI PORTB, (0x05)         ; Acende o led.
  RCALL myDelay             ; Solicitação de delay.
RET                         ; [retorno tipo void]
;............................
led_off:                    ; # aux label
;.,.,.,.,.,.,.,.,.,.,.,.,.,.,
  CBI PORTB, (0x05)         ; Apaga o led.
  RCALL myDelay             ; Solicitação de delay.
RET                         ; [retorno tipo void].
;$--------------------------$
.equ delayValue, (0xCAFE)   ; Diretiva constante para [milisegundos]: ( ? ) Será usada na etiqueta delay.
;$--------------------------$
tenLed:
;#¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨#
  CPI r24, (0x00)           ; Verica se o argumento foi passado
  BRNE checklimits          ; Se sim passa para a checagem
  LDI r24, (0x0A)           ; Caso contrário recebe o argumento padrão
  RJMP arg                  ; e pulamos para fluxo normal
  checklimits:
    CPI r24, (0x10)         ; Verifica se é maior que 16
    BRLO arg                ; Se sim segue o fluxo normal
    LDI r24, (0x0F)         ; Caso contrário recebe 15 e fluxo segue normamente
  arg:
    MOV r18, r24            ; Argumento guardado em r24 registrador especial que pode receber args no AVR.
  ;#........................#
  LDI r16, (0x00)           ;
    MOV r20, r16            ; movemos 0 para r20.
  ;%"'"'"'"'"'"'"'"'"'"'"''"%
  CBI PORTB, (0x05)         ; Começa desligado.
  ;%"'"'"'"'"'"'"'"'"'"'"''"%
  placing:
  ; Etiqueta auxiliar...
  ;$~~::---------------::~~~$
    INC r20                 ; Incrementamos r20 até X.
    ;""""""""""""""""""""""""
      CP r20, r18           ; Caso r20 for igual ao argumento passamos para próxima etiqueta.
    ;""""""""""""""""""""""""
    BRLO placing            ; Caso iguais ignoramos essa intrução.
  ;$~~::---------------::~~~$
  __Again__:
  NOP                       ;
  RCALL myDelay             ; Delay.
  ;'"'"'"'"'"'"'"'"'"'"'"'"'"
    IN r16, PINB            ; Lê o estado atual dos pinos do porto B e armazena em r16.
      LDI r17, 0x80         ; r17 recebe 0b10000000.
      EOR r16, r17          ; Lógica xor nos regs 16 e 17.
    OUT PORTB, r16          ; Escrevemos r16 em PORTB.
  ;"'"'"'"'"'"'"'"'"'"'"'"'"'
  RCALL myDelay             ; Delay.
    SUBI r20, 0x01          ; Decrementamos rX até 0.
  BRNE __Again__            ; Diferente de 0 repete a etiqueta.
  ;''''''''''''''''''''''''''
  ; EOR (r18), (r18)        ; Foi descartado.
  ; EOR (r24), (r24)        ; Foi descartado.
  ;''''''''''''''''''''''''''
  NOP                       ; Nada.
  NOP                       ; Nada.
RJMP led_off                ; jump off.
;+-+-+-+-+-+-+-+-+-+-+-+-+-+-
myDelay:                    ; # aux label
;____________________________
;.,.,.,.,.,.,.,.,.,.,.,.,.,.,
  NOP                       ; No operation.
  ;,,,,,,,,,,,,,,,,,,,,,,,,,,
  LDI r20, (0x64)           ; [Carregamos 100 no r20]
    MOV r21, r20            ; -> opicional.
    ;........................
    EOR r20, r20            ; -> opicional.
  outerloop:                ; # aux label
  ;+-+-+-+-+-+-+-+-+-+-+-+-+-
    LDI r30,lo8(delayValue) ; Parte baixa do Reg(Z) recebe 5000.
    LDI r31,hi8(delayValue) ; Parte alta do Reg(Z) recebe 5000.
  ;-+-+-+-+-+-+-+-+-+-+-+-+-+
  innerloop:                ; # aux label
  ;__________________________
    SBIW r30, (0x01)        ;  Subtração imediata de um registrador de dois bytes: Nota importante o uso de sbiw é exclusivo de dois bytes.
    NOP                     ; 1 ciclo sem operação.
  ;__________________________
  BRNE innerloop            ; Se valor for diferente de 0 chama a etiqueta interna.
    SUBI r21, (0x01)        ; Subtração imediata de um registrador de um byte.
    NOP                     ; No operation.
  ;==========================
  BRNE outerloop            ; Se valor for diferente de 0 chama a etiqueta externa.
;____________________________
;°º*°º*°º*°º*°º*°º*°º*°º*°º*°
