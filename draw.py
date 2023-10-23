import matplotlib.pyplot as plt

x = [128, 256, 512, 1024, 2048]
y_w = [
    [1, 2, 3, 4, 5],# noKVSep
    [44.2, 87.5, 139.5, 274.2 ,10], # kvSepBeforeMem
    [3, 6 ,9 ,12, 15] #kvSepBeforeSSD
]
y_r = [
    [1, 2, 3, 4, 5],# noKVSep
    [158.9, 154.9, 145.0, 160.9 ,10], # kvSepBeforeMem
    [3, 6 ,9 ,12, 15] #kvSepBeforeSSD
]
y_rsep = [
    [1, 2, 3, 4, 5],# noKVSep
    [355.2, 357.7, 339.8, 378.9 ,10], # kvSepBeforeMem
    [3, 6 ,9 ,12, 15] #kvSepBeforeSSD
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
plt.title("Read Performance(readsep)")
plt.xlabel("Value size(B)")
plt.ylabel("Throughout(MiB/s)")
l1 = plt.plot(x, y_rsep[0], "bo", linestyle = "dashed")
l1 = plt.plot(x, y_rsep[1], "g^", linestyle = "dashed")
l1 = plt.plot(x, y_rsep[2], "y+", linestyle = "dashed")
plt.legend(["noKVSep", "kvSepBeforeMem", "kvSepBeforeSSD"])
plt.show()