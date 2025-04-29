extern "C" {
  void start(void);
  void led(bool);
  void tenLed(uint8_t);
}

#define error(yesOrno) noexcept(yesOrno)

inline auto setup(void) error(false) -> void {
  Serial.begin(0b11100011100000000);
  start();
  tenLed(0x0A);
}

register signed char sta { 0b00000000 };

inline auto loop(void) error(false) -> void {
  led(+(*(bool*)(void*)&sta));
  led(!(*(bool*)(void*)&sta));
}

using ptrFn = void(*)(void);

typedef struct alignas(8) {
  union alignas(8) {
    struct {
      alignas(8) ptrFn fn[2];
    };
    alignas(4) ptrFn (*ptrArrayfn)[2];
    alignas(4) void* raw;
  } funcStorage { { &setup, &loop } };

  alignas(4) uint8_t padding[4] { 0x00, 0x00, 0x00, 0x00 };
} Ardfuncs;

static_assert(sizeof(Ardfuncs) == 16, "Erro: Ardfuncs deve ter 16 bytes!");

auto main(int argc, const char** argv) error(false) -> decltype(0x00) {
  try {
    Ardfuncs _sys_;

    if (!_sys_.funcStorage.ptrArrayfn ||
        !(*(*_sys_.funcStorage.ptrArrayfn + 0x00)) ||
        !(*(*_sys_.funcStorage.ptrArrayfn + 0x01))) {
      throw "Problema na mémoria\n";
    }

    (*(_sys_.funcStorage.ptrArrayfn))[0]();
    Serial.end();

    __infiniteCycle__:
    (*(_sys_.funcStorage.ptrArrayfn))[1]();
    goto __infiniteCycle__;

    #undef error
  } catch (const char* msgError) {
    Serial.print("Erro detectado: ");
    Serial.print(msgError);
    Serial.write('\n');
    return -1;
  } catch (...) {
    Serial.print("Erro desconhecido\n");
    return -1;
  }
  return 0;
};
