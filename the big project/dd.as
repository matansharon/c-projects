add r7, *r6
clr K
sub L3, L3
.entry MAIN
jmp LOOP
END: stop
.entry STR
STR: .string “abcd”
LIST: .data 6, -9
.data -100
K: .data 31
.extern L3
