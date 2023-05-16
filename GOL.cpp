#include "GOL.hpp"

int game::count_neighbours(int posx, int posy) const
{
    std::cout.sync_with_stdio(false);
    std::cout.tie(nullptr);

    int count = 0;
    
    for(int i = -1; i<=1; ++i)
    for(int j = -1; j<=1; ++j)
    {
        if(!i && !j ) continue; 
        try
        {
            count += field.at(posx+i).at(posy+j);
        }
        catch(std::out_of_range) {}
     }
        
    return count;
}

void game::construct_mask() const
{
    for(int i = 0; i<height; ++i)
    for(int j = 0; j<width ; ++j)
    {
        int count = count_neighbours(i, j);
        mask[i][j] = (field[i][j] && (count < 2 || count > 3)) 
                     || (!field[i][j] && count == 3); //uhum uhum
    }
}

void game::apply_mask()
{
    for(int i = 0; i<height; ++i)
    for(int j = 0; j<width ; ++j)
    {
        field[i][j] = field[i][j] ^ mask[i][j];
        // field[i][j] ^= mask[i][j] does not work
    }
}

game::game(int h, int w): height{h}, width{w} 
{
    field = std::vector<std::vector<bool>>(height);
    for(auto &x: field)
    {
        x = std::vector<bool>(width);
    }
    mask = field;
}

void game::set_alive(std::vector<point> &points)
{
	for (auto [i, j]: points)
	    field.at(i).at(j) = true;
}

// TODO: change to output to window instead of cout
// maybe
void game::print() const
{
	for(auto &x: field)
    {
        for(auto y: x)
            std::cout.put(y ? '#'  : '`').put(' ');
        std::cout.put('\n');
    }
    std::cout.put('\n');
    std::cout.flush();
}