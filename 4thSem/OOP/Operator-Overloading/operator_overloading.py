import math


# Complex Number class
class Complex_Number:
    
    def __init__(self, real,  imaginary):
        
        self.__real = real
        self.__imaginary = imaginary
        
    def get_complex_number(self):
        
        return self.__real, self.__imaginary         
    
    # add operator overloaded    
    def __add__(self, complex_number):
             
        #return self.__real + complex_number.__real, self.__imaginary + complex_number.__imaginary
        return Complex_Number(self.__real - complex_number.__real, self.__imaginary - complex_number.__imaginary)
    
    # sub operator overloaded    
    def __sub__(self, complex_number):
        
        #return self.__real - complex_number.__real, self.__imaginary - complex_number.__imaginary
        return Complex_Number(self.__real - complex_number.__real, self.__imaginary - complex_number.__imaginary)
        
        
# Take inputs        
a, b = raw_input("Enter real and imaginary part: ").split()
a, b = [int(a), int(b)]

no1 = Complex_Number(a, b)

a, b = raw_input("Enter real and imaginary part: ").split()
a, b = [int(a), int(b)]
no2 = Complex_Number(a, b)

a, b = raw_input("Enter real and imaginary part: ").split()
a, b = [int(a), int(b)]
no3 = Complex_Number(a, b)


# Sum of 3 complex numbers
result = no1 + no2 + no3
sum_real, sum_imaginary = result.get_complex_number()

print 'no1 + no2 + no3:  ' + str(sum_real) + ' + ' + str(sum_imaginary) + 'i'


# check values of no1, no2, no3
sum_real, sum_imaginary = no1.get_complex_number()

print 'no1:  ' + str(sum_real) + ' + ' + str(sum_imaginary) + 'i'
sum_real, sum_imaginary = no2.get_complex_number()

print 'no2:  ' + str(sum_real) + ' + ' + str(sum_imaginary) + 'i'
sum_real, sum_imaginary = no3.get_complex_number()

print 'no3:  ' + str(sum_real) + ' + ' + str(sum_imaginary) + 'i' 



# Sum and difference of 3 complex numbers
result = no1 - no2 + no3
sum_real, sum_imaginary = result.get_complex_number()

print 'no1 - no2 + no3:  ' + str(sum_real) + ' + ' + str(sum_imaginary) + 'i' 

       
