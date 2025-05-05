#pragma GCC optimize ("O1")
#define _y_ 0x02
extern "C" { [[ gnu::used ]] void start(void); [[ gnu::used ]] void led(bool); [[ gnu::used ]] void tenLed(uint8_t); } 
using ptrFn = void(*)(void); alignas(0x04) static signed char i{ 0x00 };

[ [ gnu::const ] ][  [gnu::always_inline]  ] static inline auto setup(void) noexcept(false) -> void 
{ Serial.begin(0x2580); start(); tenLed(0x0A); return; }

__attribute__((noreturn)) [  [gnu::always_inline]  ] static inline auto loop(void) noexcept(false) -> void 
{ led(+(*(bool*)(void*) &i)); /*  */ led(!(*(bool*)(void*) &i)); }

alignas(0x08) typedef struct __attribute__((optimize("O0"), (aligned(0x08))) { unsigned long: 0b00000000; 
  union alignas(0x08) __attribute__((aligned(0x08))) {
    alignas(sizeof(ptrFn)) ptrFn fn[_y_] __attribute__((aligned(sizeof(ptrFn)))){ &setup, &loop }; 
  };
  union alignas(0x08) __attribute__((aligned(0x08))) {
      alignas(sizeof(ptrFn)) ptrFn (*ptrArrayfn)[sizeof(fn)/sizeof(ptrFn)] __attribute__((aligned(sizeof(ptrFn))))
      { reinterpret_cast<ptrFn(*)[_y_]>(&fn) }; void* raw;
  };
} Ardfuncs;
static_assert(sizeof(Ardfuncs) <= 0x0C, "Erro: Ardfuncs deve ter menos de 16 bytes!");

#pragma GCC optimize ("Os")
[[  noreturn  ]] auto main(int argc, const char** argv) noexcept(false) -> decltype(0x00) {
  try {                                   Ardfuncs _sys_;
    if (!(volatile ptrFn(*)[])_sys_.ptrArrayfn        ||
        !(volatile ptrFn)(*(*_sys_.ptrArrayfn +0x00)) ||
        !(volatile ptrFn)(*(*_sys_.ptrArrayfn +0x01))  ) 
    [[likely]] { throw "Erro detectado: Problema na mémoria\n"; }

    (*(_sys_.ptrArrayfn))[  0x00  ](  ); Serial.end(  );

    __infiniteCycle__: (*(_sys_.ptrArrayfn))[  0x01  ](  ); goto __infiniteCycle__; asm volatile ("jmp 0");
  } 
  catch (const char* msgError) { Serial.print(msgError); return -+0x01; } 
  catch (...) { Serial.print("Erro desconhecido\n");     return -+0x01; }
  return                                                    0b00000000;
};
