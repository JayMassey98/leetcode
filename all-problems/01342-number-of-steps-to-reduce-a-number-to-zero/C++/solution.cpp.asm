number_of_steps(int):
        xor     eax, eax
        test    edi, edi
        je      .L6
.L5:
        mov     ecx, edi
        lea     edx, [rdi-1]
        sar     ecx
        and     edi, 1
        cmove   edx, ecx
        add     eax, 1
        mov     edi, edx
        test    edx, edx
        jne     .L5
        ret
.L6:
        ret