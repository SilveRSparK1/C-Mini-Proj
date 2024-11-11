from random import shuffle

PACKET_SIZE = 3

data = input("Enter the data: ")

packets = [(i//PACKET_SIZE,data[i:i+PACKET_SIZE]) for i in range(0,len(data),PACKET_SIZE)]

print("Packets: ",packets)

shuffle(packets)

print("shuffled packets: ",packets)

packets.sort(key = lambda x: x[0])

print("sorted packets: ",packets)

print("received data: ","".join(map(lambda x:x[1],packets)))