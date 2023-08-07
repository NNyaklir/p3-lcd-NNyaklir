    .text
    .global main2

    .sect ".data"
JT:
    .word default
    .word case1
    .word case2

    .sect ".text"
main2:
    MOV &correct, r12
    CMP #6, r12
    JGE default
    ADD r12, r12
    MOV &JT, r13
    ADD r13, r12
    MOV r12, r15         ; Store the calculated index in r15
    MOV JT(r15), r0      ; Access the value from JT using indexed addressing
    JMP @r0

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

    .end
