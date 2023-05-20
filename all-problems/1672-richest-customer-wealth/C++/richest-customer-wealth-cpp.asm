richest_customer_wealth(std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >&):
        push    rbp
        push    rbx
        mov     rbx, rdi
        sub     rsp, 40
        mov     DWORD PTR [rsp+8], 0
        call    std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >::begin()
        mov     rdi, rbx
        mov     QWORD PTR [rsp+16], rax
        call    std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >::end()
        mov     QWORD PTR [rsp+24], rax
        jmp     .L2
.L3:
        lea     rdi, [rsp+16]
        call    __gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >::operator*() const
        mov     rbx, rax
        mov     rdi, rax
        call    std::vector<int, std::allocator<int> >::end() const
        mov     rdi, rbx
        mov     rbp, rax
        call    std::vector<int, std::allocator<int> >::begin() const
        xor     edx, edx
        mov     rsi, rbp
        mov     rdi, rax
        call    int std::accumulate<__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >, int>(__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >, __gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >, int)
        lea     rdi, [rsp+8]
        lea     rsi, [rsp+12]
        mov     DWORD PTR [rsp+12], eax
        call    int const& std::max<int>(int const&, int const&)
        lea     rdi, [rsp+16]
        mov     eax, DWORD PTR [rax]
        mov     DWORD PTR [rsp+8], eax
        call    __gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >::operator++()
.L2:
        lea     rsi, [rsp+24]
        lea     rdi, [rsp+16]
        call    bool __gnu_cxx::operator!=<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >(__gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > > const&, __gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > > const&)
        test    al, al
        jne     .L3
        mov     eax, DWORD PTR [rsp+8]
        add     rsp, 40
        pop     rbx
        pop     rbp
        ret