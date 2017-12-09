.extern puts
.global main

         .data
msg:     .ascii  "Hello, World\n"
handle:  .int    50
//written: .int    0

         .text
main:
        subq $0x28, %rsp
        //movabsq $50, handle
        movabsq $handle, %rcx
        call puts
        addq $0x28, %rsp
        ret


/*            .global go
            .data
handle:     .int 0
written:    .int 0
            .text
go:
            //Get handle
            push $-11
            call _GetStdHandle@4
            mov %eax, handle

            //Do work
            xor %rax, %rax
            movq $3, %rcx 
            Loop1: 
                addq %rcx,%rax 
                addq $3, %rcx 
                cmp  $1000, %rcx 
                jl   Loop1 
            movq $5, %rcx 
            Loop2: 
                addq %rcx,%rax 
                addq $5, %rcx 
                cmp $1000, %rcx 
                jl Loop2 
            xor %rbx, %rbx 
            xor %rcx, %rcx 
            Loop3: 
                addq %rcx, %rbx 
                addq $15, %rcx 
                cmp $1000, %rcx 
                jl Loop3 
            subq %rbx, %rax 
            #movq %rax, %r12d

            //Print work
            push $0
            push $written
            push $13
            push %rax
            push handle
            call _WriteConsoleA@20

            //Exit
            push $0
            call _ExitProcess@4
*/
