import tensorflow as tf
import pandas as pd

#14 lines
data = pd.read_csv('./data/Data_for_UCI_named.csv')
print(data.loc[1])

data_one_hot_encoded = pd.get_dummies(data)
print(data_one_hot_encoded.loc[1])

train_data = data_one_hot_encoded.sample(frac=1.0,random_state=200)
train_input_data = train_data.filter(
    ['stabf'])
train_label_data = train_data.filter(
    ['unstable','stable'])

X = tf.placeholder(tf.float32,[None,14])
Y = tf.placeholder(tf.float32,[None,1])

learning_rate = 0.001

keep_prob = tf.placeholder(tf.float32)

W1 = tf.get_variable('W1',shape=[14,14],initializer=tf.contrib.layers.xavier_initializer())
b1 = tf.Variable(tf.random_normal([14]))
L1 = tf.nn.relu(tf.matmul(X,W1)) + b1
L1 = tf.nn.dropout(L1,keep_prob=keep_prob)

W2 = tf.get_variable('W2',shape=[14,14],initializer=tf.contrib.layers.xavier_initializer())
b2 = tf.Variable(tf.random_normal([14]))
L2 = tf.nn.relu(tf.matmul(L1,W2)) + b2
L2 = tf.nn.dropout(L2,keep_prob=keep_prob)

W3 = tf.get_variable('W3',shape=[14,1],initializer=tf.contrib.layers.xavier_initializer())
b3 = tf.Variable(tf.random_normal([1]))
L3 = tf.nn.relu(tf.matmul(L2,W3)) + b3
L3 = tf.nn.dropout(L3,keep_prob=keep_prob)

cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits_v2(logits=L3,labels=Y))
optimizer = tf.train.AdamOptimizer(learning_rate=learning_rate).minimize(cost)

sess = tf.InteractiveSession()
tf.global_variables_initializer().run()

for _ in range(200):
    print('Optimizer : ', sess.run(optimizer, feed_dict={X:train_input_data,Y:train_label_data}))





