"""
Clone of 2048 game.
"""

import poc_2048_gui
from random import randint

# Directions, DO NOT MODIFY
UP = 1
DOWN = 2
LEFT = 3
RIGHT = 4

# Offsets for computing tile indices in each direction.
# DO NOT MODIFY this dictionary.
OFFSETS = {UP: (1, 0),
           DOWN: (-1, 0),
           LEFT: (0, 1),
           RIGHT: (0, -1)}

def merge(line):
    """
    Merge Function merges a single row or column in 2048.
    finding the non empty numbers and storing in temp
     """
    temp=[]
    for _non_zero_nos in line:
        if(_non_zero_nos>0):
            temp.append(_non_zero_nos)
    #the addition list of numbers after getting the temp
    _add_list=[]
    if (len(temp) ==0):
        return line
    else:
        _iterator=1;
        _last_elem=0;
        _add_list.append(temp[0])
        while(_iterator<len(temp)):
            if(_add_list[_last_elem] == temp[_iterator]):
                _add_list[_last_elem]+=temp[_iterator]
                if(_iterator<=(len(temp)-2)):
                    _add_list.append(temp[_iterator+1])
                    _iterator+=1
                    _last_elem+=1
            else:
                _add_list.append(temp[_iterator])
                _last_elem+=1
            _iterator+=1
        # #padding it with zeros to make the list complete
        if(len(_add_list)!=len(line)):
            while((len(line)- len(_add_list))!=0):
                _add_list.append(0)
    line = _add_list
    return line

class TwentyFortyEight:
    """
    Class to run the game logic.
    """

    def __init__(self, grid_height, grid_width):
        """ this method creates the the grid """
        self._grid_height = grid_height
        self._grid_width = grid_width
        self._grid = []
        self.reset()

    def reset(self):
        """
        Reset the game so the grid is empty except for two
        initial tiles.
        """
        self._grid = [[0 for _col in range(self._grid_width)] for _row in range(self._grid_height)]
        self.new_tile()
        self.new_tile()

    def __str__(self):
        """
        Return a string representation of the grid for debugging.
        """
        _grid_str =''
        for _row in range(self._grid_height):
            for _col in range(self._grid_width):
                _grid_str+=str(self._grid[_row][_col])
        # replace with your code
        return _grid_str

    def get_grid_height(self):
        """
        Get the height of the board.
        """
        # replace with your code
        return self._grid_height

    def get_grid_width(self):
        """
        Get the width of the board.
        """
        # replace with your code
        return self._grid_width

    def move(self, direction):
        """
        Move all tiles in the given direction and add
        a new tile if any tiles moved.
        """
        _prev_move_grid = str(self._grid)
        if(direction == 1):
            for _col_val in range(self._grid_width):
                _temp_row=merge([_row[_col_val] for _row in self._grid])
                for _row in range(self._grid_height):
                    self.set_tile(_row,_col_val,_temp_row[_row])
        elif(direction==2):
            for _col_val in range(self._grid_width):
                _temp_row= [_row[_col_val] for _row in self._grid]
                _temp_row.reverse()
                _temp_row=merge(_temp_row)
                _temp_row.reverse()
                for _row in range(self._grid_height):
                    self.set_tile(_row,_col_val,_temp_row[_row])
        elif(direction==4):
            for _row in range(self._grid_height):
                _temp_row=self._grid[_row]
                _temp_row.reverse()
                _temp_row=merge(_temp_row)
                _temp_row.reverse()
                self._grid[_row]=_temp_row
        else:
            for _row in range(self._grid_height):
                _temp_row=self._grid[_row]
                _temp_row=merge(_temp_row)
                self._grid[_row]=_temp_row
        if(_prev_move_grid!=str(self._grid)):
            self.new_tile()    

    def new_tile(self):
        """
        Create a new tile in a randomly selected empty
        square.  The tile should be 2 90% of the time and
        4 10% of the time.
        """
        #first find the row,col which are empty
        _empty_grid=[]
        for _row in range(self._grid_height):
            for _col in range(self._grid_width):
                if(self._grid[_row][_col]==0):
                    _empty_grid.append([_row,_col])
        if(len(_empty_grid)>0) :
            _temp_row,_temp_col = _empty_grid[randint(0,len(_empty_grid)-1)]
            if(randint(0,9)==0):
                self.set_tile(_temp_row,_temp_col,4)
            else:
                self.set_tile(_temp_row,_temp_col,2)
        # replace with your code

    def set_tile(self, row, col, value):
        """
        Set the tile at position row, col to have the given value.
        """
        self._grid[row][col] = value

    def get_tile(self, row, col):
        """
        Return the value of the tile at position row, col.
        """
        return self._grid[row][col]


poc_2048_gui.run_gui(TwentyFortyEight(4, 4))