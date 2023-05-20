richest_customer_wealth:
        xor     r9d, r9d
        test    esi, esi
        je      .L21
        push    rbp
        mov     r10, rdi
        mov     r11, rdx
        xor     ecx, ecx
        push    rbx
        movsx   rbx, esi
.L2:
        movsx   rsi, DWORD PTR [r11+rcx*4]
        xor     eax, eax
        mov     r8, rsi
        test    esi, esi
        je      .L8
        lea     rax, [rsi-1]
        mov     rdi, QWORD PTR [r10+rcx*8]
        cmp     rax, 2
        jbe     .L10
        mov     rdx, rsi
        mov     rax, rdi
        pxor    xmm0, xmm0
        shr     rdx, 2
        sal     rdx, 4
        add     rdx, rdi
.L5:
        movdqu  xmm2, XMMWORD PTR [rax]
        add     rax, 16
        paddd   xmm0, xmm2
        cmp     rax, rdx
        jne     .L5
        movdqa  xmm1, xmm0
        and     r8d, 3
        psrldq  xmm1, 8
        paddd   xmm0, xmm1
        movdqa  xmm1, xmm0
        psrldq  xmm1, 4
        paddd   xmm0, xmm1
        movd    eax, xmm0
        je      .L8
        mov     rdx, rsi
        and     rdx, -4
.L4:
        lea     rbp, [rdx+1]
        lea     r8, [0+rdx*4]
        add     eax, DWORD PTR [rdi+rdx*4]
        cmp     rbp, rsi
        jnb     .L8
        add     rdx, 2
        add     eax, DWORD PTR [rdi+4+r8]
        cmp     rdx, rsi
        jnb     .L8
        add     eax, DWORD PTR [rdi+8+r8]
.L8:
        cmp     r9d, eax
        cmovl   r9d, eax
        add     rcx, 1
        cmp     rcx, rbx
        jne     .L2
        mov     eax, r9d
        pop     rbx
        pop     rbp
        ret
.L10:
        xor     edx, edx
        xor     eax, eax
        jmp     .L4
.L21:
        mov     eax, r9d
        ret