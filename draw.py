import matplotlib.pyplot as plt

x = [128, 256, 512, 1024, 2048]
y_w = [
    [1, 2, 3, 4, 5],
    [2, 4, 6, 8 ,10],
    [3, 6 ,9 ,12, 15]
]
y_r = [
    [1, 2, 3, 4, 5],
    [2, 4, 6, 8 ,10],
    [3, 6 ,9 ,12, 15]
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
plt.title("Read Performance(readrandom)")
plt.xlabel("Value size(B)")
plt.ylabel("Throughout(MiB/s)")
l1 = plt.plot(x, y_r[0], "bo", linestyle = "dashed")
l1 = plt.plot(x, y_r[1], "g^", linestyle = "dashed")
l1 = plt.plot(x, y_r[2], "y+", linestyle = "dashed")
plt.legend(["noKVSep", "kvSepBeforeMem", "kvSepBeforeSSD"])
plt.show()