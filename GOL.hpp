#ifndef __GAME_OF_LIFE_JUSTANOTHERCATGITL__42069__THE_MACRO_NAME_IS_SO_LONG_JUST_FOR_SAFETY_REASONS__
#define __GAME_OF_LIFE_JUSTANOTHERCATGITL__42069__THE_MACRO_NAME_IS_SO_LONG_JUST_FOR_SAFETY_REASONS__

#include <vector>
#include <iostream>

struct point
{
    int first;
    int second;
};

class game
{
    typedef std::vector<std::vector<bool>> field_t;
    int height, width;
    field_t field;
    mutable field_t mask;
    
    int count_neighbours(int posx, int posy) const;
    void construct_mask() const;
    void apply_mask();
    
    
public:
    
    game(int h, int w);
    
    void set_alive(std::vector<point> &points);
    inline void next_iteration()
    {
        construct_mask();
        apply_mask();
    }
    void print() const;
    
};

#endif // __GAME_OF_LIFE_JUSTANOTHERCATGITL__42069__THE_MACRO_NAME_IS_SO_LONG_JUST_FOR_SAFETY_REASONS__