def compute_crc(data):
    crc = 0
    data +="0"*16
    
    for bit in data:
        crc<<=1
        crc|=int(bit)
        if crc & (1<<16):
            crc^=0x11021
        crc &= (1<<16)-1
        
    return crc

print("Sender part")
data = input("Enter the data (only 0 & 1): ")
crc_value = compute_crc(data)
print("data with crc: ",data + bin(crc_value)[2:].zfill(16))

print("reciver part: ")
recieved_data = input("Enter the received data: ")
recieved_crc = compute_crc(recieved_data)

if recieved_crc==0:
    print("data received correctly")
else:
    print("There is error in received data ")