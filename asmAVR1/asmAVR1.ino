#define                          __empty__ void
extern                                      "C"
{ 
  void      start                    (  void );            
  void      led                      (  bool ); 
  void      tenLed                   (uint8_t);
  /*\       De assembly para C/C++          \*/
}                                             ;
/*\ ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨ \*/
#define                    error noexcept(0x00)
inline auto setup                 ( __empty__ ) 
error                                   -> void            
{ 
  Serial.               begin( 1001011000000 );
  start                                    ( );
  tenLed                              ( 0x0A );
  return                                      ;
}
signed char                  sta{ 0b00000000 };
#define value(_o_) (*(bool*)(void* const)& _o_) 
inline auto loop                  ( __empty__ ) 
error                                   -> void     
{ 
  led        (  +(value                (sta)));   
  led        (  !(value                (sta))); 
}
/*\ ><><><><><><><><><><>=<><><><><><><><>< \*/
auto main         (int argc, const char** argv) 
noexcept(0x00) ->                decltype(0x00)
{
  try
  {
    typedef                              struct 
    {
      using ptrFn =              void(*)(void);
      void(*ptrSp)  (void)          { &setup };
  	  void(*ptrLp)  (void)          { &loop  };
      /*\ ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨ \*/
      ptrFn fn          [0x02]{ ptrSp, ptrLp };
      ptrFn                     ( *ptrArrayfn )
      [(uint8_t)(sizeof(fn) /   sizeof(ptrFn))]         
      {               (void*)&fn             };
    }                                 Ardfuncs;
    Ardfuncs                             _sys_;
  
   if (  !(_sys_.ptrArrayfn             )    ||   
         !(* (*(_sys_.ptrArrayfn +0x00)))    ||   
         !(* (*(_sys_.ptrArrayfn +0x01)))     )
    {
      throw            "Problema na mémoria\n";
    }
    /*\ -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \*/
    {
      (* (_sys_.ptrArrayfn))      [ 0x00 ](  );
    }
    __infiniteCycle__:
    {
      (* (_sys_.ptrArrayfn))      [ 0x01 ](  );
    } goto                   __infiniteCycle__;
  } 
  catch                  (const char* msgError) 
  {
    Serial.          print("Erro detectado: ");
    Serial.                    print(msgError);
    Serial.                        write('\n');
    return                              -+0x01;
  } 
  catch                                   (...) 
  {
    Serial.       print("Erro desconhecido\n");
    return                              +-0x01;
  }
  return                                  0x00;
};
