#pragma GCC                                              optimize("O0")
#define _y_ 0x02
#define _x_ 0x01
#define SYSTEM_AVR
extern  "C" { void start(void); void led(bool); void tenLed(uint8_t); };
using ptrFn = void(*)(void); alignas(0x04) static signed char i{ 0x00 };

static inline auto setup(void) noexcept(false) -> void 
{ start(  ); tenLed(0x0A);                  return; };
static inline auto loop(void) noexcept(false) ->  void 
{ 
  led                         (+(*(bool*)(void*) &i)); 
  led                         (!(*(bool*)(void*) &i)); 
};

#if defined(_y_) && defined(_x_)
  #if _y_ < 0x02 || _y_ > 0x02 && _x_ < 0x01 || _x_ > 0x01
    #error Erro indíce menor inferior ao valor mínimo...
  #elif _y_ == 0x02 && _x_ == 0x01
alignas(0x08) typedef struct alignas(0x08) { 

  unsigned long: 0b00000000;
  union alignas(0x08) {
    ptrFn fn[_y_][_x_]{ &setup, &loop };
    uint8_t memorycache[sizeof(fn)]; void* raw;
  } Box;
  
  ptrFn(*ptrArrayfn)[_y_][_x_]{ reinterpret_cast<ptrFn(*)[_y_][_x_]>(&Box.fn) };

} Ardfuncs;
  #else
    #warning Ocorreu um erro não identificado!!! Isso pode causar comportamento indefinido!!!
  #endif
#else
  #warning Ocorreu um erro não identificado!!! Isso pode causar comportamento indefinido!!!
#                                                                                     endif
#pragma GCC                                               optimize("Os")
auto main(int argc, const char** argv) noexcept(false) -> decltype(0x00) {
  Ardfuncs _sys_;
  #ifndef                                                                   INDEX
  #define INDEX 0x00
  if (!(volatile ptrFn(*)[_y_][_x_])_sys_.ptrArrayfn                           ||
      !(volatile ptrFn)(*((&((*_sys_.ptrArrayfn)[INDEX][INDEX]) +0x00) +0x00)) ||
      !(volatile ptrFn)(*((&((*_sys_.ptrArrayfn)[INDEX][INDEX]) +0x01) +0x00))  ) 
  [[unlikely]]                                                 { return -+0x01; }
  #undef                                                                    INDEX
  #undef                                                                      _y_
  #undef                                                                      _x_
  #                                                                         endif
  #ifdef SYSTEM_AVR
  (*(_sys_.ptrArrayfn))[0x00][0x00](  ); while (true) { (*(_sys_.ptrArrayfn))[0x01][0x00](  ); } 
  #else
    #error Erro sistema de controle não definido!!!
  #                                           endif
  return (0x01) ? -+0x00: -+0x01;
};
