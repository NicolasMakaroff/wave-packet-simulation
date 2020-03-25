import numpy as np
from matplotlib.image import imread

###########
# Try PyTruth
###########

class Field:
        """
        Define a class for a field generator.
        Generate the initial wave function and the potential field from an image file, a formula...

        Args:
                _start_x_:
                _start_y_:
                _size_:
                _spatial_step_:
                _time_step_:
                _potential_:
                _initial_state_:
        """
        def __init__(self, _start_x_, _start_y_, _size_, _spatial_step_, _time_step_):
                self._start_x_ = _start_x_
                self._start_y_ = _start_y_
                self._size_ = _size_
                self._spatial_step_ = _spatial_step_
                self._time_step_ = _time_step_
                self._potential_ = np.ascontiguousarray(np.zeros([self._size_,self._size_]),dtype=np.complex) # C matrix like 
                self._initial_state_ = np.ascontiguousarray(np.zeros([self._size_,self._size_]),dtype=np.complex) 

        def _setPotential_(self,_potential_array):
                if _potential_array.shape == (self._size_,self._size_):
                        self._potential_ = _potential_array
                        return True
                else:
                        raise ValueError(
                '{} array object must be 2D array of the size _size_. Given size: {} '.format(self.__class__.__name__,_potential_array.shape))
        
        def _setInitialState_(self,_initial_state_array):
                if _initial_state_array.shape == (self._size_,self._size_):
                        self._potential_ = _initial_state_array
                        return True
                else:
                        raise ValueError(
                '{} array object must be 2D array of the size _size_. Given size: {} '.format(self.__class__.__name__,_initial_state_array.shape))

        def _calc_initial_state(self,func):
                """
                Apply the function `func` to compute the initial state. 
                Could be improved if `func`is a numpy function or act as a numpy function. 

                Args: 
                 func: A function with two args. 
                """
                for i in range(self._size_):
                        new_i_ = self._start_x_ + self._spatial_step_ * i
                        for j in range(self._size_):
                                new_j_ = self._start_y_ + self._spatial_step_ * j 
                                self._initial_state_[i][j] = func(new_i_, new_j_)
        
        def _calc_initial_gaussian_state_(self,mean_x_, mean_y_, sd_): 
                """
                Vectorized function.
                _size_ = 10000
                Without loops => 12.81 s
                with loops => 223.5 s
                """    
                discret_step_ = np.linspace(start = 0,stop = self._size_,num=(self._size_))
                new_i_ = self._start_x_ + self._spatial_step_ * discret_step_
                new_j_ = self._start_y_ + self._spatial_step_ * discret_step_
                xx, yy = np.meshgrid(new_i_,new_j_)
                X = (xx - mean_x_)
                Y = (yy - mean_y_)
                self._initial_state_ = np.exp(-1 * (np.square(X) + np.square(Y)) / sd_**2 ) 

        def _from_image_(self,image):
                img = imread(image)
                if img.shape == (self._size_,self._size_,3):
                        img = np.ascontiguousarray(img,dtype=np.complex32)
                        self._setPotential_(img)
                else:
                        raise ValueError(
                '{} array object must be 2D array of the size _size_. Given size: {} '.format(self.__class__.__name__,img.shape))
        

        

        


