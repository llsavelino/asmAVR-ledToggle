#define                          __empty__ void
extern                                      "C"
{ 
  void      start                    (  void );            
  void      led                      (uint8_t); 
  void      tenLed                   (uint8_t);
  /*\       De assembly para C/C++          \*/
}                                             ;
/*\ ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨ \*/
#define                    error noexcept(0x00)
inline auto setup                 ( __empty__ ) 
error                                   -> void            
{ 
  start                                    ( );
  tenLed                              ( 0x0A );
  return                                      ;
}
register signed char  sta        { 0b00000000 };
inline auto loop                  ( __empty__ ) 
error                                   -> void     
{ 
  led        (  +(*(bool*)(void* const)& sta));   
  led        (  !(*(bool*)(void* const)& sta)); 
}
/*\ ><><><><><><><><><><>=<><><><><><><><>< \*/
auto main         (int argc, const char** argv) 
noexcept(0x00) ->                decltype(0x00)
{
  struct {
    using ptrFn =                void(*)(void);
    void(*ptrSp)  (void)            { &setup };
  	void(*ptrLp)  (void)            { &loop  };
    /*\ ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨ \*/
    ptrFn fn            [0x02]{ ptrSp, ptrLp };
    ptrFn                       ( *ptrArrayfn )
    [(uint8_t)(sizeof(fn) /     sizeof(ptrFn))]         
    {            (void* const)&fn            };
  }
  Ardfuncs                                    ;
  if ( !( *(Ardfuncs.fn +0x00))              ||
       !( *(Ardfuncs.fn +0x01))               )
  { 
    return                               +0x01;
  }
  if (   !(* (*Ardfuncs.ptrArrayfn +0x00))    )
  {
    return                               -0x01;
  }
  {
    (* (Ardfuncs.ptrArrayfn))     [ 0x00 ](  );
  }
  __infiniteCycle__:
  {
    (* (Ardfuncs.ptrArrayfn))     [ 0x01 ](  );
  } goto                     __infiniteCycle__;
  return                                  0x00;
};