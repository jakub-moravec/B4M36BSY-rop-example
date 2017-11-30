import angr, angrop
p = angr.Project("/home/jakub/B4M36BSY-rop-example/cmake-build-debug/rop")
p = angr.Project("./rop")
p = angr.Project("/bin/ls")
rop = p.analyses.ROP()
rop.find_gadgets()
chain = rop.set_regs(rax=0x1337, rbx=0x56565656)
chain.payload_str()

#'\xb32@\x00\x00\x00\x00\x007\x13\x00\x00\x00\x00\x00\x00\xa1\x18@\x00\x00\x00\x00\x00VVVV\x00\x00\x00\x00'
#>>> chain.print_payload_code()
#chain = ""
#chain += p64(0x410b23)	# pop rax; ret
#chain += p64(0x1337)
#chain += p64(0x404dc0)	# pop rbx; ret
#chain += p64(0x56565656)