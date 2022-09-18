#
# PROGRAM:    assign12
#
    
# Compiler variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11
        
# Rule to link object code files to create executable file
assign12: assign12.o shape.o circle.o triangle.o rectangle.o
	$(CXX) $(CXXFLAGS) -o assign12 $^

# Rules to compile source code file to object code
assign12.o: assign12.cpp circle.h triangle.h rectangle.h
shape.o: shape.cpp shape.h
circle.o: circle.cpp circle.h
triangle.o: triangle.cpp triangle.h
rectangle.o: rectangle.cpp rectangle.h

circle.h: shape.h
triangle.h: shape.h
rectangle.h: shape.h

   
# Pseudo-target to remove object code and executable files
clean:
	rm -f assign12 *.o