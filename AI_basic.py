# y = wx +b implementation
import tensorflow as tf

w = tf.Variable([0.77],tf.float32)
b = tf.Variable([0.28],tf.float32)

x = tf.placeholder(tf.float32)

y = tf.placeholder(tf.float32)

linear_model = w * x + b
square = tf.square(linear_model - y)
loss = tf.reduce_sum(square)

optimizer = tf.train.GradientDescentOptimizer(0.01)
train = optimizer.minimize(loss)

#init = tf.global_variables_initializer()
init = tf.initialize_all_variables()

sess = tf.Session()
sess.run(init)

for i in range(1000):
	sess.run(train,{x:[1,2,3,4],y:[0,-1,-2,-3]})
	
print(sess.run([w,b]))

print(sess.run(linear_model,{x:1}))


