get_symbol_value(char):
        sub     edi, 67
        xor     eax, eax
        cmp     dil, 21
        ja      .L1
        movzx   edi, dil
        mov     eax, DWORD PTR CSWTCH.1[0+rdi*4]
.L1:
        ret
check_order_reduction(char, char):
        cmp     dil, 73
        je      .L6
        cmp     dil, 88
        je      .L7
        cmp     dil, 67
        jne     .L14
.L8:
        cmp     sil, 68
        je      .L12
        cmp     sil, 77
        je      .L12
.L14:
        xor     eax, eax
        ret
.L6:
        lea     edx, [rsi-86]
        mov     eax, 2
        and     edx, 253
        je      .L5
.L7:
        cmp     sil, 76
        je      .L11
        cmp     sil, 67
        jne     .L8
.L11:
        mov     eax, 20
        ret
.L12:
        mov     eax, 200
.L5:
        ret
roman_to_integer(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >):
        push    r14
        push    r13
        mov     r13, rdi
        push    r12
        push    rbp
        push    rbx
        call    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::length() const
        test    rax, rax
        je      .L18
        mov     r12, rax
        xor     ebx, ebx
        xor     ebp, ebp
        xor     r14d, r14d
.L17:
        mov     rsi, rbx
        mov     rdi, r13
        add     rbx, 1
        call    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::operator[](unsigned long) const
        mov     edx, ebp
        movsx   esi, BYTE PTR [rax]
        mov     edi, esi
        mov     ebp, esi
        call    get_symbol_value(char)
        movsx   edi, dl
        add     r14d, eax
        call    check_order_reduction(char, char)
        sub     r14d, eax
        cmp     r12, rbx
        jne     .L17
        pop     rbx
        mov     eax, r14d
        pop     rbp
        pop     r12
        pop     r13
        pop     r14
        ret
.L18:
        xor     r14d, r14d
        pop     rbx
        pop     rbp
        mov     eax, r14d
        pop     r12
        pop     r13
        pop     r14
        ret
CSWTCH.1:
        .long   100
        .long   500
        .long   0
        .long   0
        .long   0
        .long   0
        .long   1
        .long   0
        .long   0
        .long   50
        .long   1000
        .long   0
        .long   0
        .long   0
        .long   0
        .long   0
        .long   0
        .long   0
        .long   0
        .long   5
        .long   0
        .long   10