#pragma GCC optimize ("O1")
#define _y_ 0x02
#define _x_ 0x01
#define Brain main
extern "C" { [[gnu::used]] void start(void); [[gnu::used]] void led(bool); [[gnu::used]] void tenLed(uint8_t); } 
using ptrFn = void(*)(void); alignas(0x04) static signed char i{ 0x00 };

[[gnu::const]][[gnu::always_inline]] static inline auto setup(void) noexcept(false) -> void { start(); tenLed(0x0A); return; }
__attribute__((noreturn, hot))[[gnu::always_inline]] static inline auto loop(void) noexcept(false) -> void 
{ led(+(*(bool*)(void*) &i)); /*  */ led(!(*(bool*)(void*) &i)); }
#if defined(_y_) && defined(_x_)
  #if _y_ < 0x02 || _y_ > 0x02 && _x_ < 0x01 || _x_ > 0x01
    #error Erro indíce menor inferior ao valor mínimo...
  #elif _y_ == 0x02 && _x_ == 0x01
alignas(0x08) typedef struct __attribute__((optimize("O0"), (aligned(0x08))) { 
  unsigned long: 0b00000000;
  union alignas(0x08) __attribute__((aligned(0x08))) {
    alignas(sizeof(ptrFn)) ptrFn fn[_y_][_x_] 
    __attribute__((aligned(sizeof(ptrFn)))){ &setup, &loop }; 
  };
  union alignas(0x08) __attribute__((aligned(0x08))) {
      alignas(sizeof(ptrFn)) ptrFn (*ptrArrayfn)[sizeof(fn)/sizeof(ptrFn)][sizeof(fn)/sizeof(fn)] 
      __attribute__((aligned(sizeof(ptrFn)))){ reinterpret_cast<ptrFn(*)[_y_][_x_]>((void*)&fn) }; void* raw;
  };
} Ardfuncs;
  #else
    #warning Ocorreu um erro não identificado!!! Isso pode causar comportamento indefinido!!!
  #endif
static_assert(sizeof(Ardfuncs) <= 0x0C, "Erro: Ardfuncs deve ter menos de 16 bytes!");
#else
  #warning Ocorreu um erro não identificado!!! Isso pode causar comportamento indefinido!!!
#endif
#undef _y_
#undef _x_
#pragma GCC optimize ("Os")
#ifdef Brain
[[noreturn]] auto Brain(int argc, const char** argv) noexcept(false) -> decltype(0x00) {
  Ardfuncs _sys_;
  #ifndef INDEX
  #define INDEX 0x00
  if (!(volatile ptrFn(*)[][])_sys_.ptrArrayfn                                 ||
      !(volatile ptrFn)(*((&((*_sys_.ptrArrayfn)[INDEX][INDEX]) +0x00) +0x00)) ||
      !(volatile ptrFn)(*((&((*_sys_.ptrArrayfn)[INDEX][INDEX]) +0x01) +0x00))  ) 
  [unlikely]]                                                  { return -+0x01; }
  #endif
  #undef INDEX
    
  (*(_sys_.ptrArrayfn))[  0x00  ][  0x00  ](  );  Serial.end(  );
  while (true) { (*(_sys_.ptrArrayfn))[  0x01  ][  0x00  ](  ); } 
  
  return 0b00000000;
};
#ifndef Brain
  #warning Escopo principal não definido...
#else
 #error Erro desconhecido e não catalogado...
#endif
