import matplotlib.pyplot as plt

x = [128, 256, 512, 1024, 2048]
y_w = [
    [52.8, 67.0, 60.8, 52.3, 42.2, 30.2],# noKVSep
    [44.2, 87.5, 139.5, 274.2 ,426.3], # kvSepBeforeMem
    [59.9, 102.4 ,147.9 ,173.5, 184.2] #kvSepBeforeSSD
]
y_r = [
    [731.9, 1127.4, 1515.2, 3274.7, 4261.9],# noKVSep
    [158.9, 154.9, 145.0, 160.9 ,147.3], # kvSepBeforeMem
    [171.1, 136.0 ,179.8 ,169.8, 159.9] #kvSepBeforeSSD
]   
y_random = [
    [2.363, 2.698, 3.972, 3.735, 7.428],# noKVSep
    [2.957, 2.953, 3.417, 3.363 ,3.954], # kvSepBeforeMem
    [2.927, 2.739 ,2.947, 3.604, 3.530] #kvSepBeforeSSD
]

plt.figure(num = 1)
plt.title("Write Performance(fillrandom)")
plt.xlabel("Value size(B)")
plt.ylabel("Throughout(MiB/s)")
l1 = plt.plot(x, y_w[0], "bo", linestyle = "dashed")
l1 = plt.plot(x, y_w[1], "g^", linestyle = "dashed")
l1 = plt.plot(x, y_w[2], "y+", linestyle = "dashed")
plt.legend(["noKVSep", "kvSepBeforeMem", "kvSepBeforeSSD"])
plt.show()
plt.figure(num = 1)
plt.title("Read Performance(readreverse)")
plt.xlabel("Value size(B)")
plt.ylabel("Throughout(MiB/s)")
l1 = plt.plot(x, y_r[0], "bo", linestyle = "dashed")
l1 = plt.plot(x, y_r[1], "g^", linestyle = "dashed")
l1 = plt.plot(x, y_r[2], "y+", linestyle = "dashed")
plt.legend(["noKVSep", "kvSepBeforeMem", "kvSepBeforeSSD"])
plt.show()
plt.title("Read Performance(readrandom)")
plt.xlabel("Value size(B)")
plt.ylabel("Micros/op")
l1 = plt.plot(x, y_random[0], "bo", linestyle = "dashed")
l1 = plt.plot(x, y_random[1], "g^", linestyle = "dashed")
l1 = plt.plot(x, y_random[2], "y+", linestyle = "dashed")
plt.legend(["noKVSep", "kvSepBeforeMem", "kvSepBeforeSSD"])
plt.show()