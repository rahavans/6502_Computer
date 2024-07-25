ROM = bytearray([0xea] * 32768)

ROM[0] = 0xa9 # load into 'a' register opcode
ROM[1] = 0x42 # value to be loaded into 'a' register
ROM[2] = 0x8d # store in memory
ROM[3] = 0x00 # value to be stored in memory (low byte)
ROM[4] = 0x60 # value to be stored in memory (high byte)

ROM[0x7ffc] = 0x00
ROM[0x7ffd] = 0x80
with open("rom.bin", "wb") as file:
    file.write(ROM)