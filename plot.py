import matplotlib.pyplot as plt

x = [int(i) for i in range(1, 20)]


with open("cycle.txt") as fichier:
    y_str = fichier.read().split()

y = list(map(int, y_str))

plt.title('Nombre de cycles en fonction de la taille n de lechequier',color='b')
plt.xlabel('Taille n de lechequier',color='r')
plt.ylabel('Nombre de cycles',color='r')
plt.plot(x, y)
plt.show()
