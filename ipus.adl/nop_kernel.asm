.org    0x0

// ******************************************
// 6 cycles loop  
start_test6:
  mov loopcnt,6      // comment if no ititial delay shall be emulated
delay6:              // until
  loop delay6        // here
  done d61,i
d61:
  done d62,i
d62:
  done d63,i
d63:
  mov confsat,1

loop6:               // pixel cycle with 6 instructions
  mov out0,ina4      // copy input to output
  mov out1,0
  mov out2,0xffff
  nop
  done loop6,ixo
end_test6:

// ******************************************
// 5 cycles loop  
start_test5:
  mov loopcnt,6      // comment if no ititial delay shall be emulated
delay5:              // until
  loop delay5        // here
  done d51,i
d51:
  done d52,i
d52:
  done d53,i
d53:
  mov confsat,1

loop5:               // pixel cycle with 6 instructions
  mov out0,ina4      // copy input to output
  mov out1,0
  mov out2,0xffff
  done loop5,ixo
end_test5:

// ******************************************
// 7 cycles loop  
start_test7:
  mov loopcnt,6      // comment if no ititial delay shall be emulated
delay7:              // until
  loop delay7        // here
  done d71,i
d71:
  done d72,i
d72:
  done d73,i
d73:
  mov confsat,1

loop7:               // pixel cycle with 6 instructions
  mov out0,ina4      // copy input to output
  mov out1,0
  mov out2,0xffff
  nop
  nop
  done loop7,ixo
end_test7:

  
// ******************************************
// 3 cycles loop  
start_test3:
  mov loopcnt,6      // comment if no ititial delay shall be emulated
delay3:              // until
  loop delay3        // here
  done d31,i
d31:
  done d32,i
d32:
  done d33,i
d33:
  mov confsat,1

loop3:               // pixel cycle with 6 instructions
  mov out0,ina4      // copy input to output
  done loop3,ixo
end_test3:
