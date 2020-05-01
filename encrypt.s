section .text

global encrypt

encrypt:
    push rbp     ;
    mov rbp, rsp

keyXORvect:
;rdi - key  rsi - vect rdx - text

    mov r8, rdi ; copy key pointer
    mov r9, rsi ; copy vector pointer
    xor r10, r10 ; set counter r10 to 0

keyXORvect_loop:
    mov al, [r8] ; load key byte
    mov cl, [r9] ; load vector byte

    xor cl, al

    mov [r9], cl ;save xored byte in vector
    ;increment pointers
    inc r8
    inc r9
    inc r10

    cmp r10, 4
    jl keyXORvect_loop

vectXORplainText:
    mov r8, rsi ;copy vector pointer
    ;mov r9, rdx ;copy plain text pointer
    xor r10,r10 ;counter set to 0
vectXORplainText_loop:
    mov al, [r8] ; load vector byte
    mov cl, [rdx] ; load plain text byte

    cmp cl, 0 ;plaintext ended finish program
    jz end

    xor cl, al ;xor plaintext with vector

    mov[rdx], cl
    mov[r8], cl

    inc r8
    inc rdx
    inc r10

    cmp r10, 4
    jl vectXORplainText_loop
    je keyXORvect



end:
    mov rsp, rbp
    pop rbp
    ret

