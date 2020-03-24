import numpy as np

start_x_, double start_y_, int size_, int spatial_step_, int time_step_, arma::cx_mat potential_, arma::cx_mat initial_state_
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
                self._start_Y_ = _start_y_
                self._size_ = _size_
                self._spatial_step_ = _spatial_step_
                self._time_step_ = _time_step_
                self._potential_ = np.ascontiguousarray(np.zeros([self._size_,self._size_]),dtype=np.complex) # C matrix like 
                self._initial_state_ = np.ascontiguousarray(np.zeros([self._size_,self._size_]),dtype=np.complex) 

        def _setPotential_(self,_potential_array):
                if array.shape == (self._size_,self._size_):
                        self._potential_ = np.ascontiguousarray(_potential_array)
                        return True
                else:
                        raise ValueError(
                '{} array object must be 2D array of the size _size_. Given size: {} '.format(self.__class__.__name__,array.shape))
        
        def _setInitialState_(self,_initial_state_array):
                if array.shape == (self._size_,self._size_):
                        self._potential_ = np.ascontiguousarray(_initial_state_array)
                        return True
                else:
                        raise ValueError(
                '{} array object must be 2D array of the size _size_. Given size: {} '.format(self.__class__.__name__,array.shape))

        


