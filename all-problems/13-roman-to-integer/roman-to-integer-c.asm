roman_to_integer:
        movzx   r8d, BYTE PTR [rdi]
        test    r8b, r8b
        je      .L19
        lea     rcx, [rdi+1]
        xor     esi, esi
        xor     eax, eax
.L18:
        lea     edx, [r8-67]
        cmp     dl, 21
        ja      .L3
        movzx   edx, dl
        jmp     [QWORD PTR .L5[0+rdx*8]]
.L5:
        .quad   .L11
        .quad   .L10
        .quad   .L3
        .quad   .L3
        .quad   .L3
        .quad   .L3
        .quad   .L9
        .quad   .L3
        .quad   .L3
        .quad   .L8
        .quad   .L7
        .quad   .L3
        .quad   .L3
        .quad   .L3
        .quad   .L3
        .quad   .L3
        .quad   .L3
        .quad   .L3
        .quad   .L3
        .quad   .L6
        .quad   .L3
        .quad   .L4
.L7:
        lea     edx, [rax+1000]
        add     eax, 800
        cmp     sil, 67
        cmovne  eax, edx
.L3:
        movzx   edx, BYTE PTR [rcx]
        add     rcx, 1
        mov     esi, r8d
        test    dl, dl
        je      .L22
.L20:
        mov     r8d, edx
        jmp     .L18
.L4:
        lea     edx, [rax+10]
        add     eax, 8
        cmp     sil, 73
        mov     esi, r8d
        cmovne  eax, edx
        movzx   edx, BYTE PTR [rcx]
        add     rcx, 1
        test    dl, dl
        jne     .L20
.L22:
        ret
.L6:
        lea     edx, [rax+5]
        add     eax, 3
        cmp     sil, 73
        cmovne  eax, edx
        jmp     .L3
.L8:
        lea     edx, [rax+50]
        add     eax, 30
        cmp     sil, 88
        cmovne  eax, edx
        jmp     .L3
.L9:
        add     eax, 1
        jmp     .L3
.L10:
        lea     edx, [rax+500]
        add     eax, 300
        cmp     sil, 67
        cmovne  eax, edx
        jmp     .L3
.L11:
        lea     edx, [rax+100]
        add     eax, 80
        cmp     sil, 88
        cmovne  eax, edx
        jmp     .L3
.L19:
        xor     eax, eax
        ret