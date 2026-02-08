
NAME        = fixed

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
DEPFLAGS    = -MMD -MP

SRC         = main.cpp Fixed.cpp

OBJDIR      = obj
OBJ         = $(addprefix $(OBJDIR)/,$(SRC:.cpp=.o))
DEP         = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Create the object/deps directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Build .o into OBJDIR and emit the matching .d next to it
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@ -MF $(@:.o=.d)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)