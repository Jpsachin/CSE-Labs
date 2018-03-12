# OpenCV library
import cv2
# Numpy
import numpy as np
# Matplotlib
import matplotlib.pyplot as plt


class Image:

    # init with path of image
    def __init__(self, path):
        self.__path = path


    # get image from path
    def get_image(self):
        # read image
        self.__image = cv2.imread(self.__path)
        cv2.imshow("image", self.__image)
        cv2.waitKey(0)


    # convert image to gray scale
    def grayscale(self):
        # get dimension from image {row, col, depth}
        dimension = np.shape(self.__image)
        # initialize 2D matric to store greyscale of each pixel in the image
        self.__img_grayscale = np.zeros(dimension[0:2], np.uint8)

        # move through each pixel in original image
        # each pixel is an matrix element in image with RBG values are depth
        for i in range(dimension[0]):
            for j in range(dimension[1]):
                avg = 0
                # get avg of RBG values
                for k in range(3):
                    avg += self.__image[i][j][k];

                avg = avg / 3
                # store grayscale value in a 2D matrix
                self.__img_grayscale[i][j] = avg

        cv2.imshow("gray scale image", self.__img_grayscale)
        cv2.waitKey(0)


    # convert image to negative scale
    def negate(self):
        # get dimension from image {row, col, depth}
        dimension = np.shape(self.__image)

        # get highest pixel intensity in gray scale image
        max_intensity = np.max(self.__img_grayscale)

        self.__img_negative = np.zeros(dimension[0:2], np.uint8)

        # move through each pixel in gray scale image
        for i in range(dimension[0]):
            for j in range(dimension[1]):
                # reverse the pixel of gray scale by substracting from max_intensity
                self.__img_negative[i][j] = max_intensity - self.__img_grayscale[i][j]

        cv2.imshow("negative scale image", self.__img_negative)
        cv2.waitKey(0)


    def plot_histogram(self):
        # store unrolled matrix of image
        intensity = []

        # get dimension from image {row, col, depth}
        dimension = np.shape(self.__image)

        for i in range(dimension[0]):
            for j in range(dimension[1]):
                intensity.append(self.__img_grayscale[i][j])

        # plot histogram        
        plt.hist(intensity)
        plt.title("Pixel Intensity Histogram")
        plt.xlabel("Intensity Value of Pixels")
        plt.ylabel("Frequency of Pixels")
        plt.show()


img = Image('bird.jpg')

img.get_image()

img.grayscale()

img.negate()

img.plot_histogram()

cv2.destroyAllWindows()
