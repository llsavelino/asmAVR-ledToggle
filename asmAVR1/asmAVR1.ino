extern "C" 
{
  void start(void); void led(bool); void tenLed(uint8_t);
}

static inline auto setup(void) noexcept(false) -> void 
{
  Serial.begin(0b11100011100000000);
  start(); tenLed(0x0A);
}

static signed char sta{ 0x00 };

static inline auto loop(void) noexcept(false) -> void 
{
  led(+(*(bool*)(void*)&sta)); /*  */ led(!(*(bool*)(void*)&sta));
}

using ptrFn = void(*)(void);
alignas(0x08) typedef struct __attribute__((aligned(0x08))) 
{
  unsigned long: 0x00; struct alignas(0x08) 
  { 
    ptrFn fn[0x02] __attribute__((aligned(sizeof(ptrFn)))){ &setup, &loop }; 
  };
  union alignas(0x08) __attribute__((aligned(0x08))) 
  {
      alignas(sizeof(ptrFn)) ptrFn (*ptrArrayfn)[0x02]{ &fn }; alignas(sizeof(void*)) void* raw;
  };
} Ardfuncs;

static_assert(sizeof(Ardfuncs) == 16, "Erro: Ardfuncs deve ter 16 bytes!");

auto main(int argc, const char** argv) noexcept(false) -> decltype(0x00) {
  try {
    Ardfuncs _sys_;

    if (!(volatile ptrFn(*)[0x02])_sys_.ptrArrayfn     ||
        !(volatile void*)(*(*_sys_.ptrArrayfn + 0x00)) ||
        !(volatile void*)(*(*_sys_.ptrArrayfn + 0x01))  ) 
    {
      throw "Problema na mémoria\n";
    }

    (*(_sys_.ptrArrayfn))[0x00](); Serial.end();

    __infiniteCycle__: (*(_sys_.ptrArrayfn))[0x01](); goto __infiniteCycle__;
  } 
  catch (const char* msgError) {
    Serial.print("Erro detectado: "); Serial.print(msgError); return -+0x01;
  } 
  catch (...) { Serial.print("Erro desconhecido\n"); return -+0x01; }
  return 0b00000000;
};
