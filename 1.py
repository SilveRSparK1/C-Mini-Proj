data = input("Enter the data (0 & 1 s only): ")

stuffed_data = data.replace("011111","0111110")
print("stuffed data: ",stuffed_data)

unstuffed_data = stuffed_data.replace("0111110","011111")
print("unstuffed data: ",unstuffed_data)