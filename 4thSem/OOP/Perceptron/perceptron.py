import numpy as np


# Percepton
class Perceptron:
    # learning rate
    learning_rate = 0.01
    # inputs to the perceptron
    no_of_inputs = 2
    # weight corresponding to each input
    weigths = []
    # weighted sum
    Sum = 0
    # threshold for the perceptron
    threshold = 0

    # initialize the perceptron
    def __init__(self, n, learning_rate, threshold):

        self.n = n
        self.weights = np.random.rand(self.n)
        self.learning_rate = learning_rate
        self.threshold = threshold

    # calculate the weighted sum
    def accumulate(self, I):

        for i in range(self.n):
            self.Sum += self.weights[i] * I[i]

    # generate output signal of the perceptron as per the weighted sum and the threshold
    def activation(self):

        if self.Sum < self.threshold:
            return 0

        if self.Sum >= self.threshold:
            return 1

    # perceptron learns
    def learn(self, I, Y, N):

        # counter for input data set
        i = 0

        # iterate through the data set for learning
        for k in range(N):

            # set weighted sum to 0
            self.Sum = 0

            # get theb weighted sum for a input combination from the data set
            self.accumulate(I[i % len(I)])

            # find the output for the weighted sum calculated earlier from the activation function
            y = self.activation()

            # calculate error from the expected output for the input combination and output from the activation function
            error = Y[i % len(Y)] - y

            # update the weights
            for j in range(self.n):
                # calculate weight update margin
                '''
                if error is negative implies that the weighted sum is large so to bring it down we have to reduce the
                sum hence the weight, so higher I[i % len(I)][j] the weight corresponding to it will be reduced more
                Move the weights for that value very far in the opposite direction 
                else error is positive similar to above case higher I[i % len(I)][j] the weight corresponding to it 
                will be increased more so that weighted sum value increases as it was small 

                Use of learning rate is avoid increase in changes by a large margin
                '''
                dw = self.learning_rate * error * I[i % len(I)][j]
                # update weights
                self.weights[j] = self.weights[j] + dw

            # update threshold
            self.threshold = -(-self.threshold + self.learning_rate * error)

            # increment data set counter
            i += 1

        # print learned weights
        print(self.weights)

        # print learned threshold value
        print(self.threshold)

    # test the perceptron
    def test(self, I):

        self.Sum = 0
        self.accumulate(I)
        y = self.activation()

        print(y)


# input combinations for the OR data set
I = [(0, 0), (0, 1), (1, 0), (1, 1)]
# output for the corresponding input combination for the OR data set
Y = [0, 1, 1, 1]

# Make a new Perceptron
Or = Perceptron(2, 0.01, 0)

# feed daat set for the Perceptron to learn
Or.learn(I, Y, 10000)

# test the perceptron for various input combinations
Or.test((0, 0))
Or.test((0, 1))
Or.test((1, 0))
Or.test((1, 1))

# input combinations for the AND data set
I = [(0, 0), (0, 1), (1, 0), (1, 1)]
# output for the corresponding input combination for the AND data set
Y = [0, 0, 0, 1]

# Make a new Perceptron
And = Perceptron(2, 0.01, 0)

# feed daat set for the Perceptron to learn
And.learn(I, Y, 10000)

# test the perceptron for various input combinations
And.test((0, 0))
And.test((0, 1))
And.test((1, 0))
And.test((1, 1))








