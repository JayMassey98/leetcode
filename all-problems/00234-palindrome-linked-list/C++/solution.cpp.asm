is_palindrome:
        test    rdi, rdi
        je      .L2
        mov     rax, rdi
        xor     ecx, ecx
        jmp     .L3
.L5:
        mov     rdi, QWORD PTR [rdx+8]
        mov     rdx, QWORD PTR [rax+8]
        mov     QWORD PTR [rax+8], rcx
        mov     rcx, rax
        test    rdi, rdi
        je      .L4
        mov     rax, rdx
.L3:
        mov     rdx, QWORD PTR [rdi+8]
        test    rdx, rdx
        jne     .L5
        mov     rdx, QWORD PTR [rax+8]
        mov     rax, rcx
.L4:
        test    rdx, rdx
        jne     .L8
        jmp     .L9
.L19:
        mov     rdx, QWORD PTR [rdx+8]
        mov     rax, QWORD PTR [rax+8]
        test    rdx, rdx
        je      .L9
.L8:
        mov     esi, DWORD PTR [rdx]
        cmp     DWORD PTR [rax], esi
        je      .L19
.L2:
        xor     eax, eax
        ret
.L9:
        mov     eax, 1
        ret