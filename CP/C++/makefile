#CXXFLAGS = -ggdb3 --std=c++17 -pipe -Wall -Wextra -pedantic -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=undefined,address,float-divide-by-zero,float-cast-overflow -fno-omit-frame-pointer -fno-optimize-sibling-calls -fstack-protector-all -fno-sanitize-recover=all-fstack-protector  -Wno-char-subscripts -Wformat-signedness -Wvla -Wredundant-decls -DDEBUG
#CXXFLAGS = -ggdb3 -std=c++17 -Wall -Wextra -pedantic -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fstack-protector -DDEBUG
#CXXFLAGS = -ggdb3 -std=c++17 -Wall -Wextra -O2 -Wshadow -Wformat=2 -Wfloat-equal -DDEBUG

CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Wshadow -Wconversion -Wlogical-op -Wvla -Wno-char-subscripts -Wshift-overflow=2 -Wduplicated-cond -D_FORTIFY_SOURCE=2 -Wfloat-equal -DDEBUG
#CXXFLAGS = -ggdb3 -std=c++20 -Wall -Wextra -O2 -Werror=shadow -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover  -fsanitize=undefined -Wfloat-equal -DDEBUG


#CXXFLAGS = -ggdb -std=c++17 -Wall -Wextra -O2 -Wshadow -Wformat=2 -Wfloat-equal
#make default stronger

run:
	./a.out < in

#gdb ./a.out --tui
#start
#run
find:
	find . | grep -i $(1) 
#use fg trie to find objects
