JT:
    .word default
    .word case1
    .word case1
    .global main

main2:
    mov &correct,r12
    cmp #6,r12
    jge default
    add r12,r12 
    mov JT(r12),r0

case1:
    call #state1
    jmp esc

case2:
    call #state2
    jmp esc

default:
    jmp esc

esc:
    pop r0