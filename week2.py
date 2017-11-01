import numpy as np

f = open('decision_tree_data.txt','r')

x_train = []
y_train = []

for line in f:
	line = np.array(line.split(),dtype=np.float32)
	x_train.append(line[:-1])
	y_train.append(line[:-1])

x_train = np.asmatrix(x_train)
#print(x_train)
y_train = np.reshape(y_train,(len(y_train),1))
print(y_train)
