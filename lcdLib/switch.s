JT:
    .word default
    .word case1
    .word case1
    .global main

main2:
    MOV &correct,r12
    CMP #6,r12
    JGE default
    ADD r12,r12 
    MOV JT(r12),r0

case1:
    CALL #state1
    JMP esc

case2:
    CALL #state2
    JMP esc

default:
    JMP esc

esc:
    POP r0