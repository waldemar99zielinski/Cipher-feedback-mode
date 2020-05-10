section .text

global encryptv2

encryptv2:
    push rbp     ;
    mov rbp, rsp
    mov r8, rdx
    xor rax,rax ;counter set to 0
keyXORvect:
;rdi - key  rsi - vect rdx - text rcx - text lenght

    mov r10d, [rdi] ; load key
    mov r9d, [rsi] ; load vector

    xor r9d, r10d ; xor key vect

    mov [rsi], r9d ; save vector
   

vectXORplainText:
    mov r9d, [rsi] ;load vector
    mov r10d, [rdx]; load text

    xor r9d, r10d ;xor text vector

    mov [rsi], r9d ;save xored value to vector
    mov [rdx], r9d;

    add rax, 4
    add rdx, 4

    cmp rax, rcx
    jl keyXORvect
    

end:
    add r8, rcx
    xor cl, cl ; zero 
    mov [r8], cl

    mov rsp, rbp
    pop rbp
    ret

